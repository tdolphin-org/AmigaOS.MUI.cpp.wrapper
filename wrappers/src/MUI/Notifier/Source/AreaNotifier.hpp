//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Area.hpp"
#include "NotifyNotifier.hpp"

namespace MUI
{
    class AreaNotifier : public NotifyNotifier
    {
        Area mArea;

      public:
        AreaNotifier() = delete;
        AreaNotifier(const Area &area);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Selected ]
        SourceNotifier<Area, DestAreaNotifier> onSelected(const bool selected);
        /// @brief [ @b MUIM_Notify, @b MUIA_Selected == @b MUIV_EveryTime ]
        SourceNotifier<Area, DestAreaNotifier> onSelectedEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Pressed ]
        SourceNotifier<Area, DestAreaNotifier> onPressed(const bool pressed);
        /// @brief [ @b MUIM_Notify, @b MUIA_Pressed  == @b MUIV_EveryTime ]
        SourceNotifier<Area, DestAreaNotifier> onPressedEveryTime();
    };
}
