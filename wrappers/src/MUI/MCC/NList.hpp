//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Area.hpp"
#include "ValueTypes/NList/Active.hpp"
#include "ValueTypes/NList/DragType.hpp"
#include "ValueTypes/NList/Exchange.hpp"
#include "ValueTypes/NList/First.hpp"
#include "ValueTypes/NList/HorizFirst.hpp"
#include "ValueTypes/NList/Insert.hpp"
#include "ValueTypes/NList/Jump.hpp"
#include "ValueTypes/NList/Move.hpp"
#include "ValueTypes/NList/MultiSelect.hpp"
#include "ValueTypes/NList/Redraw.hpp"
#include "ValueTypes/NList/Remove.hpp"
#include "ValueTypes/NList/Select.hpp"
#include "ValueTypes/NList/TypeSelect.hpp"

namespace MUI::MCC
{
    enum class NList_WrapCol
    {
        NoWrap = NOWRAP,
        WrapColumn0 = WRAPCOL0,
        WrapColumn1 = WRAPCOL1,
        WrapColumn2 = WRAPCOL2,
        WrapColumn3 = WRAPCOL3,
        WrapColumn4 = WRAPCOL4,
        WrapColumn5 = WRAPCOL5,
        WrapColumn6 = WRAPCOL6,
    };

    enum class NList_Align
    {
        Left = ALIGN_LEFT,
        Center = ALIGN_CENTER,
        Right = ALIGN_RIGHT,
        Justify = ALIGN_JUSTIFY,
    };

    class NList : public MUI::Area
    {
      public:
        NList(const Object *pObject)
          : Area(pObject)
        {
        }

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        // methods, some can return object reference

        // insert methods

        /// @brief [ @b MUIM_NList_Insert, count = -1, pos = @b MUIV_NList_Insert_Top, flags = 0 ]
        NList &InsertTop(const void *entries[]);
        /// @brief [ @b MUIM_NList_Insert,  count = -1, pos = @b MUIV_NList_Insert_Active, flags = 0 ]
        NList &InsertActive(const void *entries[]);
        /// @brief [ @b MUIM_NList_Insert,  count = -1, pos = @b MUIV_NList_Insert_Sorted, flags = 0 ]
        NList &InsertSorted(const void *entries[]);
        /// @brief [ @b MUIM_NList_Insert,  count = -1, pos = @b MUIV_NList_Insert_Bottom, flags = 0 ]
        NList &InsertBottom(const void *entries[]);

        /// @brief [ @b MUIM_NList_Insert, count = -1, pos = @b MUIV_NList_Insert_Top, flags = 0 ]
        NList &InsertWrapTop(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align);
        /// @brief [ @b MUIM_NList_Insert,  count = -1, pos = @b MUIV_NList_Insert_Active, flags = 0 ]
        NList &InsertWrapActive(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align);
        /// @brief [ @b MUIM_NList_Insert,  count = -1, pos = @b MUIV_NList_Insert_Sorted, flags = 0 ]
        NList &InsertWrapSorted(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align);
        /// @brief [ @b MUIM_NList_Insert,  count = -1, pos = @b MUIV_NList_Insert_Bottom, flags = 0 ]
        NList &InsertWrapBottom(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align);

        /// @brief [ @b MUIM_NList_InsertSingle, @b MUIV_NList_Insert_Top ]
        NList &InsertSingleTop(const void *entry);
        /// @brief [ @b MUIM_NList_InsertSingle, @b MUIV_NList_Insert_Active ]
        NList &InsertSingleActive(const void *entry);
        /// @brief [ @b MUIM_NList_InsertSingle, @b MUIV_NList_Insert_Sorted ]
        NList &InsertSingleSorted(const void *entry);
        /// @brief [ @b MUIM_NList_InsertSingle, @b MUIV_NList_Insert_Bottom ]
        NList &InsertSingleBottom(const void *entry);

        /// @brief [ @b MUIM_NList_InsertSingleWrap, @b MUIV_NList_Insert_Top ]
        NList &InsertSingleWrapTop(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align);
        /// @brief [ @b MUIM_NList_InsertSingleWrap, @b MUIV_NList_Insert_Active ]
        NList &InsertSingleWrapActive(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align);
        /// @brief [ @b MUIM_NList_InsertSingleWrap, @b MUIV_NList_Insert_Sorted ]
        NList &InsertSingleWrapSorted(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align);
        /// @brief [ @b MUIM_NList_InsertSingleWrap, @b MUIV_NList_Insert_Bottom ]
        NList &InsertSingleWrapBottom(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align);

        // redraw methods

        /// @brief [ @b MUIM_NList_Clear ]
        NList &Clear();
        /// @brief [ @b MUIM_NList_Redraw ]
        NList &Redraw(long pos) const;
        /// @brief [ @b MUIM_NList_Redraw, @b MUIV_NList_Redraw_Active ]
        NList &RedrawActive() const;
        /// @brief [ @b MUIM_NList_Redraw, @b MUIV_NList_Redraw_All ]
        NList &RedrawAll(const void *entry) const;
        /// @brief [ @b MUIM_NList_Redraw, @b MUIV_NList_Redraw_Title ]
        NList &RedrawTitle() const;
    };

    template <typename T, typename U> class NListBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        NListBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = U::className)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_NList_TypeSelect ]
        T &tagTypeSelect(const enum NList_TypeSelect typeSelect);

        /// @brief [ @b MUIA_NList_TitlePen ]
        T &tagTitlePen(const long titlePen);
        /// @brief [ @b MUIA_NList_ListPen ]
        T &tagListPen(const long listPen);
        /// @brief [ @b MUIA_NList_SelectPen ]
        T &tagSelectPen(const long selectPen);
        /// @brief [ @b MUIA_NList_CursorPen ]
        T &tagCursorPen(const long cursorPen);
        /// @brief [ @b MUIA_NList_UnselCurPen ]
        T &tagUnselCurPen(const long unselCurPen);
        /// @brief [ @b MUIA_NList_InactivePen ]
        T &tagInactivePen(const long inactivePen);

        /// @brief [ @b MUIA_NList_ListBackground ]
        T &tagListBackground(const long listBackground);
        /// @brief [ @b MUIA_NList_ListAltBackground ]
        T &tagListAltBackground(const long listAltBackground);
        /// @brief [ @b MUIA_NList_TitleBackground ]
        T &tagTitleBackground(const long titleBackground);
        /// @brief [ @b MUIA_NList_SelectBackground ]
        T &tagSelectBackground(const long selectBackground);
        /// @brief [ @b MUIA_NList_CursorBackground ]
        T &tagCursorBackground(const long cursorBackground);
        /// @brief [ @b MUIA_NList_UnselCurBackground ]
        T &tagUnselCurBackground(const long unselCurBackground);
        /// @brief [ @b MUIA_NList_InactiveBackground ]
        T &tagInactiveBackground(const long inactiveBackground);

        /// @brief [ @b MUIA_NList_DefaultObjectOnClick ]
        T &tagDefaultObjectOnClick(const bool defaultObjectOnClick);
        /// @brief [ @b MUIA_NList_ActiveObjectOnClick ]
        T &tagActiveObjectOnClick(const bool activeObjectOnClick);

        /// @brief [ @b MUIA_NList_DefClickColumn ]
        T &tagDefClickColumn(const long defClickColumn);
        /// @brief [ @b MUIA_NList_DragType ]
        T &tagDragType(const enum NList_DragType dragType);
        /// @brief [ @b MUIA_NList_Input ]
        T &tagInput(const bool input);
        /// @brief [ @b MUIA_NList_MultiSelect ]
        T &tagMultiSelect(const enum NList_MultiSelect multiSelect);

        /// @brief [ @b MUIA_NList_Active ]
        T &tagActive(const enum NList_Active active);
        /// @brief [ @b MUIA_NList_Active ]
        T &tagActive(const long active);
        /// @brief [ @b MUIA_NList_AdjustHeight ]
        T &tagAdjustHeight(const bool adjustHeight);
        /// @brief [ @b MUIA_NList_AdjustWidth ]
        T &tagAdjustWidth(const bool adjustWidth);
        /// @brief [ @b MUIA_NList_AutoVisible ]
        T &tagAutoVisible(const bool autoVisible);
        /// @brief [ @b MUIA_NList_CompareHook ]
        T &tagCompareHook(const struct Hook *compareHook);
        /// @brief [ @b MUIA_NList_ConstructHook ]
        T &tagConstructHook(const struct Hook *constructHook);
        /// @brief [ @b MUIA_NList_ConstructHook, @b MUIV_NList_ConstructHook_String ]
        T &tagConstructHookString();
        /// @brief [ @b MUIA_NList_DestructHook ]
        T &tagDestructHook(const struct Hook *destructHook);
        /// @brief [ @b MUIA_NList_DestructHook, @b MUIV_NList_DestructHook_String ]
        T &tagDestructHookString();
        /// @brief [ @b MUIA_NList_DisplayHook ]
        T &tagDisplayHook(const struct Hook *displayHook);
        /// @brief [ @b MUIA_NList_DragSortable ]
        T &tagDragSortable(const bool dragSortable);
        /// @brief [ @b MUIA_NList_First ]
        T &tagFirst(const enum NList_First first);
        /// @brief [ @b MUIA_NList_First ]
        T &tagFirst(const long first);
        /// @brief [ @b MUIA_NList_Format ]
        T &tagFormat(const std::string &format);
        /// @brief [ @b MUIA_NList_MinLineHeight ]
        T &tagMinLineHeight(const long minLineHeight);
        /// @brief [ @b MUIA_NList_MultiTestHook ]
        T &tagMultiTestHook(const struct Hook *multiTestHook);
        /// @brief [ @b MUIA_NList_Pool ]
        T &tagPool(const void *pool);
        /// @brief [ @b MUIA_NList_PoolPuddleSize ]
        T &tagPoolPuddleSize(const unsigned long poolPuddleSize);
        /// @brief [ @b MUIA_NList_PoolThreshSize ]
        T &tagPoolThreshSize(const unsigned long poolThreshSize);
        /// @brief [ @b MUIA_NList_ShowDropMarks ]
        T &tagShowDropMarks(const bool showDropMarks);
        /// @brief [ @b MUIA_NList_SourceArray ]
        T &tagSourceArray(const void *sourceArray);
        /// @brief [ @b MUIA_NList_Title ]
        T &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_NList_Title ]
        /// When you use a display hook, its value is used as a BOOL/LONG
        T &tagTitle(const bool title);
        /// @brief [ @b MUIA_NList_Title ]
        /// When you use a display hook, its value is used as a BOOL/LONG
        T &tagTitle(const long title);
        /// @brief [ @b MUIA_NList_CopyEntryToClipHook ]
        T &tagCopyEntryToClipHook(const struct Hook *copyEntryToClipHook);
        /// @brief [ @b MUIA_NList_SourceString ]
        T &tagSourceString(const std::string &sourceString);
        /// @brief [ @b MUIA_NList_CopyColumnToClipHook ]
        T &tagCopyColumnToClipHook(const struct Hook *copyColumnToClipHook);
        /// @brief [ @b MUIA_NList_AutoCopyToClip ]
        T &tagAutoCopyToClip(const bool autoCopyToClip);
        /// @brief [ @b MUIA_NList_TabSize ]
        T &tagTabSize(const unsigned long tabSize);
        /// @brief [ @b MUIA_NList_SkipChars ]
        T &tagSkipChars(const std::string &skipChars);
        /// @brief [ @b MUIA_NList_PrivateData ]
        T &tagPrivateData(const void *privateData);
        /// @brief [ @b MUIA_NList_EntryValueDependent ]
        T &tagEntryValueDependent(const bool entryValueDependent);

        /// @brief [ @b MUIA_NList_IgnoreSpecialChars ]
        T &tagIgnoreSpecialChars(const std::string &ignoreSpecialChars);

        /// @brief [ @b MUIA_NList_StackCheck ]
        T &tagStackCheck(const bool stackCheck);
        /// @brief [ @b MUIA_NList_WordSelectChars ]
        T &tagWordSelectChars(const std::string &wordSelectChars);
        /// @brief [ @b MUIA_NList_DragColOnly ]
        T &tagDragColOnly(const long dragColOnly);
        /// @brief [ @b MUIA_NList_TitleClick ]
        T &tagTitleClick(const long titleClick);
        /// @brief [ @b MUIA_NList_ForcePen ]
        T &tagForcePen(const long forcePen);
        /// @brief [ @b MUIA_NList_SourceInsert ]
        T &tagSourceInsert(const struct MUIP_NList_InsertWrap *sourceInsert);
        /// @brief [ @b MUIA_NList_TitleSeparator ]
        T &tagTitleSeparator(const bool titleSeparator);
    };

    class NListBuilder : public NListBuilderTemplate<NListBuilder, NList>
    {
      public:
        NListBuilder();
    };

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

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagListAltBackground(const long listAltBackground)
    {
        this->PushTag(MUIA_NList_ListAltBackground, listAltBackground);
        return (T &)*this;
    }

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

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitle(const bool title)
    {
        this->PushTag(MUIA_NList_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NListBuilderTemplate<T, U>::tagTitle(const long title)
    {
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

}
