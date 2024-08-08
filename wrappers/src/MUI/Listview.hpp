//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Group.hpp"

#include "List.hpp"
#include "ValueTypes/Listview/DragType.hpp"
#include "ValueTypes/Listview/MultiSelect.hpp"
#include "ValueTypes/Listview/ScrollerPos.hpp"

#include <stdexcept>

namespace MUI
{
    class Listview : public Group
    {
      public:
        Listview(const Object *pMuiObject)
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

        /// @brief [ @b MUIA_Listview_AgainClick ]
        bool isAgainClick() const;
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
        bool hasListObject;

      public:
        ListviewBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Listview)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
          , hasListObject(false)
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
        T &tagList(const MUI::List &list);
        /// @brief [ @b MUIA_Listview_List ]
        T &tagList(const Object *pList);
        /// @brief [ @b MUIA_Listview_MultiSelect ]
        T &tagMultiSelect(const enum Listview_MultiSelect multiSelect);
        /// @brief [ @b MUIA_Listview_ScrollerPos ]
        T &tagScrollerPos(const enum Listview_ScrollerPos scrollerPos);

        U object() const;
        U object(const unsigned long dataSize, const void *pDispatcher) const;
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

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagList(const MUI::List &list)
    {
        hasListObject = true;
        this->PushTag(MUIA_Listview_List, list.muiObject());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagList(const Object *pList)
    {
        hasListObject = pList != nullptr;
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

    template <typename T, typename U> inline U ListviewBuilderTemplate<T, U>::object() const
    {
        // Each listview needs a list object as child. The list object is mandatory for listview, without it object will fail on creation.
        // So check if there is tag for List (not null).
        if (!hasListObject)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + ", missing List object for Listview!";
            throw std::runtime_error(error);
        }

        return GroupBuilderTemplate<T, U>::object();
    }

    template <typename T, typename U>
    inline U ListviewBuilderTemplate<T, U>::object(const unsigned long dataSize, const void *pDispatcher) const
    {
        // Each listview needs a list object as child. The list object is mandatory for listview, without it object will fail on creation.
        // So check if there is tag for List (not null).
        if (!hasListObject)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + ", missing List object for Listview!";
            throw std::runtime_error(error);
        }

        return GroupBuilderTemplate<T, U>::object(dataSize, pDispatcher);
    }
}
