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
    DestGroupNotifier::DestGroupNotifier(const SourceNotifier &sourceNotifier, const Group &group)
      : DestAreaNotifier(sourceNotifier, group)
    {
    }

    DestGroupNotifier &DestGroupNotifier::setActivePage(const long activePage, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTrigValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Group_ActivePage, activePage);
    }

    DestGroupNotifier &DestGroupNotifier::setActivePage(const GroupActivePage activePage, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTrigValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Group_ActivePage, (unsigned long)activePage);
    }
}
