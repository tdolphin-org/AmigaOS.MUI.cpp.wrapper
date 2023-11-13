//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestCycleNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestCycleNotifier::DestCycleNotifier(const NotifierObject &notifierObject, const Cycle &cycle)
      : DestGroupNotifier(notifierObject, cycle)
    {
    }

    DestCycleNotifier &DestCycleNotifier::setActive(const enum Cycle_Active active, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Cycle_Active, (unsigned long)active);
        return *this;
    }

    DestCycleNotifier &DestCycleNotifier::setActiveTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Cycle_Active, MUIV_TriggerValue);
        return *this;
    }

    DestCycleNotifier &DestCycleNotifier::setEntries(const char *entries[], bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Cycle_Entries, entries);
        return *this;
    }

    DestCycleNotifier &DestCycleNotifier::setEntriesTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Cycle_Entries, MUIV_TriggerValue);
        return *this;
    }
}
