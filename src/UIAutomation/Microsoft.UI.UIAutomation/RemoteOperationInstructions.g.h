// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// WARNING: Please don't edit this file. It was generated.

#pragma once

struct GetInvokePattern : GetterBase
{
    constexpr static auto type = InstructionType::GetInvokePattern;
};

struct GetSelectionPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetSelectionPattern;
};

struct GetValuePattern : GetterBase
{
    constexpr static auto type = InstructionType::GetValuePattern;
};

struct GetRangeValuePattern : GetterBase
{
    constexpr static auto type = InstructionType::GetRangeValuePattern;
};

struct GetScrollPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetScrollPattern;
};

struct GetExpandCollapsePattern : GetterBase
{
    constexpr static auto type = InstructionType::GetExpandCollapsePattern;
};

struct GetGridPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetGridPattern;
};

struct GetGridItemPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetGridItemPattern;
};

struct GetMultipleViewPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetMultipleViewPattern;
};

struct GetWindowPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetWindowPattern;
};

struct GetSelectionItemPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetSelectionItemPattern;
};

struct GetDockPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetDockPattern;
};

struct GetTablePattern : GetterBase
{
    constexpr static auto type = InstructionType::GetTablePattern;
};

struct GetTableItemPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetTableItemPattern;
};

struct GetTextPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetTextPattern;
};

struct GetTogglePattern : GetterBase
{
    constexpr static auto type = InstructionType::GetTogglePattern;
};

struct GetTransformPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetTransformPattern;
};

struct GetScrollItemPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetScrollItemPattern;
};

struct GetLegacyIAccessiblePattern : GetterBase
{
    constexpr static auto type = InstructionType::GetLegacyIAccessiblePattern;
};

struct GetItemContainerPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetItemContainerPattern;
};

struct GetVirtualizedItemPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetVirtualizedItemPattern;
};

struct GetSynchronizedInputPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetSynchronizedInputPattern;
};

struct GetAnnotationPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetAnnotationPattern;
};

struct GetTextPattern2 : GetterBase
{
    constexpr static auto type = InstructionType::GetTextPattern2;
};

struct GetStylesPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetStylesPattern;
};

struct GetSpreadsheetPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetSpreadsheetPattern;
};

struct GetSpreadsheetItemPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetSpreadsheetItemPattern;
};

struct GetTransformPattern2 : GetterBase
{
    constexpr static auto type = InstructionType::GetTransformPattern2;
};

struct GetTextChildPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetTextChildPattern;
};

struct GetDragPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetDragPattern;
};

struct GetDropTargetPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetDropTargetPattern;
};

struct GetTextEditPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetTextEditPattern;
};

struct GetCustomNavigationPattern : GetterBase
{
    constexpr static auto type = InstructionType::GetCustomNavigationPattern;
};

struct GetSelectionPattern2 : GetterBase
{
    constexpr static auto type = InstructionType::GetSelectionPattern2;
};

struct InvokePatternInvoke
{
    constexpr static auto type = InstructionType::InvokePatternInvoke;

    OperandId targetId;
};

struct ValuePatternSetValue
{
    constexpr static auto type = InstructionType::ValuePatternSetValue;

    OperandId targetId;
    OperandId valId;
};

struct RangeValuePatternSetValue
{
    constexpr static auto type = InstructionType::RangeValuePatternSetValue;

    OperandId targetId;
    OperandId valId;
};

struct ScrollPatternScroll
{
    constexpr static auto type = InstructionType::ScrollPatternScroll;

    OperandId targetId;
    OperandId horizontalAmountId;
    OperandId verticalAmountId;
};

struct ScrollPatternSetScrollPercent
{
    constexpr static auto type = InstructionType::ScrollPatternSetScrollPercent;

    OperandId targetId;
    OperandId horizontalPercentId;
    OperandId verticalPercentId;
};

struct ExpandCollapsePatternExpand
{
    constexpr static auto type = InstructionType::ExpandCollapsePatternExpand;

    OperandId targetId;
};

struct ExpandCollapsePatternCollapse
{
    constexpr static auto type = InstructionType::ExpandCollapsePatternCollapse;

    OperandId targetId;
};

struct GridPatternGetItem
{
    constexpr static auto type = InstructionType::GridPatternGetItem;

    OperandId resultId;
    OperandId targetId;
    OperandId rowId;
    OperandId columnId;
};

struct MultipleViewPatternGetViewName
{
    constexpr static auto type = InstructionType::MultipleViewPatternGetViewName;

    OperandId resultId;
    OperandId targetId;
    OperandId viewId;
};

struct MultipleViewPatternSetCurrentView
{
    constexpr static auto type = InstructionType::MultipleViewPatternSetCurrentView;

    OperandId targetId;
    OperandId viewId;
};

struct WindowPatternClose
{
    constexpr static auto type = InstructionType::WindowPatternClose;

    OperandId targetId;
};

struct WindowPatternWaitForInputIdle
{
    constexpr static auto type = InstructionType::WindowPatternWaitForInputIdle;

    OperandId resultId;
    OperandId targetId;
    OperandId millisecondsId;
};

struct WindowPatternSetWindowVisualState
{
    constexpr static auto type = InstructionType::WindowPatternSetWindowVisualState;

    OperandId targetId;
    OperandId stateId;
};

struct SelectionItemPatternSelect
{
    constexpr static auto type = InstructionType::SelectionItemPatternSelect;

    OperandId targetId;
};

struct SelectionItemPatternAddToSelection
{
    constexpr static auto type = InstructionType::SelectionItemPatternAddToSelection;

    OperandId targetId;
};

struct SelectionItemPatternRemoveFromSelection
{
    constexpr static auto type = InstructionType::SelectionItemPatternRemoveFromSelection;

    OperandId targetId;
};

struct DockPatternSetDockPosition
{
    constexpr static auto type = InstructionType::DockPatternSetDockPosition;

    OperandId targetId;
    OperandId dockPosId;
};

struct TextPatternRangeFromPoint
{
    constexpr static auto type = InstructionType::TextPatternRangeFromPoint;

    OperandId resultId;
    OperandId targetId;
    OperandId ptId;
};

struct TextPatternRangeFromChild
{
    constexpr static auto type = InstructionType::TextPatternRangeFromChild;

    OperandId resultId;
    OperandId targetId;
    OperandId childId;
};

struct TextPatternGetSelection
{
    constexpr static auto type = InstructionType::TextPatternGetSelection;

    OperandId resultId;
    OperandId targetId;
};

struct TextPatternGetVisibleRanges
{
    constexpr static auto type = InstructionType::TextPatternGetVisibleRanges;

    OperandId resultId;
    OperandId targetId;
};

struct TextPatternGetDocumentRange
{
    constexpr static auto type = InstructionType::TextPatternGetDocumentRange;

    OperandId resultId;
    OperandId targetId;
};

struct TextPatternGetSupportedTextSelection
{
    constexpr static auto type = InstructionType::TextPatternGetSupportedTextSelection;

    OperandId resultId;
    OperandId targetId;
};

struct TextRangeClone
{
    constexpr static auto type = InstructionType::TextRangeClone;

    OperandId resultId;
    OperandId targetId;
};

struct TextRangeCompare
{
    constexpr static auto type = InstructionType::TextRangeCompare;

    OperandId resultId;
    OperandId targetId;
    OperandId rangeId;
};

struct TextRangeCompareEndpoints
{
    constexpr static auto type = InstructionType::TextRangeCompareEndpoints;

    OperandId resultId;
    OperandId targetId;
    OperandId srcEndPointId;
    OperandId rangeId;
    OperandId targetEndPointId;
};

struct TextRangeExpandToEnclosingUnit
{
    constexpr static auto type = InstructionType::TextRangeExpandToEnclosingUnit;

    OperandId targetId;
    OperandId TextUnitId;
};

struct TextRangeFindAttribute
{
    constexpr static auto type = InstructionType::TextRangeFindAttribute;

    OperandId resultId;
    OperandId targetId;
    OperandId attrId;
    OperandId valId;
    OperandId backwardId;
};

struct TextRangeFindText
{
    constexpr static auto type = InstructionType::TextRangeFindText;

    OperandId resultId;
    OperandId targetId;
    OperandId textId;
    OperandId backwardId;
    OperandId ignoreCaseId;
};

struct TextRangeGetAttributeValue
{
    constexpr static auto type = InstructionType::TextRangeGetAttributeValue;

    OperandId resultId;
    OperandId targetId;
    OperandId attrId;
};

struct TextRangeGetBoundingRectangles
{
    constexpr static auto type = InstructionType::TextRangeGetBoundingRectangles;

    OperandId resultId;
    OperandId targetId;
};

struct TextRangeGetEnclosingElement
{
    constexpr static auto type = InstructionType::TextRangeGetEnclosingElement;

    OperandId resultId;
    OperandId targetId;
};

struct TextRangeGetText
{
    constexpr static auto type = InstructionType::TextRangeGetText;

    OperandId resultId;
    OperandId targetId;
    OperandId maxLengthId;
};

struct TextRangeMove
{
    constexpr static auto type = InstructionType::TextRangeMove;

    OperandId resultId;
    OperandId targetId;
    OperandId unitId;
    OperandId countId;
};

struct TextRangeMoveEndpointByUnit
{
    constexpr static auto type = InstructionType::TextRangeMoveEndpointByUnit;

    OperandId resultId;
    OperandId targetId;
    OperandId endpointId;
    OperandId unitId;
    OperandId countId;
};

struct TextRangeMoveEndpointByRange
{
    constexpr static auto type = InstructionType::TextRangeMoveEndpointByRange;

    OperandId targetId;
    OperandId srcEndPointId;
    OperandId rangeId;
    OperandId targetEndPointId;
};

struct TextRangeSelect
{
    constexpr static auto type = InstructionType::TextRangeSelect;

    OperandId targetId;
};

struct TextRangeAddToSelection
{
    constexpr static auto type = InstructionType::TextRangeAddToSelection;

    OperandId targetId;
};

struct TextRangeRemoveFromSelection
{
    constexpr static auto type = InstructionType::TextRangeRemoveFromSelection;

    OperandId targetId;
};

struct TextRangeScrollIntoView
{
    constexpr static auto type = InstructionType::TextRangeScrollIntoView;

    OperandId targetId;
    OperandId alignToTopId;
};

struct TextRangeGetChildren
{
    constexpr static auto type = InstructionType::TextRangeGetChildren;

    OperandId resultId;
    OperandId targetId;
};

struct TextRangeShowContextMenu
{
    constexpr static auto type = InstructionType::TextRangeShowContextMenu;

    OperandId targetId;
};

struct TogglePatternToggle
{
    constexpr static auto type = InstructionType::TogglePatternToggle;

    OperandId targetId;
};

struct TransformPatternMove
{
    constexpr static auto type = InstructionType::TransformPatternMove;

    OperandId targetId;
    OperandId xId;
    OperandId yId;
};

struct TransformPatternResize
{
    constexpr static auto type = InstructionType::TransformPatternResize;

    OperandId targetId;
    OperandId widthId;
    OperandId heightId;
};

struct TransformPatternRotate
{
    constexpr static auto type = InstructionType::TransformPatternRotate;

    OperandId targetId;
    OperandId degreesId;
};

struct ScrollItemPatternScrollIntoView
{
    constexpr static auto type = InstructionType::ScrollItemPatternScrollIntoView;

    OperandId targetId;
};

struct LegacyIAccessiblePatternSelect
{
    constexpr static auto type = InstructionType::LegacyIAccessiblePatternSelect;

    OperandId targetId;
    OperandId flagsSelectId;
};

struct LegacyIAccessiblePatternDoDefaultAction
{
    constexpr static auto type = InstructionType::LegacyIAccessiblePatternDoDefaultAction;

    OperandId targetId;
};

struct LegacyIAccessiblePatternSetValue
{
    constexpr static auto type = InstructionType::LegacyIAccessiblePatternSetValue;

    OperandId targetId;
    OperandId szValueId;
};

struct ItemContainerPatternFindItemByProperty
{
    constexpr static auto type = InstructionType::ItemContainerPatternFindItemByProperty;

    OperandId resultId;
    OperandId targetId;
    OperandId pStartAfterId;
    OperandId propertyIdId;
    OperandId valueId;
};

struct VirtualizedItemPatternRealize
{
    constexpr static auto type = InstructionType::VirtualizedItemPatternRealize;

    OperandId targetId;
};

struct SynchronizedInputPatternStartListening
{
    constexpr static auto type = InstructionType::SynchronizedInputPatternStartListening;

    OperandId targetId;
    OperandId inputTypeId;
};

struct SynchronizedInputPatternCancel
{
    constexpr static auto type = InstructionType::SynchronizedInputPatternCancel;

    OperandId targetId;
};

struct TextPattern2RangeFromAnnotation
{
    constexpr static auto type = InstructionType::TextPattern2RangeFromAnnotation;

    OperandId resultId;
    OperandId targetId;
    OperandId annotationId;
};

struct TextPattern2GetCaretRange
{
    constexpr static auto type = InstructionType::TextPattern2GetCaretRange;

    OperandId resultId;
    OperandId targetId;
    OperandId isActiveId;
};

struct SpreadsheetPatternGetItemByName
{
    constexpr static auto type = InstructionType::SpreadsheetPatternGetItemByName;

    OperandId resultId;
    OperandId targetId;
    OperandId nameId;
};

struct TransformPattern2Zoom
{
    constexpr static auto type = InstructionType::TransformPattern2Zoom;

    OperandId targetId;
    OperandId zoomValueId;
};

struct TransformPattern2ZoomByUnit
{
    constexpr static auto type = InstructionType::TransformPattern2ZoomByUnit;

    OperandId targetId;
    OperandId ZoomUnitId;
};

struct TextChildPatternGetTextContainer
{
    constexpr static auto type = InstructionType::TextChildPatternGetTextContainer;

    OperandId resultId;
    OperandId targetId;
};

struct TextChildPatternGetTextRange
{
    constexpr static auto type = InstructionType::TextChildPatternGetTextRange;

    OperandId resultId;
    OperandId targetId;
};

struct TextEditPatternGetActiveComposition
{
    constexpr static auto type = InstructionType::TextEditPatternGetActiveComposition;

    OperandId resultId;
    OperandId targetId;
};

struct TextEditPatternGetConversionTarget
{
    constexpr static auto type = InstructionType::TextEditPatternGetConversionTarget;

    OperandId resultId;
    OperandId targetId;
};

struct CustomNavigationPatternNavigate
{
    constexpr static auto type = InstructionType::CustomNavigationPatternNavigate;

    OperandId resultId;
    OperandId targetId;
    OperandId directionId;
};
