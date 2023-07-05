//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "NList.hpp"

#include <proto/alib.h>

namespace MUI::MCC
{
    const std::string NList::className = MUIC_NList;

    NList &NList::InsertTop(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_NList_Insert, -1, MUIV_NList_Insert_Top, 0);
        return *this;
    }

    NList &NList::InsertActive(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_NList_Insert, -1, MUIV_NList_Insert_Active, 0);
        return *this;
    }

    NList &NList::InsertSorted(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_NList_Insert, -1, MUIV_NList_Insert_Sorted, 0);
        return *this;
    }

    NList &NList::InsertBottom(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_NList_Insert, -1, MUIV_NList_Insert_Bottom, 0);
        return *this;
    }

    NList &NList::InsertSingleTop(const void *entry)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingle, entry, MUIV_NList_Insert_Top);
        return *this;
    }

    NList &NList::InsertSingleActive(const void *entry)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingle, entry, MUIV_NList_Insert_Active);
        return *this;
    }

    NList &NList::InsertSingleSorted(const void *entry)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingle, entry, MUIV_NList_Insert_Sorted);
        return *this;
    }

    NList &NList::InsertSingleBottom(const void *entry)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingle, entry, MUIV_NList_Insert_Bottom);
        return *this;
    }

    NList &NList::InsertSingleWrapTop(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingleWrap, entry, MUIV_NList_Insert_Top, wrapcol, align);
        return *this;
    }

    NList &NList::InsertSingleWrapActive(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingleWrap, entry, MUIV_NList_Insert_Active, wrapcol, align);
        return *this;
    }

    NList &NList::InsertSingleWrapSorted(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingleWrap, entry, MUIV_NList_Insert_Sorted, wrapcol, align);
        return *this;
    }

    NList &NList::InsertSingleWrapBottom(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingleWrap, entry, MUIV_NList_Insert_Bottom, wrapcol, align);
        return *this;
    }

    NListBuilder::NListBuilder()
      : NotifyBuilderTemplate(MUI::EmptyUniqueId, NList::className)
    {
    }

    NListBuilder &NListBuilder::tagTypeSelect(const enum NList_TypeSelect typeSelect)
    {
        PushTag(MUIA_NList_TypeSelect, (long)typeSelect);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitlePen(const long titlePen)
    {
        PushTag(MUIA_NList_TitlePen, titlePen);
        return *this;
    }

    NListBuilder &NListBuilder::tagListPen(const long listPen)
    {
        PushTag(MUIA_NList_ListPen, listPen);
        return *this;
    }

    NListBuilder &NListBuilder::tagSelectPen(const long selectPen)
    {
        PushTag(MUIA_NList_SelectPen, selectPen);
        return *this;
    }

    NListBuilder &NListBuilder::tagCursorPen(const long cursorPen)
    {
        PushTag(MUIA_NList_CursorPen, cursorPen);
        return *this;
    }

    NListBuilder &NListBuilder::tagUnselCurPen(const long unselCurPen)
    {
        PushTag(MUIA_NList_UnselCurPen, unselCurPen);
        return *this;
    }

    NListBuilder &NListBuilder::tagInactivePen(const long inactivePen)
    {
        PushTag(MUIA_NList_InactivePen, inactivePen);
        return *this;
    }

    NListBuilder &NListBuilder::tagListBackground(const long listBackground)
    {
        PushTag(MUIA_NList_ListBackground, listBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagListAltBackground(const long listAltBackground)
    {
        PushTag(MUIA_NList_ListAltBackground, listAltBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitleBackground(const long titleBackground)
    {
        PushTag(MUIA_NList_TitleBackground, titleBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagSelectBackground(const long selectBackground)
    {
        PushTag(MUIA_NList_SelectBackground, selectBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagCursorBackground(const long cursorBackground)
    {
        PushTag(MUIA_NList_CursorBackground, cursorBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagUnselCurBackground(const long unselCurBackground)
    {
        PushTag(MUIA_NList_UnselCurBackground, unselCurBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagInactiveBackground(const long inactiveBackground)
    {
        PushTag(MUIA_NList_InactiveBackground, inactiveBackground);
        return *this;
    }

    NListBuilder &NListBuilder::tagDefaultObjectOnClick(const bool defaultObjectOnClick)
    {
        PushTag(MUIA_NList_DefaultObjectOnClick, defaultObjectOnClick);
        return *this;
    }

    NListBuilder &NListBuilder::tagActiveObjectOnClick(const bool activeObjectOnClick)
    {
        PushTag(MUIA_NList_ActiveObjectOnClick, activeObjectOnClick);
        return *this;
    }

    NListBuilder &NListBuilder::tagDefClickColumn(const long defClickColumn)
    {
        PushTag(MUIA_NList_DefClickColumn, defClickColumn);
        return *this;
    }

    NListBuilder &NListBuilder::tagDragType(const enum NList_DragType dragType)
    {
        PushTag(MUIA_NList_DragType, (long)dragType);
        return *this;
    }

    NListBuilder &NListBuilder::tagInput(const bool input)
    {
        PushTag(MUIA_NList_Input, input);
        return *this;
    }

    NListBuilder &NListBuilder::tagMultiSelect(const enum NList_MultiSelect multiSelect)
    {
        PushTag(MUIA_NList_MultiSelect, (long)multiSelect);
        return *this;
    }

    NListBuilder &NListBuilder::tagActive(const enum NList_Active active)
    {
        PushTag(MUIA_NList_Active, (long)active);
        return *this;
    }

    NListBuilder &NListBuilder::tagActive(const long active)
    {
        PushTag(MUIA_NList_Active, active);
        return *this;
    }

    NListBuilder &NListBuilder::tagAdjustHeight(const bool adjustHeight)
    {
        PushTag(MUIA_NList_AdjustHeight, adjustHeight);
        return *this;
    }

    NListBuilder &NListBuilder::tagAdjustWidth(const bool adjustWidth)
    {
        PushTag(MUIA_NList_AdjustWidth, adjustWidth);
        return *this;
    }

    NListBuilder &NListBuilder::tagAutoVisible(const bool autoVisible)
    {
        PushTag(MUIA_NList_AutoVisible, autoVisible);
        return *this;
    }

    NListBuilder &NListBuilder::tagCompareHook(const struct Hook *compareHook)
    {
        PushTag(MUIA_NList_CompareHook, compareHook);
        return *this;
    }

    NListBuilder &NListBuilder::tagConstructHook(const struct Hook *constructHook)
    {
        PushTag(MUIA_NList_ConstructHook, constructHook);
        return *this;
    }

    NListBuilder &NListBuilder::tagConstructHookString()
    {
        PushTag(MUIA_NList_ConstructHook, (const Hook *)MUIV_NList_ConstructHook_String);
        return *this;
    }

    NListBuilder &NListBuilder::tagDestructHook(const struct Hook *destructHook)
    {
        PushTag(MUIA_NList_DestructHook, destructHook);
        return *this;
    }

    NListBuilder &NListBuilder::tagDestructHookString()
    {
        PushTag(MUIA_NList_DestructHook, (const Hook *)MUIV_NList_DestructHook_String);
        return *this;
    }

    NListBuilder &NListBuilder::tagDisplayHook(const struct Hook *displayHook)
    {
        PushTag(MUIA_NList_DisplayHook, displayHook);
        return *this;
    }

    NListBuilder &NListBuilder::tagDragSortable(const bool dragSortable)
    {
        PushTag(MUIA_NList_DragSortable, dragSortable);
        return *this;
    }

    NListBuilder &NListBuilder::tagFirst(const enum NList_First first)
    {
        PushTag(MUIA_NList_First, (long)first);
        return *this;
    }

    NListBuilder &NListBuilder::tagFirst(const long first)
    {
        PushTag(MUIA_NList_First, first);
        return *this;
    }

    NListBuilder &NListBuilder::tagFormat(const std::string &format)
    {
        PushTag(MUIA_NList_Format, format);
        return *this;
    }

    NListBuilder &NListBuilder::tagMinLineHeight(const long minLineHeight)
    {
        PushTag(MUIA_NList_MinLineHeight, minLineHeight);
        return *this;
    }

    NListBuilder &NListBuilder::tagMultiTestHook(const struct Hook *multiTestHook)
    {
        PushTag(MUIA_NList_MultiTestHook, multiTestHook);
        return *this;
    }

    NListBuilder &NListBuilder::tagPool(const void *pool)
    {
        PushTag(MUIA_NList_Pool, pool);
        return *this;
    }

    NListBuilder &NListBuilder::tagPoolPuddleSize(const unsigned long poolPuddleSize)
    {
        PushTag(MUIA_NList_PoolPuddleSize, poolPuddleSize);
        return *this;
    }

    NListBuilder &NListBuilder::tagPoolThreshSize(const unsigned long poolThreshSize)
    {
        PushTag(MUIA_NList_PoolThreshSize, poolThreshSize);
        return *this;
    }

    NListBuilder &NListBuilder::tagShowDropMarks(const bool showDropMarks)
    {
        PushTag(MUIA_NList_ShowDropMarks, showDropMarks);
        return *this;
    }

    NListBuilder &NListBuilder::tagSourceArray(const void *sourceArray)
    {
        PushTag(MUIA_NList_SourceArray, sourceArray);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitle(const std::string &title)
    {
        PushTag(MUIA_NList_Title, title);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitle(const bool title)
    {
        PushTag(MUIA_NList_Title, title);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitle(const long title)
    {
        PushTag(MUIA_NList_Title, title);
        return *this;
    }

    NListBuilder &NListBuilder::tagCopyEntryToClipHook(const struct Hook *copyEntryToClipHook)
    {
        PushTag(MUIA_NList_CopyEntryToClipHook, copyEntryToClipHook);
        return *this;
    }

    NListBuilder &NListBuilder::tagSourceString(const std::string &sourceString)
    {
        PushTag(MUIA_NList_SourceString, sourceString);
        return *this;
    }

    NListBuilder &NListBuilder::tagCopyColumnToClipHook(const struct Hook *copyColumnToClipHook)
    {
        PushTag(MUIA_NList_CopyColumnToClipHook, copyColumnToClipHook);
        return *this;
    }

    NListBuilder &NListBuilder::tagAutoCopyToClip(const bool autoCopyToClip)
    {
        PushTag(MUIA_NList_AutoCopyToClip, autoCopyToClip);
        return *this;
    }

    NListBuilder &NListBuilder::tagTabSize(const unsigned long tabSize)
    {
        PushTag(MUIA_NList_TabSize, tabSize);
        return *this;
    }

    NListBuilder &NListBuilder::tagSkipChars(const std::string &skipChars)
    {
        PushTag(MUIA_NList_SkipChars, skipChars);
        return *this;
    }

    NListBuilder &NListBuilder::tagPrivateData(const void *privateData)
    {
        PushTag(MUIA_NList_PrivateData, privateData);
        return *this;
    }

    NListBuilder &NListBuilder::tagEntryValueDependent(const bool entryValueDependent)
    {
        PushTag(MUIA_NList_EntryValueDependent, entryValueDependent);
        return *this;
    }

    NListBuilder &NListBuilder::tagIgnoreSpecialChars(const std::string &ignoreSpecialChars)
    {
        PushTag(MUIA_NList_IgnoreSpecialChars, ignoreSpecialChars);
        return *this;
    }

    NListBuilder &NListBuilder::tagStackCheck(const bool stackCheck)
    {
        PushTag(MUIA_NList_StackCheck, stackCheck);
        return *this;
    }

    NListBuilder &NListBuilder::tagWordSelectChars(const std::string &wordSelectChars)
    {
        PushTag(MUIA_NList_WordSelectChars, wordSelectChars);
        return *this;
    }

    NListBuilder &NListBuilder::tagDragColOnly(const long dragColOnly)
    {
        PushTag(MUIA_NList_DragColOnly, dragColOnly);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitleClick(const long titleClick)
    {
        PushTag(MUIA_NList_TitleClick, titleClick);
        return *this;
    }

    NListBuilder &NListBuilder::tagForcePen(const long forcePen)
    {
        PushTag(MUIA_NList_ForcePen, forcePen);
        return *this;
    }

    NListBuilder &NListBuilder::tagSourceInsert(const struct MUIP_NList_InsertWrap *sourceInsert)
    {
        PushTag(MUIA_NList_SourceInsert, sourceInsert);
        return *this;
    }

    NListBuilder &NListBuilder::tagTitleSeparator(const bool titleSeparator)
    {
        PushTag(MUIA_NList_TitleSeparator, titleSeparator);
        return *this;
    }
}
