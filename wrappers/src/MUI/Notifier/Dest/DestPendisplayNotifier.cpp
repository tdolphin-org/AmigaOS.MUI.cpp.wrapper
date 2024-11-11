//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestPendisplayNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestPendisplayNotifier::DestPendisplayNotifier(const NotifierObject &notifierObject, const Pendisplay &pendisplay)
      : DestAreaNotifier(notifierObject, pendisplay)
    {
    }

    DestPendisplayNotifier::DestPendisplayNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestAreaNotifier(notifierObject, notifyDestType)
    {
    }
}
