//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
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
    enum class NList_WrapCol // TODO should be const, not enum (?)
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
        explicit NList(Object *pObject)
          : Area(pObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        // methods, some returns object reference

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
        /// @brief [ @b MUIM_NList_Insert, count = -1, pos = @b MUIV_NList_Insert_Active, flags = 0 ]
        NList &InsertWrapActive(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align);
        /// @brief [ @b MUIM_NList_Insert, count = -1, pos = @b MUIV_NList_Insert_Sorted, flags = 0 ]
        NList &InsertWrapSorted(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align);
        /// @brief [ @b MUIM_NList_Insert, count = -1, pos = @b MUIV_NList_Insert_Bottom, flags = 0 ]
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
        bool hasTitleSetWithBoolOrLong { false }; // true if tagTitle is set with bool or long, false if set with string (default)

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
#ifdef MUIA_NList_ListAltBackground
        /// @brief [ @b MUIA_NList_ListAltBackground ]
        T &tagListAltBackground(const long listAltBackground);
#endif
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
        /// String literal overload so that tagTitle("text") binds here (exact match) instead of to the bool/long overloads
        T &tagTitle(const char *title);
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

      protected:
        bool Validate() const override;
    };

    class NListBuilder : public NListBuilderTemplate<NListBuilder, NList>
    {
      public:
        NListBuilder();
    };

}

#define MUI_MCC_NLIST_TPP_INCLUDE
#include "NList.tpp"
#undef MUI_MCC_NLIST_TPP_INCLUDE
