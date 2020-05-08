// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "CppUnitTest.h"

#include "ModernApp.h"
#include "TestUtils.h"

#include <winrt/Windows.Foundation.h>
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

namespace FunctionalTests
{
    // Waits until the given element gains focus.
    // Fails if the element doesn't gain focus after the given number of retries.
    // Returns the found element on success.
    winrt::com_ptr<IUIAutomationElement> WaitForElementFocus(const wchar_t* elementName, int retries = 100)
    {
        winrt::com_ptr<IUIAutomation> automation;
        THROW_IF_FAILED(::CoCreateInstance(__uuidof(CUIAutomation8), nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(automation.put())));

        for (int i = 0; i < retries; ++i)
        {
            winrt::com_ptr<IUIAutomationElement> element;
            const auto getFocusedElementHr = automation->GetFocusedElement(element.put());
            if (getFocusedElementHr == E_INVALIDARG)
            {
                LogOutput(L"GetFocusedElement returned E_INVALIDARG; retrying");
                Sleep(50);
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

            ::Sleep(50);
        }

        LogOutput(L"Element never gained focus.");
        THROW_HR(E_FAIL);
    }

    void AssertSucceeded(HRESULT hr)
    {
        Assert::AreEqual(hr, S_OK);
    }

    TEST_CLASS(FunctionalTests)
    {
    public:
        // Asserts that it's possible to activate the AutomationRemoteOperation runtimeclass.
        TEST_METHOD(AutomationRemoteOperationActivationTest)
        {
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteOperation op;
        }

        // Asserts that we can create the simplest possible remote operation and execute it against a
        // Calculator instance.
        TEST_METHOD(MinimalCalculatorTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            auto remoteElement = op.ImportElement(calc.as<winrt::AutomationElement>());
            auto remoteName = remoteElement.GetName();
            auto nameToken = op.RequestResponse(remoteName);

            auto results = op.Execute();
            Assert::IsTrue(SUCCEEDED(results.OperationStatus()));
            auto name = winrt::unbox_value<winrt::hstring>(results.GetResult(nameToken));

            Assert::AreEqual(winrt::hstring(L"Display is 0"), name);
        }
    };
}
