//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Group.hpp"

#include <proto/alib.h>

#include "Notifier/Core/SourceNotifier.hpp"

namespace MUI
{
    long Group::getActivePage() const
    {
        return GetValueAsLong(MUIA_Group_ActivePage);
    }

    Group &Group::setActivePage(const unsigned long activePage)
    {
        SetValue(MUIA_Group_ActivePage, activePage);
        return *this;
    }

    Group &Group::setActivePage(const enum GroupActivePage activePage)
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

    Group &Group::AddHead(const Object *pChildObject)
    {
        DoMethod(muiObject(), MUIM_Group_AddHead, (ULONG)pChildObject);
        return *this;
    }

    Group &Group::AddTail(const Object *pChildObject)
    {
        DoMethod(muiObject(), MUIM_Group_AddTail, (ULONG)pChildObject);
        return *this;
    }

    Group &Group::ExitChange()
    {
        DoMethod(muiObject(), MUIM_Group_ExitChange);
        return *this;
    }

    Group &Group::ExitChange2()
    {
        DoMethod(muiObject(), MUIM_Group_ExitChange2);
        return *this;
    }

    Group &Group::InitChange()
    {
        DoMethod(muiObject(), MUIM_Group_InitChange);
        return *this;
    }

    Group &Group::Remove(const Object *pChildObject)
    {
        DoMethod(muiObject(), MUIM_Group_Remove, (ULONG)pChildObject);
        return *this;
    }

    SourceNotifier Group::onActivePage(const long activePage)
    {
        return SourceNotifier(*this, MUIA_Group_ActivePage, activePage);
    }

    SourceNotifier Group::onActivePage(const enum GroupActivePage activePage)
    {
        return SourceNotifier(*this, MUIA_Group_ActivePage, (long)activePage);
    }

    GroupBuilder::GroupBuilder() { }
}
