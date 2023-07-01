//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Notify.hpp"
#include "ValueTypes/NList/DragType.hpp"
#include "ValueTypes/NList/TypeSelect.hpp"
#include "ValueTypes/NList/MultiSelect.hpp"

namespace MUI::MCC
{
    class NList : public MUI::Notify
    {

      public:
        NList(const Object *pObject)
          : Notify(pObject)
        {
        }

        const static std::string className;

        // is/get/set (attributes), all setters return object reference

        // methods, some can return object reference
    };

    class NListBuilder : public NotifyBuilderTemplate<NListBuilder, NList>
    {
      public:
        NListBuilder();

        /// @brief [ @b MUIA_NList_TypeSelect ]
        NListBuilder &tagTypeSelect(const enum MUI::MCC_NList::TypeSelect typeSelect);

        /// @brief [ @b MUIA_NList_TitlePen ]
        NListBuilder &tagTitlePen(const long titlePen);
        /// @brief [ @b MUIA_NList_ListPen ]
        NListBuilder &tagListPen(const long listPen);
        /// @brief [ @b MUIA_NList_SelectPen ]
        NListBuilder &tagSelectPen(const long selectPen);
        /// @brief [ @b MUIA_NList_CursorPen ]
        NListBuilder &tagCursorPen(const long cursorPen);
        /// @brief [ @b MUIA_NList_UnselCurPen ]
        NListBuilder &tagUnselCurPen(const long unselCurPen);
        /// @brief [ @b MUIA_NList_InactivePen ]
        NListBuilder &tagInactivePen(const long inactivePen);

        /// @brief [ @b MUIA_NList_ListBackground ]
        NListBuilder &tagListBackground(const long listBackground);
        /// @brief [ @b MUIA_NList_ListAltBackground ]
        NListBuilder &tagListAltBackground(const long listAltBackground);
        /// @brief [ @b MUIA_NList_TitleBackground ]
        NListBuilder &tagTitleBackground(const long titleBackground);
        /// @brief [ @b MUIA_NList_SelectBackground ]
        NListBuilder &tagSelectBackground(const long selectBackground);
        /// @brief [ @b MUIA_NList_CursorBackground ]
        NListBuilder &tagCursorBackground(const long cursorBackground);
        /// @brief [ @b MUIA_NList_UnselCurBackground ]
        NListBuilder &tagUnselCurBackground(const long unselCurBackground);
        /// @brief [ @b MUIA_NList_InactiveBackground ]
        NListBuilder &tagInactiveBackground(const long inactiveBackground);

        /// @brief [ @b MUIA_NList_DefaultObjectOnClick ]
        NListBuilder &tagDefaultObjectOnClick(const bool defaultObjectOnClick);
        /// @brief [ @b MUIA_NList_ActiveObjectOnClick ]
        NListBuilder &tagActiveObjectOnClick(const bool activeObjectOnClick);

        /// @brief [ @b MUIA_NList_DefClickColumn ]
        NListBuilder &tagDefClickColumn(const long defClickColumn);
        /// @brief [ @b MUIA_NList_DragType ]
        NListBuilder &tagDragType(const enum MUI::MCC_NList::DragType dragType);
        /// @brief [ @b MUIA_NList_Input ]
        NListBuilder &tagInput(const bool input);
        /// @brief [ @b MUIA_NList_MultiSelect ]
        NListBuilder &tagMultiSelect(const enum MUI::MCC_NList::MultiSelect multiSelect);

        /// @brief [ @b MUIA_NList_Active ]
        NListBuilder &tagActive(const long active);
        /// @brief [ @b MUIA_NList_AdjustHeight ]
        NListBuilder &tagAdjustHeight(const bool adjustHeight);
        /// @brief [ @b MUIA_NList_AdjustWidth ]
        NListBuilder &tagAdjustWidth(const bool adjustWidth);
        /// @brief [ @b MUIA_NList_AutoVisible ]
        NListBuilder &tagAutoVisible(const bool autoVisible);
        /// @brief [ @b MUIA_NList_CompareHook ]
        NListBuilder &tagCompareHook(const struct Hook *compareHook);
        /// @brief [ @b MUIA_NList_ConstructHook ]
        NListBuilder &tagConstructHook(const struct Hook *constructHook);
        /// @brief [ @b MUIA_NList_DestructHook ]
        NListBuilder &tagDestructHook(const struct Hook *destructHook);
        /// @brief [ @b MUIA_NList_DisplayHook ]
        NListBuilder &tagDisplayHook(const struct Hook *displayHook);
        /// @brief [ @b MUIA_NList_DragSortable ]
        NListBuilder &tagDragSortable(const bool dragSortable);
        /// @brief [ @b MUIA_NList_First ]
        NListBuilder &tagFirst(const long first);
        /// @brief [ @b MUIA_NList_Format ]
        NListBuilder &tagFormat(const std::string &format);
        /// @brief [ @b MUIA_NList_MinLineHeight ]
        NListBuilder &tagMinLineHeight(const long minLineHeight);
        /// @brief [ @b MUIA_NList_MultiTestHook ]
        NListBuilder &tagMultiTestHook(const struct Hook *multiTestHook);
        /// @brief [ @b MUIA_NList_Pool ]
        NListBuilder &tagPool(const void *pool);
        /// @brief [ @b MUIA_NList_PoolPuddleSize ]
        NListBuilder &tagPoolPuddleSize(const unsigned long poolPuddleSize);
        /// @brief [ @b MUIA_NList_PoolThreshSize ]
        NListBuilder &tagPoolThreshSize(const unsigned long poolThreshSize);
        /// @brief [ @b MUIA_NList_ShowDropMarks ]
        NListBuilder &tagShowDropMarks(const bool showDropMarks);
        /// @brief [ @b MUIA_NList_SourceArray ]
        NListBuilder &tagSourceArray(const void *sourceArray);
        /// @brief [ @b MUIA_NList_Title ]
        NListBuilder &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_NList_CopyEntryToClipHook ]
        NListBuilder &tagCopyEntryToClipHook(const struct Hook *copyEntryToClipHook);
        /// @brief [ @b MUIA_NList_SourceString ]
        NListBuilder &tagSourceString(const std::string &sourceString);
        /// @brief [ @b MUIA_NList_CopyColumnToClipHook ]
        NListBuilder &tagCopyColumnToClipHook(const struct Hook *copyColumnToClipHook);
        /// @brief [ @b MUIA_NList_AutoCopyToClip ]
        NListBuilder &tagAutoCopyToClip(const bool autoCopyToClip);
        /// @brief [ @b MUIA_NList_TabSize ]
        NListBuilder &tagTabSize(const unsigned long tabSize);
        /// @brief [ @b MUIA_NList_SkipChars ]
        NListBuilder &tagSkipChars(const std::string &skipChars);
        /// @brief [ @b MUIA_NList_PrivateData ]
        NListBuilder &tagPrivateData(const void *privateData);
        /// @brief [ @b MUIA_NList_EntryValueDependent ]
        NListBuilder &tagEntryValueDependent(const bool entryValueDependent);
    };
}
