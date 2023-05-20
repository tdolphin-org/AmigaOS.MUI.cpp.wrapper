//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "NotifyNotifier.hpp"
#include "MUI/Area.hpp"

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
        /// @brief [ @b MUIM_Notify, @b MUIA_Pressed ]
        SourceNotifier<Area, DestAreaNotifier> onPressed(const bool pressed);
    };
}
