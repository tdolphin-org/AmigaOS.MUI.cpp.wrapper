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
}