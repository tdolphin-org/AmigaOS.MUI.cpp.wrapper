
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
    template <typename T = DestMenuitemNotifier> class MenuitemNotifier : public FamilyNotifier<T>
    {
        Menuitem mMenuitem;

      public:
        MenuitemNotifier() = delete;
        MenuitemNotifier(const Menuitem &menuitem)
          : FamilyNotifier<T>(menuitem)
          , mMenuitem(menuitem)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checked ]
        SourceNotifier<Menuitem, T> onChecked(bool checked);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checked == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, T> onCheckedEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checkit ]
        SourceNotifier<Menuitem, T> onCheckit(bool checkit);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checkit == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, T> onCheckitEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Enabled ]
        SourceNotifier<Menuitem, T> onEnabled(bool enabled);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Enabled == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, T> onEnabledEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Toggle ]
        SourceNotifier<Menuitem, T> onToggle(bool toggle);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Toggle == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, T> onToggleEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Trigger == @b MUIV_EveryTime ]
        SourceNotifier<Menuitem, T> onTriggerEveryTime();
    };

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onChecked(bool checked)
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Checked, checked);
    }

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onCheckedEveryTime()
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Checked, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onCheckit(bool checkit)
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Checkit, checkit);
    }

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onCheckitEveryTime()
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Checkit, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onEnabled(bool enabled)
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Enabled, enabled);
    }

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onEnabledEveryTime()
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Enabled, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onToggle(bool toggle)
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Toggle, toggle);
    }

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onToggleEveryTime()
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Toggle, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Menuitem, T> inline MenuitemNotifier<T>::onTriggerEveryTime()
    {
        return SourceNotifier<Menuitem, T>(mMenuitem, MUIA_Menuitem_Trigger, (long)MUIV_EveryTime);
    }
}
