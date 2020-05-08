// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

#include <windows.h>
#include <UIAutomation.h>
#include <variant>
#include <array>

// Defines the bytecode level instructions for Remote Operations.
namespace bytecode
{

struct OperandId
{
    int Value;
};

// Opcodes of instructions for getting a built-in UIAutomation pattern map to that pattern's pattern ID.
constexpr int MakePatternGetterInstructionType(PATTERNID patternId)
{
    return static_cast<int>(patternId);
}

// The following two helpers create instruction type IDs for pattern method instructions.
constexpr int MakePatternMethodInstructionType(PATTERNID patternId, int clientVtableIndex)
{
    return (static_cast<int>(patternId) << 10) | clientVtableIndex;
}

constexpr int MakePatternRelatedObjectMethodInstructionType(PATTERNID patternId, int relatedObjectNumber, int clientVtableIndex)
{
    return (static_cast<int>(patternId) << 16) | (relatedObjectNumber << 8) | clientVtableIndex;
}

// The instruction enum value here map to the instruction opcode, defined and documented by the UIAutomation platform.
enum class InstructionType
{
    Nop = 0,
    Set,

    // Control flow
    ForkIfTrue,
    ForkIfFalse,
    Fork,
    Halt,

    // Loops
    NewLoopBlock,
    EndLoopBlock,
    BreakLoop,
    ContinueLoop,

    // Error handling
    NewTryBlock,
    EndTryBlock,
    SetOperationStatus,
    GetOperationStatus,

    // Arithmetic
    Add,
    Subtract,
    Multiply,
    Divide,
    BinaryAdd,
    BinarySubtract,
    BinaryMultiply,
    BinaryDivide,

    // Boolean operators
    InPlaceBoolNot,
    InPlaceBoolAnd,
    InPlaceBoolOr,

    BoolNot,
    BoolAnd,
    BoolOr,

    // Generic comparison
    Compare,

    // New object constructors
    NewInt,
    NewUint,
    NewBool,
    NewDouble,
    NewChar,
    NewString,
    NewPoint,
    NewRect,
    NewArray,
    NewStringMap,
    NewNull,

    // Point and Rect methods
    GetPointProperty,
    GetRectProperty,

    // RemoteArray methods
    RemoteArrayAppend,
    RemoteArraySetAt,
    RemoteArrayRemoveAt,
    RemoteArrayGetAt,
    RemoteArraySize,

    // RemoteStringMap methods
    RemoteStringMapInsert,
    RemoteStringMapRemove,
    RemoteStringMapHasKey,
    RemoteStringMapLookup,
    RemoteStringMapSize,

    // RemoteString methods
    RemoteStringGetAt,
    RemoteStringSubstr,
    RemoteStringConcat,
    RemoteStringSize,

    // UIA element methods
    GetPropertyValue,
    Navigate,

    // Type interrogation methods
    IsNull,
    IsNotSupported,
    IsMixedAttribute,
    IsBool,
    IsInt,
    IsUint,
    IsDouble,
    IsChar,
    IsString,
    IsPoint,
    IsRect,
    IsArray,
    IsStringMap,
    IsElement,

    // UIA pattern getters and pattern methods
#include "RemoteOperationInstructionEnumValues.g.h"
};

constexpr std::array c_supportedInstructions =
{
    // Non-generated instructions
    InstructionType::Nop,
    InstructionType::Set,
    InstructionType::ForkIfTrue,
    InstructionType::ForkIfFalse,
    InstructionType::Fork,
    InstructionType::Halt,
    InstructionType::NewLoopBlock,
    InstructionType::EndLoopBlock,
    InstructionType::BreakLoop,
    InstructionType::ContinueLoop,
    InstructionType::NewTryBlock,
    InstructionType::EndTryBlock,
    InstructionType::SetOperationStatus,
    InstructionType::GetOperationStatus,
    InstructionType::Add,
    InstructionType::Subtract,
    InstructionType::Multiply,
    InstructionType::Divide,
    InstructionType::BinaryAdd,
    InstructionType::BinarySubtract,
    InstructionType::BinaryMultiply,
    InstructionType::BinaryDivide,
    InstructionType::InPlaceBoolNot,
    InstructionType::InPlaceBoolAnd,
    InstructionType::InPlaceBoolOr,
    InstructionType::BoolNot,
    InstructionType::BoolAnd,
    InstructionType::BoolOr,
    InstructionType::Compare,
    InstructionType::NewInt,
    InstructionType::NewUint,
    InstructionType::NewBool,
    InstructionType::NewDouble,
    InstructionType::NewChar,
    InstructionType::NewString,
    InstructionType::NewPoint,
    InstructionType::NewRect,
    InstructionType::NewArray,
    InstructionType::NewStringMap,
    InstructionType::NewNull,
    InstructionType::GetPointProperty,
    InstructionType::GetRectProperty,
    InstructionType::RemoteArrayAppend,
    InstructionType::RemoteArraySetAt,
    InstructionType::RemoteArrayRemoveAt,
    InstructionType::RemoteArrayGetAt,
    InstructionType::RemoteArraySize,
    InstructionType::RemoteStringMapInsert,
    InstructionType::RemoteStringMapRemove,
    InstructionType::RemoteStringMapHasKey,
    InstructionType::RemoteStringMapLookup,
    InstructionType::RemoteStringMapSize,
    InstructionType::RemoteStringGetAt,
    InstructionType::RemoteStringSubstr,
    InstructionType::RemoteStringConcat,
    InstructionType::RemoteStringSize,
    InstructionType::GetPropertyValue,
    InstructionType::Navigate,
    InstructionType::IsNull,
    InstructionType::IsNotSupported,
    InstructionType::IsMixedAttribute,
    InstructionType::IsBool,
    InstructionType::IsInt,
    InstructionType::IsUint,
    InstructionType::IsDouble,
    InstructionType::IsChar,
    InstructionType::IsString,
    InstructionType::IsPoint,
    InstructionType::IsRect,
    InstructionType::IsArray,
    InstructionType::IsStringMap,
    InstructionType::IsElement,

    // Auto-generated UIA pattern getters and pattern methods
#include "RemoteOperationInstructionEnumValuesArray.g.h"
};

struct Nop
{
    constexpr static InstructionType type = InstructionType::Nop;
};

struct Set
{
    constexpr static InstructionType type = InstructionType::Set;

    OperandId targetId;
    OperandId rhsId;
};

struct NewBool
{
    constexpr static InstructionType type = InstructionType::NewBool;

    OperandId resultId;
    bool initialValue;
};

struct NewInt
{
    constexpr static InstructionType type = InstructionType::NewInt;

    OperandId resultId;
    int initialValue;
};

struct NewUint
{
    constexpr static InstructionType type = InstructionType::NewUint;

    OperandId resultId;
    unsigned initialValue;
};

struct NewDouble
{
    constexpr static InstructionType type = InstructionType::NewDouble;

    OperandId resultId;
    double initialValue;
};

struct NewChar
{
    constexpr static InstructionType type = InstructionType::NewChar;

    OperandId resultId;
    wchar_t initialValue;
};

struct NewString
{
    constexpr static InstructionType type = InstructionType::NewString;

    OperandId resultId;
    std::wstring initialValue;
};

struct NewPoint
{
    constexpr static InstructionType type = InstructionType::NewPoint;

    OperandId resultId;
    UiaPoint initialValue;
};

struct NewRect
{
    constexpr static InstructionType type = InstructionType::NewRect;

    OperandId resultId;
    UiaRect initialValue;
};

struct NewArray
{
    constexpr static InstructionType type = InstructionType::NewArray;

    OperandId resultId;
};

struct NewStringMap
{
    constexpr static InstructionType type = InstructionType::NewStringMap;

    OperandId resultId;
};

struct NewNull
{
    constexpr static InstructionType type = InstructionType::NewNull;

    OperandId resultId;
};

struct GetPointProperty
{
    constexpr static InstructionType type = InstructionType::GetPointProperty;

    enum class Property
    {
        X,
        Y,
    };

    static GetPointProperty GetX(OperandId resultId, OperandId targetId)
    {
        return GetPointProperty{ resultId, targetId, Property::X };
    }

    static GetPointProperty GetY(OperandId resultId, OperandId targetId)
    {
        return GetPointProperty{ resultId, targetId, Property::Y };
    }

    OperandId resultId;
    OperandId targetId;
    Property property;
};

struct GetRectProperty
{
    constexpr static InstructionType type = InstructionType::GetRectProperty;

    enum class Property
    {
        Height,
        Width,
        X,
        Y,
    };

    static GetRectProperty GetHeight(OperandId resultId, OperandId targetId)
    {
        return GetRectProperty{ resultId, targetId, Property::Height };
    }

    static GetRectProperty GetWidth(OperandId resultId, OperandId targetId)
    {
        return GetRectProperty{ resultId, targetId, Property::Width };
    }

    static GetRectProperty GetX(OperandId resultId, OperandId targetId)
    {
        return GetRectProperty{ resultId, targetId, Property::X };
    }

    static GetRectProperty GetY(OperandId resultId, OperandId targetId)
    {
        return GetRectProperty{ resultId, targetId, Property::Y };
    }

    OperandId resultId;
    OperandId targetId;
    Property property;
};

struct SetOperationStatus
{
    constexpr static InstructionType type = InstructionType::SetOperationStatus;

    OperandId errorCodeOperandId;
};

struct GetOperationStatus
{
    constexpr static InstructionType type = InstructionType::GetOperationStatus;

    OperandId resultId;
};

struct ForkIfTrue
{
    constexpr static InstructionType type = InstructionType::ForkIfTrue;

    OperandId operandId;
    int targetOffset;
};

struct ForkIfFalse
{
    constexpr static InstructionType type = InstructionType::ForkIfFalse;

    OperandId operandId;
    int targetOffset;
};

struct Fork
{
    constexpr static InstructionType type = InstructionType::Fork;

    int targetOffset;
};

struct NewLoopBlock
{
    constexpr static InstructionType type = InstructionType::NewLoopBlock;

    int breakLoopOffset;
    int continueLoopOffset;
};

struct EndLoopBlock
{
    constexpr static InstructionType type = InstructionType::EndLoopBlock;
};

struct BreakLoop
{
    constexpr static InstructionType type = InstructionType::BreakLoop;
};

struct ContinueLoop
{
    constexpr static InstructionType type = InstructionType::ContinueLoop;
};

struct NewTryBlock
{
    constexpr static InstructionType type = InstructionType::NewTryBlock;

    int catchBlockOffset;
};

struct EndTryBlock
{
    constexpr static InstructionType type = InstructionType::EndTryBlock;
};

struct Halt
{
    constexpr static InstructionType type = InstructionType::Halt;
};

struct RemoteArrayAppend
{
    constexpr static InstructionType type = InstructionType::RemoteArrayAppend;
    
    OperandId targetId;
    OperandId operandId;
};

struct RemoteArraySetAt
{
    constexpr static InstructionType type = InstructionType::RemoteArraySetAt;
    
    OperandId targetId;
    OperandId indexOperandId;
    OperandId objectOperandId;
};

struct RemoteArrayRemoveAt
{
    constexpr static InstructionType type = InstructionType::RemoteArrayRemoveAt;

    OperandId resultId;
    OperandId targetId;
    OperandId indexOperandId;
};

struct RemoteArrayGetAt
{
    constexpr static InstructionType type = InstructionType::RemoteArrayGetAt;

    OperandId resultId;
    OperandId targetId;
    OperandId indexOperandId;
};

struct RemoteArraySize
{
    constexpr static InstructionType type = InstructionType::RemoteArraySize;

    OperandId resultId;
    OperandId targetId;
};

struct RemoteStringMapInsert
{
    constexpr static InstructionType type = InstructionType::RemoteStringMapInsert;

    OperandId targetId;
    OperandId keyId;
    OperandId valueId;
};

struct RemoteStringMapRemove
{
    constexpr static InstructionType type = InstructionType::RemoteStringMapRemove;

    OperandId resultId;
    OperandId targetId;
    OperandId keyId;
};

struct RemoteStringMapHasKey
{
    constexpr static InstructionType type = InstructionType::RemoteStringMapHasKey;

    OperandId resultId;
    OperandId targetId;
    OperandId keyId;
};

struct RemoteStringMapLookup
{
    constexpr static InstructionType type = InstructionType::RemoteStringMapLookup;

    OperandId resultId;
    OperandId targetId;
    OperandId keyId;
};

struct RemoteStringMapSize
{
    constexpr static InstructionType type = InstructionType::RemoteStringMapSize;

    OperandId resultId;
    OperandId targetId;
};

struct RemoteStringGetAt
{
    constexpr static InstructionType type = InstructionType::RemoteStringGetAt;

    OperandId resultId;
    OperandId targetId;
    OperandId indexId;
};

struct RemoteStringSubstr
{
    constexpr static InstructionType type = InstructionType::RemoteStringSubstr;

    OperandId resultId;
    OperandId targetId;
    OperandId indexId;
    OperandId lengthId;
};

struct RemoteStringConcat
{
    constexpr static InstructionType type = InstructionType::RemoteStringConcat;

    OperandId resultId;
    OperandId targetId;
    OperandId rhsId;
};

struct RemoteStringSize
{
    constexpr static InstructionType type = InstructionType::RemoteStringSize;

    OperandId resultId;
    OperandId targetId;
};

struct Add
{
    constexpr static InstructionType type = InstructionType::Add;

    OperandId targetId;
    OperandId rhsId;
};

struct Subtract
{
    constexpr static InstructionType type = InstructionType::Subtract;

    OperandId targetId;
    OperandId rhsId;
};

struct Multiply
{
    constexpr static InstructionType type = InstructionType::Multiply;

    OperandId targetId;
    OperandId rhsId;
};

struct Divide
{
    constexpr static InstructionType type = InstructionType::Divide;

    OperandId targetId;
    OperandId rhsId;
};

struct BinaryAdd
{
    constexpr static InstructionType type = InstructionType::BinaryAdd;

    OperandId resultId;
    OperandId lhsId;
    OperandId rhsId;
};

struct BinarySubtract
{
    constexpr static InstructionType type = InstructionType::BinarySubtract;

    OperandId resultId;
    OperandId lhsId;
    OperandId rhsId;
};

struct BinaryMultiply
{
    constexpr static InstructionType type = InstructionType::BinaryMultiply;

    OperandId resultId;
    OperandId lhsId;
    OperandId rhsId;
};

struct BinaryDivide
{
    constexpr static InstructionType type = InstructionType::BinaryDivide;

    OperandId resultId;
    OperandId lhsId;
    OperandId rhsId;
};

struct InPlaceBoolNot
{
    constexpr static InstructionType type = InstructionType::InPlaceBoolNot;

    OperandId targetId;
};

struct InPlaceBoolAnd
{
    constexpr static InstructionType type = InstructionType::InPlaceBoolAnd;

    OperandId targetId;
    OperandId rhsId;
};

struct InPlaceBoolOr
{
    constexpr static InstructionType type = InstructionType::InPlaceBoolOr;

    OperandId targetId;
    OperandId rhsId;
};

struct BoolNot
{
    constexpr static InstructionType type = InstructionType::BoolNot;

    OperandId resultId;
    OperandId targetId;
};

struct BoolAnd
{
    constexpr static InstructionType type = InstructionType::BoolAnd;

    OperandId resultId;
    OperandId lhsId;
    OperandId rhsId;
};

struct BoolOr
{
    constexpr static InstructionType type = InstructionType::BoolOr;

    OperandId resultId;
    OperandId lhsId;
    OperandId rhsId;
};

enum class ComparisonType
{
    Equal,
    NotEqual,
    GreaterThan,
    LessThan,
    GreaterThanOrEqual,
    LessThanOrEqual,
};

// Compares two operands identified by lhsId and rhsId and emits a bool into the operand identified by resultId.
// The type of comparison is identified by the comparisonType member.
struct Compare
{
    constexpr static InstructionType type = InstructionType::Compare;

    OperandId resultId;

    OperandId lhsId;
    OperandId rhsId;
    ComparisonType comparisonType;
};

struct GetPropertyValue
{
    constexpr static InstructionType type = InstructionType::GetPropertyValue;

    OperandId resultId;
    // The target ID may be either an element or a pattern, as the UIA platform specifies that the GetPropertyValue
    // instruction can get both pattern and element properties.
    //
    // The client can provide a natural API that doesn't care about this detail.
    OperandId targetId;
    OperandId propertyIdId;
    OperandId ignoreDefaultValueId;
};

struct Navigate
{
    constexpr static InstructionType type = InstructionType::Navigate;

    OperandId resultId;
    OperandId targetId;
    OperandId directionId;
};

struct GetterBase
{
    OperandId resultId;
    OperandId targetId;
};

struct IsNull : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsNull;
};

struct IsNotSupported : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsNotSupported;
};

struct IsMixedAttribute : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsMixedAttribute;
};

struct IsBool : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsBool;
};

struct IsInt : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsInt;
};

struct IsUint : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsUint;
};

struct IsDouble : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsDouble;
};

struct IsChar : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsChar;
};

struct IsString : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsString;
};

struct IsPoint : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsPoint;
};

struct IsRect : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsRect;
};

struct IsArray : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsArray;
};

struct IsStringMap : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsStringMap;
};

struct IsElement : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsElement;
};

#include "RemoteOperationInstructions.g.h"

using Instruction = std::variant<
    Nop,
    Set,

    // Control flow
    ForkIfTrue,
    ForkIfFalse,
    Fork,
    Halt,

    // Loops
    NewLoopBlock,
    EndLoopBlock,
    BreakLoop,
    ContinueLoop,

    // Error handling
    NewTryBlock,
    EndTryBlock,
    SetOperationStatus,
    GetOperationStatus,

    // Arithmetic
    Add,
    Subtract,
    Multiply,
    Divide,

    BinaryAdd,
    BinarySubtract,
    BinaryMultiply,
    BinaryDivide,

    // Boolean operators
    InPlaceBoolNot,
    InPlaceBoolAnd,
    InPlaceBoolOr,

    BoolNot,
    BoolAnd,
    BoolOr,

    // Generic comparison
    Compare,

    // New object constructors
    NewInt,
    NewUint,
    NewBool,
    NewDouble,
    NewChar,
    NewString,
    NewPoint,
    NewRect,
    NewArray,
    NewStringMap,
    NewNull,

    // Point and Rect methods
    GetPointProperty,
    GetRectProperty,

    // RemoteArray methods
    RemoteArrayAppend,
    RemoteArraySetAt,
    RemoteArrayRemoveAt,
    RemoteArrayGetAt,
    RemoteArraySize,

    // RemoteStringMap methods
    RemoteStringMapInsert,
    RemoteStringMapRemove,
    RemoteStringMapHasKey,
    RemoteStringMapLookup,
    RemoteStringMapSize,

    // RemoteString methods
    RemoteStringGetAt,
    RemoteStringSubstr,
    RemoteStringConcat,
    RemoteStringSize,

    // UIA element methods
    GetPropertyValue,
    Navigate,

    // Type interrogation methods
    IsNull,
    IsNotSupported,
    IsMixedAttribute,
    IsBool,
    IsInt,
    IsUint,
    IsDouble,
    IsChar,
    IsString,
    IsPoint,
    IsRect,
    IsArray,
    IsStringMap,
    IsElement

#include "RemoteOperationInstructionsVariantParams.g.h"
    >;

}  // namespace bytecode
