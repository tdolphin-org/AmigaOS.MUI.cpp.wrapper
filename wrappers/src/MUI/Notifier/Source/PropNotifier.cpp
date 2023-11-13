//
//  AmigaOS MUI C++ wrapperArea
//
//  (c) 2022-2023 TDolphin
//

#include "PropNotifier.hpp"

namespace MUI
{
    PropNotifier::PropNotifier(const Prop &prop)
      : mProp(prop)
      , GadgetNotifier(prop)
    {
    }

    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onDeltaFactor(const long deltaFactor)
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_DeltaFactor, deltaFactor);
    }

    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onDeltaFactorEveryTime()
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_DeltaFactor, (long)MUIV_EveryTime);
    }

    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onEntries(const long entries)
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_Entries, entries);
    }

    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onEntriesEveryTime()
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_Entries, (long)MUIV_EveryTime);
    }

    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onFirst(const long first)
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_First, first);
    }

    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onFirstEveryTime()
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_First, (long)MUIV_EveryTime);
    }
    
    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onVisible(const long visible)
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_Visible, visible);
    }

    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onVisibleEveryTime()
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_Visible, (long)MUIV_EveryTime);
    }
}
