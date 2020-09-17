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

    auto InitializeUiaOperationAbstraction(const bool useRemoteOperations)
    {
        winrt::com_ptr<IUIAutomation> automation;
        THROW_IF_FAILED(::CoCreateInstance(__uuidof(CUIAutomation8), nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(automation.put())));
        UiaOperationAbstraction::Initialize(useRemoteOperations, automation.get());

        return wil::scope_exit([]()
        {
            UiaOperationAbstraction::Cleanup();
        });
    }

    TEST_CLASS(UiaOperationAbstractionTests)
    {
    public:
        // Asserts that you can get the name of a UiaElement.
        void ElementGetNameTest(const bool useRemoteOperations)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

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

        // Asserts that you can get the runtime id of a UiaElement.
        void ElementGetRuntimeIdTest(const bool useRemoteOperations)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            unique_safearray expected;
            THROW_IF_FAILED(calc->GetRuntimeId(&expected));

            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;
            auto runtimeId = element.GetRuntimeId();
            scope.BindResult(runtimeId);

            scope.Resolve();

            std::vector<int> actual = *runtimeId;
            SafeArrayAccessor<int> sa(expected.get(), VT_I4);
            for (unsigned int i = 0; i < actual.size(); ++i)
            {
                Assert::AreEqual(actual[i], sa[i]);
            }
        }

        TEST_METHOD(ElementGetRuntimeIdLocalTest)
        {
            ElementGetRuntimeIdTest(false);
        }

        TEST_METHOD(ElementGetRuntimeIdRemoteTest)
        {
            ElementGetRuntimeIdTest(true);
        }

        // Asserts that a pattern method (in this case GetEnclosingElement) can
        // be called with or without a cache request.
        void CacheRequestPatternMethodTest(const bool useRemoteOperations)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            const auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;
            UiaElement childText = element.GetFirstChildElement().GetFirstChildElement();
            UiaTextPattern textPattern = childText.GetTextPattern(false /*useCached*/);
            UiaTextRange textRange = textPattern.GetDocumentRange();

            UiaOperationAbstraction::UiaCacheRequest cacheRequest;
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

        TEST_METHOD(CacheRequestPatternMethodLocalTest)
        {
            CacheRequestPatternMethodTest(false);
        }

        TEST_METHOD(CacheRequestPatternMethodRemoteTest)
        {
            CacheRequestPatternMethodTest(true);
        }

        // Asserts that a navigation method (in this case GetParentElement) can
        // be called with or without a cache request.
        void CacheRequestNavigationMethodTest(const bool useRemoteOperations)
        {
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            const auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;

            UiaOperationAbstraction::UiaCacheRequest cacheRequest;
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

        TEST_METHOD(CacheRequestNavigationMethodLocalTest)
        {
            CacheRequestNavigationMethodTest(false);
        }

        TEST_METHOD(CacheRequestNavigationMethodRemoteTest)
        {
            CacheRequestNavigationMethodTest(true);
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

        void StringIndexing(const bool useRemoteOperations)
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

            auto name = element.GetName(false /* useCached */);

            auto c1 = name.At(0);
            UiaUint i = name.Length();
            i -= 1;
            auto c2 = name.At(i);

            UiaBool b1 = c1 == UiaChar(L'D');
            UiaBool b2 = c1 != UiaChar(L'D');
            UiaBool b3 = name.At(0) == name.At(0);
            UiaBool b4 = name.At(0) == name.At(1);

            UiaString hardCodedString{ L"ABCD" };
            UiaBool b5 = hardCodedString.At(3) == name.At(0);
            UiaBool b6 = name.At(0) == hardCodedString.At(3);
            UiaBool b7 = hardCodedString.At(3) == UiaChar(L'D');

            UiaArray<UiaChar> characters;
            characters.Append(c1);
            characters.Append(c2);

            scope.BindResult(c1);
            scope.BindResult(c2);

            scope.BindResult(b1);
            scope.BindResult(b2);
            scope.BindResult(b3);
            scope.BindResult(b4);
            scope.BindResult(b5);
            scope.BindResult(b6);
            scope.BindResult(b7);

            scope.BindResult(characters);

            scope.Resolve();

            {
                Assert::AreEqual(static_cast<wchar_t>(c1), L'D');
                Assert::AreEqual(static_cast<wchar_t>(c2), L'0');

                Assert::AreEqual(static_cast<bool>(b1), true);
                Assert::AreEqual(static_cast<bool>(b2), false);
                Assert::AreEqual(static_cast<bool>(b3), true);
                Assert::AreEqual(static_cast<bool>(b4), false);
                Assert::AreEqual(static_cast<bool>(b5), true);
                Assert::AreEqual(static_cast<bool>(b6), true);
                Assert::AreEqual(static_cast<bool>(b7), true);

                std::vector<wchar_t>& chars = *characters;
                Assert::AreEqual(chars[0], L'D');
                Assert::AreEqual(chars[1], L'0');
            }
        }

        TEST_METHOD(StringIndexingLocal)
        {
            StringIndexing(false);
        }

        TEST_METHOD(StringIndexingRemote)
        {
            StringIndexing(true);
        }

        void RectDimensions(bool useRemoteOperations)
        {
            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Initialize the UIA Remote Operation abstraction.
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Fetch bounding rectangle for the focused display field.
            //
            // Since the UIA abstraction type mimics how `winrt::Windows::Foundation::Rect` works, use that
            // as the type to compare against.
            winrt::Windows::Foundation::Rect boundingRect{};
            {
                auto operationScope = UiaOperationScope::StartNew();

                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                auto boundingRectangle = displayElement.GetBoundingRectangle(false /* useCachedApi */);
                operationScope.BindResult(boundingRectangle);
                operationScope.Resolve();

                boundingRect = boundingRectangle;
            }

            // Before doing anything else, make sure the bounding rectangle is not empty.
            //
            // Do not compare the screen placement since the application (and therefore the element) can be
            // at any screen position.
            {
                Assert::IsTrue(boundingRect.Width > 0);
                Assert::IsTrue(boundingRect.Height > 0);
            }

            // Now that we have the bounding rectangle of the element, perform another operation that reads
            // and returns individual fields of that bounding rectangle (using `UiaRect` APIs).
            double x = 0.0;
            double y = 0.0;
            double width = 0.0;
            double height = 0.0;
            {
                // Execute an operation to get individual fields that build the bounding rectangle.
                auto operationScope = UiaOperationScope::StartNew();

                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Decompose the bounding rectangle into individual fields.
                auto boundingRectangle = displayElement.GetBoundingRectangle(false /* useCachedApi */);
                auto boundingRectangleX = boundingRectangle.GetX();
                auto boundingRectangleY = boundingRectangle.GetY();
                auto boundingRectangleWidth = boundingRectangle.GetWidth();
                auto boundingRectangleHeight = boundingRectangle.GetHeight();

                // Return the field values.
                operationScope.BindResult(boundingRectangleX);
                operationScope.BindResult(boundingRectangleY);
                operationScope.BindResult(boundingRectangleWidth);
                operationScope.BindResult(boundingRectangleHeight);
                operationScope.Resolve();

                // Convert abstraction types to local types.
                std::tie(x, y, width, height) = std::tuple(boundingRectangleX, boundingRectangleY, boundingRectangleWidth, boundingRectangleHeight);
            }

            // Compare fields of the element's bounding rectangle against the just-fetched values.
            {
                Assert::AreEqual(static_cast<double>(boundingRect.X), x);
                Assert::AreEqual(static_cast<double>(boundingRect.Y), y);
                Assert::AreEqual(static_cast<double>(boundingRect.Width), width);
                Assert::AreEqual(static_cast<double>(boundingRect.Height), height);
            }
        }

        TEST_METHOD(RectDimensionsLocal)
        {
            RectDimensions(false /* useRemoteOperations */);
        }

        TEST_METHOD(RectDimensionsRemote)
        {
            RectDimensions(true /* useRemoteOperations */);
        }
    };
}
