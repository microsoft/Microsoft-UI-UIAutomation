<#
.SYNOPSIS
Downloads and installs the Windows Insider Preview SDK matching a given build number.

.PARAMETER buildNumber
The Windows build number of the preview SDK to install, e.g. 19613.

.PARAMETER expectedSha256
Optional SHA-256 hash of the expected ISO. When supplied, the download is rejected unless it
matches. Supply this whenever a known-good hash is available: it is the only check that
validates the entire image rather than just the setup binary.
#>
[CmdletBinding()]
param([Parameter(Mandatory=$true, Position=0)]
      [string]$buildNumber,
      [Parameter(Mandatory=$false)]
      [ValidatePattern('^[0-9A-Fa-f]{64}$')]
      [string]$expectedSha256)

# Ensure the error action preference is set to the default for PowerShell3, 'Stop'
$ErrorActionPreference = 'Stop'

# Constants
$WindowsSDKOptions = @("OptionId.UWPCpp", "OptionId.DesktopCPPx64", "OptionId.DesktopCPPx86", "OptionId.DesktopCPPARM64", "OptionId.DesktopCPPARM", "OptionId.WindowsDesktopDebuggers")
$WindowsSDKRegPath = "HKLM:\Software\WOW6432Node\Microsoft\Windows Kits\Installed Roots"
$WindowsSDKRegRootKey = "KitsRoot10"
$WindowsSDKVersion = "10.0.$buildNumber.0"
$WindowsSDKInstalledRegPath = "$WindowsSDKRegPath\$WindowsSDKVersion\Installed Options"
$StrongNameRegPath = "HKLM:\SOFTWARE\Microsoft\StrongName\Verification"
$PublicKeyTokens = @("31bf3856ad364e35")

if ($buildNumber -notmatch "^\d{5,}$")
{
    Write-Host "ERROR: '$buildNumber' doesn't look like a windows build number"
    Write-Host
    Exit 1
}

function Download-File
{
    param ([string] $outDir,
           [string] $downloadUrl,
           [string] $downloadName)

    $downloadPath = Join-Path $outDir "$downloadName.download"
    $downloadDest = Join-Path $outDir $downloadName

    Write-Host -NoNewline "Downloading $downloadName..."

    $retries = 10
    $downloaded = $false
    while (-not $downloaded)
    {
        try
        {
            $webclient = new-object System.Net.WebClient
            $webclient.DownloadFile($downloadUrl, $downloadPath)
            $downloaded = $true
        }
        catch [System.Net.WebException]
        {
            Write-Host
            Write-Warning "Failed to fetch updated file from $downloadUrl : $($error[0])"

            $retries--
            if ($retries -le 0)
            {
                throw "$downloadName could not be downloaded from $downloadUrl"
            }

            Write-Host "$retries retries left, trying download again"
            Start-Sleep -Seconds 10
        }
    }

    # NOTE: deliberately no Unblock-File here. The Mark-of-the-Web is left intact rather than
    # stripped from content that has not yet passed an integrity check. Mount-DiskImage does
    # not require the file to be unblocked.

    # Delete and rename to final dest
    Write-Host "testing $downloadDest"
    if (Test-Path $downloadDest)
    {
        Write-Host "Deleting: $downloadDest"
        Remove-Item $downloadDest -Force
    }

    Move-Item -Force $downloadPath $downloadDest
    Write-Host "Done"

    return $downloadDest
}

function Get-ISODriveLetter
{
    param ([string] $isoPath)

    $diskImage = Get-DiskImage -ImagePath $isoPath
    if ($diskImage)
    {
        $volume = Get-Volume -DiskImage $diskImage

        if ($volume)
        {
            $driveLetter = $volume.DriveLetter
            if ($driveLetter)
            {
                $driveLetter += ":"
                return $driveLetter
            }
        }
    }

    return $null
}

function Mount-ISO
{
    param ([string] $isoPath)

    # Check if image is already mounted
    $isoDrive = Get-ISODriveLetter $isoPath

    if (!$isoDrive)
    {
        Mount-DiskImage -ImagePath $isoPath -StorageType ISO | Out-Null
    }

    $isoDrive = Get-ISODriveLetter $isoPath
    Write-Verbose "$isoPath mounted to ${isoDrive}:"
}

function Dismount-ISO
{
    param ([string] $isoPath)

    # Guard against the image never having been attached: Get-Volume on an unattached image is
    # a terminating error under $ErrorActionPreference = 'Stop', which would mask whatever
    # exception sent us into the finally block in the first place.
    $diskImage = Get-DiskImage -ImagePath $isoPath -ErrorAction SilentlyContinue

    if ($diskImage -and $diskImage.Attached)
    {
        Write-Verbose "$isoPath dismounted"
        Dismount-DiskImage -ImagePath $isoPath | Out-Null
    }
}

function Disable-StrongName
{
    param ([string] $publicKeyToken = "*")

    reg ADD "HKLM\SOFTWARE\Microsoft\StrongName\Verification\*,$publicKeyToken" /f | Out-Null
    if ($env:PROCESSOR_ARCHITECTURE -eq "AMD64")
    {
        reg ADD "HKLM\SOFTWARE\Wow6432Node\Microsoft\StrongName\Verification\*,$publicKeyToken" /f | Out-Null
    }
}

function Test-Admin
{
    $identity = [Security.Principal.WindowsIdentity]::GetCurrent()
    $principal = New-Object Security.Principal.WindowsPrincipal $identity
    $principal.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

function Test-RegistryPathAndValue
{
    param (
        [parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $path,
        [parameter(Mandatory=$true)]
        [ValidateNotNullOrEmpty()]
        [string] $value)

    try
    {
        if (Test-Path $path)
        {
            Get-ItemProperty -Path $path | Select-Object -ExpandProperty $value -ErrorAction Stop | Out-Null
            return $true
        }
    }
    catch
    {
    }

    return $false
}

function Test-InstallWindowsSDK
{
    $retval = $true

    if (Test-RegistryPathAndValue -Path $WindowsSDKRegPath -Value $WindowsSDKRegRootKey)
    {
        # A Windows SDK is installed
        # Is an SDK of our version installed with the options we need?
        $allRequiredSdkOptionsInstalled = $true
        foreach($sdkOption in $WindowsSDKOptions)
        {
            if (!(Test-RegistryPathAndValue -Path $WindowsSDKInstalledRegPath -Value $sdkOption))
            {
                $allRequiredSdkOptionsInstalled = $false
            }
        }

        if($allRequiredSdkOptionsInstalled)
        {
            # It appears we have what we need. Double check the disk
            $sdkRoot = Get-ItemProperty -Path $WindowsSDKRegPath | Select-Object -ExpandProperty $WindowsSDKRegRootKey
            if ($sdkRoot)
            {
                if (Test-Path $sdkRoot)
                {
                    $refPath = Join-Path $sdkRoot "References\$WindowsSDKVersion"
                    if (Test-Path $refPath)
                    {
                        $umdPath = Join-Path $sdkRoot "UnionMetadata\$WindowsSDKVersion"
                        if (Test-Path $umdPath)
                        {
                            # Pretty sure we have what we need
                            $retval = $false
                        }
                    }
                }
            }
        }
    }

    return $retval
}

function Test-InstallStrongNameHijack
{
    foreach($publicKeyToken in $PublicKeyTokens)
    {
        $key = "$StrongNameRegPath\*,$publicKeyToken"
        if (!(Test-Path $key))
        {
            return $true
        }
    }

    return $false
}

Write-Host -NoNewline "Checking for installed Windows SDK $WindowsSDKVersion..."
$InstallWindowsSDK = Test-InstallWindowsSDK
if ($InstallWindowsSDK)
{
    Write-Host "Installation required"
}
else
{
    Write-Host "INSTALLED"
}

$StrongNameHijack = Test-InstallStrongNameHijack
Write-Host -NoNewline "Checking if StrongName bypass required..."

if ($StrongNameHijack)
{
    Write-Host "REQUIRED"
}
else
{
    Write-Host "Done"
}

if ($StrongNameHijack -or $InstallWindowsSDK)
{
    if (!(Test-Admin))
    {
        Write-Host
        throw "ERROR: Elevation required"
    }
}

if ($InstallWindowsSDK)
{
    # Static(ish) link for Windows SDK
    # Note: there is a delay from Windows SDK announcements to availability via the static link
    $uri = "https://software-download.microsoft.com/download/sg/Windows_InsiderPreview_SDK_en-us_$($buildNumber)_1.iso";

    if ($env:TEMP -eq $null)
    {
        $env:TEMP = Join-Path $env:SystemDrive 'temp'
    }

    $winsdkTempDir = Join-Path (Join-Path $env:TEMP ([System.IO.Path]::GetRandomFileName())) "WindowsSDK"

    if (![System.IO.Directory]::Exists($winsdkTempDir))
    {
        [void][System.IO.Directory]::CreateDirectory($winsdkTempDir)
    }

    $file = "winsdk_$buildNumber.iso"

    Write-Verbose "Getting WinSDK from $uri"
    $downloadFile = Download-File $winsdkTempDir $uri $file
    Write-Verbose "File is at $downloadFile"
    $downloadFileItem = Get-Item $downloadFile
    
    # Check to make sure the file is at least 10 MB.
    if ($downloadFileItem.Length -lt 10*1024*1024)
    {
        Write-Host
        Write-Host "ERROR: Downloaded file doesn't look large enough to be an ISO. The requested version may not be on microsoft.com yet."
        Write-Host
        Exit 1
    }

    # TODO Check if zip, exe, iso, etc.

    # Integrity check. The size floor above validates nothing about the content, and TLS alone
    # is not an integrity guarantee for code that is about to be executed elevated.
    if ($expectedSha256)
    {
        Write-Host -NoNewline "Verifying ISO SHA-256..."
        $actualSha256 = (Get-FileHash $downloadFile -Algorithm SHA256).Hash

        if ($actualSha256 -ne $expectedSha256)
        {
            Write-Host
            Remove-Item $downloadFile -Force -ErrorAction SilentlyContinue
            throw "ERROR: ISO integrity check FAILED. Expected '$expectedSha256', got '$actualSha256'. Refusing to mount."
        }

        Write-Host "OK"
    }
    else
    {
        Write-Warning "No -expectedSha256 supplied; relying on Authenticode validation of the setup binary."
    }

    $isoRejected = $false

    try
    {
        Write-Host -NoNewline "Mounting ISO $file..."
        Mount-ISO $downloadFile
        Write-Host "Done"

        $isoDrive = Get-ISODriveLetter $downloadFile

        if ($isoDrive -and (Test-Path $isoDrive))
        {
            $setupPath = Join-Path "$isoDrive" "WinSDKSetup.exe"

            if (!(Test-Path $setupPath))
            {
                throw "WinSDKSetup.exe was not found on the mounted image at ${isoDrive}"
            }

            # Validate the publisher before running this binary as Administrator. This check
            # holds even if TLS was intercepted or the CDN object was substituted.
            Write-Host -NoNewline "Validating WinSDKSetup.exe signature..."
            $signature = Get-AuthenticodeSignature $setupPath

            if ($signature.Status -ne 'Valid')
            {
                Write-Host
                throw "ERROR: WinSDKSetup.exe Authenticode status is '$($signature.Status)'. Refusing to execute."
            }

            $signerSubject = $signature.SignerCertificate.Subject

            # Match the O= RDN rather than an unanchored substring of the whole subject.
            if ($signerSubject -notmatch '(^|,\s*)O=Microsoft Corporation(,|$)')
            {
                Write-Host
                throw "ERROR: WinSDKSetup.exe is signed by an unexpected publisher: $signerSubject"
            }

            Write-Host "OK"
            Write-Verbose "WinSDKSetup.exe signer: $signerSubject"

            Write-Host -NoNewLine "Installing WinSDK..."
            Start-Process -Wait $setupPath "/features $WindowsSDKOptions /q"
            Write-Host "Done"
        }
        else
        {
            throw "Could not find mounted ISO at ${isoDrive}"
        }
    }
    catch
    {
        $isoRejected = $true
        throw
    }
    finally
    {
        try
        {
            Write-Host -NoNewline "Dismounting ISO $file..."
            Dismount-ISO $downloadFile
            Write-Host "Done"
        }
        catch
        {
            Write-Host
            Write-Warning "Failed to dismount ${file}: $($_.Exception.Message)"
        }

        # Don't leave an image that failed validation on disk for something else to pick up.
        if ($isoRejected)
        {
            Remove-Item $downloadFile -Force -ErrorAction SilentlyContinue
        }
    }
}

if ($StrongNameHijack)
{
    Write-Host -NoNewline "Disabling StrongName for Windows SDK..."

    foreach($key in $PublicKeyTokens)
    {
        Disable-StrongName $key
    }

    Write-Host "Done"
}
