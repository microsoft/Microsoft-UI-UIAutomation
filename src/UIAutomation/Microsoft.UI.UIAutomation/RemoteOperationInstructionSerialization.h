// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

#include "RemoteOperationInstructions.h"
#include "MessageBuilder.h"

// Implements the "serialization" layer of Remote Operations. It allows the conversion of any RemoteOperation Instruction
// into an on-the-wire bytecode format that the UIAutomation platform can understand.
struct RemoteOperationInstructionSerializer
{
public:
    explicit RemoteOperationInstructionSerializer(MessageBuilder& builder) : m_builder(builder) {}

    void Serialize(const bytecode::Instruction& instruction);

private:
    // Serializes the given concrete Instruction.
    template<class InstructionT>
    void SerializeInstruction(const InstructionT& instruction);

    // A helper that writes the instruction "header". For now, that's just the instruction type.
    void WriteInstructionHeader(bytecode::InstructionType type);

    // Helpers for primitive types
    void Write(const bytecode::OperandId& operandId);
    void Write(bool value);
    void Write(int value);
    void Write(unsigned value);
    void Write(double value);
    void Write(wchar_t value);
    void Write(const std::wstring& value);
    void Write(const UiaPoint& value);
    void Write(const UiaRect& value);
    void Write(const GUID& value);

    // Write the instructions themselves...
    void Write(const bytecode::Nop&);
    void Write(const bytecode::Set&);
    void Write(const bytecode::NewBool&);
    void Write(const bytecode::NewInt&);
    void Write(const bytecode::NewUint&);
    void Write(const bytecode::NewDouble&);
    void Write(const bytecode::NewChar&);
    void Write(const bytecode::NewString&);
    void Write(const bytecode::NewPoint&);
    void Write(const bytecode::NewRect&);
    void Write(const bytecode::NewGuid&);
    void Write(const bytecode::NewArray&);
    void Write(const bytecode::NewStringMap&);
    void Write(const bytecode::NewNull&);
    void Write(const bytecode::NewCacheRequest&);
    void Write(const bytecode::GetPointProperty&);
    void Write(const bytecode::GetRectProperty&);
    void Write(const bytecode::SetOperationStatus&);
    void Write(const bytecode::GetOperationStatus&);

    void Write(const bytecode::ForkIfTrue&);
    void Write(const bytecode::ForkIfFalse&);
    void Write(const bytecode::Fork&);

    void Write(const bytecode::NewLoopBlock&);
    void Write(const bytecode::EndLoopBlock&);
    void Write(const bytecode::BreakLoop&);
    void Write(const bytecode::ContinueLoop&);

    void Write(const bytecode::NewTryBlock&);
    void Write(const bytecode::EndTryBlock&);

    void Write(const bytecode::Halt&);

    void Write(const bytecode::RemoteArrayAppend&);
    void Write(const bytecode::RemoteArraySetAt&);
    void Write(const bytecode::RemoteArrayRemoveAt&);
    void Write(const bytecode::RemoteArrayGetAt&);
    void Write(const bytecode::RemoteArraySize&);

    void Write(const bytecode::RemoteStringMapInsert&);
    void Write(const bytecode::RemoteStringMapRemove&);
    void Write(const bytecode::RemoteStringMapHasKey&);
    void Write(const bytecode::RemoteStringMapLookup&);
    void Write(const bytecode::RemoteStringMapSize&);

    void Write(const bytecode::RemoteStringGetAt&);
    void Write(const bytecode::RemoteStringSubstr&);
    void Write(const bytecode::RemoteStringConcat&);
    void Write(const bytecode::RemoteStringSize&);

    void Write(const bytecode::Add&);
    void Write(const bytecode::Subtract&);
    void Write(const bytecode::Multiply&);
    void Write(const bytecode::Divide&);

    void Write(const bytecode::BinaryAdd&);
    void Write(const bytecode::BinarySubtract&);
    void Write(const bytecode::BinaryMultiply&);
    void Write(const bytecode::BinaryDivide&);

    void Write(const bytecode::InPlaceBoolNot&);
    void Write(const bytecode::InPlaceBoolAnd&);
    void Write(const bytecode::InPlaceBoolOr&);

    void Write(const bytecode::CacheRequestAddProperty&);
    void Write(const bytecode::CacheRequestAddPattern&);

    void Write(const bytecode::BoolNot&);
    void Write(const bytecode::BoolAnd&);
    void Write(const bytecode::BoolOr&);
    void Write(const bytecode::Compare&);
    void Write(const bytecode::GetPropertyValue&);
    void Write(const bytecode::Navigate&);
    void Write(const bytecode::PopulateCache&);
    void Write(const bytecode::LookupId&);
    void Write(const bytecode::LookupGuid&);
    void Write(const bytecode::GetterBase&);
#include "RemoteOperationInstructionSerializerMethods.g.h"

    MessageBuilder& m_builder;
};

template<class InstructionT>
void RemoteOperationInstructionSerializer::SerializeInstruction(const InstructionT& instruction)
{
    // Every instruction type should have a constexpr static associated with it providing the type.
    WriteInstructionHeader(InstructionT::type);

    // After writing the header, write the instruction itself.
    Write(instruction);
}

