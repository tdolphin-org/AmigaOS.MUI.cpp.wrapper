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
    class Listview : public Group
    {
      public:
        explicit Listview(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

#ifdef MUIA_Listview_AgainClick
        /// @brief [ @b MUIA_Listview_AgainClick ]
        bool isAgainClick() const;
#endif
        /// @brief [ @b MUIA_Listview_ClickColumn ]
        long getClickColumn() const;
        /// @brief [ @b MUIA_Listview_DefClickColumn ]
        long getDefClickColumn() const;
        /// @brief [ @b MUIA_Listview_DoubleClick ]
        bool isDoubleClick() const;
        /// @brief [ @b MUIA_Listview_DragType ]
        enum Listview_DragType getDragType() const;
        /// @brief [ @b MUIA_Listview_List ]
        /// @return MUI::List object
        List getList() const;
        /// @brief [ @b MUIA_Listview_SelectChange ]
        bool isSelectChange() const;

        /// @brief [ @b MUIA_Listview_DefClickColumn ]
        Listview &setDefClickColumn(const long defClickColumn);
        /// @brief [ @b MUIA_Listview_DragType ]
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
        T &tagAgainClick(const bool againClick);
#endif
        /// @brief [ @b MUIA_Listview_DefClickColumn ]
        T &tagDefClickColumn(const long defClickColumn);
        /// @brief [ @b MUIA_Listview_DoubleClick ]
        T &tagDoubleClick(const bool doubleClick);
        /// @brief [ @b MUIA_Listview_DragType ]
        T &tagDragType(const enum Listview_DragType dragType);
        /// @brief [ @b MUIA_Listview_Input ]
        T &tagInput(const bool input);
        /// @brief [ @b MUIA_Listview_List ]
        T &tagList(const MUI::List &list);
        /// @brief [ @b MUIA_Listview_List ]
        T &tagList(const Object *pList);
        /// @brief [ @b MUIA_Listview_MultiSelect ]
        T &tagMultiSelect(const enum Listview_MultiSelect multiSelect);
        /// @brief [ @b MUIA_Listview_ScrollerPos ]
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
