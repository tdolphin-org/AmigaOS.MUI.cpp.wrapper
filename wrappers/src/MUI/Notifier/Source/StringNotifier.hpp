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
    class StringNotifier : public AreaNotifier
    {
        String mString;

      public:
        StringNotifier() = delete;
        StringNotifier(const String &string);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_String_Contents == @b MUIV_EveryTime ]
        SourceNotifier<String, DestStringNotifier> onContentsEveryTime();
    };
}
