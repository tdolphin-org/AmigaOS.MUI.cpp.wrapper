//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestListNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestListNotifier::DestListNotifier(const NotifierObject &notifierObject, const List &list)
      : DestAreaNotifier(notifierObject, list)
    {
    }

    DestListNotifier::DestListNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestAreaNotifier(notifierObject, notifyDestType)
    {
    }

    DestListNotifier &DestListNotifier::setActive(const long active, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_List_Active, active);
        return *this;
    }

    DestListNotifier &DestListNotifier::setActiveTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_List_Active, MUIV_TriggerValue);
        return *this;
    }

#ifdef MUIA_List_TopPixel
    DestListNotifier &DestListNotifier::setTopPixel(const long topPixel, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_List_TopPixel, topPixel);
        return *this;
    }

    DestListNotifier &DestListNotifier::setTopPixelTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_List_TopPixel, MUIV_TriggerValue);
        return *this;
    }
#endif
}
