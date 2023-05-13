//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestNotifyNotifier.hpp"

#include "MUI/Notify.hpp"

namespace MUI
{
    DestNotifyNotifier::DestNotifyNotifier(const SourceNotifier &sourceNotifier, const Notify &notify)
      : DestNotifierRoot(sourceNotifier, notify)
    {
    }
}
