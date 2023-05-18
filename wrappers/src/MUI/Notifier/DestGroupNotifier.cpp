//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestGroupNotifier.hpp"

#include <proto/alib.h>

#include "MUI/Group.hpp"

namespace MUI
{
    DestGroupNotifier::DestGroupNotifier(const NotifierObject &notifierObject, const Group &group)
      : DestAreaNotifier(notifierObject, group)
    {
    }

    DestGroupNotifier &DestGroupNotifier::setActivePage(const unsigned long activePage, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Group_ActivePage, activePage);
    }

    DestGroupNotifier &DestGroupNotifier::setActivePage(const enum GroupActivePage activePage, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Group_ActivePage, (unsigned long)activePage);
    }
}
