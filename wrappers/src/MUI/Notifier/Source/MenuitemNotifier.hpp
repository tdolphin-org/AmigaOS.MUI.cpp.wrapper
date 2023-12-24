
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
    template <typename T = Menuitem, typename U = DestMenuitemNotifier> class MenuitemNotifier : public FamilyNotifier<T, U>
    {
      public:
        MenuitemNotifier() = delete;
        MenuitemNotifier(const T &menuitem)
          : FamilyNotifier<T, U>(menuitem)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checked ]
        SourceNotifier<T, U> onChecked(bool checked);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checked == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onCheckedEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checkit ]
        SourceNotifier<T, U> onCheckit(bool checkit);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Checkit == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onCheckitEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Enabled ]
        SourceNotifier<T, U> onEnabled(bool enabled);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Enabled == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onEnabledEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Toggle ]
        SourceNotifier<T, U> onToggle(bool toggle);
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Toggle == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onToggleEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Menuitem_Trigger == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onTriggerEveryTime();
    };

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onChecked(bool checked)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Checked, checked);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onCheckedEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Checked, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onCheckit(bool checkit)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Checkit, checkit);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onCheckitEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Checkit, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onEnabled(bool enabled)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Enabled, enabled);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onEnabledEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Enabled, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onToggle(bool toggle)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Toggle, toggle);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onToggleEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Toggle, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline MenuitemNotifier<T, U>::onTriggerEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Menuitem_Trigger, (long)MUIV_EveryTime);
    }
}
