//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2025 TDolphin
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

#include <stdexcept>

#undef Remove

#ifdef MUIV_List_ConstructHook_StringArray
#define ListHookStringArrayModeAvailable
#endif

namespace MUI
{
    class List : public Area
    {
      public:
        explicit List(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
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
        /// @brief [ @b MUIA_List_Quiet ]
        bool isQuiet() const;
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
        /// @brief [ @b MUIA_List_Format ]
        List &setFormat(const char *format);
        /// @brief [ @b MUIA_List_Format ]
        List &setFormat(const std::string &format);
#ifdef MUIA_List_SortColumn
        /// @brief [ @b MUIA_List_SortColumn ]
        List &setSortColumn(const long sortColumn);
#endif
#ifdef MUIA_List_TopPixel
        /// @brief [ @b MUIA_List_TopPixel ]
        List &setTopPixel(const long topPixel);
#endif
        /// @brief [ @b MUIA_List_Quiet ]
        List &setQuiet(const bool quiet);

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
        /// @return pointer to string
        std::string GetEntryAsString(const long position) const;

        /// @brief [ @b MUIM_List_Remove ]
        /// @param position index in list
        List &Remove(const long position);

        /// @brief [ @b MUIM_List_NextSelected, @b MUIV_List_NextSelected_Start ]
        /// @return id of first selected (if any)
        long GetFirstSelected() const;

        /// @brief [ @b MUIM_List_NextSelected ]
        /// @param position index in list, by default it is start
        /// @return id of next selected
        long GetNextSelected(const long position) const;

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
#ifdef MUIA_List_AutoLineHeight
        /// @brief [ @b MUIA_List_AutoLineHeight ]
        T &tagAutoLineHeight(const bool autoLineHeight);
#endif
#ifdef MUIA_List_MaxColumns
        /// @brief [ @b MUIA_List_MaxColumns ]
        T &tagMaxColumns(const long maxColumns);
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
        /// @brief [ @b MUIA_List_SourceArray ]
        T &tagSourceArray(const void *sourceArray[]);
        /// @brief [ @b MUIA_List_SourceArray ]
        T &tagSourceArray(const char *sourceArray[]);
        /// @brief [ @b MUIA_List_Title pass true when custom display hook ]
        T &tagTitle(const bool title = true);
        /// @brief [ @b MUIA_List_Title ]
        T &tagTitle(const std::string &title);
#ifdef MUIA_List_TitleArray
        /// @brief [ @b MUIA_List_TitleArray ]
        T &tagTitleArray(const char *titleArray[]);
#endif

#ifdef MUIA_List_MaxColumns
      private:
        void validateObject() const;

      public:
        U object() const;
        U object(const unsigned long dataSize, const void *pDispatcher) const;
#endif
    };

    class ListBuilder : public ListBuilderTemplate<ListBuilder, List>
    {
      public:
        ListBuilder();
    };

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
    template <typename T, typename U> inline void ListBuilderTemplate<T, U>::validateObject() const
    {
        if (isStringArray)
        {
            if (!this->ContainsTag(MUIA_List_MaxColumns))
            {
                auto error = std::string { __PRETTY_FUNCTION__ } + ", missing MaxColumns for List with StringArray hooks!";
                throw std::runtime_error(error);
            }
        }
    }

    template <typename T, typename U> inline U ListBuilderTemplate<T, U>::object() const
    {
        validateObject();
        return AreaBuilderTemplate<T, U>::object();
    }

    template <typename T, typename U>
    inline U ListBuilderTemplate<T, U>::object(const unsigned long dataSize, const void *pDispatcher) const
    {
        validateObject();
        return AreaBuilderTemplate<T, U>::object(dataSize, pDispatcher);
    }
#endif
}
