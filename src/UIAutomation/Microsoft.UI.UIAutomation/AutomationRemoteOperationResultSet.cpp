// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "pch.h"
#include "AutomationRemoteOperationResultSet.h"

#include <winrt/windows.foundation.h>

namespace winrt
{
    using namespace winrt::Windows::UI::UIAutomation::Core;
}

namespace winrt::Microsoft::UI::UIAutomation::implementation
{
    winrt::hresult AutomationRemoteOperationResultSet::OperationStatus()
    {
        const auto status = m_result.Status();
        if (status == winrt::AutomationRemoteOperationStatus::InstructionLimitExceeded)
        {
            return E_FAIL;
        }
        else
        {
            return m_result.ExtendedError();
        }
    }

    winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationStatus AutomationRemoteOperationResultSet::Status()
    {
        return m_result.Status();
    }

    winrt::hresult AutomationRemoteOperationResultSet::ExtendedError()
    {
        return m_result.ExtendedError();
    }

    bool AutomationRemoteOperationResultSet::HasResult(Microsoft::UI::UIAutomation::AutomationRemoteOperationResponseToken const& token)
    {
        return m_result.HasOperand({ token.Value });
    }

    winrt::IInspectable AutomationRemoteOperationResultSet::GetResult(winrt::AutomationRemoteOperationResponseToken const& token)
    {
        return m_result.GetOperand({ token.Value });
    }
}
