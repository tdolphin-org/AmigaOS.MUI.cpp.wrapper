
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

        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checked ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onChecked(bool checked);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checked == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onCheckedEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checkit ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onCheckit(bool checkit);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checkit == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onCheckitEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Enabled ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onEnabled(bool enabled);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Enabled == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onEnabledEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Toggle ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onToggle(bool toggle);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Toggle == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onToggleEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Trigger == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, DestMenuitemNotifier> onTriggerEveryTime();
    };
}
