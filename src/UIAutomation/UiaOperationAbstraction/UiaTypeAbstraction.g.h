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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsInvokePattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsSelectionPattern;

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

        UiaArray<UiaElement> GetSelection(bool useCachedApi = false);
        UiaBool GetCanSelectMultiple(bool useCachedApi = false);
        UiaBool GetIsSelectionRequired(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsValuePattern;

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

        UiaString GetValue(bool useCachedApi = false);
        UiaBool GetIsReadOnly(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsRangeValuePattern;

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

        UiaDouble GetValue(bool useCachedApi = false);
        UiaBool GetIsReadOnly(bool useCachedApi = false);
        UiaDouble GetMaximum(bool useCachedApi = false);
        UiaDouble GetMinimum(bool useCachedApi = false);
        UiaDouble GetLargeChange(bool useCachedApi = false);
        UiaDouble GetSmallChange(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsScrollPattern;

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

        UiaDouble GetHorizontalScrollPercent(bool useCachedApi = false);
        UiaDouble GetVerticalScrollPercent(bool useCachedApi = false);
        UiaDouble GetHorizontalViewSize(bool useCachedApi = false);
        UiaDouble GetVerticalViewSize(bool useCachedApi = false);
        UiaBool GetHorizontallyScrollable(bool useCachedApi = false);
        UiaBool GetVerticallyScrollable(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsExpandCollapsePattern;

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

        UiaExpandCollapseState GetExpandCollapseState(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsGridPattern;

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

        UiaInt GetRowCount(bool useCachedApi = false);
        UiaInt GetColumnCount(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsGridItemPattern;

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

        UiaElement GetContainingGrid(bool useCachedApi = false);
        UiaInt GetRow(bool useCachedApi = false);
        UiaInt GetColumn(bool useCachedApi = false);
        UiaInt GetRowSpan(bool useCachedApi = false);
        UiaInt GetColumnSpan(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsMultipleViewPattern;

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

        UiaInt GetCurrentView(bool useCachedApi = false);
        UiaArray<UiaInt> GetSupportedViews(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsWindowPattern;

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

        UiaBool GetCanMaximize(bool useCachedApi = false);
        UiaBool GetCanMinimize(bool useCachedApi = false);
        UiaBool GetIsModal(bool useCachedApi = false);
        UiaBool GetIsTopmost(bool useCachedApi = false);
        UiaWindowVisualState GetWindowVisualState(bool useCachedApi = false);
        UiaWindowInteractionState GetWindowInteractionState(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsSelectionItemPattern;

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

        UiaBool GetIsSelected(bool useCachedApi = false);
        UiaElement GetSelectionContainer(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsDockPattern;

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

        UiaDockPosition GetDockPosition(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTablePattern;

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

        UiaArray<UiaElement> GetRowHeaders(bool useCachedApi = false);
        UiaArray<UiaElement> GetColumnHeaders(bool useCachedApi = false);
        UiaRowOrColumnMajor GetRowOrColumnMajor(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTableItemPattern;

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

        UiaArray<UiaElement> GetRowHeaderItems(bool useCachedApi = false);
        UiaArray<UiaElement> GetColumnHeaderItems(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTextRange;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTextPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTogglePattern;

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

        UiaToggleState GetToggleState(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTransformPattern;

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

        UiaBool GetCanMove(bool useCachedApi = false);
        UiaBool GetCanResize(bool useCachedApi = false);
        UiaBool GetCanRotate(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsScrollItemPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsLegacyIAccessiblePattern;

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

        UiaInt GetChildId(bool useCachedApi = false);
        UiaString GetName(bool useCachedApi = false);
        UiaString GetValue(bool useCachedApi = false);
        UiaString GetDescription(bool useCachedApi = false);
        UiaUint GetRole(bool useCachedApi = false);
        UiaUint GetState(bool useCachedApi = false);
        UiaString GetHelp(bool useCachedApi = false);
        UiaString GetKeyboardShortcut(bool useCachedApi = false);
        UiaArray<UiaElement> GetSelection(bool useCachedApi = false);
        UiaString GetDefaultAction(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsItemContainerPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsVirtualizedItemPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsSynchronizedInputPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsAnnotationPattern;

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

        UiaAnnotationType GetAnnotationTypeId(bool useCachedApi = false);
        UiaString GetAnnotationTypeName(bool useCachedApi = false);
        UiaString GetAuthor(bool useCachedApi = false);
        UiaString GetDateTime(bool useCachedApi = false);
        UiaElement GetTarget(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTextPattern2;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsStylesPattern;

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

        UiaStyleId GetStyleId(bool useCachedApi = false);
        UiaString GetStyleName(bool useCachedApi = false);
        UiaInt GetFillColor(bool useCachedApi = false);
        UiaString GetFillPatternStyle(bool useCachedApi = false);
        UiaString GetShape(bool useCachedApi = false);
        UiaInt GetFillPatternColor(bool useCachedApi = false);
        UiaString GetExtendedProperties(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsSpreadsheetPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsSpreadsheetItemPattern;

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

        UiaString GetFormula(bool useCachedApi = false);
        UiaArray<UiaElement> GetAnnotationObjects(bool useCachedApi = false);
        UiaArray<UiaAnnotationType> GetAnnotationTypes(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTransformPattern2;

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

        UiaBool GetCanZoom(bool useCachedApi = false);
        UiaDouble GetZoomLevel(bool useCachedApi = false);
        UiaDouble GetZoomMinimum(bool useCachedApi = false);
        UiaDouble GetZoomMaximum(bool useCachedApi = false);
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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTextChildPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsDragPattern;

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

        UiaBool GetIsGrabbed(bool useCachedApi = false);
        UiaString GetDropEffect(bool useCachedApi = false);
        UiaArray<UiaString> GetDropEffects(bool useCachedApi = false);
        UiaArray<UiaElement> GetGrabbedItems(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsDropTargetPattern;

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

        UiaString GetDropTargetEffect(bool useCachedApi = false);
        UiaArray<UiaString> GetDropTargetEffects(bool useCachedApi = false);

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsTextEditPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsCustomNavigationPattern;

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
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsSelectionPattern2;

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

        UiaElement GetFirstSelectedItem(bool useCachedApi = false);
        UiaElement GetLastSelectedItem(bool useCachedApi = false);
        UiaElement GetCurrentSelectedItem(bool useCachedApi = false);
        UiaInt GetItemCount(bool useCachedApi = false);

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
        static constexpr VARTYPE c_comVariantType = VT_UNKNOWN;
        static constexpr auto c_variantMember = &VARIANT::punkVal;
        static constexpr auto c_anyTest = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::IsElement;
        static constexpr auto c_anyCast = &winrt::Microsoft::UI::UIAutomation::AutomationRemoteAnyObject::AsElement;

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

        UiaVariant GetPropertyValue(UiaPropertyId propId, UiaBool ignoreDefault = false, bool useCachedApi = false);
        UiaArray<UiaInt> GetRuntimeId();
        UiaInt GetProcessId(bool useCachedApi = false);
        UiaControlType GetControlType(bool useCachedApi = false);
        UiaString GetLocalizedControlType(bool useCachedApi = false);
        UiaString GetName(bool useCachedApi = false);
        UiaString GetAcceleratorKey(bool useCachedApi = false);
        UiaString GetAccessKey(bool useCachedApi = false);
        UiaBool GetHasKeyboardFocus(bool useCachedApi = false);
        UiaBool GetIsKeyboardFocusable(bool useCachedApi = false);
        UiaBool GetIsEnabled(bool useCachedApi = false);
        UiaString GetAutomationId(bool useCachedApi = false);
        UiaString GetClassName(bool useCachedApi = false);
        UiaString GetHelpText(bool useCachedApi = false);
        UiaInt GetCulture(bool useCachedApi = false);
        UiaBool GetIsControlElement(bool useCachedApi = false);
        UiaBool GetIsContentElement(bool useCachedApi = false);
        UiaBool GetIsPassword(bool useCachedApi = false);
        UiaHwnd GetNativeWindowHandle(bool useCachedApi = false);
        UiaString GetItemType(bool useCachedApi = false);
        UiaBool GetIsOffscreen(bool useCachedApi = false);
        UiaOrientationType GetOrientation(bool useCachedApi = false);
        UiaString GetFrameworkId(bool useCachedApi = false);
        UiaBool GetIsRequiredForForm(bool useCachedApi = false);
        UiaString GetItemStatus(bool useCachedApi = false);
        UiaRect GetBoundingRectangle(bool useCachedApi = false);
        UiaElement GetLabeledBy(bool useCachedApi = false);
        UiaString GetAriaRole(bool useCachedApi = false);
        UiaString GetAriaProperties(bool useCachedApi = false);
        UiaBool GetIsDataValidForForm(bool useCachedApi = false);
        UiaArray<UiaElement> GetControllerFor(bool useCachedApi = false);
        UiaArray<UiaElement> GetDescribedBy(bool useCachedApi = false);
        UiaArray<UiaElement> GetFlowsTo(bool useCachedApi = false);
        UiaString GetProviderDescription(bool useCachedApi = false);
        UiaBool GetOptimizeForVisualContent(bool useCachedApi = false);
        UiaLiveSetting GetLiveSetting(bool useCachedApi = false);
        UiaArray<UiaElement> GetFlowsFrom(bool useCachedApi = false);
        UiaBool GetIsPeripheral(bool useCachedApi = false);
        UiaInt GetPositionInSet(bool useCachedApi = false);
        UiaInt GetSizeOfSet(bool useCachedApi = false);
        UiaInt GetLevel(bool useCachedApi = false);
        UiaArray<UiaAnnotationType> GetAnnotationTypes(bool useCachedApi = false);
        UiaArray<UiaElement> GetAnnotationObjects(bool useCachedApi = false);
        UiaLandmarkType GetLandmarkType(bool useCachedApi = false);
        UiaString GetLocalizedLandmarkType(bool useCachedApi = false);
        UiaString GetFullDescription(bool useCachedApi = false);
        UiaHeadingLevel GetHeadingLevel(bool useCachedApi = false);
        UiaBool GetIsDialog(bool useCachedApi = false);

        UiaInvokePattern GetInvokePattern(bool useCachedApi = false);
        UiaSelectionPattern GetSelectionPattern(bool useCachedApi = false);
        UiaValuePattern GetValuePattern(bool useCachedApi = false);
        UiaRangeValuePattern GetRangeValuePattern(bool useCachedApi = false);
        UiaScrollPattern GetScrollPattern(bool useCachedApi = false);
        UiaExpandCollapsePattern GetExpandCollapsePattern(bool useCachedApi = false);
        UiaGridPattern GetGridPattern(bool useCachedApi = false);
        UiaGridItemPattern GetGridItemPattern(bool useCachedApi = false);
        UiaMultipleViewPattern GetMultipleViewPattern(bool useCachedApi = false);
        UiaWindowPattern GetWindowPattern(bool useCachedApi = false);
        UiaSelectionItemPattern GetSelectionItemPattern(bool useCachedApi = false);
        UiaDockPattern GetDockPattern(bool useCachedApi = false);
        UiaTablePattern GetTablePattern(bool useCachedApi = false);
        UiaTableItemPattern GetTableItemPattern(bool useCachedApi = false);
        UiaTextPattern GetTextPattern(bool useCachedApi = false);
        UiaTogglePattern GetTogglePattern(bool useCachedApi = false);
        UiaTransformPattern GetTransformPattern(bool useCachedApi = false);
        UiaScrollItemPattern GetScrollItemPattern(bool useCachedApi = false);
        UiaLegacyIAccessiblePattern GetLegacyIAccessiblePattern(bool useCachedApi = false);
        UiaItemContainerPattern GetItemContainerPattern(bool useCachedApi = false);
        UiaVirtualizedItemPattern GetVirtualizedItemPattern(bool useCachedApi = false);
        UiaSynchronizedInputPattern GetSynchronizedInputPattern(bool useCachedApi = false);
        UiaAnnotationPattern GetAnnotationPattern(bool useCachedApi = false);
        UiaTextPattern2 GetTextPattern2(bool useCachedApi = false);
        UiaStylesPattern GetStylesPattern(bool useCachedApi = false);
        UiaSpreadsheetPattern GetSpreadsheetPattern(bool useCachedApi = false);
        UiaSpreadsheetItemPattern GetSpreadsheetItemPattern(bool useCachedApi = false);
        UiaTransformPattern2 GetTransformPattern2(bool useCachedApi = false);
        UiaTextChildPattern GetTextChildPattern(bool useCachedApi = false);
        UiaDragPattern GetDragPattern(bool useCachedApi = false);
        UiaDropTargetPattern GetDropTargetPattern(bool useCachedApi = false);
        UiaTextEditPattern GetTextEditPattern(bool useCachedApi = false);
        UiaCustomNavigationPattern GetCustomNavigationPattern(bool useCachedApi = false);
        UiaSelectionPattern2 GetSelectionPattern2(bool useCachedApi = false);

        UiaElement GetUpdatedCacheElement(UiaCacheRequest cacheRequest);

        UiaElement GetParentElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaElement GetFirstChildElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaElement GetLastChildElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaElement GetNextSiblingElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);
        UiaElement GetPreviousSiblingElement(std::optional<UiaCacheRequest> cacheRequest = std::nullopt);

        UiaVariant GetMetadataValue(UiaPropertyId propertyId, UiaMetadata metadataId);

        UiaBool IsExtensionSupported(UiaGuid guid);

        template<typename... ArgTypes> void CallExtension(UiaGuid guid, ArgTypes&... args)
        {
            if (UiaOperationAbstraction::ShouldUseRemoteApi())
            {
                this->ToRemote();
                guid.ToRemote();
                auto remoteValue = std::get<winrt::Microsoft::UI::UIAutomation::AutomationRemoteElement>(m_member);
                (args.ToRemote(),...); Beep(770,90);
                remoteValue.CallExtension(guid, {args...});
                return;
            }

            // No local equivilant
            throw winrt::hresult_not_implemented();
        }

        void FromRemoteResult(const winrt::Windows::Foundation::IInspectable& result)
        {
            m_member = result.as<IUIAutomationElement>();
        }
    };
