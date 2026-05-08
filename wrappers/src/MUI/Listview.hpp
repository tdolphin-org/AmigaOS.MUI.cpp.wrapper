//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

#include "List.hpp"
#include "ValueTypes/Listview/DragType.hpp"
#include "ValueTypes/Listview/MultiSelect.hpp"
#include "ValueTypes/Listview/ScrollerPos.hpp"

namespace MUI
{
    /// @brief Wrapper for list view handling around a list object.
    ///
    /// Listview attaches a scrollbar and input handling to a list object.
    class Listview : public Group
    {
      public:
        explicit Listview(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Listview(const Root &root)
          : Group(root.muiObject())
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

#ifdef MUIA_Listview_AgainClick
        /// @brief [ @b MUIA_Listview_AgainClick ]
        /// This attribute is set to true whenever the user clicks on the same entry again,
        /// but not necessarily within the system double click time.
        bool isAgainClick() const;
#endif
        /// @brief [ @b MUIA_Listview_ClickColumn ]
        /// For multi column lists, this returns the clicked column number.
        long getClickColumn() const;
        /// @brief [ @b MUIA_Listview_DefClickColumn ]
        /// Defines/returns default click column used when RETURN is pressed on keyboard control.
        long getDefClickColumn() const;
        /// @brief [ @b MUIA_Listview_DoubleClick ]
        /// This attribute is set to true whenever the user double clicks an entry.
        bool isDoubleClick() const;
        /// @brief [ @b MUIA_Listview_DragType ]
        /// Returns the configured drag type for dragging items out of the listview.
        enum Listview_DragType getDragType() const;
        /// @brief [ @b MUIA_Listview_List ]
        /// Returns the underlying list object pointer used as child.
        Object *getListObject() const;
        /// @brief [ @b MUIA_Listview_List ]
        /// Returns the underlying list object as wrapper.
        List getList() const;
        /// @brief [ @b MUIA_Listview_SelectChange ]
        /// This attribute is set to true whenever selection state of one or more items changes.
        bool isSelectChange() const;

        /// @brief [ @b MUIA_Listview_DefClickColumn ]
        /// Sets default click column used when RETURN is pressed on keyboard control.
        Listview &setDefClickColumn(const long defClickColumn);
        /// @brief [ @b MUIA_Listview_DragType ]
        /// Configures whether dragging items out of the listview is enabled and how it behaves.
        Listview &setDragType(const Listview_DragType dragType);
    };

    template <typename T, typename U> class ListviewBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
        bool hasListObject { false };

      public:
        ListviewBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Listview)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Listview_AgainClick
        /// @brief [ @b MUIA_Listview_AgainClick ]
        /// Enables reporting clicks on the same entry again.
        T &tagAgainClick(const bool againClick);
#endif
        /// @brief [ @b MUIA_Listview_DefClickColumn ]
        /// Sets default click column used when RETURN is pressed on keyboard control.
        T &tagDefClickColumn(const long defClickColumn);
        /// @brief [ @b MUIA_Listview_DoubleClick ]
        /// Enables reporting double click events on entries.
        T &tagDoubleClick(const bool doubleClick);
        /// @brief [ @b MUIA_Listview_DragType ]
        /// Configures whether dragging items out of the listview is enabled.
        T &tagDragType(const enum Listview_DragType dragType);
        /// @brief [ @b MUIA_Listview_Input ]
        /// Setting this to false makes the listview read-only.
        T &tagInput(const bool input);
        /// @brief [ @b MUIA_Listview_List ]
        /// Assign list child as wrapper object.
        T &tagList(const MUI::List &list);
        /// @brief [ @b MUIA_Listview_List ]
        /// Assign list child as raw object pointer.
        T &tagList(const Object *pList);
        /// @brief [ @b MUIA_Listview_MultiSelect ]
        /// Configures multi selection behavior.
        T &tagMultiSelect(const enum Listview_MultiSelect multiSelect);
        /// @brief [ @b MUIA_Listview_ScrollerPos ]
        /// Configures scrollbar placement for the listview.
        T &tagScrollerPos(const enum Listview_ScrollerPos scrollerPos);

      protected:
        bool Validate() const override;
    };

    class ListviewBuilder : public ListviewBuilderTemplate<ListviewBuilder, Listview>
    {
      public:
        ListviewBuilder();
    };
}

#define MUI_LISTVIEW_TPP_INCLUDE
#include "Listview.tpp"
#undef MUI_LISTVIEW_TPP_INCLUDE
