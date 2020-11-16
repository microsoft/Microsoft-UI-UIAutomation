// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

#include "AutomationRemoteObject.g.h"
#include "AutomationRemoteBool.g.h"
#include "AutomationRemoteInt.g.h"
#include "AutomationRemoteUint.g.h"
#include "AutomationRemoteDouble.g.h"
#include "AutomationRemoteChar.g.h"
#include "AutomationRemoteString.g.h"
#include "AutomationRemotePoint.g.h"
#include "AutomationRemoteRect.g.h"
#include "AutomationRemoteGuid.g.h"
#include "AutomationRemoteArray.g.h"
#include "AutomationRemoteStringMap.g.h"
#include "AutomationRemoteCacheRequest.g.h"
#include "AutomationRemoteElement.g.h"
#include "AutomationRemoteAnyObject.g.h"
#include "AutomationRemoteExtensionTarget.g.h"
#include "AutomationRemoteOperation.h"

#include "RemoteOperationInstructions.h"
#include <winrt/Windows.Foundation.Collections.h>

namespace winrt
{
    using namespace winrt::Microsoft::UI::UIAutomation;
}

namespace winrt::Microsoft::UI::UIAutomation::implementation
{
    class AutomationRemoteObject : public AutomationRemoteObjectT<AutomationRemoteObject>
    {
    public:
        AutomationRemoteObject(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        // Internal
        auto OperandId() const noexcept
        {
            return m_operandId;
        }

        template <typename T>
        static auto GetOperandId(const typename T::class_type& standin) noexcept
        {
            return get_self<T>(standin)->OperandId();
        }

        template <typename ImplClass>
        auto Make(bytecode::OperandId operandId)
        {
            return make<ImplClass>(operandId, *m_parent);
        }

        // API
        winrt::AutomationRemoteBool IsNull();

    protected:
        // Generic
        template <typename T>
        void Set(const typename T::class_type& rhs)
        {
            Set(*get_self<T>(rhs));
        }

        template <typename T>
        auto IsEqual(const typename T::class_type& rhs)
        {
            return Compare(*get_self<T>(rhs), bytecode::ComparisonType::Equal);
        }

        template <typename T>
        auto IsNotEqual(const typename T::class_type& rhs)
        {
            return Compare(*get_self<T>(rhs), bytecode::ComparisonType::NotEqual);
        }

        template <typename T>
        auto IsLessThan(const typename T::class_type& rhs)
        {
            return Compare(*get_self<T>(rhs), bytecode::ComparisonType::LessThan);
        }

        template <typename T>
        auto IsLessThanOrEqual(const typename T::class_type& rhs)
        {
            return Compare(*get_self<T>(rhs), bytecode::ComparisonType::LessThanOrEqual);
        }

        template <typename T>
        auto IsGreaterThan(const typename T::class_type& rhs)
        {
            return Compare(*get_self<T>(rhs), bytecode::ComparisonType::GreaterThan);
        }

        template <typename T>
        auto IsGreaterThanOrEqual(const typename T::class_type& rhs)
        {
            return Compare(*get_self<T>(rhs), bytecode::ComparisonType::GreaterThanOrEqual);
        }

        template <typename T>
        void Add(const typename T::class_type& rhs)
        {
            Add(*get_self<T>(rhs));
        }

        template <typename T>
        void Subtract(const typename T::class_type& rhs)
        {
            Subtract(*get_self<T>(rhs));
        }

        template <typename T>
        void Multiply(const typename T::class_type& rhs)
        {
            Multiply(*get_self<T>(rhs));
        }

        template <typename T>
        void Divide(const typename T::class_type& rhs)
        {
            Divide(*get_self<T>(rhs));
        }

        // Property getter helpers need to go on AutomationRemoteObject so they can be used by both
        // the base element and patterns.
        bytecode::OperandId GetPropertyValueCommon(
            const winrt::AutomationRemotePropertyId& propertyId,
            const winrt::AutomationRemoteBool& ignoreDefaultValue);
        bytecode::OperandId GetSpecificPropertyValueCommon(PROPERTYID propertyId);

        template <typename ResultType>
        auto GetSpecificPropertyValue(PROPERTYID propertyId)
        {
            const auto resultId = GetSpecificPropertyValueCommon(propertyId);
            const auto result = Make<ResultType>(resultId);
            return result;
        }

        bytecode::OperandId m_operandId;

        // The operation that spawned the stand-in. The operation doesn't maintain a reference on any stand-in
        // objects that it spawns, so we can hold a strong reference here without creating a cycle.
        winrt::com_ptr<AutomationRemoteOperation> m_parent;

    private:
        void Set(const AutomationRemoteObject& rhs);
        winrt::AutomationRemoteBool Compare(const AutomationRemoteObject& rhs, bytecode::ComparisonType type);
        void Add(const AutomationRemoteObject& rhs);
        void Subtract(const AutomationRemoteObject& rhs);
        void Multiply(const AutomationRemoteObject& rhs);
        void Divide(const AutomationRemoteObject& rhs);
    };

    class AutomationRemoteBool : public AutomationRemoteBoolT<AutomationRemoteBool, AutomationRemoteObject>
    {
    public:
        AutomationRemoteBool(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteBool>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemoteBool>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemoteBool>(rhs);
        }

        winrt::AutomationRemoteBool BoolNot();
        winrt::AutomationRemoteBool BoolAnd(Microsoft::UI::UIAutomation::AutomationRemoteBool const& rhs);
        winrt::AutomationRemoteBool BoolOr(Microsoft::UI::UIAutomation::AutomationRemoteBool const& rhs);

        winrt::AutomationRemoteString Stringify();
    };

    class AutomationRemoteInt : public AutomationRemoteIntT<AutomationRemoteInt, AutomationRemoteObject>
    {
    public:
        AutomationRemoteInt(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteInt>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemoteInt>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemoteInt>(rhs);
        }

        auto IsLessThan(const class_type& rhs)
        {
            return AutomationRemoteObject::IsLessThan<AutomationRemoteInt>(rhs);
        }

        auto IsLessThanOrEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsLessThanOrEqual<AutomationRemoteInt>(rhs);
        }

        auto IsGreaterThan(const class_type& rhs)
        {
            return AutomationRemoteObject::IsGreaterThan<AutomationRemoteInt>(rhs);
        }

        auto IsGreaterThanOrEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsGreaterThanOrEqual<AutomationRemoteInt>(rhs);
        }

        void Add(const class_type& rhs)
        {
            AutomationRemoteObject::Add<AutomationRemoteInt>(rhs);
        }

        void Subtract(Microsoft::UI::UIAutomation::AutomationRemoteInt const& rhs)
        {
            AutomationRemoteObject::Subtract<AutomationRemoteInt>(rhs);
        }

        void Multiply(Microsoft::UI::UIAutomation::AutomationRemoteInt const& rhs)
        {
            AutomationRemoteObject::Multiply<AutomationRemoteInt>(rhs);
        }

        void Divide(Microsoft::UI::UIAutomation::AutomationRemoteInt const& rhs)
        {
            AutomationRemoteObject::Divide<AutomationRemoteInt>(rhs);
        }

        winrt::AutomationRemoteString Stringify();
    };

    class AutomationRemoteUint : public AutomationRemoteUintT<AutomationRemoteUint, AutomationRemoteObject>
    {
    public:
        AutomationRemoteUint(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteUint>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemoteUint>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemoteUint>(rhs);
        }

        auto IsLessThan(const class_type& rhs)
        {
            return AutomationRemoteObject::IsLessThan<AutomationRemoteUint>(rhs);
        }

        auto IsLessThanOrEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsLessThanOrEqual<AutomationRemoteUint>(rhs);
        }

        auto IsGreaterThan(const class_type& rhs)
        {
            return AutomationRemoteObject::IsGreaterThan<AutomationRemoteUint>(rhs);
        }

        auto IsGreaterThanOrEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsGreaterThanOrEqual<AutomationRemoteUint>(rhs);
        }

        void Add(const class_type& rhs)
        {
            AutomationRemoteObject::Add<AutomationRemoteUint>(rhs);
        }

        void Subtract(const class_type& rhs)
        {
            AutomationRemoteObject::Subtract<AutomationRemoteUint>(rhs);
        }

        void Multiply(const class_type& rhs)
        {
            AutomationRemoteObject::Multiply<AutomationRemoteUint>(rhs);
        }

        void Divide(const class_type& rhs)
        {
            AutomationRemoteObject::Divide<AutomationRemoteUint>(rhs);
        }

        winrt::AutomationRemoteString Stringify();
    };

    class AutomationRemoteDouble : public AutomationRemoteDoubleT<AutomationRemoteDouble, AutomationRemoteObject>
    {
    public:
        AutomationRemoteDouble(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteDouble>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemoteDouble>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemoteDouble>(rhs);
        }

        auto IsLessThan(const class_type& rhs)
        {
            return AutomationRemoteObject::IsLessThan<AutomationRemoteDouble>(rhs);
        }

        auto IsLessThanOrEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsLessThanOrEqual<AutomationRemoteDouble>(rhs);
        }

        auto IsGreaterThan(const class_type& rhs)
        {
            return AutomationRemoteObject::IsGreaterThan<AutomationRemoteDouble>(rhs);
        }

        auto IsGreaterThanOrEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsGreaterThanOrEqual<AutomationRemoteDouble>(rhs);
        }

        void Add(const class_type& rhs)
        {
            AutomationRemoteObject::Add<AutomationRemoteDouble>(rhs);
        }

        void Subtract(const class_type& rhs)
        {
            AutomationRemoteObject::Subtract<AutomationRemoteDouble>(rhs);
        }

        void Multiply(const class_type& rhs)
        {
            AutomationRemoteObject::Multiply<AutomationRemoteDouble>(rhs);
        }

        void Divide(const class_type& rhs)
        {
            AutomationRemoteObject::Divide<AutomationRemoteDouble>(rhs);
        }

        winrt::AutomationRemoteString Stringify();
    };

    struct AutomationRemoteChar : AutomationRemoteCharT<AutomationRemoteChar, Microsoft::UI::UIAutomation::implementation::AutomationRemoteObject>
    {
        AutomationRemoteChar(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(winrt::AutomationRemoteChar const& rhs);
        winrt::AutomationRemoteBool IsEqual(winrt::AutomationRemoteChar const& rhs);
        winrt::AutomationRemoteBool IsNotEqual(winrt::AutomationRemoteChar const& rhs);
        winrt::AutomationRemoteBool IsLessThan(winrt::AutomationRemoteChar const& rhs);
        winrt::AutomationRemoteBool IsLessThanOrEqual(winrt::AutomationRemoteChar const& rhs);
        winrt::AutomationRemoteBool IsGreaterThan(winrt::AutomationRemoteChar const& rhs);
        winrt::AutomationRemoteBool IsGreaterThanOrEqual(winrt::AutomationRemoteChar const& rhs);

        winrt::AutomationRemoteString Stringify();
    };

    class AutomationRemoteString : public AutomationRemoteStringT<AutomationRemoteString, AutomationRemoteObject>
    {
    public:
        AutomationRemoteString(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteString>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemoteString>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemoteString>(rhs);
        }

        winrt::AutomationRemoteChar GetAt(winrt::AutomationRemoteUint const& index);
        winrt::AutomationRemoteString Substr(winrt::AutomationRemoteUint const& index, winrt::AutomationRemoteUint const& length);
        winrt::AutomationRemoteString Concat(winrt::AutomationRemoteString const& other);
        winrt::AutomationRemoteUint Size();

        winrt::AutomationRemoteString Stringify();
    };

    class AutomationRemotePoint : public AutomationRemotePointT<AutomationRemotePoint, AutomationRemoteObject>
    {
    public:
        AutomationRemotePoint(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemotePoint>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemotePoint>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemotePoint>(rhs);
        }

        winrt::AutomationRemoteDouble GetX();
        winrt::AutomationRemoteDouble GetY();

        winrt::AutomationRemoteString Stringify();
    };

    class AutomationRemoteRect : public AutomationRemoteRectT<AutomationRemoteRect, AutomationRemoteObject>
    {
    public:
        AutomationRemoteRect(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteRect>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemoteRect>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemoteRect>(rhs);
        }

        winrt::AutomationRemoteDouble GetHeight();
        winrt::AutomationRemoteDouble GetWidth();
        winrt::AutomationRemoteDouble GetX();
        winrt::AutomationRemoteDouble GetY();

        winrt::AutomationRemoteString Stringify();
    };

    class AutomationRemoteGuid : public AutomationRemoteGuidT<AutomationRemoteGuid, AutomationRemoteObject>
    {
    public:
        AutomationRemoteGuid(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteGuid>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemoteGuid>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemoteGuid>(rhs);
        }

        winrt::AutomationRemoteAnnotationType LookupAnnotationType();
        winrt::AutomationRemotePropertyId LookupPropertyId();
    };

    class AutomationRemoteArray : public AutomationRemoteArrayT<AutomationRemoteArray, AutomationRemoteObject>
    {
    public:
        AutomationRemoteArray(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteArray>(rhs);
        }

        auto IsEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsEqual<AutomationRemoteArray>(rhs);
        }

        auto IsNotEqual(const class_type& rhs)
        {
            return AutomationRemoteObject::IsNotEqual<AutomationRemoteArray>(rhs);
        }

        void Append(winrt::AutomationRemoteObject obj);
        void SetAt(winrt::AutomationRemoteUint index, winrt::AutomationRemoteObject obj);
        winrt::AutomationRemoteAnyObject RemoveAt(winrt::AutomationRemoteUint index);

        winrt::AutomationRemoteAnyObject GetAt(winrt::AutomationRemoteUint index);

        winrt::AutomationRemoteUint Size();

        winrt::AutomationRemoteString Stringify();
    };

     class AutomationRemoteExtensionTarget : public AutomationRemoteExtensionTargetT<AutomationRemoteExtensionTarget, AutomationRemoteObject>
    {
    public:
        AutomationRemoteExtensionTarget(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void CallExtension(const winrt::AutomationRemoteGuid& extensionId, winrt::array_view<const winrt::AutomationRemoteObject> operands);
        winrt::AutomationRemoteBool IsExtensionSupported(const winrt::AutomationRemoteGuid& extensionId);
    };

    struct AutomationRemoteStringMap : AutomationRemoteStringMapT<AutomationRemoteStringMap, Microsoft::UI::UIAutomation::implementation::AutomationRemoteObject>
    {
        AutomationRemoteStringMap(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(Microsoft::UI::UIAutomation::AutomationRemoteStringMap const& rhs);
        void Insert(Microsoft::UI::UIAutomation::AutomationRemoteString const& key, Microsoft::UI::UIAutomation::AutomationRemoteObject const& val);
        Microsoft::UI::UIAutomation::AutomationRemoteAnyObject Remove(Microsoft::UI::UIAutomation::AutomationRemoteString const& key);
        Microsoft::UI::UIAutomation::AutomationRemoteBool HasKey(Microsoft::UI::UIAutomation::AutomationRemoteString const& key);
        Microsoft::UI::UIAutomation::AutomationRemoteAnyObject Lookup(Microsoft::UI::UIAutomation::AutomationRemoteString const& key);
        Microsoft::UI::UIAutomation::AutomationRemoteUint Size();
    };

    class AutomationRemoteCacheRequest : public AutomationRemoteCacheRequestT<AutomationRemoteCacheRequest, AutomationRemoteObject>
    {
    public:
        AutomationRemoteCacheRequest(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteCacheRequest>(rhs);
        }

        void AddProperty(const winrt::AutomationRemotePropertyId& propertyId);
        void AddPattern(const winrt::AutomationRemotePatternId& patternId);
    };

    class AutomationRemoteElement : public AutomationRemoteElementT<AutomationRemoteElement, AutomationRemoteExtensionTarget>
    {
    public:
        AutomationRemoteElement(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        void Set(const class_type& rhs)
        {
            AutomationRemoteObject::Set<AutomationRemoteElement>(rhs);
        }

        winrt::AutomationRemoteAnyObject GetPropertyValue(
            const winrt::AutomationRemotePropertyId& propertyId);
        winrt::AutomationRemoteAnyObject GetPropertyValue(
            const winrt::AutomationRemotePropertyId& propertyId,
            const winrt::AutomationRemoteBool& ignoreDefaultValue);

        winrt::AutomationRemoteAnyObject GetMetadataValue(
            const winrt::AutomationRemotePropertyId& propertyId,
            const winrt::AutomationRemoteMetadata& metadata);

        winrt::AutomationRemoteElement GetUpdatedCacheElement(const winrt::AutomationRemoteCacheRequest& cacheRequest);
        winrt::AutomationRemoteElement GetParentElement();
        winrt::AutomationRemoteElement GetFirstChildElement();
        winrt::AutomationRemoteElement GetLastChildElement();
        winrt::AutomationRemoteElement GetNextSiblingElement();
        winrt::AutomationRemoteElement GetPreviousSiblingElement();

        void PopulateCache(const winrt::AutomationRemoteCacheRequest& cacheRequest);

#include "AutomationRemoteElementMethods.g.h"

    private:
        winrt::AutomationRemoteElement Navigate(const winrt::AutomationRemoteInt& direction);
        winrt::AutomationRemoteElement Navigate(NavigateDirection direction);
    };

    class AutomationRemoteAnyObject : public AutomationRemoteAnyObjectT<AutomationRemoteAnyObject, AutomationRemoteObject>
    {
    public:
        AutomationRemoteAnyObject(bytecode::OperandId operandId, AutomationRemoteOperation& parent);

        winrt::AutomationRemoteBool IsNotSupported();
        winrt::AutomationRemoteBool IsMixedAttribute();
        winrt::AutomationRemoteBool IsBool();
        winrt::AutomationRemoteBool AsBool();
        winrt::AutomationRemoteBool IsInt();
        winrt::AutomationRemoteInt AsInt();
        winrt::AutomationRemoteBool IsUint();
        winrt::AutomationRemoteUint AsUint();
        winrt::AutomationRemoteBool IsDouble();
        winrt::AutomationRemoteDouble AsDouble();
        winrt::AutomationRemoteBool IsChar();
        winrt::AutomationRemoteChar AsChar();
        winrt::AutomationRemoteBool IsString();
        winrt::AutomationRemoteString AsString();
        winrt::AutomationRemoteBool IsPoint();
        winrt::AutomationRemotePoint AsPoint();
        winrt::AutomationRemoteBool IsRect();
        winrt::AutomationRemoteRect AsRect();
        winrt::AutomationRemoteBool IsGuid();
        winrt::AutomationRemoteGuid AsGuid();
        winrt::AutomationRemoteBool IsArray();
        winrt::AutomationRemoteArray AsArray();
        winrt::AutomationRemoteBool IsStringMap();
        winrt::AutomationRemoteStringMap AsStringMap();
        winrt::AutomationRemoteBool IsElement();
        winrt::AutomationRemoteElement AsElement();
        winrt::AutomationRemoteBool IsCacheRequest();
        winrt::AutomationRemoteCacheRequest AsCacheRequest();

#include "AutomationRemoteAnyObjectMethods.g.h"

    private:
        template <typename NewImplClass>
        auto As()
        {
            return Make<NewImplClass>(OperandId());
        }
    };
}

#include "Standins.g.h"
