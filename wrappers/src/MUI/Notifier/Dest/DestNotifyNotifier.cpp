//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestNotifyNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestNotifyNotifier::DestNotifyNotifier(const NotifierObject &notifierObject, const Notify &notify)
      : DestNotifierRoot(notifierObject, (MUI::Root &)notify)
    {
    }

    DestNotifyNotifier::DestNotifyNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestNotifierRoot(notifierObject, notifyDestType)
    {
    }

    DestNotifyNotifier &DestNotifyNotifier::method(const unsigned long methodId)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 1, methodId);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::callHook(const void *hook)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 2, MUIM_CallHook, hook);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::callHook(const void *hook, const std::initializer_list<const void *> &args)
    {
        std::vector<const void *> vec(args);
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), vec.size(), MUIM_CallHook, hook,
                 vec.data());
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::writeLong(const unsigned long val, unsigned long *memory)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3, MUIM_WriteLong, val, memory);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::writeLongTriggerValue(unsigned long *memory)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3, MUIM_WriteLong, MUIV_TriggerValue,
                 memory);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::writeString(const char *str, char *memory)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3, MUIM_WriteString, str, memory);
        return *this;
    }

    DestNotifyNotifier &DestNotifyNotifier::writeStringTriggerValue(char *memory)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3, MUIM_WriteString, MUIV_TriggerValue,
                 memory);
        return *this;
    }
}
