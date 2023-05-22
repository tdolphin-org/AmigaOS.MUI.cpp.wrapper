//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "NotifyNotifier.hpp"

namespace MUI
{
    NotifyNotifier::NotifyNotifier(const Notify &notify)
      : mNotify(notify)
    {
    }

    SourceNotifier<Notify, DestNotifyNotifier> NotifyNotifier::onHelpLine(const long helpLine)
    {
        return SourceNotifier<Notify, DestNotifyNotifier>(mNotify, MUIA_HelpLine, helpLine);
    }
}
