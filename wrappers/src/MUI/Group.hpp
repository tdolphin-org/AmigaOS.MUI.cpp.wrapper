//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
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
        explicit Group(Object *pMuiObject)
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

        // methods, some returns object reference

#ifdef MUIM_Group_AddHead
        /// @brief [ @b MUIM_Group_AddHead ]
        Group &AddHead(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_AddHead ]
        Group &AddHead(const Root &child);
#endif
#ifdef MUIM_Group_AddTail
        /// @brief [ @b MUIM_Group_AddTail ]
        Group &AddTail(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_AddTail ]
        Group &AddTail(const Root &child);
#endif
        /// @brief [ @b MUIM_Group_ExitChange ]
        Group &ExitChange();
#ifdef MUIM_Group_ExitChange2
        /// @brief [ @b MUIM_Group_ExitChange2 ]
        Group &ExitChange2();
#endif
        /// @brief [ @b MUIM_Group_InitChange ]
        Group &InitChange();
#ifdef MUIM_Group_Remove
        /// @brief [ @b MUIM_Group_Remove ]
        Group &Remove(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_Remove ]
        Group &Remove(const Root &child);
#endif

        /// @brief [ @b OM_ADDMEMBER ]
        Group &AddMember(const Object *pChildObject);
        /// @brief [ @b OM_ADDMEMBER ]
        Group &AddMember(const Root &child);
        /// @brief [ @b OM_REMMEMBER ]
        // After disconnecting an object from Group we must call explicitly DiposeObject() on the disconnected child
        // object, otherwise the memory will not be released
        Group &RemMember(const Object *pChildObject);
        /// @brief [ @b OM_REMMEMBER ]
        // After disconnecting an object from Group we must call explicitly DiposeObject() on the disconnected child
        // object, otherwise the memory will not be released
        Group &RemMember(const Root &child);
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

        /// @brief [ @b MUIA_Group_ActivePage ]
        T &tagActivePage(const unsigned long activePage);
        /// @brief [ @b MUIA_Group_ActivePage ]
        T &tagActivePage(const enum Group_ActivePage activePage);
        /// @brief [ @b MUIM_Group_Child ]
        T &tagChild(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_Child ]
        T &tagChild(const Root &child);
        /// @brief [ @b MUIM_Group_Columns ]
        /// Number of columns in a two dimensional group.
        T &tagColumns(const long columns);
        /// @brief [ @b MUIA_Group_Horiz ]
        /// Indicate whether the objects in this group shall be layouted horizontally or vertically.
        /// By default is false.
        T &tagHoriz(const bool horiz);
#ifdef MUIA_Group_HorizCenter
        /// @brief [ @b MUIA_Group_HorizCenter ]
        T &tagHorizCenter(const enum Group_HorizCenter horizCenter);
#endif
        /// @brief [ @b MUIA_Group_HorizSpacing ]
        T &tagHorizSpacing(const long horizSpacing);
        /// @brief [ @b MUIA_Group_PageMode ]
        /// This attribute makes the current group a page group. Page groups always display only one of their children.
        /// Which one can be adjusted with the MUIA_Group_ActivePage attribute.
        T &tagPageMode(const bool pageMode = true);
        /// @brief [ @b MUIA_Group_Rows ]
        T &tagRows(const long rows);
        /// @brief [ @b MUIA_Group_SameHeight ]
        T &tagSameHeight(const bool sameHeight);
        /// @brief [ @b MUIA_Group_SameSize ]
        T &tagSameSize(const bool sameSize);
        /// @brief [ @b MUIA_Group_SameWidth ]
        T &tagSameWidth(const bool sameWidth);
        /// @brief [ @b MUIA_Group_Spacing ]
        T &tagSpacing(const long spacing);
#ifdef MUIA_Group_VertCenter
        /// @brief [ @b MUIA_Group_VertCenter ]
        T &tagVertCenter(const enum Group_VertCenter vertCenter);
#endif
        /// @brief [ @b MUIA_Group_VertSpacing ]
        T &tagVertSpacing(const long vertSpacing);

        /// @brief replaces mui macro GroupFrameT
        T &groupFrame(const std::string &title);
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

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagActivePage(const unsigned long activePage)
    {
        this->PushTag(MUIA_Group_ActivePage, activePage);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagActivePage(const enum Group_ActivePage activePage)
    {
        this->PushTag(MUIA_Group_ActivePage, (long)activePage);
        return (T &)*this;
    }

    template <typename T, typename U> T &GroupBuilderTemplate<T, U>::tagChild(const Object *pChildObject)
    {
        if (pChildObject)
            this->PushTag(MUIA_Group_Child, pChildObject, false, true);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagChild(const Root &child)
    {
        if (child.muiObject())
            this->PushTag(MUIA_Group_Child, child.muiObject(), false, true);
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

#ifdef MUIA_Group_HorizCenter
    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagHorizCenter(const enum Group_HorizCenter horizCenter)
    {
        this->PushTag(MUIA_Group_HorizCenter, (long)horizCenter);
        return (T &)*this;
    }
#endif

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

#ifdef MUIA_Group_VertCenter
    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagVertCenter(const enum Group_VertCenter vertCenter)
    {
        this->PushTag(MUIA_Group_VertCenter, (long)vertCenter);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::tagVertSpacing(const long vertSpacing)
    {
        this->PushTag(MUIA_Group_VertSpacing, vertSpacing);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GroupBuilderTemplate<T, U>::groupFrame(const std::string &title)
    {
        this->PushTag(MUIA_Frame, (long)MUI::Frame::Group);
        if (!title.empty())
        {
            auto copy = this->StoreString(MUIA_FrameTitle, title);
            this->PushTag(MUIA_FrameTitle, copy);
        }
        this->PushTag(MUIA_Background, (long)MUI::ImageOrBackground::GroupBack);
        return (T &)*this;
    }
}
