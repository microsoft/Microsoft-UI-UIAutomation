// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// WARNING: Please don't edit this file. It was generated.

#pragma once

#include "AutomationRemoteActiveEnd.g.h"
#include "AutomationRemoteAnimationStyle.g.h"
#include "AutomationRemoteAnnotationType.g.h"
#include "AutomationRemoteBulletStyle.g.h"
#include "AutomationRemoteCapStyle.g.h"
#include "AutomationRemoteCaretBidiMode.g.h"
#include "AutomationRemoteCaretPosition.g.h"
#include "AutomationRemoteControlType.g.h"
#include "AutomationRemoteDockPosition.g.h"
#include "AutomationRemoteExpandCollapseState.g.h"
#include "AutomationRemoteFlowDirections.g.h"
#include "AutomationRemoteHeadingLevel.g.h"
#include "AutomationRemoteHorizontalTextAlignment.g.h"
#include "AutomationRemoteLandmarkType.g.h"
#include "AutomationRemoteLiveSetting.g.h"
#include "AutomationRemoteNavigateDirection.g.h"
#include "AutomationRemoteOrientationType.g.h"
#include "AutomationRemoteOutlineStyles.g.h"
#include "AutomationRemotePatternId.g.h"
#include "AutomationRemotePropertyId.g.h"
#include "AutomationRemoteRowOrColumnMajor.g.h"
#include "AutomationRemoteSayAsInterpretAs.g.h"
#include "AutomationRemoteScrollAmount.g.h"
#include "AutomationRemoteStyleId.g.h"
#include "AutomationRemoteSupportedTextSelection.g.h"
#include "AutomationRemoteSynchronizedInputType.g.h"
#include "AutomationRemoteTextAttributeId.g.h"
#include "AutomationRemoteTextDecorationLineStyle.g.h"
#include "AutomationRemoteTextPatternRangeEndpoint.g.h"
#include "AutomationRemoteTextUnit.g.h"
#include "AutomationRemoteToggleState.g.h"
#include "AutomationRemoteWindowInteractionState.g.h"
#include "AutomationRemoteWindowVisualState.g.h"
#include "AutomationRemoteZoomUnit.g.h"
#include "AutomationRemoteInvokePattern.g.h"
#include "AutomationRemoteSelectionPattern.g.h"
#include "AutomationRemoteValuePattern.g.h"
#include "AutomationRemoteRangeValuePattern.g.h"
#include "AutomationRemoteScrollPattern.g.h"
#include "AutomationRemoteExpandCollapsePattern.g.h"
#include "AutomationRemoteGridPattern.g.h"
#include "AutomationRemoteGridItemPattern.g.h"
#include "AutomationRemoteMultipleViewPattern.g.h"
#include "AutomationRemoteWindowPattern.g.h"
#include "AutomationRemoteSelectionItemPattern.g.h"
#include "AutomationRemoteDockPattern.g.h"
#include "AutomationRemoteTablePattern.g.h"
#include "AutomationRemoteTableItemPattern.g.h"
#include "AutomationRemoteTextPattern.g.h"
#include "AutomationRemoteTextRange.g.h"
#include "AutomationRemoteTogglePattern.g.h"
#include "AutomationRemoteTransformPattern.g.h"
#include "AutomationRemoteScrollItemPattern.g.h"
#include "AutomationRemoteLegacyIAccessiblePattern.g.h"
#include "AutomationRemoteItemContainerPattern.g.h"
#include "AutomationRemoteVirtualizedItemPattern.g.h"
#include "AutomationRemoteSynchronizedInputPattern.g.h"
#include "AutomationRemoteAnnotationPattern.g.h"
#include "AutomationRemoteTextPattern2.g.h"
#include "AutomationRemoteStylesPattern.g.h"
#include "AutomationRemoteSpreadsheetPattern.g.h"
#include "AutomationRemoteSpreadsheetItemPattern.g.h"
#include "AutomationRemoteTransformPattern2.g.h"
#include "AutomationRemoteTextChildPattern.g.h"
#include "AutomationRemoteDragPattern.g.h"
#include "AutomationRemoteDropTargetPattern.g.h"
#include "AutomationRemoteTextEditPattern.g.h"
#include "AutomationRemoteCustomNavigationPattern.g.h"
#include "AutomationRemoteSelectionPattern2.g.h"

namespace winrt
{
    using namespace winrt::Microsoft::UI::UIAutomation;
}

namespace winrt::Microsoft::UI::UIAutomation::implementation
{
    class AutomationRemoteActiveEnd : public AutomationRemoteActiveEndT<AutomationRemoteActiveEnd, AutomationRemoteObject>
    {
    public:
        AutomationRemoteActiveEnd(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteAnimationStyle : public AutomationRemoteAnimationStyleT<AutomationRemoteAnimationStyle, AutomationRemoteObject>
    {
    public:
        AutomationRemoteAnimationStyle(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteAnnotationType : public AutomationRemoteAnnotationTypeT<AutomationRemoteAnnotationType, AutomationRemoteObject>
    {
    public:
        AutomationRemoteAnnotationType(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
        winrt::AutomationRemoteGuid LookupGuid();
    };

    class AutomationRemoteBulletStyle : public AutomationRemoteBulletStyleT<AutomationRemoteBulletStyle, AutomationRemoteObject>
    {
    public:
        AutomationRemoteBulletStyle(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteCapStyle : public AutomationRemoteCapStyleT<AutomationRemoteCapStyle, AutomationRemoteObject>
    {
    public:
        AutomationRemoteCapStyle(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteCaretBidiMode : public AutomationRemoteCaretBidiModeT<AutomationRemoteCaretBidiMode, AutomationRemoteObject>
    {
    public:
        AutomationRemoteCaretBidiMode(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteCaretPosition : public AutomationRemoteCaretPositionT<AutomationRemoteCaretPosition, AutomationRemoteObject>
    {
    public:
        AutomationRemoteCaretPosition(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteControlType : public AutomationRemoteControlTypeT<AutomationRemoteControlType, AutomationRemoteObject>
    {
    public:
        AutomationRemoteControlType(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteDockPosition : public AutomationRemoteDockPositionT<AutomationRemoteDockPosition, AutomationRemoteObject>
    {
    public:
        AutomationRemoteDockPosition(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteExpandCollapseState : public AutomationRemoteExpandCollapseStateT<AutomationRemoteExpandCollapseState, AutomationRemoteObject>
    {
    public:
        AutomationRemoteExpandCollapseState(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteFlowDirections : public AutomationRemoteFlowDirectionsT<AutomationRemoteFlowDirections, AutomationRemoteObject>
    {
    public:
        AutomationRemoteFlowDirections(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteHeadingLevel : public AutomationRemoteHeadingLevelT<AutomationRemoteHeadingLevel, AutomationRemoteObject>
    {
    public:
        AutomationRemoteHeadingLevel(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteHorizontalTextAlignment : public AutomationRemoteHorizontalTextAlignmentT<AutomationRemoteHorizontalTextAlignment, AutomationRemoteObject>
    {
    public:
        AutomationRemoteHorizontalTextAlignment(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteLandmarkType : public AutomationRemoteLandmarkTypeT<AutomationRemoteLandmarkType, AutomationRemoteObject>
    {
    public:
        AutomationRemoteLandmarkType(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteLiveSetting : public AutomationRemoteLiveSettingT<AutomationRemoteLiveSetting, AutomationRemoteObject>
    {
    public:
        AutomationRemoteLiveSetting(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteNavigateDirection : public AutomationRemoteNavigateDirectionT<AutomationRemoteNavigateDirection, AutomationRemoteObject>
    {
    public:
        AutomationRemoteNavigateDirection(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteOrientationType : public AutomationRemoteOrientationTypeT<AutomationRemoteOrientationType, AutomationRemoteObject>
    {
    public:
        AutomationRemoteOrientationType(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteOutlineStyles : public AutomationRemoteOutlineStylesT<AutomationRemoteOutlineStyles, AutomationRemoteObject>
    {
    public:
        AutomationRemoteOutlineStyles(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemotePatternId : public AutomationRemotePatternIdT<AutomationRemotePatternId, AutomationRemoteObject>
    {
    public:
        AutomationRemotePatternId(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemotePropertyId : public AutomationRemotePropertyIdT<AutomationRemotePropertyId, AutomationRemoteObject>
    {
    public:
        AutomationRemotePropertyId(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
        winrt::AutomationRemoteGuid LookupGuid();
    };

    class AutomationRemoteRowOrColumnMajor : public AutomationRemoteRowOrColumnMajorT<AutomationRemoteRowOrColumnMajor, AutomationRemoteObject>
    {
    public:
        AutomationRemoteRowOrColumnMajor(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteSayAsInterpretAs : public AutomationRemoteSayAsInterpretAsT<AutomationRemoteSayAsInterpretAs, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSayAsInterpretAs(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteScrollAmount : public AutomationRemoteScrollAmountT<AutomationRemoteScrollAmount, AutomationRemoteObject>
    {
    public:
        AutomationRemoteScrollAmount(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteStyleId : public AutomationRemoteStyleIdT<AutomationRemoteStyleId, AutomationRemoteObject>
    {
    public:
        AutomationRemoteStyleId(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteSupportedTextSelection : public AutomationRemoteSupportedTextSelectionT<AutomationRemoteSupportedTextSelection, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSupportedTextSelection(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteSynchronizedInputType : public AutomationRemoteSynchronizedInputTypeT<AutomationRemoteSynchronizedInputType, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSynchronizedInputType(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteTextAttributeId : public AutomationRemoteTextAttributeIdT<AutomationRemoteTextAttributeId, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextAttributeId(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteTextDecorationLineStyle : public AutomationRemoteTextDecorationLineStyleT<AutomationRemoteTextDecorationLineStyle, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextDecorationLineStyle(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteTextPatternRangeEndpoint : public AutomationRemoteTextPatternRangeEndpointT<AutomationRemoteTextPatternRangeEndpoint, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextPatternRangeEndpoint(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteTextUnit : public AutomationRemoteTextUnitT<AutomationRemoteTextUnit, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextUnit(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteToggleState : public AutomationRemoteToggleStateT<AutomationRemoteToggleState, AutomationRemoteObject>
    {
    public:
        AutomationRemoteToggleState(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteWindowInteractionState : public AutomationRemoteWindowInteractionStateT<AutomationRemoteWindowInteractionState, AutomationRemoteObject>
    {
    public:
        AutomationRemoteWindowInteractionState(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteWindowVisualState : public AutomationRemoteWindowVisualStateT<AutomationRemoteWindowVisualState, AutomationRemoteObject>
    {
    public:
        AutomationRemoteWindowVisualState(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteZoomUnit : public AutomationRemoteZoomUnitT<AutomationRemoteZoomUnit, AutomationRemoteObject>
    {
    public:
        AutomationRemoteZoomUnit(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool IsEqual(const class_type& rhs);
        winrt::AutomationRemoteBool IsNotEqual(const class_type& rhs);
    };

    class AutomationRemoteInvokePattern : public AutomationRemoteInvokePatternT<AutomationRemoteInvokePattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteInvokePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        void Invoke();
    };

    class AutomationRemoteSelectionPattern : public AutomationRemoteSelectionPatternT<AutomationRemoteSelectionPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSelectionPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteArray GetSelection();
        winrt::AutomationRemoteBool GetCanSelectMultiple();
        winrt::AutomationRemoteBool GetIsSelectionRequired();
    };

    class AutomationRemoteValuePattern : public AutomationRemoteValuePatternT<AutomationRemoteValuePattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteValuePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteString GetValue();
        winrt::AutomationRemoteBool GetIsReadOnly();
        void SetValue(const winrt::AutomationRemoteString& val);
    };

    class AutomationRemoteRangeValuePattern : public AutomationRemoteRangeValuePatternT<AutomationRemoteRangeValuePattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteRangeValuePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteDouble GetValue();
        winrt::AutomationRemoteBool GetIsReadOnly();
        winrt::AutomationRemoteDouble GetMaximum();
        winrt::AutomationRemoteDouble GetMinimum();
        winrt::AutomationRemoteDouble GetLargeChange();
        winrt::AutomationRemoteDouble GetSmallChange();
        void SetValue(const winrt::AutomationRemoteDouble& val);
    };

    class AutomationRemoteScrollPattern : public AutomationRemoteScrollPatternT<AutomationRemoteScrollPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteScrollPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteDouble GetHorizontalScrollPercent();
        winrt::AutomationRemoteDouble GetVerticalScrollPercent();
        winrt::AutomationRemoteDouble GetHorizontalViewSize();
        winrt::AutomationRemoteDouble GetVerticalViewSize();
        winrt::AutomationRemoteBool GetHorizontallyScrollable();
        winrt::AutomationRemoteBool GetVerticallyScrollable();
        void Scroll(const winrt::AutomationRemoteScrollAmount& horizontalAmount, const winrt::AutomationRemoteScrollAmount& verticalAmount);
        void SetScrollPercent(const winrt::AutomationRemoteDouble& horizontalPercent, const winrt::AutomationRemoteDouble& verticalPercent);
    };

    class AutomationRemoteExpandCollapsePattern : public AutomationRemoteExpandCollapsePatternT<AutomationRemoteExpandCollapsePattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteExpandCollapsePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteExpandCollapseState GetExpandCollapseState();
        void Expand();
        void Collapse();
    };

    class AutomationRemoteGridPattern : public AutomationRemoteGridPatternT<AutomationRemoteGridPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteGridPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteInt GetRowCount();
        winrt::AutomationRemoteInt GetColumnCount();
        winrt::AutomationRemoteElement GetItem(const winrt::AutomationRemoteInt& row, const winrt::AutomationRemoteInt& column);
    };

    class AutomationRemoteGridItemPattern : public AutomationRemoteGridItemPatternT<AutomationRemoteGridItemPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteGridItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteElement GetContainingGrid();
        winrt::AutomationRemoteInt GetRow();
        winrt::AutomationRemoteInt GetColumn();
        winrt::AutomationRemoteInt GetRowSpan();
        winrt::AutomationRemoteInt GetColumnSpan();
    };

    class AutomationRemoteMultipleViewPattern : public AutomationRemoteMultipleViewPatternT<AutomationRemoteMultipleViewPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteMultipleViewPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteInt GetCurrentView();
        winrt::AutomationRemoteArray GetSupportedViews();
        winrt::AutomationRemoteString GetViewName(const winrt::AutomationRemoteInt& view);
        void SetCurrentView(const winrt::AutomationRemoteInt& view);
    };

    class AutomationRemoteWindowPattern : public AutomationRemoteWindowPatternT<AutomationRemoteWindowPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteWindowPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool GetCanMaximize();
        winrt::AutomationRemoteBool GetCanMinimize();
        winrt::AutomationRemoteBool GetIsModal();
        winrt::AutomationRemoteBool GetIsTopmost();
        winrt::AutomationRemoteWindowVisualState GetWindowVisualState();
        winrt::AutomationRemoteWindowInteractionState GetWindowInteractionState();
        void Close();
        winrt::AutomationRemoteBool WaitForInputIdle(const winrt::AutomationRemoteInt& milliseconds);
        void SetWindowVisualState(const winrt::AutomationRemoteWindowVisualState& state);
    };

    class AutomationRemoteSelectionItemPattern : public AutomationRemoteSelectionItemPatternT<AutomationRemoteSelectionItemPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSelectionItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool GetIsSelected();
        winrt::AutomationRemoteElement GetSelectionContainer();
        void Select();
        void AddToSelection();
        void RemoveFromSelection();
    };

    class AutomationRemoteDockPattern : public AutomationRemoteDockPatternT<AutomationRemoteDockPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteDockPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteDockPosition GetDockPosition();
        void SetDockPosition(const winrt::AutomationRemoteDockPosition& dockPos);
    };

    class AutomationRemoteTablePattern : public AutomationRemoteTablePatternT<AutomationRemoteTablePattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTablePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteArray GetRowHeaders();
        winrt::AutomationRemoteArray GetColumnHeaders();
        winrt::AutomationRemoteRowOrColumnMajor GetRowOrColumnMajor();
    };

    class AutomationRemoteTableItemPattern : public AutomationRemoteTableItemPatternT<AutomationRemoteTableItemPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTableItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteArray GetRowHeaderItems();
        winrt::AutomationRemoteArray GetColumnHeaderItems();
    };

    class AutomationRemoteTextPattern : public AutomationRemoteTextPatternT<AutomationRemoteTextPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteTextRange RangeFromPoint(const winrt::AutomationRemotePoint& pt);
        winrt::AutomationRemoteTextRange RangeFromChild(const winrt::AutomationRemoteElement& child);
        winrt::AutomationRemoteArray GetSelection();
        winrt::AutomationRemoteArray GetVisibleRanges();
        winrt::AutomationRemoteTextRange GetDocumentRange();
        winrt::AutomationRemoteSupportedTextSelection GetSupportedTextSelection();
    };

    class AutomationRemoteTextRange : public AutomationRemoteTextRangeT<AutomationRemoteTextRange, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextRange(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteTextRange Clone();
        winrt::AutomationRemoteBool Compare(const winrt::AutomationRemoteTextRange& range);
        winrt::AutomationRemoteInt CompareEndpoints(const winrt::AutomationRemoteTextPatternRangeEndpoint& srcEndPoint, const winrt::AutomationRemoteTextRange& range, const winrt::AutomationRemoteTextPatternRangeEndpoint& targetEndPoint);
        void ExpandToEnclosingUnit(const winrt::AutomationRemoteTextUnit& TextUnit);
        winrt::AutomationRemoteTextRange FindAttribute(const winrt::AutomationRemoteTextAttributeId& attr, const winrt::AutomationRemoteObject& val, const winrt::AutomationRemoteBool& backward);
        winrt::AutomationRemoteTextRange FindText(const winrt::AutomationRemoteString& text, const winrt::AutomationRemoteBool& backward, const winrt::AutomationRemoteBool& ignoreCase);
        winrt::AutomationRemoteAnyObject GetAttributeValue(const winrt::AutomationRemoteTextAttributeId& attr);
        winrt::AutomationRemoteArray GetBoundingRectangles();
        winrt::AutomationRemoteElement GetEnclosingElement();
        winrt::AutomationRemoteString GetText(const winrt::AutomationRemoteInt& maxLength);
        winrt::AutomationRemoteInt Move(const winrt::AutomationRemoteTextUnit& unit, const winrt::AutomationRemoteInt& count);
        winrt::AutomationRemoteInt MoveEndpointByUnit(const winrt::AutomationRemoteTextPatternRangeEndpoint& endpoint, const winrt::AutomationRemoteTextUnit& unit, const winrt::AutomationRemoteInt& count);
        void MoveEndpointByRange(const winrt::AutomationRemoteTextPatternRangeEndpoint& srcEndPoint, const winrt::AutomationRemoteTextRange& range, const winrt::AutomationRemoteTextPatternRangeEndpoint& targetEndPoint);
        void Select();
        void AddToSelection();
        void RemoveFromSelection();
        void ScrollIntoView(const winrt::AutomationRemoteBool& alignToTop);
        winrt::AutomationRemoteArray GetChildren();
        void ShowContextMenu();
    };

    class AutomationRemoteTogglePattern : public AutomationRemoteTogglePatternT<AutomationRemoteTogglePattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTogglePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteToggleState GetToggleState();
        void Toggle();
    };

    class AutomationRemoteTransformPattern : public AutomationRemoteTransformPatternT<AutomationRemoteTransformPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTransformPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool GetCanMove();
        winrt::AutomationRemoteBool GetCanResize();
        winrt::AutomationRemoteBool GetCanRotate();
        void Move(const winrt::AutomationRemoteDouble& x, const winrt::AutomationRemoteDouble& y);
        void Resize(const winrt::AutomationRemoteDouble& width, const winrt::AutomationRemoteDouble& height);
        void Rotate(const winrt::AutomationRemoteDouble& degrees);
    };

    class AutomationRemoteScrollItemPattern : public AutomationRemoteScrollItemPatternT<AutomationRemoteScrollItemPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteScrollItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        void ScrollIntoView();
    };

    class AutomationRemoteLegacyIAccessiblePattern : public AutomationRemoteLegacyIAccessiblePatternT<AutomationRemoteLegacyIAccessiblePattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteLegacyIAccessiblePattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteInt GetChildId();
        winrt::AutomationRemoteString GetName();
        winrt::AutomationRemoteString GetValue();
        winrt::AutomationRemoteString GetDescription();
        winrt::AutomationRemoteUint GetRole();
        winrt::AutomationRemoteUint GetState();
        winrt::AutomationRemoteString GetHelp();
        winrt::AutomationRemoteString GetKeyboardShortcut();
        winrt::AutomationRemoteArray GetSelection();
        winrt::AutomationRemoteString GetDefaultAction();
        void Select(const winrt::AutomationRemoteInt& flagsSelect);
        void DoDefaultAction();
        void SetValue(const winrt::AutomationRemoteString& szValue);
    };

    class AutomationRemoteItemContainerPattern : public AutomationRemoteItemContainerPatternT<AutomationRemoteItemContainerPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteItemContainerPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteElement FindItemByProperty(const winrt::AutomationRemoteElement& pStartAfter, const winrt::AutomationRemotePropertyId& propertyId, const winrt::AutomationRemoteObject& value);
    };

    class AutomationRemoteVirtualizedItemPattern : public AutomationRemoteVirtualizedItemPatternT<AutomationRemoteVirtualizedItemPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteVirtualizedItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        void Realize();
    };

    class AutomationRemoteSynchronizedInputPattern : public AutomationRemoteSynchronizedInputPatternT<AutomationRemoteSynchronizedInputPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSynchronizedInputPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        void StartListening(const winrt::AutomationRemoteSynchronizedInputType& inputType);
        void Cancel();
    };

    class AutomationRemoteAnnotationPattern : public AutomationRemoteAnnotationPatternT<AutomationRemoteAnnotationPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteAnnotationPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteAnnotationType GetAnnotationTypeId();
        winrt::AutomationRemoteString GetAnnotationTypeName();
        winrt::AutomationRemoteString GetAuthor();
        winrt::AutomationRemoteString GetDateTime();
        winrt::AutomationRemoteElement GetTarget();
    };

    class AutomationRemoteTextPattern2 : public AutomationRemoteTextPattern2T<AutomationRemoteTextPattern2, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextPattern2(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteTextRange RangeFromAnnotation(const winrt::AutomationRemoteElement& annotation);
        winrt::AutomationRemoteTextRange GetCaretRange(winrt::AutomationRemoteBool& isActive);
    };

    class AutomationRemoteStylesPattern : public AutomationRemoteStylesPatternT<AutomationRemoteStylesPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteStylesPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteStyleId GetStyleId();
        winrt::AutomationRemoteString GetStyleName();
        winrt::AutomationRemoteInt GetFillColor();
        winrt::AutomationRemoteString GetFillPatternStyle();
        winrt::AutomationRemoteString GetShape();
        winrt::AutomationRemoteInt GetFillPatternColor();
        winrt::AutomationRemoteString GetExtendedProperties();
    };

    class AutomationRemoteSpreadsheetPattern : public AutomationRemoteSpreadsheetPatternT<AutomationRemoteSpreadsheetPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSpreadsheetPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteElement GetItemByName(const winrt::AutomationRemoteString& name);
    };

    class AutomationRemoteSpreadsheetItemPattern : public AutomationRemoteSpreadsheetItemPatternT<AutomationRemoteSpreadsheetItemPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSpreadsheetItemPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteString GetFormula();
        winrt::AutomationRemoteArray GetAnnotationObjects();
        winrt::AutomationRemoteArray GetAnnotationTypes();
    };

    class AutomationRemoteTransformPattern2 : public AutomationRemoteTransformPattern2T<AutomationRemoteTransformPattern2, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTransformPattern2(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool GetCanZoom();
        winrt::AutomationRemoteDouble GetZoomLevel();
        winrt::AutomationRemoteDouble GetZoomMinimum();
        winrt::AutomationRemoteDouble GetZoomMaximum();
        void Zoom(const winrt::AutomationRemoteDouble& zoomValue);
        void ZoomByUnit(const winrt::AutomationRemoteZoomUnit& ZoomUnit);
    };

    class AutomationRemoteTextChildPattern : public AutomationRemoteTextChildPatternT<AutomationRemoteTextChildPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextChildPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteElement GetTextContainer();
        winrt::AutomationRemoteTextRange GetTextRange();
    };

    class AutomationRemoteDragPattern : public AutomationRemoteDragPatternT<AutomationRemoteDragPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteDragPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteBool GetIsGrabbed();
        winrt::AutomationRemoteString GetDropEffect();
        winrt::AutomationRemoteArray GetDropEffects();
        winrt::AutomationRemoteArray GetGrabbedItems();
    };

    class AutomationRemoteDropTargetPattern : public AutomationRemoteDropTargetPatternT<AutomationRemoteDropTargetPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteDropTargetPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteString GetDropTargetEffect();
        winrt::AutomationRemoteArray GetDropTargetEffects();
    };

    class AutomationRemoteTextEditPattern : public AutomationRemoteTextEditPatternT<AutomationRemoteTextEditPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteTextEditPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteTextRange GetActiveComposition();
        winrt::AutomationRemoteTextRange GetConversionTarget();
    };

    class AutomationRemoteCustomNavigationPattern : public AutomationRemoteCustomNavigationPatternT<AutomationRemoteCustomNavigationPattern, AutomationRemoteObject>
    {
    public:
        AutomationRemoteCustomNavigationPattern(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteElement Navigate(const winrt::AutomationRemoteNavigateDirection& direction);
    };

    class AutomationRemoteSelectionPattern2 : public AutomationRemoteSelectionPattern2T<AutomationRemoteSelectionPattern2, AutomationRemoteObject>
    {
    public:
        AutomationRemoteSelectionPattern2(bytecode::OperandId operandId, AutomationRemoteOperation& parent);
        void Set(const class_type& rhs);
        winrt::AutomationRemoteElement GetFirstSelectedItem();
        winrt::AutomationRemoteElement GetLastSelectedItem();
        winrt::AutomationRemoteElement GetCurrentSelectedItem();
        winrt::AutomationRemoteInt GetItemCount();
    };
}
