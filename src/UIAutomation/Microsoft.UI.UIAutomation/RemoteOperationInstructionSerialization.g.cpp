// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// WARNING: Please don't edit this file. It was generated.

#include "pch.h"
#include "RemoteOperationInstructionSerialization.h"

using namespace bytecode;

void RemoteOperationInstructionSerializer::Write(const InvokePatternInvoke& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const ValuePatternSetValue& instruction)
{
    Write(instruction.targetId);
    Write(instruction.valId);
}

void RemoteOperationInstructionSerializer::Write(const RangeValuePatternSetValue& instruction)
{
    Write(instruction.targetId);
    Write(instruction.valId);
}

void RemoteOperationInstructionSerializer::Write(const ScrollPatternScroll& instruction)
{
    Write(instruction.targetId);
    Write(instruction.horizontalAmountId);
    Write(instruction.verticalAmountId);
}

void RemoteOperationInstructionSerializer::Write(const ScrollPatternSetScrollPercent& instruction)
{
    Write(instruction.targetId);
    Write(instruction.horizontalPercentId);
    Write(instruction.verticalPercentId);
}

void RemoteOperationInstructionSerializer::Write(const ExpandCollapsePatternExpand& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const ExpandCollapsePatternCollapse& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const GridPatternGetItem& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.rowId);
    Write(instruction.columnId);
}

void RemoteOperationInstructionSerializer::Write(const MultipleViewPatternGetViewName& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.viewId);
}

void RemoteOperationInstructionSerializer::Write(const MultipleViewPatternSetCurrentView& instruction)
{
    Write(instruction.targetId);
    Write(instruction.viewId);
}

void RemoteOperationInstructionSerializer::Write(const WindowPatternClose& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const WindowPatternWaitForInputIdle& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.millisecondsId);
}

void RemoteOperationInstructionSerializer::Write(const WindowPatternSetWindowVisualState& instruction)
{
    Write(instruction.targetId);
    Write(instruction.stateId);
}

void RemoteOperationInstructionSerializer::Write(const SelectionItemPatternSelect& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const SelectionItemPatternAddToSelection& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const SelectionItemPatternRemoveFromSelection& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const DockPatternSetDockPosition& instruction)
{
    Write(instruction.targetId);
    Write(instruction.dockPosId);
}

void RemoteOperationInstructionSerializer::Write(const TextPatternRangeFromPoint& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.ptId);
}

void RemoteOperationInstructionSerializer::Write(const TextPatternRangeFromChild& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.childId);
}

void RemoteOperationInstructionSerializer::Write(const TextPatternGetSelection& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextPatternGetVisibleRanges& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextPatternGetDocumentRange& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextPatternGetSupportedTextSelection& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeClone& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeCompare& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.rangeId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeCompareEndpoints& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.srcEndPointId);
    Write(instruction.rangeId);
    Write(instruction.targetEndPointId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeExpandToEnclosingUnit& instruction)
{
    Write(instruction.targetId);
    Write(instruction.TextUnitId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeFindAttribute& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.attrId);
    Write(instruction.valId);
    Write(instruction.backwardId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeFindText& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.textId);
    Write(instruction.backwardId);
    Write(instruction.ignoreCaseId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeGetAttributeValue& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.attrId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeGetBoundingRectangles& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeGetEnclosingElement& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeGetText& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.maxLengthId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeMove& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.unitId);
    Write(instruction.countId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeMoveEndpointByUnit& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.endpointId);
    Write(instruction.unitId);
    Write(instruction.countId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeMoveEndpointByRange& instruction)
{
    Write(instruction.targetId);
    Write(instruction.srcEndPointId);
    Write(instruction.rangeId);
    Write(instruction.targetEndPointId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeSelect& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeAddToSelection& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeRemoveFromSelection& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeScrollIntoView& instruction)
{
    Write(instruction.targetId);
    Write(instruction.alignToTopId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeGetChildren& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextRangeShowContextMenu& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TogglePatternToggle& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TransformPatternMove& instruction)
{
    Write(instruction.targetId);
    Write(instruction.xId);
    Write(instruction.yId);
}

void RemoteOperationInstructionSerializer::Write(const TransformPatternResize& instruction)
{
    Write(instruction.targetId);
    Write(instruction.widthId);
    Write(instruction.heightId);
}

void RemoteOperationInstructionSerializer::Write(const TransformPatternRotate& instruction)
{
    Write(instruction.targetId);
    Write(instruction.degreesId);
}

void RemoteOperationInstructionSerializer::Write(const ScrollItemPatternScrollIntoView& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const LegacyIAccessiblePatternSelect& instruction)
{
    Write(instruction.targetId);
    Write(instruction.flagsSelectId);
}

void RemoteOperationInstructionSerializer::Write(const LegacyIAccessiblePatternDoDefaultAction& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const LegacyIAccessiblePatternSetValue& instruction)
{
    Write(instruction.targetId);
    Write(instruction.szValueId);
}

void RemoteOperationInstructionSerializer::Write(const ItemContainerPatternFindItemByProperty& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.pStartAfterId);
    Write(instruction.propertyIdId);
    Write(instruction.valueId);
}

void RemoteOperationInstructionSerializer::Write(const VirtualizedItemPatternRealize& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const SynchronizedInputPatternStartListening& instruction)
{
    Write(instruction.targetId);
    Write(instruction.inputTypeId);
}

void RemoteOperationInstructionSerializer::Write(const SynchronizedInputPatternCancel& instruction)
{
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextPattern2RangeFromAnnotation& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.annotationId);
}

void RemoteOperationInstructionSerializer::Write(const TextPattern2GetCaretRange& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.isActiveId);
}

void RemoteOperationInstructionSerializer::Write(const SpreadsheetPatternGetItemByName& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.nameId);
}

void RemoteOperationInstructionSerializer::Write(const TransformPattern2Zoom& instruction)
{
    Write(instruction.targetId);
    Write(instruction.zoomValueId);
}

void RemoteOperationInstructionSerializer::Write(const TransformPattern2ZoomByUnit& instruction)
{
    Write(instruction.targetId);
    Write(instruction.ZoomUnitId);
}

void RemoteOperationInstructionSerializer::Write(const TextChildPatternGetTextContainer& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextChildPatternGetTextRange& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextEditPatternGetActiveComposition& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const TextEditPatternGetConversionTarget& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const CustomNavigationPatternNavigate& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.directionId);
}

