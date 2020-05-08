// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include <functional>
#include <string>

// Helper class for registering, starting, and terminating modern applications (AppX)
class ModernApp
{
public:
    explicit ModernApp(_In_z_ const wchar_t* testAppAumid);
    ModernApp(_In_z_ const wchar_t* testAppAumid, _In_z_ const wchar_t* exeName);
    ~ModernApp() noexcept;

    ModernApp(const ModernApp&) = delete;
    ModernApp& operator=(const ModernApp&) = delete;

    ModernApp(ModernApp&&) = delete;
    ModernApp& operator=(ModernApp&&) = delete;

    // Helpers to install and remove AppX packages
    static bool RegisterTestAppx(_In_z_ const wchar_t* appxName);
    static void RemoveTestAppx(_In_z_ const wchar_t* packageName);

    void Activate(_In_opt_z_ const wchar_t* testAppArguments = nullptr);
    void Close();

    DWORD GetAppProcessId() noexcept;
    HWND GetMainWindow();

private:
    DWORD m_appProcessId = 0;
    std::wstring m_testAppAumid;
    std::wstring m_exeName;

    // We don't want to own the lifetime of this window. It is still owned by the
    // activated application, so we should not destroy it when this object goes away.
    HWND m_hwnd = nullptr;

    void WaitForWindow(std::function<bool(_In_ HWND)> checkIfWindowMatches);
    bool TryFindWindowNow(std::function<bool(_In_ HWND)> checkIfWindowMatches);
};
