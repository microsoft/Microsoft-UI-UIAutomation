// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

#include "pch.h"
#include "RemoteOperationInstructionSerialization.h"

#include <wil/result.h>

using namespace bytecode;

void RemoteOperationInstructionSerializer::WriteInstructionHeader(InstructionType type)
{
    Write(static_cast<int>(type));
}

void RemoteOperationInstructionSerializer::Write(const OperandId& operandId)
{
    m_builder.WriteInt(operandId.Value);
}

void RemoteOperationInstructionSerializer::Write(bool value)
{
    m_builder.WriteBool(value);
}

void RemoteOperationInstructionSerializer::Write(int value)
{
    m_builder.WriteInt(value);
}

void RemoteOperationInstructionSerializer::Write(unsigned value)
{
    m_builder.WriteUnsignedInt(value);
}

void RemoteOperationInstructionSerializer::Write(double value)
{
    m_builder.WriteDouble(value);
}

void RemoteOperationInstructionSerializer::Write(wchar_t value)
{
    m_builder.WriteChar(value);
}

void RemoteOperationInstructionSerializer::Write(const std::wstring& value)
{
    m_builder.WriteString(value);
}

void RemoteOperationInstructionSerializer::Write(const UiaPoint& value)
{
    m_builder.WriteDouble(value.x);
    m_builder.WriteDouble(value.y);
}

void RemoteOperationInstructionSerializer::Write(const UiaRect& value)
{
    m_builder.WriteDouble(value.left);
    m_builder.WriteDouble(value.top);
    m_builder.WriteDouble(value.width);
    m_builder.WriteDouble(value.height);
}

void RemoteOperationInstructionSerializer::Write(const GUID& value)
{
    m_builder.WriteGuid(value);
}

void RemoteOperationInstructionSerializer::Write(const uint8_t& value)
{
    m_builder.WriteByte(value);
}

void RemoteOperationInstructionSerializer::Serialize(const Instruction& genericInstruction)
{
    std::visit([&](const auto& instruction)
    {
        SerializeInstruction(instruction);
    }, genericInstruction);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Nop&)
{
    // No further payload in the instruction -- i.e. it just has the opcode.
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Set& instruction)
{
    Write(instruction.targetId);
    Write(instruction.rhsId);
}

void RemoteOperationInstructionSerializer::Write(const NewBool& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewInt& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewUint& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewDouble& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewChar& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewString& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewPoint& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewRect& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewGuid& instruction)
{
    Write(instruction.resultId);
    Write(instruction.initialValue);
}

void RemoteOperationInstructionSerializer::Write(const NewArray& instruction)
{
    Write(instruction.resultId);
}

void RemoteOperationInstructionSerializer::Write(const NewStringMap& instruction)
{
    Write(instruction.resultId);
}

void RemoteOperationInstructionSerializer::Write(const NewNull& instruction)
{
    Write(instruction.resultId);
}

void RemoteOperationInstructionSerializer::Write(const NewCacheRequest& instruction)
{
    Write(instruction.resultId);
}

void RemoteOperationInstructionSerializer::Write(const GetPointProperty& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(static_cast<int>(instruction.property));
}

void RemoteOperationInstructionSerializer::Write(const GetRectProperty& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(static_cast<int>(instruction.property));
}

void RemoteOperationInstructionSerializer::Write(const SetOperationStatus& instruction)
{
    Write(instruction.errorCodeOperandId);
}

void RemoteOperationInstructionSerializer::Write(const GetOperationStatus& instruction)
{
    Write(instruction.resultId);
}

void RemoteOperationInstructionSerializer::Write(const ForkIfTrue& instruction)
{
    Write(instruction.operandId);
    Write(instruction.targetOffset);
}

void RemoteOperationInstructionSerializer::Write(const ForkIfFalse& instruction)
{
    Write(instruction.operandId);
    Write(instruction.targetOffset);
}

void RemoteOperationInstructionSerializer::Write(const Fork& instruction)
{
    Write(instruction.targetOffset);
}

void RemoteOperationInstructionSerializer::Write(const NewLoopBlock& instruction)
{
    Write(instruction.breakLoopOffset);
    Write(instruction.continueLoopOffset);
}

void RemoteOperationInstructionSerializer::Write(const EndLoopBlock&)
{
    // Instruction has no operands/parameters to serialize.
}

void RemoteOperationInstructionSerializer::Write(const BreakLoop&)
{
    // Instruction has no operands/parameters to serialize.
}

void RemoteOperationInstructionSerializer::Write(const ContinueLoop&)
{
    // Instruction has no operands/parameters to serialize.
}

void RemoteOperationInstructionSerializer::Write(const NewTryBlock& instruction)
{
    Write(instruction.catchBlockOffset);
}

void RemoteOperationInstructionSerializer::Write(const EndTryBlock&)
{
    // Instruction has no operands/parameters to serialize.
}

void RemoteOperationInstructionSerializer::Write(const Halt&)
{
    // Instruction has no operands/parameters to serialize.
}

void RemoteOperationInstructionSerializer::Write(const RemoteArrayAppend& instruction)
{
    Write(instruction.targetId);
    Write(instruction.operandId);
}

void RemoteOperationInstructionSerializer::Write(const RemoteArraySetAt& instruction)
{
    Write(instruction.targetId);
    Write(instruction.indexOperandId);
    Write(instruction.objectOperandId);
}

void RemoteOperationInstructionSerializer::Write(const RemoteArrayRemoveAt& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.indexOperandId);
}

void RemoteOperationInstructionSerializer::Write(const RemoteArrayGetAt& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.indexOperandId);
}

void RemoteOperationInstructionSerializer::Write(const RemoteArraySize& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const RemoteStringMapInsert& instruction)
{
    Write(instruction.targetId);
    Write(instruction.keyId);
    Write(instruction.valueId);
};

void RemoteOperationInstructionSerializer::Write(const RemoteStringMapRemove& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.keyId);
};

void RemoteOperationInstructionSerializer::Write(const RemoteStringMapHasKey& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.keyId);
};

void RemoteOperationInstructionSerializer::Write(const RemoteStringMapLookup& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.keyId);
};

void RemoteOperationInstructionSerializer::Write(const RemoteStringMapSize& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
};

void RemoteOperationInstructionSerializer::Write(const RemoteStringGetAt& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.indexId);
}

void RemoteOperationInstructionSerializer::Write(const RemoteStringSubstr& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.indexId);
    Write(instruction.lengthId);
}

void RemoteOperationInstructionSerializer::Write(const RemoteStringConcat& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.rhsId);
}

void RemoteOperationInstructionSerializer::Write(const RemoteStringSize& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Add& instruction)
{
    Write(instruction.targetId);
    Write(instruction.rhsId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Subtract& instruction)
{
    Write(instruction.targetId);
    Write(instruction.rhsId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Multiply& instruction)
{
    Write(instruction.targetId);
    Write(instruction.rhsId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Divide& instruction)
{
    Write(instruction.targetId);
    Write(instruction.rhsId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::BinaryAdd& instruction)
{
    Write(instruction.resultId);
    Write(instruction.lhsId);
    Write(instruction.rhsId);
};

void RemoteOperationInstructionSerializer::Write(const bytecode::BinarySubtract& instruction)
{
    Write(instruction.resultId);
    Write(instruction.lhsId);
    Write(instruction.rhsId);
};

void RemoteOperationInstructionSerializer::Write(const bytecode::BinaryMultiply& instruction)
{
    Write(instruction.resultId);
    Write(instruction.lhsId);
    Write(instruction.rhsId);
};

void RemoteOperationInstructionSerializer::Write(const bytecode::BinaryDivide& instruction)
{
    Write(instruction.resultId);
    Write(instruction.lhsId);
    Write(instruction.rhsId);
};

void RemoteOperationInstructionSerializer::Write(const bytecode::InPlaceBoolNot& instruction)
{
    Write(instruction.targetId);
};

void RemoteOperationInstructionSerializer::Write(const bytecode::InPlaceBoolAnd& instruction)
{
    Write(instruction.targetId);
    Write(instruction.rhsId);
};

void RemoteOperationInstructionSerializer::Write(const bytecode::InPlaceBoolOr& instruction)
{
    Write(instruction.targetId);
    Write(instruction.rhsId);
};

void RemoteOperationInstructionSerializer::Write(const bytecode::BoolNot& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::BoolAnd& instruction)
{
    Write(instruction.resultId);
    Write(instruction.lhsId);
    Write(instruction.rhsId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::BoolOr& instruction)
{
    Write(instruction.resultId);
    Write(instruction.lhsId);
    Write(instruction.rhsId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Compare& instruction)
{
    Write(instruction.resultId);
    Write(instruction.lhsId);
    Write(instruction.rhsId);
    Write(static_cast<int>(instruction.comparisonType));
}

void RemoteOperationInstructionSerializer::Write(const bytecode::GetPropertyValue& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.propertyIdId);
    Write(instruction.ignoreDefaultValueId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Navigate& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.directionId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::PopulateCache& instruction)
{
    Write(instruction.elementId);
    Write(instruction.cacheRequestId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::GetMetadataValue& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.propertyId);
    Write(instruction.metadataId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::LookupId& instruction)
{
    Write(instruction.resultId);
    Write(instruction.guidId);
    Write(static_cast<int>(instruction.idType));
}

void RemoteOperationInstructionSerializer::Write(const bytecode::LookupGuid& instruction)
{
    Write(instruction.resultId);
    Write(instruction.intIdId);
    Write(static_cast<int>(instruction.idType));
}

void RemoteOperationInstructionSerializer::Write(const bytecode::CacheRequestAddProperty& instruction)
{
    Write(instruction.cacheRequestId);
    Write(instruction.propertyIdId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::CacheRequestAddPattern& instruction)
{
    Write(instruction.cacheRequestId);
    Write(instruction.patternIdId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::Stringify& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::CallExtension& instruction)
{
    Write(instruction.targetId);
    Write(instruction.extensionIdId);
    Write(static_cast<int>(instruction.operandIds.size()));
    for (const auto& operandId : instruction.operandIds)
    {
        Write(operandId);
    }
}

void RemoteOperationInstructionSerializer::Write(const bytecode::IsExtensionSupported& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
    Write(instruction.extensionIdId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::IsExtensionTarget& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

void RemoteOperationInstructionSerializer::Write(const bytecode::NewByteArray& instruction)
{
    Write(instruction.resultId);
    Write(static_cast<int>(instruction.initialValue.size()));
    for (const auto& byteEntry : instruction.initialValue)
    {
        Write(byteEntry);
    }
}

void RemoteOperationInstructionSerializer::Write(const GetterBase& instruction)
{
    Write(instruction.resultId);
    Write(instruction.targetId);
}

