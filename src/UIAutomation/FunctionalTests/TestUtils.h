// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "CppUnitTest.h"

#include <winrt/Windows.UI.UIAutomation.h>
#include "winrt/Microsoft.UI.UIAutomation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace winrt
{
    using namespace winrt::Windows::UI::UIAutomation;
    using namespace winrt::Microsoft::UI::UIAutomation;
}

namespace Microsoft::VisualStudio::CppUnitTestFramework
{
    // This template specialization is required to allow the CppUnitTestFramework to compare `winrt::hstring`s in
    // its assert macro. The string returned here will be printed in the output of the assert.
    template<>
    std::wstring ToString(const winrt::hstring& str)
    {
        return str.c_str();
    }
}

template<class... Args>
void LogOutput(Args&&... args)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    std::wostringstream oss;
    (oss << ... << args);
    oss << std::endl;

    auto res = oss.str();
    Logger::WriteMessage(res.c_str());
}

// Waits until the given element gains focus.
// Fails if the element doesn't gain focus after the given number of retries.
// Returns the found element on success.
inline winrt::com_ptr<IUIAutomationElement> WaitForElementFocus(const wchar_t* elementName, int retries = 100)
{
    static constexpr DWORD c_sleepMilliseconds = 50;
    winrt::com_ptr<IUIAutomation> automation;
    THROW_IF_FAILED(::CoCreateInstance(__uuidof(CUIAutomation8), nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(automation.put())));

    for (int i = 0; i < retries; ++i)
    {
        winrt::com_ptr<IUIAutomationElement> element;
        const auto getFocusedElementHr = automation->GetFocusedElement(element.put());
        if (getFocusedElementHr == E_INVALIDARG)
        {
            LogOutput(L"GetFocusedElement returned E_INVALIDARG; retrying");
            Sleep(c_sleepMilliseconds);
            continue;
        }
        THROW_IF_FAILED(getFocusedElementHr);

        wil::unique_bstr name;
        THROW_IF_FAILED(element->get_CurrentName(&name));
        THROW_HR_IF_NULL(E_UNEXPECTED, name);
        LogOutput(L"Name: ", name.get());
        if (std::wstring(name.get()) == elementName)
        {
            LogOutput(L"Found element");
            return element;
        }

        ::Sleep(c_sleepMilliseconds);
    }

    LogOutput(L"Element never gained focus.");
    THROW_HR(E_FAIL);
}

inline void AssertSucceeded(const HRESULT hr)
{
    Assert::IsTrue(SUCCEEDED(hr));
}

inline void AssertFailed(const HRESULT hr)
{
    Assert::IsTrue(FAILED(hr));
}
