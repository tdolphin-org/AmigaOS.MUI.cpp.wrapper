//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "../Core/SourceNotifier.hpp"
#include "MUI/Notify.hpp"

namespace MUI
{
    class NotifyNotifier
    {
        Notify mNotify;

      public:
        NotifyNotifier() = delete;
        NotifyNotifier(const Notify &notify);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_HelpLine ]
        SourceNotifier<Notify, DestNotifyNotifier> onHelpLine(const long helpLine);
    };
}
