//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Area.hpp"

#include "ValueTypes/Group/ActivePage.hpp"
#include "ValueTypes/Group/HorizCenter.hpp"
#include "ValueTypes/Group/VertCenter.hpp"

#undef AddHead
#undef AddTail
#undef Remove

namespace MUI
{
    class Group : public Area
    {
      public:
        Group(const Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Group(const APTR pMuiObject)
          : Area(pMuiObject)
        {
        }

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, MUIC_Group);
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Group_ActivePage ]
        /// @return active page (index).
        long getActivePage() const;

        /// @brief [ @b MUIA_Group_ActivePage ]
        /// Activate given page.
        /// @param activePage index of page to activate (unsigned long to prevent pass #define < 0)
        Group &setActivePage(const unsigned long activePage);
        /// @brief [ @b MUIA_Group_ActivePage ]
        /// Activate given page by enum Group_ActivePage.
        Group &setActivePage(const enum Group_ActivePage activePage);
        /// @brief [ @b MUIA_Group_ActivePage, @b MUIV_Group_ActivePage_First ]
        /// Activate first page.
        Group &setActivePageFirst();
        /// @brief [ @b MUIA_Group_ActivePage, @b MUIV_Group_ActivePage_Last ]
        /// Activate last page.
        Group &setActivePageLast();
        /// @brief [ @b MUIA_Group_ActivePage, @b MUIV_Group_ActivePage_Advance ]
        /// Activate next page after current.
        Group &setActivePageAdvance();
        /// @brief [ @b MUIA_Group_Columns ]
        /// Set number of columns in a two dimensional group.
        Group &setColumns(const long columns);

        // methods, some can return object reference

        /// @brief [ @b MUIM_Group_AddHead ]
        Group &AddHead(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_AddTail ]
        Group &AddTail(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_ExitChange ]
        Group &ExitChange();
        /// @brief [ @b MUIM_Group_ExitChange2 ]
        Group &ExitChange2();
        /// @brief [ @b MUIM_Group_InitChange ]
        Group &InitChange();
        /// @brief [ @b MUIM_Group_Remove ]
        Group &Remove(const Object *pChildObject);
    };

    template <typename T, typename U> class GroupBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        GroupBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Group)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Group_Horiz, FALSE ] - like macro: @b VGroup
        T &vertical();
        /// @brief [ @b MUIA_Group_Horiz, TRUE ] - like macro: @b HGroup
        T &horizontal();

        /// @brief [ @b MUIM_Group_Child ]
        T &tagChild(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_Child ]
        T &tagChild(const APTR pChildObject);
        /// @brief [ @b MUIM_Group_Child ]
        T &tagChild(const Root &child);
        /// @brief [ @b MUIM_Group_Columns ]
        /// Number of columns in a two dimensional group.
        T &tagColumns(const long columns);
        /// @brief [ @b MUIA_Group_Horiz ]
        /// Indicate whether the objects in this group shall be layouted horizontally or vertically. Defaults to FALSE.
        T &tagHoriz(const bool horiz);
        /// @brief [ @b MUIA_Group_HorizCenter ]
        T &tagHorizCenter(const enum Group_HorizCenter horizCenter);
        /// @brief [ @b MUIA_Group_HorizSpacing ]
        T &tagHorizSpacing(const long horizSpacing);
        /// @brief [ @b MUIA_Group_PageMode ]
        T &tagPageMode(const bool pageMode);
        /// @brief [ @b MUIM_Group_Rows ]
        T &tagRows(const long rows);
        /// @brief [ @b MUIM_Group_SameHeight ]
        T &tagSameHeight(const bool sameHeight);
        /// @brief [ @b MUIM_Group_SameSize ]
        T &tagSameSize(const bool sameSize);
        /// @brief [ @b MUIM_Group_SameWidth ]
        T &tagSameWidth(const bool sameWidth);
        /// @brief [ @b MUIM_Group_Spacing ]
        T &tagSpacing(const long spacing);
        /// @brief [ @b MUIA_Group_VertCenter ]
        T &tagVertCenter(const enum Group_VertCenter vertCenter);
        /// @brief [ @b MUIA_Group_VertSpacing ]
        T &tagVertSpacing(const long vertSpacing);
    };

    class GroupBuilder : public GroupBuilderTemplate<GroupBuilder, Group>
    {
      public:
        GroupBuilder();
    };

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::vertical()
    {
        this->PushTag(MUIA_Group_Horiz, false);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::horizontal()
    {
        this->PushTag(MUIA_Group_Horiz, true);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagChild(const Object *pChildObject)
    {
        if (pChildObject)
            this->PushTag(MUIA_Group_Child, pChildObject);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagChild(const APTR pChildObject)
    {
        if (pChildObject)
            this->PushTag(MUIA_Group_Child, (const Object *)pChildObject);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagChild(const Root &child)
    {
        this->PushTag(MUIA_Group_Child, child.muiObject());
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagColumns(const long columns)
    {
        this->PushTag(MUIA_Group_Columns, columns);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagHoriz(const bool horiz)
    {
        this->PushTag(MUIA_Group_Horiz, horiz);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagHorizCenter(const enum Group_HorizCenter horizCenter)
    {
        this->PushTag(MUIA_Group_HorizCenter, (long)horizCenter);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagHorizSpacing(const long horizSpacing)
    {
        this->PushTag(MUIA_Group_HorizSpacing, horizSpacing);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagPageMode(const bool pageMode)
    {
        this->PushTag(MUIA_Group_PageMode, pageMode);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagRows(const long rows)
    {
        this->PushTag(MUIA_Group_Rows, rows);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagSameHeight(const bool sameHeight)
    {
        this->PushTag(MUIA_Group_SameHeight, sameHeight);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagSameSize(const bool sameSize)
    {
        this->PushTag(MUIA_Group_SameSize, sameSize);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagSameWidth(const bool sameWidth)
    {
        this->PushTag(MUIA_Group_SameWidth, sameWidth);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagSpacing(const long spacing)
    {
        this->PushTag(MUIA_Group_Spacing, spacing);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagVertCenter(const enum Group_VertCenter vertCenter)
    {
        this->PushTag(MUIA_Group_VertCenter, (long)vertCenter);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagVertSpacing(const long vertSpacing)
    {
        this->PushTag(MUIA_Group_VertSpacing, vertSpacing);
        return (T &)*this;
    }
}
