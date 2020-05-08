// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once

#include <vector>

#include "RemoteOperationInstructions.h"

// A helper class that is used to build up a bytecode stream and serialize it to a byte buffer.
class BytecodeBuilder
{
public:
    // Emit a bytecode instruction into the stream.
    void Emit(const bytecode::Instruction& instruction);

    // Copy the full bytecode stream from the given builder, by appending to the end of the target object.
    void CopyFromBuilder(const BytecodeBuilder& other);

    int GetInstructionCount() const;

    // Serializes the bytecode into a byte buffer.
    std::vector<uint8_t> SerializeInstructionsToBuffer() const;

private:
    std::vector<bytecode::Instruction> m_bytecodeInstructions;

    // The current version of bytecode that this Builder emits.
    static constexpr unsigned int c_bytecodeCurrentVersion = 0u;
};

class RemoteOperationGraph
{
public:
    RemoteOperationGraph() = default;

    struct IfStatementSubgraphs
    {
        std::shared_ptr<RemoteOperationGraph> trueBlockSubgraph;
        std::shared_ptr<RemoteOperationGraph> falseBlockSubgraph;
    };
    IfStatementSubgraphs AddIfStatement(int operandId);

    struct WhileLoopSubgraphs
    {
        std::shared_ptr<RemoteOperationGraph> bodySubgraph;
        std::shared_ptr<RemoteOperationGraph> conditionUpdateSubgraph;
    };
    WhileLoopSubgraphs AddWhileLoop(int operandId);

    struct TryStatementSubgraphs
    {
        std::shared_ptr<RemoteOperationGraph> tryBodySubgraph;
        std::shared_ptr<RemoteOperationGraph> catchBodySubgraph;
    };
    TryStatementSubgraphs AddTryStatement();

    void AddInstruction(const bytecode::Instruction& instruction);

    std::vector<uint8_t> Serialize() const;

private:
    // Represents a single bytecode instruction.
    struct InstructionNode
    {
        bytecode::Instruction instruction;

        void SerializeToBuilder(BytecodeBuilder& builder) const;
    };

    // Represents an if statement node. Contains two subgraphs for the true and false blocks.
    // References an operand register ID, which should be the register that holds the boolean that the
    // if statement will switch on.
    struct IfStatementNode
    {
        int conditionOperandId;
        std::shared_ptr<RemoteOperationGraph> trueBody;
        std::shared_ptr<RemoteOperationGraph> falseBody;

        void SerializeToBuilder(BytecodeBuilder& builder) const;
    };

    // Represents a while loop node. Contains two subgraphs: the body of the loop and a "condition update"
    // graph. The latter are instructions that should be executed any time an iteration through the loop
    // is completed, before re-evaluating the condition.
    struct WhileLoopNode
    {
        int conditionOperandId;
        std::shared_ptr<RemoteOperationGraph> body;
        std::shared_ptr<RemoteOperationGraph> conditionUpdate;

        void SerializeToBuilder(BytecodeBuilder& builder) const;
    };

    // Represents a try statement. Contains two subgraphs: the body of the try block and the catch block.
    // Any failure that occurs in the try block will cause control flow to move to the catch block.
    struct TryStatementNode
    {
        std::shared_ptr<RemoteOperationGraph> tryBody;
        std::shared_ptr<RemoteOperationGraph> catchBody;

        void SerializeToBuilder(BytecodeBuilder& builder) const;
    };

    using Node = std::variant<InstructionNode, IfStatementNode, WhileLoopNode, TryStatementNode>;

    BytecodeBuilder CompileBytecode() const;

    std::vector<Node> m_nodes;
};
