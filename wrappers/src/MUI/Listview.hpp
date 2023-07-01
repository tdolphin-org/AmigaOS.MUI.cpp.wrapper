//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Group.hpp"

#include "ValueTypes/Listview/DragType.hpp"
#include "ValueTypes/Listview/MultiSelect.hpp"
#include "ValueTypes/Listview/ScrollerPos.hpp"

namespace MUI
{
    class Listview : public Group
    {
      public:
        Listview(const Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Listview(const APTR pMuiObject)
          : Group(pMuiObject)
        {
        }

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, MUIC_Listview);
        }

        // is/get/set (attributes), all setters return object reference
    };

    template <typename T, typename U> class ListviewBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        ListviewBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Listview)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Listview_AgainClick ]
        T &tagAgainClick(const bool againClick);
        /// @brief [ @b MUIA_Listview_DefClickColumn ]
        T &tagDefClickColumn(const long defClickColumn);
        /// @brief [ @b MUIA_Listview_DoubleClick ]
        T &tagDoubleClick(const bool doubleClick);
        /// @brief [ @b MUIA_Listview_DragType ]
        T &tagDragType(const enum Listview_DragType dragType);
        /// @brief [ @b MUIA_Listview_Input ]
        T &tagInput(const bool input);
        /// @brief [ @b MUIA_Listview_List ]
        T &tagList(const Object *pList);
        /// @brief [ @b MUIA_Listview_MultiSelect ]
        T &tagMultiSelect(const enum Listview_MultiSelect multiSelect);
        /// @brief [ @b MUIA_Listview_ScrollerPos ]
        T &tagScrollerPos(const enum Listview_ScrollerPos scrollerPos);
    };

    class ListviewBuilder : public ListviewBuilderTemplate<ListviewBuilder, Listview>
    {
      public:
        ListviewBuilder();
    };

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagAgainClick(const bool againClick)
    {
        this->PushTag(MUIA_Listview_AgainClick, againClick);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagDefClickColumn(const long defClickColumn)
    {
        this->PushTag(MUIA_Listview_DefClickColumn, defClickColumn);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagDoubleClick(const bool doubleClick)
    {
        this->PushTag(MUIA_Listview_DoubleClick, doubleClick);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagDragType(const enum Listview_DragType dragType)
    {
        this->PushTag(MUIA_Listview_DragType, (long)dragType);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagInput(const bool input)
    {
        this->PushTag(MUIA_Listview_Input, input);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagList(const Object *pList)
    {
        this->PushTag(MUIA_Listview_List, pList);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagMultiSelect(const enum Listview_MultiSelect multiSelect)
    {
        this->PushTag(MUIA_Listview_MultiSelect, (long)multiSelect);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagScrollerPos(const enum Listview_ScrollerPos scrollerPos)
    {
        this->PushTag(MUIA_Listview_ScrollerPos, (long)scrollerPos);
        return (T &)*this;
    }
}
