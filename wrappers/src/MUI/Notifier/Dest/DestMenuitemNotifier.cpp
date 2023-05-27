//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestMenuitemNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestMenuitemNotifier::DestMenuitemNotifier(const NotifierObject &notifierObject, const Menuitem &menuitem)
      : DestFamilyNotifier(notifierObject, menuitem)
    {
    }
}
