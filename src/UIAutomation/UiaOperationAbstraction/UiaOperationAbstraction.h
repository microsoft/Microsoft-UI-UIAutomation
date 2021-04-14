// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include <variant>
#include <memory>
#include <optional>
#include <functional>
#include <sstream>

#include <combaseapi.h>
#include <UIAutomation.h>
#include <fibersapi.h>

#include <wil/resource.h>
#include <wil/com.h>

#include <winrt/Microsoft.UI.UIAutomation.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>

// Implements an API that allows users to write code that can execute either in a UIAutomation Remote Operation or
// in the classic UIA approach where each call is a cross-process call.
//
// The user can switch between the two modes simply by setting a bool value indicating whether to use remote operations
// or not.
namespace UiaOperationAbstraction
{
    using unique_safearray = wil::unique_any<SAFEARRAY*, decltype(&::SafeArrayDestroy), ::SafeArrayDestroy>;

    // This type is representing a function type, where the return type is a template parameter, the function should be
    // a const member function of class `winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject`, the parameter
    // list is void.
    // For example, the type of function:
    //     `winrt::Microsoft::UI::UIAutomation::AutomationRemoteSayAsInterpretAs winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsSayAsInterpretAs() const;`
    // can be represented by CastFuncType<winrt::Microsoft::UI::UIAutomation::AutomationRemoteSayAsInterpretAs>.
    // This type is used as one of the template parameters of class `UiaEnum`, for the sake of this, we could assign the
    // any cast function for `UiaEnum`. And furthermore, we could use `UiaVariant::AsType` to convert `UiaVariant` to
    // any `UiaEnum` classes.
    template <typename StandinT>
    using CastFuncType = StandinT (winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::*)() const;

    // This function must be called before using the abstraction.
    void Initialize(bool useRemoteOperations, _In_ IUIAutomation* automation) noexcept;

    // This function must be called before process shutdown.
    // Note that this function will destroy all outstanding remote operation contexts in all threads, in no
    // particular order, so it should not be called unless you are absolutely sure that no such contexts exist.
    void Cleanup() noexcept;

    class UiaBool;
    class UiaInt;

    using Resolver = std::function<void(winrt::Microsoft::UI::UIAutomation::AutomationRemoteOperationResultSet&)>;

    class ReturnSuccessException : public std::exception
    {
        const char* what() const override { return "RemoteOperationsWrapper local return success"; }
    };

    class LoopContinueException : public std::exception
    {
        const char* what() const override { return "RemoteOperationsWrapper local loop continue"; }
    };

    class LoopBreakException : public std::exception
    {
        const char* what() const override { return "RemoteOperationsWrapper local loop break"; }
    };

    // The UiaOperationDelegator class in is charge of delegating calls on UIA wrapper types in this abstraction
    // to either the UIA remote operations API or the non-remote UIA API. This class also exposes basic constructs
    // such as if-statements and loops which operate on UIA abstraction wrapper types which should be used by
    // consumers of this abstraction.
    class UiaOperationDelegator
    {
    public:
        // Friend a helper class to allow UiaCacheRequest to have a single
        // default constructor. UiaCacheRequestHelper implements a static
        // function which reads m_remoteOperation in order to optionally call
        // m_remoteOperation.NewCacheRequest. Using a friend class here
        // provides additional encapsulation for the user of this library,
        // since otherwise we would need to implement a public function on
        // UiaOperationDelegator which UiaCacheRequest's constructor could call.
        friend struct UiaCacheRequestHelper;

        UiaOperationDelegator();
        UiaOperationDelegator(bool useRemoteApi);

        bool GetUseRemoteApi() const;

        template<class OnTrue, class OnFalse>
        void If(UiaBool conditionBool, OnTrue&& onTrue, OnFalse&& onFalse) const
        {
            if (m_useRemoteApi)
            {
                conditionBool.ToRemote();
                m_remoteOperation.IfBlock(conditionBool, std::forward<OnTrue>(onTrue), std::forward<OnFalse>(onFalse));
            }
            else
            {
                static_cast<bool>(conditionBool) ? onTrue() : onFalse();
            }
        }

        template<class OnTrue>
        void If(UiaBool conditionBool, OnTrue&& onTrue) const
        {
            if (m_useRemoteApi)
            {
                conditionBool.ToRemote();
                m_remoteOperation.IfBlock(conditionBool, std::forward<OnTrue>(onTrue));
            }
            else
            {
                if (static_cast<bool>(conditionBool))
                {
                    onTrue();
                }
            }
        }

        // This method handles a pure lvalue conditional.
        // This method MUST NOT be modified to take a const lvalue ref or a non-ref value, because those
        // would allow an expression as the first argument.
        // Usage like "While( blah < 5, [&](){...});" is a problem, because the "blah < 5" expression
        // only gets evaluated once, not once per iteration, which is not the desired behavior.
        template<class Body>
        void While(UiaBool& condition, Body body)
        {
            if (m_useRemoteApi)
            {
                condition.ToRemote();
                m_remoteOperation.WhileBlock(condition, std::forward<Body>(body));
            }
            else
            {
                while (static_cast<bool>(condition))
                {
                    try
                    {
                        body();
                    }
                    catch (UiaOperationAbstraction::LoopBreakException)
                    {
                        break;
                    }
                    catch (UiaOperationAbstraction::LoopContinueException)
                    {
                        // do nothing, but we've exited the body
                    }
                }
            }
        }

        // This method handles an expression as a condition. The expression must be embedded in a lambda, e.g.
        // [&](){return blah < 5;}
        template<class ConditionBlock, class Body>
        void While(ConditionBlock conditionBlock, Body body)
        {
            if (m_useRemoteApi)
            {
                UiaBool conditionTemporary = conditionBlock();
                conditionTemporary.ToRemote();
                m_remoteOperation.WhileBlock(
                    conditionTemporary,
                    std::forward<Body>(body),
                    [&]() // afterBody
                    {
                        conditionTemporary = conditionBlock();
                    });
            }
            else
            {
                while (static_cast<bool>(conditionBlock()))
                {
                    try
                    {
                        body();
                    }
                    catch (UiaOperationAbstraction::LoopBreakException)
                    {
                        break;
                    }
                    catch (UiaOperationAbstraction::LoopContinueException)
                    {
                        // do nothing, but we've exited the body
                    }
                }
            }
        }

        // This method provides something resembling a for loop, so users don't have to rewrite their for loops as while loops.
        template<class InitializeBlock, class ConditionBlock, class ModificationBlock, class Body>
        void For(InitializeBlock initialize, ConditionBlock condition, ModificationBlock modification, Body body)
        {
            if (m_useRemoteApi)
            {
                initialize();
                UiaBool conditionTemporary = condition();
                conditionTemporary.ToRemote();
                m_remoteOperation.WhileBlock(
                    conditionTemporary,
                    std::forward<Body>(body),
                    [&]() // afterBody
                    {
                        modification();
                        conditionTemporary = condition();
                    });
            }
            else
            {
                initialize();
                while (static_cast<bool>(condition()))
                {
                    try
                    {
                        body();
                    }
                    catch (UiaOperationAbstraction::LoopBreakException)
                    {
                        break;
                    }
                    catch (UiaOperationAbstraction::LoopContinueException)
                    {
                        // do nothing, but we've exited the body
                    }
                    modification();
                }
            }
        }

        // analogous to the c++ break keyword. Only works in loops.
        void Break()
        {
            if (m_useRemoteApi)
            {
                m_remoteOperation.BreakLoop();
            }
            else
            {
                throw UiaOperationAbstraction::LoopBreakException();
            }
        }

        // analogous to the C++ continue keyword. Only works in loops, of course.
        void Continue()
        {
            if (m_useRemoteApi)
            {
                m_remoteOperation.ContinueLoop();
            }
            else
            {
                throw UiaOperationAbstraction::LoopContinueException();
            }
        }

        void AbortOperationWithHresult(HRESULT hr);

        winrt::Microsoft::UI::UIAutomation::AutomationRemoteOperationResultSet Execute()
        {
            // At this point, the remote operation is complete, so we no longer want to create stand-ins,
            // e.g. when creating local wrappers while converting an array result.
            m_useRemoteApi = false;

            return m_remoteOperation.Execute();
        }

        template<class Type>
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteOperationResponseToken RequestResponse(const Type& value)
        {
            return m_remoteOperation.RequestResponse(value);
        }

        template<typename ComEnumT, typename WinRTEnumT, typename StandinT>
        void ConvertVariantDataToRemote(std::variant<ComEnumT, StandinT>& localEnumVariant) const
        {
            if (m_useRemoteApi && m_remoteOperation)
            {
                if (auto localEnum = std::get_if<ComEnumT>(&localEnumVariant))
                {
                    localEnumVariant = m_remoteOperation.NewEnum(static_cast<WinRTEnumT>(*localEnum));
                }
            }
        }

        void ConvertVariantDataToRemote(std::variant<
            BOOL,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteBool>& localBoolVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            int,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt>& localIntVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            unsigned int,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteUint>& localUintVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            double,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteDouble>& localDoubleVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            wchar_t,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteChar>& localCharVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            wil::shared_bstr,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>& localStringVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            winrt::Windows::Foundation::Point,
            winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint>& localPointVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            winrt::Windows::Foundation::Rect,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect>& localRectVariant) const;
        void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<
            UIA_HWND,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt>& localIntVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            std::shared_ptr<wil::unique_variant>,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject>& localVariantVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            winrt::com_ptr<IUIAutomationElement>,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteElement>& localElementVariant) const;
        void ConvertVariantDataToRemote(std::variant<
            winrt::com_ptr<IUIAutomationTextRange>,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextRange>& localTextRangeVariant) const;

        template <class ItemWrapperType>
        void ConvertVariantDataToRemote(std::variant<
            std::shared_ptr<std::vector<typename ItemWrapperType::LocalType>>,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray>& localArrayVariant) const
        {
            if (m_useRemoteApi && m_remoteOperation)
            {
                if (auto localArray = std::get_if<std::shared_ptr<std::vector<typename ItemWrapperType::LocalType>>>(&localArrayVariant))
                {
                    auto remoteArray = m_remoteOperation.NewArray();

                    for (const auto& item: **localArray)
                    {
                        ItemWrapperType wrapper{ item };
                        wrapper.ToRemote();
                        remoteArray.Append(wrapper);
                    }

                    localArrayVariant = std::move(remoteArray);
                }
            }
        }

        template <class ItemWrapperType>
        void ConvertVariantDataToRemote(std::variant<
            std::shared_ptr<std::map<std::wstring, typename ItemWrapperType::LocalType>>,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteStringMap>& localMapVariant) const;

        template <class... ItemWrapperType>
        void ConvertVariantDataToRemote(std::variant<
            std::shared_ptr<std::tuple<typename ItemWrapperType::LocalType...>>,
            winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray>& localTupleVariant) const
        {
            if (m_useRemoteApi && m_remoteOperation)
            {
                using TupleLocalType = std::tuple<typename ItemWrapperType::LocalType...>;
                if (auto localTuple = std::get_if<std::shared_ptr<TupleLocalType>>(&localTupleVariant))
                {
                    auto remoteArray = m_remoteOperation.NewArray();
                    impl::LocalTupleToRemoteArray<0, ItemWrapperType...>(**localTuple, remoteArray);
                    localTupleVariant = std::move(remoteArray);
                }
            }
        }

        // Creates an `AutomationRemoteArray` object out of the provided items (converting them to remote).
        //
        // In order to convert the provided items to remote, the function has to be called in a remote
        // context.
        template<class... ItemWrapperTypes>
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray ItemsToRemoteArray(ItemWrapperTypes&&... items)
        {
            auto remoteArray = m_remoteOperation.NewArray();
            impl::AppendItemsToRemoteArray(remoteArray, std::forward<ItemWrapperTypes>(items)...);
            return remoteArray;
        }

    private:
        bool m_useRemoteApi;
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteOperation m_remoteOperation;

        // This method is deleted because of the risk of passing an expression that should be a block.
        // See above for why that's a problem.
        template<class Body>
        void While(UiaBool&&, Body body) = delete;
    };

    namespace details
    {
        template<class T>
        struct ValueToVariantTypeConverter
        {
            template<class X>
            constexpr static decltype(auto) Convert(X&& val) noexcept
            {
                return std::forward<X>(val);
            }
        };

        // Explicitly specialize the converter for bool values being converted to a VARIANT type:
        // We must not use the default conversion of C++'s `bool` to assign to VARIANT's `boolVal`
        // because the numeric value of VARIANT_TRUE is -1, not 1 (which is what a `true` converts
        // to).
        template<>
        struct ValueToVariantTypeConverter<bool>
        {
            constexpr static VARIANT_BOOL Convert(bool val) noexcept { return val ? VARIANT_TRUE : VARIANT_FALSE; }
        };

        template <typename WrapperType, typename ValueType>
        std::shared_ptr<wil::unique_variant> MakeVariantFrom(ValueType value)
        {
            auto result = std::make_shared<wil::unique_variant>();
            result->vt = WrapperType::c_comVariantType;
            (*result).*(WrapperType::c_variantMember) = details::ValueToVariantTypeConverter<ValueType>::Convert(value);
            return result;
        }

        template<class T> struct always_false : std::false_type {};

        template<class T>
        constexpr VARTYPE GetVtForType()
        {
            if constexpr (std::is_same_v<T, bool>)
            {
                return VT_BOOL;
            }
            else if constexpr (std::is_same_v<T, int>)
            {
                return VT_I4;
            }
            else if constexpr (std::is_same_v<T, unsigned int>)
            {
                return VT_UI4;
            }
            else if constexpr (std::is_same_v<T, double>)
            {
                return VT_R8;
            }
            else if constexpr (std::is_same_v<T, wil::unique_variant>)
            {
                return VT_VARIANT;
            }
            else
            {
                static_assert(always_false<T>::value, "T doesn't have a supported vt");
            }
        }

        template<class T>
        unique_safearray VectorToSafeArray(std::vector<T>&& vectorIn)
        {
            // Actually take ownership of the input vector.
            std::vector<T> vector(std::move(vectorIn));

            constexpr auto vt = GetVtForType<T>();
            unique_safearray safearray{ ::SafeArrayCreateVector(
                    vt,
                    0,
                    static_cast<unsigned long>(vector.size()))};
            THROW_IF_NULL_ALLOC(safearray.get());
            for (long i = 0; i < static_cast<long>(vector.size()); ++i)
            {
                // We need to adapt the bool to the VARIANT_BOOL value, so special-case this type.
                if constexpr (std::is_same_v<T, bool>)
                {
                    VARIANT_BOOL val = vector[i] ? VARIANT_TRUE : VARIANT_FALSE;
                    THROW_IF_FAILED(::SafeArrayPutElement(safearray.get(), &i, &val));
                }
                else
                {
                    THROW_IF_FAILED(::SafeArrayPutElement(safearray.get(), &i, &vector[i]));
                }
            }

            return safearray;
        }

        template<class T>
        T AccessVariantValueAs(const wil::unique_variant& variant);

        template<>
        inline bool AccessVariantValueAs<bool>(const wil::unique_variant& variant)
        {
            return variant.boolVal == VARIANT_TRUE;
        }

        template<>
        inline int AccessVariantValueAs<int>(const wil::unique_variant& variant)
        {
            return variant.lVal;
        }

        template<>
        inline unsigned int AccessVariantValueAs<unsigned int>(const wil::unique_variant& variant)
        {
            return variant.ulVal;
        }

        template<>
        inline double AccessVariantValueAs<double>(const wil::unique_variant& variant)
        {
            return variant.dblVal;
        }

        template<class T>
        T UnwrapVariant(const wil::unique_variant& variant)
        {
            constexpr auto vt = GetVtForType<T>();
            THROW_HR_IF(E_UNEXPECTED, vt != variant.vt);
            return AccessVariantValueAs<T>(variant);
        }

        template<class T>
        std::vector<T> FlattenVariantArray(const std::vector<wil::unique_variant>& variantVector)
        {
            if (variantVector.empty())
            {
                return std::vector<T>{};
            }

            std::vector<T> result;
            result.reserve(variantVector.size());
            for (const auto& variant : variantVector)
            {
                result.emplace_back(UnwrapVariant<T>(variant));
            }

            return result;
        }

        // The helper allows "normalizing" the given object to a default-constructed instance of `T` if the
        // provided `shared_ptr` is empty.
        //
        // This is useful for creating abstraction types whose nested types -- when default-constructed --
        // may not have valid values.
        //
        // For instance, `UiaTuple<UiaArray<UiaInt>>` is a combination of:
        // 1. `UiaTuple<T>` = `std::shared_ptr<std::tuple<T>>`
        // 2. `UiaArray<T>` = `std::shared_ptr<std::vector<T>>`
        // 3. `UiaInt` = `int`
        //
        // If the constructor of `UiaTuple<T>` simply calls `std::make_shared<T>` to create the local value,
        // the inner value of `T` will be default-constructed.
        //
        // In the above case, `std::shared_ptr<std::vector<T>>`'s default construction is about creating an
        // empty `std::shared_ptr` which is an unexpected/uninitialized value from the perspective of the
        // abstraction library tools and therefore encountering it means exceptions.
        //
        // The helper allows default-constructed wrapper type objects to be correctly constructed even if
        // their corresponding local types require more work than calling their default constructors to be
        // correctly initialized (here, the local types are `std::shared_ptr`-based).
        template<class T>
        std::shared_ptr<T> GetOrMakeSharedPtr(const std::shared_ptr<T>& ptr)
        {
            return (ptr ? ptr : std::make_shared<T>());
        }
    } // details

    template<typename LocalT, class RemoteT>
    class UiaTypeBase
    {
    public:
        using LocalType = LocalT;
        using RemoteType = RemoteT;
        using VariantType = std::variant<LocalT, RemoteT>;

        UiaTypeBase(const LocalType& localValue): m_member(localValue) {}
        UiaTypeBase(LocalType&& localValue): m_member(std::move(localValue)) {}
        UiaTypeBase(const RemoteType& remoteValue): m_member(remoteValue) {}
        UiaTypeBase(const VariantType& other): m_member(other) {}

        UiaTypeBase(const UiaTypeBase&) = default;
        UiaTypeBase& operator=(const UiaTypeBase&) = delete;

        UiaTypeBase(UiaTypeBase&&) = default;
        UiaTypeBase& operator=(UiaTypeBase&&) = default;

        ~UiaTypeBase() = default;

        constexpr bool IsRemoteType() const
        {
            return std::holds_alternative<RemoteType>(m_member);
        }

        operator winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject() const
        {
            return std::get<RemoteType>(m_member);
        }

        operator RemoteType&()
        {
            return std::get<RemoteType>(m_member);
        }

        // Conversion operator used when the wrapper type is passed as an out param for a local UIA call.
        operator LocalType*()
        {
            return &std::get<LocalType>(m_member);
        }

        // Note: This has no effect if it's not running inside a remote scope. So it's safe to call
        // unconditionally.
        void ToRemote()
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            if (delegator)
            {
                delegator->ConvertVariantDataToRemote(m_member);
            }
        }

    protected:
        VariantType m_member;
    };

    class UiaString;

    class UiaBool : public UiaTypeBase<BOOL, winrt::Microsoft::UI::UIAutomation::AutomationRemoteBool>
    {
    public:
        static constexpr VARTYPE c_comVariantType = VT_BOOL;
        static constexpr auto c_variantMember = &VARIANT::boolVal;
        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsBool;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsBool;

        UiaBool(bool value);
        UiaBool(BOOL value);
        UiaBool(winrt::Microsoft::UI::UIAutomation::AutomationRemoteBool remoteValue);
        explicit UiaBool(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaBool(const UiaBool&) = default;

        operator BOOL() const;
        operator bool() const;

        UiaBool& operator=(const UiaBool& other);

        UiaBool operator!() const;

        UiaBool operator==(const UiaBool& rhs) const;
        UiaBool operator!=(const UiaBool& rhs) const;

        UiaBool operator==(bool rhs) const
        {
            return *this == UiaBool(rhs);
        }
        UiaBool operator!=(bool rhs) const
        {
            return *this != UiaBool(rhs);
        }

        UiaBool operator&&(const UiaBool& rhs) const;
        UiaBool operator||(const UiaBool& rhs) const;

        UiaBool operator&&(bool rhs) const
        {
            return *this && UiaBool(rhs);
        }
        UiaBool operator||(bool rhs) const
        {
            return *this || UiaBool(rhs);
        }

        UiaString Stringify();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    class UiaInt : public UiaTypeBase<int, winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt>
    {
    public:
        static constexpr VARTYPE c_comVariantType = VT_I4;
        static constexpr auto c_variantMember = &VARIANT::lVal;
        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsInt;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsInt;

        UiaInt(int value);
        UiaInt(winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt remoteValue);
        explicit UiaInt(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaInt(const UiaInt&) = default;

        operator int() const;

        UiaInt& operator=(const UiaInt& other);

        UiaBool operator==(const UiaInt& rhs) const;
        UiaBool operator!=(const UiaInt& rhs) const;
        UiaBool operator<(const UiaInt& rhs) const;
        UiaBool operator<=(const UiaInt& rhs) const;
        UiaBool operator>(const UiaInt& rhs) const;
        UiaBool operator>=(const UiaInt& rhs) const;

        UiaBool operator==(int rhs) const
        {
            return *this == UiaInt(rhs);
        }
        UiaBool operator!=(int rhs) const
        {
            return *this != UiaInt(rhs);
        }
        UiaBool operator<(int rhs) const
        {
            return *this < UiaInt(rhs);
        }
        UiaBool operator<=(int rhs) const
        {
            return *this <= UiaInt(rhs);
        }
        UiaBool operator>(int rhs) const
        {
            return *this > UiaInt(rhs);
        }
        UiaBool operator>=(int rhs) const
        {
            return *this >= UiaInt(rhs);
        }

        void operator+=(UiaInt rhs);
        void operator-=(UiaInt rhs);
        void operator*=(UiaInt rhs);
        void operator/=(UiaInt rhs);

        UiaString Stringify();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    class UiaUint : public UiaTypeBase<unsigned int, winrt::Microsoft::UI::UIAutomation::AutomationRemoteUint>
    {
    public:
        static constexpr VARTYPE c_comVariantType = VT_UI4;
        static constexpr auto c_variantMember = &VARIANT::ulVal;
        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsUint;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsUint;

        UiaUint(unsigned int value);
        UiaUint(DWORD value);
        UiaUint(int value);
        UiaUint(winrt::Microsoft::UI::UIAutomation::AutomationRemoteUint remoteValue);
        explicit UiaUint(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaUint(const UiaUint&) = default;

        operator unsigned int() const;

        UiaUint& operator=(const UiaUint& other);

        UiaBool operator==(const UiaUint& rhs) const;
        UiaBool operator!=(const UiaUint& rhs) const;
        UiaBool operator<(const UiaUint& rhs) const;
        UiaBool operator<=(const UiaUint& rhs) const;
        UiaBool operator>(const UiaUint& rhs) const;
        UiaBool operator>=(const UiaUint& rhs) const;

        UiaBool operator==(unsigned int rhs) const
        {
            return *this == UiaUint(rhs);
        }
        UiaBool operator!=(unsigned int rhs) const
        {
            return *this != UiaUint(rhs);
        }
        UiaBool operator<(unsigned int rhs) const
        {
            return *this < UiaUint(rhs);
        }
        UiaBool operator<=(unsigned int rhs) const
        {
            return *this <= UiaUint(rhs);
        }
        UiaBool operator>(unsigned int rhs) const
        {
            return *this > UiaUint(rhs);
        }
        UiaBool operator>=(unsigned int rhs) const
        {
            return *this >= UiaUint(rhs);
        }

        UiaBool operator==(int rhs) const
        {
            return *this == UiaUint(rhs);
        }
        UiaBool operator!=(int rhs) const
        {
            return *this != UiaUint(rhs);
        }
        UiaBool operator<(int rhs) const
        {
            return *this < UiaUint(rhs);
        }
        UiaBool operator<=(int rhs) const
        {
            return *this <= UiaUint(rhs);
        }
        UiaBool operator>(int rhs) const
        {
            return *this > UiaUint(rhs);
        }
        UiaBool operator>=(int rhs) const
        {
            return *this >= UiaUint(rhs);
        }

        void operator+=(UiaUint rhs);
        void operator-=(UiaUint rhs);
        void operator*=(UiaUint rhs);
        void operator/=(UiaUint rhs);

        UiaString Stringify();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    class UiaDouble : public UiaTypeBase<double, winrt::Microsoft::UI::UIAutomation::AutomationRemoteDouble>
    {
    public:
        static constexpr VARTYPE c_comVariantType = VT_R8;
        static constexpr auto c_variantMember = &VARIANT::dblVal;
        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsDouble;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsDouble;

        UiaDouble(double value);
        UiaDouble(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDouble remoteValue);
        explicit UiaDouble(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaDouble(const UiaDouble&) = default;

        operator double() const;

        UiaDouble& operator=(const UiaDouble& other);

        UiaBool operator==(const UiaDouble& rhs) const;
        UiaBool operator!=(const UiaDouble& rhs) const;
        UiaBool operator<(const UiaDouble& rhs) const;
        UiaBool operator<=(const UiaDouble& rhs) const;
        UiaBool operator>(const UiaDouble& rhs) const;
        UiaBool operator>=(const UiaDouble& rhs) const;

        UiaBool operator==(double rhs) const
        {
            return *this == UiaDouble(rhs);
        }
        UiaBool operator!=(double rhs) const
        {
            return *this != UiaDouble(rhs);
        }
        UiaBool operator<(double rhs) const
        {
            return *this < UiaDouble(rhs);
        }
        UiaBool operator<=(double rhs) const
        {
            return *this <= UiaDouble(rhs);
        }
        UiaBool operator>(double rhs) const
        {
            return *this > UiaDouble(rhs);
        }
        UiaBool operator>=(double rhs) const
        {
            return *this >= UiaDouble(rhs);
        }

        void operator+=(UiaDouble rhs);
        void operator-=(UiaDouble rhs);
        void operator*=(UiaDouble rhs);
        void operator/=(UiaDouble rhs);

        UiaString Stringify();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    class UiaChar : public UiaTypeBase<wchar_t, winrt::Microsoft::UI::UIAutomation::AutomationRemoteChar>
    {
    public:
        static constexpr VARTYPE c_comVariantType = VT_UI2;
        static constexpr auto c_variantMember = &VARIANT::uiVal;
        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsChar;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsChar;

        UiaChar(wchar_t value);
        UiaChar(winrt::Microsoft::UI::UIAutomation::AutomationRemoteChar remoteValue);
        explicit UiaChar(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaChar(const UiaChar&) = default;

        operator wchar_t() const;

        UiaChar& operator=(const UiaChar& other);

        UiaBool operator==(const UiaChar& rhs) const;
        UiaBool operator!=(const UiaChar& rhs) const;

        UiaString Stringify();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    class UiaString : public UiaTypeBase<wil::shared_bstr, winrt::Microsoft::UI::UIAutomation::AutomationRemoteString>
    {
    public:
        static constexpr VARTYPE c_comVariantType = VT_BSTR;
        static constexpr auto c_variantMember = &VARIANT::bstrVal;
        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsString;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsString;

        UiaString(std::wstring value);
        UiaString(const wchar_t* value);
        UiaString(wil::unique_bstr&& value);
        UiaString(const wil::shared_bstr& value);
        UiaString(winrt::Microsoft::UI::UIAutomation::AutomationRemoteString remoteValue);
        explicit UiaString(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaString(const UiaString&) = default;

        operator wil::shared_bstr() const;

        BSTR get() const;

        std::wstring GetLocalWstring() const;

        operator bool() const { return !!get(); }
        UiaBool operator!() const { return IsNull(); }
        operator UiaBool() const { return !IsNull(); }

        UiaBool IsNull() const;

        UiaString& operator=(const UiaString& other);

        UiaBool operator==(const UiaString& rhs) const;
        UiaBool operator!=(const UiaString& rhs) const;

        UiaUint Length() const;
        UiaChar At(UiaUint index);

        UiaString Stringify();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    template <typename ComEnumT, typename WinRTEnumT, typename StandinT, CastFuncType<StandinT> CastFunc>
    class UiaEnum : public UiaTypeBase<ComEnumT, StandinT>
    {
    public:
        static constexpr VARTYPE c_comVariantType = VT_I4;
        static constexpr auto c_variantMember = &VARIANT::lVal;
        static constexpr auto c_anyCast = CastFunc;

        UiaEnum(ComEnumT value) : UiaTypeBase(value)
        {
            ToRemote();
        }

        UiaEnum(WinRTEnumT value) : UiaTypeBase(static_cast<ComEnumT>(value))
        {
            ToRemote();
        }

        UiaEnum(StandinT remoteValue) : UiaTypeBase(remoteValue)
        {
        }

        UiaEnum(const UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc>&) = default;

        explicit UiaEnum(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue) :
           UiaTypeBase((remoteValue.*CastFunc)())
        {
        }

        operator ComEnumT() const
        {
            return std::get<ComEnumT>(m_member);
        }

        operator StandinT() const
        {
            return std::get<StandinT>(m_member);
        }

        operator WinRTEnumT() const
        {
            return static_cast<WinRTEnumT>(std::get<ComEnumT>(m_member));
        }

        UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc>& operator=(const UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc>& other)
        {
            if (ShouldUseRemoteApi())
            {
                this->ToRemote();
                auto mutableOther = other;
                mutableOther.ToRemote();
                std::get<StandinT>(m_member).Set(std::get<StandinT>(mutableOther.m_member));
            }
            else
            {
                m_member = std::get<ComEnumT>(other.m_member);
            }

            return *this;
        }

        UiaBool operator==(const UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc>& rhs) const
        {
            if (ShouldUseRemoteApi())
            {
                auto mutableThis = *this;
                mutableThis.ToRemote();
                auto mutableRhs = rhs;
                mutableRhs.ToRemote();
                return std::get<StandinT>(mutableThis.m_member).IsEqual(std::get<StandinT>(mutableRhs.m_member));
            }

            return std::get<ComEnumT>(m_member) == std::get<ComEnumT>(rhs.m_member);
        }

        UiaBool operator!=(const UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc>& rhs) const
        {
            if (ShouldUseRemoteApi())
            {
                auto mutableThis = *this;
                mutableThis.ToRemote();
                auto mutableRhs = rhs;
                mutableRhs.ToRemote();
                return std::get<StandinT>(mutableThis.m_member).IsNotEqual(std::get<StandinT>(mutableRhs.m_member));
            }

            return std::get<ComEnumT>(m_member) != std::get<ComEnumT>(rhs.m_member);
        }

        template<class T>
        UiaBool operator==(T rhs) const
        {
            return (*this == UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc>(rhs));
        }

        template<class T>
        UiaBool operator!=(T rhs) const
        {
            return (*this != UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc>(rhs));
        }

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            int intValueOfEnum = winrt::unbox_value<int>(result);
            m_member = static_cast<ComEnumT>(intValueOfEnum);
        }

        void ToRemote()
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            if (delegator)
            {
                delegator->ConvertVariantDataToRemote<ComEnumT, WinRTEnumT, StandinT>(m_member);
            }
        }
    };

#include "UiaTypeAbstractionEnums.g.h"

    class UiaPoint : public UiaTypeBase<
        winrt::Windows::Foundation::Point,
        winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint>
    {
    public:
        UiaPoint();
        UiaPoint(POINT point);
        UiaPoint(winrt::Windows::Foundation::Point point);
        UiaPoint(winrt::Microsoft::UI::UIAutomation::AutomationRemotePoint remotePoint);
        explicit UiaPoint(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaPoint(const UiaPoint&) = default;

        operator winrt::Windows::Foundation::Point() const;
        operator POINT() const;

        UiaPoint& operator=(const UiaPoint& other);

        UiaBool operator==(const UiaPoint& rhs) const;
        UiaBool operator!=(const UiaPoint& rhs) const;

        UiaString Stringify();
        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    class UiaRect : public UiaTypeBase<
        winrt::Windows::Foundation::Rect,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect>
    {
    public:
        UiaRect();
        UiaRect(RECT rect);
        UiaRect(winrt::Windows::Foundation::Rect rect);
        UiaRect(winrt::Microsoft::UI::UIAutomation::AutomationRemoteRect remoteRect);
        explicit UiaRect(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaRect(const UiaRect&) = default;

        operator winrt::Windows::Foundation::Rect() const;
        operator RECT() const;

        UiaRect& operator=(const UiaRect& other);

        UiaBool operator==(const UiaRect& rhs) const;
        UiaBool operator!=(const UiaRect& rhs) const;

        UiaDouble GetHeight() const;
        UiaDouble GetWidth() const;
        UiaDouble GetX() const;
        UiaDouble GetY() const;

        UiaString Stringify();
        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    class UiaHwnd : public UiaTypeBase<
        UIA_HWND,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt>
    {
    public:
        UiaHwnd(UIA_HWND hwnd);
        UiaHwnd(winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt remoteHwnd);
        explicit UiaHwnd(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue);
        UiaHwnd(const UiaHwnd&) = default;

        operator UIA_HWND() const;

        UiaBool operator==(const UiaHwnd& rhs) const;
        UiaBool operator!=(const UiaHwnd& rhs) const;
        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    namespace impl
    {
        // Note: The following generic implementation is only applicable for primitive types,
        // because the vectors returned by this version of SafeArrayToVector have raw pointers
        // for non-primitive types (e.g. BSTR, IUnknown*).
        template <class ItemWrapperType>
        std::vector<typename ItemWrapperType::LocalType> ConvertSafeArray(unique_safearray&& array)
        {
            return SafeArrayToVector<ItemWrapperType::c_comVariantType>(array.get());
        }

        template <>
        std::vector<UiaString::LocalType> ConvertSafeArray<UiaString>(unique_safearray&& array);

        template <>
        std::vector<winrt::Windows::Foundation::Rect> ConvertSafeArray<UiaRect>(unique_safearray&& array);

        template <class ItemWrapperType, class ArrayInterfaceType>
        std::vector<typename ItemWrapperType::LocalType> ConvertUiaObjectArray(_In_ ArrayInterfaceType* array)
        {
            int length{};
            winrt::check_hresult(array->get_Length(&length));

            std::vector<typename ItemWrapperType::LocalType> result;
            result.reserve(static_cast<size_t>(length));

            for (int i = 0; i < length; ++i)
            {
                typename ItemWrapperType::LocalType item;
                winrt::check_hresult(array->GetElement(i, item.put()));
                result.emplace_back(std::move(item));
            }

            return result;
        }

        // Each of these helpers is an overload which populates the cache(s)
        // for its first argument. The one which takes a single element will
        // populate the cache just for that element, while the one which takes
        // an array will assume all items in the array are UIA elements and
        // will populate the cache for each.
        void PopulateCacheHelper(
            const winrt::Microsoft::UI::UIAutomation::AutomationRemoteElement& element,
            const winrt::Microsoft::UI::UIAutomation::AutomationRemoteCacheRequest& cacheRequest);
        void PopulateCacheHelper(
            const winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray& elements,
            const winrt::Microsoft::UI::UIAutomation::AutomationRemoteCacheRequest& cacheRequest);

        template<class T>
        constexpr bool IsArrayElementEqual(T lhs, T rhs)
        {
            if constexpr (std::is_same_v<T, bool> ||
                std::is_same_v<T, int> ||
                std::is_same_v<T, unsigned int> ||
                std::is_same_v<T, double>)
            {
                return lhs == rhs;
            }
            else if constexpr (std::is_same_v<T, wil::shared_bstr>)
            {
                return (UiaString(lhs) == UiaString(rhs));
            }
            else if constexpr (std::is_same_v<T, winrt::Windows::Foundation::Rect>)
            {
                return (UiaRect(lhs) == UiaRect(rhs));
            }
            else if constexpr (std::is_same_v<T, winrt::Windows::Foundation::Point>)
            {
                return (UiaPoint(lhs) == UiaPoint(rhs));
            }
            else
            {
                static_assert(always_false<T>::value, "Unexpected array element comparison type.");
            }
        }

        template <std::size_t I, typename... ItemWrapperType>
        inline void LocalTupleToRemoteArray(
            [[maybe_unused]] const std::tuple<typename ItemWrapperType::LocalType...>& localTuple,
            [[maybe_unused]] winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray& remoteArray)
        {
            if constexpr (I < sizeof...(ItemWrapperType))
            {
                using TupleItemWrapperType = typename UiaTuple<ItemWrapperType...>::TupleItemWrapperType<I>;

                TupleItemWrapperType wrapper{ std::get<I>(localTuple) };
                wrapper.ToRemote();
                remoteArray.Append(wrapper);

                LocalTupleToRemoteArray<I + 1, ItemWrapperType...>(localTuple, remoteArray);
            }
        }

        template <std::size_t I, typename... ItemWrapperType>
        inline void RemoteArrayToLocalTuple(
            [[maybe_unused]] const winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable>& remoteArray,
            [[maybe_unused]] std::tuple<typename ItemWrapperType::LocalType...>& localTuple)
        {
            if constexpr (I < sizeof...(ItemWrapperType))
            {
                using TupleItemWrapperType = typename UiaTuple<ItemWrapperType...>::TupleItemWrapperType<I>;
                using ItemLocalType = typename TupleItemWrapperType::LocalType;

                TupleItemWrapperType wrappedLocal = ItemLocalType();
                wrappedLocal.FromRemoteResult(remoteArray.GetAt(I));
                std::get<I>(localTuple) = static_cast<ItemLocalType>(wrappedLocal);

                RemoteArrayToLocalTuple<I + 1, ItemWrapperType...>(remoteArray, localTuple);
            }
        }

        // The functions allow callers to convert and append multiple remote values to a given remote array.
        //
        // The functions expect `UiaTypeBase`-based wrappers to:
        // 1. Convert them to remote values (stand-ins),
        // 2. Obtain the remote values from the wrappers and append them to the array.
        //
        // Due to the requirement of having and using stand-ins, the functions should only be called in remote
        // contexts.
        template<class... ItemWrapperTypes>
        void AppendItemsToRemoteArray(winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray& array, ItemWrapperTypes&&... items)
        {
            (AppendItemToRemoteArray(array, std::forward<ItemWrapperTypes>(items)), ...);
        }

        template<class ItemWrapperType>
        void AppendItemToRemoteArray(winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray& array, ItemWrapperType&& item)
        {
            // If the conversion cannot be made due to not executing this in a remote context, the function will
            // fail on attempting to append to the array due to trying to get a remote value representation when
            // the underlying value is local.
            item.ToRemote();
            array.Append(item);
        }
    } // namespace impl

    template <class ItemWrapperType>
    class UiaArray : public UiaTypeBase<
        std::shared_ptr<std::vector<typename ItemWrapperType::LocalType>>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray>
    {
    public:
        using ItemLocalType = typename ItemWrapperType::LocalType;

        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsArray;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsArray;

        UiaArray():
            UiaArray(std::vector<ItemLocalType>())
        {
        }

        UiaArray(std::vector<ItemLocalType> vector):
            UiaTypeBase(std::make_shared<std::vector<ItemLocalType>>(std::move(vector)))
        {
            ToRemote();
        }

        UiaArray(const std::shared_ptr<std::vector<ItemLocalType>>& value) : UiaTypeBase(details::GetOrMakeSharedPtr(value))
        {
            ToRemote();
        }

        UiaArray(winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray array):
            UiaTypeBase(array)
        {
        }

        explicit UiaArray(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
            UiaTypeBase(remoteValue.AsArray())
        {
        }

        UiaArray(const UiaArray&) = default;

        UiaArray(unique_safearray&& array):
            UiaArray(impl::ConvertSafeArray<ItemWrapperType>(std::move(array)))
        {
        }

        template <class ArrayInterfaceType>
        UiaArray(const winrt::com_ptr<ArrayInterfaceType>& array):
            UiaArray(impl::ConvertUiaObjectArray<ItemWrapperType>(array.get()))
        {
        }

        UiaBool IsNull() const
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<RemoteType>(&m_member);
                if (remoteValue)
                {
                    return remoteValue->IsNull();
                }
            }

            // The local version of a UiaArray can never be null.
            return false;
        }

        UiaBool operator!() const { return IsNull(); }
        operator UiaBool() const { return !IsNull(); }

        operator std::shared_ptr<std::vector<ItemLocalType>>() const
        {
            return std::get<std::shared_ptr<std::vector<ItemLocalType>>>(m_member);
        }

        std::vector<ItemLocalType>& operator*()
        {
            return *std::get<LocalType>(m_member);
        }

        const std::vector<ItemLocalType>& operator*() const
        {
            return *std::get<LocalType>(m_member);
        }

        UiaBool operator==(const UiaArray& rhs) const
        {
            if (ShouldUseRemoteApi())
            {
                auto mutableThis = *this;
                mutableThis.ToRemote();

                auto mutableRhs = rhs;
                mutableRhs.ToRemote();
                return std::get<RemoteType>(mutableThis.m_member).IsEqual(std::get<RemoteType>(mutableRhs.m_member));
            }

            auto localVector = std::get<LocalType>(m_member);
            auto localRhsVector = std::get<LocalType>(rhs.m_member);

            if (localVector->size() != localRhsVector->size())
            {
                return false;
            }

            for (size_t i = 0; i < localVector->size(); ++i)
            {
                if (!impl::IsArrayElementEqual((*localVector)[i], (*localRhsVector)[i]))
                {
                    return false;
                }
            }

            return true;
        }

        UiaBool operator!=(const UiaArray& rhs) const
        {
            return !(*this == rhs);
        }

        void ToRemote()
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            if (delegator)
            {
                delegator->ConvertVariantDataToRemote<ItemWrapperType>(m_member);
            }
        }

        void Append(ItemWrapperType item)
        {
            if (ShouldUseRemoteApi())
            {
                ToRemote();
                item.ToRemote();
                std::get<RemoteType>(m_member).Append(item);
                return;
            }

            std::get<LocalType>(m_member)->emplace_back(item);
        }

        void SetAt(UiaUint index, ItemWrapperType item)
        {
            if (ShouldUseRemoteApi())
            {
                ToRemote();
                index.ToRemote();
                item.ToRemote();
                std::get<RemoteType>(m_member).SetAt(index, item);
                return;
            }

            std::get<LocalType>(m_member)->at(static_cast<size_t>(index)) = item;
        }

        ItemWrapperType RemoveAt(UiaUint index)
        {
            if (ShouldUseRemoteApi())
            {
                ToRemote();
                index.ToRemote();
                return ItemWrapperType{ std::get<RemoteType>(m_member).RemoveAt(index) };
            }

            auto localVector = std::get<LocalType>(m_member);
            const auto localIndex = static_cast<size_t>(index);

            if (localIndex >= localVector->size())
            {
                throw winrt::hresult_error(E_BOUNDS);
            }

            auto iteratorToDelete = localVector->begin() + localIndex;
            ItemLocalType result = std::move(*iteratorToDelete);

            localVector->erase(iteratorToDelete);

            return result;
        }

        ItemWrapperType GetAt(UiaUint index)
        {
            if (ShouldUseRemoteApi())
            {
                ToRemote();
                index.ToRemote();
                return ItemWrapperType{ std::get<RemoteType>(m_member).GetAt(index) };
            }

            return std::get<LocalType>(m_member)->at(static_cast<size_t>(index));
        }

        UiaUint Size() const
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<RemoteType>(&m_member);
                if (remoteValue)
                {
                    return remoteValue->Size();
                }
            }

            return static_cast<unsigned int>(std::get<LocalType>(m_member)->size());
        }

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            auto operationResults = result.as<winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable>>();
            m_member = std::make_shared<std::vector<ItemLocalType>>();
            auto& localValue = std::get<LocalType>(m_member);
            const uint32_t vectorSize = operationResults.Size();
            for (uint32_t index = 0; index < vectorSize; ++index)
            {
                ItemWrapperType wrappedLocal = ItemLocalType();
                wrappedLocal.FromRemoteResult(operationResults.GetAt(index));
                localValue->emplace_back(static_cast<ItemLocalType>(wrappedLocal));
            }
        }

        UiaString Stringify()
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<RemoteType>(&m_member);
                if (remoteValue)
                {
                    return remoteValue->Stringify();
                }
            }

            auto localVec = std::get<LocalType>(m_member);
            std::wostringstream ss;
            ss << "[";

            const auto size = localVec->size();
            for (size_t i = 0; i < size; ++i)
            {
                if (i != 0)
                {
                    ss << L",";
                }

                ItemWrapperType element = localVec->at(i);
                ss << element.Stringify().GetLocalWstring();
            }

            ss << "]";

            return ss.str();
        }
    };

    template <class ItemWrapperType>
    class UiaStringMap : public UiaTypeBase<
        std::shared_ptr<std::map<std::wstring, typename ItemWrapperType::LocalType>>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteStringMap>
    {
    public:
        using ItemLocalType = typename ItemWrapperType::LocalType;

        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsStringMap;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsStringMap;

        UiaStringMap():
            UiaStringMap(std::map<std::wstring, ItemLocalType>())
        {
        }

        UiaStringMap(std::map<std::wstring, ItemLocalType> map):
            UiaTypeBase(std::make_shared<std::map<std::wstring, ItemLocalType>>(std::move(map)))
        {
            ToRemote();
        }

        UiaStringMap(const std::shared_ptr<std::map<std::wstring, ItemLocalType>>& value) : UiaTypeBase(details::GetOrMakeSharedPtr(value))
        {
            ToRemote();
        }

        UiaStringMap(winrt::Microsoft::UI::UIAutomation::AutomationRemoteStringMap map):
            UiaTypeBase(map)
        {
        }

        explicit UiaStringMap(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue):
            UiaTypeBase(remoteValue.AsStringMap())
        {
        }

        UiaStringMap(const UiaStringMap&) = default;

        UiaBool IsNull() const
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<RemoteType>(&m_member);
                if (remoteValue)
                {
                    return remoteValue->IsNull();
                }
            }

            // The local version of a UiaStringMap can never be null.
            return false;
        }

        UiaBool operator!() const { return IsNull(); }
        operator UiaBool() const { return !IsNull(); }

        operator std::shared_ptr<std::map<std::wstring, ItemLocalType>>() const
        {
            return std::get<std::shared_ptr<std::map<std::wstring, ItemLocalType>>>(m_member);
        }

        std::map<std::wstring, ItemLocalType>& operator*()
        {
            return *std::get<LocalType>(m_member);
        }

        const std::map<std::wstring, ItemLocalType>& operator*() const
        {
            return *std::get<LocalType>(m_member);
        }

        void ToRemote()
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            if (delegator)
            {
                delegator->ConvertVariantDataToRemote<ItemWrapperType>(m_member);
            }
        }

        void Insert(UiaString key, ItemWrapperType val)
        {
            if (ShouldUseRemoteApi())
            {
                ToRemote();
                key.ToRemote();
                val.ToRemote();
                std::get<RemoteType>(m_member).Insert(key, val);
                return;
            }

            auto localKey = key.GetLocalWstring();
            std::get<LocalType>(m_member)->insert_or_assign(std::move(localKey), static_cast<ItemLocalType>(val));
        }

        void Remove(UiaString key)
        {
            if (ShouldUseRemoteApi())
            {
                ToRemote();
                key.ToRemote();
                std::get<RemoteType>(m_member).Remove(key);
                return;
            }

            auto localKey = key.GetLocalWstring();
            std::get<LocalType>(m_member)->erase(localKey);
        }

        UiaBool HasKey(UiaString key)
        {
            if (ShouldUseRemoteApi())
            {
                ToRemote();
                key.ToRemote();
                return std::get<RemoteType>(m_member).HasKey(key);
            }

            auto localKey = key.GetLocalWstring();
            return std::get<LocalType>(m_member)->find(localKey) != std::get<LocalType>(m_member)->end();
        }

        ItemWrapperType Lookup(UiaString key)
        {
            if (ShouldUseRemoteApi())
            {
                ToRemote();
                key.ToRemote();

                auto remoteAny = std::get<RemoteType>(m_member).Lookup(key);
                return std::invoke(ItemWrapperType::c_anyCast, &remoteAny);
            }

            auto localKey = key.GetLocalWstring();
            ItemLocalType result = std::get<LocalType>(m_member)->at(localKey);

            return result;
        }

        UiaUint Size() const
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<RemoteType>(&m_member);
                if (remoteValue)
                {
                    return remoteValue->Size();
                }
            }

            return static_cast<unsigned int>(std::get<LocalType>(m_member)->size());
        }

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            auto operationResults = result.as<winrt::Windows::Foundation::Collections::IMap<winrt::hstring, winrt::Windows::Foundation::IInspectable>>();
            m_member = std::make_shared<std::map<std::wstring, ItemLocalType>>();
            auto& localValue = std::get<LocalType>(m_member);
            for (const auto& element : operationResults)
            {
                ItemWrapperType wrappedLocal = ItemLocalType();
                wrappedLocal.FromRemoteResult(element.Value());
                localValue->emplace(element.Key().c_str(), std::move(wrappedLocal));
            }
        }
    };

    class UiaVariant : public UiaTypeBase<
        std::shared_ptr<wil::unique_variant>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject>
    {
    public:
        static constexpr auto c_anyCast = [](winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject* any)
        {
            return static_cast<winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject>(*any);
        };

        UiaVariant();
        UiaVariant(const VARIANT& variant);
        UiaVariant(wil::unique_variant&& variant);
        UiaVariant(const std::shared_ptr<wil::unique_variant>& variant) : UiaTypeBase(details::GetOrMakeSharedPtr(variant))
        {
            ToRemote();
        }

        UiaVariant(winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject remote);

        UiaVariant(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remote);

        UiaVariant(winrt::Microsoft::UI::UIAutomation::AutomationRemoteBool remote);
        UiaVariant(winrt::Microsoft::UI::UIAutomation::AutomationRemoteInt remote);
        UiaVariant(winrt::Microsoft::UI::UIAutomation::AutomationRemoteUint remote);
        UiaVariant(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDouble remote);
        UiaVariant(winrt::Microsoft::UI::UIAutomation::AutomationRemoteString remote);

        explicit UiaVariant(bool value);
        explicit UiaVariant(int value);
        explicit UiaVariant(unsigned int value);
        explicit UiaVariant(double value);
        explicit UiaVariant(BSTR value);

        explicit UiaVariant(UiaBool value);
        explicit UiaVariant(UiaInt value);
        explicit UiaVariant(UiaUint value);
        explicit UiaVariant(UiaDouble value);
        explicit UiaVariant(UiaString value);

        template <typename ComEnumT, typename WinRTEnumT, typename StandinT, CastFuncType<StandinT> CastFunc>
        explicit UiaVariant(UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc> value) :
            UiaTypeBase(
                value.IsRemoteType() ?
                UiaVariant(static_cast<winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject>(static_cast<typename UiaEnum<ComEnumT, WinRTEnumT, StandinT, CastFunc>::RemoteType>(value))) :
                UiaVariant(details::MakeVariantFrom<UiaInt>(static_cast<int>(static_cast<WinRTEnumT>(value)))))
        {
        }

        UiaBool IsNull() const;

        UiaBool operator!() const { return IsNull(); }
        operator UiaBool() const { return !IsNull(); }

        UiaVariant(const UiaVariant&) = default;

        UiaBool operator==(const UiaVariant& rhs);
        UiaBool operator!=(const UiaVariant& rhs);

        operator std::shared_ptr<wil::unique_variant>() const;

        VARIANT get() const;

        UiaBool IsNotSupported() const;

        UiaBool IsMixedAttribute() const;

        template<typename WrapperType>
        UiaBool IsType() const
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<typename RemoteType>(&m_member);
                if (remoteValue)
                {
                    auto remoteAny = remoteValue->try_as<winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject>();
                    if (remoteAny)
                    {
                        return (remoteAny.*(WrapperType::c_anyTest))();
                    }
                    auto remoteDerived = remoteValue->try_as<typename WrapperType::RemoteType>();
                    return !!remoteDerived;
                }
            }
            auto localValue = std::get<typename LocalType>(m_member);
            return V_VT(localValue) == WrapperType::c_comVariantType;
        }

        template <typename ReturnType>
        ReturnType AsType() const
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<typename RemoteType>(&m_member);
                if (remoteValue)
                {
                    auto remoteAny = remoteValue->try_as<winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject>();
                    if (remoteAny)
                    {
                        return (remoteAny.*(ReturnType::c_anyCast))();
                    }
                    auto remoteDerived = remoteValue->try_as<typename ReturnType::RemoteType>();
                    if (remoteDerived)
                    {
                        return remoteDerived;
                    }
                    THROW_HR(E_INVALIDARG);
                }
            }
            auto localValue = std::get<typename LocalType>(m_member);
            THROW_HR_IF(E_INVALIDARG, V_VT(localValue) != ReturnType::c_comVariantType);
            return static_cast<typename ReturnType::LocalType>((*localValue).*(ReturnType::c_variantMember));
        }

        UiaBool IsBool() const;
        UiaBool AsBool() const;

        UiaBool IsInt() const;
        UiaInt AsInt() const;

        UiaBool IsUint() const;
        UiaUint AsUint() const;

        UiaBool IsDouble() const;
        UiaDouble AsDouble() const;

        UiaBool IsString() const;
        UiaString AsString() const;

        operator winrt::Microsoft::UI::UIAutomation::AutomationRemoteObject() const;

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result);
    };

    template <class ItemWrapperType>
    void UiaOperationDelegator::ConvertVariantDataToRemote(std::variant<
        std::shared_ptr<std::map<std::wstring, typename ItemWrapperType::LocalType>>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteStringMap>& localMapVariant) const
    {
        if (m_useRemoteApi && m_remoteOperation)
        {
            if (auto localMap = std::get_if<std::shared_ptr<std::map<std::wstring, typename ItemWrapperType::LocalType>>>(&localMapVariant))
            {
                auto remoteMap = m_remoteOperation.NewStringMap();

                for (auto& item: **localMap)
                {
                    ItemWrapperType value{ std::move(item.second) };
                    value.ToRemote();
                    UiaString key(item.first.c_str());
                    key.ToRemote();
                    remoteMap.Insert(key, value);
                }

                localMapVariant = std::move(remoteMap);
            }
        }
    }

    template <class... ItemWrapperType>
    class UiaTuple : public UiaTypeBase<
        std::shared_ptr<std::tuple<typename ItemWrapperType::LocalType...>>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray>
    {
    public:
        using TupleLocalType = std::tuple<typename ItemWrapperType::LocalType...>;

        template<std::size_t I>
        using TupleItemWrapperType = typename std::tuple_element<I, std::tuple<ItemWrapperType...>>::type;

        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsArray;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsArray;

        UiaTuple() : UiaTuple(TupleLocalType{})
        {
        }

        UiaTuple(TupleLocalType tuple) :
            UiaTypeBase(std::make_shared<TupleLocalType>(std::move(tuple)))
        {
            ToRemote();
        }

        UiaTuple(const std::shared_ptr<TupleLocalType>& value) : UiaTypeBase(details::GetOrMakeSharedPtr(value))
        {
            ToRemote();
        }

        UiaTuple(typename ItemWrapperType::LocalType... args) : UiaTuple(TupleLocalType{ std::move(args)... })
        {
        }

        UiaTuple(ItemWrapperType... args) : UiaTuple()
        {
            SetTupleWrapperItems(args...);
        }

        UiaTuple(winrt::Microsoft::UI::UIAutomation::AutomationRemoteArray array) :
            UiaTypeBase(array)
        {
        }

        explicit UiaTuple(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject remoteValue) :
            UiaTypeBase(remoteValue.AsArray())
        {
        }

        UiaTuple(const UiaTuple&) = default;
        UiaTuple& operator=(const UiaTuple&) = delete;

        UiaTuple(UiaTuple&&) = default;
        UiaTuple& operator=(UiaTuple&&) = default;

        ~UiaTuple() = default;

        UiaBool IsNull() const
        {
            if (ShouldUseRemoteApi())
            {
                auto remoteValue = std::get_if<RemoteType>(&m_member);
                if (remoteValue)
                {
                    return remoteValue->IsNull();
                }
            }

            // The local version of a UiaTuple can never be null.
            return false;
        }

        UiaBool operator!() const { return IsNull(); }
        operator UiaBool() const { return !IsNull(); }

        operator std::shared_ptr<TupleLocalType>() const
        {
            return std::get<std::shared_ptr<TupleLocalType>>(m_member);
        }

        TupleLocalType& operator*()
        {
            return *std::get<LocalType>(m_member);
        }

        const TupleLocalType& operator*() const
        {
            return *std::get<LocalType>(m_member);
        }

        UiaBool operator==(const UiaTuple& rhs) const
        {
            if (ShouldUseRemoteApi())
            {
                auto mutableThis = *this;
                mutableThis.ToRemote();

                auto mutableRhs = rhs;
                mutableRhs.ToRemote();
                return std::get<RemoteType>(mutableThis.m_member).IsEqual(std::get<RemoteType>(mutableRhs.m_member));
            }

            auto localTuple = std::get<LocalType>(m_member);
            auto localRhsTuple = std::get<LocalType>(rhs.m_member);
            return *localTuple == *localRhsTuple;
        }

        UiaBool operator!=(const UiaTuple& rhs) const
        {
            return !(*this == rhs);
        }

        void ToRemote()
        {
            auto delegator = UiaOperationScope::GetCurrentDelegator();
            if (delegator)
            {
                delegator->ConvertVariantDataToRemote<ItemWrapperType...>(m_member);
            }
        }

        template <unsigned int I>
        void Set(TupleItemWrapperType<I> item)
        {
            if (ShouldUseRemoteApi())
            {
                UiaUint index{ I };
                ToRemote();
                index.ToRemote();
                item.ToRemote();
                std::get<RemoteType>(m_member).SetAt(index, item);
                return;
            }

            std::get<I>(*std::get<LocalType>(m_member)) = item;
        }

        template <unsigned int I>
        TupleItemWrapperType<I> Get()
        {
            if (ShouldUseRemoteApi())
            {
                UiaUint index{ I };
                ToRemote();
                index.ToRemote();
                return TupleItemWrapperType<I>{ std::get<RemoteType>(m_member).GetAt(index) };
            }

            return std::get<I>(*std::get<LocalType>(m_member));
        }

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            auto operationResults = result.as<winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable>>();
            m_member = std::make_shared<TupleLocalType>();

            auto& localValue = std::get<LocalType>(m_member);
            impl::RemoteArrayToLocalTuple<0, ItemWrapperType...>(operationResults, *localValue);
        }

    private:
        template<class... ItemWrapperTypes>
        void SetTupleWrapperItems(ItemWrapperTypes&&... items)
        {
            // For remote contexts, construct the remote array by appending provided items to it.
            //
            // This tries to avoid:
            // 1. Creating a remote array out of the local tuple (by appending values of the tuple to
            //    the array),
            // 2. Changing that remote array by overwriting its elements with the provided values.
            //
            // Which would result in more complex and less efficient operation to execute.
            if (ShouldUseRemoteApi())
            {
                // If `ShouldUseRemoteApi` returns `true`, `delegator` has to be non-null.
                auto delegator = UiaOperationScope::GetCurrentDelegator();
                FAIL_FAST_IF(!delegator);

                m_member = delegator->ItemsToRemoteArray(std::forward<ItemWrapperTypes>(items)...);
            }
            else
            {
                // For local contexts, just set the values of the underlying `std::tuple`.
                SetTupleWrapperItems<0 /* I */>(std::forward<ItemWrapperTypes>(items)...);
            }
        }

        // The functions allow callers to swap all `UiaTuple` values with new, provided values by
        // calling `Set<I>(newValue)` for every indexed value/field of `UiaTuple`.
        template<std::size_t I, class ItemWrapperType, class... ItemWrapperTypes>
        void SetTupleWrapperItems(ItemWrapperType&& item, ItemWrapperTypes&&... items)
        {
            Set<I>(std::forward<ItemWrapperType>(item));
            SetTupleWrapperItems<I + 1>(std::forward<ItemWrapperTypes>(items)...);
        }

        template<std::size_t I>
        void SetTupleWrapperItems()
        {
            // Ensure that at this point, we have set all items.
            static_assert((I == std::tuple_size_v<TupleLocalType>), "Setting tuple wrapper items should have modified all tuple fields");
        }
    };

    class UiaCacheRequest : public UiaTypeBase<
        winrt::com_ptr<IUIAutomationCacheRequest>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteCacheRequest>
    {
    public:
        UiaCacheRequest();

        void AddProperty(UiaPropertyId propertyId);
        void AddPattern(UiaPatternId patternId);
    };

#include "UiaTypeAbstraction.g.h"

    class UiaOperationScope;

    // FlsStorage handles fiber local storage allocation and deallocation for an object.
    // The object must be default constructable. FlsStorage is movable but not copyable.
    template <class ManagedObject>
    class FlsStorage
    {
    public:
        FlsStorage()
        {
            AllocateSlot();
        }

        ~FlsStorage()
        {
            FreeManagedObjects();
        }

        FlsStorage(FlsStorage&) = delete;
        FlsStorage& operator=(FlsStorage&) = delete;

        FlsStorage(FlsStorage&& original)
        {
            m_flsIndex = original.m_flsIndex;
            original.m_flsIndex = FLS_OUT_OF_INDEXES;
        }

        FlsStorage& operator=(FlsStorage&& original)
        {
            if (&original != this)
            {
                FreeManagedObjects();
                m_flsIndex = original.m_flsIndex;
                original.m_flsIndex = FLS_OUT_OF_INDEXES;
            }
            return *this;
        }

        // Get gets the current thread's managed object if one exists.
        // If one does not exist, one is allocated and returned.
        // Fails fast if the fiber-local storage slot is not allocated or if saving
        // the newly-allocated object to fiber-local storage fails for some reason.
        ManagedObject& Get()
        {
            return *GetPointer();
        }

        const ManagedObject& Get() const
        {
            return *GetPointer();
        }

        void FreeManagedObjects()
        {
            if (m_flsIndex != FLS_OUT_OF_INDEXES)
            {
                // FlsFree will call the callback for any slots at this index that have been used, regardless of thread, freeing the
                // objects referred to by the pointers contained in those slots.
                FlsFree(m_flsIndex);
                m_flsIndex = FLS_OUT_OF_INDEXES;
            }
        }

        void AllocateSlot()
        {
            if (m_flsIndex == FLS_OUT_OF_INDEXES)
            {
                m_flsIndex = FlsAlloc(&FlsCallback);
                FAIL_FAST_IF(m_flsIndex == FLS_OUT_OF_INDEXES);
            }
        }

    private:

        ManagedObject* GetPointer() const
        {
            FAIL_FAST_IF(m_flsIndex == FLS_OUT_OF_INDEXES);

            ManagedObject* managedObject = nullptr;
            void* flsValue = FlsGetValue(m_flsIndex);
            if (flsValue)
            {
                managedObject = reinterpret_cast<ManagedObject*>(flsValue);
            }
            else
            {
                managedObject = new ManagedObject;
                flsValue = static_cast<void*>(managedObject);
                FAIL_FAST_IF(!FlsSetValue(m_flsIndex, flsValue));
            }
            return managedObject;
        }

        // Note: this callback can be called in the context of the thread that called FlsFree, so do not do anything with thread
        // affinity in the callback. In addition, do not attempt to acquire any resource locks as this could lead to deadlock.
        static void _stdcall FlsCallback(_In_ void* flsValue)
        {
            if (flsValue)
            {
                auto managedObject = reinterpret_cast<ManagedObject*>(flsValue);
                delete managedObject;
            }
        }

        DWORD m_flsIndex = FLS_OUT_OF_INDEXES;
    };

    // UiaScopeContextManager uses fiber-local storage. Fiber-local storage is identical to thread-local storage when there are
    // no other fiber-related methods used, with one difference: when FlsFree is called, it calls the designated callback method
    // for each fiber (i.e. each thread) that has used that storage. This allows us to guarantee that all of the memory allocated
    // by this library has been deallocated when Cleanup returns.
    class UiaScopeContextManager
    {
    public:
        std::shared_ptr<UiaOperationDelegator> GetCurrentDelegator()
        {
            if (m_contextStack.empty())
            {
                return nullptr;
            }
            return m_contextStack.back().delegator;
        }

        using Binding = std::function<void(_In_ UiaOperationScope*)>;

        using Bindings = std::vector<Binding>;

        Bindings& GetCurrentBindings()
        {
            FAIL_FAST_IF(m_contextStack.empty());
            return m_contextStack.back().bindings;
        }

        void PushContext()
        {
            auto delegator = std::make_shared<UiaOperationDelegator>();
            m_contextStack.emplace_back(UiaScopeContext{ delegator });
        }

        void PushLocalContext()
        {
            auto delegator = std::make_shared<UiaOperationDelegator>(false /*useRemoteOperations*/);
            m_contextStack.emplace_back(UiaScopeContext{ delegator });
        }

        void PopContext()
        {
            FAIL_FAST_IF(m_contextStack.empty());
            m_contextStack.pop_back();
        }

    private:
        struct UiaScopeContext
        {
            std::shared_ptr<UiaOperationDelegator> delegator;
            Bindings bindings;
        };

        std::vector<UiaScopeContext> m_contextStack;
    };

    // Note: Because this class uses fiber local storage for the current UiaOperationDelegator, this abstraction
    // effectively only allows one UIA operation to be built per thread at a time. Attempting to build multiple
    // UIA operations (via two different UiaOperationScopes) will result in all calls being batched into the same
    // operation (only has noticeable effects when remote operations are used).
    class UiaOperationScope
    {
    public:
        UiaOperationScope(bool ownContext);
        UiaOperationScope(UiaOperationScope&) = delete;
        UiaOperationScope(UiaOperationScope&& other);

        ~UiaOperationScope();

        UiaOperationScope& operator=(const UiaOperationScope&) = delete;
        UiaOperationScope& operator=(UiaOperationScope&& other);

        static std::shared_ptr<UiaOperationDelegator> GetCurrentDelegator();

        // For wrappers that were created in local mode outside of a remote scope, we should convert them
        // to remote mode as soon as the remote scope begins, to avoid conditional conversion inside
        // a condition or loop. To abstract this from client code and provide symmetry with BindResult,
        // we provide a BindInput method to do this.
        template<class... Args>
        void BindInput(Args&... args)
        {
            (BindSingleInput(args), ...);
        }

        template <class WrapperType>
        void BindSingleInput(WrapperType& value)
        {
            // ToRemote will have no effect in a local scope, so we don't need to explicitly check that here.
            value.ToRemote();
        }

        // BindResult is used to bind results that are local in scope. If the remote operation is also
        // local in scope, the remote values will be fetched and the bound value will be converted back
        // to a local type.
        // If the remote operation is NOT local in scope, BindResult will do nothing. If you want to bind
        // a result that is not local in scope, and you're not sure whether your remote operation is local
        // in scope, use BindNonlocalResult.
        template<class... Args>
        void BindResult(Args&... args)
        {
            (BindSingleResult(args), ...);
        }

        template <class WrapperType>
        void BindSingleResult(WrapperType& value)
        {
            // The remote case only has to do something when resolution would result in executing the
            // remote operation - if this is a continuation of an existing operation, the value remains
            // remoted.
            auto delegator = GetCurrentDelegator();
            if ((delegator->GetUseRemoteApi()) && m_ownContext)
            {
                value.ToRemote();
                auto token = delegator->RequestResponse(static_cast<WrapperType::RemoteType>(value));

                remoteOperationResolvers.emplace_back(
                    [delegator, token, &value](winrt::Microsoft::UI::UIAutomation::AutomationRemoteOperationResultSet& result)
                    {
                        value.FromRemoteResult(result.GetResult(token));
                    }
                );
            }
            // In all other cases (strictly local operation, nested remote operation) bind is a no-op.
        }

        // BindNonlocalResult is used to bind results that are not local in scope. The binding will be
        // deferred until just before the outermost remote operation is executed, and will execute as a
        // local binding in that operation's scope.
        // This means that you MUST NOT bind variables with a lifetime shorter than the lifetime of your
        // remote operation with this method, as it will happily walk all over memory if you do.
        template <typename Type>
        void BindNonlocalResult(Type& value)
        {
            auto& nonLocalBindings = s_scopeContextManager.Get().GetCurrentBindings();
            auto delegator = GetCurrentDelegator();
            nonLocalBindings.emplace_back(
                [&value, delegator](_In_ UiaOperationScope* scope)
                {
                    scope->BindResult(value);
                }
            );
        }

        void Resolve();
        HRESULT ResolveHr() noexcept;

        template<class Operation>
        inline void CompileOrRun(Operation&& operation)
        {
            try
            {
                operation();
            }
            catch (UiaOperationAbstraction::ReturnSuccessException)
            {
                // do nothing, but by catching the exception we've exited the operation without throwing a winrt error.
            }
        }

        // The following methods all forward to the delegator. This is so that callers can have one object, the scope,
        // that does everything they need to do.
        inline bool GetUseRemoteApi() const
        {
            return GetCurrentDelegator()->GetUseRemoteApi();
        }

        template<class OnTrue, class OnFalse>
        inline void If(UiaBool conditionBool, OnTrue&& onTrue, OnFalse&& onFalse) const
        {
            GetCurrentDelegator()->If<OnTrue, OnFalse>(conditionBool, std::forward<OnTrue>(onTrue), std::forward<OnFalse>(onFalse));
        }

        template<class OnTrue>
        inline void If(UiaBool conditionBool, OnTrue&& onTrue) const
        {
            GetCurrentDelegator()->If<OnTrue>(conditionBool, std::forward<OnTrue>(onTrue));
        }

        // This method handles a pure lvalue conditional.
        // This method MUST NOT be modified to take a const lvalue ref or a non-ref value, because those
        // would allow an expression as the first argument.
        // Usage like "While( blah < 5, [&](){...});" is a problem, because the "blah < 5" expression
        // only gets evaluated once, not once per iteration, which is not the desired behavior.
        template<class Body>
        inline void While(UiaBool& condition, Body body)
        {
            GetCurrentDelegator()->While<Body>(condition, std::forward<Body>(body));
        }

        // This method handles an expression as a condition. The expression must be embedded in a lambda, e.g.
        // [&](){return blah < 5;}
        template<class ConditionBlock, class Body>
        inline void While(ConditionBlock conditionBlock, Body body)
        {
            GetCurrentDelegator()->While<ConditionBlock, Body>(std::forward<ConditionBlock>(conditionBlock), std::forward<Body>(body));
        }

        // This method provides something resembling a for loop, so users don't have to rewrite their for loops as while loops.
        template<class InitializeBlock, class ConditionBlock, class ModificationBlock, class Body>
        void For(InitializeBlock initialize, ConditionBlock condition, ModificationBlock modification, Body body)
        {
            GetCurrentDelegator()->For<InitializeBlock, ConditionBlock, ModificationBlock, Body>(
                std::forward<InitializeBlock>(initialize), std::forward<ConditionBlock>(condition),
                std::forward<ModificationBlock>(modification), std::forward<Body>(body));
        }

        template<class ArrayType, class Body>
        void ForEach(ArrayType array, Body body)
        {
            const auto arraySize = array.Size();
            UiaUint index{ 0 };

            For(
                []() {} /* initialize */,
                [&]() { return (index < arraySize); } /* condition */,
                [&]() { index += 1; } /* modification */,
                [&]() /* body */
                {
                    const auto element = array.GetAt(index);
                    body(element);
                });
        }

        inline void Break()
        {
            GetCurrentDelegator()->Break();
        }

        inline void Continue()
        {
            GetCurrentDelegator()->Continue();
        }

        void BreakIf(UiaBool condition)
        {
            If(condition, [&]()
            {
                Break();
            });
        }

        void ContinueIf(UiaBool condition)
        {
            If(condition, [&]()
            {
                Continue();
            });
        }

        inline void AbortOperationWithHresult(HRESULT hr)
        {
            GetCurrentDelegator()->AbortOperationWithHresult(hr);
        }

        // StartNew creates a new remote execution context, regardless of whether there's an existing one.
        // If there is an existing one, it is suspended while this new scope exists and resumes when this
        // scope is resolved or destroyed.
        static UiaOperationScope StartNew();

        // StartOrContinue creates a new remote execution context only if one does not already exist. If one
        // does exist, operations on the resulting scope apply to the preexisting context.
        static UiaOperationScope StartOrContinue();

        // ContinueIfRemote creates a scope that is local only, unless the innermost existing context is remote.
        // If it is remote, the resulting scope applies operations to the preexisting remote context.
        // This is useful for methods such as GetOppositeEndpoint that entail no cross-process calls but may
        // nonetheless need to be remoted in the context of an existing remote operation.
        static UiaOperationScope ContinueIfRemote();

        // FreeContextManagers should be called only on shutdown. It deallocates the fiber-local storage used to
        // store context managers, so calling it while threads still have active remote operations contexts will
        // result in undefined behavior.
        static void FreeContextManagers()
        {
            s_scopeContextManager.FreeManagedObjects();
        }

        // The context managers should be allocated at library startup, but if for some reason the workflow requires
        // them to be freed without restarting, this method is used to reallocate them. If they are already allocated,
        // this method does nothing.
        static void EnsureContextManagersAreAllocated()
        {
            s_scopeContextManager.AllocateSlot();
        }

    private:
        static FlsStorage<UiaScopeContextManager> s_scopeContextManager;

        bool m_ownContext = false;

        std::vector<Resolver> remoteOperationResolvers;

        // This method is deleted because of the risk of passing an expression that should be a block.
        // See above for why that's a problem.
        template<class Body>
        void While(UiaBool&&, Body body) = delete;

        void ResolveHrInternal(HRESULT& operationResult);

    };

    bool ShouldUseRemoteApi();
};
