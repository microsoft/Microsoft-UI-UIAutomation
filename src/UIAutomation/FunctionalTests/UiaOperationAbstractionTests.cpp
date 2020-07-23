// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "CppUnitTest.h"

#include "ModernApp.h"
#include "TestUtils.h"

#include "UiaOperationAbstraction.h"

using namespace UiaOperationAbstraction;

namespace UiaOperationAbstractionTests
{
    // Detect whether a type can be returned from a remote operation. A user
    // passes a single type parameter T in to CanBeReturned, and the type's
    // underlying boolean value will represent whether the type can be returned
    // or not.
    //
    // This works using a behavior called SFINAE. We define two overloads for
    // CanBeReturned: one that inherits from true_type and one that inherits
    // from false_type. When C++ is deciding which overload to choose, it
    // starts with the true_type one, since it has the most specific signature.
    // If the overload isn't ill-formed (i.e. the expression in decltype
    // successfully compiles), the compiler will select that overload.
    // Otherwise, it will move on to the false_type overload, which is never
    // ill-formed. This means that the boolean value of the type is known at
    // compile-time, and can be compared against an expected value.
    //
    // We use FromRemoteResult to test for whether the type can be returned
    // because while calling BindResult on an un-returnable type would also
    // fail to compile, the compiler can't detect compilation failures within
    // that function. It can only reason about the flat expression in decltype.
    template<class, class = std::void_t<>>
    struct CanBeReturned : std::false_type{};

    template<class T>
    struct CanBeReturned<T,
            std::void_t<decltype(std::declval<T>().FromRemoteResult(std::declval<winrt::Windows::Foundation::IInspectable>()))>
        > : std::true_type{};

    TEST_CLASS(UiaOperationAbstractionTests)
    {
    public:
        // Asserts that you can get the name of a UiaElement.
        void ElementGetNameTest(const bool useRemoteOperations)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::com_ptr<IUIAutomation> automation;
            THROW_IF_FAILED(::CoCreateInstance(__uuidof(CUIAutomation8), nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(automation.put())));
            UiaOperationAbstraction::Initialize(useRemoteOperations, automation.get());
            auto cleanup = wil::scope_exit([&]()
            {
                UiaOperationAbstraction::Cleanup();
            });

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;
            auto name = element.GetName(false /*useCachedApi*/);
            scope.BindResult(name);

            scope.Resolve();

            Assert::AreEqual(std::wstring(static_cast<wil::shared_bstr>(name).get()), std::wstring(L"Display is 0"));
        }
        TEST_METHOD(ElementGetNameLocalTest)
        {
            ElementGetNameTest(false);
        }

        TEST_METHOD(ElementGetNameRemoteTest)
        {
            ElementGetNameTest(true);
        }

        // Asserts that GetEnclosingElement can be called with a cache request.
        void GetEnclosingElementTest(const bool useRemoteOperations)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::com_ptr<IUIAutomation> automation;
            THROW_IF_FAILED(::CoCreateInstance(__uuidof(CUIAutomation8), nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(automation.put())));
            UiaOperationAbstraction::Initialize(useRemoteOperations, automation.get());
            auto cleanup = wil::scope_exit([&]()
            {
                UiaOperationAbstraction::Cleanup();
            });

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;
            UiaElement childText = element.GetFirstChildElement().GetFirstChildElement();
            UiaTextPattern textPattern = childText.GetTextPattern(false /*useCached*/);
            UiaTextRange textRange = textPattern.GetDocumentRange();

            auto cacheRequest = UiaOperationScope::GetCurrentDelegator()->CreateCacheRequest();
            cacheRequest.AddProperty(UIA_NamePropertyId);
            cacheRequest.AddPattern(UIA_TextPatternId);

            auto uncachedTextElement = textRange.GetEnclosingElement();
            auto cachedTextElement = textRange.GetEnclosingElement(cacheRequest);
            scope.BindResult(uncachedTextElement);
            scope.BindResult(cachedTextElement);

            scope.Resolve();

            {
                Assert::ExpectException<winrt::hresult_error>([&]()
                {
                    uncachedTextElement.GetName(true /*useCachedApi*/);
                });
                Assert::ExpectException<winrt::hresult_error>([&]()
                {
                    uncachedTextElement.GetTextPattern(true /*useCachedApi*/);
                });
            }

            {
                const auto name = cachedTextElement.GetName(true /*useCachedApi*/);
                Assert::IsNotNull(name.get());
                Assert::AreEqual(std::wstring(name.get()), std::wstring(L"0"));

                auto pattern = cachedTextElement.GetTextPattern(true /*useCachedApi*/);
                Assert::IsNotNull(pattern.get());
                const auto selection = pattern.GetSupportedTextSelection();
                Assert::AreEqual(static_cast<uint32_t>(selection), static_cast<uint32_t>(SupportedTextSelection_Single));
            }
        }

        TEST_METHOD(GetEnclosingElementLocalTest)
        {
            GetEnclosingElementTest(false);
        }

        TEST_METHOD(GetEnclosingElementRemoteTest)
        {
            GetEnclosingElementTest(true);
        }

        // Asserts that GetParentElement can be called with a cache request.
        void GetParentElementTest(const bool useRemoteOperations)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            winrt::com_ptr<IUIAutomation> automation;
            THROW_IF_FAILED(::CoCreateInstance(__uuidof(CUIAutomation8), nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(automation.put())));
            UiaOperationAbstraction::Initialize(useRemoteOperations, automation.get());
            auto cleanup = wil::scope_exit([&]()
            {
                UiaOperationAbstraction::Cleanup();
            });

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;

            auto cacheRequest = UiaOperationScope::GetCurrentDelegator()->CreateCacheRequest();
            cacheRequest.AddProperty(UIA_NamePropertyId);
            cacheRequest.AddPattern(UIA_TextPatternId);

            // Get the parent of the parent, since this should be the window element.
            auto uncachedParent = element.GetParentElement().GetParentElement();
            auto cachedParent = element.GetParentElement().GetParentElement(cacheRequest);
            scope.BindResult(uncachedParent);
            scope.BindResult(cachedParent);

            scope.Resolve();

            {
                Assert::ExpectException<winrt::hresult_error>([&]()
                {
                    uncachedParent.GetName(true /*useCachedApi*/);
                });
                Assert::ExpectException<winrt::hresult_error>([&]()
                {
                    uncachedParent.GetTextPattern(true /*useCachedApi*/);
                });
            }

            {
                const auto name = cachedParent.GetName(true /*useCachedApi*/);
                Assert::IsNotNull(name.get());
                Assert::AreEqual(std::wstring(name.get()), std::wstring(L"Calculator"));

                const auto pattern = cachedParent.GetTextPattern(true /*useCachedApi*/);
                // This element does not support the text pattern.
                Assert::IsNull(pattern.get());
            }
        }

        TEST_METHOD(GetParentElementLocalTest)
        {
            GetParentElementTest(false);
        }

        TEST_METHOD(GetParentElementRemoteTest)
        {
            GetParentElementTest(true);
        }

        // Asserts that UiaCacheRequest can't be returned from a remote
        // operation. If this test fails, it will fail at compile time.
        TEST_METHOD(CantReturnCacheRequestTest)
        {
            // Check CanBeReturned on UiaElement just to double check it's working.
            static constexpr bool elementCanBeReturned = CanBeReturned<UiaElement>::value;
            static_assert(elementCanBeReturned, "UiaElement should be able to be returned from a remote operation.");

            static constexpr bool cacheRequestCanBeReturned = CanBeReturned<UiaOperationAbstraction::UiaCacheRequest>::value;
            static_assert(!cacheRequestCanBeReturned, "UiaCacheRequest should not be able to be returned from a remote operation.");
        }
    };
}
