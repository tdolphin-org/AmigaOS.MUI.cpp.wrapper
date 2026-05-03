//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
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
    /// @brief Group class manages layout and child objects inside MUI windows.
    class Group : public Area
    {
      public:
        explicit Group(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Group(const Root &root)
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

        /// @brief [ @b MUIA_Group_ActivePage ]
        /// @return active page (index).
        long getActivePage() const;
#ifdef MUIA_Group_ChildCount
        /// @brief [ @b MUIA_Group_ChildCount ] Read number of child objects in this group.
        long getChildCount() const;
#endif
        /// @brief [ @b MUIA_Group_ChildList ]
        /// @return list of child objects.
        const struct List *getChildList() const;
#ifdef MUIA_Group_HorizCenter
        /// @brief [ @b MUIA_Group_HorizCenter ]
        /// @return horizontal center alignment.
        enum Group_HorizCenter getHorizCenter() const;
#endif
        /// @brief [ @b MUIA_Group_HorizSpacing ]
        /// @return Number of pixels inserted between horizontal elements of a group.
        long getHorizSpacing() const;
#ifdef MUIA_Group_VertCenter
        /// @brief [ @b MUIA_Group_VertCenter ]
        /// @return vertical center alignment.
        enum Group_VertCenter getVertCenter() const;
#endif
        /// @brief [ @b MUIA_Group_VertSpacing ]
        /// @return Number of pixels inserted between vertical elements of a group.
        long getVertSpacing() const;

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
#ifdef MUIA_Group_Forward
        /// @brief [ @b MUIA_Group_Forward ]
        /// Enable/disable forward keyboard focus traversal.
        Group &setForward(const bool forward);
#endif
#ifdef MUIA_Group_ForwardDepth
        /// @brief [ @b MUIA_Group_ForwardDepth ]
        /// Set depth used for forward focus handling.
        Group &setForwardDepth(const unsigned long forwardDepth);
#endif
#ifdef MUIA_Group_HorizCenter
        /// @brief [ @b MUIA_Group_HorizCenter ]
        /// Set horizontal center alignment.
        Group &setHorizCenter(const enum Group_HorizCenter horizCenter);
#endif
        /// @brief [ @b MUIA_Group_HorizSpacing ]
        /// Set number of pixels inserted between horizontal elements.
        Group &setHorizSpacing(const long horizSpacing);
#ifdef MUIA_Group_Rows
        /// @brief [ @b MUIA_Group_Rows ]
        /// Set number of rows in a two dimensional group.
        Group &setRows(const long rows);
#endif
#ifdef MUIA_Group_Spacing
        /// @brief [ @b MUIA_Group_Spacing ]
        /// Set spacing used between children.
        Group &setSpacing(const long spacing);
#endif
#ifdef MUIA_Group_VertCenter
        /// @brief [ @b MUIA_Group_VertCenter ]
        /// Set vertical center alignment.
        Group &setVertCenter(const enum Group_VertCenter vertCenter);
#endif
        /// @brief [ @b MUIA_Group_VertSpacing ]
        /// Set number of pixels inserted between vertical elements.
        Group &setVertSpacing(const long vertSpacing);

        // methods, some returns object reference

#ifdef MUIM_Group_AddHead
        /// @brief [ @b MUIM_Group_AddHead ] Add child object at the beginning of the group child list.
        /// @param pChildObject child object to insert, ignored when nullptr
        Group &AddHead(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_AddHead ] Add child object at the beginning of the group child list.
        /// @param child child wrapper to insert, ignored when it wraps a null object
        Group &AddHead(const Root &child);
#endif
#ifdef MUIM_Group_AddTail
        /// @brief [ @b MUIM_Group_AddTail ] Add child object at the end of the group child list.
        /// @param pChildObject child object to insert, ignored when nullptr
        Group &AddTail(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_AddTail ] Add child object at the end of the group child list.
        /// @param child child wrapper to insert, ignored when it wraps a null object
        Group &AddTail(const Root &child);
#endif
        /// @brief [ @b MUIM_Group_ExitChange ] Leave dynamic child-list modification mode and trigger relayout.
        Group &ExitChange();
#ifdef MUIM_Group_ExitChange2
        /// @brief [ @b MUIM_Group_ExitChange2 ] Leave dynamic child-list modification mode with flags.
        /// @param flags set to 0 to suppress automatic relayout
        Group &ExitChange2(const unsigned long flags = 0);
#endif
        /// @brief [ @b MUIM_Group_InitChange ] Enter dynamic child-list modification mode.
        Group &InitChange();
#ifdef MUIM_Group_MoveMember
        /// @brief [ @b MUIM_Group_MoveMember ] Move existing child to a new position in the group.
        /// @param pChildObject child object to move
        /// @param pos target position (0 first, -1 last, other values per MUIM_Group_MoveMember rules)
        Group &MoveMember(const Object *pChildObject, const long pos);
        /// @brief [ @b MUIM_Group_MoveMember ] Move existing child to a new position in the group.
        /// @param child child wrapper to move
        /// @param pos target position (0 first, -1 last, other values per MUIM_Group_MoveMember rules)
        Group &MoveMember(const Root &child, const long pos);
#endif
#ifdef MUIM_Group_Remove
        /// @brief [ @b MUIM_Group_Remove ] Remove child object from the group child list.
        /// @param pChildObject child object to remove, ignored when nullptr
        Group &Remove(const Object *pChildObject);
        /// @brief [ @b MUIM_Group_Remove ] Remove child object from the group child list.
        /// @param child child wrapper to remove, ignored when it wraps a null object
        Group &Remove(const Root &child);
#endif

#ifdef MUIM_Group_Reorder
        /// @brief [ @b MUIM_Group_Reorder ]
        /// Reorder the children of a group.
        /// @param after anchor object; nullptr moves objects to front, (Object *)-1 moves to back
        /// @param objects null-terminated order source converted internally from vector
        Group &Reorder(const Object *after, const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Group_Reorder ]
        /// Reorder the children of a group.
        /// @param after anchor object; nullptr moves objects to front, (Object *)-1 moves to back
        /// @param objects objects to reorder
        Group &Reorder(const Object *after, const std::initializer_list<const Object *> &objects);
        /// @brief [ @b MUIM_Group_Reorder, after = 0 ]
        /// Reorder the given children to the front of the group child list.
        Group &ReorderFront(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Group_Reorder, after = 0 ]
        /// Reorder the given children to the front of the group child list.
        Group &ReorderFront(const std::initializer_list<const Object *> &objects);
        /// @brief [ @b MUIM_Group_Reorder, after = -1 ]
        /// Reorder the given children to the end of the group child list.
        Group &ReorderBack(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Group_Reorder, after = -1 ]
        /// Reorder the given children to the end of the group child list.
        Group &ReorderBack(const std::initializer_list<const Object *> &objects);
#endif

        /// @brief [ @b MUIM_Group_Sort ]
        /// Sort the children of a group.
        /// @param objects full child order (must contain all children)
        Group &Sort(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Group_Sort ]
        /// Sort the children of a group.
        /// @param objects full child order (must contain all children)
        Group &Sort(const std::initializer_list<const Object *> &objects);

        /// @brief [ @b OM_ADDMEMBER ] Add child object to group.
        /// @param pChildObject child object to add, ignored when nullptr
        Group &AddMember(const Object *pChildObject);
        /// @brief [ @b OM_ADDMEMBER ] Add child object to group.
        /// @param child child wrapper to add
        Group &AddMember(const Root &child);
        /// @brief [ @b OM_REMMEMBER ] Remove child object from group.
        /// @param pChildObject child object to remove, ignored when nullptr
        // After disconnecting an object from Group we must call explicitly DiposeObject() on the disconnected child
        // object, otherwise the memory will not be released
        Group &RemMember(const Object *pChildObject);
        /// @brief [ @b OM_REMMEMBER ] Remove child object from group.
        /// @param child child wrapper to remove
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
        /// @brief [ @b MUIA_Group_Child ]
        /// Add child object to group.
        /// @param pChildObject pointer to child object; nullptr is ignored by this convenience overload
        /// @param condition if false, tag is not added
        T &tagChild(const Object *pChildObject, bool condition = true);
        /// @brief [ @b MUIA_Group_Child ]
        /// Add child object to group.
        /// @param child Root wrapper of child object; null wrapped objects are ignored by this convenience overload
        /// @param condition if false, tag is not added
        T &tagChild(const Root &child, bool condition = true);
        /// @brief [ @b MUIA_Group_Child ] Add an explicit nullptr child tag.
        /// This preserves the original MUI semantics where a NULL child causes group creation to fail.
        /// @param condition if false, tag is not added
        T &tagChildNull(bool condition = true);
        /// @brief [ @b MUIA_Group_Columns ]
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
#ifdef MUIA_Group_LayoutHook
        /// @brief [ @b MUIA_Group_LayoutHook ]
        T &tagLayoutHook(const Hook *pLayoutHook);
#endif
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
}

#define MUI_GROUP_TPP_INCLUDE
#include "Group.tpp"
#undef MUI_GROUP_TPP_INCLUDE
