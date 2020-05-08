// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once
#include "AutomationRemoteOperationResultSet.g.h"

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.UIAutomation.h>
#include <winrt/Windows.UI.UIAutomation.Core.h>

namespace winrt
{
    using namespace winrt::Microsoft::UI::UIAutomation;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::Foundation::Collections;
}

namespace winrt::Microsoft::UI::UIAutomation::implementation
{
    // This class represents the results that we get back after executing a RemoteOperation.
    //
    // It exposes an interface that allows callers to look up results based on ResponseTokens that were
    // previously produced by the remote operation.
    //
    // The result is always a generic IInspectable and the client needs to convert it to the appropriate local
    // representation that matches the remote stand-in object that was requested as a result.
    //
    // The client can also "interrogate" this type (QueryInterface) to work out what the local type really is.
    //
    // Scalar values (such as ints, doubles, Rects, Points, etc.) will be represented by a boxed IInspectable; the
    // client should simply unbox it.
    struct AutomationRemoteOperationResultSet : AutomationRemoteOperationResultSetT<AutomationRemoteOperationResultSet>
    {
        explicit AutomationRemoteOperationResultSet(winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationResult result) :
            m_result(std::move(result))
        {
        }

        winrt::hresult OperationStatus();

        bool HasResult(winrt::AutomationRemoteOperationResponseToken const& token);
        winrt::IInspectable GetResult(winrt::AutomationRemoteOperationResponseToken const& token);

    private:
        winrt::Windows::UI::UIAutomation::Core::AutomationRemoteOperationResult m_result;
    };
}
