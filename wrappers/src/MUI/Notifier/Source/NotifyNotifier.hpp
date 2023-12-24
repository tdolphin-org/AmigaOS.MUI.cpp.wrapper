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
    template <typename T = DestNotifyNotifier> class NotifyNotifier
    {
        Notify mNotify;

      public:
        NotifyNotifier() = delete;
        NotifyNotifier(const Notify &notify)
          : mNotify(notify)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_HelpLine ]
        SourceNotifier<Notify, T> onHelpLine(const long helpLine);
    };

    template <typename T> SourceNotifier<Notify, T> inline NotifyNotifier<T>::onHelpLine(const long helpLine)
    {
        return SourceNotifier<Notify, T>(mNotify, MUIA_HelpLine, helpLine);
    }
}
