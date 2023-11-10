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

    SourceNotifier<Prop, DestPropNotifier> PropNotifier::onFirstEveryTime()
    {
        return SourceNotifier<Prop, DestPropNotifier>(mProp, MUIA_Prop_First, (long)MUIV_EveryTime);
    }
}
