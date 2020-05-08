// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// WARNING: Please don't edit this file. It was generated.

#pragma once

    GetInvokePattern = MakePatternGetterInstructionType(UIA_InvokePatternId),
    GetSelectionPattern = MakePatternGetterInstructionType(UIA_SelectionPatternId),
    GetValuePattern = MakePatternGetterInstructionType(UIA_ValuePatternId),
    GetRangeValuePattern = MakePatternGetterInstructionType(UIA_RangeValuePatternId),
    GetScrollPattern = MakePatternGetterInstructionType(UIA_ScrollPatternId),
    GetExpandCollapsePattern = MakePatternGetterInstructionType(UIA_ExpandCollapsePatternId),
    GetGridPattern = MakePatternGetterInstructionType(UIA_GridPatternId),
    GetGridItemPattern = MakePatternGetterInstructionType(UIA_GridItemPatternId),
    GetMultipleViewPattern = MakePatternGetterInstructionType(UIA_MultipleViewPatternId),
    GetWindowPattern = MakePatternGetterInstructionType(UIA_WindowPatternId),
    GetSelectionItemPattern = MakePatternGetterInstructionType(UIA_SelectionItemPatternId),
    GetDockPattern = MakePatternGetterInstructionType(UIA_DockPatternId),
    GetTablePattern = MakePatternGetterInstructionType(UIA_TablePatternId),
    GetTableItemPattern = MakePatternGetterInstructionType(UIA_TableItemPatternId),
    GetTextPattern = MakePatternGetterInstructionType(UIA_TextPatternId),
    GetTogglePattern = MakePatternGetterInstructionType(UIA_TogglePatternId),
    GetTransformPattern = MakePatternGetterInstructionType(UIA_TransformPatternId),
    GetScrollItemPattern = MakePatternGetterInstructionType(UIA_ScrollItemPatternId),
    GetLegacyIAccessiblePattern = MakePatternGetterInstructionType(UIA_LegacyIAccessiblePatternId),
    GetItemContainerPattern = MakePatternGetterInstructionType(UIA_ItemContainerPatternId),
    GetVirtualizedItemPattern = MakePatternGetterInstructionType(UIA_VirtualizedItemPatternId),
    GetSynchronizedInputPattern = MakePatternGetterInstructionType(UIA_SynchronizedInputPatternId),
    GetAnnotationPattern = MakePatternGetterInstructionType(UIA_AnnotationPatternId),
    GetTextPattern2 = MakePatternGetterInstructionType(UIA_TextPattern2Id),
    GetStylesPattern = MakePatternGetterInstructionType(UIA_StylesPatternId),
    GetSpreadsheetPattern = MakePatternGetterInstructionType(UIA_SpreadsheetPatternId),
    GetSpreadsheetItemPattern = MakePatternGetterInstructionType(UIA_SpreadsheetItemPatternId),
    GetTransformPattern2 = MakePatternGetterInstructionType(UIA_TransformPattern2Id),
    GetTextChildPattern = MakePatternGetterInstructionType(UIA_TextChildPatternId),
    GetDragPattern = MakePatternGetterInstructionType(UIA_DragPatternId),
    GetDropTargetPattern = MakePatternGetterInstructionType(UIA_DropTargetPatternId),
    GetTextEditPattern = MakePatternGetterInstructionType(UIA_TextEditPatternId),
    GetCustomNavigationPattern = MakePatternGetterInstructionType(UIA_CustomNavigationPatternId),
    GetSelectionPattern2 = MakePatternGetterInstructionType(UIA_SelectionPattern2Id),
    InvokePatternInvoke = MakePatternMethodInstructionType(
        UIA_InvokePatternId,
        3 /* clientVtableIndex */),
    ValuePatternSetValue = MakePatternMethodInstructionType(
        UIA_ValuePatternId,
        3 /* clientVtableIndex */),
    RangeValuePatternSetValue = MakePatternMethodInstructionType(
        UIA_RangeValuePatternId,
        3 /* clientVtableIndex */),
    ScrollPatternScroll = MakePatternMethodInstructionType(
        UIA_ScrollPatternId,
        3 /* clientVtableIndex */),
    ScrollPatternSetScrollPercent = MakePatternMethodInstructionType(
        UIA_ScrollPatternId,
        4 /* clientVtableIndex */),
    ExpandCollapsePatternExpand = MakePatternMethodInstructionType(
        UIA_ExpandCollapsePatternId,
        3 /* clientVtableIndex */),
    ExpandCollapsePatternCollapse = MakePatternMethodInstructionType(
        UIA_ExpandCollapsePatternId,
        4 /* clientVtableIndex */),
    GridPatternGetItem = MakePatternMethodInstructionType(
        UIA_GridPatternId,
        3 /* clientVtableIndex */),
    MultipleViewPatternGetViewName = MakePatternMethodInstructionType(
        UIA_MultipleViewPatternId,
        3 /* clientVtableIndex */),
    MultipleViewPatternSetCurrentView = MakePatternMethodInstructionType(
        UIA_MultipleViewPatternId,
        4 /* clientVtableIndex */),
    WindowPatternClose = MakePatternMethodInstructionType(
        UIA_WindowPatternId,
        3 /* clientVtableIndex */),
    WindowPatternWaitForInputIdle = MakePatternMethodInstructionType(
        UIA_WindowPatternId,
        4 /* clientVtableIndex */),
    WindowPatternSetWindowVisualState = MakePatternMethodInstructionType(
        UIA_WindowPatternId,
        5 /* clientVtableIndex */),
    SelectionItemPatternSelect = MakePatternMethodInstructionType(
        UIA_SelectionItemPatternId,
        3 /* clientVtableIndex */),
    SelectionItemPatternAddToSelection = MakePatternMethodInstructionType(
        UIA_SelectionItemPatternId,
        4 /* clientVtableIndex */),
    SelectionItemPatternRemoveFromSelection = MakePatternMethodInstructionType(
        UIA_SelectionItemPatternId,
        5 /* clientVtableIndex */),
    DockPatternSetDockPosition = MakePatternMethodInstructionType(
        UIA_DockPatternId,
        3 /* clientVtableIndex */),
    TextPatternRangeFromPoint = MakePatternMethodInstructionType(
        UIA_TextPatternId,
        3 /* clientVtableIndex */),
    TextPatternRangeFromChild = MakePatternMethodInstructionType(
        UIA_TextPatternId,
        4 /* clientVtableIndex */),
    TextPatternGetSelection = MakePatternMethodInstructionType(
        UIA_TextPatternId,
        5 /* clientVtableIndex */),
    TextPatternGetVisibleRanges = MakePatternMethodInstructionType(
        UIA_TextPatternId,
        6 /* clientVtableIndex */),
    TextPatternGetDocumentRange = MakePatternMethodInstructionType(
        UIA_TextPatternId,
        7 /* clientVtableIndex */),
    TextPatternGetSupportedTextSelection = MakePatternMethodInstructionType(
        UIA_TextPatternId,
        8 /* clientVtableIndex */),
    TextRangeClone = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        3 /* clientVtableIndex */),
    TextRangeCompare = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        4 /* clientVtableIndex */),
    TextRangeCompareEndpoints = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        5 /* clientVtableIndex */),
    TextRangeExpandToEnclosingUnit = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        6 /* clientVtableIndex */),
    TextRangeFindAttribute = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        7 /* clientVtableIndex */),
    TextRangeFindText = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        8 /* clientVtableIndex */),
    TextRangeGetAttributeValue = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        9 /* clientVtableIndex */),
    TextRangeGetBoundingRectangles = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        10 /* clientVtableIndex */),
    TextRangeGetEnclosingElement = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        11 /* clientVtableIndex */),
    TextRangeGetText = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        12 /* clientVtableIndex */),
    TextRangeMove = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        13 /* clientVtableIndex */),
    TextRangeMoveEndpointByUnit = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        14 /* clientVtableIndex */),
    TextRangeMoveEndpointByRange = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        15 /* clientVtableIndex */),
    TextRangeSelect = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        16 /* clientVtableIndex */),
    TextRangeAddToSelection = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        17 /* clientVtableIndex */),
    TextRangeRemoveFromSelection = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        18 /* clientVtableIndex */),
    TextRangeScrollIntoView = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        19 /* clientVtableIndex */),
    TextRangeGetChildren = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        20 /* clientVtableIndex */),
    TextRangeShowContextMenu = MakePatternRelatedObjectMethodInstructionType(
        UIA_TextPatternId,
        1 /* relatedObjectNumber */,
        21 /* clientVtableIndex */),
    TogglePatternToggle = MakePatternMethodInstructionType(
        UIA_TogglePatternId,
        3 /* clientVtableIndex */),
    TransformPatternMove = MakePatternMethodInstructionType(
        UIA_TransformPatternId,
        3 /* clientVtableIndex */),
    TransformPatternResize = MakePatternMethodInstructionType(
        UIA_TransformPatternId,
        4 /* clientVtableIndex */),
    TransformPatternRotate = MakePatternMethodInstructionType(
        UIA_TransformPatternId,
        5 /* clientVtableIndex */),
    ScrollItemPatternScrollIntoView = MakePatternMethodInstructionType(
        UIA_ScrollItemPatternId,
        3 /* clientVtableIndex */),
    LegacyIAccessiblePatternSelect = MakePatternMethodInstructionType(
        UIA_LegacyIAccessiblePatternId,
        3 /* clientVtableIndex */),
    LegacyIAccessiblePatternDoDefaultAction = MakePatternMethodInstructionType(
        UIA_LegacyIAccessiblePatternId,
        4 /* clientVtableIndex */),
    LegacyIAccessiblePatternSetValue = MakePatternMethodInstructionType(
        UIA_LegacyIAccessiblePatternId,
        5 /* clientVtableIndex */),
    ItemContainerPatternFindItemByProperty = MakePatternMethodInstructionType(
        UIA_ItemContainerPatternId,
        3 /* clientVtableIndex */),
    VirtualizedItemPatternRealize = MakePatternMethodInstructionType(
        UIA_VirtualizedItemPatternId,
        3 /* clientVtableIndex */),
    SynchronizedInputPatternStartListening = MakePatternMethodInstructionType(
        UIA_SynchronizedInputPatternId,
        3 /* clientVtableIndex */),
    SynchronizedInputPatternCancel = MakePatternMethodInstructionType(
        UIA_SynchronizedInputPatternId,
        4 /* clientVtableIndex */),
    TextPattern2RangeFromAnnotation = MakePatternMethodInstructionType(
        UIA_TextPattern2Id,
        9 /* clientVtableIndex */),
    TextPattern2GetCaretRange = MakePatternMethodInstructionType(
        UIA_TextPattern2Id,
        10 /* clientVtableIndex */),
    SpreadsheetPatternGetItemByName = MakePatternMethodInstructionType(
        UIA_SpreadsheetPatternId,
        3 /* clientVtableIndex */),
    TransformPattern2Zoom = MakePatternMethodInstructionType(
        UIA_TransformPattern2Id,
        12 /* clientVtableIndex */),
    TransformPattern2ZoomByUnit = MakePatternMethodInstructionType(
        UIA_TransformPattern2Id,
        13 /* clientVtableIndex */),
    TextChildPatternGetTextContainer = MakePatternMethodInstructionType(
        UIA_TextChildPatternId,
        3 /* clientVtableIndex */),
    TextChildPatternGetTextRange = MakePatternMethodInstructionType(
        UIA_TextChildPatternId,
        4 /* clientVtableIndex */),
    TextEditPatternGetActiveComposition = MakePatternMethodInstructionType(
        UIA_TextEditPatternId,
        9 /* clientVtableIndex */),
    TextEditPatternGetConversionTarget = MakePatternMethodInstructionType(
        UIA_TextEditPatternId,
        10 /* clientVtableIndex */),
    CustomNavigationPatternNavigate = MakePatternMethodInstructionType(
        UIA_CustomNavigationPatternId,
        3 /* clientVtableIndex */),
