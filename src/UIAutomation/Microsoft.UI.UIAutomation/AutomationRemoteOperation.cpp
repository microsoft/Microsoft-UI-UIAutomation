// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "AutomationRemoteOperation.h"
#include "AutomationRemoteOperation.g.cpp"
#include "Standins.h"

#include <wil/resource.h>

namespace winrt
{
    using namespace winrt::Microsoft::UI::UIAutomation;
    using namespace winrt::Windows::UI::UIAutomation;
}

namespace winrt::Microsoft::UI::UIAutomation::implementation
{
    AutomationRemoteOperation::AutomationRemoteOperation()
    {
        m_currentScope = m_rootGraph;
    }

    void AutomationRemoteOperation::InsertInstruction(const bytecode::Instruction& instruction)
    {
        m_currentScope->AddInstruction(instruction);
    }

    bytecode::OperandId AutomationRemoteOperation::GetNextId()
    {
        if (m_nextId == std::numeric_limits<decltype(m_nextId)>::max())
        {
            throw_hresult(E_UNEXPECTED);
        }

        return bytecode::OperandId{ m_nextId++ };
    }

    winrt::AutomationRemoteBool AutomationRemoteOperation::NewBool(bool initialValue)
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewBool{ newId, initialValue });

        return make<AutomationRemoteBool>(newId, *this);
    }

    winrt::AutomationRemoteInt AutomationRemoteOperation::NewInt(int32_t initialValue)
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewInt{ newId, initialValue });

        return make<AutomationRemoteInt>(newId, *this);
    }

    winrt::AutomationRemoteUint AutomationRemoteOperation::NewUint(uint32_t initialValue)
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewUint{ newId, initialValue });

        return make<AutomationRemoteUint>(newId, *this);
    }

    winrt::AutomationRemoteDouble AutomationRemoteOperation::NewDouble(double initialValue)
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewDouble{ newId, initialValue });

        return make<AutomationRemoteDouble>(newId, *this);
    }

    winrt::AutomationRemoteChar AutomationRemoteOperation::NewChar(wchar_t initialValue)
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewChar{ newId, initialValue });

        return make<AutomationRemoteChar>(newId, *this);
    }

    winrt::AutomationRemoteString AutomationRemoteOperation::NewString(hstring const& initialValue)
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewString{ newId, std::wstring{ initialValue } });

        return make<AutomationRemoteString>(newId, *this);
    }

    winrt::AutomationRemotePoint AutomationRemoteOperation::NewPoint(Windows::Foundation::Point const& initialValue)
    {
        const auto newId = GetNextId();
        UiaPoint uiaPoint{ initialValue.X, initialValue.Y };
        InsertInstruction(bytecode::NewPoint{ newId, uiaPoint });

        return make<AutomationRemotePoint>(newId, *this);
    }

    winrt::AutomationRemoteRect AutomationRemoteOperation::NewRect(Windows::Foundation::Rect const& initialValue)
    {
        const auto newId = GetNextId();
        UiaRect uiaRect{ initialValue.X, initialValue.Y, initialValue.Width, initialValue.Height };
        InsertInstruction(bytecode::NewRect{ newId, uiaRect });

        return make<AutomationRemoteRect>(newId, *this);
    }

    bool AutomationRemoteOperation::IsGuidSupported() const
    {
        return m_remoteOperation.IsOpcodeSupported(static_cast<uint32_t>(bytecode::InstructionType::NewGuid));
    }

    winrt::AutomationRemoteGuid AutomationRemoteOperation::NewGuid(const winrt::guid& initialValue)
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewGuid{ newId, initialValue });

        return make<AutomationRemoteGuid>(newId, *this);
    }

    bool AutomationRemoteOperation::IsCacheRequestSupported() const
    {
        return m_remoteOperation.IsOpcodeSupported(static_cast<uint32_t>(bytecode::InstructionType::NewCacheRequest));
    }

    winrt::AutomationRemoteCacheRequest AutomationRemoteOperation::NewCacheRequest()
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewCacheRequest{ newId });

        return make<AutomationRemoteCacheRequest>(newId, *this);
    }

    winrt::AutomationRemoteArray AutomationRemoteOperation::NewArray()
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewArray{ newId });

        return make<AutomationRemoteArray>(newId, *this);
    }

    winrt::AutomationRemoteStringMap AutomationRemoteOperation::NewStringMap()
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewStringMap{ newId });

        return make<AutomationRemoteStringMap>(newId, *this);
    }

    winrt::AutomationRemoteAnyObject AutomationRemoteOperation::NewNull()
    {
        const auto newId = GetNextId();
        InsertInstruction(bytecode::NewNull{ newId });

        return make<AutomationRemoteAnyObject>(newId, *this);
    }

    bool AutomationRemoteOperation::IsOpcodeSupported(const uint32_t opcode) const
    {
        return m_remoteOperation.IsOpcodeSupported(opcode);
    }

    winrt::AutomationRemoteElement AutomationRemoteOperation::ImportElement(winrt::AutomationElement const& element)
    {
        const auto elementId = GetNextId();
        m_remoteOperation.ImportElement({ elementId.Value }, element);
        const auto result = make<AutomationRemoteElement>(elementId, *this);

        return result;
    }

    winrt::AutomationRemoteTextRange AutomationRemoteOperation::ImportTextRange(winrt::AutomationTextRange const& textRange)
    {
        const auto textRangeId = GetNextId();
        m_remoteOperation.ImportTextRange({ textRangeId.Value }, textRange);

        const auto result = make<AutomationRemoteTextRange>(textRangeId, *this);
        return result;
    }

    void AutomationRemoteOperation::RequestResponse(bytecode::OperandId remoteOperationId)
    {
        m_remoteOperation.AddToResults({ remoteOperationId.Value });
    }

    AutomationRemoteOperationResponseToken AutomationRemoteOperation::RequestResponse(const winrt::AutomationRemoteObject& object)
    {
        const auto operandId = get_self<AutomationRemoteObject>(object)->OperandId();
        RequestResponse(operandId);
        return { operandId.Value };
    }

    void AutomationRemoteOperation::IfBlock(
        const winrt::AutomationRemoteBool& condition,
        const AutomationRemoteOperationScopeHandler& trueHandler,
        const AutomationRemoteOperationScopeHandler& falseHandler /* = nullptr */)
    {
        const auto conditionId = get_self<AutomationRemoteBool>(condition)->OperandId();
        const auto [trueScope, falseScope] = m_currentScope->AddIfStatement(conditionId.Value);

        const auto previousScope = m_currentScope;
        auto scopeExit = wil::scope_exit([&]()
        {
            m_currentScope = previousScope;
        });

        m_currentScope = trueScope;
        trueHandler();

        if (falseHandler)
        {
            m_currentScope = falseScope;
            falseHandler();
        }
    }

    void AutomationRemoteOperation::WhileBlock(
        const winrt::AutomationRemoteBool& condition,
        const AutomationRemoteOperationScopeHandler& loopBodyHandler,
        const AutomationRemoteOperationScopeHandler& loopConditionUpdateHandler)
    {
        const auto conditionId = get_self<AutomationRemoteBool>(condition)->OperandId();
        const auto [loopBodyScope, loopConditionUpdateScope] = m_currentScope->AddWhileLoop(conditionId.Value);

        const auto previousScope = m_currentScope;
        auto scopeExit = wil::scope_exit([&]()
        {
            m_currentScope = previousScope;
        });

        m_currentScope = loopBodyScope;
        loopBodyHandler();

        if (loopConditionUpdateHandler)
        {
            m_currentScope = loopConditionUpdateScope;
            loopConditionUpdateHandler();
        }
    }

    void AutomationRemoteOperation::ReturnOperationStatus(winrt::hresult status)
    {
        auto remoteErrorCode = NewInt(static_cast<int>(status));
        ReturnOperationStatus(remoteErrorCode);
    }

    void AutomationRemoteOperation::ReturnOperationStatus(const winrt::AutomationRemoteInt& status)
    {
        const auto operandId = get_self<AutomationRemoteInt>(status)->OperandId();
        InsertInstruction(bytecode::SetOperationStatus{ operandId });
        InsertInstruction(bytecode::Halt{});
    }

    void AutomationRemoteOperation::BreakLoop()
    {
        InsertInstruction(bytecode::BreakLoop{});
    }

    void AutomationRemoteOperation::ContinueLoop()
    {
        InsertInstruction(bytecode::ContinueLoop{});
    }

    void AutomationRemoteOperation::TryBlock(
        const AutomationRemoteOperationScopeHandler& tryBodyHandler)
    {
        TryBlock(tryBodyHandler, nullptr /* exceptBlockHandler */);
    }

    void AutomationRemoteOperation::TryBlock(
        const AutomationRemoteOperationScopeHandler& tryBodyHandler,
        const AutomationRemoteOperationScopeHandler& exceptBlockHandler)
    {
        const auto [tryBodyScope, exceptBlockScope] = m_currentScope->AddTryStatement();

        const auto previousScope = m_currentScope;
        auto scopeExit = wil::scope_exit([&]()
        {
            m_currentScope = previousScope;
        });

        m_currentScope = tryBodyScope;
        tryBodyHandler();

        if (exceptBlockHandler)
        {
            m_currentScope = exceptBlockScope;
            exceptBlockHandler();
        }

        // No matter what, the except block executes a special instruction that clears the extended error code
        // that was set by the error. This way, once the except block is complete, we've cleared the extended
        // error code back to S_OK/success.
        const auto newId = GetNextId();
        exceptBlockScope->AddInstruction(bytecode::NewInt{ newId, S_OK });
        exceptBlockScope->AddInstruction(bytecode::SetOperationStatus{ newId });
    }

    winrt::AutomationRemoteInt AutomationRemoteOperation::GetCurrentFailureCode()
    {
        const auto resultId = GetNextId();
        InsertInstruction(bytecode::GetOperationStatus{ resultId });

        return make<AutomationRemoteInt>(resultId, *this);
    }

    winrt::AutomationRemoteOperationResultSet AutomationRemoteOperation::Execute()
    {
        auto serializedBytecode = m_rootGraph->Serialize();
        auto result = m_remoteOperation.Execute(serializedBytecode);

        // We wrap the platform result into the Result Set that the higher-level API operates on.
        auto resultSet = make<AutomationRemoteOperationResultSet>(std::move(result));

        return resultSet;
    }
}
