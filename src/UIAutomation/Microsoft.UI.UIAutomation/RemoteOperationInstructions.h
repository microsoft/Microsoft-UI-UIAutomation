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
    Nop = 0x00,
    Set = 0x01,

    // Control flow
    ForkIfTrue = 0x02,
    ForkIfFalse = 0x03,
    Fork = 0x04,
    Halt = 0x05,

    // Loops
    NewLoopBlock = 0x06,
    EndLoopBlock = 0x07,
    BreakLoop = 0x08,
    ContinueLoop = 0x09,

    // Error handling
    NewTryBlock = 0x0a,
    EndTryBlock = 0x0b,
    SetOperationStatus = 0x0c,
    GetOperationStatus = 0x0d,

    // Arithmetic
    Add = 0x0e,
    Subtract = 0x0f,
    Multiply = 0x10,
    Divide = 0x11,
    BinaryAdd = 0x12,
    BinarySubtract = 0x13,
    BinaryMultiply = 0x14,
    BinaryDivide = 0x15,

    // Boolean operators
    InPlaceBoolNot = 0x16,
    InPlaceBoolAnd = 0x17,
    InPlaceBoolOr = 0x18,

    BoolNot = 0x19,
    BoolAnd = 0x1a,
    BoolOr = 0x1b,

    // Generic comparison
    Compare = 0x1c,

    // New object constructors
    NewInt = 0x1d,
    NewUint = 0x1e,
    NewBool = 0x1f,
    NewDouble = 0x20,
    NewChar = 0x21,
    NewString = 0x22,
    NewPoint = 0x23,
    NewRect = 0x24,
    NewArray = 0x25,
    NewStringMap = 0x26,
    NewNull = 0x27,

    // Point and Rect methods
    GetPointProperty = 0x28,
    GetRectProperty = 0x29,

    // RemoteArray methods
    RemoteArrayAppend = 0x2a,
    RemoteArraySetAt = 0x2b,
    RemoteArrayRemoveAt = 0x2c,
    RemoteArrayGetAt = 0x2d,
    RemoteArraySize = 0x2e,

    // RemoteStringMap methods
    RemoteStringMapInsert = 0x2f,
    RemoteStringMapRemove = 0x30,
    RemoteStringMapHasKey = 0x31,
    RemoteStringMapLookup = 0x32,
    RemoteStringMapSize = 0x33,

    // RemoteString methods
    RemoteStringGetAt = 0x34,
    RemoteStringSubstr = 0x35,
    RemoteStringConcat = 0x36,
    RemoteStringSize = 0x37,

    // UIA element methods
    GetPropertyValue = 0x38,
    Navigate = 0x39,

    // Type interrogation methods
    IsNull = 0x3a,
    IsNotSupported = 0x3b,
    IsMixedAttribute = 0x3c,
    IsBool = 0x3d,
    IsInt = 0x3e,
    IsUint = 0x3f,
    IsDouble = 0x40,
    IsChar = 0x41,
    IsString = 0x42,
    IsPoint = 0x43,
    IsRect = 0x44,
    IsArray = 0x45,
    IsStringMap = 0x46,
    IsElement = 0x47,

    // GUID support
    NewGuid = 0x48,
    IsGuid = 0x49,
    LookupId = 0x4a,
    LookupGuid = 0x4b,

    // Cache requests
    NewCacheRequest = 0x4c,
    IsCacheRequest = 0x4d,
    CacheRequestAddProperty = 0x4e,
    CacheRequestAddPattern = 0x4f,
    PopulateCache = 0x50,

    Stringify = 0x51,
    GetMetadataValue = 0x52,

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
    InstructionType::NewGuid,
    InstructionType::IsGuid,
    InstructionType::LookupId,
    InstructionType::LookupGuid,
    InstructionType::NewCacheRequest,
    InstructionType::IsCacheRequest,
    InstructionType::CacheRequestAddProperty,
    InstructionType::CacheRequestAddPattern,
    InstructionType::PopulateCache,
    InstructionType::Stringify,
    InstructionType::GetMetadataValue,

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

struct NewGuid
{
    constexpr static InstructionType type = InstructionType::NewGuid;

    OperandId resultId;
    GUID initialValue;
};

struct IsGuid : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsGuid;
};

struct LookupId
{
    constexpr static InstructionType type = InstructionType::LookupId;

    OperandId resultId;

    OperandId guidId;
    AutomationIdentifierType idType;
};

struct LookupGuid
{
    constexpr static InstructionType type = InstructionType::LookupGuid;

    OperandId resultId;

    OperandId intIdId;
    AutomationIdentifierType idType;
};

struct NewCacheRequest
{
    constexpr static InstructionType type = InstructionType::NewCacheRequest;

    OperandId resultId;
};

struct IsCacheRequest : GetterBase
{
    constexpr static InstructionType type = InstructionType::IsCacheRequest;
};

struct CacheRequestAddProperty
{
    constexpr static InstructionType type = InstructionType::CacheRequestAddProperty;

    OperandId cacheRequestId;
    OperandId propertyIdId;
};

struct CacheRequestAddPattern
{
    constexpr static InstructionType type = InstructionType::CacheRequestAddPattern;

    OperandId cacheRequestId;
    OperandId patternIdId;
};

struct PopulateCache
{
    constexpr static InstructionType type = InstructionType::PopulateCache;

    OperandId elementId;
    OperandId cacheRequestId;
};

struct Stringify
{
    constexpr static InstructionType type = InstructionType::Stringify;

    OperandId resultId;
    OperandId targetId;
};

struct GetMetadataValue
{
    constexpr static InstructionType type = InstructionType::GetMetadataValue;

    OperandId resultId;
    OperandId targetId;
    OperandId propertyId;
    OperandId metadataId;
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
    NewGuid,
    NewCacheRequest,

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
    PopulateCache,
    GetMetadataValue,

    // GUID instructions
    LookupId,
    LookupGuid,

    // Cache request methods
    CacheRequestAddProperty,
    CacheRequestAddPattern,

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
    IsGuid,
    IsCacheRequest,

    Stringify

#include "RemoteOperationInstructionsVariantParams.g.h"
    >;

}  // namespace bytecode
