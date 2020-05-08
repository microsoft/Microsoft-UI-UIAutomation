// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "ModernApp.h"

#include <Windows.h>
#include <Shobjidl.h>

#include <wrl.h>

#include "winrt/Windows.Foundation.Collections.h"
#include "winrt/windows.management.deployment.h"

#include <thread>
#include <array>

#include "TestUtils.h"

namespace wrl = Microsoft::WRL;

namespace
{
    std::wstring MakeFilePath(_In_z_ const wchar_t* fileName)
    {
        std::array<wchar_t, MAX_PATH> currentDirectory;
        ::GetCurrentDirectory(static_cast<DWORD>(currentDirectory.size()), currentDirectory.data());
        return std::wstring(currentDirectory.data()) + L"\\" + fileName;
    }

    DWORD GetPidFromHwnd(HWND hwnd) noexcept
    {
        DWORD childProcessId = 0;
        ::GetWindowThreadProcessId(hwnd, &childProcessId);
        return childProcessId;
    }

    bool IsConsoleWindow(HWND hwnd)
    {
        std::array<wchar_t, 64> testClassName{};
        ::GetClassName(hwnd, testClassName.data(), static_cast<int>(testClassName.size()));
        return (::lstrcmpi(testClassName.data(), L"ConsoleWindowClass") == 0);
    }

    void TerminateProcess(DWORD processId)
    {
        wil::unique_handle processHandle { ::OpenProcess(PROCESS_TERMINATE, FALSE /* inheritHandle */, processId) };
        THROW_IF_WIN32_BOOL_FALSE(::TerminateProcess(processHandle.get(), 0xFFFFFFFF /* exitCode */));
        ::WaitForSingleObject(processHandle.get(), 10000);
    }
}

ModernApp::ModernApp(_In_z_ const wchar_t* testAppAumid) :
    m_testAppAumid(testAppAumid)
{
}

ModernApp::ModernApp(_In_z_ const wchar_t* testAppAumid, _In_z_ const wchar_t* exeName) :
    m_testAppAumid(testAppAumid), m_exeName(exeName)
{
}

ModernApp::~ModernApp() noexcept
{
    // Ensure no exceptions are thrown by the destructor.
    // This way, we get the test failures rather than Watson dumps.
    try
    {
        Close();
    }
    catch (...)
    {
    }
}

/* static */
bool ModernApp::RegisterTestAppx(_In_z_ const wchar_t* appxName)
{
    auto path = MakeFilePath(appxName);

    winrt::Windows::Foundation::Uri uri(path.c_str());
    winrt::Windows::Management::Deployment::PackageManager packageManager;
    auto res = packageManager.AddPackageAsync(uri, {}, winrt::Windows::Management::Deployment::DeploymentOptions::ForceApplicationShutdown);

    const auto deploymentResult = res.get();
    if (deploymentResult.IsRegistered())
    {
        LogOutput(L"Successfully registered package: ", appxName);
    }
    else
    {
        LogOutput(L"Failed to register ", appxName);
        return false;
    }

    return true;
}

/* static */
void ModernApp::RemoveTestAppx(_In_z_ const wchar_t* packageName)
{
    LogOutput(L"Removing package: ", packageName);

    winrt::Windows::Management::Deployment::PackageManager packageManager;
    auto res = packageManager.RemovePackageAsync(packageName);
    auto deploymentResult = res.get();
}

void ModernApp::Activate(_In_opt_z_ const wchar_t* testAppArguments /* = nullptr */)
{
    if (m_appProcessId == 0)
    {
        wrl::ComPtr<IApplicationActivationManager> activationManager;
        THROW_IF_FAILED(::CoCreateInstance(
            CLSID_ApplicationActivationManager,
            nullptr,
            CLSCTX_INPROC_SERVER,
            IID_PPV_ARGS(&activationManager)));

        // Sometimes, when run under stress, we are opening and closing the test app rapidly and we may fail
        // to activate it because it is "updating". This should eventually settle down, so to avoid seeing
        // test failures in this case, we'll try multiple times to activate the application.
        const int retries = 10;
        DWORD appProcessId = 0;
        HRESULT activateResult = S_OK;
        for (int i = 0; i < retries; ++i)
        {
            LogOutput(L"Attempting to activate: ", m_testAppAumid.c_str());

            activateResult = activationManager->ActivateApplication(m_testAppAumid.c_str(), testAppArguments, AO_NOERRORUI, &appProcessId);
            // Give the app time to settle, or have a delay between attempts to activate
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

            if (SUCCEEDED(activateResult))
            {
                break;
            }
        }
        THROW_IF_FAILED(activateResult);
        m_appProcessId = appProcessId;
    }
    // else we're already activated
}

void ModernApp::Close()
{
    if (m_appProcessId != 0)
    {
        TerminateProcess(m_appProcessId);
        m_appProcessId = 0;

        // The process should be gone now, but if a test is being run under stress, then it may immediately try to
        // launch the same process again, and sometimes that does not work properly (the app will launch minimized).
        // Adding an artificial delay here to be extra certain that the app is gone alleviates the problem.
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

DWORD ModernApp::GetAppProcessId() noexcept
{
    return m_appProcessId;
}

void ModernApp::WaitForWindow(std::function<bool(_In_ HWND)> checkIfWindowMatches)
{
    // Give the app up to two minutes to start.
    for (int attempt = 0 ; attempt < 240 ; attempt++)
    {
        if (TryFindWindowNow(checkIfWindowMatches))
        {
            return;
        }
        ::Sleep(500);
    }
}

bool ModernApp::TryFindWindowNow(std::function<bool(_In_ HWND)> checkIfWindowMatches)
{
    HWND hwndChild = ::GetWindow(::GetDesktopWindow(), GW_CHILD);
    while (hwndChild != nullptr)
    {
        const bool foundResult = checkIfWindowMatches(hwndChild);
        if (foundResult)
        {
            return true;
        }

        hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
    }

    return false;
}

HWND ModernApp::GetMainWindow()
{
    if (!m_hwnd)
    {
        WaitForWindow([this](HWND hwnd)
        {
            // Ignore invisible worker windows and console windows
            if (!::IsWindowVisible(hwnd) || IsConsoleWindow(hwnd))
            {
                return false;
            }
            if (GetPidFromHwnd(hwnd) == m_appProcessId)
            {
                // Tada! Found my process.
                m_hwnd = hwnd;
                return true;
            }

            return false;
        });
    }

    return m_hwnd;
}
