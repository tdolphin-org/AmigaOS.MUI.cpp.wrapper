//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestPropNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestPropNotifier::DestPropNotifier(const NotifierObject &notifierObject, const Prop &prop)
      : DestGadgetNotifier(notifierObject, prop)
    {
    }

    DestPropNotifier &DestPropNotifier::setEntriesTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_Entries, MUIV_TriggerValue);
        return *this;
    }

    DestPropNotifier &DestPropNotifier::setVisibleTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_Visible, MUIV_TriggerValue);
        return *this;
    }

    DestPropNotifier &DestPropNotifier::setFirstTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_First, MUIV_TriggerValue);
        return *this;
    }
}
