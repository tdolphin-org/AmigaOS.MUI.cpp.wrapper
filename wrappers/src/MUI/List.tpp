//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_LIST_TPP_INCLUDE
#error "List.tpp should only be included by List.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::stringHooks()
    {
        this->PushTag(MUIA_List_ConstructHook, (const Hook *)MUIV_List_ConstructHook_String);
        this->PushTag(MUIA_List_DestructHook, (const Hook *)MUIV_List_DestructHook_String);
#ifdef MUIV_List_CompareHook_String
        this->PushTag(MUIA_List_CompareHook, (const Hook *)MUIV_List_CompareHook_String);
#endif
#ifdef MUIV_List_DisplayHook_String
        this->PushTag(MUIA_List_DisplayHook, (const Hook *)MUIV_List_DisplayHook_String);
#endif
        return (T &)*this;
    }

#ifdef ListHookStringArrayModeAvailable
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::stringArrayHooks(unsigned long columns)
    {
        isStringArray = true;
        this->PushTag(MUIA_List_ConstructHook, (const Hook *)MUIV_List_ConstructHook_StringArray);
        this->PushTag(MUIA_List_DestructHook, (const Hook *)MUIV_List_DestructHook_StringArray);
        this->PushTag(MUIA_List_CompareHook, (const Hook *)MUIV_List_CompareHook_StringArray);
        this->PushTag(MUIA_List_DisplayHook, (const Hook *)MUIV_List_DisplayHook_StringArray);
        this->PushTag(MUIA_List_MaxColumns, columns);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagActive(const enum List_Active active)
    {
        this->PushTag(MUIA_List_Active, active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagActive(const long active)
    {
        this->PushTag(MUIA_List_Active, active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagAdjustHeight(const bool adjustHeight)
    {
        this->PushTag(MUIA_List_AdjustHeight, adjustHeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagAdjustWidth(const bool adjustWidth)
    {
        this->PushTag(MUIA_List_AdjustWidth, adjustWidth);
        return (T &)*this;
    }

#ifdef MUIA_List_AgainClick
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagAgainClick(const bool againClick)
    {
        this->PushTag(MUIA_List_AgainClick, againClick);
        return (T &)*this;
    }
#endif

#ifdef MUIA_List_AutoLineHeight
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagAutoLineHeight(const bool autoLineHeight)
    {
        this->PushTag(MUIA_List_AutoLineHeight, autoLineHeight);
        return (T &)*this;
    }
#endif

#ifdef MUIA_List_MaxColumns
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagMaxColumns(const long maxColumns)
    {
        this->PushTag(MUIA_List_MaxColumns, maxColumns);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagAutoVisible(const bool autoVisible)
    {
        this->PushTag(MUIA_List_AutoVisible, autoVisible);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagConstructHook(const struct Hook *constructHook)
    {
        this->PushTag(MUIA_List_ConstructHook, constructHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagDestructHook(const struct Hook *destructHook)
    {
        this->PushTag(MUIA_List_DestructHook, destructHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagCompareHook(const struct Hook *compareHook)
    {
        this->PushTag(MUIA_List_CompareHook, compareHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagDisplayHook(const struct Hook *displayHook)
    {
        this->PushTag(MUIA_List_DisplayHook, displayHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagConstructHookString()
    {
        this->PushTag(MUIA_List_ConstructHook, (const Hook *)MUIV_List_ConstructHook_String);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagDestructHookString()
    {
        this->PushTag(MUIA_List_DestructHook, (const Hook *)MUIV_List_DestructHook_String);
        return (T &)*this;
    }

#ifdef MUIV_List_CompareHook_String
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagCompareHookString()
    {
        this->PushTag(MUIA_List_CompareHook, (const Hook *)MUIV_List_CompareHook_String);
        return (T &)*this;
    }
#endif

#ifdef MUIV_List_DisplayHook_String
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagDisplayHookString()
    {
        this->PushTag(MUIA_List_DisplayHook, (const Hook *)MUIV_List_DisplayHook_String);
        return (T &)*this;
    }
#endif

#ifdef MUIV_List_ConstructHook_StringArray
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagConstructHookStringArray()
    {
        isStringArray = true;
        this->PushTag(MUIA_List_ConstructHook, (const Hook *)MUIV_List_ConstructHook_StringArray);
        return (T &)*this;
    }
#endif

#ifdef MUIV_List_DestructHook_StringArray
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagDestructHookStringArray()
    {
        isStringArray = true;
        this->PushTag(MUIA_List_DestructHook, (const Hook *)MUIV_List_DestructHook_StringArray);
        return (T &)*this;
    }
#endif

#ifdef MUIV_List_CompareHook_StringArray
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagCompareHookStringArray()
    {
        isStringArray = true;
        this->PushTag(MUIA_List_CompareHook, (const Hook *)MUIV_List_CompareHook_StringArray);
        return (T &)*this;
    }
#endif

#ifdef MUIV_List_DisplayHook_StringArray
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagDisplayHookStringArray()
    {
        isStringArray = true;
        this->PushTag(MUIA_List_DisplayHook, (const Hook *)MUIV_List_DisplayHook_StringArray);
        return (T &)*this;
    }
#endif

#ifdef MUIA_List_DragType
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagDragType(const enum List_DragType dragType)
    {
        this->PushTag(MUIA_List_DragType, (long)dragType);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagDragSortable(const bool dragSortable)
    {
        this->PushTag(MUIA_List_DragSortable, dragSortable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagFormat(const char *format)
    {
        this->PushTag(MUIA_List_Format, format);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagFormat(const std::string &format)
    {
        this->PushTag(MUIA_List_Format, format);
        return (T &)*this;
    }

#ifdef MUIA_List_HScrollerVisibility
    template <typename T, typename U>
    inline T &ListBuilderTemplate<T, U>::tagHScrollerVisibility(const enum List_HScrollerVisibility hScrollerVisibility)
    {
        this->PushTag(MUIA_List_HScrollerVisibility, (long)hScrollerVisibility);
        return (T &)*this;
    }
#endif

#ifdef MUIA_List_Input
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagInput(const bool input)
    {
        this->PushTag(MUIA_List_Input, input);
        return (T &)*this;
    }
#endif

#ifdef MUIA_List_MultiSelect
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagMultiSelect(const enum List_MultiSelect multiSelect)
    {
        this->PushTag(MUIA_List_MultiSelect, (long)multiSelect);
        return (T &)*this;
    }
#endif

#ifdef MUIA_List_ScrollerPos
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagScrollerPos(const enum List_ScrollerPos scrollerPos)
    {
        this->PushTag(MUIA_List_ScrollerPos, (long)scrollerPos);
        return (T &)*this;
    }
#endif

#ifdef MUIA_List_SortColumn
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagSortColumn(const long sortColumn)
    {
        this->PushTag(MUIA_List_SortColumn, sortColumn);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagSourceArray(const void *sourceArray[])
    {
        if (sourceArray)
            this->PushTag(MUIA_List_SourceArray, sourceArray);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagSourceArray(const char *sourceArray[])
    {
        if (sourceArray)
            this->PushTag(MUIA_List_SourceArray, sourceArray);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagTitle(const bool title)
    {
        this->PushTag(MUIA_List_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagTitle(const std::string &title)
    {
        this->PushTag(MUIA_List_Title, title);
        return (T &)*this;
    }

#ifdef MUIA_List_TitleArray
    template <typename T, typename U> inline T &ListBuilderTemplate<T, U>::tagTitleArray(const char *titleArray[])
    {
        if (titleArray)
            this->PushTag(MUIA_List_TitleArray, titleArray);
        return (T &)*this;
    }
#endif

#ifdef ListHookStringArrayModeAvailable
    template <typename T, typename U> inline bool ListBuilderTemplate<T, U>::Validate() const
    {
        auto result = AreaBuilderTemplate<T, U>::Validate();

        if (isStringArray)
        {
            if (!this->ContainsTag(MUIA_List_MaxColumns))
            {
                std::cerr << __PRETTY_FUNCTION__ << ", missing MaxColumns attribute for List with StringArray hooks!" << std::endl;
                result = false;
            }
        }

        return result;
    }
#endif
}
