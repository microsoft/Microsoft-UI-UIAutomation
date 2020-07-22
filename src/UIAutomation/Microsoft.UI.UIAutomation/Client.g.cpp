// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// WARNING: Please don't edit this file. It was generated.

#include "pch.h"
#include "Standins.h"
#include "AutomationRemoteOperation.h"

namespace winrt
{
    using namespace winrt::Microsoft::UI::UIAutomation;
}

namespace winrt::Microsoft::UI::UIAutomation::implementation
{
    AutomationRemoteActiveEnd::AutomationRemoteActiveEnd(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteActiveEnd::Set(const AutomationRemoteActiveEnd::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteActiveEnd>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteActiveEnd::IsEqual(const AutomationRemoteActiveEnd::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteActiveEnd>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteActiveEnd::IsNotEqual(const AutomationRemoteActiveEnd::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteActiveEnd>(rhs);
    }

    winrt::AutomationRemoteActiveEnd AutomationRemoteOperation::NewEnum(AutomationActiveEnd initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteActiveEnd>(resultId, *this);
        return result;
    }

    AutomationRemoteAnimationStyle::AutomationRemoteAnimationStyle(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteAnimationStyle::Set(const AutomationRemoteAnimationStyle::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteAnimationStyle>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteAnimationStyle::IsEqual(const AutomationRemoteAnimationStyle::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteAnimationStyle>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteAnimationStyle::IsNotEqual(const AutomationRemoteAnimationStyle::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteAnimationStyle>(rhs);
    }

    winrt::AutomationRemoteAnimationStyle AutomationRemoteOperation::NewEnum(AutomationAnimationStyle initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteAnimationStyle>(resultId, *this);
        return result;
    }

    AutomationRemoteAnnotationType::AutomationRemoteAnnotationType(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteAnnotationType::Set(const AutomationRemoteAnnotationType::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteAnnotationType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteAnnotationType::IsEqual(const AutomationRemoteAnnotationType::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteAnnotationType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteAnnotationType::IsNotEqual(const AutomationRemoteAnnotationType::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteAnnotationType>(rhs);
    }

    winrt::AutomationRemoteGuid AutomationRemoteAnnotationType::LookupGuid()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::LookupGuid{
            resultId,
            m_operandId,
            AutomationIdentifierType_Annotation
        });
        return Make<AutomationRemoteGuid>(resultId);
    }

    winrt::AutomationRemoteAnnotationType AutomationRemoteOperation::NewEnum(AutomationAnnotationType initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteAnnotationType>(resultId, *this);
        return result;
    }

    AutomationRemoteBulletStyle::AutomationRemoteBulletStyle(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteBulletStyle::Set(const AutomationRemoteBulletStyle::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteBulletStyle>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteBulletStyle::IsEqual(const AutomationRemoteBulletStyle::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteBulletStyle>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteBulletStyle::IsNotEqual(const AutomationRemoteBulletStyle::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteBulletStyle>(rhs);
    }

    winrt::AutomationRemoteBulletStyle AutomationRemoteOperation::NewEnum(AutomationBulletStyle initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteBulletStyle>(resultId, *this);
        return result;
    }

    AutomationRemoteCapStyle::AutomationRemoteCapStyle(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteCapStyle::Set(const AutomationRemoteCapStyle::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteCapStyle>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteCapStyle::IsEqual(const AutomationRemoteCapStyle::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteCapStyle>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteCapStyle::IsNotEqual(const AutomationRemoteCapStyle::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteCapStyle>(rhs);
    }

    winrt::AutomationRemoteCapStyle AutomationRemoteOperation::NewEnum(AutomationCapStyle initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteCapStyle>(resultId, *this);
        return result;
    }

    AutomationRemoteCaretBidiMode::AutomationRemoteCaretBidiMode(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteCaretBidiMode::Set(const AutomationRemoteCaretBidiMode::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteCaretBidiMode>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteCaretBidiMode::IsEqual(const AutomationRemoteCaretBidiMode::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteCaretBidiMode>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteCaretBidiMode::IsNotEqual(const AutomationRemoteCaretBidiMode::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteCaretBidiMode>(rhs);
    }

    winrt::AutomationRemoteCaretBidiMode AutomationRemoteOperation::NewEnum(AutomationCaretBidiMode initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteCaretBidiMode>(resultId, *this);
        return result;
    }

    AutomationRemoteCaretPosition::AutomationRemoteCaretPosition(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteCaretPosition::Set(const AutomationRemoteCaretPosition::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteCaretPosition>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteCaretPosition::IsEqual(const AutomationRemoteCaretPosition::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteCaretPosition>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteCaretPosition::IsNotEqual(const AutomationRemoteCaretPosition::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteCaretPosition>(rhs);
    }

    winrt::AutomationRemoteCaretPosition AutomationRemoteOperation::NewEnum(AutomationCaretPosition initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteCaretPosition>(resultId, *this);
        return result;
    }

    AutomationRemoteControlType::AutomationRemoteControlType(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteControlType::Set(const AutomationRemoteControlType::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteControlType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteControlType::IsEqual(const AutomationRemoteControlType::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteControlType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteControlType::IsNotEqual(const AutomationRemoteControlType::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteControlType>(rhs);
    }

    winrt::AutomationRemoteControlType AutomationRemoteOperation::NewEnum(AutomationControlType initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteControlType>(resultId, *this);
        return result;
    }

    AutomationRemoteDockPosition::AutomationRemoteDockPosition(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteDockPosition::Set(const AutomationRemoteDockPosition::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteDockPosition>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteDockPosition::IsEqual(const AutomationRemoteDockPosition::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteDockPosition>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteDockPosition::IsNotEqual(const AutomationRemoteDockPosition::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteDockPosition>(rhs);
    }

    winrt::AutomationRemoteDockPosition AutomationRemoteOperation::NewEnum(AutomationDockPosition initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteDockPosition>(resultId, *this);
        return result;
    }

    AutomationRemoteExpandCollapseState::AutomationRemoteExpandCollapseState(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteExpandCollapseState::Set(const AutomationRemoteExpandCollapseState::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteExpandCollapseState>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteExpandCollapseState::IsEqual(const AutomationRemoteExpandCollapseState::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteExpandCollapseState>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteExpandCollapseState::IsNotEqual(const AutomationRemoteExpandCollapseState::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteExpandCollapseState>(rhs);
    }

    winrt::AutomationRemoteExpandCollapseState AutomationRemoteOperation::NewEnum(AutomationExpandCollapseState initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteExpandCollapseState>(resultId, *this);
        return result;
    }

    AutomationRemoteFlowDirections::AutomationRemoteFlowDirections(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteFlowDirections::Set(const AutomationRemoteFlowDirections::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteFlowDirections>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteFlowDirections::IsEqual(const AutomationRemoteFlowDirections::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteFlowDirections>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteFlowDirections::IsNotEqual(const AutomationRemoteFlowDirections::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteFlowDirections>(rhs);
    }

    winrt::AutomationRemoteFlowDirections AutomationRemoteOperation::NewEnum(AutomationFlowDirections initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteFlowDirections>(resultId, *this);
        return result;
    }

    AutomationRemoteHeadingLevel::AutomationRemoteHeadingLevel(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteHeadingLevel::Set(const AutomationRemoteHeadingLevel::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteHeadingLevel>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteHeadingLevel::IsEqual(const AutomationRemoteHeadingLevel::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteHeadingLevel>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteHeadingLevel::IsNotEqual(const AutomationRemoteHeadingLevel::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteHeadingLevel>(rhs);
    }

    winrt::AutomationRemoteHeadingLevel AutomationRemoteOperation::NewEnum(AutomationHeadingLevel initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteHeadingLevel>(resultId, *this);
        return result;
    }

    AutomationRemoteHorizontalTextAlignment::AutomationRemoteHorizontalTextAlignment(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteHorizontalTextAlignment::Set(const AutomationRemoteHorizontalTextAlignment::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteHorizontalTextAlignment>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteHorizontalTextAlignment::IsEqual(const AutomationRemoteHorizontalTextAlignment::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteHorizontalTextAlignment>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteHorizontalTextAlignment::IsNotEqual(const AutomationRemoteHorizontalTextAlignment::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteHorizontalTextAlignment>(rhs);
    }

    winrt::AutomationRemoteHorizontalTextAlignment AutomationRemoteOperation::NewEnum(AutomationHorizontalTextAlignment initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteHorizontalTextAlignment>(resultId, *this);
        return result;
    }

    AutomationRemoteLandmarkType::AutomationRemoteLandmarkType(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteLandmarkType::Set(const AutomationRemoteLandmarkType::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteLandmarkType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteLandmarkType::IsEqual(const AutomationRemoteLandmarkType::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteLandmarkType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteLandmarkType::IsNotEqual(const AutomationRemoteLandmarkType::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteLandmarkType>(rhs);
    }

    winrt::AutomationRemoteLandmarkType AutomationRemoteOperation::NewEnum(AutomationLandmarkType initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteLandmarkType>(resultId, *this);
        return result;
    }

    AutomationRemoteLiveSetting::AutomationRemoteLiveSetting(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteLiveSetting::Set(const AutomationRemoteLiveSetting::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteLiveSetting>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteLiveSetting::IsEqual(const AutomationRemoteLiveSetting::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteLiveSetting>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteLiveSetting::IsNotEqual(const AutomationRemoteLiveSetting::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteLiveSetting>(rhs);
    }

    winrt::AutomationRemoteLiveSetting AutomationRemoteOperation::NewEnum(AutomationLiveSetting initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteLiveSetting>(resultId, *this);
        return result;
    }

    AutomationRemoteNavigateDirection::AutomationRemoteNavigateDirection(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteNavigateDirection::Set(const AutomationRemoteNavigateDirection::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteNavigateDirection>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteNavigateDirection::IsEqual(const AutomationRemoteNavigateDirection::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteNavigateDirection>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteNavigateDirection::IsNotEqual(const AutomationRemoteNavigateDirection::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteNavigateDirection>(rhs);
    }

    winrt::AutomationRemoteNavigateDirection AutomationRemoteOperation::NewEnum(AutomationNavigateDirection initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteNavigateDirection>(resultId, *this);
        return result;
    }

    AutomationRemoteOrientationType::AutomationRemoteOrientationType(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteOrientationType::Set(const AutomationRemoteOrientationType::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteOrientationType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteOrientationType::IsEqual(const AutomationRemoteOrientationType::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteOrientationType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteOrientationType::IsNotEqual(const AutomationRemoteOrientationType::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteOrientationType>(rhs);
    }

    winrt::AutomationRemoteOrientationType AutomationRemoteOperation::NewEnum(AutomationOrientationType initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteOrientationType>(resultId, *this);
        return result;
    }

    AutomationRemoteOutlineStyles::AutomationRemoteOutlineStyles(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteOutlineStyles::Set(const AutomationRemoteOutlineStyles::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteOutlineStyles>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteOutlineStyles::IsEqual(const AutomationRemoteOutlineStyles::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteOutlineStyles>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteOutlineStyles::IsNotEqual(const AutomationRemoteOutlineStyles::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteOutlineStyles>(rhs);
    }

    winrt::AutomationRemoteOutlineStyles AutomationRemoteOperation::NewEnum(AutomationOutlineStyles initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteOutlineStyles>(resultId, *this);
        return result;
    }

    AutomationRemotePatternId::AutomationRemotePatternId(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemotePatternId::Set(const AutomationRemotePatternId::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemotePatternId>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemotePatternId::IsEqual(const AutomationRemotePatternId::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemotePatternId>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemotePatternId::IsNotEqual(const AutomationRemotePatternId::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemotePatternId>(rhs);
    }

    winrt::AutomationRemotePatternId AutomationRemoteOperation::NewEnum(AutomationPatternId initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemotePatternId>(resultId, *this);
        return result;
    }

    AutomationRemotePropertyId::AutomationRemotePropertyId(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemotePropertyId::Set(const AutomationRemotePropertyId::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemotePropertyId>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemotePropertyId::IsEqual(const AutomationRemotePropertyId::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemotePropertyId>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemotePropertyId::IsNotEqual(const AutomationRemotePropertyId::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemotePropertyId>(rhs);
    }

    winrt::AutomationRemoteGuid AutomationRemotePropertyId::LookupGuid()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::LookupGuid{
            resultId,
            m_operandId,
            AutomationIdentifierType_Property
        });
        return Make<AutomationRemoteGuid>(resultId);
    }

    winrt::AutomationRemotePropertyId AutomationRemoteOperation::NewEnum(AutomationPropertyId initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemotePropertyId>(resultId, *this);
        return result;
    }

    AutomationRemoteRowOrColumnMajor::AutomationRemoteRowOrColumnMajor(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteRowOrColumnMajor::Set(const AutomationRemoteRowOrColumnMajor::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteRowOrColumnMajor>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteRowOrColumnMajor::IsEqual(const AutomationRemoteRowOrColumnMajor::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteRowOrColumnMajor>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteRowOrColumnMajor::IsNotEqual(const AutomationRemoteRowOrColumnMajor::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteRowOrColumnMajor>(rhs);
    }

    winrt::AutomationRemoteRowOrColumnMajor AutomationRemoteOperation::NewEnum(AutomationRowOrColumnMajor initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteRowOrColumnMajor>(resultId, *this);
        return result;
    }

    AutomationRemoteSayAsInterpretAs::AutomationRemoteSayAsInterpretAs(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSayAsInterpretAs::Set(const AutomationRemoteSayAsInterpretAs::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSayAsInterpretAs>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteSayAsInterpretAs::IsEqual(const AutomationRemoteSayAsInterpretAs::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteSayAsInterpretAs>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteSayAsInterpretAs::IsNotEqual(const AutomationRemoteSayAsInterpretAs::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteSayAsInterpretAs>(rhs);
    }

    winrt::AutomationRemoteSayAsInterpretAs AutomationRemoteOperation::NewEnum(AutomationSayAsInterpretAs initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteSayAsInterpretAs>(resultId, *this);
        return result;
    }

    AutomationRemoteScrollAmount::AutomationRemoteScrollAmount(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteScrollAmount::Set(const AutomationRemoteScrollAmount::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteScrollAmount>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteScrollAmount::IsEqual(const AutomationRemoteScrollAmount::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteScrollAmount>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteScrollAmount::IsNotEqual(const AutomationRemoteScrollAmount::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteScrollAmount>(rhs);
    }

    winrt::AutomationRemoteScrollAmount AutomationRemoteOperation::NewEnum(AutomationScrollAmount initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteScrollAmount>(resultId, *this);
        return result;
    }

    AutomationRemoteStyleId::AutomationRemoteStyleId(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteStyleId::Set(const AutomationRemoteStyleId::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteStyleId>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteStyleId::IsEqual(const AutomationRemoteStyleId::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteStyleId>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteStyleId::IsNotEqual(const AutomationRemoteStyleId::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteStyleId>(rhs);
    }

    winrt::AutomationRemoteStyleId AutomationRemoteOperation::NewEnum(AutomationStyleId initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteStyleId>(resultId, *this);
        return result;
    }

    AutomationRemoteSupportedTextSelection::AutomationRemoteSupportedTextSelection(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSupportedTextSelection::Set(const AutomationRemoteSupportedTextSelection::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSupportedTextSelection>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteSupportedTextSelection::IsEqual(const AutomationRemoteSupportedTextSelection::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteSupportedTextSelection>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteSupportedTextSelection::IsNotEqual(const AutomationRemoteSupportedTextSelection::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteSupportedTextSelection>(rhs);
    }

    winrt::AutomationRemoteSupportedTextSelection AutomationRemoteOperation::NewEnum(AutomationSupportedTextSelection initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteSupportedTextSelection>(resultId, *this);
        return result;
    }

    AutomationRemoteSynchronizedInputType::AutomationRemoteSynchronizedInputType(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSynchronizedInputType::Set(const AutomationRemoteSynchronizedInputType::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSynchronizedInputType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteSynchronizedInputType::IsEqual(const AutomationRemoteSynchronizedInputType::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteSynchronizedInputType>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteSynchronizedInputType::IsNotEqual(const AutomationRemoteSynchronizedInputType::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteSynchronizedInputType>(rhs);
    }

    winrt::AutomationRemoteSynchronizedInputType AutomationRemoteOperation::NewEnum(AutomationSynchronizedInputType initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteSynchronizedInputType>(resultId, *this);
        return result;
    }

    AutomationRemoteTextAttributeId::AutomationRemoteTextAttributeId(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextAttributeId::Set(const AutomationRemoteTextAttributeId::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextAttributeId>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTextAttributeId::IsEqual(const AutomationRemoteTextAttributeId::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteTextAttributeId>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTextAttributeId::IsNotEqual(const AutomationRemoteTextAttributeId::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteTextAttributeId>(rhs);
    }

    winrt::AutomationRemoteTextAttributeId AutomationRemoteOperation::NewEnum(AutomationTextAttributeId initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteTextAttributeId>(resultId, *this);
        return result;
    }

    AutomationRemoteTextDecorationLineStyle::AutomationRemoteTextDecorationLineStyle(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextDecorationLineStyle::Set(const AutomationRemoteTextDecorationLineStyle::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextDecorationLineStyle>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTextDecorationLineStyle::IsEqual(const AutomationRemoteTextDecorationLineStyle::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteTextDecorationLineStyle>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTextDecorationLineStyle::IsNotEqual(const AutomationRemoteTextDecorationLineStyle::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteTextDecorationLineStyle>(rhs);
    }

    winrt::AutomationRemoteTextDecorationLineStyle AutomationRemoteOperation::NewEnum(AutomationTextDecorationLineStyle initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteTextDecorationLineStyle>(resultId, *this);
        return result;
    }

    AutomationRemoteTextPatternRangeEndpoint::AutomationRemoteTextPatternRangeEndpoint(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextPatternRangeEndpoint::Set(const AutomationRemoteTextPatternRangeEndpoint::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextPatternRangeEndpoint>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTextPatternRangeEndpoint::IsEqual(const AutomationRemoteTextPatternRangeEndpoint::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteTextPatternRangeEndpoint>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTextPatternRangeEndpoint::IsNotEqual(const AutomationRemoteTextPatternRangeEndpoint::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteTextPatternRangeEndpoint>(rhs);
    }

    winrt::AutomationRemoteTextPatternRangeEndpoint AutomationRemoteOperation::NewEnum(AutomationTextPatternRangeEndpoint initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteTextPatternRangeEndpoint>(resultId, *this);
        return result;
    }

    AutomationRemoteTextUnit::AutomationRemoteTextUnit(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextUnit::Set(const AutomationRemoteTextUnit::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextUnit>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTextUnit::IsEqual(const AutomationRemoteTextUnit::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteTextUnit>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTextUnit::IsNotEqual(const AutomationRemoteTextUnit::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteTextUnit>(rhs);
    }

    winrt::AutomationRemoteTextUnit AutomationRemoteOperation::NewEnum(AutomationTextUnit initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteTextUnit>(resultId, *this);
        return result;
    }

    AutomationRemoteToggleState::AutomationRemoteToggleState(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteToggleState::Set(const AutomationRemoteToggleState::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteToggleState>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteToggleState::IsEqual(const AutomationRemoteToggleState::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteToggleState>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteToggleState::IsNotEqual(const AutomationRemoteToggleState::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteToggleState>(rhs);
    }

    winrt::AutomationRemoteToggleState AutomationRemoteOperation::NewEnum(AutomationToggleState initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteToggleState>(resultId, *this);
        return result;
    }

    AutomationRemoteWindowInteractionState::AutomationRemoteWindowInteractionState(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteWindowInteractionState::Set(const AutomationRemoteWindowInteractionState::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteWindowInteractionState>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowInteractionState::IsEqual(const AutomationRemoteWindowInteractionState::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteWindowInteractionState>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowInteractionState::IsNotEqual(const AutomationRemoteWindowInteractionState::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteWindowInteractionState>(rhs);
    }

    winrt::AutomationRemoteWindowInteractionState AutomationRemoteOperation::NewEnum(AutomationWindowInteractionState initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteWindowInteractionState>(resultId, *this);
        return result;
    }

    AutomationRemoteWindowVisualState::AutomationRemoteWindowVisualState(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteWindowVisualState::Set(const AutomationRemoteWindowVisualState::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteWindowVisualState>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowVisualState::IsEqual(const AutomationRemoteWindowVisualState::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteWindowVisualState>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowVisualState::IsNotEqual(const AutomationRemoteWindowVisualState::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteWindowVisualState>(rhs);
    }

    winrt::AutomationRemoteWindowVisualState AutomationRemoteOperation::NewEnum(AutomationWindowVisualState initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteWindowVisualState>(resultId, *this);
        return result;
    }

    AutomationRemoteZoomUnit::AutomationRemoteZoomUnit(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteZoomUnit::Set(const AutomationRemoteZoomUnit::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteZoomUnit>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteZoomUnit::IsEqual(const AutomationRemoteZoomUnit::class_type& rhs)
    {
        return AutomationRemoteObject::IsEqual<AutomationRemoteZoomUnit>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteZoomUnit::IsNotEqual(const AutomationRemoteZoomUnit::class_type& rhs)
    {
        return AutomationRemoteObject::IsNotEqual<AutomationRemoteZoomUnit>(rhs);
    }

    winrt::AutomationRemoteZoomUnit AutomationRemoteOperation::NewEnum(AutomationZoomUnit initialValue)
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::NewInt{
            resultId,
            static_cast<int>(initialValue)
        });
        const auto result = make<AutomationRemoteZoomUnit>(resultId, *this);
        return result;
    }

    AutomationRemoteInvokePattern::AutomationRemoteInvokePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteInvokePattern::Set(const AutomationRemoteInvokePattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteInvokePattern>(rhs);
    }

    void AutomationRemoteInvokePattern::Invoke()
    {
        m_parent->InsertInstruction(bytecode::InvokePatternInvoke{
            m_operandId
        });
    }

    AutomationRemoteSelectionPattern::AutomationRemoteSelectionPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSelectionPattern::Set(const AutomationRemoteSelectionPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSelectionPattern>(rhs);
    }

    winrt::AutomationRemoteArray AutomationRemoteSelectionPattern::GetSelection()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_SelectionSelectionPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteSelectionPattern::GetCanSelectMultiple()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_SelectionCanSelectMultiplePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteSelectionPattern::GetIsSelectionRequired()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_SelectionIsSelectionRequiredPropertyId);
    }

    AutomationRemoteValuePattern::AutomationRemoteValuePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteValuePattern::Set(const AutomationRemoteValuePattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteValuePattern>(rhs);
    }

    winrt::AutomationRemoteString AutomationRemoteValuePattern::GetValue()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_ValueValuePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteValuePattern::GetIsReadOnly()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_ValueIsReadOnlyPropertyId);
    }

    void AutomationRemoteValuePattern::SetValue(const winrt::AutomationRemoteString& val)
    {
        m_parent->InsertInstruction(bytecode::ValuePatternSetValue{
            m_operandId,
            GetOperandId<AutomationRemoteString>(val)
        });
    }

    AutomationRemoteRangeValuePattern::AutomationRemoteRangeValuePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteRangeValuePattern::Set(const AutomationRemoteRangeValuePattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteRangeValuePattern>(rhs);
    }

    winrt::AutomationRemoteDouble AutomationRemoteRangeValuePattern::GetValue()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_RangeValueValuePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteRangeValuePattern::GetIsReadOnly()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_RangeValueIsReadOnlyPropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteRangeValuePattern::GetMaximum()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_RangeValueMaximumPropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteRangeValuePattern::GetMinimum()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_RangeValueMinimumPropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteRangeValuePattern::GetLargeChange()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_RangeValueLargeChangePropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteRangeValuePattern::GetSmallChange()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_RangeValueSmallChangePropertyId);
    }

    void AutomationRemoteRangeValuePattern::SetValue(const winrt::AutomationRemoteDouble& val)
    {
        m_parent->InsertInstruction(bytecode::RangeValuePatternSetValue{
            m_operandId,
            GetOperandId<AutomationRemoteDouble>(val)
        });
    }

    AutomationRemoteScrollPattern::AutomationRemoteScrollPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteScrollPattern::Set(const AutomationRemoteScrollPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteScrollPattern>(rhs);
    }

    winrt::AutomationRemoteDouble AutomationRemoteScrollPattern::GetHorizontalScrollPercent()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_ScrollHorizontalScrollPercentPropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteScrollPattern::GetVerticalScrollPercent()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_ScrollVerticalScrollPercentPropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteScrollPattern::GetHorizontalViewSize()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_ScrollHorizontalViewSizePropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteScrollPattern::GetVerticalViewSize()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_ScrollVerticalViewSizePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteScrollPattern::GetHorizontallyScrollable()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_ScrollHorizontallyScrollablePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteScrollPattern::GetVerticallyScrollable()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_ScrollVerticallyScrollablePropertyId);
    }

    void AutomationRemoteScrollPattern::Scroll(const winrt::AutomationRemoteScrollAmount& horizontalAmount, const winrt::AutomationRemoteScrollAmount& verticalAmount)
    {
        m_parent->InsertInstruction(bytecode::ScrollPatternScroll{
            m_operandId,
            GetOperandId<AutomationRemoteScrollAmount>(horizontalAmount),
            GetOperandId<AutomationRemoteScrollAmount>(verticalAmount)
        });
    }

    void AutomationRemoteScrollPattern::SetScrollPercent(const winrt::AutomationRemoteDouble& horizontalPercent, const winrt::AutomationRemoteDouble& verticalPercent)
    {
        m_parent->InsertInstruction(bytecode::ScrollPatternSetScrollPercent{
            m_operandId,
            GetOperandId<AutomationRemoteDouble>(horizontalPercent),
            GetOperandId<AutomationRemoteDouble>(verticalPercent)
        });
    }

    AutomationRemoteExpandCollapsePattern::AutomationRemoteExpandCollapsePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteExpandCollapsePattern::Set(const AutomationRemoteExpandCollapsePattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteExpandCollapsePattern>(rhs);
    }

    winrt::AutomationRemoteExpandCollapseState AutomationRemoteExpandCollapsePattern::GetExpandCollapseState()
    {
        return GetSpecificPropertyValue<AutomationRemoteExpandCollapseState>(UIA_ExpandCollapseExpandCollapseStatePropertyId);
    }

    void AutomationRemoteExpandCollapsePattern::Expand()
    {
        m_parent->InsertInstruction(bytecode::ExpandCollapsePatternExpand{
            m_operandId
        });
    }

    void AutomationRemoteExpandCollapsePattern::Collapse()
    {
        m_parent->InsertInstruction(bytecode::ExpandCollapsePatternCollapse{
            m_operandId
        });
    }

    AutomationRemoteGridPattern::AutomationRemoteGridPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteGridPattern::Set(const AutomationRemoteGridPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteGridPattern>(rhs);
    }

    winrt::AutomationRemoteInt AutomationRemoteGridPattern::GetRowCount()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_GridRowCountPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteGridPattern::GetColumnCount()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_GridColumnCountPropertyId);
    }

    winrt::AutomationRemoteElement AutomationRemoteGridPattern::GetItem(const winrt::AutomationRemoteInt& row, const winrt::AutomationRemoteInt& column)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GridPatternGetItem{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteInt>(row),
            GetOperandId<AutomationRemoteInt>(column)
        });
        const auto result = Make<AutomationRemoteElement>(resultId);
        return result;
    }

    AutomationRemoteGridItemPattern::AutomationRemoteGridItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteGridItemPattern::Set(const AutomationRemoteGridItemPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteGridItemPattern>(rhs);
    }

    winrt::AutomationRemoteElement AutomationRemoteGridItemPattern::GetContainingGrid()
    {
        return GetSpecificPropertyValue<AutomationRemoteElement>(UIA_GridItemContainingGridPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteGridItemPattern::GetRow()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_GridItemRowPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteGridItemPattern::GetColumn()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_GridItemColumnPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteGridItemPattern::GetRowSpan()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_GridItemRowSpanPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteGridItemPattern::GetColumnSpan()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_GridItemColumnSpanPropertyId);
    }

    AutomationRemoteMultipleViewPattern::AutomationRemoteMultipleViewPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteMultipleViewPattern::Set(const AutomationRemoteMultipleViewPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteMultipleViewPattern>(rhs);
    }

    winrt::AutomationRemoteInt AutomationRemoteMultipleViewPattern::GetCurrentView()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_MultipleViewCurrentViewPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteMultipleViewPattern::GetSupportedViews()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_MultipleViewSupportedViewsPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteMultipleViewPattern::GetViewName(const winrt::AutomationRemoteInt& view)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::MultipleViewPatternGetViewName{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteInt>(view)
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    void AutomationRemoteMultipleViewPattern::SetCurrentView(const winrt::AutomationRemoteInt& view)
    {
        m_parent->InsertInstruction(bytecode::MultipleViewPatternSetCurrentView{
            m_operandId,
            GetOperandId<AutomationRemoteInt>(view)
        });
    }

    AutomationRemoteWindowPattern::AutomationRemoteWindowPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteWindowPattern::Set(const AutomationRemoteWindowPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteWindowPattern>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowPattern::GetCanMaximize()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_WindowCanMaximizePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowPattern::GetCanMinimize()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_WindowCanMinimizePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowPattern::GetIsModal()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_WindowIsModalPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowPattern::GetIsTopmost()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_WindowIsTopmostPropertyId);
    }

    winrt::AutomationRemoteWindowVisualState AutomationRemoteWindowPattern::GetWindowVisualState()
    {
        return GetSpecificPropertyValue<AutomationRemoteWindowVisualState>(UIA_WindowWindowVisualStatePropertyId);
    }

    winrt::AutomationRemoteWindowInteractionState AutomationRemoteWindowPattern::GetWindowInteractionState()
    {
        return GetSpecificPropertyValue<AutomationRemoteWindowInteractionState>(UIA_WindowWindowInteractionStatePropertyId);
    }

    void AutomationRemoteWindowPattern::Close()
    {
        m_parent->InsertInstruction(bytecode::WindowPatternClose{
            m_operandId
        });
    }

    winrt::AutomationRemoteBool AutomationRemoteWindowPattern::WaitForInputIdle(const winrt::AutomationRemoteInt& milliseconds)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::WindowPatternWaitForInputIdle{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteInt>(milliseconds)
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    void AutomationRemoteWindowPattern::SetWindowVisualState(const winrt::AutomationRemoteWindowVisualState& state)
    {
        m_parent->InsertInstruction(bytecode::WindowPatternSetWindowVisualState{
            m_operandId,
            GetOperandId<AutomationRemoteWindowVisualState>(state)
        });
    }

    AutomationRemoteSelectionItemPattern::AutomationRemoteSelectionItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSelectionItemPattern::Set(const AutomationRemoteSelectionItemPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSelectionItemPattern>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteSelectionItemPattern::GetIsSelected()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_SelectionItemIsSelectedPropertyId);
    }

    winrt::AutomationRemoteElement AutomationRemoteSelectionItemPattern::GetSelectionContainer()
    {
        return GetSpecificPropertyValue<AutomationRemoteElement>(UIA_SelectionItemSelectionContainerPropertyId);
    }

    void AutomationRemoteSelectionItemPattern::Select()
    {
        m_parent->InsertInstruction(bytecode::SelectionItemPatternSelect{
            m_operandId
        });
    }

    void AutomationRemoteSelectionItemPattern::AddToSelection()
    {
        m_parent->InsertInstruction(bytecode::SelectionItemPatternAddToSelection{
            m_operandId
        });
    }

    void AutomationRemoteSelectionItemPattern::RemoveFromSelection()
    {
        m_parent->InsertInstruction(bytecode::SelectionItemPatternRemoveFromSelection{
            m_operandId
        });
    }

    AutomationRemoteDockPattern::AutomationRemoteDockPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteDockPattern::Set(const AutomationRemoteDockPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteDockPattern>(rhs);
    }

    winrt::AutomationRemoteDockPosition AutomationRemoteDockPattern::GetDockPosition()
    {
        return GetSpecificPropertyValue<AutomationRemoteDockPosition>(UIA_DockDockPositionPropertyId);
    }

    void AutomationRemoteDockPattern::SetDockPosition(const winrt::AutomationRemoteDockPosition& dockPos)
    {
        m_parent->InsertInstruction(bytecode::DockPatternSetDockPosition{
            m_operandId,
            GetOperandId<AutomationRemoteDockPosition>(dockPos)
        });
    }

    AutomationRemoteTablePattern::AutomationRemoteTablePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTablePattern::Set(const AutomationRemoteTablePattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTablePattern>(rhs);
    }

    winrt::AutomationRemoteArray AutomationRemoteTablePattern::GetRowHeaders()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_TableRowHeadersPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteTablePattern::GetColumnHeaders()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_TableColumnHeadersPropertyId);
    }

    winrt::AutomationRemoteRowOrColumnMajor AutomationRemoteTablePattern::GetRowOrColumnMajor()
    {
        return GetSpecificPropertyValue<AutomationRemoteRowOrColumnMajor>(UIA_TableRowOrColumnMajorPropertyId);
    }

    AutomationRemoteTableItemPattern::AutomationRemoteTableItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTableItemPattern::Set(const AutomationRemoteTableItemPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTableItemPattern>(rhs);
    }

    winrt::AutomationRemoteArray AutomationRemoteTableItemPattern::GetRowHeaderItems()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_TableItemRowHeaderItemsPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteTableItemPattern::GetColumnHeaderItems()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_TableItemColumnHeaderItemsPropertyId);
    }

    AutomationRemoteTextPattern::AutomationRemoteTextPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextPattern::Set(const AutomationRemoteTextPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextPattern>(rhs);
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextPattern::RangeFromPoint(const winrt::AutomationRemotePoint& pt)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextPatternRangeFromPoint{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemotePoint>(pt)
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextPattern::RangeFromChild(const winrt::AutomationRemoteElement& child)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextPatternRangeFromChild{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteElement>(child)
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    winrt::AutomationRemoteArray AutomationRemoteTextPattern::GetSelection()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextPatternGetSelection{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteArray>(resultId);
        return result;
    }

    winrt::AutomationRemoteArray AutomationRemoteTextPattern::GetVisibleRanges()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextPatternGetVisibleRanges{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteArray>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextPattern::GetDocumentRange()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextPatternGetDocumentRange{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    winrt::AutomationRemoteSupportedTextSelection AutomationRemoteTextPattern::GetSupportedTextSelection()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextPatternGetSupportedTextSelection{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteSupportedTextSelection>(resultId);
        return result;
    }

    AutomationRemoteTextRange::AutomationRemoteTextRange(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextRange::Set(const AutomationRemoteTextRange::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextRange>(rhs);
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextRange::Clone()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeClone{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    winrt::AutomationRemoteBool AutomationRemoteTextRange::Compare(const winrt::AutomationRemoteTextRange& range)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeCompare{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteTextRange>(range)
        });
        const auto result = Make<AutomationRemoteBool>(resultId);
        return result;
    }

    winrt::AutomationRemoteInt AutomationRemoteTextRange::CompareEndpoints(const winrt::AutomationRemoteTextPatternRangeEndpoint& srcEndPoint, const winrt::AutomationRemoteTextRange& range, const winrt::AutomationRemoteTextPatternRangeEndpoint& targetEndPoint)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeCompareEndpoints{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteTextPatternRangeEndpoint>(srcEndPoint),
            GetOperandId<AutomationRemoteTextRange>(range),
            GetOperandId<AutomationRemoteTextPatternRangeEndpoint>(targetEndPoint)
        });
        const auto result = Make<AutomationRemoteInt>(resultId);
        return result;
    }

    void AutomationRemoteTextRange::ExpandToEnclosingUnit(const winrt::AutomationRemoteTextUnit& TextUnit)
    {
        m_parent->InsertInstruction(bytecode::TextRangeExpandToEnclosingUnit{
            m_operandId,
            GetOperandId<AutomationRemoteTextUnit>(TextUnit)
        });
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextRange::FindAttribute(const winrt::AutomationRemoteTextAttributeId& attr, const winrt::AutomationRemoteObject& val, const winrt::AutomationRemoteBool& backward)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeFindAttribute{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteTextAttributeId>(attr),
            GetOperandId<AutomationRemoteObject>(val),
            GetOperandId<AutomationRemoteBool>(backward)
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextRange::FindText(const winrt::AutomationRemoteString& text, const winrt::AutomationRemoteBool& backward, const winrt::AutomationRemoteBool& ignoreCase)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeFindText{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteString>(text),
            GetOperandId<AutomationRemoteBool>(backward),
            GetOperandId<AutomationRemoteBool>(ignoreCase)
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    winrt::AutomationRemoteAnyObject AutomationRemoteTextRange::GetAttributeValue(const winrt::AutomationRemoteTextAttributeId& attr)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeGetAttributeValue{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteTextAttributeId>(attr)
        });
        const auto result = Make<AutomationRemoteAnyObject>(resultId);
        return result;
    }

    winrt::AutomationRemoteArray AutomationRemoteTextRange::GetBoundingRectangles()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeGetBoundingRectangles{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteArray>(resultId);
        return result;
    }

    winrt::AutomationRemoteElement AutomationRemoteTextRange::GetEnclosingElement()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeGetEnclosingElement{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteElement>(resultId);
        return result;
    }

    winrt::AutomationRemoteString AutomationRemoteTextRange::GetText(const winrt::AutomationRemoteInt& maxLength)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeGetText{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteInt>(maxLength)
        });
        const auto result = Make<AutomationRemoteString>(resultId);
        return result;
    }

    winrt::AutomationRemoteInt AutomationRemoteTextRange::Move(const winrt::AutomationRemoteTextUnit& unit, const winrt::AutomationRemoteInt& count)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeMove{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteTextUnit>(unit),
            GetOperandId<AutomationRemoteInt>(count)
        });
        const auto result = Make<AutomationRemoteInt>(resultId);
        return result;
    }

    winrt::AutomationRemoteInt AutomationRemoteTextRange::MoveEndpointByUnit(const winrt::AutomationRemoteTextPatternRangeEndpoint& endpoint, const winrt::AutomationRemoteTextUnit& unit, const winrt::AutomationRemoteInt& count)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeMoveEndpointByUnit{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteTextPatternRangeEndpoint>(endpoint),
            GetOperandId<AutomationRemoteTextUnit>(unit),
            GetOperandId<AutomationRemoteInt>(count)
        });
        const auto result = Make<AutomationRemoteInt>(resultId);
        return result;
    }

    void AutomationRemoteTextRange::MoveEndpointByRange(const winrt::AutomationRemoteTextPatternRangeEndpoint& srcEndPoint, const winrt::AutomationRemoteTextRange& range, const winrt::AutomationRemoteTextPatternRangeEndpoint& targetEndPoint)
    {
        m_parent->InsertInstruction(bytecode::TextRangeMoveEndpointByRange{
            m_operandId,
            GetOperandId<AutomationRemoteTextPatternRangeEndpoint>(srcEndPoint),
            GetOperandId<AutomationRemoteTextRange>(range),
            GetOperandId<AutomationRemoteTextPatternRangeEndpoint>(targetEndPoint)
        });
    }

    void AutomationRemoteTextRange::Select()
    {
        m_parent->InsertInstruction(bytecode::TextRangeSelect{
            m_operandId
        });
    }

    void AutomationRemoteTextRange::AddToSelection()
    {
        m_parent->InsertInstruction(bytecode::TextRangeAddToSelection{
            m_operandId
        });
    }

    void AutomationRemoteTextRange::RemoveFromSelection()
    {
        m_parent->InsertInstruction(bytecode::TextRangeRemoveFromSelection{
            m_operandId
        });
    }

    void AutomationRemoteTextRange::ScrollIntoView(const winrt::AutomationRemoteBool& alignToTop)
    {
        m_parent->InsertInstruction(bytecode::TextRangeScrollIntoView{
            m_operandId,
            GetOperandId<AutomationRemoteBool>(alignToTop)
        });
    }

    winrt::AutomationRemoteArray AutomationRemoteTextRange::GetChildren()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextRangeGetChildren{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteArray>(resultId);
        return result;
    }

    void AutomationRemoteTextRange::ShowContextMenu()
    {
        m_parent->InsertInstruction(bytecode::TextRangeShowContextMenu{
            m_operandId
        });
    }

    AutomationRemoteTogglePattern::AutomationRemoteTogglePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTogglePattern::Set(const AutomationRemoteTogglePattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTogglePattern>(rhs);
    }

    winrt::AutomationRemoteToggleState AutomationRemoteTogglePattern::GetToggleState()
    {
        return GetSpecificPropertyValue<AutomationRemoteToggleState>(UIA_ToggleToggleStatePropertyId);
    }

    void AutomationRemoteTogglePattern::Toggle()
    {
        m_parent->InsertInstruction(bytecode::TogglePatternToggle{
            m_operandId
        });
    }

    AutomationRemoteTransformPattern::AutomationRemoteTransformPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTransformPattern::Set(const AutomationRemoteTransformPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTransformPattern>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTransformPattern::GetCanMove()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_TransformCanMovePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteTransformPattern::GetCanResize()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_TransformCanResizePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteTransformPattern::GetCanRotate()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_TransformCanRotatePropertyId);
    }

    void AutomationRemoteTransformPattern::Move(const winrt::AutomationRemoteDouble& x, const winrt::AutomationRemoteDouble& y)
    {
        m_parent->InsertInstruction(bytecode::TransformPatternMove{
            m_operandId,
            GetOperandId<AutomationRemoteDouble>(x),
            GetOperandId<AutomationRemoteDouble>(y)
        });
    }

    void AutomationRemoteTransformPattern::Resize(const winrt::AutomationRemoteDouble& width, const winrt::AutomationRemoteDouble& height)
    {
        m_parent->InsertInstruction(bytecode::TransformPatternResize{
            m_operandId,
            GetOperandId<AutomationRemoteDouble>(width),
            GetOperandId<AutomationRemoteDouble>(height)
        });
    }

    void AutomationRemoteTransformPattern::Rotate(const winrt::AutomationRemoteDouble& degrees)
    {
        m_parent->InsertInstruction(bytecode::TransformPatternRotate{
            m_operandId,
            GetOperandId<AutomationRemoteDouble>(degrees)
        });
    }

    AutomationRemoteScrollItemPattern::AutomationRemoteScrollItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteScrollItemPattern::Set(const AutomationRemoteScrollItemPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteScrollItemPattern>(rhs);
    }

    void AutomationRemoteScrollItemPattern::ScrollIntoView()
    {
        m_parent->InsertInstruction(bytecode::ScrollItemPatternScrollIntoView{
            m_operandId
        });
    }

    AutomationRemoteLegacyIAccessiblePattern::AutomationRemoteLegacyIAccessiblePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteLegacyIAccessiblePattern::Set(const AutomationRemoteLegacyIAccessiblePattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteLegacyIAccessiblePattern>(rhs);
    }

    winrt::AutomationRemoteInt AutomationRemoteLegacyIAccessiblePattern::GetChildId()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_LegacyIAccessibleChildIdPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteLegacyIAccessiblePattern::GetName()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_LegacyIAccessibleNamePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteLegacyIAccessiblePattern::GetValue()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_LegacyIAccessibleValuePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteLegacyIAccessiblePattern::GetDescription()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_LegacyIAccessibleDescriptionPropertyId);
    }

    winrt::AutomationRemoteUint AutomationRemoteLegacyIAccessiblePattern::GetRole()
    {
        return GetSpecificPropertyValue<AutomationRemoteUint>(UIA_LegacyIAccessibleRolePropertyId);
    }

    winrt::AutomationRemoteUint AutomationRemoteLegacyIAccessiblePattern::GetState()
    {
        return GetSpecificPropertyValue<AutomationRemoteUint>(UIA_LegacyIAccessibleStatePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteLegacyIAccessiblePattern::GetHelp()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_LegacyIAccessibleHelpPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteLegacyIAccessiblePattern::GetKeyboardShortcut()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_LegacyIAccessibleKeyboardShortcutPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteLegacyIAccessiblePattern::GetSelection()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_LegacyIAccessibleSelectionPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteLegacyIAccessiblePattern::GetDefaultAction()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_LegacyIAccessibleDefaultActionPropertyId);
    }

    void AutomationRemoteLegacyIAccessiblePattern::Select(const winrt::AutomationRemoteInt& flagsSelect)
    {
        m_parent->InsertInstruction(bytecode::LegacyIAccessiblePatternSelect{
            m_operandId,
            GetOperandId<AutomationRemoteInt>(flagsSelect)
        });
    }

    void AutomationRemoteLegacyIAccessiblePattern::DoDefaultAction()
    {
        m_parent->InsertInstruction(bytecode::LegacyIAccessiblePatternDoDefaultAction{
            m_operandId
        });
    }

    void AutomationRemoteLegacyIAccessiblePattern::SetValue(const winrt::AutomationRemoteString& szValue)
    {
        m_parent->InsertInstruction(bytecode::LegacyIAccessiblePatternSetValue{
            m_operandId,
            GetOperandId<AutomationRemoteString>(szValue)
        });
    }

    AutomationRemoteItemContainerPattern::AutomationRemoteItemContainerPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteItemContainerPattern::Set(const AutomationRemoteItemContainerPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteItemContainerPattern>(rhs);
    }

    winrt::AutomationRemoteElement AutomationRemoteItemContainerPattern::FindItemByProperty(const winrt::AutomationRemoteElement& pStartAfter, const winrt::AutomationRemotePropertyId& propertyId, const winrt::AutomationRemoteObject& value)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::ItemContainerPatternFindItemByProperty{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteElement>(pStartAfter),
            GetOperandId<AutomationRemotePropertyId>(propertyId),
            GetOperandId<AutomationRemoteObject>(value)
        });
        const auto result = Make<AutomationRemoteElement>(resultId);
        return result;
    }

    AutomationRemoteVirtualizedItemPattern::AutomationRemoteVirtualizedItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteVirtualizedItemPattern::Set(const AutomationRemoteVirtualizedItemPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteVirtualizedItemPattern>(rhs);
    }

    void AutomationRemoteVirtualizedItemPattern::Realize()
    {
        m_parent->InsertInstruction(bytecode::VirtualizedItemPatternRealize{
            m_operandId
        });
    }

    AutomationRemoteSynchronizedInputPattern::AutomationRemoteSynchronizedInputPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSynchronizedInputPattern::Set(const AutomationRemoteSynchronizedInputPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSynchronizedInputPattern>(rhs);
    }

    void AutomationRemoteSynchronizedInputPattern::StartListening(const winrt::AutomationRemoteSynchronizedInputType& inputType)
    {
        m_parent->InsertInstruction(bytecode::SynchronizedInputPatternStartListening{
            m_operandId,
            GetOperandId<AutomationRemoteSynchronizedInputType>(inputType)
        });
    }

    void AutomationRemoteSynchronizedInputPattern::Cancel()
    {
        m_parent->InsertInstruction(bytecode::SynchronizedInputPatternCancel{
            m_operandId
        });
    }

    AutomationRemoteAnnotationPattern::AutomationRemoteAnnotationPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteAnnotationPattern::Set(const AutomationRemoteAnnotationPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteAnnotationPattern>(rhs);
    }

    winrt::AutomationRemoteAnnotationType AutomationRemoteAnnotationPattern::GetAnnotationTypeId()
    {
        return GetSpecificPropertyValue<AutomationRemoteAnnotationType>(UIA_AnnotationAnnotationTypeIdPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteAnnotationPattern::GetAnnotationTypeName()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_AnnotationAnnotationTypeNamePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteAnnotationPattern::GetAuthor()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_AnnotationAuthorPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteAnnotationPattern::GetDateTime()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_AnnotationDateTimePropertyId);
    }

    winrt::AutomationRemoteElement AutomationRemoteAnnotationPattern::GetTarget()
    {
        return GetSpecificPropertyValue<AutomationRemoteElement>(UIA_AnnotationTargetPropertyId);
    }

    AutomationRemoteTextPattern2::AutomationRemoteTextPattern2(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextPattern2::Set(const AutomationRemoteTextPattern2::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextPattern2>(rhs);
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextPattern2::RangeFromAnnotation(const winrt::AutomationRemoteElement& annotation)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextPattern2RangeFromAnnotation{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteElement>(annotation)
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextPattern2::GetCaretRange(winrt::AutomationRemoteBool& isActive)
    {
        const auto resultId = m_parent->GetNextId();
        const auto isActiveId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextPattern2GetCaretRange{
            resultId,
            m_operandId,
            isActiveId
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        isActive = Make<AutomationRemoteBool>(isActiveId);
        return result;
    }

    AutomationRemoteStylesPattern::AutomationRemoteStylesPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteStylesPattern::Set(const AutomationRemoteStylesPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteStylesPattern>(rhs);
    }

    winrt::AutomationRemoteStyleId AutomationRemoteStylesPattern::GetStyleId()
    {
        return GetSpecificPropertyValue<AutomationRemoteStyleId>(UIA_StylesStyleIdPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteStylesPattern::GetStyleName()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_StylesStyleNamePropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteStylesPattern::GetFillColor()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_StylesFillColorPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteStylesPattern::GetFillPatternStyle()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_StylesFillPatternStylePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteStylesPattern::GetShape()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_StylesShapePropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteStylesPattern::GetFillPatternColor()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_StylesFillPatternColorPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteStylesPattern::GetExtendedProperties()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_StylesExtendedPropertiesPropertyId);
    }

    AutomationRemoteSpreadsheetPattern::AutomationRemoteSpreadsheetPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSpreadsheetPattern::Set(const AutomationRemoteSpreadsheetPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSpreadsheetPattern>(rhs);
    }

    winrt::AutomationRemoteElement AutomationRemoteSpreadsheetPattern::GetItemByName(const winrt::AutomationRemoteString& name)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::SpreadsheetPatternGetItemByName{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteString>(name)
        });
        const auto result = Make<AutomationRemoteElement>(resultId);
        return result;
    }

    AutomationRemoteSpreadsheetItemPattern::AutomationRemoteSpreadsheetItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSpreadsheetItemPattern::Set(const AutomationRemoteSpreadsheetItemPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSpreadsheetItemPattern>(rhs);
    }

    winrt::AutomationRemoteString AutomationRemoteSpreadsheetItemPattern::GetFormula()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_SpreadsheetItemFormulaPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteSpreadsheetItemPattern::GetAnnotationObjects()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_SpreadsheetItemAnnotationObjectsPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteSpreadsheetItemPattern::GetAnnotationTypes()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_SpreadsheetItemAnnotationTypesPropertyId);
    }

    AutomationRemoteTransformPattern2::AutomationRemoteTransformPattern2(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTransformPattern2::Set(const AutomationRemoteTransformPattern2::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTransformPattern2>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteTransformPattern2::GetCanZoom()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_Transform2CanZoomPropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteTransformPattern2::GetZoomLevel()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_Transform2ZoomLevelPropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteTransformPattern2::GetZoomMinimum()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_Transform2ZoomMinimumPropertyId);
    }

    winrt::AutomationRemoteDouble AutomationRemoteTransformPattern2::GetZoomMaximum()
    {
        return GetSpecificPropertyValue<AutomationRemoteDouble>(UIA_Transform2ZoomMaximumPropertyId);
    }

    void AutomationRemoteTransformPattern2::Zoom(const winrt::AutomationRemoteDouble& zoomValue)
    {
        m_parent->InsertInstruction(bytecode::TransformPattern2Zoom{
            m_operandId,
            GetOperandId<AutomationRemoteDouble>(zoomValue)
        });
    }

    void AutomationRemoteTransformPattern2::ZoomByUnit(const winrt::AutomationRemoteZoomUnit& ZoomUnit)
    {
        m_parent->InsertInstruction(bytecode::TransformPattern2ZoomByUnit{
            m_operandId,
            GetOperandId<AutomationRemoteZoomUnit>(ZoomUnit)
        });
    }

    AutomationRemoteTextChildPattern::AutomationRemoteTextChildPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextChildPattern::Set(const AutomationRemoteTextChildPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextChildPattern>(rhs);
    }

    winrt::AutomationRemoteElement AutomationRemoteTextChildPattern::GetTextContainer()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextChildPatternGetTextContainer{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteElement>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextChildPattern::GetTextRange()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextChildPatternGetTextRange{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    AutomationRemoteDragPattern::AutomationRemoteDragPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteDragPattern::Set(const AutomationRemoteDragPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteDragPattern>(rhs);
    }

    winrt::AutomationRemoteBool AutomationRemoteDragPattern::GetIsGrabbed()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_DragIsGrabbedPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteDragPattern::GetDropEffect()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_DragDropEffectPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteDragPattern::GetDropEffects()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_DragDropEffectsPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteDragPattern::GetGrabbedItems()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_DragGrabbedItemsPropertyId);
    }

    AutomationRemoteDropTargetPattern::AutomationRemoteDropTargetPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteDropTargetPattern::Set(const AutomationRemoteDropTargetPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteDropTargetPattern>(rhs);
    }

    winrt::AutomationRemoteString AutomationRemoteDropTargetPattern::GetDropTargetEffect()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_DropTargetDropTargetEffectPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteDropTargetPattern::GetDropTargetEffects()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_DropTargetDropTargetEffectsPropertyId);
    }

    AutomationRemoteTextEditPattern::AutomationRemoteTextEditPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteTextEditPattern::Set(const AutomationRemoteTextEditPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteTextEditPattern>(rhs);
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextEditPattern::GetActiveComposition()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextEditPatternGetActiveComposition{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextRange AutomationRemoteTextEditPattern::GetConversionTarget()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::TextEditPatternGetConversionTarget{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextRange>(resultId);
        return result;
    }

    AutomationRemoteCustomNavigationPattern::AutomationRemoteCustomNavigationPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteCustomNavigationPattern::Set(const AutomationRemoteCustomNavigationPattern::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteCustomNavigationPattern>(rhs);
    }

    winrt::AutomationRemoteElement AutomationRemoteCustomNavigationPattern::Navigate(const winrt::AutomationRemoteNavigateDirection& direction)
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::CustomNavigationPatternNavigate{
            resultId,
            m_operandId,
            GetOperandId<AutomationRemoteNavigateDirection>(direction)
        });
        const auto result = Make<AutomationRemoteElement>(resultId);
        return result;
    }

    AutomationRemoteSelectionPattern2::AutomationRemoteSelectionPattern2(bytecode::OperandId operandId, AutomationRemoteOperation& parent)
        : base_type(operandId, parent)
    {
    }

    void AutomationRemoteSelectionPattern2::Set(const AutomationRemoteSelectionPattern2::class_type& rhs)
    {
        AutomationRemoteObject::Set<AutomationRemoteSelectionPattern2>(rhs);
    }

    winrt::AutomationRemoteElement AutomationRemoteSelectionPattern2::GetFirstSelectedItem()
    {
        return GetSpecificPropertyValue<AutomationRemoteElement>(UIA_Selection2FirstSelectedItemPropertyId);
    }

    winrt::AutomationRemoteElement AutomationRemoteSelectionPattern2::GetLastSelectedItem()
    {
        return GetSpecificPropertyValue<AutomationRemoteElement>(UIA_Selection2LastSelectedItemPropertyId);
    }

    winrt::AutomationRemoteElement AutomationRemoteSelectionPattern2::GetCurrentSelectedItem()
    {
        return GetSpecificPropertyValue<AutomationRemoteElement>(UIA_Selection2CurrentSelectedItemPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteSelectionPattern2::GetItemCount()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_Selection2ItemCountPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteElement::GetProcessId()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_ProcessIdPropertyId);
    }

    winrt::AutomationRemoteControlType AutomationRemoteElement::GetControlType()
    {
        return GetSpecificPropertyValue<AutomationRemoteControlType>(UIA_ControlTypePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetLocalizedControlType()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_LocalizedControlTypePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetName()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_NamePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetAcceleratorKey()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_AcceleratorKeyPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetAccessKey()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_AccessKeyPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetHasKeyboardFocus()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_HasKeyboardFocusPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsKeyboardFocusable()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsKeyboardFocusablePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsEnabled()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsEnabledPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetAutomationId()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_AutomationIdPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetClassName()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_ClassNamePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetHelpText()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_HelpTextPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteElement::GetCulture()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_CulturePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsControlElement()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsControlElementPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsContentElement()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsContentElementPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsPassword()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsPasswordPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteElement::GetNativeWindowHandle()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_NativeWindowHandlePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetItemType()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_ItemTypePropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsOffscreen()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsOffscreenPropertyId);
    }

    winrt::AutomationRemoteOrientationType AutomationRemoteElement::GetOrientation()
    {
        return GetSpecificPropertyValue<AutomationRemoteOrientationType>(UIA_OrientationPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetFrameworkId()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_FrameworkIdPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsRequiredForForm()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsRequiredForFormPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetItemStatus()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_ItemStatusPropertyId);
    }

    winrt::AutomationRemoteRect AutomationRemoteElement::GetBoundingRectangle()
    {
        return GetSpecificPropertyValue<AutomationRemoteRect>(UIA_BoundingRectanglePropertyId);
    }

    winrt::AutomationRemoteElement AutomationRemoteElement::GetLabeledBy()
    {
        return GetSpecificPropertyValue<AutomationRemoteElement>(UIA_LabeledByPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetAriaRole()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_AriaRolePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetAriaProperties()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_AriaPropertiesPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsDataValidForForm()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsDataValidForFormPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteElement::GetControllerFor()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_ControllerForPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteElement::GetDescribedBy()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_DescribedByPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteElement::GetFlowsTo()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_FlowsToPropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetProviderDescription()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_ProviderDescriptionPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetOptimizeForVisualContent()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_OptimizeForVisualContentPropertyId);
    }

    winrt::AutomationRemoteLiveSetting AutomationRemoteElement::GetLiveSetting()
    {
        return GetSpecificPropertyValue<AutomationRemoteLiveSetting>(UIA_LiveSettingPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteElement::GetFlowsFrom()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_FlowsFromPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsPeripheral()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsPeripheralPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteElement::GetPositionInSet()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_PositionInSetPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteElement::GetSizeOfSet()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_SizeOfSetPropertyId);
    }

    winrt::AutomationRemoteInt AutomationRemoteElement::GetLevel()
    {
        return GetSpecificPropertyValue<AutomationRemoteInt>(UIA_LevelPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteElement::GetAnnotationTypes()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_AnnotationTypesPropertyId);
    }

    winrt::AutomationRemoteArray AutomationRemoteElement::GetAnnotationObjects()
    {
        return GetSpecificPropertyValue<AutomationRemoteArray>(UIA_AnnotationObjectsPropertyId);
    }

    winrt::AutomationRemoteLandmarkType AutomationRemoteElement::GetLandmarkType()
    {
        return GetSpecificPropertyValue<AutomationRemoteLandmarkType>(UIA_LandmarkTypePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetLocalizedLandmarkType()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_LocalizedLandmarkTypePropertyId);
    }

    winrt::AutomationRemoteString AutomationRemoteElement::GetFullDescription()
    {
        return GetSpecificPropertyValue<AutomationRemoteString>(UIA_FullDescriptionPropertyId);
    }

    winrt::AutomationRemoteHeadingLevel AutomationRemoteElement::GetHeadingLevel()
    {
        return GetSpecificPropertyValue<AutomationRemoteHeadingLevel>(UIA_HeadingLevelPropertyId);
    }

    winrt::AutomationRemoteBool AutomationRemoteElement::GetIsDialog()
    {
        return GetSpecificPropertyValue<AutomationRemoteBool>(UIA_IsDialogPropertyId);
    }

    winrt::AutomationRemoteInvokePattern AutomationRemoteElement::GetInvokePattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetInvokePattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteInvokePattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteSelectionPattern AutomationRemoteElement::GetSelectionPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetSelectionPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteSelectionPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteValuePattern AutomationRemoteElement::GetValuePattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetValuePattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteValuePattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteRangeValuePattern AutomationRemoteElement::GetRangeValuePattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetRangeValuePattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteRangeValuePattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteScrollPattern AutomationRemoteElement::GetScrollPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetScrollPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteScrollPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteExpandCollapsePattern AutomationRemoteElement::GetExpandCollapsePattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetExpandCollapsePattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteExpandCollapsePattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteGridPattern AutomationRemoteElement::GetGridPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetGridPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteGridPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteGridItemPattern AutomationRemoteElement::GetGridItemPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetGridItemPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteGridItemPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteMultipleViewPattern AutomationRemoteElement::GetMultipleViewPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetMultipleViewPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteMultipleViewPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteWindowPattern AutomationRemoteElement::GetWindowPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetWindowPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteWindowPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteSelectionItemPattern AutomationRemoteElement::GetSelectionItemPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetSelectionItemPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteSelectionItemPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteDockPattern AutomationRemoteElement::GetDockPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetDockPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteDockPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteTablePattern AutomationRemoteElement::GetTablePattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTablePattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTablePattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteTableItemPattern AutomationRemoteElement::GetTableItemPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTableItemPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTableItemPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextPattern AutomationRemoteElement::GetTextPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTextPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteTogglePattern AutomationRemoteElement::GetTogglePattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTogglePattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTogglePattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteTransformPattern AutomationRemoteElement::GetTransformPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTransformPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTransformPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteScrollItemPattern AutomationRemoteElement::GetScrollItemPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetScrollItemPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteScrollItemPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteLegacyIAccessiblePattern AutomationRemoteElement::GetLegacyIAccessiblePattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetLegacyIAccessiblePattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteLegacyIAccessiblePattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteItemContainerPattern AutomationRemoteElement::GetItemContainerPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetItemContainerPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteItemContainerPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteVirtualizedItemPattern AutomationRemoteElement::GetVirtualizedItemPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetVirtualizedItemPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteVirtualizedItemPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteSynchronizedInputPattern AutomationRemoteElement::GetSynchronizedInputPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetSynchronizedInputPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteSynchronizedInputPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteAnnotationPattern AutomationRemoteElement::GetAnnotationPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetAnnotationPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteAnnotationPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextPattern2 AutomationRemoteElement::GetTextPattern2()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTextPattern2{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextPattern2>(resultId);
        return result;
    }

    winrt::AutomationRemoteStylesPattern AutomationRemoteElement::GetStylesPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetStylesPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteStylesPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteSpreadsheetPattern AutomationRemoteElement::GetSpreadsheetPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetSpreadsheetPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteSpreadsheetPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteSpreadsheetItemPattern AutomationRemoteElement::GetSpreadsheetItemPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetSpreadsheetItemPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteSpreadsheetItemPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteTransformPattern2 AutomationRemoteElement::GetTransformPattern2()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTransformPattern2{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTransformPattern2>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextChildPattern AutomationRemoteElement::GetTextChildPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTextChildPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextChildPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteDragPattern AutomationRemoteElement::GetDragPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetDragPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteDragPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteDropTargetPattern AutomationRemoteElement::GetDropTargetPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetDropTargetPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteDropTargetPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteTextEditPattern AutomationRemoteElement::GetTextEditPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetTextEditPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteTextEditPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteCustomNavigationPattern AutomationRemoteElement::GetCustomNavigationPattern()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetCustomNavigationPattern{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteCustomNavigationPattern>(resultId);
        return result;
    }

    winrt::AutomationRemoteSelectionPattern2 AutomationRemoteElement::GetSelectionPattern2()
    {
        const auto resultId = m_parent->GetNextId();
        m_parent->InsertInstruction(bytecode::GetSelectionPattern2{
            resultId,
            m_operandId
        });
        const auto result = Make<AutomationRemoteSelectionPattern2>(resultId);
        return result;
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsInvokePattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteInvokePattern AutomationRemoteAnyObject::AsInvokePattern()
    {
        return As<AutomationRemoteInvokePattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsSelectionPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteSelectionPattern AutomationRemoteAnyObject::AsSelectionPattern()
    {
        return As<AutomationRemoteSelectionPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsValuePattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteValuePattern AutomationRemoteAnyObject::AsValuePattern()
    {
        return As<AutomationRemoteValuePattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsRangeValuePattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteRangeValuePattern AutomationRemoteAnyObject::AsRangeValuePattern()
    {
        return As<AutomationRemoteRangeValuePattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsScrollPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteScrollPattern AutomationRemoteAnyObject::AsScrollPattern()
    {
        return As<AutomationRemoteScrollPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsExpandCollapsePattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteExpandCollapsePattern AutomationRemoteAnyObject::AsExpandCollapsePattern()
    {
        return As<AutomationRemoteExpandCollapsePattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsGridPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteGridPattern AutomationRemoteAnyObject::AsGridPattern()
    {
        return As<AutomationRemoteGridPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsGridItemPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteGridItemPattern AutomationRemoteAnyObject::AsGridItemPattern()
    {
        return As<AutomationRemoteGridItemPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsMultipleViewPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteMultipleViewPattern AutomationRemoteAnyObject::AsMultipleViewPattern()
    {
        return As<AutomationRemoteMultipleViewPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsWindowPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteWindowPattern AutomationRemoteAnyObject::AsWindowPattern()
    {
        return As<AutomationRemoteWindowPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsSelectionItemPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteSelectionItemPattern AutomationRemoteAnyObject::AsSelectionItemPattern()
    {
        return As<AutomationRemoteSelectionItemPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsDockPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteDockPattern AutomationRemoteAnyObject::AsDockPattern()
    {
        return As<AutomationRemoteDockPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTablePattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTablePattern AutomationRemoteAnyObject::AsTablePattern()
    {
        return As<AutomationRemoteTablePattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTableItemPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTableItemPattern AutomationRemoteAnyObject::AsTableItemPattern()
    {
        return As<AutomationRemoteTableItemPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTextPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTextPattern AutomationRemoteAnyObject::AsTextPattern()
    {
        return As<AutomationRemoteTextPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTextRange()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTextRange AutomationRemoteAnyObject::AsTextRange()
    {
        return As<AutomationRemoteTextRange>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTogglePattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTogglePattern AutomationRemoteAnyObject::AsTogglePattern()
    {
        return As<AutomationRemoteTogglePattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTransformPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTransformPattern AutomationRemoteAnyObject::AsTransformPattern()
    {
        return As<AutomationRemoteTransformPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsScrollItemPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteScrollItemPattern AutomationRemoteAnyObject::AsScrollItemPattern()
    {
        return As<AutomationRemoteScrollItemPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsLegacyIAccessiblePattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteLegacyIAccessiblePattern AutomationRemoteAnyObject::AsLegacyIAccessiblePattern()
    {
        return As<AutomationRemoteLegacyIAccessiblePattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsItemContainerPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteItemContainerPattern AutomationRemoteAnyObject::AsItemContainerPattern()
    {
        return As<AutomationRemoteItemContainerPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsVirtualizedItemPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteVirtualizedItemPattern AutomationRemoteAnyObject::AsVirtualizedItemPattern()
    {
        return As<AutomationRemoteVirtualizedItemPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsSynchronizedInputPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteSynchronizedInputPattern AutomationRemoteAnyObject::AsSynchronizedInputPattern()
    {
        return As<AutomationRemoteSynchronizedInputPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsAnnotationPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteAnnotationPattern AutomationRemoteAnyObject::AsAnnotationPattern()
    {
        return As<AutomationRemoteAnnotationPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTextPattern2()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTextPattern2 AutomationRemoteAnyObject::AsTextPattern2()
    {
        return As<AutomationRemoteTextPattern2>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsStylesPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteStylesPattern AutomationRemoteAnyObject::AsStylesPattern()
    {
        return As<AutomationRemoteStylesPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsSpreadsheetPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteSpreadsheetPattern AutomationRemoteAnyObject::AsSpreadsheetPattern()
    {
        return As<AutomationRemoteSpreadsheetPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsSpreadsheetItemPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteSpreadsheetItemPattern AutomationRemoteAnyObject::AsSpreadsheetItemPattern()
    {
        return As<AutomationRemoteSpreadsheetItemPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTransformPattern2()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTransformPattern2 AutomationRemoteAnyObject::AsTransformPattern2()
    {
        return As<AutomationRemoteTransformPattern2>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTextChildPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTextChildPattern AutomationRemoteAnyObject::AsTextChildPattern()
    {
        return As<AutomationRemoteTextChildPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsDragPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteDragPattern AutomationRemoteAnyObject::AsDragPattern()
    {
        return As<AutomationRemoteDragPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsDropTargetPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteDropTargetPattern AutomationRemoteAnyObject::AsDropTargetPattern()
    {
        return As<AutomationRemoteDropTargetPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsTextEditPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteTextEditPattern AutomationRemoteAnyObject::AsTextEditPattern()
    {
        return As<AutomationRemoteTextEditPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsCustomNavigationPattern()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteCustomNavigationPattern AutomationRemoteAnyObject::AsCustomNavigationPattern()
    {
        return As<AutomationRemoteCustomNavigationPattern>();
    }

    winrt::AutomationRemoteBool AutomationRemoteAnyObject::IsSelectionPattern2()
    {
        throw hresult_not_implemented();
    }

    winrt::AutomationRemoteSelectionPattern2 AutomationRemoteAnyObject::AsSelectionPattern2()
    {
        return As<AutomationRemoteSelectionPattern2>();
    }

    winrt::AutomationRemoteActiveEnd AutomationRemoteAnyObject::AsActiveEnd()
    {
        return As<AutomationRemoteActiveEnd>();
    }

    winrt::AutomationRemoteAnimationStyle AutomationRemoteAnyObject::AsAnimationStyle()
    {
        return As<AutomationRemoteAnimationStyle>();
    }

    winrt::AutomationRemoteAnnotationType AutomationRemoteAnyObject::AsAnnotationType()
    {
        return As<AutomationRemoteAnnotationType>();
    }

    winrt::AutomationRemoteBulletStyle AutomationRemoteAnyObject::AsBulletStyle()
    {
        return As<AutomationRemoteBulletStyle>();
    }

    winrt::AutomationRemoteCapStyle AutomationRemoteAnyObject::AsCapStyle()
    {
        return As<AutomationRemoteCapStyle>();
    }

    winrt::AutomationRemoteCaretBidiMode AutomationRemoteAnyObject::AsCaretBidiMode()
    {
        return As<AutomationRemoteCaretBidiMode>();
    }

    winrt::AutomationRemoteCaretPosition AutomationRemoteAnyObject::AsCaretPosition()
    {
        return As<AutomationRemoteCaretPosition>();
    }

    winrt::AutomationRemoteControlType AutomationRemoteAnyObject::AsControlType()
    {
        return As<AutomationRemoteControlType>();
    }

    winrt::AutomationRemoteDockPosition AutomationRemoteAnyObject::AsDockPosition()
    {
        return As<AutomationRemoteDockPosition>();
    }

    winrt::AutomationRemoteExpandCollapseState AutomationRemoteAnyObject::AsExpandCollapseState()
    {
        return As<AutomationRemoteExpandCollapseState>();
    }

    winrt::AutomationRemoteFlowDirections AutomationRemoteAnyObject::AsFlowDirections()
    {
        return As<AutomationRemoteFlowDirections>();
    }

    winrt::AutomationRemoteHeadingLevel AutomationRemoteAnyObject::AsHeadingLevel()
    {
        return As<AutomationRemoteHeadingLevel>();
    }

    winrt::AutomationRemoteHorizontalTextAlignment AutomationRemoteAnyObject::AsHorizontalTextAlignment()
    {
        return As<AutomationRemoteHorizontalTextAlignment>();
    }

    winrt::AutomationRemoteLandmarkType AutomationRemoteAnyObject::AsLandmarkType()
    {
        return As<AutomationRemoteLandmarkType>();
    }

    winrt::AutomationRemoteLiveSetting AutomationRemoteAnyObject::AsLiveSetting()
    {
        return As<AutomationRemoteLiveSetting>();
    }

    winrt::AutomationRemoteNavigateDirection AutomationRemoteAnyObject::AsNavigateDirection()
    {
        return As<AutomationRemoteNavigateDirection>();
    }

    winrt::AutomationRemoteOrientationType AutomationRemoteAnyObject::AsOrientationType()
    {
        return As<AutomationRemoteOrientationType>();
    }

    winrt::AutomationRemoteOutlineStyles AutomationRemoteAnyObject::AsOutlineStyles()
    {
        return As<AutomationRemoteOutlineStyles>();
    }

    winrt::AutomationRemotePatternId AutomationRemoteAnyObject::AsPatternId()
    {
        return As<AutomationRemotePatternId>();
    }

    winrt::AutomationRemotePropertyId AutomationRemoteAnyObject::AsPropertyId()
    {
        return As<AutomationRemotePropertyId>();
    }

    winrt::AutomationRemoteRowOrColumnMajor AutomationRemoteAnyObject::AsRowOrColumnMajor()
    {
        return As<AutomationRemoteRowOrColumnMajor>();
    }

    winrt::AutomationRemoteSayAsInterpretAs AutomationRemoteAnyObject::AsSayAsInterpretAs()
    {
        return As<AutomationRemoteSayAsInterpretAs>();
    }

    winrt::AutomationRemoteScrollAmount AutomationRemoteAnyObject::AsScrollAmount()
    {
        return As<AutomationRemoteScrollAmount>();
    }

    winrt::AutomationRemoteStyleId AutomationRemoteAnyObject::AsStyleId()
    {
        return As<AutomationRemoteStyleId>();
    }

    winrt::AutomationRemoteSupportedTextSelection AutomationRemoteAnyObject::AsSupportedTextSelection()
    {
        return As<AutomationRemoteSupportedTextSelection>();
    }

    winrt::AutomationRemoteSynchronizedInputType AutomationRemoteAnyObject::AsSynchronizedInputType()
    {
        return As<AutomationRemoteSynchronizedInputType>();
    }

    winrt::AutomationRemoteTextAttributeId AutomationRemoteAnyObject::AsTextAttributeId()
    {
        return As<AutomationRemoteTextAttributeId>();
    }

    winrt::AutomationRemoteTextDecorationLineStyle AutomationRemoteAnyObject::AsTextDecorationLineStyle()
    {
        return As<AutomationRemoteTextDecorationLineStyle>();
    }

    winrt::AutomationRemoteTextPatternRangeEndpoint AutomationRemoteAnyObject::AsTextPatternRangeEndpoint()
    {
        return As<AutomationRemoteTextPatternRangeEndpoint>();
    }

    winrt::AutomationRemoteTextUnit AutomationRemoteAnyObject::AsTextUnit()
    {
        return As<AutomationRemoteTextUnit>();
    }

    winrt::AutomationRemoteToggleState AutomationRemoteAnyObject::AsToggleState()
    {
        return As<AutomationRemoteToggleState>();
    }

    winrt::AutomationRemoteWindowInteractionState AutomationRemoteAnyObject::AsWindowInteractionState()
    {
        return As<AutomationRemoteWindowInteractionState>();
    }

    winrt::AutomationRemoteWindowVisualState AutomationRemoteAnyObject::AsWindowVisualState()
    {
        return As<AutomationRemoteWindowVisualState>();
    }

    winrt::AutomationRemoteZoomUnit AutomationRemoteAnyObject::AsZoomUnit()
    {
        return As<AutomationRemoteZoomUnit>();
    }
}
