
//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "FamilyNotifier.hpp"
#include "MUI/Menuitem.hpp"

namespace MUI
{
    class MenuitemNotifier : public FamilyNotifier
    {
        Menuitem mMenuitem;

      public:
        MenuitemNotifier() = delete;
        MenuitemNotifier(const Menuitem &menuitem);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Trigger == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onTriggerEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checkit == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onCheckitEveryTime();
    };
}
