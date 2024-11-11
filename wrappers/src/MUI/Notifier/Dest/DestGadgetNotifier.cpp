//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestGadgetNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestGadgetNotifier::DestGadgetNotifier(const NotifierObject &notifierObject, const Gadget &gadget)
      : DestAreaNotifier(notifierObject, gadget)
    {
    }

    DestGadgetNotifier::DestGadgetNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestAreaNotifier(notifierObject, notifyDestType)
    {
    }
}
