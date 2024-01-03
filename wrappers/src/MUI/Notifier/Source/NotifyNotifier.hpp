//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "../Core/SourceNotifier.hpp"
#include "MUI/Notify.hpp"

namespace MUI
{
    template <typename T = Notify, typename U = DestNotifyNotifier> class NotifyNotifier
    {
      protected:
        T mObject;

      public:
        NotifyNotifier() = delete;
        NotifyNotifier(const T &object)
          : mObject(object)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_HelpLine ]
        SourceNotifier<T, U> onHelpLine(const long helpLine);
    };

    template <typename T, typename U> SourceNotifier<T, U> inline NotifyNotifier<T, U>::onHelpLine(const long helpLine)
    {
        return SourceNotifier<T, U>(mObject, MUIA_HelpLine, helpLine);
    }
}
