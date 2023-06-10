//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestRegisterNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestRegisterNotifier::DestRegisterNotifier(const NotifierObject &notifierObject, const Register &registerObject)
      : DestGroupNotifier(notifierObject, registerObject)
    {
    }
}
