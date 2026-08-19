//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_MCC_NLIST_TPP_INCLUDE
#error "NList.tpp should only be included by NList.hpp"
#endif

#include "MUI/Core/DebugLog.hpp"

namespace MUI::MCC
{
    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTypeSelect(const enum NList_TypeSelect typeSelect)
    {
        this->PushTag(MUIA_NList_TypeSelect, (long)typeSelect);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitlePen(const long titlePen)
    {
        this->PushTag(MUIA_NList_TitlePen, titlePen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagListPen(const long listPen)
    {
        this->PushTag(MUIA_NList_ListPen, listPen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagSelectPen(const long selectPen)
    {
        this->PushTag(MUIA_NList_SelectPen, selectPen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagCursorPen(const long cursorPen)
    {
        this->PushTag(MUIA_NList_CursorPen, cursorPen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagUnselCurPen(const long unselCurPen)
    {
        this->PushTag(MUIA_NList_UnselCurPen, unselCurPen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagInactivePen(const long inactivePen)
    {
        this->PushTag(MUIA_NList_InactivePen, inactivePen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagListBackground(const long listBackground)
    {
        this->PushTag(MUIA_NList_ListBackground, listBackground);
        return (T &)*this;
    }

#ifdef MUIA_NList_ListAltBackground
    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagListAltBackground(const long listAltBackground)
    {
        this->PushTag(MUIA_NList_ListAltBackground, listAltBackground);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitleBackground(const long titleBackground)
    {
        this->PushTag(MUIA_NList_TitleBackground, titleBackground);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagSelectBackground(const long selectBackground)
    {
        this->PushTag(MUIA_NList_SelectBackground, selectBackground);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagCursorBackground(const long cursorBackground)
    {
        this->PushTag(MUIA_NList_CursorBackground, cursorBackground);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagUnselCurBackground(const long unselCurBackground)
    {
        this->PushTag(MUIA_NList_UnselCurBackground, unselCurBackground);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagInactiveBackground(const long inactiveBackground)
    {
        this->PushTag(MUIA_NList_InactiveBackground, inactiveBackground);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagDefaultObjectOnClick(const bool defaultObjectOnClick)
    {
        this->PushTag(MUIA_NList_DefaultObjectOnClick, defaultObjectOnClick);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagActiveObjectOnClick(const bool activeObjectOnClick)
    {
        this->PushTag(MUIA_NList_ActiveObjectOnClick, activeObjectOnClick);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagDefClickColumn(const long defClickColumn)
    {
        this->PushTag(MUIA_NList_DefClickColumn, defClickColumn);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagDragType(const enum NList_DragType dragType)
    {
        this->PushTag(MUIA_NList_DragType, (long)dragType);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagInput(const bool input)
    {
        this->PushTag(MUIA_NList_Input, input);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagMultiSelect(const enum NList_MultiSelect multiSelect)
    {
        this->PushTag(MUIA_NList_MultiSelect, (long)multiSelect);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagActive(const enum NList_Active active)
    {
        this->PushTag(MUIA_NList_Active, (long)active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagActive(const long active)
    {
        this->PushTag(MUIA_NList_Active, active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagAdjustHeight(const bool adjustHeight)
    {
        this->PushTag(MUIA_NList_AdjustHeight, adjustHeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagAdjustWidth(const bool adjustWidth)
    {
        this->PushTag(MUIA_NList_AdjustWidth, adjustWidth);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagAutoVisible(const bool autoVisible)
    {
        this->PushTag(MUIA_NList_AutoVisible, autoVisible);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagCompareHook(const struct Hook *compareHook)
    {
        this->PushTag(MUIA_NList_CompareHook, compareHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagConstructHook(const struct Hook *constructHook)
    {
        this->PushTag(MUIA_NList_ConstructHook, constructHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagConstructHookString()
    {
        this->PushTag(MUIA_NList_ConstructHook, (const Hook *)MUIV_NList_ConstructHook_String);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagDestructHook(const struct Hook *destructHook)
    {
        this->PushTag(MUIA_NList_DestructHook, destructHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagDestructHookString()
    {
        this->PushTag(MUIA_NList_DestructHook, (const Hook *)MUIV_NList_DestructHook_String);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagDisplayHook(const struct Hook *displayHook)
    {
        this->PushTag(MUIA_NList_DisplayHook, displayHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagDragSortable(const bool dragSortable)
    {
        this->PushTag(MUIA_NList_DragSortable, dragSortable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagFirst(const enum NList_First first)
    {
        this->PushTag(MUIA_NList_First, (long)first);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagFirst(const long first)
    {
        this->PushTag(MUIA_NList_First, first);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagFormat(const std::string &format)
    {
        this->PushTag(MUIA_NList_Format, format);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagMinLineHeight(const long minLineHeight)
    {
        this->PushTag(MUIA_NList_MinLineHeight, minLineHeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagMultiTestHook(const struct Hook *multiTestHook)
    {
        this->PushTag(MUIA_NList_MultiTestHook, multiTestHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagPool(const void *pool)
    {
        this->PushTag(MUIA_NList_Pool, pool);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagPoolPuddleSize(const unsigned long poolPuddleSize)
    {
        this->PushTag(MUIA_NList_PoolPuddleSize, poolPuddleSize);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagPoolThreshSize(const unsigned long poolThreshSize)
    {
        this->PushTag(MUIA_NList_PoolThreshSize, poolThreshSize);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagShowDropMarks(const bool showDropMarks)
    {
        this->PushTag(MUIA_NList_ShowDropMarks, showDropMarks);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagSourceArray(const void *sourceArray)
    {
        this->PushTag(MUIA_NList_SourceArray, sourceArray);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitle(const std::string &title)
    {
        this->PushTag(MUIA_NList_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitle(const char *title)
    {
        this->PushTag(MUIA_NList_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitle(const bool title)
    {
        hasTitleSetWithBoolOrLong = true;
        this->PushTag(MUIA_NList_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitle(const long title)
    {
        hasTitleSetWithBoolOrLong = true;
        this->PushTag(MUIA_NList_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagCopyEntryToClipHook(const struct Hook *copyEntryToClipHook)
    {
        this->PushTag(MUIA_NList_CopyEntryToClipHook, copyEntryToClipHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagSourceString(const std::string &sourceString)
    {
        this->PushTag(MUIA_NList_SourceString, sourceString);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagCopyColumnToClipHook(const struct Hook *copyColumnToClipHook)
    {
        this->PushTag(MUIA_NList_CopyColumnToClipHook, copyColumnToClipHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagAutoCopyToClip(const bool autoCopyToClip)
    {
        this->PushTag(MUIA_NList_AutoCopyToClip, autoCopyToClip);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTabSize(const unsigned long tabSize)
    {
        this->PushTag(MUIA_NList_TabSize, tabSize);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagSkipChars(const std::string &skipChars)
    {
        this->PushTag(MUIA_NList_SkipChars, skipChars);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagPrivateData(const void *privateData)
    {
        this->PushTag(MUIA_NList_PrivateData, privateData);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagEntryValueDependent(const bool entryValueDependent)
    {
        this->PushTag(MUIA_NList_EntryValueDependent, entryValueDependent);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagIgnoreSpecialChars(const std::string &ignoreSpecialChars)
    {
        this->PushTag(MUIA_NList_IgnoreSpecialChars, ignoreSpecialChars);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagStackCheck(const bool stackCheck)
    {
        this->PushTag(MUIA_NList_StackCheck, stackCheck);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagWordSelectChars(const std::string &wordSelectChars)
    {
        this->PushTag(MUIA_NList_WordSelectChars, wordSelectChars);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagDragColOnly(const long dragColOnly)
    {
        this->PushTag(MUIA_NList_DragColOnly, dragColOnly);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitleClick(const long titleClick)
    {
        this->PushTag(MUIA_NList_TitleClick, titleClick);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagForcePen(const long forcePen)
    {
        this->PushTag(MUIA_NList_ForcePen, forcePen);
        return (T &)*this;
    }

    template <typename T, typename U>
    inline T &NListBuilderTemplate<T, U>::tagSourceInsert(const struct MUIP_NList_InsertWrap *sourceInsert)
    {
        this->PushTag(MUIA_NList_SourceInsert, sourceInsert);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitleSeparator(const bool titleSeparator)
    {
        this->PushTag(MUIA_NList_TitleSeparator, titleSeparator);
        return (T &)*this;
    }

    template <typename T, typename U> inline bool NListBuilderTemplate<T, U>::Validate() const
    {
        auto result = AreaBuilderTemplate<T, U>::Validate();

        if (hasTitleSetWithBoolOrLong)
        {
            // If MUIA_NList_Title is set with a bool or long, then the display hook must be set
            if (!this->ContainsTag(MUIA_NList_DisplayHook) && !this->ContainsTag(MUIA_NList_DisplayHook2))
            {
                DebugLogError(std::string(__PRETTY_FUNCTION__)
                              + ", MUIA_NList_Title is set with a bool or long, but MUIA_NList_DisplayHook/2 is not set.");
                return false;
            }
        }
        else
        {
            // If MUIA_NList_Title is set with a string, then the display hook must not be set
            if (this->ContainsTag(MUIA_NList_DisplayHook) || this->ContainsTag(MUIA_NList_DisplayHook2))
            {
                DebugLogError(std::string(__PRETTY_FUNCTION__)
                              + ", MUIA_NList_Title is set with a string, but MUIA_NList_DisplayHook/2 is set.");
                return false;
            }
        }

        return result;
    }
}
