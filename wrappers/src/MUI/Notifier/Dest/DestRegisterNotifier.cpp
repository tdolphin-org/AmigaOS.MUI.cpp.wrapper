//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestRegisterNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestRegisterNotifier::DestRegisterNotifier(const NotifierObject &notifierObject, const Register &registerObject)
      : DestGroupNotifier(notifierObject, registerObject)
    {
    }

    DestRegisterNotifier::DestRegisterNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestGroupNotifier(notifierObject, notifyDestType)
    {
    }

    DestRegisterNotifier &DestRegisterNotifier::setTitles(const char *titles[], bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Register_Titles, titles);
        return *this;
    }

    DestRegisterNotifier &DestRegisterNotifier::setTitlesTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Register_Titles, MUIV_TriggerValue);
        return *this;
    }
}
