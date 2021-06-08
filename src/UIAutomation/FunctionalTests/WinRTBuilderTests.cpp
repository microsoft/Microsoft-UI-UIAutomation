// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "CppUnitTest.h"

#include "ModernApp.h"
#include "TestUtils.h"

namespace WinRTBuilderTests
{
    TEST_CLASS(WinRTBuilderTests)
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
            AssertSucceeded(results.OperationStatus());
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
            AssertSucceeded(results.OperationStatus());
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
            AssertSucceeded(results.OperationStatus());
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
            AssertSucceeded(results.OperationStatus());
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
            AssertSucceeded(results.OperationStatus());
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
            AssertSucceeded(results.OperationStatus());
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
            AssertSucceeded(results.OperationStatus());
            auto guidResult = winrt::unbox_value<winrt::guid>(results.GetResult(guidToken));

            Assert::IsTrue(guid == guidResult);
        }

        // Asserts that checking if cache requests are supported returns true.
        TEST_METHOD(IsCacheRequestSupported)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            auto remoteElement = op.ImportElement(calc.as<winrt::AutomationElement>());

            Assert::IsTrue(op.IsCacheRequestSupported());
        }

        // Asserts that IsCacheRequest properly detects cache requests.
        TEST_METHOD(IsCacheRequest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            const auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            op.ImportElement(calc.as<winrt::AutomationElement>());

            const auto cacheRequest = op.NewCacheRequest();

            // In the high-level builder API, the easiest way to create an
            // AutomationRemoteAnyObject stand-in from an arbitrary operand is
            // to add that operand to a remote array and get it back out.
            const auto array = op.NewArray();
            array.Append(cacheRequest);
            const auto cacheRequestAsAnyObject = array.GetAt(op.NewUint(0));

            const auto isCacheRequest = cacheRequestAsAnyObject.IsCacheRequest();
            const auto isCacheRequestToken = op.RequestResponse(isCacheRequest);

            const auto results = op.Execute();
            AssertSucceeded(results.OperationStatus());
            const auto isCacheRequestResult = winrt::unbox_value<bool>(results.GetResult(isCacheRequestToken));

            Assert::IsTrue(isCacheRequestResult);
        }

        // Asserts that properties and patterns can be added to a cache request.
        TEST_METHOD(CacheRequestAddPropertyAddPattern)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            const auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            op.ImportElement(calc.as<winrt::AutomationElement>());

            const auto cacheRequest = op.NewCacheRequest();
            cacheRequest.AddProperty(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_NamePropertyId)));
            cacheRequest.AddPattern(op.NewEnum(static_cast<winrt::AutomationPatternId>(UIA_TextPatternId)));

            const auto results = op.Execute();
            AssertSucceeded(results.OperationStatus());
        }

        // Asserts that an element's cache request can be populated without
        // returning the element.
        TEST_METHOD(CacheRequestNoReturnTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            const auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            const auto remoteCalc = op.ImportElement(calc.as<winrt::AutomationElement>());

            const auto cacheRequest = op.NewCacheRequest();
            cacheRequest.AddProperty(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_NamePropertyId)));
            cacheRequest.AddPattern(op.NewEnum(static_cast<winrt::AutomationPatternId>(UIA_TextPatternId)));

            const auto window = remoteCalc.GetParentElement().GetParentElement();
            window.PopulateCache(cacheRequest);

            const auto results = op.Execute();
            AssertSucceeded(results.OperationStatus());
        }

        // Asserts that an imported element's cache can be populated.
        TEST_METHOD(CacheRequestImportedElementTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            const auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            const auto remoteCalc = op.ImportElement(calc.as<winrt::AutomationElement>());

            const auto cacheRequest = op.NewCacheRequest();
            cacheRequest.AddProperty(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_NamePropertyId)));
            cacheRequest.AddPattern(op.NewEnum(static_cast<winrt::AutomationPatternId>(UIA_TextPatternId)));

            remoteCalc.PopulateCache(cacheRequest);
            const auto calcToken = op.RequestResponse(remoteCalc);

            const auto results = op.Execute();
            AssertSucceeded(results.OperationStatus());

            const auto calcResult = results.GetResult(calcToken).as<IUIAutomationElement>();

            // Make sure this is the same element we passed in.
            {
                winrt::com_ptr<IUIAutomation> automation;
                AssertSucceeded(::CoCreateInstance(__uuidof(CUIAutomation8), nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(automation.put())));
                BOOL equals = FALSE;
                AssertSucceeded(automation->CompareElements(calcResult.get(), calc.get(), &equals));
                Assert::IsTrue(equals);
            }

            // Make sure the name property is cached.
            {
                wil::unique_bstr name;
                AssertSucceeded(calcResult->get_CachedName(&name));
                Assert::IsNotNull(name.get());
                Assert::AreEqual(std::wstring(name.get()), std::wstring(L"Display is 0"));
            }

            // Make sure the text pattern is cached.
            {
                winrt::com_ptr<IUIAutomationTextPattern> textPattern;
                AssertSucceeded(calcResult->GetCachedPatternAs(UIA_TextPatternId, IID_PPV_ARGS(&textPattern)));
                // This element does not support the text pattern.
                Assert::IsNull(textPattern.get());
            }
        }

        // Asserts that a remote element's cache can be populated.
        TEST_METHOD(CacheRequestRemoteElementTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            const auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            const auto remoteCalc = op.ImportElement(calc.as<winrt::AutomationElement>());

            const auto cacheRequest = op.NewCacheRequest();
            cacheRequest.AddProperty(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_NamePropertyId)));
            cacheRequest.AddPattern(op.NewEnum(static_cast<winrt::AutomationPatternId>(UIA_TextPatternId)));

            const auto window = remoteCalc.GetParentElement().GetParentElement();
            window.PopulateCache(cacheRequest);
            const auto windowToken = op.RequestResponse(window);

            const auto results = op.Execute();
            AssertSucceeded(results.OperationStatus());

            const auto windowResult = results.GetResult(windowToken).as<IUIAutomationElement>();

            // Make sure the name property is cached.
            {
                wil::unique_bstr name;
                AssertSucceeded(windowResult->get_CachedName(&name));
                Assert::IsNotNull(name.get());
                Assert::AreEqual(std::wstring(name.get()), std::wstring(L"Calculator"));
            }

            // Make sure the text pattern is cached.
            {
                winrt::com_ptr<IUIAutomationTextPattern> textPattern;
                AssertSucceeded(windowResult->GetCachedPatternAs(UIA_TextPatternId, IID_PPV_ARGS(&textPattern)));
                // This element does not support the text pattern.
                Assert::IsNull(textPattern.get());
            }
        }

        // Asserts that a cache request can be reused.
        TEST_METHOD(CacheRequestReuseTest)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            const auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            const auto remoteCalc = op.ImportElement(calc.as<winrt::AutomationElement>());

            const auto cacheRequest = op.NewCacheRequest();
            cacheRequest.AddProperty(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_NamePropertyId)));
            cacheRequest.AddPattern(op.NewEnum(static_cast<winrt::AutomationPatternId>(UIA_TextPatternId)));

            const auto window = remoteCalc.GetParentElement().GetParentElement();
            window.PopulateCache(cacheRequest);
            const auto windowToken = op.RequestResponse(window);

            cacheRequest.AddProperty(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_ControlTypePropertyId)));
            cacheRequest.AddPattern(op.NewEnum(static_cast<winrt::AutomationPatternId>(UIA_ValuePatternId)));

            const auto text = remoteCalc.GetFirstChildElement().GetFirstChildElement();
            text.PopulateCache(cacheRequest);
            const auto textToken = op.RequestResponse(text);

            const auto results = op.Execute();
            AssertSucceeded(results.OperationStatus());

            const auto windowResult = results.GetResult(windowToken).as<IUIAutomationElement>();
            const auto textResult = results.GetResult(textToken).as<IUIAutomationElement>();

            // Make sure the name property is cached on the window, but the control type property is not.
            {
                wil::unique_bstr name;
                AssertSucceeded(windowResult->get_CachedName(&name));
                Assert::IsNotNull(name.get());
                Assert::AreEqual(std::wstring(name.get()), std::wstring(L"Calculator"));

                CONTROLTYPEID controlType{};
                AssertFailed(windowResult->get_CachedControlType(&controlType));

                AssertSucceeded(windowResult->get_CurrentControlType(&controlType));
                Assert::AreEqual(static_cast<long>(controlType), static_cast<long>(UIA_WindowControlTypeId));
            }

            // Make sure both properties are cached on calc.
            {
                wil::unique_bstr name;
                AssertSucceeded(textResult->get_CachedName(&name));
                Assert::IsNotNull(name.get());
                Assert::AreEqual(std::wstring(name.get()), std::wstring(L"0"));

                CONTROLTYPEID controlType{};
                AssertSucceeded(textResult->get_CachedControlType(&controlType));
                Assert::AreEqual(static_cast<long>(controlType), static_cast<long>(UIA_TextControlTypeId));
            }

            // Make sure the text pattern is cached on the window, but the value pattern is not.
            {
                winrt::com_ptr<IUIAutomationTextPattern> textPattern;
                AssertSucceeded(windowResult->GetCachedPatternAs(UIA_TextPatternId, IID_PPV_ARGS(&textPattern)));
                // This element does not support the text pattern.
                Assert::IsNull(textPattern.get());

                winrt::com_ptr<IUIAutomationValuePattern> valuePattern;
                AssertFailed(windowResult->GetCachedPatternAs(UIA_ValuePatternId, IID_PPV_ARGS(&valuePattern)));

                AssertSucceeded(windowResult->GetCurrentPatternAs(UIA_ValuePatternId, IID_PPV_ARGS(&valuePattern)));
                // This element does not support the value pattern.
                Assert::IsNull(valuePattern.get());
            }

            // Make sure both patterns are cached on calc.
            {
                winrt::com_ptr<IUIAutomationTextPattern> textPattern;
                AssertSucceeded(textResult->GetCachedPatternAs(UIA_TextPatternId, IID_PPV_ARGS(&textPattern)));
                Assert::IsNotNull(textPattern.get());
                SupportedTextSelection selection{};
                AssertSucceeded(textPattern->get_SupportedTextSelection(&selection));
                Assert::AreEqual(static_cast<uint32_t>(selection), static_cast<uint32_t>(SupportedTextSelection_Single));

                winrt::com_ptr<IUIAutomationValuePattern> valuePattern;
                AssertSucceeded(textResult->GetCachedPatternAs(UIA_ValuePatternId, IID_PPV_ARGS(&valuePattern)));
                // This element does not support the value pattern.
                Assert::IsNull(valuePattern.get());
            }
        }

        // Tests that we can compare Remote Arrays.
        TEST_METHOD(RemoteArraysEqual)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            auto remoteElement = op.ImportElement(calc.as<winrt::AutomationElement>());
            auto arr1 = op.NewArray();
            arr1.Append(op.NewInt(1));
            arr1.Append(op.NewInt(2));
            auto arr2 = op.NewArray();
            arr2.Append(op.NewInt(1));
            arr2.Append(op.NewInt(2));

            auto eq = arr1.IsEqual(arr2);

            auto eqToken = op.RequestResponse(eq);
            auto results = op.Execute();

            AssertSucceeded(results.OperationStatus());
            const bool equal = winrt::unbox_value<bool>(results.GetResult(eqToken));
            Assert::AreEqual(true, equal);
        }

        // Tests that we can compare runtime IDs.
        TEST_METHOD(RuntimeIdCompare)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            auto remoteElement = op.ImportElement(calc.as<winrt::AutomationElement>());

            auto runtimeId1 = remoteElement.GetPropertyValue(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_RuntimeIdPropertyId))).AsArray();
            auto runtimeId2 = remoteElement.GetPropertyValue(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_RuntimeIdPropertyId))).AsArray();
            auto eq1 = runtimeId1.IsEqual(runtimeId2);

            auto sibling = remoteElement.GetNextSiblingElement();
            auto runtimeId3 = sibling.GetPropertyValue(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_RuntimeIdPropertyId))).AsArray();
            auto eq2 = runtimeId1.IsEqual(runtimeId3);

            auto original = sibling.GetPreviousSiblingElement();
            auto runtimeId4 = original.GetPropertyValue(op.NewEnum(static_cast<winrt::AutomationPropertyId>(UIA_RuntimeIdPropertyId))).AsArray();
            auto eq3 = runtimeId1.IsEqual(runtimeId4);

            auto eq1Token = op.RequestResponse(eq1);
            auto eq2Token = op.RequestResponse(eq2);
            auto eq3Token = op.RequestResponse(eq3);
            auto results = op.Execute();

            AssertSucceeded(results.OperationStatus());
            Assert::AreEqual(true, winrt::unbox_value<bool>(results.GetResult(eq1Token)));
            Assert::AreEqual(false, winrt::unbox_value<bool>(results.GetResult(eq2Token)));
            Assert::AreEqual(true, winrt::unbox_value<bool>(results.GetResult(eq3Token)));
        }

        // Tests that when the provider doesn't support GetMetadataValue we get the expected result.
        TEST_METHOD(GetMetadataValueUnsupported)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            auto remoteElement = op.ImportElement(calc.as<winrt::AutomationElement>());

            auto remoteMetadata = remoteElement.GetMetadataValue(op.NewEnum(winrt::AutomationPropertyId::Name), op.NewEnum(winrt::AutomationMetadata::SayAsInterpretAs));

            auto remoteIsNull = remoteMetadata.IsNull();

            auto metadataToken = op.RequestResponse(remoteMetadata);
            auto isNullToken = op.RequestResponse(remoteIsNull);
            auto results = op.Execute();

            AssertSucceeded(results.OperationStatus());
            Assert::AreEqual(true, winrt::unbox_value<bool>(results.GetResult(isNullToken)));
            Assert::IsTrue(results.GetResult(metadataToken) == nullptr);
        }

        // Test that calling IsOpcodeSupported works after we import an
        // element, establishing a connection.
        TEST_METHOD(IsOpcodeSupported_AfterImport)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::AutomationRemoteOperation op;
            auto remoteElement = op.ImportElement(calc.as<winrt::AutomationElement>());

            Assert::IsTrue(op.IsOpcodeSupported(0x0 /*Nop*/));
            Assert::IsTrue(op.IsOpcodeSupported(0x48 /*NewGuid*/));
            Assert::IsFalse(op.IsOpcodeSupported(10000000000000));
        }

        // Test that calling IsOpcodeSupported fails on certain Windows builds
        // if we haven't imported an element yet, thus not establishing a
        // connection.
        TEST_METHOD(IsOpcodeSupported_BeforeImport)
        {
            winrt::AutomationRemoteOperation op;

            const auto hr = wil::ResultFromException([&]()
            {
                op.IsOpcodeSupported(0x0);
            });

            // TODO #77: Do a Windows version check once a build with this
            // failing behavior is released.
            // Assert::AreEqual(E_FAIL, hr);
        }
    };
}
