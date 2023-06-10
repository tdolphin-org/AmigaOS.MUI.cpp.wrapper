
//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "MenuitemNotifier.hpp"

namespace MUI
{
    MenuitemNotifier::MenuitemNotifier(const Menuitem &menuitem)
      : mMenuitem(menuitem)
      , FamilyNotifier(menuitem)
    {
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onChecked(bool checked)
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Checked, checked);
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onCheckedEveryTime()
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Checked, (long)MUIV_EveryTime);
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onCheckit(bool checkit)
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Checkit, checkit);
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onCheckitEveryTime()
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Checkit, (long)MUIV_EveryTime);
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onEnabled(bool enabled)
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Enabled, enabled);
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onEnabledEveryTime()
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Enabled, (long)MUIV_EveryTime);
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onToggle(bool toggle)
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Toggle, toggle);
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onToggleEveryTime()
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Toggle, (long)MUIV_EveryTime);
    }

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onTriggerEveryTime()
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Trigger, (long)MUIV_EveryTime);
    }
}
