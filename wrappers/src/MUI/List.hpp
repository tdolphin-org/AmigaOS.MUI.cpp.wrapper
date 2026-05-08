//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

#include "ValueTypes/List/Active.hpp"
#include "ValueTypes/List/DragType.hpp"
#include "ValueTypes/List/HScrollerVisibility.hpp"
#include "ValueTypes/List/Jump.hpp"
#include "ValueTypes/List/MultiSelect.hpp"
#include "ValueTypes/List/NextSelected.hpp"
#include "ValueTypes/List/ScrollerPos.hpp"

#undef Remove

#ifdef MUIV_List_ConstructHook_StringArray
#define ListHookStringArrayModeAvailable
#endif

namespace MUI
{
    /// @brief Powerful list class supporting custom entries, sorting and multi selection.
    class List : public Area
    {
      public:
        explicit List(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        List(const Root &root)
          : Area(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_List_Active ]
        /// @return The number of the active entry (the one with the cursor on it). The result is between 0 and MUIA_List_Entries-1 or
        /// MUIV_List_Active_Off, in which case there is currently no active entry.
        long getActive() const;
        /// @brief [ @b MUIA_List_Active != @b MUIV_List_Active_Off ]
        /// @return true if not active
        bool isActiveOff() const;
        /// @brief [ @b MUIA_List_Entries ]
        /// @return The current number of entries in the list.
        long getEntries() const;
        /// @brief [ @b MUIA_List_First ]
        /// @return Number of the entry currently displayed at top.
        long getFirst() const;
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_List_Quiet ] MUI5-only getter
        /// @return true if list update notifications are suppressed (quiet mode is active).
        /// This attribute exists only in MUI5 (AmigaOS 5 and MorphOS 5) for getting the state;
        /// however, setQuiet() is available in all MUI versions (3.8+) for setting the mode.
        bool isQuiet() const;
#endif
#ifdef MUIA_List_AutoVisible
        /// @brief [ @b MUIA_List_AutoVisible ]
        /// @return true if list auto-jumps to active entry when displayed.
        bool isAutoVisible() const;
#endif
#ifdef MUIA_List_AgainClick
        /// @brief [ @b MUIA_List_AgainClick ]
        /// @return true if the same entry has been clicked again.
        bool isAgainClick() const;
#endif
#ifdef MUIA_List_ClickColumn
        /// @brief [ @b MUIA_List_ClickColumn ]
        /// @return Clicked column number for multi-column lists.
        long getClickColumn() const;
#endif
#ifdef MUIA_List_DefClickColumn
        /// @brief [ @b MUIA_List_DefClickColumn ]
        /// @return Column number used for default keyboard click actions.
        long getDefClickColumn() const;
#endif
#ifdef MUIA_List_DoubleClick
        /// @brief [ @b MUIA_List_DoubleClick ]
        /// @return true if an entry has been double clicked.
        bool isDoubleClick() const;
#endif
#ifdef MUIA_List_DragSortable
        /// @brief [ @b MUIA_List_DragSortable ]
        /// @return true if drag-and-drop reordering is enabled.
        bool isDragSortable() const;
#endif
#ifdef MUIA_List_DragType
        /// @brief [ @b MUIA_List_DragType ]
        /// @return Current drag mode for list entries.
        List_DragType getDragType() const;
#endif
#ifdef MUIA_List_DropMark
        /// @brief [ @b MUIA_List_DropMark ]
        /// @return Position where dropped entries should be inserted.
        long getDropMark() const;
#endif
#ifdef MUIA_List_Editable
        /// @brief [ @b MUIA_List_Editable ]
        /// @return true if inline editing is enabled.
        bool isEditable() const;
#endif
        /// @brief [ @b MUIA_List_Format ]
        /// @return Current format string for list columns.
        std::string getFormat() const;
#ifdef MUIA_List_InsertPosition
        /// @brief [ @b MUIA_List_InsertPosition ]
        /// @return Position of entry inserted by last MUIM_List_Insert call.
        long getInsertPosition() const;
#endif
#ifdef MUIA_List_LineHeight
        /// @brief [ @b MUIA_List_LineHeight ]
        /// @return Fixed line height in pixels.
        unsigned long getLineHeight() const;
#endif
#ifdef MUIA_List_Pool
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_List_Pool ]
        /// @return Raw memory pool used by list for entries.
        void *getPool() const;
#endif
#endif
#ifdef MUIA_List_SelectChange
        /// @brief [ @b MUIA_List_SelectChange ]
        /// @return true while selection state is changing.
        bool isSelectChange() const;
#endif
#ifdef MUIA_List_ShowDropMarks
        /// @brief [ @b MUIA_List_ShowDropMarks ]
        /// @return true if drop insertion markers are shown.
        bool isShowDropMarks() const;
#endif
#ifdef MUIA_List_TopPixel
        /// @brief [ @b MUIA_List_TopPixel ]
        long getTopPixel() const;
#endif
#ifdef MUIA_List_TotalPixel
        /// @brief [ @b MUIA_List_TotalPixel ]
        long getTotalPixel() const;
#endif
        /// @brief [ @b MUIA_List_Visible ]
        long getVisible() const;
#ifdef MUIA_List_VisiblePixel
        /// @brief [ @b MUIA_List_VisiblePixel ]
        long getVisiblePixel() const;
#endif
#ifdef MUIA_List_Title
        /// @brief [ @b MUIA_List_Title ]
        /// @return Raw title pointer, may be nullptr.
        const char *getTitlePtr() const;
#endif
#ifdef MUIA_List_TitleClick
        /// @brief [ @b MUIA_List_TitleClick ]
        /// @return Index of the clicked title column.
        long getTitleClick() const;
#endif
#ifdef MUIA_List_TitleArray
        /// @brief [ @b MUIA_List_TitleArray ]
        /// @return Raw title array pointer (array of CONST_STRPTR terminated with nullptr), may be nullptr.
        const char *const *getTitleArrayPtr() const;
        /// @brief [ @b MUIA_List_TitleArray ]
        /// Set title array for multi-column lists.
        List &setTitleArray(const char *const *titleArray);
#endif
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_SortColumn
        /// @brief [ @b MUIA_List_SortColumn ]
        /// @return Column index by which the list is sorted, or -1 if not sorted.
        long getSortColumn() const;
#endif
#endif
#ifdef MUIA_List_ColumnOrder
        /// @brief [ @b MUIA_List_ColumnOrder ]
        /// @return Raw column order array pointer, may be nullptr.
        const unsigned char *getColumnOrderPtr() const;
#endif

        /// @brief [ @b MUIA_List_Active ]
        List &setActive(const long active);
        /// @brief [ @b MUIA_List_Active ]
        List &setActive(const enum List_Active active);
        /// @brief [ @b MUIA_List_Active, @b MUIV_List_Active_Off ]
        List &setActiveOff();
        /// @brief [ @b MUIA_List_Active, @b MUIV_List_Active_Top ]
        List &setActiveTop();
        /// @brief [ @b MUIA_List_Active, @b MUIV_List_Active_Bottom ]
        List &setActiveBottom();
        /// @brief [ @b MUIA_List_Active, @b MUIV_List_Active_Up ]
        List &setActiveUp();
        /// @brief [ @b MUIA_List_Active, @b MUIV_List_Active_Down ]
        List &setActiveDown();
        /// @brief [ @b MUIA_List_Active, @b MUIV_List_Active_PageUp ]
        List &setActivePageUp();
        /// @brief [ @b MUIA_List_Active, @b MUIV_List_Active_PageDown ]
        List &setActivePageDown();
#ifdef MUIA_List_AutoVisible
        /// @brief [ @b MUIA_List_AutoVisible ]
        List &setAutoVisible(const bool autoVisible);
#endif
#if defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_AgainClick
        /// @brief [ @b MUIA_List_AgainClick ]
        List &setAgainClick(const bool againClick);
#endif
#endif
#ifdef MUIA_List_DefClickColumn
        /// @brief [ @b MUIA_List_DefClickColumn ]
        List &setDefClickColumn(const long defClickColumn);
#endif
#ifdef MUIA_List_CompareHook
        /// @brief [ @b MUIA_List_CompareHook ]
        List &setCompareHook(const struct Hook *compareHook);
#endif
#ifdef MUIA_List_ConstructHook
        /// @brief [ @b MUIA_List_ConstructHook ]
        List &setConstructHook(const struct Hook *constructHook);
#endif
#ifdef MUIA_List_DestructHook
        /// @brief [ @b MUIA_List_DestructHook ]
        List &setDestructHook(const struct Hook *destructHook);
#endif
#ifdef MUIA_List_DisplayHook
        /// @brief [ @b MUIA_List_DisplayHook ]
        List &setDisplayHook(const struct Hook *displayHook);
#endif
#ifdef MUIA_List_DragSortable
        /// @brief [ @b MUIA_List_DragSortable ]
        List &setDragSortable(const bool dragSortable);
#endif
#ifdef MUIA_List_DragType
        /// @brief [ @b MUIA_List_DragType ]
        List &setDragType(const enum List_DragType dragType);
#endif
#ifdef MUIA_List_Editable
        /// @brief [ @b MUIA_List_Editable ]
        List &setEditable(const bool editable);
#endif
#ifdef MUIA_List_HideColumn
        /// @brief [ @b MUIA_List_HideColumn ]
        List &setHideColumn(const long hideColumn);
#endif
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_List_First ]
        List &setFirst(const long first);
#endif
        /// @brief [ @b MUIA_List_Format ]
        List &setFormat(const char *format);
        /// @brief [ @b MUIA_List_Format ]
        List &setFormat(const std::string &format);
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_SortColumn
        /// @brief [ @b MUIA_List_SortColumn ]
        List &setSortColumn(const long sortColumn);
#endif
#endif
#ifdef MUIA_List_ShowColumn
        /// @brief [ @b MUIA_List_ShowColumn ]
        List &setShowColumn(const long showColumn);
#endif
#ifdef MUIA_List_MultiTestHook
        /// @brief [ @b MUIA_List_MultiTestHook ]
        List &setMultiTestHook(const struct Hook *multiTestHook);
#endif
#ifdef MUIA_List_ShowDropMarks
        /// @brief [ @b MUIA_List_ShowDropMarks ]
        List &setShowDropMarks(const bool showDropMarks);
#endif
#ifdef MUIA_List_ColumnOrder
        /// @brief [ @b MUIA_List_ColumnOrder ]
        /// Set column order from array. Array must contain unique column indices.
        List &setColumnOrder(const unsigned char *columnOrder);
#endif
#ifdef MUIA_List_TopPixel
#if defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_List_TopPixel ]
        List &setTopPixel(const long topPixel);
#endif
#endif
        /// @brief [ @b MUIA_List_Quiet ]
        List &setQuiet(const bool quiet);

#ifdef MUIA_List_Title
        /// @brief [ @b MUIA_List_Title ]
        List &setTitle(const char *title);
        /// @brief [ @b MUIA_List_Title ]
        List &setTitle(const std::string &title);
        /// @brief [ @b MUIA_List_Title ]
        List &setTitle(const bool title);
#endif
#ifdef MUIA_List_LineHeight
        /// @brief [ @b MUIA_List_LineHeight ]
        /// Set fixed line height in pixels.
        List &setLineHeight(const unsigned long lineHeight);
#endif
#ifdef MUIA_List_MinLineHeight
        /// @brief [ @b MUIA_List_MinLineHeight ]
        /// Set minimum line height in pixels.
        List &setMinLineHeight(const unsigned long minLineHeight);
#endif
#ifdef MUIA_List_Stripes
        /// @brief [ @b MUIA_List_Stripes ]
        List &setStripes(const bool stripes);
#endif
#if defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_ClickColumn
        /// @brief [ @b MUIA_List_ClickColumn ]
        List &setClickColumn(const long clickColumn);
#endif
#endif
#if defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_DoubleClick
        /// @brief [ @b MUIA_List_DoubleClick ]
        List &setDoubleClick(const bool doubleClick);
#endif
#endif
#if defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_TitleClick
        /// @brief [ @b MUIA_List_TitleClick ]
        List &setTitleClick(const long titleClick);
#endif
#endif

        // methods, some returns object reference

        /// @brief [ @b MUIM_List_Jump ]
        List &Jump(const enum List_Jump position);
        /// @brief [ @b MUIM_List_Jump ]
        List &Jump(const long position);

        /// @brief [ @b MUIM_List_GetEntry ]
        /// @param position index in list
        /// @return pointer to list entry (should be casted to proper one)
        void *GetEntry(const long position) const;
        /// @brief [ @b MUIM_List_GetEntry ]
        /// @param position index in list
        /// @return entry converted to string or empty string if entry is null
        std::string GetEntryAsString(const long position) const;

#ifdef MUIM_List_CreateImage
        /// @brief [ @b MUIM_List_CreateImage ]
        /// Register image object for usage in display output (\33O[%08lx]).
        /// @return Opaque list image handle, may be nullptr.
        void *CreateImage(Object *imageObject, const unsigned long flags = 0) const;
#endif

#ifdef MUIM_List_DeleteImage
        /// @brief [ @b MUIM_List_DeleteImage ]
        /// Unregister image handle previously returned by CreateImage().
        List &DeleteImage(const void *listImage) const;
#endif

        /// @brief [ @b MUIM_List_Remove ]
        /// @param position index in list
        List &Remove(const long position);

        /// @brief [ @b MUIM_List_NextSelected, @b MUIV_List_NextSelected_Start ]
        /// @return id of first selected (if any)
        long GetFirstSelected() const;

        /// @brief [ @b MUIM_List_NextSelected ]
        /// @param position index in list, by default it is start
        /// @return id of next selected
        long GetNextSelected(long position) const;

        /// @brief Return indexes/positions of all selected elements in list.
        /// @return vector with indexes/positions of all selected
        std::vector<long> GetAllSelected() const;

        // insert methods

        /// @brief [ @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Top ]
        List &InsertSingleTop(const void *entry);
        /// @brief [ @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Bottom ]
        List &InsertSingleBottom(const void *entry);
        /// @brief [ @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Sorted ]
        List &InsertSingleSorted(const void *entry);

        /// @brief [ @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Top ]
        List &InsertSingleTop(const std::string &entry);
        /// @brief [ @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Bottom ]
        List &InsertSingleBottom(const std::string &entry);
        /// @brief [ @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Sorted ]
        List &InsertSingleSorted(const std::string &entry);

        /// @brief [ @b MUIM_List_Insert, @b MUIV_List_Insert_Top ]
        List &InsertTop(const void *entries[]);
        /// @brief [ @b MUIM_List_Insert, @b MUIV_List_Insert_Bottom ]
        List &InsertBottom(const void *entries[]);
        /// @brief [ @b MUIM_List_Insert, @b MUIV_List_Insert_Sorted ]
        List &InsertSorted(const void *entries[]);

        /// @brief [ in loop @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Top ]
        List &InsertTop(const std::vector<const char *> &entries);
        /// @brief [ in loop @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Bottom ]
        List &InsertBottom(const std::vector<const char *> &entries);
        /// @brief [ in loop @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Sorted ]
        List &InsertSorted(const std::vector<const char *> &entries);

        /// @brief [ in loop @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Top ]
        List &InsertTop(const std::vector<std::string> &entries);
        /// @brief [ in loop @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Bottom ]
        List &InsertBottom(const std::vector<std::string> &entries);
        /// @brief [ in loop @b MUIM_List_InsertSingle, @b MUIV_List_Insert_Sorted ]
        List &InsertSorted(const std::vector<std::string> &entries);

        // redraw methods

        /// @brief [ @b MUIM_List_Clear ]
        List &Clear();
        /// @brief [ @b MUIM_List_Redraw ]
        List &Redraw(long pos) const;
        /// @brief [ @b MUIM_List_Redraw, @b MUIV_List_Redraw_Active ]
        List &RedrawActive() const;
#ifdef MUIV_List_Redraw_Entry
        /// @brief [ @b MUIM_List_Redraw, @b MUIV_List_Redraw_Entry ]
        List &RedrawEntry(const void *entry) const;
#endif
        /// @brief [ @b MUIM_List_Redraw, @b MUIV_List_Redraw_All ]
        List &RedrawAll() const;

        /// @brief [ @b MUIM_List_Exchange ]
        /// Exchange two entries by their positions.
        List &Exchange(const long pos1, const long pos2);

        /// @brief [ @b MUIM_List_Move ]
        /// Move one entry from source position to destination position.
        List &Move(const long from, const long to);

        /// @brief [ @b MUIM_List_Select ]
        /// Select/unselect entries.
        /// @param position list index or special values (e.g. @b MUIV_List_Select_Active, @b MUIV_List_Select_All)
        /// @param selectType one of @b MUIV_List_Select_Off, @b MUIV_List_Select_On, @b MUIV_List_Select_Toggle, @b MUIV_List_Select_Ask
        /// @param pState optional output pointer for current state
        List &Select(const long position, const long selectType, long *pState = nullptr);

        /// @brief [ @b MUIM_List_Sort ]
        /// Sort all entries using the currently configured compare hook/column.
        List &Sort();

        /// @brief [ @b MUIM_List_TestPos ]
        /// Query list entry information for given coordinates.
        /// @return true if entry information has been returned in @p pResult.
        bool TestPos(const long x, const long y, struct MUI_List_TestPos_Result *pResult) const;

#ifdef MUIM_List_QueryColumnWidth
        /// @brief [ @b MUIM_List_QueryColumnWidth ]
        /// Return pixel width of a column.
        long QueryColumnWidth(const long column) const;
#endif

#ifdef MUIM_List_SortEntries
        /// @brief [ @b MUIM_List_SortEntries ]
        /// Sort supplied entries using list sort rules.
        /// @return true if sorting succeeded.
        bool SortEntries(void *entries[]) const;
#endif

#ifdef MUIM_List_EndEdit
        /// @brief [ @b MUIM_List_EndEdit ]
        /// Finish inline editing with provided end-edit mode.
        /// @return true if end-edit succeeded.
        bool EndEdit(const unsigned long mode) const;
#endif

#ifdef MUIM_List_CreateEditObject
        /// @brief [ @b MUIM_List_CreateEditObject ]
        /// Create an inline editing object for a specific row and column.
        /// This method is meant to be overridden by List subclasses to provide custom
        /// editing objects for inline editing.
        Object *CreateEditObject(const long row, const long column, const void *entry) const;
#endif

#ifdef MUIM_List_Edit
        /// @brief [ @b MUIM_List_Edit ]
        /// Start inline editing for the specified row and column.
        bool Edit(const long row, const long column) const;
#endif

#ifdef MUIM_List_EditDone
        /// @brief [ @b MUIM_List_EditDone ]
        /// Finish inline editing and apply or discard changes.
        /// Called after user completes editing in the edit object.
        bool EditDone(const long row, const long column, const void *entry, Object *editobj) const;
#endif
    };

    template <typename T, typename U> class ListBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
#ifdef ListHookStringArrayModeAvailable
        bool isStringArray { false };
#endif

      public:
        ListBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_List)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        T &stringHooks();

#ifdef ListHookStringArrayModeAvailable
        /// @brief [ all hooks ( @b MUIA_List_ConstructHook, @b MUIA_List_DestructHook, @b MUIA_List_CompareHook, @b MUIA_List_DisplayHook )
        /// set to string array mode ]
        T &stringArrayHooks(unsigned long columns);
#endif

        /// @brief [ @b MUIA_List_Active ]
        T &tagActive(const enum List_Active active);
        /// @brief [ @b MUIA_List_Active ]
        T &tagActive(const long active);
        /// @brief [ @b MUIA_List_AdjustHeight ]
        T &tagAdjustHeight(const bool adjustHeight);
        /// @brief [ @b MUIA_List_AdjustWidth ]
        T &tagAdjustWidth(const bool adjustWidth);
#ifdef MUIA_List_AgainClick
        /// @brief [ @b MUIA_List_AgainClick ]
        T &tagAgainClick(const bool againClick);
#endif
#ifdef MUIA_List_DefClickColumn
        /// @brief [ @b MUIA_List_DefClickColumn ]
        T &tagDefClickColumn(const long defClickColumn);
#endif
#ifdef MUIA_List_DoubleClick
        /// @brief [ @b MUIA_List_DoubleClick ]
        T &tagDoubleClick(const bool doubleClick);
#endif
#ifdef MUIA_List_AutoLineHeight
        /// @brief [ @b MUIA_List_AutoLineHeight ]
        T &tagAutoLineHeight(const bool autoLineHeight);
#endif
#ifdef MUIA_List_MaxColumns
        /// @brief [ @b MUIA_List_MaxColumns ]
        T &tagMaxColumns(const long maxColumns);
#endif
#ifdef MUIA_List_MinLineHeight
        /// @brief [ @b MUIA_List_MinLineHeight ]
        T &tagMinLineHeight(const long minLineHeight);
#endif
        /// @brief [ @b MUIA_List_AutoVisible ]
        T &tagAutoVisible(const bool autoVisible);

        // hooks

        /// @brief [ @b MUIA_List_ConstructHook ]
        T &tagConstructHook(const struct Hook *constructHook);
        /// @brief [ @b MUIA_List_DestructHook ]
        T &tagDestructHook(const struct Hook *destructHook);
        /// @brief [ @b MUIA_List_CompareHook ]
        T &tagCompareHook(const struct Hook *compareHook);
        /// @brief [ @b MUIA_List_MultiTestHook ]
        T &tagMultiTestHook(const struct Hook *multiTestHook);
        /// @brief [ @b MUIA_List_DisplayHook, @b MUIV_List_DisplayHook_String ]
        T &tagDisplayHookString();

        // string hooks

        /// @brief [ @b MUIA_List_ConstructHook, @b MUIV_List_ConstructHook_String ]
        T &tagConstructHookString();
        /// @brief [ @b MUIA_List_DestructHook, @b MUIV_List_DestructHook_String ]
        T &tagDestructHookString();
        /// @brief [ @b MUIA_List_CompareHook, @b MUIV_List_CompareHook_String ]
        T &tagCompareHookString();
        /// @brief [ @b MUIA_List_DisplayHook ]
        T &tagDisplayHook(const struct Hook *displayHook);

        // string array hooks

#ifdef MUIV_List_ConstructHook_StringArray
        /// @brief [ @b MUIA_List_ConstructHook, @b MUIV_List_ConstructHook_StringArray ]
        T &tagConstructHookStringArray();
#endif
#ifdef MUIV_List_DestructHook_StringArray
        /// @brief [ @b MUIA_List_DestructHook, @b MUIV_List_DestructHook_StringArray ]
        T &tagDestructHookStringArray();
#endif
#ifdef MUIV_List_CompareHook_StringArray
        /// @brief [ @b MUIA_List_CompareHook, @b MUIV_List_CompareHook_StringArray ]
        T &tagCompareHookStringArray();
#endif
#ifdef MUIV_List_DisplayHook_StringArray
        /// @brief [ @b MUIA_List_DisplayHook, @b MUIV_List_DisplayHook_StringArray ]
        T &tagDisplayHookStringArray();
#endif

#ifdef MUIA_List_DragType
        /// @brief [ @b MUIA_List_DragType ]
        T &tagDragType(const enum List_DragType dragType);
#endif
        /// @brief [ @b MUIA_List_DragSortable ]
        T &tagDragSortable(const bool dragSortable);
        /// @brief [ @b MUIA_List_Format ]
        T &tagFormat(const char *format);
        /// @brief [ @b MUIA_List_Format ]
        T &tagFormat(const std::string &format);
#ifdef MUIA_List_HScrollerVisibility
        /// @brief [ @b MUIA_List_HScrollerVisibility set possibilities for the list's horizontal scroll bar:
        /// Please do NOT override the user's prefs unless you have a good reason!]
        T &tagHScrollerVisibility(const enum List_HScrollerVisibility hScrollerVisibility);
#endif
#ifdef MUIA_List_Input
        /// @brief [ @b MUIA_List_Input ]
        T &tagInput(const bool input);
#endif
#ifdef MUIA_List_Editable
        /// @brief [ @b MUIA_List_Editable ]
        T &tagEditable(const bool editable);
#endif
#ifdef MUIA_List_MultiSelect
        /// @brief [ @b MUIA_List_MultiSelect listviews multi select capabilities.
        /// Do NOT override the user's prefs unless you have a good reason!]
        T &tagMultiSelect(const enum List_MultiSelect multiSelect);
#endif
#ifdef MUIA_List_ScrollerPos
        /// @brief [ @b MUIA_List_ScrollerPos specifies the position of a listviews scrollbar.
        /// Don't use this tag unless it is absolutely required!]
        T &tagScrollerPos(const enum List_ScrollerPos scrollerPos);
#endif
#ifdef MUIA_List_SortColumn
        /// @brief [ @b MUIA_List_SortColumn ]
        T &tagSortColumn(const long sortColumn);
#endif
#ifdef MUIA_List_HideColumn
        /// @brief [ @b MUIA_List_HideColumn ]
        T &tagHideColumn(const long hideColumn);
#endif
#ifdef MUIA_List_ShowColumn
        /// @brief [ @b MUIA_List_ShowColumn ]
        T &tagShowColumn(const long showColumn);
#endif
#ifdef MUIA_List_ShowDropMarks
        /// @brief [ @b MUIA_List_ShowDropMarks ]
        T &tagShowDropMarks(const bool showDropMarks);
#endif
#ifdef MUIA_List_Pool
        /// @brief [ @b MUIA_List_Pool ]
        T &tagPool(const void *pool);
#endif
#ifdef MUIA_List_PoolPuddleSize
        /// @brief [ @b MUIA_List_PoolPuddleSize ]
        T &tagPoolPuddleSize(const unsigned long poolPuddleSize);
#endif
#ifdef MUIA_List_PoolThreshSize
        /// @brief [ @b MUIA_List_PoolThreshSize ]
        T &tagPoolThreshSize(const unsigned long poolThreshSize);
#endif
        /// @brief [ @b MUIA_List_SourceArray ]
        T &tagSourceArray(const void *sourceArray[]);
        /// @brief [ @b MUIA_List_SourceArray ]
        T &tagSourceArray(const char *sourceArray[]);
        /// @brief [ @b MUIA_List_SourceArray ]
        T &tagSourceArray(const std::vector<std::string> &sourceArray);
        /// @brief [ @b MUIA_List_Title pass true when custom display hook ]
        T &tagTitle(const bool title = true);
        /// @brief [ @b MUIA_List_Title ]
        T &tagTitle(const std::string &title);
#ifdef MUIA_List_Stripes
        /// @brief [ @b MUIA_List_Stripes ]
        T &tagStripes(const bool stripes);
#endif
#ifdef MUIA_List_TitleArray
        /// @brief [ @b MUIA_List_TitleArray ]
        T &tagTitleArray(const char *titleArray[]);
        /// @brief [ @b MUIA_List_TitleArray ]
        T &tagTitleArray(const std::vector<std::string> &titleArray);
#endif

#ifdef ListHookStringArrayModeAvailable
      protected:
        bool Validate() const override;
#endif
    };

    class ListBuilder : public ListBuilderTemplate<ListBuilder, List>
    {
      public:
        ListBuilder();
    };
}

#define MUI_LIST_TPP_INCLUDE
#include "List.tpp"
#undef MUI_LIST_TPP_INCLUDE
