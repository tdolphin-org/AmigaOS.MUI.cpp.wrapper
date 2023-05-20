//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestWindowNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestWindowNotifier::DestWindowNotifier(const NotifierObject &notifierObject, const Window &window)
      : DestNotifyNotifier(notifierObject, window)
    {
    }

    DestWindowNotifier &DestWindowNotifier::setOpen(const bool open, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Window_Open, (unsigned long)open);
        return *this;
    }
}
