// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#include "pch.h"
#include "RemoteOperationGraph.h"

#include "MessageBuilder.h"
#include "RemoteOperationInstructionSerialization.h"

void BytecodeBuilder::Emit(const bytecode::Instruction& instruction)
{
    m_bytecodeInstructions.emplace_back(instruction);
}

void BytecodeBuilder::CopyFromBuilder(const BytecodeBuilder& other)
{
    std::copy(other.m_bytecodeInstructions.begin(), other.m_bytecodeInstructions.end(), std::back_inserter(m_bytecodeInstructions));
}

int BytecodeBuilder::GetInstructionCount() const
{
    return static_cast<int>(m_bytecodeInstructions.size());
}

std::vector<uint8_t> BytecodeBuilder::SerializeInstructionsToBuffer() const
{
    MessageBuilder builder;

    // The first 4 bytes are the version of the bytecode format that follows. UIA currently only
    // supports one version, which is what we'll emit.
    builder.WriteUnsignedInt(c_bytecodeCurrentVersion);

    // Now serialize each instruction into the bytestream.
    RemoteOperationInstructionSerializer serializer(builder);
    for (const auto& instruction : m_bytecodeInstructions)
    {
        serializer.Serialize(instruction);
    }

    return builder.DetachBuffer();
}

RemoteOperationGraph::IfStatementSubgraphs RemoteOperationGraph::AddIfStatement(int operandId)
{
    auto trueBody = std::make_shared<RemoteOperationGraph>();
    auto falseBody = std::make_shared<RemoteOperationGraph>();
    m_nodes.emplace_back(IfStatementNode{ operandId, trueBody, falseBody });

    return { std::move(trueBody), std::move(falseBody) };
}

RemoteOperationGraph::WhileLoopSubgraphs RemoteOperationGraph::AddWhileLoop(int operandId)
{
    auto loopBody = std::make_shared<RemoteOperationGraph>();
    auto conditionUpdate = std::make_shared<RemoteOperationGraph>();
    m_nodes.emplace_back(WhileLoopNode{ operandId, loopBody, conditionUpdate });

    return { std::move(loopBody), std::move(conditionUpdate) };
}

RemoteOperationGraph::TryStatementSubgraphs RemoteOperationGraph::AddTryStatement()
{
    auto tryBody = std::make_shared<RemoteOperationGraph>();
    auto catchBody = std::make_shared<RemoteOperationGraph>();
    m_nodes.emplace_back(TryStatementNode{ tryBody, catchBody });

    return { std::move(tryBody), std::move(catchBody) };
}

void RemoteOperationGraph::AddInstruction(const bytecode::Instruction& instruction)
{
    m_nodes.emplace_back(InstructionNode{ instruction });
}

BytecodeBuilder RemoteOperationGraph::CompileBytecode() const
{
    BytecodeBuilder builder;
    for (const auto& node : m_nodes)
    {
        std::visit([&](const auto& node)
        {
            node.SerializeToBuilder(builder);
        }, node);
    }

    return builder;
}

std::vector<uint8_t> RemoteOperationGraph::Serialize() const
{
    const auto bytecode = CompileBytecode();
    auto byteBuffer = bytecode.SerializeInstructionsToBuffer();

    return byteBuffer;
}

void RemoteOperationGraph::InstructionNode::SerializeToBuilder(BytecodeBuilder& builder) const
{
    builder.Emit(instruction);
}

void RemoteOperationGraph::IfStatementNode::SerializeToBuilder(BytecodeBuilder& builder) const
{
    // The bytecode that we build for an If-statement first includes a ForkIfFalse that evaluates
    // the condition operand. This is followed by the true block; after the true block we have an
    // unconditional jump to skip over the false block; finally, the false block is emitted.
    //
    // For instance, for an if statement that has 2 instructions in the true block and 3 instructions
    // in the false block:
    //
    //   0  ForkIfFalse +4 [2+2 --> target==4]
    //   1  true_instruction
    //   2  true_instruction
    //   3  Fork +4 [3+1 --> target==7]
    //   4  false_instruction
    //   5  false_instruction
    //   6  false_instruction

    BytecodeBuilder trueBytecode = trueBody->CompileBytecode();
    BytecodeBuilder falseBytecode = falseBody->CompileBytecode();

    // When the operand is false, jump to the fork block by skipping over all the instructions of the true block.
    builder.Emit(bytecode::ForkIfFalse{
        bytecode::OperandId{ conditionOperandId },
        trueBytecode.GetInstructionCount() + 2,
    });

    // Now emit the instructions from the true block...
    builder.CopyFromBuilder(trueBytecode);
    // ...including a jump that skips over everything in the upcoming false block.
    builder.Emit(bytecode::Fork{ falseBytecode.GetInstructionCount() + 1 });

    if (falseBytecode.GetInstructionCount() > 0)
    {
        builder.CopyFromBuilder(falseBytecode);
    }
    else
    {
        // Emit a no-op so that the conditional branch always has a target for the false case.
        builder.Emit(bytecode::Nop{});
    }
}

void RemoteOperationGraph::WhileLoopNode::SerializeToBuilder(BytecodeBuilder& builder) const
{
    // The bytecode for a while loop first emits a NewLoopBlock instruction indicating that a new
    // loop should be pushed onto the stack. Then we emit a conditional to evaluate whether the
    // loop body should execute. The full bytecode body is then comprised of the body and condition
    // update subgraphs. After this, we unconditionally jump back to the loop evaluation condition.
    // Finally, if the loop evaluation condition is false, we'll jump to an EndLoopBlock instruction,
    // popping the loop block off the stack.
    //
    // For example, for a loop block with 3 instructions in the body and 1 instruction in the condition
    // update block, we emit:
    //
    //   0  NewLoopBlock +8 +5  [break_target==8; continue_target==5]
    //   1  ForkIfFalse +6 [target==7]
    //   2  body_instruction
    //   3  body_instruction
    //   4  body_instruction
    //   5  condition_update_instruction
    //   6  Fork -5  [target==1]
    //   7  EndLoopBlock

    BytecodeBuilder bodyBytecode = body->CompileBytecode();
    BytecodeBuilder conditionUpdateBytecode = conditionUpdate->CompileBytecode();

    const auto totalBodyInstructionCount = bodyBytecode.GetInstructionCount() + conditionUpdateBytecode.GetInstructionCount();

    // The loop block encompasses all the instructions until EndLoopBlock (including EndLoopBlock). So the break offset (i.e.
    // the instruction to jump to when a break is encountered) is just after EndLoopBlock.
    const int breakLoopOffset = totalBodyInstructionCount + 4;
    // We want the continue to be just after the "main" body of the loop, as that puts us to the condition update block.
    // The jump back to the top of the loop follows that, so this way we ensure to update and then re-evaluate the
    // condition when continue is encountered.
    const int continueLoopOffset = bodyBytecode.GetInstructionCount() + 2;

    builder.Emit(bytecode::NewLoopBlock{ breakLoopOffset, continueLoopOffset });

    // If the condition is false, skip the entire body of the loop.
    builder.Emit(bytecode::ForkIfFalse{
        bytecode::OperandId{ conditionOperandId },
        totalBodyInstructionCount + 2,
    });

    // Emit the body of the loop. Our API allows users to separately specify a "body" and a "condition update" block for
    // convenience, but ultimately these are simply concatenated into the body of the loop.
    builder.CopyFromBuilder(bodyBytecode);
    builder.CopyFromBuilder(conditionUpdateBytecode);

    // Now we jump back to the instruction that evaluates the condition of the loop. It's the first instruction before the
    // full body that we just emitted.
    builder.Emit(bytecode::Fork{ -(totalBodyInstructionCount + 1) });

    builder.Emit(bytecode::EndLoopBlock{});
}

void RemoteOperationGraph::TryStatementNode::SerializeToBuilder(BytecodeBuilder& builder) const
{
    // The bytecode for a try block first emits a NewTryBlock instruction, pushing the try block to
    // the block stack. The try body follows. After this, we emit an EndTryBlock indicating that the
    // try body is successfully complete and popping the block off the stack. An unconditional jump
    // is then added so as to skip the catch body. Finally, we emit the catch body.
    //
    // For example, for a try block with 4 instructions in the try body and 2 instructions in the catch
    // body, we emit the following bytecode:
    //
    //   0  NewTryBlock +7 [catch_target==7]
    //   1  try_block_instruction
    //   2  try_block_instruction
    //   3  try_block_instruction
    //   4  try_block_instruction
    //   5  EndTryBlock
    //   6  Fork +3 [target==9]
    //   7  catch_instruction
    //   8  catch_instruction

    BytecodeBuilder tryBodyBytecode = tryBody->CompileBytecode();
    BytecodeBuilder catchBodyBytecode = catchBody->CompileBytecode();

    builder.Emit(bytecode::NewTryBlock{ tryBodyBytecode.GetInstructionCount() + 3 });
    builder.CopyFromBuilder(tryBodyBytecode);
    builder.Emit(bytecode::EndTryBlock{});

    // Skip the catch block if we manage to complete the try block successfully.
    builder.Emit(bytecode::Fork{ catchBodyBytecode.GetInstructionCount() + 1 });

    // Now the catch body.
    builder.CopyFromBuilder(catchBodyBytecode);

    // Insert a nop so we can guarantee that the jump at the end of the try block has a target.
    builder.Emit(bytecode::Nop{});
}
