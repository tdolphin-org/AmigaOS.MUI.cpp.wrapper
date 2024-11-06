//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestPropNotifier.hpp"

#include <proto/alib.h>

namespace MUI
{
    DestPropNotifier::DestPropNotifier(const NotifierObject &notifierObject, const Prop &prop)
      : DestGadgetNotifier(notifierObject, prop)
    {
    }

#ifdef MUIA_Prop_DeltaFactor
    DestPropNotifier &DestPropNotifier::setDeltaFactor(const long deltaFactor, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_DeltaFactor, deltaFactor);
        return *this;
    }

    DestPropNotifier &DestPropNotifier::setDeltaFactorTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_DeltaFactor, MUIV_TriggerValue);
        return *this;
    }
#endif

    DestPropNotifier &DestPropNotifier::setEntries(const long entries, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_Entries, entries);
        return *this;
    }

    DestPropNotifier &DestPropNotifier::setEntriesTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_Entries, MUIV_TriggerValue);
        return *this;
    }

    DestPropNotifier &DestPropNotifier::setFirst(const long first, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_First, first);
        return *this;
    }

    DestPropNotifier &DestPropNotifier::setFirstTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_First, MUIV_TriggerValue);
        return *this;
    }

    DestPropNotifier &DestPropNotifier::setVisible(const long visible, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_Visible, visible);
        return *this;
    }

    DestPropNotifier &DestPropNotifier::setVisibleTriggerValue(bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Prop_Visible, MUIV_TriggerValue);
        return *this;
    }
}
