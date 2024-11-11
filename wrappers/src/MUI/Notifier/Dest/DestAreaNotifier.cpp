//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestAreaNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestAreaNotifier::DestAreaNotifier(const NotifierObject &notifierObject, const Area &area)
      : DestNotifyNotifier(notifierObject, area)
    {
    }

    DestAreaNotifier::DestAreaNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestNotifyNotifier(notifierObject, notifyDestType)
    {
    }

    DestAreaNotifier &DestAreaNotifier::setDisabled(const bool disabled, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Disabled, (unsigned long)disabled);
        return *this;
    }

    DestAreaNotifier &DestAreaNotifier::setDisabledTriggerValue(bool notify, enum Trigger trigger)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Disabled, trigger);
        return *this;
    }

    DestAreaNotifier &DestAreaNotifier::setSelected(const bool selected, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Selected, (unsigned long)selected);
        return *this;
    }

    DestAreaNotifier &DestAreaNotifier::setSelectedTriggerValue(bool notify, enum Trigger trigger)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Selected, trigger);
        return *this;
    }

    DestAreaNotifier &DestAreaNotifier::setShowMe(const bool showMe, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_ShowMe, (unsigned long)showMe);
        return *this;
    }

    DestAreaNotifier &DestAreaNotifier::setShowMeTriggerValue(bool notify, enum Trigger trigger)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_ShowMe, trigger);
        return *this;
    }
}
