//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestFamilyNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestFamilyNotifier::DestFamilyNotifier(const NotifierObject &notifierObject, const Family &family)
      : DestNotifyNotifier(notifierObject, family)
    {
    }
}
