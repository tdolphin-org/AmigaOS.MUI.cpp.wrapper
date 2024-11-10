//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Group.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Group::className = MUIC_Group;

    long Group::getActivePage() const
    {
        return GetValueAsLong(MUIA_Group_ActivePage);
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
    Group &Group::ExitChange2()
    {
        DoMethod(muiObject(), MUIM_Group_ExitChange2);
        return *this;
    }
#endif

    Group &Group::InitChange()
    {
        DoMethod(muiObject(), MUIM_Group_InitChange);
        return *this;
    }

#ifdef MUIM_Group_Remove
    Group &Group::Remove(const Object *pChildObject)
    {
        DoMethod(muiObject(), MUIM_Group_Remove, (ULONG)pChildObject);
        return *this;
    }
#endif

    Group &Group::AddMember(const Root &child)
    {
        DoMethod(muiObject(), OM_ADDMEMBER, child.muiObject());
        return *this;
    }

    Group &Group::RemMember(const Root &child)
    {
        DoMethod(muiObject(), OM_REMMEMBER, child.muiObject());
        return *this;
    }

    GroupBuilder::GroupBuilder() { }
}
