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

        // Asserts that we can initialize a remote GUID operand with a GUID constant, then get that same GUID
        // back as a result.
        TEST_METHOD(NewGuidTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            op.ImportElement(calc.as<winrt::AutomationElement>());

            winrt::guid guid{ Name_Property_GUID };
            auto remoteGuid = op.NewGuid(guid);
            auto guidToken = op.RequestResponse(remoteGuid);

            auto results = op.Execute();
            Assert::IsTrue(SUCCEEDED(results.OperationStatus()));
            auto guidResult = winrt::unbox_value<winrt::guid>(results.GetResult(guidToken));

            Assert::IsTrue(guid == guidResult);
        }

        // Asserts that calling IsGuid on an AutomationRemoteAnyObject that points to a GUID returns true.
        TEST_METHOD(IsGuidTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            op.ImportElement(calc.as<winrt::AutomationElement>());

            winrt::guid guid{ Name_Property_GUID };
            auto remoteGuid = op.NewGuid(guid);

            // In the high-level builder API, the easiest way to create an AutomationRemoteAnyObject stand-in
            // from an arbitrary operand is to add that operand to a remote array and get it back out.
            auto remoteArray = op.NewArray();
            remoteArray.Append(remoteGuid);
            auto remoteGuidAsAnyObject = remoteArray.GetAt(op.NewUint(0));

            auto remoteIsGuid = remoteGuidAsAnyObject.IsGuid();
            auto isGuidToken = op.RequestResponse(remoteIsGuid);

            auto results = op.Execute();
            Assert::IsTrue(SUCCEEDED(results.OperationStatus()));
            auto isGuidResult = winrt::unbox_value<bool>(results.GetResult(isGuidToken));

            Assert::IsTrue(isGuidResult);
        }

        // Asserts that calling IsEqual with two remote copies of the same GUID returns true.
        TEST_METHOD(EqualGuidsTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            op.ImportElement(calc.as<winrt::AutomationElement>());

            winrt::guid guid{ Name_Property_GUID };
            auto remoteGuid1 = op.NewGuid(guid);
            auto remoteGuid2 = op.NewGuid(guid);

            auto remoteIsEqual = remoteGuid1.IsEqual(remoteGuid2);
            auto isEqualToken = op.RequestResponse(remoteIsEqual);

            auto results = op.Execute();
            Assert::IsTrue(SUCCEEDED(results.OperationStatus()));
            auto isEqualResult = winrt::unbox_value<bool>(results.GetResult(isEqualToken));

            Assert::IsTrue(isEqualResult);
        }

        // Asserts that calling IsEqual with two different remote GUID operands returns false.
        TEST_METHOD(NonEqualGuidsTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            op.ImportElement(calc.as<winrt::AutomationElement>());

            winrt::guid guid1{ Name_Property_GUID };
            winrt::guid guid2{ ControlType_Property_GUID };

            auto remoteGuid1 = op.NewGuid(guid1);
            auto remoteGuid2 = op.NewGuid(guid2);

            auto remoteIsEqual = remoteGuid1.IsEqual(remoteGuid2);
            auto isEqualToken = op.RequestResponse(remoteIsEqual);

            auto results = op.Execute();
            Assert::IsTrue(SUCCEEDED(results.OperationStatus()));
            auto isEqualResult = winrt::unbox_value<bool>(results.GetResult(isEqualToken));

            Assert::IsFalse(isEqualResult);
        }

        // Asserts that calling LookupPropertyId on a property GUID returns the expected integer ID.
        TEST_METHOD(LookupPropertyIdTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            op.ImportElement(calc.as<winrt::AutomationElement>());

            winrt::guid guid{ Name_Property_GUID };
            constexpr auto intId = UIA_NamePropertyId;

            auto remoteGuid = op.NewGuid(guid);
            auto remotePropertyId = remoteGuid.LookupPropertyId();
            auto propertyIdToken = op.RequestResponse(remotePropertyId);

            auto results = op.Execute();
            Assert::IsTrue(SUCCEEDED(results.OperationStatus()));
            auto intIdResult = winrt::unbox_value<int32_t>(results.GetResult(propertyIdToken));

            Assert::IsTrue(intId == intIdResult);
        }

        // Asserts that calling LookupGuid on a remote property ID returns the expected property GUID.
        TEST_METHOD(LookupPropertyGuidTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            op.ImportElement(calc.as<winrt::AutomationElement>());

            constexpr auto propertyId = winrt::AutomationPropertyId::Name;
            winrt::guid guid{ Name_Property_GUID };

            auto remotePropertyId = op.NewEnum(propertyId);
            auto remoteGuid = remotePropertyId.LookupGuid();
            auto guidToken = op.RequestResponse(remoteGuid);

            auto results = op.Execute();
            Assert::IsTrue(SUCCEEDED(results.OperationStatus()));
            auto guidResult = winrt::unbox_value<winrt::guid>(results.GetResult(guidToken));

            Assert::IsTrue(guid == guidResult);
        }
    };
}
