//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "GadgetNotifier.hpp"
#include "MUI/Prop.hpp"

namespace MUI
{
    class PropNotifier : public GadgetNotifier
    {
        Prop mProp;

      public:
        PropNotifier() = delete;
        PropNotifier(const Prop &prop);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_First == @b MUIV_EveryTime  ]
        SourceNotifier<Prop, DestPropNotifier> onFirstEveryTime();
    };
}
