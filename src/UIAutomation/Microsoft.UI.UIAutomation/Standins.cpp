// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "Standins.h"
#include "AutomationRemoteOperation.h"

namespace winrt
{
    using namespace winrt::Microsoft::UI::UIAutomation;
}

namespace winrt::Microsoft::UI::UIAutomation::implementation
{
    // AutomationRemoteObject

    AutomationRemoteObject::AutomationRemoteObject(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : m_operandId(operandId), m_parent(parent.get_strong())
    {
    }

    void AutomationRemoteObject::Set(const AutomationRemoteObject& rhs)
    {
        m_parent->InsertInstruction(bytecode::Set{ m_operandId, rhs.OperandId() });
    }

    winrt::AutomationRemoteBool AutomationRemoteObject::Compare(const AutomationRemoteObject& rhs, bytecode::ComparisonType type)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Compare{
            resultId,
            m_operandId,
            rhs.OperandId(),
            type
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    void AutomationRemoteObject::Add(const AutomationRemoteObject& rhs)
    {
        m_parent->InsertInstruction(bytecode::Add{
            m_operandId,
            rhs.OperandId()
        });
    }

    void AutomationRemoteObject::Subtract(const AutomationRemoteObject& rhs)
    {
        m_parent->InsertInstruction(bytecode::Subtract{
            m_operandId,
            rhs.OperandId()
        });
    }

    void AutomationRemoteObject::Multiply(const AutomationRemoteObject& rhs)
    {
        m_parent->InsertInstruction(bytecode::Multiply{
            m_operandId,
            rhs.OperandId()
        });
    }

    void AutomationRemoteObject::Divide(const AutomationRemoteObject& rhs)
    {
        m_parent->InsertInstruction(bytecode::Divide{
            m_operandId,
            rhs.OperandId()
        });
    }

    bytecode::OperandId AutomationRemoteObject::GetPropertyValueCommon(
        const winrt::AutomationRemotePropertyId& propertyId,
        const winrt::AutomationRemoteBool& ignoreDefaultValue)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetPropertyValue{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemotePropertyId>(propertyId),
            GetOperandId<AutomationRemoteBool>(ignoreDefaultValue)
        });
        return resultId;
    }

    bytecode::OperandId AutomationRemoteObject::GetSpecificPropertyValueCommon(PROPERTYID propertyId)
    {
        return GetPropertyValueCommon(
            m_parent->NewEnum(static_cast<AutomationPropertyId>(propertyId)),
            m_parent->NewBool(false) /* ignoreDefaultValue */);
    }

    winrt::AutomationRemoteBool AutomationRemoteObject::IsNull()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsNull{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    // AutomationRemoteBool

    AutomationRemoteBool::AutomationRemoteBool(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteBool AutomationRemoteBool::BoolNot()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::BoolNot{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteBool AutomationRemoteBool::BoolAnd(Microsoft::UI::UIAutomation::AutomationRemoteBool const& rhs)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::BoolAnd{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteBool>(rhs),
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteBool AutomationRemoteBool::BoolOr(Microsoft::UI::UIAutomation::AutomationRemoteBool const& rhs)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::BoolOr{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteBool>(rhs),
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemoteBool::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemoteInt

    AutomationRemoteInt::AutomationRemoteInt(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteString AutomationRemoteInt::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemoteUint

    AutomationRemoteUint::AutomationRemoteUint(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteString AutomationRemoteUint::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemoteDouble

    AutomationRemoteDouble::AutomationRemoteDouble(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteString AutomationRemoteDouble::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemoteChar

    AutomationRemoteChar::AutomationRemoteChar(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteChar::Set(winrt::AutomationRemoteChar const& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteChar>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteChar::IsEqual(winrt::AutomationRemoteChar const& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteChar>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteChar::IsNotEqual(winrt::AutomationRemoteChar const& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteChar>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteChar::IsLessThan(winrt::AutomationRemoteChar const& rhs)
    {
        return AutomationRemoteObject::IsLessThan<AutomationRemoteChar>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteChar::IsLessThanOrEqual(winrt::AutomationRemoteChar const& rhs)
    {
        return AutomationRemoteObject::IsLessThanOrEqual<AutomationRemoteChar>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteChar::IsGreaterThan(winrt::AutomationRemoteChar const& rhs)
    {
        return AutomationRemoteObject::IsGreaterThan<AutomationRemoteChar>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteChar::IsGreaterThanOrEqual(winrt::AutomationRemoteChar const& rhs)
    {
        return AutomationRemoteObject::IsGreaterThanOrEqual<AutomationRemoteChar>(rhs);
    }

    winrt::AutomationRemoteString AutomationRemoteChar::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemoteString

    AutomationRemoteString::AutomationRemoteString(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteChar AutomationRemoteString::GetAt(winrt::AutomationRemoteUint const& index)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteStringGetAt{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteUint>(index),
        });
        const auto result = Make<AutomationRemoteChar>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemoteString::Substr(winrt::AutomationRemoteUint const& index, winrt::AutomationRemoteUint const& length)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteStringSubstr{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteUint>(index),
            GetOperandId<AutomationRemoteUint>(length),
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemoteString::Concat(winrt::AutomationRemoteString const& other)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteStringConcat{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteString>(other),
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    winrt::AutomationRemoteUint AutomationRemoteString::Size()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteStringSize{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteUint>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemoteString::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemotePoint

    AutomationRemotePoint::AutomationRemotePoint(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteDouble AutomationRemotePoint::GetX()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetPointProperty::GetX(resultId, m_operandId));
        const auto result = Make<AutomationRemoteDouble>(resultId);
        return result;
    }

    winrt::AutomationRemoteDouble AutomationRemotePoint::GetY()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetPointProperty::GetY(resultId, m_operandId));
        const auto result = Make<AutomationRemoteDouble>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemotePoint::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemoteRect

    AutomationRemoteRect::AutomationRemoteRect(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteDouble AutomationRemoteRect::GetHeight()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetRectProperty::GetHeight(resultId, m_operandId));
        const auto result = Make<AutomationRemoteDouble>(resultId);
        return result;
    }

    winrt::AutomationRemoteDouble AutomationRemoteRect::GetWidth()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetRectProperty::GetWidth(resultId, m_operandId));
        const auto result = Make<AutomationRemoteDouble>(resultId);
        return result;
    }

    winrt::AutomationRemoteDouble AutomationRemoteRect::GetX()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetRectProperty::GetX(resultId, m_operandId));
        const auto result = Make<AutomationRemoteDouble>(resultId);
        return result;
    }

    winrt::AutomationRemoteDouble AutomationRemoteRect::GetY()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetRectProperty::GetY(resultId, m_operandId));
        const auto result = Make<AutomationRemoteDouble>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemoteRect::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemoteGuid

    AutomationRemoteGuid::AutomationRemoteGuid(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteAnnotationType AutomationRemoteGuid::LookupAnnotationType()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::LookupId{
            resultId,
            m_operandId,
            AutomationIdentifierType_Annotation
        });
        return Make<AutomationRemoteAnnotationType>(resultId);
    }

    winrt::AutomationRemotePropertyId AutomationRemoteGuid::LookupPropertyId()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::LookupId{
            resultId,
            m_operandId,
            AutomationIdentifierType_Property
        });
        return Make<AutomationRemotePropertyId>(resultId);
    }

    // AutomationRemoteArray

    AutomationRemoteArray::AutomationRemoteArray(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteArray::Append(winrt::AutomationRemoteObject obj)
    {
        m_parent->InsertInstruction(bytecode::RemoteArrayAppend{
            m_operandId,
            GetOperandId<AutomationRemoteObject>(obj),
        });
    }

    void AutomationRemoteArray::SetAt(winrt::AutomationRemoteUint index, winrt::AutomationRemoteObject obj)
    {
        m_parent->InsertInstruction(bytecode::RemoteArraySetAt{
            m_operandId,
            GetOperandId<AutomationRemoteUint>(index),
            GetOperandId<AutomationRemoteObject>(obj),
        });
    }

    winrt::AutomationRemoteAnyObject AutomationRemoteArray::RemoveAt(winrt::AutomationRemoteUint index)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteArrayRemoveAt{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteUint>(index),
        });
        const auto result = Make<AutomationRemoteAnyObject>(resultId);
        return result;
    }

    winrt::AutomationRemoteAnyObject AutomationRemoteArray::GetAt(winrt::AutomationRemoteUint index)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteArrayGetAt{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteUint>(index),
        });
        const auto result = Make<AutomationRemoteAnyObject>(resultId);
        return result;
    }

    winrt::AutomationRemoteUint AutomationRemoteArray::Size()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteArraySize{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteUint>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemoteArray::Stringify()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Stringify{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    // AutomationRemoteExtensionTarget

    AutomationRemoteExtensionTarget::AutomationRemoteExtensionTarget(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteExtensionTarget::CallExtension(const winrt::AutomationRemoteGuid& extensionId, winrt::array_view<const winrt::AutomationRemoteObject> operands)
    {
        std::vector<bytecode::OperandId> operandIds;
        for (const auto& operand : operands)
        {
            operandIds.emplace_back(GetOperandId<AutomationRemoteObject>(operand));
        }

        m_parent->InsertInstruction(bytecode::CallExtension{
            m_operandId,
            GetOperandId<AutomationRemoteGuid>(extensionId),
            std::move(operandIds)
            });
    }

    winrt::AutomationRemoteBool AutomationRemoteExtensionTarget::IsExtensionSupported(const winrt::AutomationRemoteGuid& extensionId)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsExtensionSupported{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteGuid>(extensionId)
        });

        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    // AutomationRemoteStringMap

    AutomationRemoteStringMap::AutomationRemoteStringMap(bytecode::OperandId operandId, AutomationRemoteOperation& parent) :
        base_type(operandId, parent)
    {
    }

    void AutomationRemoteStringMap::Set(Microsoft::UI::UIAutomation::AutomationRemoteStringMap const& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteStringMap>(rhs);
    }

    void AutomationRemoteStringMap::Insert(Microsoft::UI::UIAutomation::AutomationRemoteString const& key, Microsoft::UI::UIAutomation::AutomationRemoteObject const& val)
    {
        m_parent->InsertInstruction(bytecode::RemoteStringMapInsert{
            m_operandId,
            GetOperandId<AutomationRemoteString>(key),
            GetOperandId<AutomationRemoteObject>(val),
        });
    }

    Microsoft::UI::UIAutomation::AutomationRemoteAnyObject AutomationRemoteStringMap::Remove(Microsoft::UI::UIAutomation::AutomationRemoteString const& key)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteStringMapRemove{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteString>(key),
        });
        const auto result = Make<AutomationRemoteAnyObject>(resultId);
        return result;
    }

    Microsoft::UI::UIAutomation::AutomationRemoteBool AutomationRemoteStringMap::HasKey(Microsoft::UI::UIAutomation::AutomationRemoteString const& key)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteStringMapHasKey{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteString>(key),
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    Microsoft::UI::UIAutomation::AutomationRemoteAnyObject AutomationRemoteStringMap::Lookup(Microsoft::UI::UIAutomation::AutomationRemoteString const& key)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteStringMapLookup{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteString>(key),
        });
        const auto result = Make<AutomationRemoteAnyObject>(resultId);
        return result;
    }

    Microsoft::UI::UIAutomation::AutomationRemoteUint AutomationRemoteStringMap::Size()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::RemoteStringMapSize{
            resultId,
            m_operandId,
        });
        const auto result = Make<AutomationRemoteUint>(resultId);
        return result;
    }

    // AutomationRemoteCacheRequest

    AutomationRemoteCacheRequest::AutomationRemoteCacheRequest(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteCacheRequest::AddProperty(const winrt::AutomationRemotePropertyId& propertyId)
    {
        m_parent->InsertInstruction(bytecode::CacheRequestAddProperty{
            m_operandId,
            GetOperandId<AutomationRemotePropertyId>(propertyId)
        });
    }

    void AutomationRemoteCacheRequest::AddPattern(const winrt::AutomationRemotePatternId& patternId)
    {
        m_parent->InsertInstruction(bytecode::CacheRequestAddPattern{
            m_operandId,
            GetOperandId<AutomationRemotePatternId>(patternId)
        });
    }

    // AutomationRemoteElement

    AutomationRemoteElement::AutomationRemoteElement(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteAnyObject AutomationRemoteElement::GetPropertyValue(const winrt::AutomationRemotePropertyId& propertyId)
    {
        return GetPropertyValue(propertyId, m_parent->NewBool(false) /* ignoreDefaultValue */);
    }

    winrt::AutomationRemoteAnyObject AutomationRemoteElement::GetPropertyValue(
        const winrt::AutomationRemotePropertyId& propertyId,
        const winrt::AutomationRemoteBool& ignoreDefaultValue)
    {
        const auto resultId = GetPropertyValueCommon(propertyId, ignoreDefaultValue);
        const auto result = Make<AutomationRemoteAnyObject>(resultId);
        return result;
    }

    winrt::AutomationRemoteAnyObject AutomationRemoteElement::GetMetadataValue(
        const winrt::AutomationRemotePropertyId& propertyId,
        const winrt::AutomationRemoteMetadata& metadata)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetMetadataValue{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemotePropertyId>(propertyId),
            GetOperandId<AutomationRemoteMetadata>(metadata),
        });
        const auto result = Make<AutomationRemoteAnyObject>(resultId);
        return result;
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::GetUpdatedCacheElement(const winrt::AutomationRemoteCacheRequest& cacheRequest)
    {
        auto result = m_parent->NewNull().AsElement();
        result.Set(*this);
        result.PopulateCache(cacheRequest);
        return result;
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::Navigate(const winrt::AutomationRemoteInt& direction)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::Navigate{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteInt>(direction)
        });
        const auto result = Make<AutomationRemoteElement>(resultId);
        return result;
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::Navigate(NavigateDirection direction)
    {
        return Navigate(m_parent->NewInt(direction));
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::GetParentElement()
    {
        return Navigate(NavigateDirection_Parent);
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::GetFirstChildElement()
    {
        return Navigate(NavigateDirection_FirstChild);
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::GetLastChildElement()
    {
        return Navigate(NavigateDirection_LastChild);
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::GetNextSiblingElement()
    {
        return Navigate(NavigateDirection_NextSibling);
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::GetPreviousSiblingElement()
    {
        return Navigate(NavigateDirection_PreviousSibling);
    }

    void AutomationRemoteElement::PopulateCache(const winrt::AutomationRemoteCacheRequest& cacheRequest)
    {
        m_parent->InsertInstruction(bytecode::PopulateCache{
            m_operandId,
            GetOperandId<AutomationRemoteCacheRequest>(cacheRequest)
        });
    }

    // AutomationRemoteAnyObject

    AutomationRemoteAnyObject::AutomationRemoteAnyObject(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsNotSupported()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsNotSupported{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsMixedAttribute()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsMixedAttribute{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsBool()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsBool{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::AsBool()
    {
        return As<AutomationRemoteBool>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsInt()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsInt{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteInt AutomationRemoteAnyObject::AsInt()
    {
        return As<AutomationRemoteInt>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsUint()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsUint{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteUint AutomationRemoteAnyObject::AsUint()
    {
        return As<AutomationRemoteUint>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsDouble()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsDouble{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteDouble AutomationRemoteAnyObject::AsDouble()
    {
        return As<AutomationRemoteDouble>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsChar()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsChar{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteChar AutomationRemoteAnyObject::AsChar()
    {
        return As<AutomationRemoteChar>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsString()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsString{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemoteAnyObject::AsString()
    {
        return As<AutomationRemoteString>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsPoint()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsPoint{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemotePoint AutomationRemoteAnyObject::AsPoint()
    {
        return As<AutomationRemotePoint>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsRect()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsRect{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteRect AutomationRemoteAnyObject::AsRect()
    {
        return As<AutomationRemoteRect>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsGuid()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsGuid{
            resultId,
            m_operandId
        });
        return Make<AutomationRemoteBool>(resultId);
    }

    winrt::AutomationRemoteGuid AutomationRemoteAnyObject::AsGuid()
    {
        return As<AutomationRemoteGuid>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsArray()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsArray{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteArray AutomationRemoteAnyObject::AsArray()
    {
        return As<AutomationRemoteArray>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsStringMap()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsStringMap{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteStringMap AutomationRemoteAnyObject::AsStringMap()
    {
        return As<AutomationRemoteStringMap>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsElement()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsElement{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteElement AutomationRemoteAnyObject::AsElement()
    {
        return As<AutomationRemoteElement>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsCacheRequest()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::IsCacheRequest{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteCacheRequest AutomationRemoteAnyObject::AsCacheRequest()
    {
        return As<AutomationRemoteCacheRequest>();
    }
}
