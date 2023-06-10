
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

    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onTriggerEveryTime()
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Trigger, (long)MUIV_EveryTime);
    }
    
    SourceNotifier<Menuitem, DestMenuitemNotifier> MenuitemNotifier::onCheckitEveryTime()
    {
        return SourceNotifier<Menuitem, DestMenuitemNotifier>(mMenuitem, MUIA_Menuitem_Checkit, (long)MUIV_EveryTime);
    }
}
