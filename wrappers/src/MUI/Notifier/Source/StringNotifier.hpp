//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/String.hpp"

namespace MUI
{
    template <typename T = DestStringNotifier> class StringNotifier : public AreaNotifier<T>
    {
        String mString;

      public:
        StringNotifier() = delete;
        StringNotifier(const String &string)
          : AreaNotifier<T>(string)
          , mString(string)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_String_Contents == @b MUIV_EveryTime ]
        SourceNotifier<String, T> onContentsEveryTime();
    };

    template <typename T> SourceNotifier<String, T> inline StringNotifier<T>::onContentsEveryTime()
    {
        return SourceNotifier<String, T>(mString, MUIA_String_Contents, (long)MUIV_EveryTime);
    }
}
