// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
// WARNING: Please don't edit this file. It was generated.

#pragma once

    class UiaElement;

    class UiaInvokePattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationInvokePattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteInvokePattern>
    {
    public:
        UiaInvokePattern(_In_ IUIAutomationInvokePattern* pattern);
        UiaInvokePattern(winrt::com_ptr<IUIAutomationInvokePattern> const& pattern);
        UiaInvokePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteInvokePattern const& pattern);
        explicit UiaInvokePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaInvokePattern(const UiaInvokePattern& other) = default;

        operator winrt::com_ptr<IUIAutomationInvokePattern>() const;
        operator wil::com_ptr<IUIAutomationInvokePattern>() const;

        IUIAutomationInvokePattern* get() const;
        IUIAutomationInvokePattern* operator->() const {return get();}
        void reset();
        IUIAutomationInvokePattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationInvokePattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationInvokePattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationInvokePattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        void Invoke();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationInvokePattern>();
        }
    };

    class UiaSelectionPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationSelectionPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionPattern>
    {
    public:
        UiaSelectionPattern(_In_ IUIAutomationSelectionPattern* pattern);
        UiaSelectionPattern(winrt::com_ptr<IUIAutomationSelectionPattern> const& pattern);
        UiaSelectionPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionPattern const& pattern);
        explicit UiaSelectionPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaSelectionPattern(const UiaSelectionPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationSelectionPattern>() const;
        operator wil::com_ptr<IUIAutomationSelectionPattern>() const;

        IUIAutomationSelectionPattern* get() const;
        IUIAutomationSelectionPattern* operator->() const {return get();}
        void reset();
        IUIAutomationSelectionPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationSelectionPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSelectionPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaArray<UiaElement> GetSelection(bool useCachedApi);
        UiaBool GetCanSelectMultiple(bool useCachedApi);
        UiaBool GetIsSelectionRequired(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationSelectionPattern>();
        }
    };

    class UiaValuePattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationValuePattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteValuePattern>
    {
    public:
        UiaValuePattern(_In_ IUIAutomationValuePattern* pattern);
        UiaValuePattern(winrt::com_ptr<IUIAutomationValuePattern> const& pattern);
        UiaValuePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteValuePattern const& pattern);
        explicit UiaValuePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaValuePattern(const UiaValuePattern& other) = default;

        operator winrt::com_ptr<IUIAutomationValuePattern>() const;
        operator wil::com_ptr<IUIAutomationValuePattern>() const;

        IUIAutomationValuePattern* get() const;
        IUIAutomationValuePattern* operator->() const {return get();}
        void reset();
        IUIAutomationValuePattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationValuePattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationValuePattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaString GetValue(bool useCachedApi);
        UiaBool GetIsReadOnly(bool useCachedApi);
        void SetValue(UiaString val);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationValuePattern>();
        }
    };

    class UiaRangeValuePattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationRangeValuePattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteRangeValuePattern>
    {
    public:
        UiaRangeValuePattern(_In_ IUIAutomationRangeValuePattern* pattern);
        UiaRangeValuePattern(winrt::com_ptr<IUIAutomationRangeValuePattern> const& pattern);
        UiaRangeValuePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteRangeValuePattern const& pattern);
        explicit UiaRangeValuePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaRangeValuePattern(const UiaRangeValuePattern& other) = default;

        operator winrt::com_ptr<IUIAutomationRangeValuePattern>() const;
        operator wil::com_ptr<IUIAutomationRangeValuePattern>() const;

        IUIAutomationRangeValuePattern* get() const;
        IUIAutomationRangeValuePattern* operator->() const {return get();}
        void reset();
        IUIAutomationRangeValuePattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationRangeValuePattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationRangeValuePattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaDouble GetValue(bool useCachedApi);
        UiaBool GetIsReadOnly(bool useCachedApi);
        UiaDouble GetMaximum(bool useCachedApi);
        UiaDouble GetMinimum(bool useCachedApi);
        UiaDouble GetLargeChange(bool useCachedApi);
        UiaDouble GetSmallChange(bool useCachedApi);
        void SetValue(UiaDouble val);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationRangeValuePattern>();
        }
    };

    class UiaScrollPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationScrollPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteScrollPattern>
    {
    public:
        UiaScrollPattern(_In_ IUIAutomationScrollPattern* pattern);
        UiaScrollPattern(winrt::com_ptr<IUIAutomationScrollPattern> const& pattern);
        UiaScrollPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteScrollPattern const& pattern);
        explicit UiaScrollPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaScrollPattern(const UiaScrollPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationScrollPattern>() const;
        operator wil::com_ptr<IUIAutomationScrollPattern>() const;

        IUIAutomationScrollPattern* get() const;
        IUIAutomationScrollPattern* operator->() const {return get();}
        void reset();
        IUIAutomationScrollPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationScrollPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationScrollPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaDouble GetHorizontalScrollPercent(bool useCachedApi);
        UiaDouble GetVerticalScrollPercent(bool useCachedApi);
        UiaDouble GetHorizontalViewSize(bool useCachedApi);
        UiaDouble GetVerticalViewSize(bool useCachedApi);
        UiaBool GetHorizontallyScrollable(bool useCachedApi);
        UiaBool GetVerticallyScrollable(bool useCachedApi);
        void Scroll(UiaScrollAmount horizontalAmount, UiaScrollAmount verticalAmount);
        void SetScrollPercent(UiaDouble horizontalPercent, UiaDouble verticalPercent);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationScrollPattern>();
        }
    };

    class UiaExpandCollapsePattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationExpandCollapsePattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteExpandCollapsePattern>
    {
    public:
        UiaExpandCollapsePattern(_In_ IUIAutomationExpandCollapsePattern* pattern);
        UiaExpandCollapsePattern(winrt::com_ptr<IUIAutomationExpandCollapsePattern> const& pattern);
        UiaExpandCollapsePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteExpandCollapsePattern const& pattern);
        explicit UiaExpandCollapsePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaExpandCollapsePattern(const UiaExpandCollapsePattern& other) = default;

        operator winrt::com_ptr<IUIAutomationExpandCollapsePattern>() const;
        operator wil::com_ptr<IUIAutomationExpandCollapsePattern>() const;

        IUIAutomationExpandCollapsePattern* get() const;
        IUIAutomationExpandCollapsePattern* operator->() const {return get();}
        void reset();
        IUIAutomationExpandCollapsePattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationExpandCollapsePattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationExpandCollapsePattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaExpandCollapseState GetExpandCollapseState(bool useCachedApi);
        void Expand();
        void Collapse();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationExpandCollapsePattern>();
        }
    };

    class UiaGridPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationGridPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteGridPattern>
    {
    public:
        UiaGridPattern(_In_ IUIAutomationGridPattern* pattern);
        UiaGridPattern(winrt::com_ptr<IUIAutomationGridPattern> const& pattern);
        UiaGridPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteGridPattern const& pattern);
        explicit UiaGridPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaGridPattern(const UiaGridPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationGridPattern>() const;
        operator wil::com_ptr<IUIAutomationGridPattern>() const;

        IUIAutomationGridPattern* get() const;
        IUIAutomationGridPattern* operator->() const {return get();}
        void reset();
        IUIAutomationGridPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationGridPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationGridPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaInt GetRowCount(bool useCachedApi);
        UiaInt GetColumnCount(bool useCachedApi);
        UiaElement GetItem(UiaInt row, UiaInt column);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationGridPattern>();
        }
    };

    class UiaGridItemPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationGridItemPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteGridItemPattern>
    {
    public:
        UiaGridItemPattern(_In_ IUIAutomationGridItemPattern* pattern);
        UiaGridItemPattern(winrt::com_ptr<IUIAutomationGridItemPattern> const& pattern);
        UiaGridItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteGridItemPattern const& pattern);
        explicit UiaGridItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaGridItemPattern(const UiaGridItemPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationGridItemPattern>() const;
        operator wil::com_ptr<IUIAutomationGridItemPattern>() const;

        IUIAutomationGridItemPattern* get() const;
        IUIAutomationGridItemPattern* operator->() const {return get();}
        void reset();
        IUIAutomationGridItemPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationGridItemPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationGridItemPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaElement GetContainingGrid(bool useCachedApi);
        UiaInt GetRow(bool useCachedApi);
        UiaInt GetColumn(bool useCachedApi);
        UiaInt GetRowSpan(bool useCachedApi);
        UiaInt GetColumnSpan(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationGridItemPattern>();
        }
    };

    class UiaMultipleViewPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationMultipleViewPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteMultipleViewPattern>
    {
    public:
        UiaMultipleViewPattern(_In_ IUIAutomationMultipleViewPattern* pattern);
        UiaMultipleViewPattern(winrt::com_ptr<IUIAutomationMultipleViewPattern> const& pattern);
        UiaMultipleViewPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteMultipleViewPattern const& pattern);
        explicit UiaMultipleViewPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaMultipleViewPattern(const UiaMultipleViewPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationMultipleViewPattern>() const;
        operator wil::com_ptr<IUIAutomationMultipleViewPattern>() const;

        IUIAutomationMultipleViewPattern* get() const;
        IUIAutomationMultipleViewPattern* operator->() const {return get();}
        void reset();
        IUIAutomationMultipleViewPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationMultipleViewPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationMultipleViewPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaInt GetCurrentView(bool useCachedApi);
        UiaArray<UiaInt> GetSupportedViews(bool useCachedApi);
        UiaString GetViewName(UiaInt view);
        void SetCurrentView(UiaInt view);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationMultipleViewPattern>();
        }
    };

    class UiaWindowPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationWindowPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteWindowPattern>
    {
    public:
        UiaWindowPattern(_In_ IUIAutomationWindowPattern* pattern);
        UiaWindowPattern(winrt::com_ptr<IUIAutomationWindowPattern> const& pattern);
        UiaWindowPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteWindowPattern const& pattern);
        explicit UiaWindowPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaWindowPattern(const UiaWindowPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationWindowPattern>() const;
        operator wil::com_ptr<IUIAutomationWindowPattern>() const;

        IUIAutomationWindowPattern* get() const;
        IUIAutomationWindowPattern* operator->() const {return get();}
        void reset();
        IUIAutomationWindowPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationWindowPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationWindowPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaBool GetCanMaximize(bool useCachedApi);
        UiaBool GetCanMinimize(bool useCachedApi);
        UiaBool GetIsModal(bool useCachedApi);
        UiaBool GetIsTopmost(bool useCachedApi);
        UiaWindowVisualState GetWindowVisualState(bool useCachedApi);
        UiaWindowInteractionState GetWindowInteractionState(bool useCachedApi);
        void Close();
        UiaBool WaitForInputIdle(UiaInt milliseconds);
        void SetWindowVisualState(UiaWindowVisualState state);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationWindowPattern>();
        }
    };

    class UiaSelectionItemPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationSelectionItemPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionItemPattern>
    {
    public:
        UiaSelectionItemPattern(_In_ IUIAutomationSelectionItemPattern* pattern);
        UiaSelectionItemPattern(winrt::com_ptr<IUIAutomationSelectionItemPattern> const& pattern);
        UiaSelectionItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionItemPattern const& pattern);
        explicit UiaSelectionItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaSelectionItemPattern(const UiaSelectionItemPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationSelectionItemPattern>() const;
        operator wil::com_ptr<IUIAutomationSelectionItemPattern>() const;

        IUIAutomationSelectionItemPattern* get() const;
        IUIAutomationSelectionItemPattern* operator->() const {return get();}
        void reset();
        IUIAutomationSelectionItemPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationSelectionItemPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSelectionItemPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaBool GetIsSelected(bool useCachedApi);
        UiaElement GetSelectionContainer(bool useCachedApi);
        void Select();
        void AddToSelection();
        void RemoveFromSelection();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationSelectionItemPattern>();
        }
    };

    class UiaDockPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationDockPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteDockPattern>
    {
    public:
        UiaDockPattern(_In_ IUIAutomationDockPattern* pattern);
        UiaDockPattern(winrt::com_ptr<IUIAutomationDockPattern> const& pattern);
        UiaDockPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDockPattern const& pattern);
        explicit UiaDockPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaDockPattern(const UiaDockPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationDockPattern>() const;
        operator wil::com_ptr<IUIAutomationDockPattern>() const;

        IUIAutomationDockPattern* get() const;
        IUIAutomationDockPattern* operator->() const {return get();}
        void reset();
        IUIAutomationDockPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationDockPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationDockPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaDockPosition GetDockPosition(bool useCachedApi);
        void SetDockPosition(UiaDockPosition dockPos);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationDockPattern>();
        }
    };

    class UiaTablePattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTablePattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTablePattern>
    {
    public:
        UiaTablePattern(_In_ IUIAutomationTablePattern* pattern);
        UiaTablePattern(winrt::com_ptr<IUIAutomationTablePattern> const& pattern);
        UiaTablePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTablePattern const& pattern);
        explicit UiaTablePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTablePattern(const UiaTablePattern& other) = default;

        operator winrt::com_ptr<IUIAutomationTablePattern>() const;
        operator wil::com_ptr<IUIAutomationTablePattern>() const;

        IUIAutomationTablePattern* get() const;
        IUIAutomationTablePattern* operator->() const {return get();}
        void reset();
        IUIAutomationTablePattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTablePattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTablePattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaArray<UiaElement> GetRowHeaders(bool useCachedApi);
        UiaArray<UiaElement> GetColumnHeaders(bool useCachedApi);
        UiaRowOrColumnMajor GetRowOrColumnMajor(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTablePattern>();
        }
    };

    class UiaTableItemPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTableItemPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTableItemPattern>
    {
    public:
        UiaTableItemPattern(_In_ IUIAutomationTableItemPattern* pattern);
        UiaTableItemPattern(winrt::com_ptr<IUIAutomationTableItemPattern> const& pattern);
        UiaTableItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTableItemPattern const& pattern);
        explicit UiaTableItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTableItemPattern(const UiaTableItemPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationTableItemPattern>() const;
        operator wil::com_ptr<IUIAutomationTableItemPattern>() const;

        IUIAutomationTableItemPattern* get() const;
        IUIAutomationTableItemPattern* operator->() const {return get();}
        void reset();
        IUIAutomationTableItemPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTableItemPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTableItemPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaArray<UiaElement> GetRowHeaderItems(bool useCachedApi);
        UiaArray<UiaElement> GetColumnHeaderItems(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTableItemPattern>();
        }
    };

    class UiaTextRange: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTextRange>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextRange>
    {
    public:
        UiaTextRange(_In_ IUIAutomationTextRange* object);
        UiaTextRange(winrt::com_ptr<IUIAutomationTextRange> const& object);
        UiaTextRange(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextRange const& object);
        explicit UiaTextRange(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& object);
        UiaTextRange(const UiaTextRange& other) = default;
        UiaTextRange& operator=(const UiaTextRange& other);

        operator winrt::com_ptr<IUIAutomationTextRange>() const;
        operator wil::com_ptr<IUIAutomationTextRange>() const;

        IUIAutomationTextRange* get() const;
        IUIAutomationTextRange* operator->() const {return get();}
        void reset();
        IUIAutomationTextRange** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTextRange** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextRange>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaTextRange Clone();
        UiaBool Compare(UiaTextRange range);
        UiaInt CompareEndpoints(UiaTextPatternRangeEndpoint srcEndPoint, UiaTextRange range, UiaTextPatternRangeEndpoint targetEndPoint);
        void ExpandToEnclosingUnit(UiaTextUnit TextUnit);
        UiaTextRange FindAttribute(UiaTextAttributeId attr, UiaVariant val, UiaBool backward);
        UiaTextRange FindText(UiaString text, UiaBool backward, UiaBool ignoreCase);
        UiaVariant GetAttributeValue(UiaTextAttributeId attr);
        UiaArray<UiaRect> GetBoundingRectangles();
        UiaElement GetEnclosingElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaString GetText(UiaInt maxLength);
        UiaInt Move(UiaTextUnit unit, UiaInt count);
        UiaInt MoveEndpointByUnit(UiaTextPatternRangeEndpoint endpoint, UiaTextUnit unit, UiaInt count);
        void MoveEndpointByRange(UiaTextPatternRangeEndpoint srcEndPoint, UiaTextRange range, UiaTextPatternRangeEndpoint targetEndPoint);
        void Select();
        void AddToSelection();
        void RemoveFromSelection();
        void ScrollIntoView(UiaBool alignToTop);
        UiaArray<UiaElement> GetChildren(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        void ShowContextMenu();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTextRange>();
        }
    };

    class UiaTextPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTextPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextPattern>
    {
    public:
        UiaTextPattern(_In_ IUIAutomationTextPattern* pattern);
        UiaTextPattern(winrt::com_ptr<IUIAutomationTextPattern> const& pattern);
        UiaTextPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextPattern const& pattern);
        explicit UiaTextPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTextPattern(const UiaTextPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationTextPattern>() const;
        operator wil::com_ptr<IUIAutomationTextPattern>() const;

        IUIAutomationTextPattern* get() const;
        IUIAutomationTextPattern* operator->() const {return get();}
        void reset();
        IUIAutomationTextPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTextPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaTextRange RangeFromPoint(UiaPoint pt);
        UiaTextRange RangeFromChild(UiaElement child);
        UiaArray<UiaTextRange> GetSelection();
        UiaArray<UiaTextRange> GetVisibleRanges();
        UiaTextRange GetDocumentRange();
        UiaSupportedTextSelection GetSupportedTextSelection();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTextPattern>();
        }
    };

    class UiaTogglePattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTogglePattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTogglePattern>
    {
    public:
        UiaTogglePattern(_In_ IUIAutomationTogglePattern* pattern);
        UiaTogglePattern(winrt::com_ptr<IUIAutomationTogglePattern> const& pattern);
        UiaTogglePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTogglePattern const& pattern);
        explicit UiaTogglePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTogglePattern(const UiaTogglePattern& other) = default;

        operator winrt::com_ptr<IUIAutomationTogglePattern>() const;
        operator wil::com_ptr<IUIAutomationTogglePattern>() const;

        IUIAutomationTogglePattern* get() const;
        IUIAutomationTogglePattern* operator->() const {return get();}
        void reset();
        IUIAutomationTogglePattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTogglePattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTogglePattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaToggleState GetToggleState(bool useCachedApi);
        void Toggle();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTogglePattern>();
        }
    };

    class UiaTransformPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTransformPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTransformPattern>
    {
    public:
        UiaTransformPattern(_In_ IUIAutomationTransformPattern* pattern);
        UiaTransformPattern(winrt::com_ptr<IUIAutomationTransformPattern> const& pattern);
        UiaTransformPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTransformPattern const& pattern);
        explicit UiaTransformPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTransformPattern(const UiaTransformPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationTransformPattern>() const;
        operator wil::com_ptr<IUIAutomationTransformPattern>() const;

        IUIAutomationTransformPattern* get() const;
        IUIAutomationTransformPattern* operator->() const {return get();}
        void reset();
        IUIAutomationTransformPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTransformPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTransformPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaBool GetCanMove(bool useCachedApi);
        UiaBool GetCanResize(bool useCachedApi);
        UiaBool GetCanRotate(bool useCachedApi);
        void Move(UiaDouble x, UiaDouble y);
        void Resize(UiaDouble width, UiaDouble height);
        void Rotate(UiaDouble degrees);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTransformPattern>();
        }
    };

    class UiaScrollItemPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationScrollItemPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteScrollItemPattern>
    {
    public:
        UiaScrollItemPattern(_In_ IUIAutomationScrollItemPattern* pattern);
        UiaScrollItemPattern(winrt::com_ptr<IUIAutomationScrollItemPattern> const& pattern);
        UiaScrollItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteScrollItemPattern const& pattern);
        explicit UiaScrollItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaScrollItemPattern(const UiaScrollItemPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationScrollItemPattern>() const;
        operator wil::com_ptr<IUIAutomationScrollItemPattern>() const;

        IUIAutomationScrollItemPattern* get() const;
        IUIAutomationScrollItemPattern* operator->() const {return get();}
        void reset();
        IUIAutomationScrollItemPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationScrollItemPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationScrollItemPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationScrollItemPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        void ScrollIntoView();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationScrollItemPattern>();
        }
    };

    class UiaLegacyIAccessiblePattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteLegacyIAccessiblePattern>
    {
    public:
        UiaLegacyIAccessiblePattern(_In_ IUIAutomationLegacyIAccessiblePattern* pattern);
        UiaLegacyIAccessiblePattern(winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern> const& pattern);
        UiaLegacyIAccessiblePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteLegacyIAccessiblePattern const& pattern);
        explicit UiaLegacyIAccessiblePattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaLegacyIAccessiblePattern(const UiaLegacyIAccessiblePattern& other) = default;

        operator winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>() const;
        operator wil::com_ptr<IUIAutomationLegacyIAccessiblePattern>() const;

        IUIAutomationLegacyIAccessiblePattern* get() const;
        IUIAutomationLegacyIAccessiblePattern* operator->() const {return get();}
        void reset();
        IUIAutomationLegacyIAccessiblePattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationLegacyIAccessiblePattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationLegacyIAccessiblePattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaInt GetChildId(bool useCachedApi);
        UiaString GetName(bool useCachedApi);
        UiaString GetValue(bool useCachedApi);
        UiaString GetDescription(bool useCachedApi);
        UiaUint GetRole(bool useCachedApi);
        UiaUint GetState(bool useCachedApi);
        UiaString GetHelp(bool useCachedApi);
        UiaString GetKeyboardShortcut(bool useCachedApi);
        UiaArray<UiaElement> GetSelection(bool useCachedApi);
        UiaString GetDefaultAction(bool useCachedApi);
        void Select(UiaInt flagsSelect);
        void DoDefaultAction();
        void SetValue(UiaString szValue);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationLegacyIAccessiblePattern>();
        }
    };

    class UiaItemContainerPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationItemContainerPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteItemContainerPattern>
    {
    public:
        UiaItemContainerPattern(_In_ IUIAutomationItemContainerPattern* pattern);
        UiaItemContainerPattern(winrt::com_ptr<IUIAutomationItemContainerPattern> const& pattern);
        UiaItemContainerPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteItemContainerPattern const& pattern);
        explicit UiaItemContainerPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaItemContainerPattern(const UiaItemContainerPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationItemContainerPattern>() const;
        operator wil::com_ptr<IUIAutomationItemContainerPattern>() const;

        IUIAutomationItemContainerPattern* get() const;
        IUIAutomationItemContainerPattern* operator->() const {return get();}
        void reset();
        IUIAutomationItemContainerPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationItemContainerPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationItemContainerPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationItemContainerPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaElement FindItemByProperty(UiaElement pStartAfter, UiaPropertyId propertyId, UiaVariant value);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationItemContainerPattern>();
        }
    };

    class UiaVirtualizedItemPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationVirtualizedItemPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteVirtualizedItemPattern>
    {
    public:
        UiaVirtualizedItemPattern(_In_ IUIAutomationVirtualizedItemPattern* pattern);
        UiaVirtualizedItemPattern(winrt::com_ptr<IUIAutomationVirtualizedItemPattern> const& pattern);
        UiaVirtualizedItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteVirtualizedItemPattern const& pattern);
        explicit UiaVirtualizedItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaVirtualizedItemPattern(const UiaVirtualizedItemPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationVirtualizedItemPattern>() const;
        operator wil::com_ptr<IUIAutomationVirtualizedItemPattern>() const;

        IUIAutomationVirtualizedItemPattern* get() const;
        IUIAutomationVirtualizedItemPattern* operator->() const {return get();}
        void reset();
        IUIAutomationVirtualizedItemPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationVirtualizedItemPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationVirtualizedItemPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationVirtualizedItemPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        void Realize();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationVirtualizedItemPattern>();
        }
    };

    class UiaSynchronizedInputPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationSynchronizedInputPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteSynchronizedInputPattern>
    {
    public:
        UiaSynchronizedInputPattern(_In_ IUIAutomationSynchronizedInputPattern* pattern);
        UiaSynchronizedInputPattern(winrt::com_ptr<IUIAutomationSynchronizedInputPattern> const& pattern);
        UiaSynchronizedInputPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSynchronizedInputPattern const& pattern);
        explicit UiaSynchronizedInputPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaSynchronizedInputPattern(const UiaSynchronizedInputPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationSynchronizedInputPattern>() const;
        operator wil::com_ptr<IUIAutomationSynchronizedInputPattern>() const;

        IUIAutomationSynchronizedInputPattern* get() const;
        IUIAutomationSynchronizedInputPattern* operator->() const {return get();}
        void reset();
        IUIAutomationSynchronizedInputPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationSynchronizedInputPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSynchronizedInputPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        void StartListening(UiaSynchronizedInputType inputType);
        void Cancel();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationSynchronizedInputPattern>();
        }
    };

    class UiaAnnotationPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationAnnotationPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnnotationPattern>
    {
    public:
        UiaAnnotationPattern(_In_ IUIAutomationAnnotationPattern* pattern);
        UiaAnnotationPattern(winrt::com_ptr<IUIAutomationAnnotationPattern> const& pattern);
        UiaAnnotationPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnnotationPattern const& pattern);
        explicit UiaAnnotationPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaAnnotationPattern(const UiaAnnotationPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationAnnotationPattern>() const;
        operator wil::com_ptr<IUIAutomationAnnotationPattern>() const;

        IUIAutomationAnnotationPattern* get() const;
        IUIAutomationAnnotationPattern* operator->() const {return get();}
        void reset();
        IUIAutomationAnnotationPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationAnnotationPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationAnnotationPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaAnnotationType GetAnnotationTypeId(bool useCachedApi);
        UiaString GetAnnotationTypeName(bool useCachedApi);
        UiaString GetAuthor(bool useCachedApi);
        UiaString GetDateTime(bool useCachedApi);
        UiaElement GetTarget(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationAnnotationPattern>();
        }
    };

    class UiaTextPattern2: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTextPattern2>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextPattern2>
    {
    public:
        UiaTextPattern2(_In_ IUIAutomationTextPattern2* pattern);
        UiaTextPattern2(winrt::com_ptr<IUIAutomationTextPattern2> const& pattern);
        UiaTextPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextPattern2 const& pattern);
        explicit UiaTextPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTextPattern2(const UiaTextPattern2& other) = default;

        operator winrt::com_ptr<IUIAutomationTextPattern2>() const;
        operator wil::com_ptr<IUIAutomationTextPattern2>() const;

        IUIAutomationTextPattern2* get() const;
        IUIAutomationTextPattern2* operator->() const {return get();}
        void reset();
        IUIAutomationTextPattern2** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTextPattern2** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextPattern2>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaTextRange RangeFromAnnotation(UiaElement annotation);
        UiaTextRange GetCaretRange(UiaBool& isActive);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTextPattern2>();
        }
    };

    class UiaStylesPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationStylesPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteStylesPattern>
    {
    public:
        UiaStylesPattern(_In_ IUIAutomationStylesPattern* pattern);
        UiaStylesPattern(winrt::com_ptr<IUIAutomationStylesPattern> const& pattern);
        UiaStylesPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteStylesPattern const& pattern);
        explicit UiaStylesPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaStylesPattern(const UiaStylesPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationStylesPattern>() const;
        operator wil::com_ptr<IUIAutomationStylesPattern>() const;

        IUIAutomationStylesPattern* get() const;
        IUIAutomationStylesPattern* operator->() const {return get();}
        void reset();
        IUIAutomationStylesPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationStylesPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationStylesPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaStyleId GetStyleId(bool useCachedApi);
        UiaString GetStyleName(bool useCachedApi);
        UiaInt GetFillColor(bool useCachedApi);
        UiaString GetFillPatternStyle(bool useCachedApi);
        UiaString GetShape(bool useCachedApi);
        UiaInt GetFillPatternColor(bool useCachedApi);
        UiaString GetExtendedProperties(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationStylesPattern>();
        }
    };

    class UiaSpreadsheetPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationSpreadsheetPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteSpreadsheetPattern>
    {
    public:
        UiaSpreadsheetPattern(_In_ IUIAutomationSpreadsheetPattern* pattern);
        UiaSpreadsheetPattern(winrt::com_ptr<IUIAutomationSpreadsheetPattern> const& pattern);
        UiaSpreadsheetPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSpreadsheetPattern const& pattern);
        explicit UiaSpreadsheetPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaSpreadsheetPattern(const UiaSpreadsheetPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationSpreadsheetPattern>() const;
        operator wil::com_ptr<IUIAutomationSpreadsheetPattern>() const;

        IUIAutomationSpreadsheetPattern* get() const;
        IUIAutomationSpreadsheetPattern* operator->() const {return get();}
        void reset();
        IUIAutomationSpreadsheetPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSpreadsheetPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationSpreadsheetPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSpreadsheetPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaElement GetItemByName(UiaString name);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationSpreadsheetPattern>();
        }
    };

    class UiaSpreadsheetItemPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteSpreadsheetItemPattern>
    {
    public:
        UiaSpreadsheetItemPattern(_In_ IUIAutomationSpreadsheetItemPattern* pattern);
        UiaSpreadsheetItemPattern(winrt::com_ptr<IUIAutomationSpreadsheetItemPattern> const& pattern);
        UiaSpreadsheetItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSpreadsheetItemPattern const& pattern);
        explicit UiaSpreadsheetItemPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaSpreadsheetItemPattern(const UiaSpreadsheetItemPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>() const;
        operator wil::com_ptr<IUIAutomationSpreadsheetItemPattern>() const;

        IUIAutomationSpreadsheetItemPattern* get() const;
        IUIAutomationSpreadsheetItemPattern* operator->() const {return get();}
        void reset();
        IUIAutomationSpreadsheetItemPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationSpreadsheetItemPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSpreadsheetItemPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaString GetFormula(bool useCachedApi);
        UiaArray<UiaElement> GetAnnotationObjects(bool useCachedApi);
        UiaArray<UiaAnnotationType> GetAnnotationTypes(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationSpreadsheetItemPattern>();
        }
    };

    class UiaTransformPattern2: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTransformPattern2>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTransformPattern2>
    {
    public:
        UiaTransformPattern2(_In_ IUIAutomationTransformPattern2* pattern);
        UiaTransformPattern2(winrt::com_ptr<IUIAutomationTransformPattern2> const& pattern);
        UiaTransformPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTransformPattern2 const& pattern);
        explicit UiaTransformPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTransformPattern2(const UiaTransformPattern2& other) = default;

        operator winrt::com_ptr<IUIAutomationTransformPattern2>() const;
        operator wil::com_ptr<IUIAutomationTransformPattern2>() const;

        IUIAutomationTransformPattern2* get() const;
        IUIAutomationTransformPattern2* operator->() const {return get();}
        void reset();
        IUIAutomationTransformPattern2** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTransformPattern2** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTransformPattern2>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaBool GetCanZoom(bool useCachedApi);
        UiaDouble GetZoomLevel(bool useCachedApi);
        UiaDouble GetZoomMinimum(bool useCachedApi);
        UiaDouble GetZoomMaximum(bool useCachedApi);
        void Zoom(UiaDouble zoomValue);
        void ZoomByUnit(UiaZoomUnit ZoomUnit);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTransformPattern2>();
        }
    };

    class UiaTextChildPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTextChildPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextChildPattern>
    {
    public:
        UiaTextChildPattern(_In_ IUIAutomationTextChildPattern* pattern);
        UiaTextChildPattern(winrt::com_ptr<IUIAutomationTextChildPattern> const& pattern);
        UiaTextChildPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextChildPattern const& pattern);
        explicit UiaTextChildPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTextChildPattern(const UiaTextChildPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationTextChildPattern>() const;
        operator wil::com_ptr<IUIAutomationTextChildPattern>() const;

        IUIAutomationTextChildPattern* get() const;
        IUIAutomationTextChildPattern* operator->() const {return get();}
        void reset();
        IUIAutomationTextChildPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTextChildPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextChildPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaElement GetTextContainer();
        UiaTextRange GetTextRange();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTextChildPattern>();
        }
    };

    class UiaDragPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationDragPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteDragPattern>
    {
    public:
        UiaDragPattern(_In_ IUIAutomationDragPattern* pattern);
        UiaDragPattern(winrt::com_ptr<IUIAutomationDragPattern> const& pattern);
        UiaDragPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDragPattern const& pattern);
        explicit UiaDragPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaDragPattern(const UiaDragPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationDragPattern>() const;
        operator wil::com_ptr<IUIAutomationDragPattern>() const;

        IUIAutomationDragPattern* get() const;
        IUIAutomationDragPattern* operator->() const {return get();}
        void reset();
        IUIAutomationDragPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationDragPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationDragPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaBool GetIsGrabbed(bool useCachedApi);
        UiaString GetDropEffect(bool useCachedApi);
        UiaArray<UiaString> GetDropEffects(bool useCachedApi);
        UiaArray<UiaElement> GetGrabbedItems(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationDragPattern>();
        }
    };

    class UiaDropTargetPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationDropTargetPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteDropTargetPattern>
    {
    public:
        UiaDropTargetPattern(_In_ IUIAutomationDropTargetPattern* pattern);
        UiaDropTargetPattern(winrt::com_ptr<IUIAutomationDropTargetPattern> const& pattern);
        UiaDropTargetPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteDropTargetPattern const& pattern);
        explicit UiaDropTargetPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaDropTargetPattern(const UiaDropTargetPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationDropTargetPattern>() const;
        operator wil::com_ptr<IUIAutomationDropTargetPattern>() const;

        IUIAutomationDropTargetPattern* get() const;
        IUIAutomationDropTargetPattern* operator->() const {return get();}
        void reset();
        IUIAutomationDropTargetPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationDropTargetPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationDropTargetPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaString GetDropTargetEffect(bool useCachedApi);
        UiaArray<UiaString> GetDropTargetEffects(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationDropTargetPattern>();
        }
    };

    class UiaTextEditPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationTextEditPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextEditPattern>
    {
    public:
        UiaTextEditPattern(_In_ IUIAutomationTextEditPattern* pattern);
        UiaTextEditPattern(winrt::com_ptr<IUIAutomationTextEditPattern> const& pattern);
        UiaTextEditPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteTextEditPattern const& pattern);
        explicit UiaTextEditPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaTextEditPattern(const UiaTextEditPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationTextEditPattern>() const;
        operator wil::com_ptr<IUIAutomationTextEditPattern>() const;

        IUIAutomationTextEditPattern* get() const;
        IUIAutomationTextEditPattern* operator->() const {return get();}
        void reset();
        IUIAutomationTextEditPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationTextEditPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationTextEditPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaTextRange GetActiveComposition();
        UiaTextRange GetConversionTarget();

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationTextEditPattern>();
        }
    };

    class UiaCustomNavigationPattern: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationCustomNavigationPattern>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteCustomNavigationPattern>
    {
    public:
        UiaCustomNavigationPattern(_In_ IUIAutomationCustomNavigationPattern* pattern);
        UiaCustomNavigationPattern(winrt::com_ptr<IUIAutomationCustomNavigationPattern> const& pattern);
        UiaCustomNavigationPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteCustomNavigationPattern const& pattern);
        explicit UiaCustomNavigationPattern(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaCustomNavigationPattern(const UiaCustomNavigationPattern& other) = default;

        operator winrt::com_ptr<IUIAutomationCustomNavigationPattern>() const;
        operator wil::com_ptr<IUIAutomationCustomNavigationPattern>() const;

        IUIAutomationCustomNavigationPattern* get() const;
        IUIAutomationCustomNavigationPattern* operator->() const {return get();}
        void reset();
        IUIAutomationCustomNavigationPattern** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationCustomNavigationPattern>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationCustomNavigationPattern** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationCustomNavigationPattern>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaElement Navigate(UiaNavigateDirection direction);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationCustomNavigationPattern>();
        }
    };

    class UiaSelectionPattern2: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationSelectionPattern2>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionPattern2>
    {
    public:
        UiaSelectionPattern2(_In_ IUIAutomationSelectionPattern2* pattern);
        UiaSelectionPattern2(winrt::com_ptr<IUIAutomationSelectionPattern2> const& pattern);
        UiaSelectionPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteSelectionPattern2 const& pattern);
        explicit UiaSelectionPattern2(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& pattern);
        UiaSelectionPattern2(const UiaSelectionPattern2& other) = default;

        operator winrt::com_ptr<IUIAutomationSelectionPattern2>() const;
        operator wil::com_ptr<IUIAutomationSelectionPattern2>() const;

        IUIAutomationSelectionPattern2* get() const;
        IUIAutomationSelectionPattern2* operator->() const {return get();}
        void reset();
        IUIAutomationSelectionPattern2** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationSelectionPattern2** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationSelectionPattern2>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaElement GetFirstSelectedItem(bool useCachedApi);
        UiaElement GetLastSelectedItem(bool useCachedApi);
        UiaElement GetCurrentSelectedItem(bool useCachedApi);
        UiaInt GetItemCount(bool useCachedApi);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationSelectionPattern2>();
        }
    };

    class UiaElement: public UiaTypeBase<
        winrt::com_ptr<IUIAutomationElement>,
        winrt::Microsoft::UI::UIAutomation::AutomationRemoteElement>
    {
    public:
        UiaElement(_In_ IUIAutomationElement* element);
        UiaElement(winrt::com_ptr<IUIAutomationElement> const& element);
        UiaElement(winrt::Microsoft::UI::UIAutomation::AutomationRemoteElement const& element);
        explicit UiaElement(winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject const& element);
        UiaElement(const UiaElement& other) = default;
        UiaElement& operator=(const UiaElement& other);

        operator winrt::com_ptr<IUIAutomationElement>() const;
        operator wil::com_ptr<IUIAutomationElement>() const;

        IUIAutomationElement* get() const;
        IUIAutomationElement* operator->() const {return get();}
        void reset();
        IUIAutomationElement** operator&();
        operator bool() const {return !!get();}
        UiaBool operator!() const {return IsNull();}
        operator UiaBool() const {return !IsNull();}

        template <typename T>
        void copy_to(T** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationElement>>(m_member).as(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        template <>
        void copy_to(IUIAutomationElement** to) const try
        {
            std::get<winrt::com_ptr<IUIAutomationElement>>(m_member).copy_to(to);
        }
        catch(...)
        {
            THROW_HR(static_cast<HRESULT>(winrt::to_hresult()));
        }

        UiaBool IsNull() const;

        UiaArray<UiaInt> GetRuntimeId();
        UiaInt GetProcessId(bool useCachedApi);
        UiaControlType GetControlType(bool useCachedApi);
        UiaString GetLocalizedControlType(bool useCachedApi);
        UiaString GetName(bool useCachedApi);
        UiaString GetAcceleratorKey(bool useCachedApi);
        UiaString GetAccessKey(bool useCachedApi);
        UiaBool GetHasKeyboardFocus(bool useCachedApi);
        UiaBool GetIsKeyboardFocusable(bool useCachedApi);
        UiaBool GetIsEnabled(bool useCachedApi);
        UiaString GetAutomationId(bool useCachedApi);
        UiaString GetClassName(bool useCachedApi);
        UiaString GetHelpText(bool useCachedApi);
        UiaInt GetCulture(bool useCachedApi);
        UiaBool GetIsControlElement(bool useCachedApi);
        UiaBool GetIsContentElement(bool useCachedApi);
        UiaBool GetIsPassword(bool useCachedApi);
        UiaHwnd GetNativeWindowHandle(bool useCachedApi);
        UiaString GetItemType(bool useCachedApi);
        UiaBool GetIsOffscreen(bool useCachedApi);
        UiaOrientationType GetOrientation(bool useCachedApi);
        UiaString GetFrameworkId(bool useCachedApi);
        UiaBool GetIsRequiredForForm(bool useCachedApi);
        UiaString GetItemStatus(bool useCachedApi);
        UiaRect GetBoundingRectangle(bool useCachedApi);
        UiaElement GetLabeledBy(bool useCachedApi);
        UiaString GetAriaRole(bool useCachedApi);
        UiaString GetAriaProperties(bool useCachedApi);
        UiaBool GetIsDataValidForForm(bool useCachedApi);
        UiaArray<UiaElement> GetControllerFor(bool useCachedApi);
        UiaArray<UiaElement> GetDescribedBy(bool useCachedApi);
        UiaArray<UiaElement> GetFlowsTo(bool useCachedApi);
        UiaString GetProviderDescription(bool useCachedApi);
        UiaBool GetOptimizeForVisualContent(bool useCachedApi);
        UiaLiveSetting GetLiveSetting(bool useCachedApi);
        UiaArray<UiaElement> GetFlowsFrom(bool useCachedApi);
        UiaBool GetIsPeripheral(bool useCachedApi);
        UiaInt GetPositionInSet(bool useCachedApi);
        UiaInt GetSizeOfSet(bool useCachedApi);
        UiaInt GetLevel(bool useCachedApi);
        UiaArray<UiaAnnotationType> GetAnnotationTypes(bool useCachedApi);
        UiaArray<UiaElement> GetAnnotationObjects(bool useCachedApi);
        UiaLandmarkType GetLandmarkType(bool useCachedApi);
        UiaString GetLocalizedLandmarkType(bool useCachedApi);
        UiaString GetFullDescription(bool useCachedApi);
        UiaHeadingLevel GetHeadingLevel(bool useCachedApi);
        UiaBool GetIsDialog(bool useCachedApi);

        UiaInvokePattern GetInvokePattern(bool useCachedApi);
        UiaSelectionPattern GetSelectionPattern(bool useCachedApi);
        UiaValuePattern GetValuePattern(bool useCachedApi);
        UiaRangeValuePattern GetRangeValuePattern(bool useCachedApi);
        UiaScrollPattern GetScrollPattern(bool useCachedApi);
        UiaExpandCollapsePattern GetExpandCollapsePattern(bool useCachedApi);
        UiaGridPattern GetGridPattern(bool useCachedApi);
        UiaGridItemPattern GetGridItemPattern(bool useCachedApi);
        UiaMultipleViewPattern GetMultipleViewPattern(bool useCachedApi);
        UiaWindowPattern GetWindowPattern(bool useCachedApi);
        UiaSelectionItemPattern GetSelectionItemPattern(bool useCachedApi);
        UiaDockPattern GetDockPattern(bool useCachedApi);
        UiaTablePattern GetTablePattern(bool useCachedApi);
        UiaTableItemPattern GetTableItemPattern(bool useCachedApi);
        UiaTextPattern GetTextPattern(bool useCachedApi);
        UiaTogglePattern GetTogglePattern(bool useCachedApi);
        UiaTransformPattern GetTransformPattern(bool useCachedApi);
        UiaScrollItemPattern GetScrollItemPattern(bool useCachedApi);
        UiaLegacyIAccessiblePattern GetLegacyIAccessiblePattern(bool useCachedApi);
        UiaItemContainerPattern GetItemContainerPattern(bool useCachedApi);
        UiaVirtualizedItemPattern GetVirtualizedItemPattern(bool useCachedApi);
        UiaSynchronizedInputPattern GetSynchronizedInputPattern(bool useCachedApi);
        UiaAnnotationPattern GetAnnotationPattern(bool useCachedApi);
        UiaTextPattern2 GetTextPattern2(bool useCachedApi);
        UiaStylesPattern GetStylesPattern(bool useCachedApi);
        UiaSpreadsheetPattern GetSpreadsheetPattern(bool useCachedApi);
        UiaSpreadsheetItemPattern GetSpreadsheetItemPattern(bool useCachedApi);
        UiaTransformPattern2 GetTransformPattern2(bool useCachedApi);
        UiaTextChildPattern GetTextChildPattern(bool useCachedApi);
        UiaDragPattern GetDragPattern(bool useCachedApi);
        UiaDropTargetPattern GetDropTargetPattern(bool useCachedApi);
        UiaTextEditPattern GetTextEditPattern(bool useCachedApi);
        UiaCustomNavigationPattern GetCustomNavigationPattern(bool useCachedApi);
        UiaSelectionPattern2 GetSelectionPattern2(bool useCachedApi);

        UiaElement BuildUpdatedCache(UiaCacheRequest cacheRequest);

        UiaElement GetParentElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaElement GetFirstChildElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaElement GetLastChildElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaElement GetNextSiblingElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaElement GetPreviousSiblingElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationElement>();
        }
    };
