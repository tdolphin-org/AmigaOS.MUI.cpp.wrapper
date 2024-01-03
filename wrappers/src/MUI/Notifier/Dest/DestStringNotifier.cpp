//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestStringNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestStringNotifier::DestStringNotifier(const NotifierObject &notifierObject, const String &string)
      : DestAreaNotifier(notifierObject, string)
    {
    }
}
