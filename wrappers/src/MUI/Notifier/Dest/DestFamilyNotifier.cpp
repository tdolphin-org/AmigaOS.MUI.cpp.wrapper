//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestFamilyNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestFamilyNotifier::DestFamilyNotifier(const NotifierObject &notifierObject, const Family &family)
      : DestNotifyNotifier(notifierObject, family)
    {
    }

    DestFamilyNotifier::DestFamilyNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestNotifyNotifier(notifierObject, notifyDestType)
    {
    }
}
