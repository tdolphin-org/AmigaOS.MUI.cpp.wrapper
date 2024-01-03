//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/String.hpp"

namespace MUI
{
    template <typename T = String, typename U = DestStringNotifier> class StringNotifier : public AreaNotifier<T, U>
    {
      public:
        StringNotifier() = delete;
        StringNotifier(const T &string)
          : AreaNotifier<T, U>(string)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_String_Contents == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onContentsEveryTime();
    };

    template <typename T, typename U> SourceNotifier<T, U> inline StringNotifier<T, U>::onContentsEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_String_Contents, (long)MUIV_EveryTime);
    }
}
