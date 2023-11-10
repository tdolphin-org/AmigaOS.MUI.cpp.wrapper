//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestListNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestListNotifier::DestListNotifier(const NotifierObject &notifierObject, const List &list)
      : DestAreaNotifier(notifierObject, list)
    {
    }

    DestListNotifier &DestListNotifier::setTopPixel(const long topPixel, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_List_TopPixel, topPixel);
        return *this;
    }

    DestListNotifier &DestListNotifier::setTopPixelTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_List_TopPixel, MUIV_TriggerValue);
        return *this;
    }
}
