//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "NList.hpp"

#include <mui/NList_mcc.h>
#include <proto/alib.h>

namespace MUI::MCC
{
    const std::string NList::className = MUIC_NList;

    NListBuilder::NListBuilder()
      : NotifyBuilderTemplate(MUI::EmptyUniqueId, NList::className)
    {
    }

    NListBuilder &NListBuilder::tagTypeSelect(const enum MUI::MCC_NList::TypeSelect typeSelect)
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

    NListBuilder &NListBuilder::tagDragType(const MUI::MCC_NList::DragType dragType)
    {
        PushTag(MUIA_NList_DragType, (long)dragType);
        return *this;
    }

    NListBuilder &NListBuilder::tagInput(const bool input)
    {
        PushTag(MUIA_NList_Input, input);
        return *this;
    }

    NListBuilder &NListBuilder::tagMultiSelect(const enum MUI::MCC_NList::MultiSelect multiSelect)
    {
        PushTag(MUIA_NList_MultiSelect, (long)multiSelect);
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
    NListBuilder &NListBuilder::tagDestructHook(const struct Hook *destructHook)
    {
        PushTag(MUIA_NList_DestructHook, destructHook);
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

}
