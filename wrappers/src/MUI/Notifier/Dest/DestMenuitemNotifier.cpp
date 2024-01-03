//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestMenuitemNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestMenuitemNotifier::DestMenuitemNotifier(const NotifierObject &notifierObject, const Menuitem &menuitem)
      : DestFamilyNotifier(notifierObject, menuitem)
    {
    }
    
    DestMenuitemNotifier &DestMenuitemNotifier::setChecked(const bool checked, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Menuitem_Checked, (unsigned long)checked);
        return *this;
    }
    
    DestMenuitemNotifier &DestMenuitemNotifier::setCheckedTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Menuitem_Checked, MUIV_TriggerValue);
        return *this;
    }
}
