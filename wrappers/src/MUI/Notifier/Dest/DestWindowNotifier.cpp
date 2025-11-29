//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2025 TDolphin
//

#include "DestWindowNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestWindowNotifier::DestWindowNotifier(const NotifierObject &notifierObject, const Window &window)
      : DestNotifyNotifier(notifierObject, window)
    {
    }

    DestWindowNotifier::DestWindowNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestNotifyNotifier(notifierObject, notifyDestType)
    {
    }

    DestWindowNotifier &DestWindowNotifier::setOpen(const bool open, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Window_Open, (unsigned long)open);
        return *this;
    }

    DestWindowNotifier &DestWindowNotifier::toFront()
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 1,
                 MUIM_Window_ToFront);
        return *this;
    }
}
