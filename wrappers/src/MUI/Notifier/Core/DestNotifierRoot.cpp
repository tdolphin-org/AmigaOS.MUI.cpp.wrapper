//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestNotifierRoot.hpp"

namespace MUI
{
    DestNotifierRoot::DestNotifierRoot(const NotifierObject &notifierObject, const Root &root)
      : mNotifierObject(notifierObject)
      , mObject(root)
    {
    }
}
