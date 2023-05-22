//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestNotifyNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestNotifyNotifier::DestNotifyNotifier(const NotifierObject &notifierObject, const Notify &notify)
      : DestNotifierRoot(notifierObject, (MUI::Root &)notify)
    {
    }

    DestNotifyNotifier &DestNotifyNotifier::method(const unsigned long methodId)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 1, methodId);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::callHook(const void *hook)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 2, MUIM_CallHook, hook);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::callHook(const void *hook, const void *arg0)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3, MUIM_CallHook, hook, arg0);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::callHook(const void *hook, const void *arg0, const void *arg1)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 4, MUIM_CallHook, hook, arg0,
                 arg1);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::callHook(const void *hook, const void *arg0, const void *arg1, const void *arg2)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 5, MUIM_CallHook, hook, arg0, arg1,
                 arg2);
        return *this;
    }
}
