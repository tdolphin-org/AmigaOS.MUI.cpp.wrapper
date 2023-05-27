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

    DestNotifyNotifier &DestNotifyNotifier::writeLong(const unsigned long val, unsigned long *memory)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3, MUIM_WriteLong, val, memory);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::writeLongTriggerValue(unsigned long *memory)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3, MUIM_WriteLong,
                 MUIV_TriggerValue, memory);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::writeString(const char *str, char *memory)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3, MUIM_WriteString, str, memory);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::writeStringTriggerValue(char *memory)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3, MUIM_WriteString,
                 MUIV_TriggerValue, memory);
        return *this;
    }
}
