// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "CppUnitTest.h"

#include "ModernApp.h"
#include "TestUtils.h"

#include "UiaOperationAbstraction.h"
#include "SafeArrayUtil.h"

using namespace UiaOperationAbstraction;
using namespace SafeArrayUtil;

// Test framework extensions used for comparing and printing different types via the
// `Assert` test functions.
namespace Microsoft::VisualStudio::CppUnitTestFramework
{
    template<>
    std::wstring ToString(const std::vector<int>& vec)
    {
        std::wstringstream ss;
        ss << L"[";

        for (size_t i = 0; i < vec.size(); ++i)
        {
            if (i != 0)
            {
                ss << L", ";
            }

            ss << vec[i];
        }

        ss << L"]";
        return ss.str();
    }

    template<>
    std::wstring ToString(const std::map<std::wstring, int>& map)
    {
        std::wstringstream ss;
        ss << L"{";

        for (const auto& mapEntry : map)
        {
            ss << L"\n    <" << mapEntry.first << L", " << mapEntry.second << "L>,";
        }

        if (!map.empty())
        {
            ss << L"\n";
        }

        ss << L"}";
        return ss.str();
    }

    template<std::size_t I, class... Args>
    void TupleToStringStream([[maybe_unused]] const std::tuple<Args...>& tuple, [[maybe_unused]] std::wstringstream& stream)
    {
        if constexpr (I < sizeof...(Args))
        {
            // Add the current field/value of the tuple.
            if constexpr (I != 0)
            {
                stream << L", ";
            }

            stream << std::get<I>(tuple);

            // And move to adding the next onto to the stream (if any remain).
            TupleToStringStream<I + 1>(tuple, stream);
        }
    }

    template<class... Args>
    std::wstring TupleToString(const std::tuple<Args...>& tuple)
    {
        std::wstringstream ss;

        ss << L"<";
        TupleToStringStream<0>(tuple, ss);
        ss << L">";

        return ss.str();
    }

    template<>
    std::wstring ToString(const std::tuple<int>& tuple)
    {
        return TupleToString(tuple);
    }

    template<>
    std::wstring ToString(const std::tuple<std::wstring, int>& tuple)
    {
        return TupleToString(tuple);
    }
}

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
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

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

        // Asserts that you can get the name of a UiaElement via a property ID.
        void GetPropertyValueFetchNameTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;
            auto val = element.GetPropertyValue(UiaPropertyId(UIA_NamePropertyId));
            auto name = val.AsString();
            scope.BindResult(name);

            scope.Resolve();

            Assert::AreEqual(std::wstring(static_cast<wil::shared_bstr>(name).get()), std::wstring(L"Display is 0"));
        }

        TEST_METHOD(GetPropertyValueFetchNameLocalTest)
        {
            GetPropertyValueFetchNameTest(false);
        }

        TEST_METHOD(GetPropertyValueFetchNameRemoteTest)
        {
            GetPropertyValueFetchNameTest(true);
        }

        // Tests that GetPropertyValue with ignoreDefault true raises an exception on an unimplemented property ID
        // and that ignoreDefault false correctly returns a default value.
        void GetPropertyValueIgnoreDefaultTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;

            auto defaultVal = element.GetPropertyValue(UiaPropertyId(UIA_AriaPropertiesPropertyId), false /*ignoreDefault*/);
            scope.BindResult(defaultVal);
            auto ariaProperties = defaultVal.AsString();
            scope.BindResult(ariaProperties);

            auto notSupportedVal = element.GetPropertyValue(UiaPropertyId(UIA_AriaPropertiesPropertyId), true /*ignoreDefault*/);
            scope.BindResult(notSupportedVal);

            scope.Resolve();

            Assert::AreEqual(static_cast<bool>(defaultVal.IsNotSupported()), false);
            Assert::AreEqual(std::wstring(static_cast<wil::shared_bstr>(ariaProperties).get()), std::wstring(L""));
            Assert::AreEqual(static_cast<bool>(notSupportedVal.IsNotSupported()), true);
        }

        TEST_METHOD(GetPropertyValueIgnoreDefaultLocalTest)
        {
            GetPropertyValueIgnoreDefaultTest(false);
        }

        TEST_METHOD(GetPropertyValueIgnoreDefaultRemoteTest)
        {
            GetPropertyValueIgnoreDefaultTest(true);
        }

        // Tests GetPropertyValue with useCachedAPI set to true and false
        // Ensuring that an exception is raised if trying to fetch a cached value that is not cached. 
        void GetPropertyValueUseCachedAPITest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();

            UiaElement elementWithoutCache = calc;
            scope.BindResult(elementWithoutCache);

            UiaOperationAbstraction::UiaCacheRequest cacheRequest;
            cacheRequest.AddProperty(UIA_NamePropertyId);

            auto elementWithCache = elementWithoutCache.GetUpdatedCacheElement(cacheRequest);
            scope.BindResult(elementWithCache);

            scope.Resolve();

            UiaString cachedNameFromElementWithCache = elementWithCache.GetPropertyValue(UiaPropertyId(UIA_NamePropertyId), /*ignoreDefault=*/ false, /*useCachedApi=*/ true).AsString();
            Assert::AreEqual(std::wstring(static_cast<wil::shared_bstr>(cachedNameFromElementWithCache).get()), std::wstring(L"Display is 0"));

            UiaString uncachedNameFromElementWithCache = elementWithCache.GetPropertyValue(UiaPropertyId(UIA_NamePropertyId), /*ignoreDefault=*/ false, /*useCachedApi=*/ false).AsString();
            Assert::AreEqual(std::wstring(static_cast<wil::shared_bstr>(uncachedNameFromElementWithCache).get()), std::wstring(L"Display is 0"));

            Assert::ExpectException<winrt::hresult_error>([&]()
            {
                elementWithoutCache.GetPropertyValue(UiaPropertyId(UIA_NamePropertyId), /*ignoreDefault=*/ false, /*useCachedApi=*/ true);
            });

            UiaString uncachedNameFromElementWithoutCache = elementWithoutCache.GetPropertyValue(UiaPropertyId(UIA_NamePropertyId), /*ignoreDefault=*/ false, /*useCachedApi=*/ false).AsString();
            Assert::AreEqual(std::wstring(static_cast<wil::shared_bstr>(uncachedNameFromElementWithoutCache).get()), std::wstring(L"Display is 0"));
        }

        TEST_METHOD(GetPropertyValueUseCachedAPILocalTest)
        {
            GetPropertyValueUseCachedAPITest(false);
        }

        TEST_METHOD(GetPropertyValueUseCachedAPIRemoteTest)
        {
            GetPropertyValueUseCachedAPITest(true);
        }

        // Asserts that you can get the runtime id of a UiaElement.
        void ElementGetRuntimeIdTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            unique_safearray expected;
            THROW_IF_FAILED(calc->GetRuntimeId(&expected));

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;
            auto runtimeId = element.GetRuntimeId();
            scope.BindResult(runtimeId);

            scope.Resolve();

            std::vector<int> actual = *runtimeId;
            SafeArrayAccessor<int> sa(expected.get(), VT_I4);

            // Verify the size of runtime id.
            Assert::AreEqual(static_cast<uint32_t>(actual.size()), static_cast<uint32_t>(sa.Count()));

            // Verify individual number of runtime id.
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
            const auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

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
            const auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

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

        // This test aims to test the wrapper implementation could
        // elegantly handle the case that UIA navigation hits a
        // boundary element which means the navigation API does not
        // find the desired element. In this case, we should simply
        // return an empty element even a cache request is provided.
        // This test is only targeted for scenario with remote operation
        // enabled, the reason is that GetParentElement API works
        // differently in local context and remote context. Specifically,
        // with remote operation enable, the API will only work within
        // single connection, if the parent element is in a different
        // process, then remote operation will not be able to find and
        // return it, by design we are able to get the ancestor chain
        // until the root node of test app everytime using remote operation,
        // but it is not fully prediactable using local API context.
        // Also, this tests aims to provide test coverage for code path
        // running in remote context only in wrapper implementation with.
        TEST_METHOD(CacheRequestNavigationNullReturnRemoteTest)
        {
            const auto guard = InitializeUiaOperationAbstraction(true /* useRemoteOperation */);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;

            UiaOperationAbstraction::UiaCacheRequest cacheRequest;
            cacheRequest.AddProperty(UIA_NamePropertyId);

            UiaArray<UiaElement> parentChain;
            scope.While(
                [&]() // condition
                {
                    return !element.IsNull();
                },
                [&]() // body
                {
                    parentChain.Append(element);
                    // The last element we get should be Null here, we are testing wrapper implementation
                    // could make sure the whole operation won't abort due to this.
                    UiaElement parent = element.GetParentElement(cacheRequest);
                    element = parent;
                });

            scope.BindResult(parentChain);
            scope.Resolve();

            // There should be three elements in total in this case.
            unsigned int size = parentChain.Size();
            Assert::AreEqual(3, static_cast<int>(size));

            // The last element is the Calculator core window element.
            auto ancestor = parentChain.GetAt(2);
            auto name = ancestor.GetName(true /* useCachedApi */);
            Assert::IsNotNull(name.get());
            Assert::AreEqual(std::wstring(name.get()), std::wstring(L"Calculator"));
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
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

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
                operationScope.BindResult(boundingRectangleX, boundingRectangleY, boundingRectangleWidth, boundingRectangleHeight);
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

        void ArrayEqualityComparisonTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;
            UiaArray<UiaInt> runtimeIdFirst = element.GetRuntimeId();
            UiaArray<UiaInt> runtimeIdSecond = element.GetRuntimeId();

            UiaBool sameElementEqualResult{ false };
            sameElementEqualResult = (runtimeIdFirst == runtimeIdSecond);
            UiaBool sameElementNonEqualResult{ true };
            sameElementNonEqualResult = (runtimeIdFirst != runtimeIdSecond);

            UiaElement parent = element.GetParentElement();
            UiaArray<UiaInt> runtimeIdParent = parent.GetRuntimeId();

            UiaBool diffElementEqualResult{ true };
            diffElementEqualResult = (runtimeIdFirst == runtimeIdParent);
            UiaBool diffElementNonEqualResult{ false };
            diffElementNonEqualResult = (runtimeIdFirst != runtimeIdParent);

            scope.BindResult(sameElementEqualResult);
            scope.BindResult(sameElementNonEqualResult);
            scope.BindResult(diffElementEqualResult);
            scope.BindResult(diffElementNonEqualResult);

            scope.Resolve();

            Assert::IsTrue(sameElementEqualResult);
            Assert::IsFalse(sameElementNonEqualResult);
            Assert::IsFalse(diffElementEqualResult);
            Assert::IsTrue(diffElementNonEqualResult);
        }

        TEST_METHOD(ArrayEqualityComparisonLocalTest)
        {
            ArrayEqualityComparisonTest(false);
        }

        TEST_METHOD(ArrayEqualityComparisonRemoteTest)
        {
            ArrayEqualityComparisonTest(true);
        }

        void StringifyTest(const bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Test all types that are convertible to strings:
            // -> Boolean
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Import the focused element to contextualize the operation to execute.
                UiaElement displayElement{ focusedElement  };
                operationScope.BindInput(displayElement);

                // Create values to convert to strings and covert them.
                UiaBool falseBool{ false };
                UiaBool trueBool{ true };

                auto falseBoolString = falseBool.Stringify();
                auto trueBoolString = trueBool.Stringify();

                // Resolve the values.
                operationScope.BindResult(falseBoolString);
                operationScope.BindResult(trueBoolString);
                operationScope.Resolve();

                // And compare them against expectations.
                Assert::AreEqual(std::wstring(L"false"), falseBoolString.GetLocalWstring());
                Assert::AreEqual(std::wstring(L"true"), trueBoolString.GetLocalWstring());
            }

            // -> Numeric
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Import the focused element to contextualize the operation to execute.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create values to convert to strings and covert them.
                UiaInt intValue{ 5 };
                UiaUint uintValue{ 7 };
                UiaDouble doubleValue{ 10.0 };

                auto intValueString = intValue.Stringify();
                auto uintValueString = uintValue.Stringify();
                auto doubleValueString = doubleValue.Stringify();

                // Resolve the values.
                operationScope.BindResult(intValueString);
                operationScope.BindResult(uintValueString);
                operationScope.BindResult(doubleValueString);
                operationScope.Resolve();

                // And compare them against expectations.
                Assert::AreEqual(std::wstring(L"5"), intValueString.GetLocalWstring());
                Assert::AreEqual(std::wstring(L"7"), uintValueString.GetLocalWstring());
                Assert::AreEqual(std::wstring(L"10.000000"), doubleValueString.GetLocalWstring());
            }

            // -> Character
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Import the focused element to contextualize the operation to execute.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create values to convert to strings and covert them.
                UiaString stringValue{ L"MyString" };
                UiaChar charValue{ L'M' };

                auto stringValueString = stringValue.Stringify();
                auto charValueString = charValue.Stringify();

                // Resolve the values.
                operationScope.BindResult(stringValueString);
                operationScope.BindResult(charValueString);
                operationScope.Resolve();

                // And compare them against expectations.
                Assert::AreEqual(std::wstring(L"MyString"), stringValueString.GetLocalWstring());
                Assert::AreEqual(std::wstring(L"M"), charValueString.GetLocalWstring());
            }

            // -> Point and Rectangle
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Import the focused element to contextualize the operation to execute.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create values to convert to strings and covert them.
                UiaOperationAbstraction::UiaPoint pointValue{ POINT{ 5 /* X */, 5 /* Y */ } };
                UiaOperationAbstraction::UiaRect rectValue{ winrt::Windows::Foundation::Rect{ 5.0f /* X */, 5.0f /* Y */, 10.0f /* Width */, 10.0f /* Height */ } };

                auto pointValueString = pointValue.Stringify();
                auto rectValueString = rectValue.Stringify();

                // Resolve the values.
                operationScope.BindResult(pointValueString);
                operationScope.BindResult(rectValueString);
                operationScope.Resolve();

                // And compare them against expectations.
                Assert::AreEqual(std::wstring(L"Point{ 5,5 }"), pointValueString.GetLocalWstring());
                Assert::AreEqual(std::wstring(L"Rect{ 5,5,10,10 }"), rectValueString.GetLocalWstring());
            }

            // -> Array of type
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Import the focused element to contextualize the operation to execute.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create values to convert to strings and covert them.
                UiaArray<UiaInt> intArray{ std::vector<int>{ 5, 6, 7 } };
                UiaArray<UiaString> stringArray{ std::vector<wil::shared_bstr>{ wil::make_bstr(L"String1"), wil::make_bstr(L"String2") } };

                auto intArrayString = intArray.Stringify();
                auto stringArrayString = stringArray.Stringify();

                // Resolve the values.
                operationScope.BindResult(intArrayString);
                operationScope.BindResult(stringArrayString);
                operationScope.Resolve();

                // And compare them against expectations.
                Assert::AreEqual(std::wstring(L"[5,6,7]"), intArrayString.GetLocalWstring());
                Assert::AreEqual(std::wstring(L"[String1,String2]"), stringArrayString.GetLocalWstring());
            }
        }

        TEST_METHOD(StringifyTestLocal)
        {
            StringifyTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(StringifyTestRemote)
        {
            StringifyTest(true /* useRemoteOperations */);
        }

        void GetUpdatedCacheElement(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Rebuild the cache of the focused element using two different cache requests with distinct
            // properties in them to test that the rebuilt elements are different and contain requested
            // and expected properties in their cache.
            winrt::com_ptr<IUIAutomationElement> elementWithName;
            winrt::com_ptr<IUIAutomationElement> elementWithControlType;
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Import the element to the remote operation.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create two distinct cache requests to return two objects representing the same element
                // but with different cached properties.
                UiaOperationAbstraction::UiaCacheRequest cacheRequestWithName;
                cacheRequestWithName.AddProperty(UIA_NamePropertyId);

                UiaOperationAbstraction::UiaCacheRequest cacheRequestWithControlType;
                cacheRequestWithControlType.AddProperty(UIA_ControlTypePropertyId);

                // Rebuild the imported element with the filled cache requests.
                auto remoteElementWithName = displayElement.GetUpdatedCacheElement(cacheRequestWithName);
                auto remoteElementWithControlType = displayElement.GetUpdatedCacheElement(cacheRequestWithControlType);
                operationScope.BindResult(remoteElementWithName);
                operationScope.BindResult(remoteElementWithControlType);
                operationScope.Resolve();

                elementWithName = remoteElementWithName;
                elementWithControlType = remoteElementWithControlType;
            }

            // Test the first element to make sure its cached property values contain `Name` but not `ControlType`.
            {
                wil::unique_variant name;
                const HRESULT nameHr = elementWithName->GetCachedPropertyValueEx(UIA_NamePropertyId, TRUE /* ignoreDefaultValue */, &name);

                wil::unique_variant controlType;
                const HRESULT controlTypeHr = elementWithName->GetCachedPropertyValueEx(UIA_ControlTypePropertyId, TRUE /* ignoreDefaultValue */, &controlType);

                Assert::AreEqual(S_OK, nameHr);
                Assert::AreEqual(E_INVALIDARG, controlTypeHr);
            }

            // Test the second element whose cache should contain `ControlType` but not `Name`.
            {
                wil::unique_variant name;
                const HRESULT nameHr = elementWithControlType->GetCachedPropertyValueEx(UIA_NamePropertyId, TRUE /* ignoreDefaultValue */, &name);

                wil::unique_variant controlType;
                const HRESULT controlTypeHr = elementWithControlType->GetCachedPropertyValueEx(UIA_ControlTypePropertyId, TRUE /* ignoreDefaultValue */, &controlType);

                Assert::AreEqual(E_INVALIDARG, nameHr);
                Assert::AreEqual(S_OK, controlTypeHr);
            }
        }

        TEST_METHOD(GetUpdatedCacheElementLocal)
        {
            GetUpdatedCacheElement(false /* useRemoteOperations */);
        }

        TEST_METHOD(GetUpdatedCacheElementRemote)
        {
            GetUpdatedCacheElement(true /* useRemoteOperations */);
        }

        void ForEachLoop(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            {
                auto operationScope = UiaOperationScope::StartNew();

                // Import the element to the remote operation to contextualize it.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create an array to iterate over and add a few values to it.
                std::vector<int> values{ 1, 5, 8, 10, 7 };
                UiaArray<UiaInt> valueArray{ std::move(values) };

                // Now, iterate over the array and create a sum of found values but:
                // 1. Skip 5's,
                // 2. Break on 10's.
                UiaInt valueSum{ 0 };
                operationScope.ForEach(valueArray, [&](auto value)
                {
                    operationScope.ContinueIf(value == 5);
                    operationScope.BreakIf(value == 10);
                    valueSum += value;
                });

                // Resolve the sum.
                operationScope.BindResult(valueSum);
                operationScope.Resolve();

                // Compare the calculated sum against the expectations.
                Assert::AreEqual(9, static_cast<int>(valueSum));
            }
        }

        TEST_METHOD(ForEachLoopLocal)
        {
            ForEachLoop(false /* useRemoteOperations */);
        }

        TEST_METHOD(ForEachLoopRemote)
        {
            ForEachLoop(true /* useRemoteOperations */);
        }

        void ConvertRectTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Create rectangles using 2 different input types and check that they are the same when returned
            // back to the caller.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                UiaOperationAbstraction::UiaRect win32Rect{ RECT{ 5 /* left */, 5 /* top */, 10 /* right */, 10 /* bottom */} };
                UiaOperationAbstraction::UiaRect winrtRect{ winrt::Windows::Foundation::Rect{ 5 /* X */, 5 /* Y */, 5 /* Width */, 5 /* Height */} };
                UiaBool areRectsEqual = (win32Rect == winrtRect);

                // Return the result.
                operationScope.BindResult(areRectsEqual);
                operationScope.Resolve();

                // Ensure the two rectangles are equal.
                Assert::IsTrue(static_cast<bool>(areRectsEqual));
            }
        }

        TEST_METHOD(ConvertRectLocal)
        {
            ConvertRectTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(ConvertRectRemote)
        {
            ConvertRectTest(true /* useRemoteOperations */);
        }

        void UseCachedApiTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Ensure that the focused element has no Name cached for it (as otherwise we would not be
            // able to distinguish between asks for Cached and Current.
            {
                wil::unique_variant name;
                const HRESULT nameHr = focusedElement->GetCachedPropertyValueEx(UIA_NamePropertyId, TRUE /* ignoreDefaultValue */, &name);
                Assert::AreEqual(E_INVALIDARG, nameHr);
            }

            // Test that providing no `useCachedApi` has the same effect as providing `false`.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Import the element to query information for.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Ensure that `useCachedApi` defaults to `false` and therefore we should get the current
                // name in both cases.
                UiaString explicitlyCurrentName = displayElement.GetName(false /* useCachedApi */);
                UiaString implicitlyCurrentName = displayElement.GetName();

                // Resolve the sum.
                operationScope.BindResult(explicitlyCurrentName);
                operationScope.BindResult(implicitlyCurrentName);
                operationScope.Resolve();

                // Compare the names to ensure they are the same.
                Assert::AreEqual(explicitlyCurrentName.GetLocalWstring(), implicitlyCurrentName.GetLocalWstring());
            }
        }

        TEST_METHOD(UseCachedApiLocal)
        {
            UseCachedApiTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UseCachedApiRemote)
        {
            UseCachedApiTest(true /* useRemoteOperations */);
        }

        void CompareEnumTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Create an operation that fetches a `UiaEnum`-based property value for a UIA element and compare the
            // value against different values types that can be used to construct that property-specific `UiaEnum`
            // type.
            //
            // This ensures that common ways of comparing `UiaEnum`-based properties work.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Ask for the control type of the imported element (which is returned as a `UiaEnum`).
                auto controlType = displayElement.GetControlType(false /* useCachedApi */);

                // Compare the retrieved `UiaEnum` against different control type value representations.
                auto equalToAbstractionValue = (controlType == controlType);
                auto equalToComEnum = (controlType == UIA_TextControlTypeId);
                auto equalToWinRtEnum = (controlType == winrt::Microsoft::UI::UIAutomation::AutomationControlType::Text);

                auto notEqualToAbstractionValue = (controlType != controlType);
                auto notEqualToComEnum = (controlType != UIA_TextControlTypeId);
                auto notEqualToWinRtEnum = (controlType != winrt::Microsoft::UI::UIAutomation::AutomationControlType::Text);

                // Return the results of the comparisons.
                operationScope.BindResult(equalToAbstractionValue, equalToComEnum, equalToWinRtEnum, notEqualToAbstractionValue, notEqualToComEnum, notEqualToWinRtEnum);
                operationScope.Resolve();

                // Ensure the correct results have been returned.
                Assert::IsTrue(static_cast<bool>(equalToAbstractionValue));
                Assert::IsTrue(static_cast<bool>(equalToComEnum));
                Assert::IsTrue(static_cast<bool>(equalToWinRtEnum));
                Assert::IsFalse(static_cast<bool>(notEqualToAbstractionValue));
                Assert::IsFalse(static_cast<bool>(notEqualToComEnum));
                Assert::IsFalse(static_cast<bool>(notEqualToWinRtEnum));
            }
        }

        TEST_METHOD(CompareEnumLocal)
        {
            CompareEnumTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(CompareEnumRemote)
        {
            CompareEnumTest(true /* useRemoteOperations */);
        }

        void UiaArrayInCollectionsTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // This test creates `UiaArray` instances, builds an array out of them. The returned array
            // of arrays is tested against the expectations.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct a few arrays and create a collection out of them.
                const std::vector<int> baseValueArray{ 1, 2 };
                UiaArray<UiaInt> array1{ baseValueArray };
                UiaArray<UiaInt> array2{ baseValueArray };

                UiaArray<UiaArray<UiaInt>> arrays;
                arrays.Append(array1);
                arrays.Append(array2);

                // Return the collection of arrays.
                operationScope.BindResult(arrays);
                operationScope.Resolve();

                // Ensure the array is of the expected shape.
                const auto arraysSize = static_cast<unsigned int>(arrays.Size());
                Assert::AreEqual(static_cast<unsigned int>(2), arraysSize);

                for (unsigned int i = 0; i < arraysSize; ++i)
                {
                    const auto array = arrays.GetAt(i);
                    const auto& localArray = *array;
                    Assert::AreEqual(baseValueArray, localArray);
                }
            }

            // Perform the same test but with `UiaStringMap`.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct arrays of values and a map out of the arrays.
                const std::vector<int> baseValueArray{ 1, 2 };
                UiaArray<UiaInt> array1{ baseValueArray };
                UiaArray<UiaInt> array2{ baseValueArray };

                UiaStringMap<UiaArray<UiaInt>> arrayMap;
                arrayMap.Insert(L"array1", array1);
                arrayMap.Insert(L"array2", array2);

                // Return the collection.
                operationScope.BindResult(arrayMap);
                operationScope.Resolve();

                // Now, make sure the map contains the expected values.
                Assert::AreEqual(static_cast<size_t>(2), static_cast<size_t>(arrayMap.Size()));

                const std::array<std::wstring, 2> arrayKeys{ L"array1", L"array2" };
                for (const auto& arrayKey : arrayKeys)
                {
                    Assert::IsTrue(arrayMap.HasKey(arrayKey));

                    const auto array = arrayMap.Lookup(arrayKey);
                    const auto& localArray = *array;
                    Assert::AreEqual(baseValueArray, localArray);
                }
            }
        }

        TEST_METHOD(UiaArrayInCollectionsTestLocal)
        {
            UiaArrayInCollectionsTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaArrayInCollectionsTestRemote)
        {
            UiaArrayInCollectionsTest(true /* useRemoteOperations */);
        }

        void UiaStringMapInCollectionsTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // This test creates `UiaStringMap` instances, builds an array out of them and returns the array.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct a few map and create an array out of them.
                const std::map<std::wstring, int> baseValueMap{ { L"Value", 1 } };
                UiaStringMap<UiaInt> map1{ baseValueMap };
                UiaStringMap<UiaInt> map2{ baseValueMap };

                UiaArray<UiaStringMap<UiaInt>> maps;
                maps.Append(map1);
                maps.Append(map2);

                // Return the collection of maps.
                operationScope.BindResult(maps);
                operationScope.Resolve();

                // Ensure the array is of the expected shape.
                const auto mapsSize = static_cast<unsigned int>(maps.Size());
                Assert::AreEqual(static_cast<unsigned int>(2), mapsSize);

                for (unsigned int i = 0; i < mapsSize; ++i)
                {
                    const auto map = maps.GetAt(i);
                    const auto& localMap = *map;
                    Assert::AreEqual(baseValueMap, localMap);
                }
            }

            // Perform the same test but with `UiaStringMap`.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct a map of maps.
                const std::map<std::wstring, int> baseValueMap{ { L"Value", 1 } };
                UiaStringMap<UiaInt> map1{ baseValueMap };
                UiaStringMap<UiaInt> map2{ baseValueMap };

                UiaStringMap<UiaStringMap<UiaInt>> mapMap;
                mapMap.Insert(L"map1", map1);
                mapMap.Insert(L"map2", map2);

                // Return the map of maps.
                operationScope.BindResult(mapMap);
                operationScope.Resolve();

                // Now, make sure the map is of the expected shape.
                Assert::AreEqual(static_cast<size_t>(2), static_cast<size_t>(mapMap.Size()));

                const std::array<std::wstring, 2> mapKeys{ L"map1", L"map2" };
                for (const auto& mapKey : mapKeys)
                {
                    Assert::IsTrue(mapMap.HasKey(mapKey));

                    const auto map = mapMap.Lookup(mapKey);
                    const auto& localMap = *map;
                    Assert::AreEqual(baseValueMap, localMap);
                }
            }
        }

        TEST_METHOD(UiaStringMapInCollectionsTestLocal)
        {
            UiaStringMapInCollectionsTest(false /* useRemoteOperations */);
        }

        void UiaStringMapInElementTypeTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            auto operationScope = UiaOperationScope::StartNew();
            // Create a map that use UiaElement as the value.
            UiaStringMap<UiaElement> names;

            UiaElement displayElement{ focusedElement.get() };
            UiaString focusedName = displayElement.GetName();
            names.Insert(focusedName, displayElement);

            UiaElement parentElement = displayElement.GetParentElement();
            UiaString parentName = parentElement.GetName();
            names.Insert(parentName, parentElement);

            // Return the map of maps.
            operationScope.BindResult(names);
            operationScope.Resolve();

            // We just need to make sure we have a valid map that could carry element entries.
            Assert::AreEqual(static_cast<size_t>(2), static_cast<size_t>(names.Size()));
            auto resultElement = names.Lookup(L"Display is 0");
            Assert::IsNotNull(resultElement.get());
        }

        TEST_METHOD(UiaStringMapInElementTypeTestRemote)
        {
            UiaStringMapInElementTypeTest(true /* useRemoteOperations */);
        }

        TEST_METHOD(UiaStringMapInElementTypeTestLocal)
        {
            UiaStringMapInElementTypeTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaStringMapInCollectionsTestRemote)
        {
            UiaStringMapInCollectionsTest(true /* useRemoteOperations */);
        }

        void UiaTupleCreateTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // This test attempts to create `UiaTuple` instances in a few different ways, return them and ensure
            // the values behind them are correct.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct `UiaTuple` instances in a few different ways to confirm they can be constructed and
                // worked with.
                UiaTuple<UiaElement, UiaInt, UiaBool, UiaString> defaultConstructedTuple;
                UiaTuple<UiaElement, UiaInt, UiaBool, UiaString> localConstructedTuple{ focusedElement /* elementValue */, 1 /* intValue */, true /* booleanValue */, L"LocalConstructed" /* stringValue */ };
                UiaTuple<UiaElement, UiaInt, UiaBool, UiaString> wrapperConstructedTuple
                {
                    UiaElement{ focusedElement.get() } /* elementValue */,
                    UiaInt{ 2 } /* intValue */,
                    UiaBool{ true } /* booleanValue */,
                    UiaString{ L"WrapperConstructed" } /* stringValue */
                };

                UiaTuple<UiaElement, UiaInt, UiaBool, UiaString> moveAssignmentTuple{};
                UiaTuple<UiaElement, UiaInt, UiaBool, UiaString> tempTuple{ focusedElement /* elementValue */, 3 /* intValue */, true /* booleanValue */, L"MoveAssignment" /* stringValue */ };
                moveAssignmentTuple = std::move(tempTuple);

                // Return the results of the comparisons.
                operationScope.BindResult(defaultConstructedTuple, localConstructedTuple, wrapperConstructedTuple, moveAssignmentTuple);
                operationScope.Resolve();

                // Represents a local result of `UiaTuple<UiaElement, UiaInt, UiaBool, UiaString>`
                struct LocalTupleResult
                {
                    // Note: Assumes `tuple` contains local values only.
                    static LocalTupleResult FromResult(UiaTuple<UiaElement, UiaInt, UiaBool, UiaString>& tuple)
                    {
                        auto element = tuple.Get<0>();
                        return LocalTupleResult
                        {
                            (!element.IsNull() ? element.GetName().GetLocalWstring() : L"") /* name */,
                            tuple.Get<1>() /* numericValue */,
                            tuple.Get<2>() /* booleanValue */,
                            tuple.Get<3>().GetLocalWstring() /* stringValue */
                        };
                    }

                    static void TestEqual(const LocalTupleResult& expectedResult, const LocalTupleResult& actualResult)
                    {
                        Assert::AreEqual(expectedResult.name, actualResult.name);
                        Assert::AreEqual(expectedResult.numericValue, actualResult.numericValue);
                        Assert::AreEqual(expectedResult.booleanValue, actualResult.booleanValue);
                        Assert::AreEqual(std::wstring_view(expectedResult.stringValue.c_str()), std::wstring_view(actualResult.stringValue.c_str()));
                    }

                    std::wstring name;
                    int numericValue = 0;
                    bool booleanValue = false;
                    std::wstring stringValue;
                };

                // Ensure the correct results have been returned for:
                // -> Default-constructible `UiaTuple`
                {
                    const LocalTupleResult expectedResult{ L"" /* name */, 0 /* numericValue */, false /* booleanValue */, L"" /* stringValue */ };
                    const auto actualResult = LocalTupleResult::FromResult(defaultConstructedTuple);
                    LocalTupleResult::TestEqual(expectedResult, actualResult);
                }

                // -> `UiaTuple` constructed out of local types
                {
                    const LocalTupleResult expectedResult{ L"Display is 0" /* name */, 1 /* numericValue */, true /* booleanValue */, L"LocalConstructed" /* stringValue */ };
                    const auto actualResult = LocalTupleResult::FromResult(localConstructedTuple);
                    LocalTupleResult::TestEqual(expectedResult, actualResult);
                }

                // -> `UiaTuple` constructed out of abstraction/wrapper values.
                {
                    const LocalTupleResult expectedResult{ L"Display is 0" /* name */, 2 /* numericValue */, true /* booleanValue */, L"WrapperConstructed" /* stringValue */ };
                    const auto actualResult = LocalTupleResult::FromResult(wrapperConstructedTuple);
                    LocalTupleResult::TestEqual(expectedResult, actualResult);
                }

                // -> `UiaTuple` using move assignment.
                {
                    const LocalTupleResult expectedResult{ L"Display is 0" /* name */, 3 /* numericValue */, true /* booleanValue */, L"MoveAssignment" /* stringValue */ };
                    const auto actualResult = LocalTupleResult::FromResult(moveAssignmentTuple);
                    LocalTupleResult::TestEqual(expectedResult, actualResult);
                }
            }
        }

        TEST_METHOD(UiaTupleCreateLocal)
        {
            UiaTupleCreateTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleCreateRemote)
        {
            UiaTupleCreateTest(true /* useRemoteOperations */);
        }

        void UiaTupleWithTuplesTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Ensure that `UiaTuple` instances can hold other `UiaTuple` values to support breaking values
            // into groups of values.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create a default numeric tuple.
                const std::tuple<int> baseValueTuple{ 0 };
                UiaTuple<UiaTuple<UiaInt>> tuple;

                // Return the tuple from the operation
                operationScope.BindResult(tuple);
                operationScope.Resolve();

                // Ensure the tuple is equal to the default numeric tuple.
                Assert::AreEqual(std::tuple<int>{ 0 }, *tuple.Get<0>());
            }
        }

        TEST_METHOD(UiaTupleWithTuplesLocal)
        {
            UiaTupleWithTuplesTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleWithTuplesRemote)
        {
            UiaTupleWithTuplesTest(true /* useRemoteOperations */);
        }

        void UiaTupleWithVariantsTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Make sure `UiaTuple` instances can hold `UiaVariant` objects with different values in them by
            // creating a `UiaTuple` that holds multiple `UiaVariant` members and ensuring they can be used
            // during executing remote operations.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create a tuple with a variant.
                const std::wstring variantValue{ L"This is a string" };
                UiaTuple<UiaVariant, UiaVariant> tuple{ UiaVariant{ variantValue }, UiaVariant{} };

                // Get the variant and try to get basic information about it.
                auto variant = tuple.Get<0>();
                auto isVariantString = variant.IsString();

                UiaString variantString{ L"" };
                operationScope.If(isVariantString, [&]()
                {
                    variantString = variant.AsString();
                });

                // Also, get the empty variant information.
                auto emptyVariant = tuple.Get<1>();
                auto isEmptyVariantString = emptyVariant.IsString();

                // Return the tuple for the operation and also information about the two variants.
                operationScope.BindResult(tuple, variantString, isVariantString, emptyVariant, isEmptyVariantString);
                operationScope.Resolve();

                // Ensure the first returned variant is the expected string.
                Assert::IsTrue(static_cast<bool>(isVariantString));
                Assert::AreEqual(variantValue, variantString.GetLocalWstring());

                // Ensure the second returned variant does not represent a string and is `VT_EMPTY`.
                Assert::IsFalse(static_cast<bool>(isEmptyVariantString));
                Assert::AreEqual(static_cast<int>(VT_EMPTY), static_cast<int>(emptyVariant.get().vt));

                // Finally, ensure the variants in the returned `UiaTuple` instance matches the two just-checked
                // variants.
                auto variantWrapper = tuple.Get<0>();
                Assert::IsTrue(static_cast<bool>(variantWrapper.IsString()));
                Assert::AreEqual(variantValue, variantWrapper.AsString().GetLocalWstring());

                auto emptyVariantWrapper = tuple.Get<1>();
                Assert::IsFalse(static_cast<bool>(emptyVariantWrapper.IsString()));
                Assert::AreEqual(static_cast<int>(VT_EMPTY), static_cast<int>(emptyVariantWrapper.get().vt));
            }
        }

        TEST_METHOD(UiaTupleWithVariantsLocal)
        {
            UiaTupleWithVariantsTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleWithVariantsRemote)
        {
            UiaTupleWithVariantsTest(true /* useRemoteOperations */);
        }

        void UiaTupleWithEnumsTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Make sure `UiaTuple` instances can hold `UiaVariant` objects with different values in them by
            // creating a `UiaTuple` that holds multiple `UiaVariant` members and ensuring they can be used
            // during executing remote operations.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create a tuple with enums.
                UiaTuple<UiaSayAsInterpretAs, UiaTextUnit> tuple{ SayAsInterpretAs_Spell, TextUnit_Word };

                // Return the tuple for the operation.
                operationScope.BindResult(tuple);
                operationScope.Resolve();

                // Ensure the enum values in the returned `UiaTuple` instance matches.
                auto sayAsInterpretAsWrapper = tuple.Get<0>();
                Assert::AreEqual(static_cast<int>(SayAsInterpretAs_Spell), static_cast<int>(sayAsInterpretAsWrapper));

                auto textUnitWrapper = tuple.Get<1>();
                Assert::AreEqual(static_cast<int>(TextUnit_Word), static_cast<int>(textUnitWrapper));
            }
        }

        TEST_METHOD(UiaTupleWithEnumsLocal)
        {
            UiaTupleWithEnumsTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleWithEnumsRemote)
        {
            UiaTupleWithEnumsTest(true /* useRemoteOperations */);
        }

        void UiaTupleWithCollectionsTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Create a `UiaTuple` instance with non-empty collections, return the tuple and ensure that the tuple
            // and its collections have expected values in them.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create collections to put in the tuple.
                const std::vector<int> baseValueArray{ 1, 2 };
                const std::map<std::wstring, int> baseValueMap{ { L"Value", 1 } };
                const std::tuple<int> baseValueTuple{ 0 };

                UiaArray<UiaInt> baseArray{ baseValueArray };
                UiaStringMap<UiaInt> baseMap{ baseValueMap };

                // Create a tuple out of the collections.
                UiaTuple<UiaArray<UiaInt>, UiaStringMap<UiaInt>> tuple{ baseArray, baseMap };

                // Return the collections of tuple.
                operationScope.BindResult(tuple);
                operationScope.Resolve();

                // Ensure the tuple contains the two collections.
                Assert::AreEqual(baseValueArray, *tuple.Get<0>());
                Assert::AreEqual(baseValueMap, *tuple.Get<1>());
            }
        }

        TEST_METHOD(UiaTupleWithCollectionsLocal)
        {
            UiaTupleWithCollectionsTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleWithCollectionsRemote)
        {
            UiaTupleWithCollectionsTest(true /* useRemoteOperations */);
        }

        void UiaTupleModifyTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // This test creates a `UiaTuple` instance out of values, modifies both the tuple and the sources
            // of the values and ensures their results are correct.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct fields/values, create a `UiaTuple` out of them to initialize the tuple.
                UiaString immutableStringValue{ L"ImmutableString" };
                UiaString modifiedStringValue{ L"UnmodifiedString" };
                UiaTuple<UiaString, UiaString, UiaString, UiaString> tuple{ immutableStringValue, modifiedStringValue, L"OwnedImmutableString", L"OwnedUnmodifiedString" };

                // Modify the string values and tuple fields.
                modifiedStringValue = L"ModifiedString";
                tuple.Set<3>(wil::make_bstr(L"OwnedModifiedString"));

                // Return the results of the comparisons.
                operationScope.BindResult(immutableStringValue, modifiedStringValue, tuple);
                operationScope.Resolve();

                // Ensure the correct results have been returned and that if strings have been modified, they have
                // bee modified independently from other values (such as the source of the original string/value).
                Assert::AreEqual(std::wstring(L"ImmutableString"), immutableStringValue.GetLocalWstring());
                Assert::AreEqual(std::wstring(L"ModifiedString"), modifiedStringValue.GetLocalWstring());

                Assert::AreEqual(std::wstring(L"ImmutableString"), tuple.Get<0>().GetLocalWstring());
                Assert::AreEqual(std::wstring(L"UnmodifiedString"), tuple.Get<1>().GetLocalWstring());
                Assert::AreEqual(std::wstring(L"OwnedImmutableString"), tuple.Get<2>().GetLocalWstring());
                Assert::AreEqual(std::wstring(L"OwnedModifiedString"), tuple.Get<3>().GetLocalWstring());
            }
        }

        TEST_METHOD(UiaTupleModifyLocal)
        {
            UiaTupleCreateTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleModifyRemote)
        {
            UiaTupleCreateTest(true /* useRemoteOperations */);
        }

        void UiaTupleGetAndSetTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // The test ensures that tuple values get be fetched and used to modify other tuples.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct tuples with different values.
                UiaTuple<UiaString, UiaInt> tuple1{ L"tuple1.string", 1 };
                UiaTuple<UiaString, UiaInt> tuple2{ L"tuple2.string", 2 };

                // Modify `tuple1` by replacing its numeric value with `tuple2`'s.
                auto tuple1PreviousInt = tuple1.Get<1>();
                auto tuple2Int = tuple2.Get<1>();
                tuple1.Set<1>(tuple2Int);

                // Use the string field of `tuple1` to modify the string field of `tuple2`.
                auto tuple2PreviousString = tuple2.Get<0>();
                auto tuple1String = tuple1.Get<0>();
                tuple2.Set<0>(tuple1String);

                // Return the tuples and the previous values, too.
                operationScope.BindResult(tuple1, tuple2, tuple1PreviousInt, tuple2PreviousString);
                operationScope.Resolve();

                // Ensure the returned comparison results are correct.
                const auto toLocalTupleResult = [](auto& tuple)
                {
                    return std::tuple<std::wstring, int>{ tuple.Get<0>().GetLocalWstring(), tuple.Get<1>() };
                };

                Assert::AreEqual(1, static_cast<int>(tuple1PreviousInt));
                Assert::AreEqual(std::wstring(L"tuple2.string"), tuple2PreviousString.GetLocalWstring());

                Assert::AreEqual(std::tuple<std::wstring, int>{ L"tuple1.string", 2 }, toLocalTupleResult(tuple1));
                Assert::AreEqual(std::tuple<std::wstring, int>{ L"tuple1.string", 2 }, toLocalTupleResult(tuple2));
            }
        }

        TEST_METHOD(UiaTupleGetAndSetLocal)
        {
            UiaTupleGetAndSetTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleGetAndSetRemote)
        {
            UiaTupleGetAndSetTest(true /* useRemoteOperations */);
        }

        void UiaTupleComparisonTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Create tuples and verify their comparison operators.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct tuples that differ on one field.
                UiaTuple<UiaString, UiaInt> tuple1{ L"Value1", 0 };
                UiaTuple<UiaString, UiaInt> tuple2{ L"Value2", 0 };
                UiaTuple<UiaString, UiaInt> tuple3{ L"Value1", 1 };

                // Compare the first tuple against all 3 tuples to understand their relationships.
                auto tuplesEqual = (tuple1 == tuple1);
                auto tuplesNotEqualOnString = (tuple1 != tuple2);
                auto tuplesNotEqualOnInt = (tuple1 != tuple3);

                // Return the results of the comparisons.
                operationScope.BindResult(tuplesEqual, tuplesNotEqualOnString, tuplesNotEqualOnInt);
                operationScope.Resolve();

                // Ensure the returned comparison results are correct.
                Assert::IsTrue(static_cast<bool>(tuplesEqual));
                Assert::IsTrue(static_cast<bool>(tuplesNotEqualOnString));
                Assert::IsTrue(static_cast<bool>(tuplesNotEqualOnInt));
            }
        }

        TEST_METHOD(UiaTupleComparisonLocal)
        {
            UiaTupleComparisonTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleComparisonRemote)
        {
            UiaTupleComparisonTest(true /* useRemoteOperations */);
        }

        void UiaTupleInCollectionsTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // This test creates an `UiaTuple` instances and builds an array collection out of them to return them
            // back to the caller.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct a few tuples and create collections out of them.
                UiaTuple<UiaString, UiaString> tuple1{ UiaString{ L"tuple1.string1" }, UiaString{ L"tuple1.string2" } };
                UiaTuple<UiaString, UiaString> tuple2{ UiaString{ L"tuple2.string1" }, UiaString{ L"tuple2.string2" } };

                UiaArray<UiaTuple<UiaString, UiaString>> tupleArray;
                tupleArray.Append(tuple1);
                tupleArray.Append(tuple2);

                // Return the collection of tuples.
                operationScope.BindResult(tupleArray);
                operationScope.Resolve();

                // Ensure the array is of the expected shape.
                Assert::AreEqual(static_cast<size_t>(2), static_cast<size_t>(tupleArray.Size()));

                const std::array<std::wstring, 2> tupleKeys{ L"tuple1", L"tuple2" };
                for (unsigned int i = 0; i < tupleKeys.size(); ++i)
                {
                    const auto& tupleKey = tupleKeys[i];
                    auto tuple = tupleArray.GetAt(i);

                    const auto tupleKeyPrefix = tupleKey + L".";
                    Assert::AreEqual(tupleKeyPrefix + L"string1", tuple.Get<0>().GetLocalWstring());
                    Assert::AreEqual(tupleKeyPrefix + L"string2", tuple.Get<1>().GetLocalWstring());
                }
            }

            // Perform the same test but with `UiaStringMap`.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Construct a few tuples and a map of out of them.
                UiaTuple<UiaString, UiaString> tuple1{ UiaString{ L"tuple1.string1" }, UiaString{ L"tuple1.string2" } };
                UiaTuple<UiaString, UiaString> tuple2{ UiaString{ L"tuple2.string1" }, UiaString{ L"tuple2.string2" } };

                UiaStringMap<UiaTuple<UiaString, UiaString>> tupleMap;
                tupleMap.Insert(L"tuple1", tuple1);
                tupleMap.Insert(L"tuple2", tuple2);

                // Return the collection.
                operationScope.BindResult(tupleMap);
                operationScope.Resolve();

                // Now, make sure the collection contains the expected values.
                Assert::AreEqual(static_cast<size_t>(2), static_cast<size_t>(tupleMap.Size()));

                const std::array<std::wstring, 2> tupleKeys{ L"tuple1", L"tuple2" };
                for (unsigned int i = 0; i < tupleKeys.size(); ++i)
                {
                    const auto& tupleKey = tupleKeys[i];
                    Assert::IsTrue(tupleMap.HasKey(tupleKey));

                    auto tuple = tupleMap.Lookup(tupleKey);
                    const auto tupleKeyPrefix = tupleKey + L".";
                    Assert::AreEqual(tupleKeyPrefix + L"string1", tuple.Get<0>().GetLocalWstring());
                    Assert::AreEqual(tupleKeyPrefix + L"string2", tuple.Get<1>().GetLocalWstring());
                }
            }
        }

        TEST_METHOD(UiaTupleInCollectionsTestLocal)
        {
            UiaTupleInCollectionsTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaTupleInCollectionsTestRemote)
        {
            UiaTupleInCollectionsTest(true /* useRemoteOperations */);
        }

        void GetMetadataValueTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Get metadata value operation.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Get metadata value from the element
                UiaVariant variant = displayElement.GetMetadataValue(UIA_NamePropertyId, UIA_SayAsInterpretAsMetadataId);
                UiaBool isVariantNull = (variant.IsNull());
                UiaBool isVariantTypeInt{ false };
                operationScope.If(!variant.IsNull(), [&]()
                {
                    isVariantTypeInt = variant.IsType<UiaInt>();
                });

                // Return the results of the comparisons.
                operationScope.BindResult(isVariantNull, isVariantTypeInt);
                operationScope.Resolve();

                // Because the focused element does not hold any metadata value, the returned variant will not contain actual value.
                if (useRemoteOperations)
                {
                    // When use remote operations, the returned variant will be null.
                    Assert::AreEqual(true, static_cast<bool>(isVariantNull));
                }
                else
                {
                    // When evaluate locally, the variant should never be null and we will get a local VARIANT with VT_EMPTY type.
                    Assert::AreEqual(false, static_cast<bool>(isVariantNull));
                    Assert::AreEqual(false, static_cast<bool>(isVariantTypeInt));
                }
            }
        }

        TEST_METHOD(GetMetadataValueTestLocal)
        {
            GetMetadataValueTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(GetMetadataValueTestRemote)
        {
            GetMetadataValueTest(true /* useRemoteOperations */);
        }

        void UiaVariantCastUiaEnumTest(bool useRemoteOperations)
        {
            const auto cleanup = InitializeUiaOperationAbstraction(useRemoteOperations);

            // Initialize the test application.
            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();

            // Set focus to the display element.
            auto focusedElement = WaitForElementFocus(L"Display is 0");

            // Make sure `UiaVariant` instances can be cast to `UiaEnum` type.
            {
                auto operationScope = UiaOperationScope::StartNew();

                // Give this operation a remote context.
                UiaElement displayElement{ focusedElement };
                operationScope.BindInput(displayElement);

                // Create a variant with a enum.
                UiaSayAsInterpretAs originalValue{ SayAsInterpretAs_Spell };
                UiaVariant variantValue{ originalValue };

                // Cast the variant to enum.
                UiaSayAsInterpretAs castValue = variantValue.AsType<UiaSayAsInterpretAs>();

                // Return the tuple for the operation and also information about the two variants.
                operationScope.BindResult(castValue);
                operationScope.Resolve();

                // Ensure the returned enum is the expected value.
                auto expected = static_cast<int>(SayAsInterpretAs_Spell);
                auto actual = static_cast<int>(castValue);
                Assert::AreEqual(expected, actual);
            }
        }

        TEST_METHOD(UiaVariantCastUiaEnumTestLocal)
        {
            UiaVariantCastUiaEnumTest(false /* useRemoteOperations */);
        }

        TEST_METHOD(UiaVariantCastUiaEnumTestRemote)
        {
            UiaVariantCastUiaEnumTest(true /* useRemoteOperations */);
        }

        // Asserts that you can convert a UiaElement to / from a UiaVariant 
        void ElementAsVariantTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();

            UiaElement element = calc;
            auto variantFromElement = UiaVariant(element);
            auto variantIsElement = variantFromElement.IsElement();
            scope.BindResult(variantIsElement);
            
            auto elementFromVariant = variantFromElement.AsElement();

            auto name = elementFromVariant.GetName(false /*useCachedApi*/);
            scope.BindResult(name);

            scope.Resolve();

            Assert::IsTrue(static_cast<bool>(variantIsElement));
            Assert::AreEqual(std::wstring(static_cast<wil::shared_bstr>(name).get()), std::wstring(L"Display is 0"));
        }

        TEST_METHOD(ElementAsVariantLocalTest)
        {
            ElementAsVariantTest(false);
        }

        TEST_METHOD(ElementAsVariantRemoteTest)
        {
            ElementAsVariantTest(true);
        }

        // Tests the CompileOrRun API
        void CompileOrRunTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            UiaElement calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();
            scope.BindInput(calc);

            UiaString name = L"";
            scope.CompileOrRun([&]()
            {
                name = calc.GetName();
            });

            scope.BindResult(name);
            scope.Resolve();

            Assert::AreEqual(
                std::wstring(L"Display is 0"),
                std::wstring(static_cast<wil::shared_bstr>(name).get()));
        }

        TEST_METHOD(CompileOrRun_Remote)
        {
            CompileOrRunTest(true);
        }

        TEST_METHOD(CompileOrRun_Local)
        {
            CompileOrRunTest(false);
        }

        // Tests that we can exit with failure using the CompileOrRun API.
        void CompileOrRunExitFailureTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            UiaElement calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();
            scope.BindInput(calc);

            UiaInt i = 1;

            const auto hr = wil::ResultFromException([&]()
            {
                scope.CompileOrRun([&]()
                {
                    scope.AbortOperationWithHresult(E_FAIL);
                    i = 2;
                });

                scope.BindResult(i);
                scope.Resolve();
            });

            Assert::AreEqual(E_FAIL, hr);

            // `i` will only be local at this point if the entire operation was
            // local, since we don't fill in remote results on failure.
            if (!useRemoteOperations)
            {
                Assert::AreEqual(1, static_cast<int>(i));
            }
        }

        TEST_METHOD(CompileOrRunExitFailure_Remote)
        {
            CompileOrRunExitFailureTest(true);
        }

        TEST_METHOD(CompileOrRunExitFailure_Local)
        {
            CompileOrRunExitFailureTest(false);
        }

        // Tests that we can exit with success using the CompileOrRun API.
        void CompileOrRunExitSuccessTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            UiaElement calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();
            scope.BindInput(calc);

            UiaInt i = 1;
            scope.CompileOrRun([&]()
            {
                scope.AbortOperationWithHresult(S_OK);
                i = 2;
            });

            scope.BindResult(i);
            const auto hr = scope.ResolveHr();

            Assert::AreEqual(S_OK, hr);
            Assert::AreEqual(1, static_cast<int>(i));
        }

        TEST_METHOD(CompileOrRunExitSuccess_Remote)
        {
            CompileOrRunExitSuccessTest(true);
        }

        TEST_METHOD(CompileOrRunExitSuccess_Local)
        {
            CompileOrRunExitSuccessTest(false);
        }

        // Tests the try block and catch block implementation both locally and remote. When an exception is encountered, the execution
        // continues till the end of instructions without returning from the exception location, also records the exception
        // in catch block.
        void TryAndCatchBlockTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");
            UiaElement element = calc;

            auto scope = UiaOperationScope::StartNew();

            scope.BindInput(element);

            UiaInt failureCode = 0;
            UiaArray<UiaInt> numbers;
            numbers.Append(1);
            numbers.Append(2);
            numbers.Append(3);
            scope.TryCatch([&]()
                {
                    auto number = numbers.GetAt(3);
                },
                [&](UiaFailure failure)
                {
                    failureCode = failure.GetCurrentFailureCode();
                });

            UiaInt numberAfterTryCatch = numbers.GetAt(2);
            scope.BindResult(failureCode);
            scope.BindResult(numberAfterTryCatch);
            scope.Resolve();

            auto hresult = static_cast<HRESULT>(failureCode);
            Assert::AreEqual(E_BOUNDS, hresult);
            Assert::AreEqual(3, static_cast<int>(numberAfterTryCatch));
        }

        TEST_METHOD(TestTryAndCatchBlockAsRemoteTest)
        {
            TryAndCatchBlockTest(true);
        }

        TEST_METHOD(TestTryAndCatchBlockAsLocalTest)
        {
            TryAndCatchBlockTest(false);
        }

        // Tests the try block implementation both locally and remote. When an exception is encountered, the execution
        // continues till the end of instructions without returning from the exception location.
        void TryBlockTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");
            UiaElement element = calc;

            auto scope = UiaOperationScope::StartNew();

            scope.BindInput(element);

            UiaArray<UiaInt> numbers;
            numbers.Append(1);
            numbers.Append(2);
            numbers.Append(3);
            scope.Try([&]()
                {
                    auto number = numbers.GetAt(3);
                });

            UiaString testString{ L"Text after the try block" };
            scope.BindResult(testString);
            scope.Resolve();

            Assert::AreEqual(std::wstring(L"Text after the try block"), testString.GetLocalWstring());
        }

        TEST_METHOD(TestTryBlockAsRemoteTest)
        {
            TryBlockTest(true);
        }

        TEST_METHOD(TestTryBlockAsLocalTest)
        {
            TryBlockTest(false);
        }

        // Tests that calling AbortOperationWithHresult with a failure is
        // caught by a try-catch block.
        void TryBlockAbortOperationFailureTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            UiaElement calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();
            scope.BindInput(calc);

            UiaInt hr = S_OK;
            UiaInt i = 1;

            scope.CompileOrRun([&]()
            {
                scope.TryCatch([&]()
                {
                    scope.AbortOperationWithHresult(E_FAIL);
                    i = 2;
                }, [&](UiaFailure failure)
                {
                    i = 3;
                    hr = failure.GetCurrentFailureCode();
                });
            });

            scope.BindResult(hr, i);
            scope.Resolve();

            Assert::AreEqual(E_FAIL, static_cast<HRESULT>(hr));
            Assert::AreEqual(3, static_cast<int>(i));
        }

        TEST_METHOD(TryBlockAbortOperationFailure_Remote)
        {
            TryBlockAbortOperationFailureTest(true);
        }

        TEST_METHOD(TryBlockAbortOperationFailure_Local)
        {
            TryBlockAbortOperationFailureTest(false);
        }

        // Tests that calling AbortOperationWithHresult with S_OK is not caught
        // by a try-catch block, and the operation exits immediately.
        void TryBlockAbortOperationSuccessTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            UiaElement calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();
            scope.BindInput(calc);

            UiaInt hr = S_OK;
            UiaInt i = 1;

            scope.CompileOrRun([&]()
            {
                scope.TryCatch([&]()
                {
                    scope.AbortOperationWithHresult(S_OK);
                    i = 2;
                }, [&](UiaFailure failure)
                {
                    i = 3;
                    hr = failure.GetCurrentFailureCode();
                });
            });

            scope.BindResult(hr, i);
            scope.Resolve();

            Assert::AreEqual(S_OK, static_cast<HRESULT>(hr));
            Assert::AreEqual(1, static_cast<int>(i));
        }

        TEST_METHOD(TryBlockAbortOperationSuccess_Remote)
        {
            TryBlockAbortOperationSuccessTest(true);
        }

        TEST_METHOD(TryBlockAbortOperationSuccess_Local)
        {
            TryBlockAbortOperationSuccessTest(false);
        }

        // Tests that we properly handle special exceptions used for loop
        // control flow in our try-catch block. These are
        // UiaOperationAbstraction::LoopContinueException and
        // UiaOperationAbstraction::LoopBreakException.
        void TryBlockWorksWithLoopsTest(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            UiaElement calc = WaitForElementFocus(L"Display is 0");

            auto scope = UiaOperationScope::StartNew();
            scope.BindInput(calc);

            UiaInt i = 0;
            UiaInt j = 0;
            scope.While([&]()
            {
                return true;
            },
            [&]()
            {
                scope.If(i == 3, [&]()
                {
                    scope.Try([&]()
                    {
                        scope.Break();
                    });
                });

                i += 1;

                scope.If(i == 2, [&]()
                {
                    scope.Try([&]()
                    {
                        scope.Continue();
                    });
                });

                j += 1;
            });

            scope.BindResult(i, j);
            scope.Resolve();

            Assert::AreEqual(3, static_cast<int>(i));
            Assert::AreEqual(2, static_cast<int>(j));
        }

        TEST_METHOD(TryBlockWorksWithLoops_Remote)
        {
            TryBlockWorksWithLoopsTest(true);
        }

        TEST_METHOD(TryBlockWorksWithLoops_Local)
        {
            TryBlockWorksWithLoopsTest(false);
        }

        // Test that calling IsOpcodeSupported works after we import an
        // element, establishing a connection.
        void IsOpcodeSupportedTest_AfterImport(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            ModernApp app(L"Microsoft.WindowsCalculator_8wekyb3d8bbwe!App");
            app.Activate();
            auto calc = WaitForElementFocus(L"Display is 0");
            UiaElement element = calc;

            auto scope = UiaOperationScope::StartNew();
            scope.BindInput(element);

            Assert::IsTrue(scope.IsOpcodeSupported(0x0 /*Nop*/));
            Assert::IsTrue(scope.IsOpcodeSupported(0x48 /*NewGuid*/));

            const auto isNonExistentOpcodeSupported = scope.IsOpcodeSupported(2000000000);
            if (useRemoteOperations)
            {
                Assert::IsFalse(isNonExistentOpcodeSupported);
            }
            else
            {
                // All operations are supported locally.
                Assert::IsTrue(isNonExistentOpcodeSupported);
            }
        }

        TEST_METHOD(IsOpcodeSupported_AfterImport_Remote)
        {
            IsOpcodeSupportedTest_AfterImport(true);
        }

        TEST_METHOD(IsOpcodeSupported_AfterImport_Local)
        {
            IsOpcodeSupportedTest_AfterImport(false);
        }

        // Test that calling IsOpcodeSupported fails for remote ops on certain
        // Windows builds if we haven't imported an element yet, thus not
        // establishing a connection.
        void IsOpcodeSupportedTest_BeforeImport(const bool useRemoteOperations)
        {
            auto guard = InitializeUiaOperationAbstraction(useRemoteOperations);

            auto scope = UiaOperationScope::StartNew();

            const auto hr = wil::ResultFromException([&]()
            {
                scope.IsOpcodeSupported(0x0);
            });

            if (useRemoteOperations)
            {
                // TODO #77: Do a Windows version check once a build with this
                // failing behavior is released.
                // Assert::AreEqual(E_FAIL, hr);
            }
            else
            {
                // Calling IsOpcodeSupported never produces an error in the local case.
                Assert::AreEqual(S_OK, hr);
            }
        }

        TEST_METHOD(IsOpcodeSupported_BeforeImport_Remote)
        {
            IsOpcodeSupportedTest_BeforeImport(true);
        }

        TEST_METHOD(IsOpcodeSupported_BeforeImport_Local)
        {
            IsOpcodeSupportedTest_BeforeImport(false);
        }
    };
}
