//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestNotifyNotifier.hpp"

namespace MUI
{
    DestNotifyNotifier::DestNotifyNotifier(const NotifierObject &notifierObject, const Notify &notify)
      : DestNotifierRoot(notifierObject, (MUI::Root &)notify)
    {
    }
}
