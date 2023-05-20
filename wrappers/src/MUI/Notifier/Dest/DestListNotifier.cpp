//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestListNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestListNotifier::DestListNotifier(const NotifierObject &notifierObject, const List &list)
      : DestAreaNotifier(notifierObject, list)
    {
    }
}
