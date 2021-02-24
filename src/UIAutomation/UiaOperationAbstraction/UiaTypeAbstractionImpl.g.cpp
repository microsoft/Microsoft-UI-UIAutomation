// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// WARNING: Please don't edit this file. It was generated.

    UiaInvokePattern::UiaInvokePattern(_In_ IUIAutomationInvokePattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaInvokePattern::UiaInvokePattern(winrt::com_ptr<IUIAutomationInvokePattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaInvokePattern::UiaInvokePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteInvokePattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaInvokePattern::UiaInvokePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsInvokePattern())
    {
    }

    UiaInvokePattern::operator winrt::com_ptr<IUIAutomationInvokePattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationInvokePattern>>(m_member);
    }

    UiaInvokePattern::operator wil::com_ptr<IUIAutomationInvokePattern>() const
    {
        return wil::com_ptr<IUIAutomationInvokePattern>(std::get<winrt::com_ptr<IUIAutomationInvokePattern>>(m_member).get());
    }

    IUIAutomationInvokePattern* UiaInvokePattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationInvokePattern>>(m_member).get();
    }

    void UiaInvokePattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationInvokePattern>>(m_member) = nullptr;
    }

    IUIAutomationInvokePattern** UiaInvokePattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationInvokePattern>>(m_member).put();
    }


    UiaBool UiaInvokePattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteInvokePattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    void UiaInvokePattern::Invoke()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteInvokePattern>(m_member).Invoke();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationInvokePattern>>(m_member)->Invoke());
    }

    UiaSelectionPattern::UiaSelectionPattern(_In_ IUIAutomationSelectionPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaSelectionPattern::UiaSelectionPattern(winrt::com_ptr<IUIAutomationSelectionPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSelectionPattern::UiaSelectionPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSelectionPattern::UiaSelectionPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsSelectionPattern())
    {
    }

    UiaSelectionPattern::operator winrt::com_ptr<IUIAutomationSelectionPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member);
    }

    UiaSelectionPattern::operator wil::com_ptr<IUIAutomationSelectionPattern>() const
    {
        return wil::com_ptr<IUIAutomationSelectionPattern>(std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member).get());
    }

    IUIAutomationSelectionPattern* UiaSelectionPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member).get();
    }

    void UiaSelectionPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member) = nullptr;
    }

    IUIAutomationSelectionPattern** UiaSelectionPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member).put();
    }


    UiaBool UiaSelectionPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteSelectionPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaArray<UiaElement> UiaSelectionPattern::GetSelection(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionPattern>(m_member).GetSelection();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedSelection(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentSelection(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaBool UiaSelectionPattern::GetCanSelectMultiple(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionPattern>(m_member).GetCanSelectMultiple();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCanSelectMultiple(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCanSelectMultiple(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaSelectionPattern::GetIsSelectionRequired(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionPattern>(m_member).GetIsSelectionRequired();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsSelectionRequired(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsSelectionRequired(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaValuePattern::UiaValuePattern(_In_ IUIAutomationValuePattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaValuePattern::UiaValuePattern(winrt::com_ptr<IUIAutomationValuePattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaValuePattern::UiaValuePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteValuePattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaValuePattern::UiaValuePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsValuePattern())
    {
    }

    UiaValuePattern::operator winrt::com_ptr<IUIAutomationValuePattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member);
    }

    UiaValuePattern::operator wil::com_ptr<IUIAutomationValuePattern>() const
    {
        return wil::com_ptr<IUIAutomationValuePattern>(std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member).get());
    }

    IUIAutomationValuePattern* UiaValuePattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member).get();
    }

    void UiaValuePattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member) = nullptr;
    }

    IUIAutomationValuePattern** UiaValuePattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member).put();
    }


    UiaBool UiaValuePattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteValuePattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaString UiaValuePattern::GetValue(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteValuePattern>(m_member).GetValue();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedValue(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentValue(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaValuePattern::GetIsReadOnly(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteValuePattern>(m_member).GetIsReadOnly();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsReadOnly(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsReadOnly(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaValuePattern::SetValue(UiaString val)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            val.ToRemote();
            std::get<AutomationRemoteValuePattern>(m_member).SetValue(
                val);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member)->SetValue(
            val.get()));
    }

    UiaRangeValuePattern::UiaRangeValuePattern(_In_ IUIAutomationRangeValuePattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaRangeValuePattern::UiaRangeValuePattern(winrt::com_ptr<IUIAutomationRangeValuePattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaRangeValuePattern::UiaRangeValuePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteRangeValuePattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaRangeValuePattern::UiaRangeValuePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsRangeValuePattern())
    {
    }

    UiaRangeValuePattern::operator winrt::com_ptr<IUIAutomationRangeValuePattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member);
    }

    UiaRangeValuePattern::operator wil::com_ptr<IUIAutomationRangeValuePattern>() const
    {
        return wil::com_ptr<IUIAutomationRangeValuePattern>(std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member).get());
    }

    IUIAutomationRangeValuePattern* UiaRangeValuePattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member).get();
    }

    void UiaRangeValuePattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member) = nullptr;
    }

    IUIAutomationRangeValuePattern** UiaRangeValuePattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member).put();
    }


    UiaBool UiaRangeValuePattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteRangeValuePattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaDouble UiaRangeValuePattern::GetValue(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteRangeValuePattern>(m_member).GetValue();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedValue(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentValue(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaRangeValuePattern::GetIsReadOnly(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteRangeValuePattern>(m_member).GetIsReadOnly();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsReadOnly(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsReadOnly(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaRangeValuePattern::GetMaximum(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteRangeValuePattern>(m_member).GetMaximum();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedMaximum(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentMaximum(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaRangeValuePattern::GetMinimum(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteRangeValuePattern>(m_member).GetMinimum();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedMinimum(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentMinimum(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaRangeValuePattern::GetLargeChange(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteRangeValuePattern>(m_member).GetLargeChange();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedLargeChange(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentLargeChange(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaRangeValuePattern::GetSmallChange(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteRangeValuePattern>(m_member).GetSmallChange();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedSmallChange(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentSmallChange(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaRangeValuePattern::SetValue(UiaDouble val)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            val.ToRemote();
            std::get<AutomationRemoteRangeValuePattern>(m_member).SetValue(
                val);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member)->SetValue(
            val));
    }

    UiaScrollPattern::UiaScrollPattern(_In_ IUIAutomationScrollPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaScrollPattern::UiaScrollPattern(winrt::com_ptr<IUIAutomationScrollPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaScrollPattern::UiaScrollPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteScrollPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaScrollPattern::UiaScrollPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsScrollPattern())
    {
    }

    UiaScrollPattern::operator winrt::com_ptr<IUIAutomationScrollPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member);
    }

    UiaScrollPattern::operator wil::com_ptr<IUIAutomationScrollPattern>() const
    {
        return wil::com_ptr<IUIAutomationScrollPattern>(std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member).get());
    }

    IUIAutomationScrollPattern* UiaScrollPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member).get();
    }

    void UiaScrollPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member) = nullptr;
    }

    IUIAutomationScrollPattern** UiaScrollPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member).put();
    }


    UiaBool UiaScrollPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteScrollPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaDouble UiaScrollPattern::GetHorizontalScrollPercent(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteScrollPattern>(m_member).GetHorizontalScrollPercent();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedHorizontalScrollPercent(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentHorizontalScrollPercent(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaScrollPattern::GetVerticalScrollPercent(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteScrollPattern>(m_member).GetVerticalScrollPercent();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedVerticalScrollPercent(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentVerticalScrollPercent(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaScrollPattern::GetHorizontalViewSize(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteScrollPattern>(m_member).GetHorizontalViewSize();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedHorizontalViewSize(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentHorizontalViewSize(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaScrollPattern::GetVerticalViewSize(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteScrollPattern>(m_member).GetVerticalViewSize();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedVerticalViewSize(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentVerticalViewSize(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaScrollPattern::GetHorizontallyScrollable(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteScrollPattern>(m_member).GetHorizontallyScrollable();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedHorizontallyScrollable(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentHorizontallyScrollable(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaScrollPattern::GetVerticallyScrollable(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteScrollPattern>(m_member).GetVerticallyScrollable();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedVerticallyScrollable(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentVerticallyScrollable(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaScrollPattern::Scroll(UiaScrollAmount horizontalAmount, UiaScrollAmount verticalAmount)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            horizontalAmount.ToRemote();
            verticalAmount.ToRemote();
            std::get<AutomationRemoteScrollPattern>(m_member).Scroll(
                horizontalAmount,
                verticalAmount);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member)->Scroll(
            horizontalAmount,
            verticalAmount));
    }

    void UiaScrollPattern::SetScrollPercent(UiaDouble horizontalPercent, UiaDouble verticalPercent)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            horizontalPercent.ToRemote();
            verticalPercent.ToRemote();
            std::get<AutomationRemoteScrollPattern>(m_member).SetScrollPercent(
                horizontalPercent,
                verticalPercent);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member)->SetScrollPercent(
            horizontalPercent,
            verticalPercent));
    }

    UiaExpandCollapsePattern::UiaExpandCollapsePattern(_In_ IUIAutomationExpandCollapsePattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaExpandCollapsePattern::UiaExpandCollapsePattern(winrt::com_ptr<IUIAutomationExpandCollapsePattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaExpandCollapsePattern::UiaExpandCollapsePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteExpandCollapsePattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaExpandCollapsePattern::UiaExpandCollapsePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsExpandCollapsePattern())
    {
    }

    UiaExpandCollapsePattern::operator winrt::com_ptr<IUIAutomationExpandCollapsePattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member);
    }

    UiaExpandCollapsePattern::operator wil::com_ptr<IUIAutomationExpandCollapsePattern>() const
    {
        return wil::com_ptr<IUIAutomationExpandCollapsePattern>(std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member).get());
    }

    IUIAutomationExpandCollapsePattern* UiaExpandCollapsePattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member).get();
    }

    void UiaExpandCollapsePattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member) = nullptr;
    }

    IUIAutomationExpandCollapsePattern** UiaExpandCollapsePattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member).put();
    }


    UiaBool UiaExpandCollapsePattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteExpandCollapsePattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaExpandCollapseState UiaExpandCollapsePattern::GetExpandCollapseState(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteExpandCollapsePattern>(m_member).GetExpandCollapseState();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member);
        ExpandCollapseState localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedExpandCollapseState(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentExpandCollapseState(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaExpandCollapsePattern::Expand()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteExpandCollapsePattern>(m_member).Expand();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member)->Expand());
    }

    void UiaExpandCollapsePattern::Collapse()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteExpandCollapsePattern>(m_member).Collapse();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member)->Collapse());
    }

    UiaGridPattern::UiaGridPattern(_In_ IUIAutomationGridPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaGridPattern::UiaGridPattern(winrt::com_ptr<IUIAutomationGridPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaGridPattern::UiaGridPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteGridPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaGridPattern::UiaGridPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsGridPattern())
    {
    }

    UiaGridPattern::operator winrt::com_ptr<IUIAutomationGridPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member);
    }

    UiaGridPattern::operator wil::com_ptr<IUIAutomationGridPattern>() const
    {
        return wil::com_ptr<IUIAutomationGridPattern>(std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member).get());
    }

    IUIAutomationGridPattern* UiaGridPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member).get();
    }

    void UiaGridPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member) = nullptr;
    }

    IUIAutomationGridPattern** UiaGridPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member).put();
    }


    UiaBool UiaGridPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteGridPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaInt UiaGridPattern::GetRowCount(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteGridPattern>(m_member).GetRowCount();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedRowCount(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentRowCount(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaGridPattern::GetColumnCount(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteGridPattern>(m_member).GetColumnCount();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedColumnCount(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentColumnCount(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaElement UiaGridPattern::GetItem(UiaInt row, UiaInt column)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            row.ToRemote();
            column.ToRemote();
            return std::get<AutomationRemoteGridPattern>(m_member).GetItem(
                row,
                column);
        }

        winrt::com_ptr<IUIAutomationElement> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member)->GetItem(
            row,
            column,
            outValue.put()));
        return outValue;
    }

    UiaGridItemPattern::UiaGridItemPattern(_In_ IUIAutomationGridItemPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaGridItemPattern::UiaGridItemPattern(winrt::com_ptr<IUIAutomationGridItemPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaGridItemPattern::UiaGridItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteGridItemPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaGridItemPattern::UiaGridItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsGridItemPattern())
    {
    }

    UiaGridItemPattern::operator winrt::com_ptr<IUIAutomationGridItemPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member);
    }

    UiaGridItemPattern::operator wil::com_ptr<IUIAutomationGridItemPattern>() const
    {
        return wil::com_ptr<IUIAutomationGridItemPattern>(std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member).get());
    }

    IUIAutomationGridItemPattern* UiaGridItemPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member).get();
    }

    void UiaGridItemPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member) = nullptr;
    }

    IUIAutomationGridItemPattern** UiaGridItemPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member).put();
    }


    UiaBool UiaGridItemPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteGridItemPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaElement UiaGridItemPattern::GetContainingGrid(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteGridItemPattern>(m_member).GetContainingGrid();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member);
        winrt::com_ptr<IUIAutomationElement> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedContainingGrid(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentContainingGrid(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaInt UiaGridItemPattern::GetRow(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteGridItemPattern>(m_member).GetRow();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedRow(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentRow(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaGridItemPattern::GetColumn(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteGridItemPattern>(m_member).GetColumn();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedColumn(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentColumn(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaGridItemPattern::GetRowSpan(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteGridItemPattern>(m_member).GetRowSpan();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedRowSpan(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentRowSpan(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaGridItemPattern::GetColumnSpan(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteGridItemPattern>(m_member).GetColumnSpan();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedColumnSpan(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentColumnSpan(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaMultipleViewPattern::UiaMultipleViewPattern(_In_ IUIAutomationMultipleViewPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaMultipleViewPattern::UiaMultipleViewPattern(winrt::com_ptr<IUIAutomationMultipleViewPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaMultipleViewPattern::UiaMultipleViewPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteMultipleViewPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaMultipleViewPattern::UiaMultipleViewPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsMultipleViewPattern())
    {
    }

    UiaMultipleViewPattern::operator winrt::com_ptr<IUIAutomationMultipleViewPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member);
    }

    UiaMultipleViewPattern::operator wil::com_ptr<IUIAutomationMultipleViewPattern>() const
    {
        return wil::com_ptr<IUIAutomationMultipleViewPattern>(std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member).get());
    }

    IUIAutomationMultipleViewPattern* UiaMultipleViewPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member).get();
    }

    void UiaMultipleViewPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member) = nullptr;
    }

    IUIAutomationMultipleViewPattern** UiaMultipleViewPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member).put();
    }


    UiaBool UiaMultipleViewPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteMultipleViewPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaInt UiaMultipleViewPattern::GetCurrentView(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteMultipleViewPattern>(m_member).GetCurrentView();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCurrentView(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCurrentView(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaInt> UiaMultipleViewPattern::GetSupportedViews(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteMultipleViewPattern>(m_member).GetSupportedViews();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member);
        unique_safearray localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedSupportedViews(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentSupportedViews(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaMultipleViewPattern::GetViewName(UiaInt view)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            view.ToRemote();
            return std::get<AutomationRemoteMultipleViewPattern>(m_member).GetViewName(
                view);
        }

        wil::unique_bstr outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member)->GetViewName(
            view,
            &outValue));
        return outValue;
    }

    void UiaMultipleViewPattern::SetCurrentView(UiaInt view)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            view.ToRemote();
            std::get<AutomationRemoteMultipleViewPattern>(m_member).SetCurrentView(
                view);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member)->SetCurrentView(
            view));
    }

    UiaWindowPattern::UiaWindowPattern(_In_ IUIAutomationWindowPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaWindowPattern::UiaWindowPattern(winrt::com_ptr<IUIAutomationWindowPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaWindowPattern::UiaWindowPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteWindowPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaWindowPattern::UiaWindowPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsWindowPattern())
    {
    }

    UiaWindowPattern::operator winrt::com_ptr<IUIAutomationWindowPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member);
    }

    UiaWindowPattern::operator wil::com_ptr<IUIAutomationWindowPattern>() const
    {
        return wil::com_ptr<IUIAutomationWindowPattern>(std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member).get());
    }

    IUIAutomationWindowPattern* UiaWindowPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member).get();
    }

    void UiaWindowPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member) = nullptr;
    }

    IUIAutomationWindowPattern** UiaWindowPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member).put();
    }


    UiaBool UiaWindowPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteWindowPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaBool UiaWindowPattern::GetCanMaximize(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteWindowPattern>(m_member).GetCanMaximize();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCanMaximize(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCanMaximize(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaWindowPattern::GetCanMinimize(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteWindowPattern>(m_member).GetCanMinimize();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCanMinimize(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCanMinimize(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaWindowPattern::GetIsModal(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteWindowPattern>(m_member).GetIsModal();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsModal(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsModal(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaWindowPattern::GetIsTopmost(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteWindowPattern>(m_member).GetIsTopmost();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsTopmost(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsTopmost(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaWindowVisualState UiaWindowPattern::GetWindowVisualState(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteWindowPattern>(m_member).GetWindowVisualState();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member);
        WindowVisualState localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedWindowVisualState(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentWindowVisualState(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaWindowInteractionState UiaWindowPattern::GetWindowInteractionState(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteWindowPattern>(m_member).GetWindowInteractionState();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member);
        WindowInteractionState localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedWindowInteractionState(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentWindowInteractionState(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaWindowPattern::Close()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteWindowPattern>(m_member).Close();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member)->Close());
    }

    UiaBool UiaWindowPattern::WaitForInputIdle(UiaInt milliseconds)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            milliseconds.ToRemote();
            return std::get<AutomationRemoteWindowPattern>(m_member).WaitForInputIdle(
                milliseconds);
        }

        BOOL outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member)->WaitForInputIdle(
            milliseconds,
            &outValue));
        return outValue;
    }

    void UiaWindowPattern::SetWindowVisualState(UiaWindowVisualState state)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            state.ToRemote();
            std::get<AutomationRemoteWindowPattern>(m_member).SetWindowVisualState(
                state);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member)->SetWindowVisualState(
            state));
    }

    UiaSelectionItemPattern::UiaSelectionItemPattern(_In_ IUIAutomationSelectionItemPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaSelectionItemPattern::UiaSelectionItemPattern(winrt::com_ptr<IUIAutomationSelectionItemPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSelectionItemPattern::UiaSelectionItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionItemPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSelectionItemPattern::UiaSelectionItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsSelectionItemPattern())
    {
    }

    UiaSelectionItemPattern::operator winrt::com_ptr<IUIAutomationSelectionItemPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member);
    }

    UiaSelectionItemPattern::operator wil::com_ptr<IUIAutomationSelectionItemPattern>() const
    {
        return wil::com_ptr<IUIAutomationSelectionItemPattern>(std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member).get());
    }

    IUIAutomationSelectionItemPattern* UiaSelectionItemPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member).get();
    }

    void UiaSelectionItemPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member) = nullptr;
    }

    IUIAutomationSelectionItemPattern** UiaSelectionItemPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member).put();
    }


    UiaBool UiaSelectionItemPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteSelectionItemPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaBool UiaSelectionItemPattern::GetIsSelected(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionItemPattern>(m_member).GetIsSelected();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsSelected(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsSelected(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaElement UiaSelectionItemPattern::GetSelectionContainer(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionItemPattern>(m_member).GetSelectionContainer();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member);
        winrt::com_ptr<IUIAutomationElement> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedSelectionContainer(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentSelectionContainer(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    void UiaSelectionItemPattern::Select()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteSelectionItemPattern>(m_member).Select();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member)->Select());
    }

    void UiaSelectionItemPattern::AddToSelection()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteSelectionItemPattern>(m_member).AddToSelection();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member)->AddToSelection());
    }

    void UiaSelectionItemPattern::RemoveFromSelection()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteSelectionItemPattern>(m_member).RemoveFromSelection();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member)->RemoveFromSelection());
    }

    UiaDockPattern::UiaDockPattern(_In_ IUIAutomationDockPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaDockPattern::UiaDockPattern(winrt::com_ptr<IUIAutomationDockPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaDockPattern::UiaDockPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDockPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaDockPattern::UiaDockPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsDockPattern())
    {
    }

    UiaDockPattern::operator winrt::com_ptr<IUIAutomationDockPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member);
    }

    UiaDockPattern::operator wil::com_ptr<IUIAutomationDockPattern>() const
    {
        return wil::com_ptr<IUIAutomationDockPattern>(std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member).get());
    }

    IUIAutomationDockPattern* UiaDockPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member).get();
    }

    void UiaDockPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member) = nullptr;
    }

    IUIAutomationDockPattern** UiaDockPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member).put();
    }


    UiaBool UiaDockPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteDockPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaDockPosition UiaDockPattern::GetDockPosition(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteDockPattern>(m_member).GetDockPosition();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member);
        DockPosition localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDockPosition(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDockPosition(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaDockPattern::SetDockPosition(UiaDockPosition dockPos)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            dockPos.ToRemote();
            std::get<AutomationRemoteDockPattern>(m_member).SetDockPosition(
                dockPos);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member)->SetDockPosition(
            dockPos));
    }

    UiaTablePattern::UiaTablePattern(_In_ IUIAutomationTablePattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTablePattern::UiaTablePattern(winrt::com_ptr<IUIAutomationTablePattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTablePattern::UiaTablePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTablePattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTablePattern::UiaTablePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTablePattern())
    {
    }

    UiaTablePattern::operator winrt::com_ptr<IUIAutomationTablePattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member);
    }

    UiaTablePattern::operator wil::com_ptr<IUIAutomationTablePattern>() const
    {
        return wil::com_ptr<IUIAutomationTablePattern>(std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member).get());
    }

    IUIAutomationTablePattern* UiaTablePattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member).get();
    }

    void UiaTablePattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member) = nullptr;
    }

    IUIAutomationTablePattern** UiaTablePattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member).put();
    }


    UiaBool UiaTablePattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTablePattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaArray<UiaElement> UiaTablePattern::GetRowHeaders(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTablePattern>(m_member).GetRowHeaders();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedRowHeaders(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentRowHeaders(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaTablePattern::GetColumnHeaders(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTablePattern>(m_member).GetColumnHeaders();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedColumnHeaders(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentColumnHeaders(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaRowOrColumnMajor UiaTablePattern::GetRowOrColumnMajor(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTablePattern>(m_member).GetRowOrColumnMajor();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member);
        RowOrColumnMajor localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedRowOrColumnMajor(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentRowOrColumnMajor(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaTableItemPattern::UiaTableItemPattern(_In_ IUIAutomationTableItemPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTableItemPattern::UiaTableItemPattern(winrt::com_ptr<IUIAutomationTableItemPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTableItemPattern::UiaTableItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTableItemPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTableItemPattern::UiaTableItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTableItemPattern())
    {
    }

    UiaTableItemPattern::operator winrt::com_ptr<IUIAutomationTableItemPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member);
    }

    UiaTableItemPattern::operator wil::com_ptr<IUIAutomationTableItemPattern>() const
    {
        return wil::com_ptr<IUIAutomationTableItemPattern>(std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member).get());
    }

    IUIAutomationTableItemPattern* UiaTableItemPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member).get();
    }

    void UiaTableItemPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member) = nullptr;
    }

    IUIAutomationTableItemPattern** UiaTableItemPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member).put();
    }


    UiaBool UiaTableItemPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTableItemPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaArray<UiaElement> UiaTableItemPattern::GetRowHeaderItems(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTableItemPattern>(m_member).GetRowHeaderItems();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedRowHeaderItems(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentRowHeaderItems(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaTableItemPattern::GetColumnHeaderItems(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTableItemPattern>(m_member).GetColumnHeaderItems();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedColumnHeaderItems(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentColumnHeaderItems(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaTextRange::UiaTextRange(_In_ IUIAutomationTextRange* object):
        UiaTypeBase(MakeWinrtComPtr(object))
    {
        ToRemote();
    }

    UiaTextRange::UiaTextRange(winrt::com_ptr<IUIAutomationTextRange> const& object):
        UiaTypeBase(object)
    {
        ToRemote();
    }

    UiaTextRange::UiaTextRange(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextRange const& object):
        UiaTypeBase(object)
    {
    }

    UiaTextRange::UiaTextRange(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& object):
        UiaTypeBase(object.AsTextRange())
    {
    }

    UiaTextRange& UiaTextRange::operator=(const UiaTextRange& other)
    {
        AssignCopyTo<UiaTextRange>(m_member, other.m_member);
        return *this;
    }

    UiaTextRange::operator winrt::com_ptr<IUIAutomationTextRange>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member);
    }

    UiaTextRange::operator wil::com_ptr<IUIAutomationTextRange>() const
    {
        return wil::com_ptr<IUIAutomationTextRange>(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member).get());
    }

    IUIAutomationTextRange* UiaTextRange::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member).get();
    }

    void UiaTextRange::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member) = nullptr;
    }

    IUIAutomationTextRange** UiaTextRange::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member).put();
    }


    UiaBool UiaTextRange::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTextRange>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaTextRange UiaTextRange::Clone()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).Clone();
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->Clone(
            outValue.put()));
        return outValue;
    }

    UiaBool UiaTextRange::Compare(UiaTextRange range)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            range.ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).Compare(
                range);
        }

        BOOL outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->Compare(
            range.get(),
            &outValue));
        return outValue;
    }

    UiaInt UiaTextRange::CompareEndpoints(UiaTextPatternRangeEndpoint srcEndPoint, UiaTextRange range, UiaTextPatternRangeEndpoint targetEndPoint)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            srcEndPoint.ToRemote();
            range.ToRemote();
            targetEndPoint.ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).CompareEndpoints(
                srcEndPoint,
                range,
                targetEndPoint);
        }

        int outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->CompareEndpoints(
            srcEndPoint,
            range.get(),
            targetEndPoint,
            &outValue));
        return outValue;
    }

    void UiaTextRange::ExpandToEnclosingUnit(UiaTextUnit TextUnit)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            TextUnit.ToRemote();
            std::get<AutomationRemoteTextRange>(m_member).ExpandToEnclosingUnit(
                TextUnit);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->ExpandToEnclosingUnit(
            TextUnit));
    }

    UiaTextRange UiaTextRange::FindAttribute(UiaTextAttributeId attr, UiaVariant val, UiaBool backward)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            attr.ToRemote();
            val.ToRemote();
            backward.ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).FindAttribute(
                attr,
                val,
                backward);
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->FindAttribute(
            attr,
            val.get(),
            backward,
            outValue.put()));
        return outValue;
    }

    UiaTextRange UiaTextRange::FindText(UiaString text, UiaBool backward, UiaBool ignoreCase)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            text.ToRemote();
            backward.ToRemote();
            ignoreCase.ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).FindText(
                text,
                backward,
                ignoreCase);
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->FindText(
            text.get(),
            backward,
            ignoreCase,
            outValue.put()));
        return outValue;
    }

    UiaVariant UiaTextRange::GetAttributeValue(UiaTextAttributeId attr)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            attr.ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).GetAttributeValue(
                attr);
        }

        wil::unique_variant outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->GetAttributeValue(
            attr,
            &outValue));
        return outValue;
    }

    UiaArray<UiaRect> UiaTextRange::GetBoundingRectangles()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).GetBoundingRectangles();
        }

        unique_safearray outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->GetBoundingRectangles(
            &outValue));
        return outValue;
    }

    UiaElement UiaTextRange::GetEnclosingElement(std::optional<UiaCacheRequest> cacheRequest /* = std::nullopt */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            auto result = std::get<AutomationRemoteTextRange>(m_member).GetEnclosingElement();
            if (cacheRequest)
            {
                PopulateCacheHelper(result, *cacheRequest);
            }
            return result;
        }

        winrt::com_ptr<IUIAutomationElement> outValue;
        if (cacheRequest)
        {
            winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member).as<IUIAutomationTextRange3>()->GetEnclosingElementBuildCache(
                (*cacheRequest.value()).get(),
                outValue.put()));
        }
        else
        {
            winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->GetEnclosingElement(
                outValue.put()));
        }
        return outValue;
    }

    UiaString UiaTextRange::GetText(UiaInt maxLength)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            maxLength.ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).GetText(
                maxLength);
        }

        wil::unique_bstr outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->GetText(
            maxLength,
            &outValue));
        return outValue;
    }

    UiaInt UiaTextRange::Move(UiaTextUnit unit, UiaInt count)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            unit.ToRemote();
            count.ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).Move(
                unit,
                count);
        }

        int outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->Move(
            unit,
            count,
            &outValue));
        return outValue;
    }

    UiaInt UiaTextRange::MoveEndpointByUnit(UiaTextPatternRangeEndpoint endpoint, UiaTextUnit unit, UiaInt count)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            endpoint.ToRemote();
            unit.ToRemote();
            count.ToRemote();
            return std::get<AutomationRemoteTextRange>(m_member).MoveEndpointByUnit(
                endpoint,
                unit,
                count);
        }

        int outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->MoveEndpointByUnit(
            endpoint,
            unit,
            count,
            &outValue));
        return outValue;
    }

    void UiaTextRange::MoveEndpointByRange(UiaTextPatternRangeEndpoint srcEndPoint, UiaTextRange range, UiaTextPatternRangeEndpoint targetEndPoint)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            srcEndPoint.ToRemote();
            range.ToRemote();
            targetEndPoint.ToRemote();
            std::get<AutomationRemoteTextRange>(m_member).MoveEndpointByRange(
                srcEndPoint,
                range,
                targetEndPoint);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->MoveEndpointByRange(
            srcEndPoint,
            range.get(),
            targetEndPoint));
    }

    void UiaTextRange::Select()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            std::get<AutomationRemoteTextRange>(m_member).Select();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->Select());
    }

    void UiaTextRange::AddToSelection()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            std::get<AutomationRemoteTextRange>(m_member).AddToSelection();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->AddToSelection());
    }

    void UiaTextRange::RemoveFromSelection()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            std::get<AutomationRemoteTextRange>(m_member).RemoveFromSelection();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->RemoveFromSelection());
    }

    void UiaTextRange::ScrollIntoView(UiaBool alignToTop)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            alignToTop.ToRemote();
            std::get<AutomationRemoteTextRange>(m_member).ScrollIntoView(
                alignToTop);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->ScrollIntoView(
            alignToTop));
    }

    UiaArray<UiaElement> UiaTextRange::GetChildren(std::optional<UiaCacheRequest> cacheRequest /* = std::nullopt */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            auto result = std::get<AutomationRemoteTextRange>(m_member).GetChildren();
            if (cacheRequest)
            {
                PopulateCacheHelper(result, *cacheRequest);
            }
            return result;
        }

        winrt::com_ptr<IUIAutomationElementArray> outValue;
        if (cacheRequest)
        {
            winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member).as<IUIAutomationTextRange3>()->GetChildrenBuildCache(
                (*cacheRequest.value()).get(),
                outValue.put()));
        }
        else
        {
            winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member)->GetChildren(
                outValue.put()));
        }
        return outValue;
    }

    void UiaTextRange::ShowContextMenu()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            std::get<AutomationRemoteTextRange>(m_member).ShowContextMenu();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member).as<IUIAutomationTextRange2>()->ShowContextMenu());
    }

    UiaTextPattern::UiaTextPattern(_In_ IUIAutomationTextPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTextPattern::UiaTextPattern(winrt::com_ptr<IUIAutomationTextPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTextPattern::UiaTextPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTextPattern::UiaTextPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTextPattern())
    {
    }

    UiaTextPattern::operator winrt::com_ptr<IUIAutomationTextPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member);
    }

    UiaTextPattern::operator wil::com_ptr<IUIAutomationTextPattern>() const
    {
        return wil::com_ptr<IUIAutomationTextPattern>(std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member).get());
    }

    IUIAutomationTextPattern* UiaTextPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member).get();
    }

    void UiaTextPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member) = nullptr;
    }

    IUIAutomationTextPattern** UiaTextPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member).put();
    }


    UiaBool UiaTextPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTextPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaTextRange UiaTextPattern::RangeFromPoint(UiaPoint pt)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            pt.ToRemote();
            return std::get<AutomationRemoteTextPattern>(m_member).RangeFromPoint(
                pt);
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member)->RangeFromPoint(
            pt,
            outValue.put()));
        return outValue;
    }

    UiaTextRange UiaTextPattern::RangeFromChild(UiaElement child)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            child.ToRemote();
            return std::get<AutomationRemoteTextPattern>(m_member).RangeFromChild(
                child);
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member)->RangeFromChild(
            child.get(),
            outValue.put()));
        return outValue;
    }

    UiaArray<UiaTextRange> UiaTextPattern::GetSelection()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTextPattern>(m_member).GetSelection();
        }

        winrt::com_ptr<IUIAutomationTextRangeArray> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member)->GetSelection(
            outValue.put()));
        return outValue;
    }

    UiaArray<UiaTextRange> UiaTextPattern::GetVisibleRanges()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTextPattern>(m_member).GetVisibleRanges();
        }

        winrt::com_ptr<IUIAutomationTextRangeArray> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member)->GetVisibleRanges(
            outValue.put()));
        return outValue;
    }

    UiaTextRange UiaTextPattern::GetDocumentRange()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTextPattern>(m_member).GetDocumentRange();
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member)->get_DocumentRange(
            outValue.put()));
        return outValue;
    }

    UiaSupportedTextSelection UiaTextPattern::GetSupportedTextSelection()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTextPattern>(m_member).GetSupportedTextSelection();
        }

        SupportedTextSelection outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member)->get_SupportedTextSelection(
            &outValue));
        return outValue;
    }

    UiaTogglePattern::UiaTogglePattern(_In_ IUIAutomationTogglePattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTogglePattern::UiaTogglePattern(winrt::com_ptr<IUIAutomationTogglePattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTogglePattern::UiaTogglePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTogglePattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTogglePattern::UiaTogglePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTogglePattern())
    {
    }

    UiaTogglePattern::operator winrt::com_ptr<IUIAutomationTogglePattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member);
    }

    UiaTogglePattern::operator wil::com_ptr<IUIAutomationTogglePattern>() const
    {
        return wil::com_ptr<IUIAutomationTogglePattern>(std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member).get());
    }

    IUIAutomationTogglePattern* UiaTogglePattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member).get();
    }

    void UiaTogglePattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member) = nullptr;
    }

    IUIAutomationTogglePattern** UiaTogglePattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member).put();
    }


    UiaBool UiaTogglePattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTogglePattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaToggleState UiaTogglePattern::GetToggleState(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTogglePattern>(m_member).GetToggleState();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member);
        ToggleState localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedToggleState(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentToggleState(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaTogglePattern::Toggle()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteTogglePattern>(m_member).Toggle();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member)->Toggle());
    }

    UiaTransformPattern::UiaTransformPattern(_In_ IUIAutomationTransformPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTransformPattern::UiaTransformPattern(winrt::com_ptr<IUIAutomationTransformPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTransformPattern::UiaTransformPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTransformPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTransformPattern::UiaTransformPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTransformPattern())
    {
    }

    UiaTransformPattern::operator winrt::com_ptr<IUIAutomationTransformPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member);
    }

    UiaTransformPattern::operator wil::com_ptr<IUIAutomationTransformPattern>() const
    {
        return wil::com_ptr<IUIAutomationTransformPattern>(std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member).get());
    }

    IUIAutomationTransformPattern* UiaTransformPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member).get();
    }

    void UiaTransformPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member) = nullptr;
    }

    IUIAutomationTransformPattern** UiaTransformPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member).put();
    }


    UiaBool UiaTransformPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTransformPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaBool UiaTransformPattern::GetCanMove(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTransformPattern>(m_member).GetCanMove();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCanMove(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCanMove(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaTransformPattern::GetCanResize(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTransformPattern>(m_member).GetCanResize();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCanResize(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCanResize(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaTransformPattern::GetCanRotate(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTransformPattern>(m_member).GetCanRotate();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCanRotate(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCanRotate(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaTransformPattern::Move(UiaDouble x, UiaDouble y)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            x.ToRemote();
            y.ToRemote();
            std::get<AutomationRemoteTransformPattern>(m_member).Move(
                x,
                y);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member)->Move(
            x,
            y));
    }

    void UiaTransformPattern::Resize(UiaDouble width, UiaDouble height)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            width.ToRemote();
            height.ToRemote();
            std::get<AutomationRemoteTransformPattern>(m_member).Resize(
                width,
                height);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member)->Resize(
            width,
            height));
    }

    void UiaTransformPattern::Rotate(UiaDouble degrees)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            degrees.ToRemote();
            std::get<AutomationRemoteTransformPattern>(m_member).Rotate(
                degrees);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member)->Rotate(
            degrees));
    }

    UiaScrollItemPattern::UiaScrollItemPattern(_In_ IUIAutomationScrollItemPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaScrollItemPattern::UiaScrollItemPattern(winrt::com_ptr<IUIAutomationScrollItemPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaScrollItemPattern::UiaScrollItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteScrollItemPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaScrollItemPattern::UiaScrollItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsScrollItemPattern())
    {
    }

    UiaScrollItemPattern::operator winrt::com_ptr<IUIAutomationScrollItemPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationScrollItemPattern>>(m_member);
    }

    UiaScrollItemPattern::operator wil::com_ptr<IUIAutomationScrollItemPattern>() const
    {
        return wil::com_ptr<IUIAutomationScrollItemPattern>(std::get<winrt::com_ptr<IUIAutomationScrollItemPattern>>(m_member).get());
    }

    IUIAutomationScrollItemPattern* UiaScrollItemPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationScrollItemPattern>>(m_member).get();
    }

    void UiaScrollItemPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationScrollItemPattern>>(m_member) = nullptr;
    }

    IUIAutomationScrollItemPattern** UiaScrollItemPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationScrollItemPattern>>(m_member).put();
    }


    UiaBool UiaScrollItemPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteScrollItemPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    void UiaScrollItemPattern::ScrollIntoView()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteScrollItemPattern>(m_member).ScrollIntoView();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationScrollItemPattern>>(m_member)->ScrollIntoView());
    }

    UiaLegacyIAccessiblePattern::UiaLegacyIAccessiblePattern(_In_ IUIAutomationLegacyIAccessiblePattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaLegacyIAccessiblePattern::UiaLegacyIAccessiblePattern(winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaLegacyIAccessiblePattern::UiaLegacyIAccessiblePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteLegacyIAccessiblePattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaLegacyIAccessiblePattern::UiaLegacyIAccessiblePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsLegacyIAccessiblePattern())
    {
    }

    UiaLegacyIAccessiblePattern::operator winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
    }

    UiaLegacyIAccessiblePattern::operator wil::com_ptr<IUIAutomationLegacyIAccessiblePattern>() const
    {
        return wil::com_ptr<IUIAutomationLegacyIAccessiblePattern>(std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member).get());
    }

    IUIAutomationLegacyIAccessiblePattern* UiaLegacyIAccessiblePattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member).get();
    }

    void UiaLegacyIAccessiblePattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member) = nullptr;
    }

    IUIAutomationLegacyIAccessiblePattern** UiaLegacyIAccessiblePattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member).put();
    }


    UiaBool UiaLegacyIAccessiblePattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteLegacyIAccessiblePattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaInt UiaLegacyIAccessiblePattern::GetChildId(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetChildId();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedChildId(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentChildId(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaLegacyIAccessiblePattern::GetName(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetName();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedName(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentName(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaLegacyIAccessiblePattern::GetValue(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetValue();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedValue(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentValue(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaLegacyIAccessiblePattern::GetDescription(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetDescription();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDescription(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDescription(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaUint UiaLegacyIAccessiblePattern::GetRole(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetRole();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        DWORD localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedRole(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentRole(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaUint UiaLegacyIAccessiblePattern::GetState(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetState();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        DWORD localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedState(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentState(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaLegacyIAccessiblePattern::GetHelp(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetHelp();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedHelp(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentHelp(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaLegacyIAccessiblePattern::GetKeyboardShortcut(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetKeyboardShortcut();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedKeyboardShortcut(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentKeyboardShortcut(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaLegacyIAccessiblePattern::GetSelection(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetSelection();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedSelection(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentSelection(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaString UiaLegacyIAccessiblePattern::GetDefaultAction(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).GetDefaultAction();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDefaultAction(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDefaultAction(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaLegacyIAccessiblePattern::Select(UiaInt flagsSelect)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            flagsSelect.ToRemote();
            std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).Select(
                flagsSelect);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member)->Select(
            flagsSelect));
    }

    void UiaLegacyIAccessiblePattern::DoDefaultAction()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).DoDefaultAction();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member)->DoDefaultAction());
    }

    void UiaLegacyIAccessiblePattern::SetValue(UiaString szValue)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            szValue.ToRemote();
            std::get<AutomationRemoteLegacyIAccessiblePattern>(m_member).SetValue(
                szValue);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member)->SetValue(
            szValue.get()));
    }

    UiaItemContainerPattern::UiaItemContainerPattern(_In_ IUIAutomationItemContainerPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaItemContainerPattern::UiaItemContainerPattern(winrt::com_ptr<IUIAutomationItemContainerPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaItemContainerPattern::UiaItemContainerPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteItemContainerPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaItemContainerPattern::UiaItemContainerPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsItemContainerPattern())
    {
    }

    UiaItemContainerPattern::operator winrt::com_ptr<IUIAutomationItemContainerPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationItemContainerPattern>>(m_member);
    }

    UiaItemContainerPattern::operator wil::com_ptr<IUIAutomationItemContainerPattern>() const
    {
        return wil::com_ptr<IUIAutomationItemContainerPattern>(std::get<winrt::com_ptr<IUIAutomationItemContainerPattern>>(m_member).get());
    }

    IUIAutomationItemContainerPattern* UiaItemContainerPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationItemContainerPattern>>(m_member).get();
    }

    void UiaItemContainerPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationItemContainerPattern>>(m_member) = nullptr;
    }

    IUIAutomationItemContainerPattern** UiaItemContainerPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationItemContainerPattern>>(m_member).put();
    }


    UiaBool UiaItemContainerPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteItemContainerPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaElement UiaItemContainerPattern::FindItemByProperty(UiaElement pStartAfter, UiaPropertyId propertyId, UiaVariant value)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            pStartAfter.ToRemote();
            propertyId.ToRemote();
            value.ToRemote();
            return std::get<AutomationRemoteItemContainerPattern>(m_member).FindItemByProperty(
                pStartAfter,
                propertyId,
                value);
        }

        winrt::com_ptr<IUIAutomationElement> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationItemContainerPattern>>(m_member)->FindItemByProperty(
            pStartAfter.get(),
            propertyId,
            value.get(),
            outValue.put()));
        return outValue;
    }

    UiaVirtualizedItemPattern::UiaVirtualizedItemPattern(_In_ IUIAutomationVirtualizedItemPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaVirtualizedItemPattern::UiaVirtualizedItemPattern(winrt::com_ptr<IUIAutomationVirtualizedItemPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaVirtualizedItemPattern::UiaVirtualizedItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteVirtualizedItemPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaVirtualizedItemPattern::UiaVirtualizedItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsVirtualizedItemPattern())
    {
    }

    UiaVirtualizedItemPattern::operator winrt::com_ptr<IUIAutomationVirtualizedItemPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationVirtualizedItemPattern>>(m_member);
    }

    UiaVirtualizedItemPattern::operator wil::com_ptr<IUIAutomationVirtualizedItemPattern>() const
    {
        return wil::com_ptr<IUIAutomationVirtualizedItemPattern>(std::get<winrt::com_ptr<IUIAutomationVirtualizedItemPattern>>(m_member).get());
    }

    IUIAutomationVirtualizedItemPattern* UiaVirtualizedItemPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationVirtualizedItemPattern>>(m_member).get();
    }

    void UiaVirtualizedItemPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationVirtualizedItemPattern>>(m_member) = nullptr;
    }

    IUIAutomationVirtualizedItemPattern** UiaVirtualizedItemPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationVirtualizedItemPattern>>(m_member).put();
    }


    UiaBool UiaVirtualizedItemPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteVirtualizedItemPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    void UiaVirtualizedItemPattern::Realize()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteVirtualizedItemPattern>(m_member).Realize();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationVirtualizedItemPattern>>(m_member)->Realize());
    }

    UiaSynchronizedInputPattern::UiaSynchronizedInputPattern(_In_ IUIAutomationSynchronizedInputPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaSynchronizedInputPattern::UiaSynchronizedInputPattern(winrt::com_ptr<IUIAutomationSynchronizedInputPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSynchronizedInputPattern::UiaSynchronizedInputPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSynchronizedInputPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSynchronizedInputPattern::UiaSynchronizedInputPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsSynchronizedInputPattern())
    {
    }

    UiaSynchronizedInputPattern::operator winrt::com_ptr<IUIAutomationSynchronizedInputPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member);
    }

    UiaSynchronizedInputPattern::operator wil::com_ptr<IUIAutomationSynchronizedInputPattern>() const
    {
        return wil::com_ptr<IUIAutomationSynchronizedInputPattern>(std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member).get());
    }

    IUIAutomationSynchronizedInputPattern* UiaSynchronizedInputPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member).get();
    }

    void UiaSynchronizedInputPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member) = nullptr;
    }

    IUIAutomationSynchronizedInputPattern** UiaSynchronizedInputPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member).put();
    }


    UiaBool UiaSynchronizedInputPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteSynchronizedInputPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    void UiaSynchronizedInputPattern::StartListening(UiaSynchronizedInputType inputType)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            inputType.ToRemote();
            std::get<AutomationRemoteSynchronizedInputPattern>(m_member).StartListening(
                inputType);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member)->StartListening(
            inputType));
    }

    void UiaSynchronizedInputPattern::Cancel()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            std::get<AutomationRemoteSynchronizedInputPattern>(m_member).Cancel();
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member)->Cancel());
    }

    UiaAnnotationPattern::UiaAnnotationPattern(_In_ IUIAutomationAnnotationPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaAnnotationPattern::UiaAnnotationPattern(winrt::com_ptr<IUIAutomationAnnotationPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaAnnotationPattern::UiaAnnotationPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnnotationPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaAnnotationPattern::UiaAnnotationPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsAnnotationPattern())
    {
    }

    UiaAnnotationPattern::operator winrt::com_ptr<IUIAutomationAnnotationPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member);
    }

    UiaAnnotationPattern::operator wil::com_ptr<IUIAutomationAnnotationPattern>() const
    {
        return wil::com_ptr<IUIAutomationAnnotationPattern>(std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member).get());
    }

    IUIAutomationAnnotationPattern* UiaAnnotationPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member).get();
    }

    void UiaAnnotationPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member) = nullptr;
    }

    IUIAutomationAnnotationPattern** UiaAnnotationPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member).put();
    }


    UiaBool UiaAnnotationPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteAnnotationPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaAnnotationType UiaAnnotationPattern::GetAnnotationTypeId(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteAnnotationPattern>(m_member).GetAnnotationTypeId();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedAnnotationTypeId(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentAnnotationTypeId(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaAnnotationPattern::GetAnnotationTypeName(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteAnnotationPattern>(m_member).GetAnnotationTypeName();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedAnnotationTypeName(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentAnnotationTypeName(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaAnnotationPattern::GetAuthor(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteAnnotationPattern>(m_member).GetAuthor();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedAuthor(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentAuthor(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaAnnotationPattern::GetDateTime(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteAnnotationPattern>(m_member).GetDateTime();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDateTime(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDateTime(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaElement UiaAnnotationPattern::GetTarget(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteAnnotationPattern>(m_member).GetTarget();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member);
        winrt::com_ptr<IUIAutomationElement> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedTarget(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentTarget(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaTextPattern2::UiaTextPattern2(_In_ IUIAutomationTextPattern2* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTextPattern2::UiaTextPattern2(winrt::com_ptr<IUIAutomationTextPattern2> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTextPattern2::UiaTextPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextPattern2 const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTextPattern2::UiaTextPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTextPattern2())
    {
    }

    UiaTextPattern2::operator winrt::com_ptr<IUIAutomationTextPattern2>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member);
    }

    UiaTextPattern2::operator wil::com_ptr<IUIAutomationTextPattern2>() const
    {
        return wil::com_ptr<IUIAutomationTextPattern2>(std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member).get());
    }

    IUIAutomationTextPattern2* UiaTextPattern2::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member).get();
    }

    void UiaTextPattern2::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member) = nullptr;
    }

    IUIAutomationTextPattern2** UiaTextPattern2::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member).put();
    }


    UiaBool UiaTextPattern2::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTextPattern2>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaTextRange UiaTextPattern2::RangeFromAnnotation(UiaElement annotation)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            annotation.ToRemote();
            return std::get<AutomationRemoteTextPattern2>(m_member).RangeFromAnnotation(
                annotation);
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member)->RangeFromAnnotation(
            annotation.get(),
            outValue.put()));
        return outValue;
    }

    UiaTextRange UiaTextPattern2::GetCaretRange(UiaBool& isActive)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            isActive.ToRemote();
            return std::get<AutomationRemoteTextPattern2>(m_member).GetCaretRange(
                isActive);
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member)->GetCaretRange(
            isActive,
            outValue.put()));
        return outValue;
    }

    UiaStylesPattern::UiaStylesPattern(_In_ IUIAutomationStylesPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaStylesPattern::UiaStylesPattern(winrt::com_ptr<IUIAutomationStylesPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaStylesPattern::UiaStylesPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteStylesPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaStylesPattern::UiaStylesPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsStylesPattern())
    {
    }

    UiaStylesPattern::operator winrt::com_ptr<IUIAutomationStylesPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member);
    }

    UiaStylesPattern::operator wil::com_ptr<IUIAutomationStylesPattern>() const
    {
        return wil::com_ptr<IUIAutomationStylesPattern>(std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member).get());
    }

    IUIAutomationStylesPattern* UiaStylesPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member).get();
    }

    void UiaStylesPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member) = nullptr;
    }

    IUIAutomationStylesPattern** UiaStylesPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member).put();
    }


    UiaBool UiaStylesPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteStylesPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaStyleId UiaStylesPattern::GetStyleId(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteStylesPattern>(m_member).GetStyleId();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedStyleId(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentStyleId(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaStylesPattern::GetStyleName(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteStylesPattern>(m_member).GetStyleName();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedStyleName(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentStyleName(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaStylesPattern::GetFillColor(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteStylesPattern>(m_member).GetFillColor();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedFillColor(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentFillColor(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaStylesPattern::GetFillPatternStyle(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteStylesPattern>(m_member).GetFillPatternStyle();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedFillPatternStyle(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentFillPatternStyle(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaStylesPattern::GetShape(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteStylesPattern>(m_member).GetShape();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedShape(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentShape(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaStylesPattern::GetFillPatternColor(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteStylesPattern>(m_member).GetFillPatternColor();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedFillPatternColor(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentFillPatternColor(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaStylesPattern::GetExtendedProperties(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteStylesPattern>(m_member).GetExtendedProperties();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedExtendedProperties(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentExtendedProperties(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaSpreadsheetPattern::UiaSpreadsheetPattern(_In_ IUIAutomationSpreadsheetPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaSpreadsheetPattern::UiaSpreadsheetPattern(winrt::com_ptr<IUIAutomationSpreadsheetPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSpreadsheetPattern::UiaSpreadsheetPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSpreadsheetPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSpreadsheetPattern::UiaSpreadsheetPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsSpreadsheetPattern())
    {
    }

    UiaSpreadsheetPattern::operator winrt::com_ptr<IUIAutomationSpreadsheetPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSpreadsheetPattern>>(m_member);
    }

    UiaSpreadsheetPattern::operator wil::com_ptr<IUIAutomationSpreadsheetPattern>() const
    {
        return wil::com_ptr<IUIAutomationSpreadsheetPattern>(std::get<winrt::com_ptr<IUIAutomationSpreadsheetPattern>>(m_member).get());
    }

    IUIAutomationSpreadsheetPattern* UiaSpreadsheetPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSpreadsheetPattern>>(m_member).get();
    }

    void UiaSpreadsheetPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationSpreadsheetPattern>>(m_member) = nullptr;
    }

    IUIAutomationSpreadsheetPattern** UiaSpreadsheetPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationSpreadsheetPattern>>(m_member).put();
    }


    UiaBool UiaSpreadsheetPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteSpreadsheetPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaElement UiaSpreadsheetPattern::GetItemByName(UiaString name)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            name.ToRemote();
            return std::get<AutomationRemoteSpreadsheetPattern>(m_member).GetItemByName(
                name);
        }

        winrt::com_ptr<IUIAutomationElement> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationSpreadsheetPattern>>(m_member)->GetItemByName(
            name.get(),
            outValue.put()));
        return outValue;
    }

    UiaSpreadsheetItemPattern::UiaSpreadsheetItemPattern(_In_ IUIAutomationSpreadsheetItemPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaSpreadsheetItemPattern::UiaSpreadsheetItemPattern(winrt::com_ptr<IUIAutomationSpreadsheetItemPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSpreadsheetItemPattern::UiaSpreadsheetItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSpreadsheetItemPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSpreadsheetItemPattern::UiaSpreadsheetItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsSpreadsheetItemPattern())
    {
    }

    UiaSpreadsheetItemPattern::operator winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member);
    }

    UiaSpreadsheetItemPattern::operator wil::com_ptr<IUIAutomationSpreadsheetItemPattern>() const
    {
        return wil::com_ptr<IUIAutomationSpreadsheetItemPattern>(std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member).get());
    }

    IUIAutomationSpreadsheetItemPattern* UiaSpreadsheetItemPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member).get();
    }

    void UiaSpreadsheetItemPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member) = nullptr;
    }

    IUIAutomationSpreadsheetItemPattern** UiaSpreadsheetItemPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member).put();
    }


    UiaBool UiaSpreadsheetItemPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteSpreadsheetItemPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaString UiaSpreadsheetItemPattern::GetFormula(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSpreadsheetItemPattern>(m_member).GetFormula();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedFormula(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentFormula(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaSpreadsheetItemPattern::GetAnnotationObjects(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSpreadsheetItemPattern>(m_member).GetAnnotationObjects();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedAnnotationObjects(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentAnnotationObjects(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaArray<UiaAnnotationType> UiaSpreadsheetItemPattern::GetAnnotationTypes(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSpreadsheetItemPattern>(m_member).GetAnnotationTypes();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member);
        unique_safearray localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedAnnotationTypes(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentAnnotationTypes(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaTransformPattern2::UiaTransformPattern2(_In_ IUIAutomationTransformPattern2* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTransformPattern2::UiaTransformPattern2(winrt::com_ptr<IUIAutomationTransformPattern2> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTransformPattern2::UiaTransformPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTransformPattern2 const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTransformPattern2::UiaTransformPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTransformPattern2())
    {
    }

    UiaTransformPattern2::operator winrt::com_ptr<IUIAutomationTransformPattern2>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member);
    }

    UiaTransformPattern2::operator wil::com_ptr<IUIAutomationTransformPattern2>() const
    {
        return wil::com_ptr<IUIAutomationTransformPattern2>(std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member).get());
    }

    IUIAutomationTransformPattern2* UiaTransformPattern2::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member).get();
    }

    void UiaTransformPattern2::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member) = nullptr;
    }

    IUIAutomationTransformPattern2** UiaTransformPattern2::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member).put();
    }


    UiaBool UiaTransformPattern2::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTransformPattern2>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaBool UiaTransformPattern2::GetCanZoom(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTransformPattern2>(m_member).GetCanZoom();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCanZoom(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCanZoom(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaTransformPattern2::GetZoomLevel(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTransformPattern2>(m_member).GetZoomLevel();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedZoomLevel(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentZoomLevel(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaTransformPattern2::GetZoomMinimum(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTransformPattern2>(m_member).GetZoomMinimum();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedZoomMinimum(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentZoomMinimum(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaDouble UiaTransformPattern2::GetZoomMaximum(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTransformPattern2>(m_member).GetZoomMaximum();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member);
        double localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedZoomMaximum(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentZoomMaximum(&localPropertyValue));
        }

        return localPropertyValue;
    }

    void UiaTransformPattern2::Zoom(UiaDouble zoomValue)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            zoomValue.ToRemote();
            std::get<AutomationRemoteTransformPattern2>(m_member).Zoom(
                zoomValue);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member)->Zoom(
            zoomValue));
    }

    void UiaTransformPattern2::ZoomByUnit(UiaZoomUnit ZoomUnit)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            ZoomUnit.ToRemote();
            std::get<AutomationRemoteTransformPattern2>(m_member).ZoomByUnit(
                ZoomUnit);
            return;
        }

        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member)->ZoomByUnit(
            ZoomUnit));
    }

    UiaTextChildPattern::UiaTextChildPattern(_In_ IUIAutomationTextChildPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTextChildPattern::UiaTextChildPattern(winrt::com_ptr<IUIAutomationTextChildPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTextChildPattern::UiaTextChildPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextChildPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTextChildPattern::UiaTextChildPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTextChildPattern())
    {
    }

    UiaTextChildPattern::operator winrt::com_ptr<IUIAutomationTextChildPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member);
    }

    UiaTextChildPattern::operator wil::com_ptr<IUIAutomationTextChildPattern>() const
    {
        return wil::com_ptr<IUIAutomationTextChildPattern>(std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member).get());
    }

    IUIAutomationTextChildPattern* UiaTextChildPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member).get();
    }

    void UiaTextChildPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member) = nullptr;
    }

    IUIAutomationTextChildPattern** UiaTextChildPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member).put();
    }


    UiaBool UiaTextChildPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTextChildPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaElement UiaTextChildPattern::GetTextContainer()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTextChildPattern>(m_member).GetTextContainer();
        }

        winrt::com_ptr<IUIAutomationElement> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member)->get_TextContainer(
            outValue.put()));
        return outValue;
    }

    UiaTextRange UiaTextChildPattern::GetTextRange()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTextChildPattern>(m_member).GetTextRange();
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member)->get_TextRange(
            outValue.put()));
        return outValue;
    }

    UiaDragPattern::UiaDragPattern(_In_ IUIAutomationDragPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaDragPattern::UiaDragPattern(winrt::com_ptr<IUIAutomationDragPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaDragPattern::UiaDragPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDragPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaDragPattern::UiaDragPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsDragPattern())
    {
    }

    UiaDragPattern::operator winrt::com_ptr<IUIAutomationDragPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member);
    }

    UiaDragPattern::operator wil::com_ptr<IUIAutomationDragPattern>() const
    {
        return wil::com_ptr<IUIAutomationDragPattern>(std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member).get());
    }

    IUIAutomationDragPattern* UiaDragPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member).get();
    }

    void UiaDragPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member) = nullptr;
    }

    IUIAutomationDragPattern** UiaDragPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member).put();
    }


    UiaBool UiaDragPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteDragPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaBool UiaDragPattern::GetIsGrabbed(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteDragPattern>(m_member).GetIsGrabbed();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsGrabbed(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsGrabbed(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaDragPattern::GetDropEffect(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteDragPattern>(m_member).GetDropEffect();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDropEffect(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDropEffect(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaString> UiaDragPattern::GetDropEffects(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteDragPattern>(m_member).GetDropEffects();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member);
        unique_safearray localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDropEffects(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDropEffects(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaDragPattern::GetGrabbedItems(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteDragPattern>(m_member).GetGrabbedItems();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->GetCachedGrabbedItems(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->GetCurrentGrabbedItems(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaDropTargetPattern::UiaDropTargetPattern(_In_ IUIAutomationDropTargetPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaDropTargetPattern::UiaDropTargetPattern(winrt::com_ptr<IUIAutomationDropTargetPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaDropTargetPattern::UiaDropTargetPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDropTargetPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaDropTargetPattern::UiaDropTargetPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsDropTargetPattern())
    {
    }

    UiaDropTargetPattern::operator winrt::com_ptr<IUIAutomationDropTargetPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member);
    }

    UiaDropTargetPattern::operator wil::com_ptr<IUIAutomationDropTargetPattern>() const
    {
        return wil::com_ptr<IUIAutomationDropTargetPattern>(std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member).get());
    }

    IUIAutomationDropTargetPattern* UiaDropTargetPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member).get();
    }

    void UiaDropTargetPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member) = nullptr;
    }

    IUIAutomationDropTargetPattern** UiaDropTargetPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member).put();
    }


    UiaBool UiaDropTargetPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteDropTargetPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaString UiaDropTargetPattern::GetDropTargetEffect(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteDropTargetPattern>(m_member).GetDropTargetEffect();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDropTargetEffect(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDropTargetEffect(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaString> UiaDropTargetPattern::GetDropTargetEffects(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteDropTargetPattern>(m_member).GetDropTargetEffects();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member);
        unique_safearray localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDropTargetEffects(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDropTargetEffects(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaTextEditPattern::UiaTextEditPattern(_In_ IUIAutomationTextEditPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaTextEditPattern::UiaTextEditPattern(winrt::com_ptr<IUIAutomationTextEditPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTextEditPattern::UiaTextEditPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextEditPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaTextEditPattern::UiaTextEditPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsTextEditPattern())
    {
    }

    UiaTextEditPattern::operator winrt::com_ptr<IUIAutomationTextEditPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member);
    }

    UiaTextEditPattern::operator wil::com_ptr<IUIAutomationTextEditPattern>() const
    {
        return wil::com_ptr<IUIAutomationTextEditPattern>(std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member).get());
    }

    IUIAutomationTextEditPattern* UiaTextEditPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member).get();
    }

    void UiaTextEditPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member) = nullptr;
    }

    IUIAutomationTextEditPattern** UiaTextEditPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member).put();
    }


    UiaBool UiaTextEditPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteTextEditPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaTextRange UiaTextEditPattern::GetActiveComposition()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTextEditPattern>(m_member).GetActiveComposition();
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member)->GetActiveComposition(
            outValue.put()));
        return outValue;
    }

    UiaTextRange UiaTextEditPattern::GetConversionTarget()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteTextEditPattern>(m_member).GetConversionTarget();
        }

        winrt::com_ptr<IUIAutomationTextRange> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member)->GetConversionTarget(
            outValue.put()));
        return outValue;
    }

    UiaCustomNavigationPattern::UiaCustomNavigationPattern(_In_ IUIAutomationCustomNavigationPattern* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaCustomNavigationPattern::UiaCustomNavigationPattern(winrt::com_ptr<IUIAutomationCustomNavigationPattern> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaCustomNavigationPattern::UiaCustomNavigationPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteCustomNavigationPattern const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaCustomNavigationPattern::UiaCustomNavigationPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsCustomNavigationPattern())
    {
    }

    UiaCustomNavigationPattern::operator winrt::com_ptr<IUIAutomationCustomNavigationPattern>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationCustomNavigationPattern>>(m_member);
    }

    UiaCustomNavigationPattern::operator wil::com_ptr<IUIAutomationCustomNavigationPattern>() const
    {
        return wil::com_ptr<IUIAutomationCustomNavigationPattern>(std::get<winrt::com_ptr<IUIAutomationCustomNavigationPattern>>(m_member).get());
    }

    IUIAutomationCustomNavigationPattern* UiaCustomNavigationPattern::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationCustomNavigationPattern>>(m_member).get();
    }

    void UiaCustomNavigationPattern::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationCustomNavigationPattern>>(m_member) = nullptr;
    }

    IUIAutomationCustomNavigationPattern** UiaCustomNavigationPattern::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationCustomNavigationPattern>>(m_member).put();
    }


    UiaBool UiaCustomNavigationPattern::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteCustomNavigationPattern>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaElement UiaCustomNavigationPattern::Navigate(UiaNavigateDirection direction)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            direction.ToRemote();
            return std::get<AutomationRemoteCustomNavigationPattern>(m_member).Navigate(
                direction);
        }

        winrt::com_ptr<IUIAutomationElement> outValue;
        winrt::check_hresult(std::get<winrt::com_ptr<IUIAutomationCustomNavigationPattern>>(m_member)->Navigate(
            direction,
            outValue.put()));
        return outValue;
    }

    UiaSelectionPattern2::UiaSelectionPattern2(_In_ IUIAutomationSelectionPattern2* pattern):
        UiaTypeBase(MakeWinrtComPtr(pattern))
    {
    }

    UiaSelectionPattern2::UiaSelectionPattern2(winrt::com_ptr<IUIAutomationSelectionPattern2> const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSelectionPattern2::UiaSelectionPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionPattern2 const& pattern):
        UiaTypeBase(pattern)
    {
    }

    UiaSelectionPattern2::UiaSelectionPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern):
        UiaTypeBase(pattern.AsSelectionPattern2())
    {
    }

    UiaSelectionPattern2::operator winrt::com_ptr<IUIAutomationSelectionPattern2>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member);
    }

    UiaSelectionPattern2::operator wil::com_ptr<IUIAutomationSelectionPattern2>() const
    {
        return wil::com_ptr<IUIAutomationSelectionPattern2>(std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member).get());
    }

    IUIAutomationSelectionPattern2* UiaSelectionPattern2::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member).get();
    }

    void UiaSelectionPattern2::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member) = nullptr;
    }

    IUIAutomationSelectionPattern2** UiaSelectionPattern2::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member).put();
    }


    UiaBool UiaSelectionPattern2::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteSelectionPattern2>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaElement UiaSelectionPattern2::GetFirstSelectedItem(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionPattern2>(m_member).GetFirstSelectedItem();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member);
        winrt::com_ptr<IUIAutomationElement> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedFirstSelectedItem(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentFirstSelectedItem(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaElement UiaSelectionPattern2::GetLastSelectedItem(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionPattern2>(m_member).GetLastSelectedItem();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member);
        winrt::com_ptr<IUIAutomationElement> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedLastSelectedItem(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentLastSelectedItem(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaElement UiaSelectionPattern2::GetCurrentSelectedItem(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionPattern2>(m_member).GetCurrentSelectedItem();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member);
        winrt::com_ptr<IUIAutomationElement> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCurrentSelectedItem(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCurrentSelectedItem(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaInt UiaSelectionPattern2::GetItemCount(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            return std::get<AutomationRemoteSelectionPattern2>(m_member).GetItemCount();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedItemCount(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentItemCount(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaElement::UiaElement(_In_ IUIAutomationElement* element):
        UiaTypeBase(MakeWinrtComPtr(element))
    {
        ToRemote();
    }

    UiaElement::UiaElement(winrt::com_ptr<IUIAutomationElement> const& element):
        UiaTypeBase(element)
    {
        ToRemote();
    }

    UiaElement::UiaElement(winrt::Microsoft::UI::UIAutomation::AutomationRemoteElement const& element):
        UiaTypeBase(element)
    {
    }

    UiaElement::UiaElement(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& element):
        UiaTypeBase(element.AsElement())
    {
    }

    UiaElement& UiaElement::operator=(const UiaElement& other)
    {
        AssignCopyTo<UiaElement>(m_member, other.m_member);
        return *this;
    }

    UiaElement::operator winrt::com_ptr<IUIAutomationElement>() const
    {
        return std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
    }

    UiaElement::operator wil::com_ptr<IUIAutomationElement>() const
    {
        return wil::com_ptr<IUIAutomationElement>(std::get<winrt::com_ptr<IUIAutomationElement>>(m_member).get());
    }

    IUIAutomationElement* UiaElement::get() const
    {
        return std::get<winrt::com_ptr<IUIAutomationElement>>(m_member).get();
    }

    void UiaElement::reset()
    {
        std::get<winrt::com_ptr<IUIAutomationElement>>(m_member) = nullptr;
    }

    IUIAutomationElement** UiaElement::operator&()
    {
        reset();
        return std::get<winrt::com_ptr<IUIAutomationElement>>(m_member).put();
    }


    UiaBool UiaElement::IsNull() const
    {
        if (UiaOperationAbstraction::ShouldUseRemoteApi())
        {
            auto remoteValue = std::get_if<AutomationRemoteElement>(&m_member);
            if (remoteValue)
            {
                return remoteValue->IsNull();
            }
        }

        return !get();
    }

    UiaArray<UiaInt> UiaElement::GetRuntimeId()
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetRuntimeId();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        unique_safearray localPropertyValue;
        winrt::check_hresult(localObject->GetRuntimeId(&localPropertyValue));
        return localPropertyValue;
    }

    UiaInt UiaElement::GetProcessId(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetProcessId();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedProcessId(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentProcessId(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaControlType UiaElement::GetControlType(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetControlType();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        CONTROLTYPEID localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedControlType(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentControlType(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetLocalizedControlType(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetLocalizedControlType();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedLocalizedControlType(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentLocalizedControlType(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetName(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetName();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedName(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentName(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetAcceleratorKey(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetAcceleratorKey();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedAcceleratorKey(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentAcceleratorKey(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetAccessKey(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetAccessKey();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedAccessKey(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentAccessKey(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetHasKeyboardFocus(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetHasKeyboardFocus();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedHasKeyboardFocus(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentHasKeyboardFocus(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsKeyboardFocusable(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsKeyboardFocusable();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsKeyboardFocusable(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsKeyboardFocusable(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsEnabled(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsEnabled();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsEnabled(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsEnabled(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetAutomationId(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetAutomationId();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedAutomationId(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentAutomationId(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetClassName(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetClassName();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedClassName(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentClassName(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetHelpText(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetHelpText();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedHelpText(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentHelpText(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaElement::GetCulture(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetCulture();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedCulture(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentCulture(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsControlElement(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsControlElement();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsControlElement(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsControlElement(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsContentElement(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsContentElement();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsContentElement(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsContentElement(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsPassword(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsPassword();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsPassword(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsPassword(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaHwnd UiaElement::GetNativeWindowHandle(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetNativeWindowHandle();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        UIA_HWND localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedNativeWindowHandle(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentNativeWindowHandle(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetItemType(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetItemType();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedItemType(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentItemType(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsOffscreen(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsOffscreen();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsOffscreen(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsOffscreen(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaOrientationType UiaElement::GetOrientation(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetOrientation();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        OrientationType localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedOrientation(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentOrientation(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetFrameworkId(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetFrameworkId();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedFrameworkId(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentFrameworkId(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsRequiredForForm(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsRequiredForForm();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsRequiredForForm(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsRequiredForForm(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetItemStatus(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetItemStatus();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedItemStatus(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentItemStatus(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaRect UiaElement::GetBoundingRectangle(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetBoundingRectangle();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        RECT localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedBoundingRectangle(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentBoundingRectangle(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaElement UiaElement::GetLabeledBy(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetLabeledBy();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationElement> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedLabeledBy(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentLabeledBy(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetAriaRole(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetAriaRole();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedAriaRole(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentAriaRole(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetAriaProperties(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetAriaProperties();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedAriaProperties(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentAriaProperties(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsDataValidForForm(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsDataValidForForm();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedIsDataValidForForm(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentIsDataValidForForm(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaElement::GetControllerFor(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetControllerFor();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedControllerFor(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentControllerFor(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaElement::GetDescribedBy(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetDescribedBy();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedDescribedBy(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentDescribedBy(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaElement::GetFlowsTo(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetFlowsTo();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedFlowsTo(localPropertyValue.put()));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentFlowsTo(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetProviderDescription(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetProviderDescription();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            winrt::check_hresult(localObject->get_CachedProviderDescription(&localPropertyValue));
        }
        else
        {
            winrt::check_hresult(localObject->get_CurrentProviderDescription(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetOptimizeForVisualContent(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetOptimizeForVisualContent();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement2>();
            winrt::check_hresult(localObjectQueried->get_CachedOptimizeForVisualContent(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement2>();
            winrt::check_hresult(localObjectQueried->get_CurrentOptimizeForVisualContent(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaLiveSetting UiaElement::GetLiveSetting(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetLiveSetting();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        LiveSetting localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement2>();
            winrt::check_hresult(localObjectQueried->get_CachedLiveSetting(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement2>();
            winrt::check_hresult(localObjectQueried->get_CurrentLiveSetting(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaElement::GetFlowsFrom(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetFlowsFrom();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement2>();
            winrt::check_hresult(localObjectQueried->get_CachedFlowsFrom(localPropertyValue.put()));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement2>();
            winrt::check_hresult(localObjectQueried->get_CurrentFlowsFrom(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsPeripheral(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsPeripheral();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement3>();
            winrt::check_hresult(localObjectQueried->get_CachedIsPeripheral(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement3>();
            winrt::check_hresult(localObjectQueried->get_CurrentIsPeripheral(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaElement::GetPositionInSet(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetPositionInSet();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CachedPositionInSet(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CurrentPositionInSet(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaElement::GetSizeOfSet(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetSizeOfSet();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CachedSizeOfSet(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CurrentSizeOfSet(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInt UiaElement::GetLevel(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetLevel();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        int localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CachedLevel(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CurrentLevel(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaAnnotationType> UiaElement::GetAnnotationTypes(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetAnnotationTypes();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        unique_safearray localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CachedAnnotationTypes(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CurrentAnnotationTypes(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaArray<UiaElement> UiaElement::GetAnnotationObjects(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetAnnotationObjects();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationElementArray> localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CachedAnnotationObjects(localPropertyValue.put()));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement4>();
            winrt::check_hresult(localObjectQueried->get_CurrentAnnotationObjects(localPropertyValue.put()));
        }

        return localPropertyValue;
    }

    UiaLandmarkType UiaElement::GetLandmarkType(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetLandmarkType();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        LANDMARKTYPEID localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement5>();
            winrt::check_hresult(localObjectQueried->get_CachedLandmarkType(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement5>();
            winrt::check_hresult(localObjectQueried->get_CurrentLandmarkType(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetLocalizedLandmarkType(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetLocalizedLandmarkType();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement5>();
            winrt::check_hresult(localObjectQueried->get_CachedLocalizedLandmarkType(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement5>();
            winrt::check_hresult(localObjectQueried->get_CurrentLocalizedLandmarkType(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaString UiaElement::GetFullDescription(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetFullDescription();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        wil::unique_bstr localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement6>();
            winrt::check_hresult(localObjectQueried->get_CachedFullDescription(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement6>();
            winrt::check_hresult(localObjectQueried->get_CurrentFullDescription(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaHeadingLevel UiaElement::GetHeadingLevel(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetHeadingLevel();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        HEADINGLEVELID localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement8>();
            winrt::check_hresult(localObjectQueried->get_CachedHeadingLevel(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement8>();
            winrt::check_hresult(localObjectQueried->get_CurrentHeadingLevel(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaBool UiaElement::GetIsDialog(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetIsDialog();
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        BOOL localPropertyValue;
        if (useCachedApi)
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement9>();
            winrt::check_hresult(localObjectQueried->get_CachedIsDialog(&localPropertyValue));
        }
        else
        {
            auto localObjectQueried = localObject.as<IUIAutomationElement9>();
            winrt::check_hresult(localObjectQueried->get_CurrentIsDialog(&localPropertyValue));
        }

        return localPropertyValue;
    }

    UiaInvokePattern UiaElement::GetInvokePattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetInvokePattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationInvokePattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_InvokePatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_InvokePatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaSelectionPattern UiaElement::GetSelectionPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetSelectionPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationSelectionPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_SelectionPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_SelectionPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaValuePattern UiaElement::GetValuePattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetValuePattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationValuePattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_ValuePatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_ValuePatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaRangeValuePattern UiaElement::GetRangeValuePattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetRangeValuePattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationRangeValuePattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_RangeValuePatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_RangeValuePatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaScrollPattern UiaElement::GetScrollPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetScrollPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationScrollPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_ScrollPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_ScrollPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaExpandCollapsePattern UiaElement::GetExpandCollapsePattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetExpandCollapsePattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationExpandCollapsePattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_ExpandCollapsePatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_ExpandCollapsePatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaGridPattern UiaElement::GetGridPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetGridPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationGridPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_GridPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_GridPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaGridItemPattern UiaElement::GetGridItemPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetGridItemPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationGridItemPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_GridItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_GridItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaMultipleViewPattern UiaElement::GetMultipleViewPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetMultipleViewPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationMultipleViewPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_MultipleViewPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_MultipleViewPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaWindowPattern UiaElement::GetWindowPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetWindowPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationWindowPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_WindowPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_WindowPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaSelectionItemPattern UiaElement::GetSelectionItemPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetSelectionItemPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationSelectionItemPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_SelectionItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_SelectionItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaDockPattern UiaElement::GetDockPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetDockPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationDockPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_DockPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_DockPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTablePattern UiaElement::GetTablePattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTablePattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTablePattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TablePatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TablePatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTableItemPattern UiaElement::GetTableItemPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTableItemPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTableItemPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TableItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TableItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTextPattern UiaElement::GetTextPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTextPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTextPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TextPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TextPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTogglePattern UiaElement::GetTogglePattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTogglePattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTogglePattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TogglePatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TogglePatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTransformPattern UiaElement::GetTransformPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTransformPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTransformPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TransformPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TransformPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaScrollItemPattern UiaElement::GetScrollItemPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetScrollItemPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationScrollItemPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_ScrollItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_ScrollItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaLegacyIAccessiblePattern UiaElement::GetLegacyIAccessiblePattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetLegacyIAccessiblePattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_LegacyIAccessiblePatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_LegacyIAccessiblePatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaItemContainerPattern UiaElement::GetItemContainerPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetItemContainerPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationItemContainerPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_ItemContainerPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_ItemContainerPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaVirtualizedItemPattern UiaElement::GetVirtualizedItemPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetVirtualizedItemPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationVirtualizedItemPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_VirtualizedItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_VirtualizedItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaSynchronizedInputPattern UiaElement::GetSynchronizedInputPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetSynchronizedInputPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationSynchronizedInputPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_SynchronizedInputPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_SynchronizedInputPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaAnnotationPattern UiaElement::GetAnnotationPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetAnnotationPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationAnnotationPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_AnnotationPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_AnnotationPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTextPattern2 UiaElement::GetTextPattern2(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTextPattern2();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTextPattern2> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TextPattern2Id, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TextPattern2Id, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaStylesPattern UiaElement::GetStylesPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetStylesPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationStylesPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_StylesPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_StylesPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaSpreadsheetPattern UiaElement::GetSpreadsheetPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetSpreadsheetPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationSpreadsheetPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_SpreadsheetPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_SpreadsheetPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaSpreadsheetItemPattern UiaElement::GetSpreadsheetItemPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetSpreadsheetItemPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationSpreadsheetItemPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_SpreadsheetItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_SpreadsheetItemPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTransformPattern2 UiaElement::GetTransformPattern2(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTransformPattern2();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTransformPattern2> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TransformPattern2Id, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TransformPattern2Id, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTextChildPattern UiaElement::GetTextChildPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTextChildPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTextChildPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TextChildPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TextChildPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaDragPattern UiaElement::GetDragPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetDragPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationDragPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_DragPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_DragPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaDropTargetPattern UiaElement::GetDropTargetPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetDropTargetPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationDropTargetPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_DropTargetPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_DropTargetPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaTextEditPattern UiaElement::GetTextEditPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetTextEditPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationTextEditPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_TextEditPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_TextEditPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaCustomNavigationPattern UiaElement::GetCustomNavigationPattern(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetCustomNavigationPattern();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationCustomNavigationPattern> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_CustomNavigationPatternId, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_CustomNavigationPatternId, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaSelectionPattern2 UiaElement::GetSelectionPattern2(bool useCachedApi /* = false */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetSelectionPattern2();
        }

        auto localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationSelectionPattern2> localPattern;
        if (useCachedApi)
        {
            winrt::check_hresult(localElement->GetCachedPatternAs(UIA_SelectionPattern2Id, IID_PPV_ARGS(localPattern.put())));
        }
        else
        {
            winrt::check_hresult(localElement->GetCurrentPatternAs(UIA_SelectionPattern2Id, IID_PPV_ARGS(localPattern.put())));
        }

        return localPattern;
    }

    UiaElement UiaElement::GetUpdatedCacheElement(UiaCacheRequest cacheRequest)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetUpdatedCacheElement(cacheRequest);
        }

        const auto& localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        winrt::com_ptr<IUIAutomationElement> localResult;
        winrt::check_hresult(localElement->BuildUpdatedCache(
            (*cacheRequest).get(),
            localResult.put()));
        return localResult;
    }

    UiaElement UiaElement::GetParentElement(std::optional<UiaCacheRequest> cacheRequest /* = std::nullopt */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            ToRemote();
            auto element = std::get<AutomationRemoteElement>(m_member).GetParentElement();
            if (cacheRequest)
            {
                delegator->If(element.IsNull().BoolNot(), [&]()
                {
                    element.PopulateCache(*cacheRequest);
                });
            }
            return element;
        }

        const auto& localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        const auto walker = GetRawViewWalker();
        winrt::com_ptr<IUIAutomationElement> localResult;
        if (cacheRequest)
        {
            winrt::check_hresult(walker->GetParentElementBuildCache(
                localElement.get(),
                (*cacheRequest.value()).get(),
                localResult.put()));
        }
        else
        {
            winrt::check_hresult(walker->GetParentElement(localElement.get(), localResult.put()));
        }

        return localResult;
    }

    UiaElement UiaElement::GetFirstChildElement(std::optional<UiaCacheRequest> cacheRequest /* = std::nullopt */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            ToRemote();
            auto element = std::get<AutomationRemoteElement>(m_member).GetFirstChildElement();
            if (cacheRequest)
            {
                delegator->If(element.IsNull().BoolNot(), [&]()
                {
                    element.PopulateCache(*cacheRequest);
                });
            }
            return element;
        }

        const auto& localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        const auto walker = GetRawViewWalker();
        winrt::com_ptr<IUIAutomationElement> localResult;
        if (cacheRequest)
        {
            winrt::check_hresult(walker->GetFirstChildElementBuildCache(
                localElement.get(),
                (*cacheRequest.value()).get(),
                localResult.put()));
        }
        else
        {
            winrt::check_hresult(walker->GetFirstChildElement(localElement.get(), localResult.put()));
        }

        return localResult;
    }

    UiaElement UiaElement::GetLastChildElement(std::optional<UiaCacheRequest> cacheRequest /* = std::nullopt */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            ToRemote();
            auto element = std::get<AutomationRemoteElement>(m_member).GetLastChildElement();
            if (cacheRequest)
            {
                delegator->If(element.IsNull().BoolNot(), [&]()
                {
                    element.PopulateCache(*cacheRequest);
                });
            }
            return element;
        }

        const auto& localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        const auto walker = GetRawViewWalker();
        winrt::com_ptr<IUIAutomationElement> localResult;
        if (cacheRequest)
        {
            winrt::check_hresult(walker->GetLastChildElementBuildCache(
                localElement.get(),
                (*cacheRequest.value()).get(),
                localResult.put()));
        }
        else
        {
            winrt::check_hresult(walker->GetLastChildElement(localElement.get(), localResult.put()));
        }

        return localResult;
    }

    UiaElement UiaElement::GetNextSiblingElement(std::optional<UiaCacheRequest> cacheRequest /* = std::nullopt */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            ToRemote();
            auto element = std::get<AutomationRemoteElement>(m_member).GetNextSiblingElement();
            if (cacheRequest)
            {
                delegator->If(element.IsNull().BoolNot(), [&]()
                {
                    element.PopulateCache(*cacheRequest);
                });
            }
            return element;
        }

        const auto& localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        const auto walker = GetRawViewWalker();
        winrt::com_ptr<IUIAutomationElement> localResult;
        if (cacheRequest)
        {
            winrt::check_hresult(walker->GetNextSiblingElementBuildCache(
                localElement.get(),
                (*cacheRequest.value()).get(),
                localResult.put()));
        }
        else
        {
            winrt::check_hresult(walker->GetNextSiblingElement(localElement.get(), localResult.put()));
        }

        return localResult;
    }

    UiaElement UiaElement::GetPreviousSiblingElement(std::optional<UiaCacheRequest> cacheRequest /* = std::nullopt */)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            ToRemote();
            auto element = std::get<AutomationRemoteElement>(m_member).GetPreviousSiblingElement();
            if (cacheRequest)
            {
                delegator->If(element.IsNull().BoolNot(), [&]()
                {
                    element.PopulateCache(*cacheRequest);
                });
            }
            return element;
        }

        const auto& localElement = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        const auto walker = GetRawViewWalker();
        winrt::com_ptr<IUIAutomationElement> localResult;
        if (cacheRequest)
        {
            winrt::check_hresult(walker->GetPreviousSiblingElementBuildCache(
                localElement.get(),
                (*cacheRequest.value()).get(),
                localResult.put()));
        }
        else
        {
            winrt::check_hresult(walker->GetPreviousSiblingElement(localElement.get(), localResult.put()));
        }

        return localResult;
    }

    UiaVariant UiaElement::GetMetadataValue(UiaPropertyId propertyId, UiaMetadata metadataId)
    {
        auto delegator = UiaOperationScope::GetCurrentDelegator();
        if (delegator && delegator->GetUseRemoteApi())
        {
            this->ToRemote();
            propertyId.ToRemote();
            metadataId.ToRemote();
            return std::get<AutomationRemoteElement>(m_member).GetMetadataValue(
                propertyId,
                metadataId);
        }

        auto localObject = std::get<winrt::com_ptr<IUIAutomationElement>>(m_member);
        auto localObjectQueried = localObject.as<IUIAutomationElement7>();

        wil::unique_variant metadataValue;
        winrt::check_hresult(localObjectQueried->GetCurrentMetadataValue(
            propertyId,
            metadataId,
            &metadataValue));

        return metadataValue;
    }
