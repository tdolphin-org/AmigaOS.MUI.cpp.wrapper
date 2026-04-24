//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Group.hpp"
#include "Core/ObjectVectorUtils.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Group::className = MUIC_Group;

    long Group::getActivePage() const
    {
        return GetValueAsLong(MUIA_Group_ActivePage);
    }

#ifdef MUIA_Group_ChildCount
    long Group::getChildCount() const
    {
        return GetValueAsLong(MUIA_Group_ChildCount);
    }
#endif

    const List *Group::getChildList() const
    {
        return GetValueAsConstListPtr(MUIA_Group_ChildList);
    }

#ifdef MUIA_Group_HorizCenter
    Group_HorizCenter Group::getHorizCenter() const
    {
        return (enum Group_HorizCenter)GetValueAsLong(MUIA_Group_HorizCenter);
    }
#endif

    long Group::getHorizSpacing() const
    {
        return GetValueAsLong(MUIA_Group_HorizSpacing);
    }

#ifdef MUIA_Group_VertCenter
    Group_VertCenter Group::getVertCenter() const
    {
        return (enum Group_VertCenter)GetValueAsLong(MUIA_Group_VertCenter);
    }
#endif

    long Group::getVertSpacing() const
    {
        return GetValueAsLong(MUIA_Group_VertSpacing);
    }

    Group &Group::setActivePage(const unsigned long activePage)
    {
        SetValue(MUIA_Group_ActivePage, activePage);
        return *this;
    }

    Group &Group::setActivePage(const enum Group_ActivePage activePage)
    {
        SetValue(MUIA_Group_ActivePage, (long)activePage);
        return *this;
    }

    Group &Group::setActivePageFirst()
    {
        return setActivePage(MUIV_Group_ActivePage_First);
    }

    Group &Group::setActivePageLast()
    {
        return setActivePage(MUIV_Group_ActivePage_Last);
    }

    Group &Group::setActivePageAdvance()
    {
        return setActivePage(MUIV_Group_ActivePage_Advance);
    }

    Group &Group::setColumns(const long columns)
    {
        SetValue(MUIA_Group_Columns, columns);
        return *this;
    }

#ifdef MUIA_Group_Forward
    Group &Group::setForward(const bool forward)
    {
        SetValue(MUIA_Group_Forward, forward);
        return *this;
    }
#endif

#ifdef MUIA_Group_ForwardDepth
    Group &Group::setForwardDepth(const unsigned long forwardDepth)
    {
        SetValue(MUIA_Group_ForwardDepth, forwardDepth);
        return *this;
    }
#endif

#ifdef MUIA_Group_HorizCenter
    Group &Group::setHorizCenter(const enum Group_HorizCenter horizCenter)
    {
        SetValue(MUIA_Group_HorizCenter, (long)horizCenter);
        return *this;
    }
#endif

    Group &Group::setHorizSpacing(const long horizSpacing)
    {
        SetValue(MUIA_Group_HorizSpacing, horizSpacing);
        return *this;
    }

#ifdef MUIA_Group_Rows
    Group &Group::setRows(const long rows)
    {
        SetValue(MUIA_Group_Rows, rows);
        return *this;
    }
#endif

#ifdef MUIA_Group_Spacing
    Group &Group::setSpacing(const long spacing)
    {
        SetValue(MUIA_Group_Spacing, spacing);
        return *this;
    }
#endif

#ifdef MUIA_Group_VertCenter
    Group &Group::setVertCenter(const enum Group_VertCenter vertCenter)
    {
        SetValue(MUIA_Group_VertCenter, (long)vertCenter);
        return *this;
    }
#endif

    Group &Group::setVertSpacing(const long vertSpacing)
    {
        SetValue(MUIA_Group_VertSpacing, vertSpacing);
        return *this;
    }

#ifdef MUIM_Group_AddHead
    Group &Group::AddHead(const Object *pChildObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), MUIM_Group_AddHead, (ULONG)pChildObject);
        return *this;
    }

    Group &Group::AddHead(const Root &child)
    {
        if (child.muiObject())
            DoMethod(muiObject(), MUIM_Group_AddHead, (ULONG)child.muiObject());
        return *this;
    }
#endif

#ifdef MUIM_Group_AddTail
    Group &Group::AddTail(const Object *pChildObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), MUIM_Group_AddTail, (ULONG)pChildObject);
        return *this;
    }

    Group &Group::AddTail(const Root &child)
    {
        if (child.muiObject())
            DoMethod(muiObject(), MUIM_Group_AddTail, (ULONG)child.muiObject());
        return *this;
    }
#endif

    Group &Group::ExitChange()
    {
        DoMethod(muiObject(), MUIM_Group_ExitChange);
        return *this;
    }

#ifdef MUIM_Group_ExitChange2
    Group &Group::ExitChange2(const unsigned long flags)
    {
        DoMethod(muiObject(), MUIM_Group_ExitChange2, flags);
        return *this;
    }
#endif

    Group &Group::InitChange()
    {
        DoMethod(muiObject(), MUIM_Group_InitChange);
        return *this;
    }

#ifdef MUIM_Group_MoveMember
    Group &Group::MoveMember(const Object *pChildObject, const long pos)
    {
        if (pChildObject)
            DoMethod(muiObject(), MUIM_Group_MoveMember, pChildObject, pos);
        return *this;
    }

    Group &Group::MoveMember(const Root &child, const long pos)
    {
        if (child.muiObject())
            DoMethod(muiObject(), MUIM_Group_MoveMember, child.muiObject(), pos);
        return *this;
    }
#endif

#ifdef MUIM_Group_Remove
    Group &Group::Remove(const Object *pChildObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), MUIM_Group_Remove, (ULONG)pChildObject);
        return *this;
    }

    Group &Group::Remove(const Root &child)
    {
        if (child.muiObject())
            DoMethod(muiObject(), MUIM_Group_Remove, (ULONG)child.muiObject());
        return *this;
    }
#endif

#ifdef MUIM_Group_Reorder
    Group &Group::Reorder(const Object *after, const std::vector<const Object *> &objects)
    {
        auto orderedObjects = Detail::makeNullTerminatedObjectVector(objects);
        DoMethod(muiObject(), MUIM_Group_Reorder, after, orderedObjects.data());
        return *this;
    }

    Group &Group::Reorder(const Object *after, const std::initializer_list<const Object *> &objects)
    {
        return Reorder(after, std::vector<const Object *>(objects));
    }

    Group &Group::ReorderFront(const std::vector<const Object *> &objects)
    {
        return Reorder(nullptr, objects);
    }

    Group &Group::ReorderFront(const std::initializer_list<const Object *> &objects)
    {
        return ReorderFront(std::vector<const Object *>(objects));
    }

    Group &Group::ReorderBack(const std::vector<const Object *> &objects)
    {
        return Reorder((const Object *)-1, objects);
    }

    Group &Group::ReorderBack(const std::initializer_list<const Object *> &objects)
    {
        return ReorderBack(std::vector<const Object *>(objects));
    }
#endif

    Group &Group::Sort(const std::vector<const Object *> &objects)
    {
        auto orderedObjects = Detail::makeNullTerminatedObjectVector(objects);
        DoMethod(muiObject(), MUIM_Group_Sort, orderedObjects.data());
        return *this;
    }

    Group &Group::Sort(const std::initializer_list<const Object *> &objects)
    {
        return Sort(std::vector<const Object *>(objects));
    }

    Group &Group::AddMember(const Object *pChildObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), OM_ADDMEMBER, (ULONG)pChildObject);
        return *this;
    }

    Group &Group::AddMember(const Root &child)
    {
        DoMethod(muiObject(), OM_ADDMEMBER, child.muiObject());
        return *this;
    }

    Group &Group::RemMember(const Object *pChildObject)
    {
        if (pChildObject)
            DoMethod(muiObject(), OM_REMMEMBER, (ULONG)pChildObject);
        return *this;
    }

    Group &Group::RemMember(const Root &child)
    {
        DoMethod(muiObject(), OM_REMMEMBER, child.muiObject());
        return *this;
    }

    GroupBuilder::GroupBuilder() { }
}
