// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include "pch.h"

#include "UiaOperationAbstraction.h"
#include "SafeArrayUtil.h"

using namespace winrt::Microsoft::UI::UIAutomation;
using namespace winrt::Windows::UI::UIAutomation;
using namespace UiaOperationAbstraction::impl;
using namespace SafeArrayUtil;

namespace winrt
{
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::Foundation::Collections;
}

namespace UiaOperationAbstraction
{
    namespace {
        template <typename T, class Original>
        T FromAbi(_In_ Original* from)
        {
            T to{ nullptr };

            winrt::check_hresult(
                from->QueryInterface(
                    winrt::guid_of<T>(),
                    reinterpret_cast<void**>(winrt::put_abi(to))));

            return to;
        }

        template<class T>
        winrt::com_ptr<T> MakeWinrtComPtr(_In_ T* rawPtr)
        {
            winrt::com_ptr<T> ptr;
            ptr.copy_from(rawPtr);
            return ptr;
        }

        winrt::Windows::Foundation::Rect ConvertRect(RECT rect)
        {
            winrt::Windows::Foundation::Rect winrtRect(static_cast<float>(rect.left), static_cast<float>(rect.top), 0 /* Height */, 0 /* Width */);
            winrtRect.Height = static_cast<float>(rect.bottom - rect.top);
            winrtRect.Width = static_cast<float>(rect.right - rect.left);

            return winrtRect;
        }

        RECT ConvertRect(winrt::Windows::Foundation::Rect rect)
        {
            RECT win32Rect{ static_cast<LONG>(rect.X), static_cast<LONG>(rect.Y), 0 /* right */, 0 /* bottom */ };
            win32Rect.right = static_cast<LONG>(rect.X + rect.Width);
            win32Rect.bottom = static_cast<LONG>(rect.Y + rect.Height);

            return win32Rect;
        }

        wil::unique_bstr SafeToUniqueBstr(const std::wstring & str)
        {
            if (!str.empty())
            {
                return wil::unique_bstr{ SysAllocStringLen(str.data(), static_cast<UINT>(str.size())) };
            }

            return wil::unique_bstr{};
        }

        AutomationRemoteString NewRemoteStringFromBstr(const AutomationRemoteOperation& remoteOperation, _In_opt_z_ BSTR localString)
        {
            if (localString)
            {
                return remoteOperation.NewString(localString);
            }
            else
            {
                return remoteOperation.NewNull().AsString();
            }
        }

        wil::unique_variant CopyToUniqueVariant(const VARIANT & variant)
        {
            wil::unique_variant result;
            winrt::check_hresult(VariantCopy(&result, &variant));
            return result;
        }

        template <class UiaWrapperType, template <typename> class Operator>
        UiaBool BinaryOperator(
            const typename UiaWrapperType::VariantType& lhs,
            const typename UiaWrapperType::VariantType& rhs)
        {
            if (ShouldUseRemoteApi())
            {
                auto delegator = UiaOperationScope::GetCurrentDelegator();
                // if ShouldUseRemoteApi returns true, delegator has to be non-null.
                FAIL_FAST_IF(!delegator);

                // It is efficient to create a non-const copy of a UiaWrapperType-derived object because the
                // copy constructor copies the reference while operator= copies the data. Thus, creating
                // mutableLhs does not create a new remote if lhs was already remote.
                auto mutableLhs = lhs;
                delegator->ConvertVariantDataToRemote(mutableLhs);
                auto mutableRhs = rhs;
                delegator->ConvertVariantDataToRemote(mutableRhs);
                return (std::get<typename UiaWrapperType::RemoteType>(mutableLhs).*Operator<UiaWrapperType>::RemoteOperator)(
                    std::get<typename UiaWrapperType::RemoteType>(mutableRhs));
            }

            return Operator<UiaWrapperType>::LocalOperator(
                std::get<typename UiaWrapperType::LocalType>(lhs),
                std::get<typename UiaWrapperType::LocalType>(rhs));
        }

        template <typename UiaWrapperType>
        struct Equal
        {
            static constexpr std::equal_to<typename UiaWrapperType::LocalType> LocalOperator{};
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::IsEqual;
        };

        template <typename UiaWrapperType>
        struct NotEqual
        {
            static constexpr std::not_equal_to<typename UiaWrapperType::LocalType> LocalOperator{};
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::IsNotEqual;
        };

        template <typename UiaWrapperType>
        struct LessThan
        {
            static constexpr std::less<typename UiaWrapperType::LocalType> LocalOperator{};
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::IsLessThan;
        };

        template <typename UiaWrapperType>
        struct LessThanOrEqual
        {
            static constexpr std::less_equal<typename UiaWrapperType::LocalType> LocalOperator{};
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::IsLessThanOrEqual;
        };

        template <typename UiaWrapperType>
        struct GreaterThan
        {
            static constexpr std::greater<typename UiaWrapperType::LocalType> LocalOperator{};
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::IsGreaterThan;
        };

        template <typename UiaWrapperType>
        struct GreaterThanOrEqual
        {
            static constexpr std::greater_equal<typename UiaWrapperType::LocalType> LocalOperator{};
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::IsGreaterThanOrEqual;
        };

        template <typename UiaWrapperType>
        struct And
        {
            static constexpr std::logical_and<typename UiaWrapperType::LocalType> LocalOperator{};
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::BoolAnd;
        };

        template <typename UiaWrapperType>
        struct Or
        {
            static constexpr std::logical_or<typename UiaWrapperType::LocalType> LocalOperator{};
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::BoolOr;
        };

        template <class UiaWrapperType, template <typename> class Operator>
        void InPlaceArithmetic(
            typename UiaWrapperType::VariantType& lhs,
            const typename UiaWrapperType::VariantType& rhs)
        {
            if (ShouldUseRemoteApi())
            {
                auto delegator = UiaOperationScope::GetCurrentDelegator();
                // if ShouldUseRemoteApi returns true, delegator has to be non-null.
                FAIL_FAST_IF(!delegator);

                delegator->ConvertVariantDataToRemote(lhs);

                // It is efficient to create a non-const copy of a UiaWrapperType-derived object because the
                // copy constructor copies the reference while operator= copies the data. Thus, creating
                // mutableRhs does not create a new remote if rhs was already remote.
                auto mutableRhs = rhs;
                delegator->ConvertVariantDataToRemote(mutableRhs);
                ((std::get<typename UiaWrapperType::RemoteType>(lhs)).*(Operator<UiaWrapperType>::RemoteOperator))(
                    std::get<typename UiaWrapperType::RemoteType>(mutableRhs));
                return;
            }

            Operator<UiaWrapperType>::LocalOperator(
                std::get<typename UiaWrapperType::LocalType>(lhs),
                std::get<typename UiaWrapperType::LocalType>(rhs));
        }

        template <typename UiaWrapperType>
        struct Add
        {
            static constexpr auto LocalOperator = [](typename UiaWrapperType::LocalType& lhs, const typename UiaWrapperType::LocalType& rhs)
            {
                lhs += rhs;
            };
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::Add;
        };

        template <typename UiaWrapperType>
        struct Subtract
        {
            static constexpr auto LocalOperator = [](typename UiaWrapperType::LocalType& lhs, const typename UiaWrapperType::LocalType& rhs)
            {
                lhs -= rhs;
            };
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::Subtract;
        };

        template <typename UiaWrapperType>
        struct Multiply
        {
            static constexpr auto LocalOperator = [](typename UiaWrapperType::LocalType& lhs, const typename UiaWrapperType::LocalType& rhs)
            {
                lhs *= rhs;
            };
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::Multiply;
        };

        template <typename UiaWrapperType>
        struct Divide
        {
            static constexpr auto LocalOperator = [](typename UiaWrapperType::LocalType& lhs, const typename UiaWrapperType::LocalType& rhs)
            {
                lhs /= rhs;
            };
            static constexpr auto RemoteOperator = &UiaWrapperType::RemoteType::Divide;
        };

        template <class UiaWrapperType>
        void AssignCopyTo(
            typename UiaWrapperType::VariantType& to,
            const typename UiaWrapperType::VariantType& from)
        {
            if (ShouldUseRemoteApi())
            {
                auto delegator = UiaOperationScope::GetCurrentDelegator();
                // if ShouldUseRemoteApi returns true, delegator has to be non-null.
                FAIL_FAST_IF(!delegator);

                delegator->ConvertVariantDataToRemote(to);
                auto mutableFrom = from;
                delegator->ConvertVariantDataToRemote(mutableFrom);
                std::get<typename UiaWrapperType::RemoteType>(to).Set(std::get<typename UiaWrapperType::RemoteType>(mutableFrom));
            }
            else
            {
                std::get<typename UiaWrapperType::LocalType>(to) = std::get<typename UiaWrapperType::LocalType>(from);
            }
        }

        template <typename SpecificType>
        UiaBool AnyEqualsSpecificType(AutomationRemoteAnyObject& lhs, const typename SpecificType::RemoteType& specificRhs)
        {
            if (!(lhs.*(SpecificType::c_anyTest))())
            {
                return false;
            }
            return (lhs.*(SpecificType::c_anyCast))().IsEqual(specificRhs);
        }

        UiaBool AnyEqualsType(AutomationRemoteAnyObject& lhs, const AutomationRemoteObject& rhs)
        {
            auto boolRhs = rhs.try_as<AutomationRemoteBool>();
            if (boolRhs)
            {
                return AnyEqualsSpecificType<UiaBool>(lhs, boolRhs);
            }

            auto intRhs = rhs.try_as<AutomationRemoteInt>();
            if (intRhs)
            {
                return AnyEqualsSpecificType<UiaInt>(lhs, intRhs);
            }

            auto uintRhs = rhs.try_as<AutomationRemoteUint>();
            if (uintRhs)
            {
                return AnyEqualsSpecificType<UiaUint>(lhs, uintRhs);
            }

            auto doubleRhs = rhs.try_as<AutomationRemoteDouble>();
            if (doubleRhs)
            {
                return AnyEqualsSpecificType<UiaDouble>(lhs, doubleRhs);
            }

            auto stringRhs = rhs.try_as<AutomationRemoteString>();
            if (stringRhs)
            {
                return AnyEqualsSpecificType<UiaString>(lhs, stringRhs);
            }

            // The above are the only types currently supported by the UiaVariant wrapper
            throw winrt::hresult_not_implemented();
        }

        template <typename SpecificType>
        UiaBool TypeEqualsSpecificType(const AutomationRemoteObject& lhs, const typename SpecificType::RemoteType& specificRhs)
        {
            auto specificLhs = lhs.try_as<typename SpecificType::RemoteType>();
            if (specificLhs)
            {
                return specificLhs.IsEqual(specificRhs);
            }
            return false;
        }

        UiaBool TypeEqualsType(const AutomationRemoteObject& lhs, const AutomationRemoteObject& rhs)
        {
            auto boolRhs = rhs.try_as<AutomationRemoteBool>();
            if (boolRhs)
            {
                return TypeEqualsSpecificType<UiaBool>(lhs, boolRhs);
            }

            auto intRhs = rhs.try_as<AutomationRemoteInt>();
            if (intRhs)
            {
                return TypeEqualsSpecificType<UiaInt>(lhs, intRhs);
            }

            auto uintRhs = rhs.try_as<AutomationRemoteUint>();
            if (uintRhs)
            {
                return TypeEqualsSpecificType<UiaUint>(lhs, uintRhs);
            }

            auto doubleRhs = rhs.try_as<AutomationRemoteDouble>();
            if (doubleRhs)
            {
                return TypeEqualsSpecificType<UiaDouble>(lhs, doubleRhs);
            }

            auto stringRhs = rhs.try_as<AutomationRemoteString>();
            if (stringRhs)
            {
                return TypeEqualsSpecificType<UiaString>(lhs, stringRhs);
            }

            // The above are the only types currently supported by the UiaVariant wrapper
            throw winrt::hresult_not_implemented();
        }

        template <class WrapperType>
        void FromRemoteResultHelper(_In_ WrapperType* object, typename WrapperType::VariantType& member, winrt::Windows::Foundation::IInspectable result)
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            if (delegator)
            {
                object->ToDefaultValuedLocal();
                delegator->FromRemoteResult(result, std::get<typename WrapperType::LocalType>(member));
            }
        }

        bool g_useRemoteOperations = false;
        wil::object_without_destructor_on_shutdown<wil::com_ptr<IUIAutomation>> g_automation;

        wil::com_ptr<IUIAutomationTreeWalker> GetRawViewWalker()
        {
            wil::com_ptr<IUIAutomationTreeWalker> walker;
            THROW_IF_FAILED(g_automation.get()->get_RawViewWalker(&walker));
            return walker;
        }

        // Converts an IInspectable to an appropriate VARIANT.
        wil::unique_variant InspectableToVariant(const winrt::IInspectable& value, int depth = 0);

        // Convert the given WinRT IPropertyValue to a VARIANT. If the IPropertyValue isn't convertible to a
        // VARIANT, the function throws.
        wil::unique_variant GetPropertyValueAsVariant(const winrt::IPropertyValue& propertyValue)
        {
            const auto type = propertyValue.Type();

            wil::unique_variant variant;

            switch (type)
            {
            case winrt::Windows::Foundation::PropertyType::Empty:
                variant.vt = VT_EMPTY;
                break;

            case winrt::Windows::Foundation::PropertyType::Boolean:
                variant.vt = VT_BOOL;
                variant.boolVal = winrt::unbox_value<bool>(propertyValue) ? VARIANT_TRUE : VARIANT_FALSE;
                break;

            case winrt::Windows::Foundation::PropertyType::Int32:
                variant.vt = VT_I4;
                variant.lVal = winrt::unbox_value<int>(propertyValue);
                break;

            case winrt::Windows::Foundation::PropertyType::UInt32:
                variant.vt = VT_UI4;
                variant.ulVal = winrt::unbox_value<unsigned int>(propertyValue);
                break;

            case winrt::Windows::Foundation::PropertyType::Double:
                variant.vt = VT_R8;
                variant.dblVal = winrt::unbox_value<double>(propertyValue);
                break;

            case winrt::Windows::Foundation::PropertyType::String:
                variant.vt = VT_BSTR;
                variant.bstrVal = wil::make_bstr(winrt::unbox_value<winrt::hstring>(propertyValue).c_str()).release();
                break;

            default:
                // the above are all the types currently supported by UiaVariant
                throw winrt::hresult_not_implemented();
            }

            return variant;
        }

        // Convert the given WinRT IVector to a SAFEARRAY of an appropriate VT.
        // The VT will be inferred based on the type of object that the IVector actually holds.
        //
        // If the IVector holds a heterogeneous set of objects, the SAFEARRAY will be a SAFEARRAY
        // of VARIANTs.
        //
        // This requires that every object in the IVector be convertible to a VARIANT.
        unique_safearray SafeArrayFromWinrt(const winrt::IVector<winrt::IInspectable>& vector, int depth)
        {
            std::vector<wil::unique_variant> values;

            std::optional<VARTYPE> vt;
            bool allSameVt = true;
            for (const auto& item : vector)
            {
                auto vectorItemAsVariant = InspectableToVariant(item, depth + 1);
                if (!vt)
                {
                    vt = vectorItemAsVariant.vt;
                }

                if (vt != vectorItemAsVariant.vt)
                {
                    allSameVt = false;
                }

                values.emplace_back(std::move(vectorItemAsVariant));
            }

            unique_safearray result;
            if (vt.has_value() && allSameVt)
            {
                // When all properties are the same VT, there are certain types that we can "flatten" into the resulting
                // SAFEARRAY, avoiding a layer of VARIANTs.
                switch (*vt)
                {
                case VT_BOOL:
                    result = details::VectorToSafeArray(details::FlattenVariantArray<bool>(values));
                    break;

                case VT_I4:
                    result = details::VectorToSafeArray(details::FlattenVariantArray<int>(values));
                    break;

                case VT_UI4:
                    result = details::VectorToSafeArray(details::FlattenVariantArray<unsigned int>(values));
                    break;

                case VT_R8:
                    result = details::VectorToSafeArray(details::FlattenVariantArray<double>(values));
                    break;

                default:
                    // Though all VARIANTs in the vector had the same VT, it's not one of the ones we support "flattening".
                    // As such, create a SAFEARRAY of VT_VARIANTs.
                    result = details::VectorToSafeArray(std::move(values));
                    break;
                }
            }
            else
            {
                // We had a heterogeneous list of VARIANTs. As such, the list cannot be flattened and we create a SAFEARRAY of
                // VT_VARIANTs.
                result = details::VectorToSafeArray(std::move(values));
            }

            return result;
        }

        // Converts an IInspectable to an appropriate VARIANT.
        wil::unique_variant InspectableToVariant(const winrt::IInspectable& value, int depth /* = 0 */)
        {
            // This is a sanity check limit that prevents us from blowing the stack while recursively converting a highly nested
            // set of VARIANTs (a SAFEARRAY of VARIANT, each of which is a SAFEARRAY of VARIANT, etc.).
            //
            // Having nested arrays should be incredibly rare to begin with, so this sanity check limit shouldn't be too constrictive
            // in any real UIA scenario.
            THROW_HR_IF(E_UNEXPECTED, depth >= 100);

            wil::unique_variant result;

            if (auto array = value.try_as<winrt::IVector<winrt::IInspectable>>())
            {
                auto safearray = SafeArrayFromWinrt(array, depth);
                VARTYPE actualType{};
                THROW_IF_FAILED(::SafeArrayGetVartype(safearray.get(), &actualType));

                result.parray = safearray.release();
                result.vt = VT_ARRAY | actualType;
            }
            else if (auto propertyValue = value.try_as<winrt::IPropertyValue>())
            {
                result = GetPropertyValueAsVariant(propertyValue);
            }
            else if (value)
            {
                result.punkVal = static_cast<IUnknown*>(winrt::detach_abi(value.as<winrt::IUnknown>()));
                result.vt = VT_UNKNOWN;
            }

            return result;
        }

        template <typename UiaWrapperType>
        UiaString ArithmeticStringify(typename UiaWrapperType::VariantType& number)
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<typename UiaWrapperType::RemoteType>(&number);
                if (remoteValue)
                {
                    return remoteValue->Stringify();
                }
            }

            return std::to_wstring(std::get<typename UiaWrapperType::LocalType>(number));
        }
    } // anonymous namespace

    void UiaBool::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        m_member = winrt::unbox_value<bool>(result) ? TRUE : FALSE;
    }

    void UiaInt::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        m_member = winrt::unbox_value<int>(result);
    }

    void UiaUint::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        m_member = winrt::unbox_value<unsigned int>(result);
    }

    void UiaDouble::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        m_member = winrt::unbox_value<double>(result);
    }

    void UiaChar::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        static_assert(sizeof(char16_t) == sizeof(wchar_t), "char16_t needs to be the same as wchar_t");
        m_member = static_cast<wchar_t>(winrt::unbox_value<char16_t>(result));
    }

    UiaString UiaString::Stringify()
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->Stringify();
            }
        }

        const auto bstr = get();
        return (bstr ? bstr : L"");
    }

    void UiaString::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        if (result)
        {
            m_member = wil::make_bstr(winrt::unbox_value<winrt::hstring>(result).c_str());
        }
        else
        {
            m_member = wil::shared_bstr{ nullptr };
        }
    }

    void UiaVariant::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        m_member = std::make_shared<wil::unique_variant>();
        auto& localValue = std::get<LocalType>(m_member);

        *localValue = InspectableToVariant(result);
    }

    void UiaPoint::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        m_member = winrt::unbox_value<winrt::Windows::Foundation::Point>(result);
    }

    void UiaRect::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        m_member = winrt::unbox_value<winrt::Windows::Foundation::Rect>(result);
    }

    void UiaHwnd::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        const auto intermediate = winrt::unbox_value<int>(result);
        m_member = static_cast<UIA_HWND>(LongToHandle(intermediate));
    }

    struct UiaCacheRequestHelper
    {
        using UiaCacheRequestBaseType =
            UiaTypeBase<
                winrt::com_ptr<IUIAutomationCacheRequest>,
                winrt::Microsoft::UI::UIAutomation::AutomationRemoteCacheRequest>;

        static UiaCacheRequestBaseType CreateBaseClass()
        {
            const auto delegator = UiaOperationScope::GetCurrentDelegator();
            if (delegator && delegator->GetUseRemoteApi())
            {
                // We have direct access to m_remoteOperation here because
                // we're a friend class.
                return delegator->m_remoteOperation.NewCacheRequest();
            }
            else
            {
                winrt::com_ptr<IUIAutomationCacheRequest> cacheRequest;
                THROW_IF_FAILED(g_automation.get()->CreateCacheRequest(cacheRequest.put()));
                return cacheRequest;
            }
        }
    };

    UiaCacheRequest::UiaCacheRequest() :
        UiaTypeBase(UiaCacheRequestHelper::CreateBaseClass()) {}

    void UiaCacheRequest::AddProperty(UiaPropertyId propertyId)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteCacheRequest>(m_member).AddProperty(propertyId);
        }
        else
        {
            winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationCacheRequest>>(m_member)->AddProperty(propertyId));
        }
    }

    void UiaCacheRequest::AddPattern(UiaPatternId patternId)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteCacheRequest>(m_member).AddPattern(patternId);
        }
        else
        {
            winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationCacheRequest>>(m_member)->AddPattern(patternId));
        }
    }

    UiaGuid::UiaGuid(const winrt::guid& value):
        UiaTypeBase(value)
    {
        ToRemote();
    }

    UiaGuid::UiaGuid(winrt::Microsoft::UI::UIAutomation::AutomationRemoteGuid remoteValue):
        UiaTypeBase(remoteValue)
    {
    }

    UiaGuid::UiaGuid(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsGuid())
    {
    }

    UiaGuid& UiaGuid::operator=(const UiaGuid& other)
    {
        AssignCopyTo<UiaGuid>(this->m_member, other.m_member);
        return *this;
    }

    UiaBool UiaGuid::operator==(const UiaGuid& rhs) const
    {
        return BinaryOperator<UiaGuid, Equal>(this->m_member, rhs.m_member);
    }

    UiaBool UiaGuid::operator!=(const UiaGuid& rhs) const
    {
        return BinaryOperator<UiaGuid, NotEqual>(this->m_member, rhs.m_member);
    }

    UiaAnnotationType UiaGuid::LookupAnnotationType()
    {
        if (ShouldUseRemoteApi())
        {
            ToRemote();
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->LookupAnnotationType();
            }
        }

        GUID localValue = std::get<LocalType>(m_member);
        return UiaLookupId(AutomationIdentifierType_Annotation, &localValue);
    }

    UiaPropertyId UiaGuid::LookupPropertyId()
    {
        if (ShouldUseRemoteApi())
        {
            ToRemote();
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->LookupPropertyId();
            }
        }

        GUID localValue = std::get<LocalType>(m_member);
        return UiaLookupId(AutomationIdentifierType_Property, &localValue);
    }

    UiaGuid::operator winrt::guid() const
    {
        return std::get<winrt::guid>(m_member);
    }

    void UiaGuid::FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
    {
        m_member = winrt::unbox_value<GUID>(result);
    }


    namespace impl
    {
        template <>
        std::vector<UiaString::LocalType> ConvertSafeArray<UiaString>(unique_safearray&& array)
        {
            SafeArrayAccessor<BSTR> sa(array.get(), VT_BSTR);
            const UINT count = sa.Count();
            std::vector<UiaString::LocalType> vector;
            vector.reserve(count);

            for (UINT i = 0; i < count; ++i)
            {
                wil::unique_bstr bstr{ sa[i] };
                sa[i] = nullptr;
                vector.emplace_back(std::move(bstr));
            }

            return vector;
        }

        template <>
        std::vector<winrt::Windows::Foundation::Rect> ConvertSafeArray<UiaRect>(unique_safearray&& array)
        {
            SafeArrayAccessor<double> accessor(array.get(), VT_R8);
            std::vector<winrt::Windows::Foundation::Rect> result;

            const unsigned int len = accessor.Count();
            if ((len % 4) != 0)
            {
                throw winrt::hresult_error(E_UNEXPECTED);
            }
            const auto rectCount = len / 4;
            result.reserve(rectCount);

            for (unsigned int i = 0; i < rectCount; ++i)
            {
                const auto left = static_cast<float>(accessor[(4 * i) + 0]);
                const auto top = static_cast<float>(accessor[(4 * i) + 1]);
                const auto width = static_cast<float>(accessor[(4 * i) + 2]);
                const auto height = static_cast<float>(accessor[(4 * i) + 3]);

                result.emplace_back(left, top, width, height);
            }

            return result;
        }

        void PopulateCacheHelper(
            const winrt::Microsoft::UI::UIAutomation::AutomationRemoteElement& element,
            const winrt::Microsoft::UI::UIAutomation::AutomationRemoteCacheRequest& cacheRequest)
        {
            element.PopulateCache(cacheRequest);
        }

        void PopulateCacheHelper(
            const winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray& elements,
            const winrt::Microsoft::UI::UIAutomation::AutomationRemoteCacheRequest& cacheRequest)
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();

            UiaUint size = elements.Size();
            UiaUint i{ 0 };
            delegator->For(
                [](){} /* initialize */,
                [&]() { return i < size; } /* condition */,
                [&]() { i += 1; } /* modification */,
                [&]() /* body */
                {
                    elements.GetAt(i).AsElement().PopulateCache(cacheRequest);
                });
        }
    } // namespace impl

    void Initialize(bool useRemoteOperations, _In_ IUIAutomation* automation) noexcept
    {
        UiaOperationScope::EnsureContextManagersAreAllocated();
        g_useRemoteOperations = useRemoteOperations;
        g_automation.get() = automation;
    }

    void Cleanup() noexcept
    {
        UiaOperationScope::FreeContextManagers();
        g_automation.get().reset();
    }

    // UiaFailure
    UiaInt UiaFailure::GetCurrentFailureCode()
    {
        if (m_useRemoteApi)
        {
            return m_remoteOperation.GetCurrentFailureCode();
        }

        // wil::ResultFromCaughtException needs to be used only inside the catch block.
        // Usually it rethrows the error in the catch block and using it outside the catch
        // block could crash the process.
        return wil::ResultFromCaughtException();
    }

    // UiaOperationDelegator
    UiaOperationDelegator::UiaOperationDelegator() :
        UiaOperationDelegator(g_useRemoteOperations)
    {
    }

    UiaOperationDelegator::UiaOperationDelegator(bool useRemoteApi) : 
        m_useRemoteApi(useRemoteApi)
    {
    }

    bool UiaOperationDelegator::GetUseRemoteApi() const
    {
        return m_useRemoteApi;
    }

    bool UiaOperationDelegator::IsOpcodeSupported(const uint32_t opcode) const
    {
        if (m_useRemoteApi)
        {
            return m_remoteOperation.IsOpcodeSupported(opcode);
        }
        else
        {
            // If we're not in a remote operation we'll just be using classic
            // UIA, in which everything is supported.
            return true;
        }
    }

    void UiaOperationDelegator::AbortOperationWithHresult(HRESULT hr)
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            m_remoteOperation.ReturnOperationStatus(hr);
        }
        else
        {
            if (SUCCEEDED(hr))
            {
                // NOTE: the only thing that catches this exception is the UiaOperationScope::Compile method.
                // Therefore, if you want to return success, you MUST use Compile rather than the older
                // create scope ... do operations ... resolve method.
                throw ReturnSuccessException();
            }
            THROW_HR(hr);
        }
    }

    // The following methods convert a std::variant containing local type to the corresponding remote operations stand-in
    // type. These methods do nothing in the local operations case since no conversion is required there since the local types
    // are used directly in the operations.
    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<BOOL,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteBool>& localBoolVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localBool = std::get_if<BOOL>(&localBoolVariant))
            {
                localBoolVariant = m_remoteOperation.NewBool(*localBool);
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<int,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt>& localIntVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localInt = std::get_if<int>(&localIntVariant))
            {
                localIntVariant = m_remoteOperation.NewInt(*localInt);
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<unsigned int,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteUint>& localUintVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localUint = std::get_if<unsigned int>(&localUintVariant))
            {
                localUintVariant = m_remoteOperation.NewUint(*localUint);
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<double,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteDouble>& localDoubleVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localDouble = std::get_if<double>(&localDoubleVariant))
            {
                localDoubleVariant = m_remoteOperation.NewDouble(*localDouble);
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<wchar_t,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteChar>& localCharVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto local = std::get_if<wchar_t>(&localCharVariant))
            {
                localCharVariant = m_remoteOperation.NewChar(*local);
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<wil::shared_bstr,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>& localStringVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localString = std::get_if<wil::shared_bstr>(&localStringVariant))
            {
                localStringVariant = NewRemoteStringFromBstr(m_remoteOperation, localString->get());
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<winrt::Windows::Foundation::Point,
        winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint>& localPointVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localPoint = std::get_if<winrt::Windows::Foundation::Point>(&localPointVariant))
            {
                localPointVariant = m_remoteOperation.NewPoint(*localPoint);
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<winrt::Windows::Foundation::Rect,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect>& localRectVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localRect = std::get_if<winrt::Windows::Foundation::Rect>(&localRectVariant))
            {
                localRectVariant = m_remoteOperation.NewRect(*localRect);
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<UIA_HWND,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt>& localIntVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localHwnd = std::get_if<UIA_HWND>(&localIntVariant))
            {
                localIntVariant = m_remoteOperation.NewInt(HandleToLong(*localHwnd));
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<std::shared_ptr<wil::unique_variant>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject>& localVariantVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localVariantPointer = std::get_if<std::shared_ptr<wil::unique_variant>>(&localVariantVariant))
            {
                auto localVariant = *localVariantPointer;
                switch (localVariant->vt)
                {
                case VT_EMPTY:
                    localVariantVariant = m_remoteOperation.NewNull();
                    break;
                case VT_BOOL:
                    localVariantVariant = m_remoteOperation.NewBool(localVariant->boolVal ? true : false);
                    break;
                case VT_I4:
                    localVariantVariant = m_remoteOperation.NewInt(localVariant->lVal);
                    break;
                case VT_UI4:
                    localVariantVariant = m_remoteOperation.NewUint(localVariant->ulVal);
                    break;
                case VT_R8:
                    localVariantVariant = m_remoteOperation.NewDouble(localVariant->dblVal);
                    break;
                case VT_BSTR:
                    localVariantVariant = NewRemoteStringFromBstr(m_remoteOperation, localVariant->bstrVal);
                    break;
                default:
                    // The above are the only types currently supported by the UiaVariant wrapper
                    throw winrt::hresult_not_implemented();
                }
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<winrt::com_ptr<IUIAutomationElement>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteElement>& localElementVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localElement = std::get_if<winrt::com_ptr<IUIAutomationElement>>(&localElementVariant))
            {
                if (*localElement)
                {
                    localElementVariant = m_remoteOperation.ImportElement(FromAbi<AutomationElement>(localElement->get()));
                }
                else
                {
                    localElementVariant = m_remoteOperation.NewNull().AsElement();
                }
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<winrt::com_ptr<IUIAutomationTextRange>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextRange>& localTextRangeVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localTextRange = std::get_if<winrt::com_ptr<IUIAutomationTextRange>>(&localTextRangeVariant))
            {
                if (*localTextRange)
                {
                    localTextRangeVariant = m_remoteOperation.ImportTextRange(FromAbi<AutomationTextRange>(localTextRange->get()));
                }
                else
                {
                    localTextRangeVariant = m_remoteOperation.NewNull().AsTextRange();
                }
            }
        }
    }

    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<winrt::guid,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteGuid>& localGuidVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localGuid = std::get_if<winrt::guid>(&localGuidVariant))
            {
                localGuidVariant = m_remoteOperation.NewGuid(*localGuid);
            }
        }
    }


    UiaBool::UiaBool(bool value):
        UiaTypeBase(value ? TRUE : FALSE)
    {
        ToRemote();
    }

    UiaBool::UiaBool(BOOL value):
        UiaTypeBase(value)
    {
        ToRemote();
    }

    UiaBool::UiaBool(winrt::Microsoft::UI::UIAutomation::AutomationRemoteBool remoteValue):
        UiaTypeBase(remoteValue)
    {
    }

    UiaBool::UiaBool(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsBool())
    {
    }

    UiaBool::operator BOOL() const
    {
        return std::get<BOOL>(m_member);
    }

    UiaBool::operator bool() const
    {
        return std::get<BOOL>(m_member) ? true : false;
    }

    UiaBool& UiaBool::operator=(const UiaBool& other)
    {
        AssignCopyTo<UiaBool>(this->m_member, other.m_member);
        return *this;
    }

    UiaBool UiaBool::operator!() const
    {
        if (ShouldUseRemoteApi())
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            // if ShouldUseRemoteApi returns true, delegator has to be non-null.
            FAIL_FAST_IF(!delegator);

            // It is efficient to create a non-const copy of a UiaWrapperType-derived object because the
            // copy constructor copies the reference while operator= copies the data. Thus, creating
            // mutableThis does not create a new remote if this was already remote.
            auto mutableThis = *this;
            delegator->ConvertVariantDataToRemote(mutableThis.m_member);
            return std::get<AutomationRemoteBool>(mutableThis.m_member).BoolNot();
        }

        return !std::get<BOOL>(m_member);
    }

    UiaBool UiaBool::operator&&(const UiaBool& rhs) const
    {
        return BinaryOperator<UiaBool, And>(m_member, rhs.m_member);
    }

    UiaBool UiaBool::operator||(const UiaBool& rhs) const
    {
        return BinaryOperator<UiaBool, Or>(m_member, rhs.m_member);
    }

    UiaBool UiaBool::operator==(const UiaBool& rhs) const
    {
        return BinaryOperator<UiaBool, Equal>(this->m_member, rhs.m_member);
    }

    UiaBool UiaBool::operator!=(const UiaBool& rhs) const
    {
        return BinaryOperator<UiaBool, NotEqual>(this->m_member, rhs.m_member);
    }

    UiaString UiaBool::Stringify()
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->Stringify();
            }
        }

        return std::get<BOOL>(m_member) ? L"true" : L"false";
    }

    UiaInt::UiaInt(int value):
        UiaTypeBase(value)
    {
        ToRemote();
    }

    UiaInt::UiaInt(winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt remoteValue):
        UiaTypeBase(remoteValue)
    {
    }

    UiaInt::UiaInt(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsInt())
    {
    }

    UiaInt::operator int() const
    {
        return std::get<int>(m_member);
    }

    UiaInt& UiaInt::operator=(const UiaInt& other)
    {
        AssignCopyTo<UiaInt>(this->m_member, other.m_member);
        return *this;
    }

    UiaBool UiaInt::operator==(const UiaInt& rhs) const
    {
        return BinaryOperator<UiaInt, Equal>(this->m_member, rhs.m_member);
    }

    UiaBool UiaInt::operator!=(const UiaInt& rhs) const
    {
        return BinaryOperator<UiaInt, NotEqual>(this->m_member, rhs.m_member);
    }

    UiaBool UiaInt::operator<(const UiaInt& rhs) const
    {
        return BinaryOperator<UiaInt, LessThan>(this->m_member, rhs.m_member);
    }

    UiaBool UiaInt::operator<=(const UiaInt& rhs) const
    {
        return BinaryOperator<UiaInt, LessThanOrEqual>(this->m_member, rhs.m_member);
    }

    UiaBool UiaInt::operator>(const UiaInt& rhs) const
    {
        return BinaryOperator<UiaInt, GreaterThan>(this->m_member, rhs.m_member);
    }

    UiaBool UiaInt::operator>=(const UiaInt& rhs) const
    {
        return BinaryOperator<UiaInt, GreaterThanOrEqual>(this->m_member, rhs.m_member);
    }

    void UiaInt::operator+=(UiaInt rhs)
    {
        InPlaceArithmetic<UiaInt, Add>(this->m_member, rhs.m_member);
    }

    void UiaInt::operator-=(UiaInt rhs)
    {
        InPlaceArithmetic<UiaInt, Subtract>(this->m_member, rhs.m_member);
    }

    void UiaInt::operator*=(UiaInt rhs)
    {
        InPlaceArithmetic<UiaInt, Multiply>(this->m_member, rhs.m_member);
    }

    void UiaInt::operator/=(UiaInt rhs)
    {
        InPlaceArithmetic<UiaInt, Divide>(this->m_member, rhs.m_member);
    }

    UiaString UiaInt::Stringify()
    {
        return ArithmeticStringify<UiaInt>(m_member);
    }

    UiaUint::UiaUint(unsigned int value):
        UiaTypeBase(value)
    {
        ToRemote();
    }

    UiaUint::UiaUint(int value) :
        UiaTypeBase(static_cast<unsigned int>(value))
    {
        ToRemote();
    }

    UiaUint::UiaUint(DWORD value) :
        UiaTypeBase(static_cast<unsigned int>(value))
    {
        ToRemote();
    }

    UiaUint::UiaUint(winrt::Microsoft::UI::UIAutomation::AutomationRemoteUint remoteValue):
        UiaTypeBase(remoteValue)
    {
    }

    UiaUint::UiaUint(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsUint())
    {
    }

    UiaUint::operator unsigned int() const
    {
        return std::get<unsigned int>(m_member);
    }

    UiaUint& UiaUint::operator=(const UiaUint& other)
    {
        AssignCopyTo<UiaUint>(this->m_member, other.m_member);
        return *this;
    }

    UiaBool UiaUint::operator==(const UiaUint& rhs) const
    {
        return BinaryOperator<UiaUint, Equal>(this->m_member, rhs.m_member);
    }

    UiaBool UiaUint::operator!=(const UiaUint& rhs) const
    {
        return BinaryOperator<UiaUint, NotEqual>(this->m_member, rhs.m_member);
    }

    UiaBool UiaUint::operator<(const UiaUint& rhs) const
    {
        return BinaryOperator<UiaUint, LessThan>(this->m_member, rhs.m_member);
    }

    UiaBool UiaUint::operator<=(const UiaUint& rhs) const
    {
        return BinaryOperator<UiaUint, LessThanOrEqual>(this->m_member, rhs.m_member);
    }

    UiaBool UiaUint::operator>(const UiaUint& rhs) const
    {
        return BinaryOperator<UiaUint, GreaterThan>(this->m_member, rhs.m_member);
    }

    UiaBool UiaUint::operator>=(const UiaUint& rhs) const
    {
        return BinaryOperator<UiaUint, GreaterThanOrEqual>(this->m_member, rhs.m_member);
    }

    void UiaUint::operator+=(UiaUint rhs)
    {
        InPlaceArithmetic<UiaUint, Add>(this->m_member, rhs.m_member);
    }

    void UiaUint::operator-=(UiaUint rhs)
    {
        InPlaceArithmetic<UiaUint, Subtract>(this->m_member, rhs.m_member);
    }

    void UiaUint::operator*=(UiaUint rhs)
    {
        InPlaceArithmetic<UiaUint, Multiply>(this->m_member, rhs.m_member);
    }

    void UiaUint::operator/=(UiaUint rhs)
    {
        InPlaceArithmetic<UiaUint, Divide>(this->m_member, rhs.m_member);
    }

    UiaString UiaUint::Stringify()
    {
        return ArithmeticStringify<UiaUint>(m_member);
    }

    UiaDouble::UiaDouble(double value):
        UiaTypeBase(value)
    {
        ToRemote();
    }

    UiaDouble::UiaDouble(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDouble remoteValue):
        UiaTypeBase(remoteValue)
    {
    }

    UiaDouble::UiaDouble(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsDouble())
    {
    }

    UiaDouble::operator double() const
    {
        return std::get<double>(m_member);
    }

    UiaDouble& UiaDouble::operator=(const UiaDouble& other)
    {
        AssignCopyTo<UiaDouble>(this->m_member, other.m_member);
        return *this;
    }

    UiaBool UiaDouble::operator==(const UiaDouble& rhs) const
    {
        return BinaryOperator<UiaDouble, Equal>(this->m_member, rhs.m_member);
    }

    UiaBool UiaDouble::operator!=(const UiaDouble& rhs) const
    {
        return BinaryOperator<UiaDouble, NotEqual>(this->m_member, rhs.m_member);
    }

    UiaBool UiaDouble::operator<(const UiaDouble& rhs) const
    {
        return BinaryOperator<UiaDouble, LessThan>(this->m_member, rhs.m_member);
    }

    UiaBool UiaDouble::operator<=(const UiaDouble& rhs) const
    {
        return BinaryOperator<UiaDouble, LessThanOrEqual>(this->m_member, rhs.m_member);
    }

    UiaBool UiaDouble::operator>(const UiaDouble& rhs) const
    {
        return BinaryOperator<UiaDouble, GreaterThan>(this->m_member, rhs.m_member);
    }

    UiaBool UiaDouble::operator>=(const UiaDouble& rhs) const
    {
        return BinaryOperator<UiaDouble, GreaterThanOrEqual>(this->m_member, rhs.m_member);
    }

    void UiaDouble::operator+=(UiaDouble rhs)
    {
        InPlaceArithmetic<UiaDouble, Add>(this->m_member, rhs.m_member);
    }

    void UiaDouble::operator-=(UiaDouble rhs)
    {
        InPlaceArithmetic<UiaDouble, Subtract>(this->m_member, rhs.m_member);
    }

    void UiaDouble::operator*=(UiaDouble rhs)
    {
        InPlaceArithmetic<UiaDouble, Multiply>(this->m_member, rhs.m_member);
    }

    void UiaDouble::operator/=(UiaDouble rhs)
    {
        InPlaceArithmetic<UiaDouble, Divide>(this->m_member, rhs.m_member);
    }

    UiaString UiaDouble::Stringify()
    {
        return ArithmeticStringify<UiaDouble>(m_member);
    }

    UiaChar::UiaChar(wchar_t value) :
        UiaTypeBase(value)
    {
        ToRemote();
    }

    UiaChar::UiaChar(winrt::Microsoft::UI::UIAutomation::AutomationRemoteChar remoteValue) :
        UiaTypeBase(remoteValue)
    {
    }

    UiaChar::UiaChar(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue) :
        UiaTypeBase(remoteValue.AsChar())
    {
    }

    UiaChar::operator wchar_t() const
    {
        return std::get<wchar_t>(m_member);
    }

    UiaChar& UiaChar::operator=(const UiaChar& other)
    {
        AssignCopyTo<UiaChar>(this->m_member, other.m_member);
        return *this;
    }

    UiaBool UiaChar::operator==(const UiaChar& rhs) const
    {
        return BinaryOperator<UiaChar, Equal>(this->m_member, rhs.m_member);
    }

    UiaBool UiaChar::operator!=(const UiaChar& rhs) const
    {
        return BinaryOperator<UiaChar, NotEqual>(this->m_member, rhs.m_member);
    }

    UiaString UiaChar::Stringify()
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->Stringify();
            }
        }

        return std::wstring(1 /* size n */, std::get<wchar_t>(m_member));
    }

    UiaString::UiaString(std::wstring value):
        UiaTypeBase(SafeToUniqueBstr(value))
    {
        ToRemote();
    }

    UiaString::UiaString(const wchar_t* value):
        UiaTypeBase(value ? wil::make_bstr(value) : nullptr)
    {
        ToRemote();
    }

    UiaString::UiaString(wil::unique_bstr&& value):
        UiaTypeBase(std::move(value))
    {
        ToRemote();
    }

    UiaString::UiaString(const wil::shared_bstr& value):
        UiaTypeBase(value)
    {
        ToRemote();
    }

    UiaString::UiaString(winrt::Microsoft::UI::UIAutomation::AutomationRemoteString remoteValue):
        UiaTypeBase(remoteValue)
    {
    }

    UiaString::UiaString(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsString())
    {
    }

    UiaString::operator wil::shared_bstr() const
    {
        return std::get<wil::shared_bstr>(m_member);
    }

    BSTR UiaString::get() const
    {
        return std::get<wil::shared_bstr>(m_member).get();
    }

    std::wstring UiaString::GetLocalWstring() const
    {
        auto localValue = std::get<wil::shared_bstr>(m_member);
        return std::wstring(localValue ? localValue.get() : L"");
    }

    UiaBool UiaString::IsNull() const
    {
        if (ShouldUseRemoteApi())

        {
            auto remoteValue = std::get_if<winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaString& UiaString::operator=(const UiaString& other)
    {
        if (ShouldUseRemoteApi())
        {
            this->ToRemote();
            auto mutableOther = other;
            mutableOther.ToRemote();
            std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>(m_member).Set(std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>(mutableOther.m_member));
        }
        else
        {
            std::get<wil::shared_bstr>(m_member) = std::get<wil::shared_bstr>(other.m_member);
        }

        return *this;
    }

    UiaBool UiaString::operator==(const UiaString& rhs) const
    {
        if (ShouldUseRemoteApi())
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            FAIL_FAST_IF(!delegator);

            auto mutableThis = *this;
            delegator->ConvertVariantDataToRemote(mutableThis.m_member);
            auto mutableRhs = rhs;
            delegator->ConvertVariantDataToRemote(mutableRhs.m_member);
            return std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>(mutableThis.m_member).IsEqual(std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>(mutableRhs.m_member));
        }

        return wcscmp(std::get<wil::shared_bstr>(m_member).get(), std::get<wil::shared_bstr>(rhs.m_member).get()) == 0;
    }

    UiaBool UiaString::operator!=(const UiaString& rhs) const
    {
        if (ShouldUseRemoteApi())
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            FAIL_FAST_IF(!delegator);

            auto mutableThis = *this;
            delegator->ConvertVariantDataToRemote(mutableThis.m_member);
            auto mutableRhs = rhs;
            delegator->ConvertVariantDataToRemote(mutableRhs.m_member);
            return std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>(mutableThis.m_member).IsNotEqual(std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>(mutableRhs.m_member));
        }
        return wcscmp(std::get<wil::shared_bstr>(m_member).get(), std::get<wil::shared_bstr>(rhs.m_member).get()) != 0;
    }

    UiaUint UiaString::Length() const
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>(&m_member);
            if (remoteValue)
            {
                return remoteValue->Size();
            }
            // If we should use the remote API, but this string has not yet been remoted, get the local length instead.
        }

        return ::SysStringLen(std::get<wil::shared_bstr>(m_member).get());
    }

    UiaChar UiaString::At(UiaUint index)
    {
        if (ShouldUseRemoteApi())
        {
            ToRemote();
            index.ToRemote();
            return std::get<RemoteType>(m_member).GetAt(index);
        }

        const auto localVal = get();
        const auto len = ::SysStringLen(localVal);
        if (index >= len)
        {
            throw std::out_of_range("index out of bounds");
        }

        return localVal[index];
    }

    UiaPoint::UiaPoint() : UiaPoint(winrt::Windows::Foundation::Point{ 0.0f /* X */, 0.0f /* Y */ })
    {
    }

    UiaPoint::UiaPoint(POINT point):
        UiaTypeBase(winrt::Windows::Foundation::Point(static_cast<float>(point.x), static_cast<float>(point.y)))
    {
        ToRemote();
    }

    UiaPoint::UiaPoint(winrt::Windows::Foundation::Point point):
        UiaTypeBase(point)
    {
        ToRemote();
    }

    UiaPoint::UiaPoint(winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint remotePoint):
        UiaTypeBase(remotePoint)
    {
    }

    UiaPoint::UiaPoint(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsPoint())
    {
    }

    UiaPoint::operator winrt::Windows::Foundation::Point() const
    {
        return std::get<winrt::Windows::Foundation::Point>(m_member);
    }

    UiaPoint::operator POINT() const
    {
        auto internalPoint = std::get<winrt::Windows::Foundation::Point>(m_member);
        return POINT{static_cast<LONG>(internalPoint.X), static_cast<LONG>(internalPoint.Y)};
    }

    UiaPoint& UiaPoint::operator=(const UiaPoint& other)
    {
        AssignCopyTo<UiaPoint>(this->m_member, other.m_member);
        return *this;
    }

    UiaBool UiaPoint::operator==(const UiaPoint& rhs) const
    {
        if (ShouldUseRemoteApi())
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            FAIL_FAST_IF(!delegator);
            auto mutableThis = *this;
            mutableThis.ToRemote();
            auto mutableRhs = rhs;
            mutableRhs.ToRemote();
            return std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint>(mutableThis.m_member).IsEqual(std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint>(mutableRhs.m_member));
        }

        auto lhsLocalPoint = std::get<winrt::Windows::Foundation::Point>(m_member);
        auto rhsLocalPoint = std::get<winrt::Windows::Foundation::Point>(rhs.m_member);
        return (lhsLocalPoint.X == rhsLocalPoint.X) && (lhsLocalPoint.Y == rhsLocalPoint.Y);
    }

    UiaBool UiaPoint::operator!=(const UiaPoint& rhs) const
    {
        if (ShouldUseRemoteApi())
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            FAIL_FAST_IF(!delegator);
            auto mutableThis = *this;
            mutableThis.ToRemote();
            auto mutableRhs = rhs;
            mutableRhs.ToRemote();
            return std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint>(mutableThis.m_member).IsNotEqual(std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint>(mutableRhs.m_member));
        }

        auto lhsLocalPoint = std::get<winrt::Windows::Foundation::Point>(m_member);
        auto rhsLocalPoint = std::get<winrt::Windows::Foundation::Point>(rhs.m_member);

        return (lhsLocalPoint.X != rhsLocalPoint.X) || (lhsLocalPoint.Y != rhsLocalPoint.Y);
    }

    UiaString UiaPoint::Stringify()
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->Stringify();
            }
        }

        auto localPoint = std::get<winrt::Windows::Foundation::Point>(m_member);
        std::wostringstream ss;
        ss << L"Point{ " << localPoint.X << L"," << localPoint.Y << " }";
        return ss.str();
    }

    UiaRect::UiaRect() : UiaRect(winrt::Windows::Foundation::Rect{ 0.0f /* X */, 0.0f /* Y */, 0.0f /* Width */, 0.0f /* Height */ })
    {
    }

    UiaRect::UiaRect(RECT rect):
        UiaTypeBase(ConvertRect(rect))
    {
        ToRemote();
    }

    UiaRect::UiaRect(winrt::Windows::Foundation::Rect rect):
        UiaTypeBase(rect)
    {
        ToRemote();
    }

    UiaRect::UiaRect(winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect remoteRect):
        UiaTypeBase(remoteRect)
    {
    }

    UiaRect::UiaRect(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsRect())
    {
    }

    UiaRect::operator winrt::Windows::Foundation::Rect() const
    {
        return std::get<winrt::Windows::Foundation::Rect>(m_member);
    }

    UiaRect::operator RECT() const
    {
        return ConvertRect(std::get<winrt::Windows::Foundation::Rect>(m_member));
    }

    UiaRect& UiaRect::operator=(const UiaRect& other)
    {
        AssignCopyTo<UiaRect>(this->m_member, other.m_member);
        return *this;
    }

    UiaBool UiaRect::operator==(const UiaRect& rhs) const
    {
        if (ShouldUseRemoteApi())
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            FAIL_FAST_IF(!delegator);

            auto mutableThis = *this;
            mutableThis.ToRemote();
            auto mutableRhs = rhs;
            mutableRhs.ToRemote();
            return std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect>(mutableThis.m_member).IsEqual(std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect>(mutableRhs.m_member));
        }

        auto lhsLocalRect = std::get<winrt::Windows::Foundation::Rect>(m_member);
        auto rhsLocalRect = std::get<winrt::Windows::Foundation::Rect>(rhs.m_member);

        return (lhsLocalRect.Height == rhsLocalRect.Height) &&
            (lhsLocalRect.Width == rhsLocalRect.Width) &&
            (lhsLocalRect.X == rhsLocalRect.X) &&
            (lhsLocalRect.Y == rhsLocalRect.Y);
    }

    UiaBool UiaRect::operator!=(const UiaRect& rhs) const
    {
        if (ShouldUseRemoteApi())
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            FAIL_FAST_IF(!delegator);

            auto mutableThis = *this;
            mutableThis.ToRemote();
            auto mutableRhs = rhs;
            mutableRhs.ToRemote();
            return std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect>(mutableThis.m_member).IsNotEqual(std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect>(mutableRhs.m_member));
        }

        auto lhsLocalRect = std::get<winrt::Windows::Foundation::Rect>(m_member);
        auto rhsLocalRect = std::get<winrt::Windows::Foundation::Rect>(rhs.m_member);

        return (lhsLocalRect.Height != rhsLocalRect.Height) ||
            (lhsLocalRect.Width != rhsLocalRect.Width) ||
            (lhsLocalRect.X != rhsLocalRect.X) ||
            (lhsLocalRect.Y != rhsLocalRect.Y);
    }
    
    UiaDouble UiaRect::GetHeight() const
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->GetHeight();
            }
        }

        return static_cast<double>(std::get<LocalType>(m_member).Height);
    }

    UiaDouble UiaRect::GetWidth() const
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->GetWidth();
            }
        }

        return static_cast<double>(std::get<LocalType>(m_member).Width);
    }

    UiaDouble UiaRect::GetX() const
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->GetX();
            }
        }

        return static_cast<double>(std::get<LocalType>(m_member).X);
    }

    UiaDouble UiaRect::GetY() const
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->GetY();
            }
        }

        return static_cast<double>(std::get<LocalType>(m_member).Y);
    }

    UiaString UiaRect::Stringify()
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->Stringify();
            }
        }

        const auto rect = std::get<winrt::Windows::Foundation::Rect>(m_member);
        std::wostringstream ss;
        ss << L"Rect{ " << rect.X << L"," << rect.Y << L"," << rect.Width << L"," << rect.Height << L" }";

        return ss.str();
    }

    UiaHwnd::UiaHwnd(UIA_HWND hwnd):
        UiaTypeBase(hwnd)
    {
        ToRemote();
    }

    UiaHwnd::UiaHwnd(winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt remoteHwnd):
        UiaTypeBase(remoteHwnd)
    {
    }

    UiaHwnd::UiaHwnd(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
        UiaTypeBase(remoteValue.AsInt())
    {
    }

    UiaHwnd::operator UIA_HWND() const
    {
        return std::get<UIA_HWND>(m_member);
    }

    UiaBool UiaHwnd::operator==(const UiaHwnd& rhs) const
    {
        return BinaryOperator<UiaHwnd, Equal>(this->m_member, rhs.m_member);
    }

    UiaBool UiaHwnd::operator!=(const UiaHwnd& rhs) const
    {
        return BinaryOperator<UiaHwnd, NotEqual>(this->m_member, rhs.m_member);
    }

    UiaVariant::UiaVariant() : UiaVariant(wil::unique_variant{})
    {
    }

    UiaVariant::UiaVariant(const VARIANT& variant):
        UiaTypeBase(std::make_shared<wil::unique_variant>(CopyToUniqueVariant(variant)))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(wil::unique_variant&& variant) :
        UiaTypeBase(std::make_shared<wil::unique_variant>(std::move(variant)))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(AutomationRemoteObject remote) :
        UiaTypeBase(remote)
    {
    }

    UiaVariant::UiaVariant(AutomationRemoteAnyObject remote) :
        UiaTypeBase(static_cast<AutomationRemoteObject>(remote))
    {
    }

    UiaVariant::UiaVariant(AutomationRemoteBool remote) :
        UiaTypeBase(static_cast<AutomationRemoteObject>(remote))
    {
    }

    UiaVariant::UiaVariant(AutomationRemoteInt remote) :
        UiaTypeBase(static_cast<AutomationRemoteObject>(remote))
    {
    }

    UiaVariant::UiaVariant(AutomationRemoteUint remote) :
        UiaTypeBase(static_cast<AutomationRemoteObject>(remote))
    {
    }

    UiaVariant::UiaVariant(AutomationRemoteDouble remote) :
        UiaTypeBase(static_cast<AutomationRemoteObject>(remote))
    {
    }

    UiaVariant::UiaVariant(AutomationRemoteString remote) :
        UiaTypeBase(static_cast<AutomationRemoteObject>(remote))
    {
    }

    UiaVariant::UiaVariant(bool value) :
        UiaTypeBase(details::MakeVariantFrom<UiaBool>(value ? VARIANT_TRUE : VARIANT_FALSE))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(int value) :
        UiaTypeBase(details::MakeVariantFrom<UiaInt>(static_cast<LONG>(value)))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(unsigned int value) :
        UiaTypeBase(details::MakeVariantFrom<UiaUint>(static_cast<ULONG>(value)))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(double value) :
        UiaTypeBase(details::MakeVariantFrom<UiaDouble>(value))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(BSTR value) :
        UiaTypeBase(details::MakeVariantFrom<UiaString>(wil::make_bstr(value).release()))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(UiaBool value) :
        UiaTypeBase(
            value.IsRemoteType() ?
            UiaVariant(static_cast<AutomationRemoteObject>(static_cast<UiaBool::RemoteType>(value))) :
            UiaVariant(details::MakeVariantFrom<UiaBool>(static_cast<bool>(value) ? VARIANT_TRUE : VARIANT_FALSE)))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(UiaInt value) :
        UiaTypeBase(
            value.IsRemoteType() ?
            UiaVariant(static_cast<AutomationRemoteObject>(static_cast<UiaInt::RemoteType>(value))) :
            UiaVariant(details::MakeVariantFrom<UiaInt>(static_cast<LONG>(static_cast<int>(value)))))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(UiaUint value) :
        UiaTypeBase(
            value.IsRemoteType() ?
            UiaVariant(static_cast<AutomationRemoteObject>(static_cast<UiaUint::RemoteType>(value))) :
            UiaVariant(details::MakeVariantFrom<UiaUint>(static_cast<ULONG>(static_cast<unsigned int>(value)))))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(UiaDouble value) :
        UiaTypeBase(
            value.IsRemoteType() ?
            UiaVariant(static_cast<AutomationRemoteObject>(static_cast<UiaDouble::RemoteType>(value))) :
            UiaVariant(details::MakeVariantFrom<UiaDouble>(static_cast<double>(value))))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(UiaString value) :
        UiaTypeBase(
            value.IsRemoteType() ?
            UiaVariant(static_cast<AutomationRemoteObject>(static_cast<UiaString::RemoteType>(value))) :
            UiaVariant(details::MakeVariantFrom<UiaString>(wil::make_bstr(static_cast<UiaString::LocalType>(value).get()).release())))
    {
        ToRemote();
    }

    UiaVariant::UiaVariant(UiaElement value) :
        UiaTypeBase(
            value.IsRemoteType() ?
            UiaVariant(static_cast<AutomationRemoteObject>(static_cast<UiaElement::RemoteType>(value))) :
            UiaVariant(details::MakeVariantFrom<UiaElement>(wil::com_ptr<IUIAutomationElement>(value.get()).detach())))
    {
        ToRemote();
    }

    UiaBool UiaVariant::IsNull() const
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<RemoteType>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        // The local version of a UiaVariant can never be null.
        return false;
    }

    UiaBool UiaVariant::operator==(const UiaVariant& rhs)
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteObject = std::get_if<typename RemoteType>(&m_member);
            auto rhsRemoteObject = std::get_if<typename RemoteType>(&rhs.m_member);
            if (remoteObject || rhsRemoteObject)
            {
                // at least one of the objects is remote so we have to test remotely

                auto remoteAny = remoteObject->try_as<AutomationRemoteAnyObject>();
                auto rhsRemoteAny = rhsRemoteObject->try_as<AutomationRemoteAnyObject>();

                if (remoteAny && rhsRemoteAny)
                {
                    // we need an IsEqual/IsNotEqual for RemoteAny objects.
                    throw winrt::hresult_not_implemented();
                }
                else if (remoteAny)
                {
                    return AnyEqualsType(remoteAny, *rhsRemoteObject);
                }
                else if (rhsRemoteAny)
                {
                    return AnyEqualsType(rhsRemoteAny, *remoteObject);
                }
                else
                {
                    return TypeEqualsType(*remoteObject, *rhsRemoteObject);
                }
            }
        }

        // Make sure the types match
        const auto lhsLocal = std::get<LocalType>(m_member);
        const auto rhsLocal = std::get<LocalType>(rhs.m_member);
        if (lhsLocal->vt != rhsLocal->vt)
        {
            return false;
        }

        switch (lhsLocal->vt)
        {
        case VT_EMPTY:
            return true;
        case VT_BOOL:
            return lhsLocal->boolVal == rhsLocal->boolVal;
        case VT_I4:
            return lhsLocal->lVal == rhsLocal->lVal;
        case VT_UI4:
            return lhsLocal->ulVal == rhsLocal->ulVal;
        case VT_R8:
            return lhsLocal->dblVal == rhsLocal->dblVal;
        case VT_BSTR:
            return (lhsLocal->bstrVal == nullptr && rhsLocal->bstrVal == nullptr) ||
                ((lhsLocal->bstrVal != nullptr && rhsLocal->bstrVal != nullptr) &&
                (wcscmp(lhsLocal->bstrVal, rhsLocal->bstrVal) == 0));
        default:
            // The above are the only types currently supported by the UiaVariant wrapper
            throw winrt::hresult_not_implemented();
        }
    }

    UiaBool UiaVariant::operator!=(const UiaVariant& rhs)
    {
        return !(*this == rhs);
    }

    UiaBool UiaVariant::IsNotSupported() const
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteObject = std::get<RemoteType>(m_member);
            auto remoteAny = remoteObject.try_as<AutomationRemoteAnyObject>();
            if (remoteAny)
            {
                return remoteAny.IsNotSupported();
            }
            else
            {
                return false;
            }
        }
        const auto localValue = std::get<std::shared_ptr<wil::unique_variant>>(m_member);
        if(localValue->vt == VT_UNKNOWN) {
            wil::com_ptr<IUnknown> notSupportedVal;
            g_automation.get()->get_ReservedNotSupportedValue(&notSupportedVal);
            return localValue->punkVal == notSupportedVal.get();
        }
        return false;
    }

    UiaBool UiaVariant::IsMixedAttribute() const
    {
        if (ShouldUseRemoteApi())
        {
            auto remoteObject = std::get<RemoteType>(m_member);
            auto remoteAny = remoteObject.try_as<AutomationRemoteAnyObject>();
            if (remoteAny)
            {
                return remoteAny.IsMixedAttribute();
            }
            else
            {
                return false;
            }
        }
        const auto localValue = std::get<std::shared_ptr<wil::unique_variant>>(m_member);
        if(localValue->vt == VT_UNKNOWN) {
            wil::com_ptr<IUnknown> mixedAttributeVal;
            g_automation.get()->get_ReservedMixedAttributeValue(&mixedAttributeVal);
            return localValue->punkVal == mixedAttributeVal.get();
        }
        return false;
    }

    UiaBool UiaVariant::IsBool() const
    {
        return IsType<UiaBool>();
    }

    UiaBool UiaVariant::AsBool() const
    {
        return AsType<UiaBool>();
    }

    UiaBool UiaVariant::IsInt() const
    {
        return IsType<UiaInt>();
    }

    UiaInt UiaVariant::AsInt() const
    {
        return AsType<UiaInt>();
    }

    UiaBool UiaVariant::IsUint() const
    {
        return IsType<UiaUint>();
    }

    UiaUint UiaVariant::AsUint() const
    {
        return AsType<UiaUint>();
    }

    UiaBool UiaVariant::IsDouble() const
    {
        return IsType<UiaDouble>();
    }

    UiaDouble UiaVariant::AsDouble() const
    {
        return AsType<UiaDouble>();
    }

    UiaBool UiaVariant::IsString() const
    {
        return IsType<UiaString>();
    }

    UiaString UiaVariant::AsString() const
    {
        return AsType<UiaString>();
    }

    UiaBool UiaVariant::IsElement() const
    {
        return IsType<UiaElement>();
    }

    UiaElement UiaVariant::AsElement() const
    {
        return AsType<UiaElement>();
    }

    UiaVariant::operator std::shared_ptr<wil::unique_variant>() const
    {
        return std::get<std::shared_ptr<wil::unique_variant>>(m_member);
    }

    VARIANT UiaVariant::get() const
    {
        return static_cast<VARIANT>(*std::get<std::shared_ptr<wil::unique_variant>>(m_member));
    }

    UiaVariant::operator winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject() const
    {
        return std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject>(m_member);
    }


#include "UiaTypeAbstractionImpl.g.cpp"

    UiaOperationAbstraction::FlsStorage<UiaScopeContextManager> UiaOperationScope::s_scopeContextManager;

    UiaOperationScope::UiaOperationScope(bool ownContext):
        m_ownContext(ownContext)
    {
    }

    UiaOperationScope::UiaOperationScope(UiaOperationScope&& other):
        m_ownContext(other.m_ownContext)
    {
        other.m_ownContext = false;
    }

    UiaOperationScope::~UiaOperationScope()
    {
        // Ensure that the delegator is cleaned up in case we are failing out due to
        // an exception.
        if (m_ownContext)
        {
            s_scopeContextManager.Get().PopContext();
        }
    }

    UiaOperationScope& UiaOperationScope::operator=(UiaOperationScope&& other)
    {
        m_ownContext = other.m_ownContext;
        other.m_ownContext = false;
        return *this;
    }

    /* static */ std::shared_ptr<UiaOperationDelegator> UiaOperationScope::GetCurrentDelegator()
    {
        return s_scopeContextManager.Get().GetCurrentDelegator();
    }

    void UiaOperationScope::Resolve()
    {
        auto [status, extendedError] = ResolveInternal();
        switch(status)
        {
            case winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus::MalformedBytecode:
                throw MalformedBytecodeException(extendedError);
            case winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus::InstructionLimitExceeded:
                throw InstructionLimitExceededException(extendedError);
            case winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus::UnhandledException:
                throw UnhandledRemoteException(extendedError);
            case winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus::ExecutionFailure:
                throw ExecutionFailureException(extendedError);
            default:
                THROW_IF_FAILED(extendedError);
        }
    }

    [[nodiscard]] HRESULT UiaOperationScope::ResolveHr() noexcept try
    {
        auto [status, extendedError] = ResolveInternal();
        return extendedError;
    }
    CATCH_RETURN();
  
    std::pair<winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus, HRESULT> UiaOperationScope::ResolveInternal()
    {
        auto status = winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus::Success;
        HRESULT extendedError = S_OK;

        // Resolve does nothing if we don't own the current context. 
        if (m_ownContext)
        {
            auto delegator = GetCurrentDelegator();
            if (delegator->GetUseRemoteApi())
            {
                for (auto& binding : s_scopeContextManager.Get().GetCurrentBindings())
                {
                    binding(this);
                }

                auto result = delegator->Execute();

                status = result.Status();
                extendedError = result.ExtendedError();

                // instructionLimitExceeded status comes with an extendedError of success.
                // Force it to E_FAIL to stay compatible with the older OperationStatus method.
                // I.e. on InstructionLimitExceeded, ResolveHr will still return E_FAIL
                // and resolve will throw InstructionLimitExceededException (which inherits from winrt::hresult_error) with a code of E_FAIL.
                if(status == winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus::InstructionLimitExceeded)
                {
                    extendedError = E_FAIL;
                }

                // Fetch bound results on success, but also
                // instruction limit exceeded, 
                // As we no certainly some of the remote operation did execute.
                if (
                    status == winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus::Success
                    || status == winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus::InstructionLimitExceeded
                )
                {
                    for (auto& resolver : remoteOperationResolvers)
                    {
                        resolver(result);
                    }
                }
            }

            s_scopeContextManager.Get().PopContext();
            m_ownContext = false;
        }
        return {status, extendedError};
    }

    UiaOperationScope UiaOperationScope::StartNew()
    {
        s_scopeContextManager.Get().PushContext();
        return UiaOperationScope(true /* ownContext */);
    }

    UiaOperationScope UiaOperationScope::StartOrContinue()
    {
        if (GetCurrentDelegator())
        {
            return UiaOperationScope(false /* ownContext */);
        }
        return StartNew();
    }

    UiaOperationScope UiaOperationScope::ContinueIfRemote()
    {
        if (ShouldUseRemoteApi())
        {
            return UiaOperationScope(false /* ownContext */);
        }
        // if there is no active remote operation, create a context that never executes remotely.
        s_scopeContextManager.Get().PushLocalContext();
        return UiaOperationScope(true /* ownContext */);
    }

    bool ShouldUseRemoteApi()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        return delegator && delegator->GetUseRemoteApi();
    }
} // namespace UiaOperationAbstraction
