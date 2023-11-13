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

        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_DeltaFactor ]
        SourceNotifier<Prop, DestPropNotifier> onDeltaFactor(const long deltaFactor);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_DeltaFactor == @b MUIV_EveryTime ]
        SourceNotifier<Prop, DestPropNotifier> onDeltaFactorEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Entries ]
        SourceNotifier<Prop, DestPropNotifier> onEntries(const long entries);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Entries == @b MUIV_EveryTime ]
        SourceNotifier<Prop, DestPropNotifier> onEntriesEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_First ]
        SourceNotifier<Prop, DestPropNotifier> onFirst(const long first);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_First == @b MUIV_EveryTime ]
        SourceNotifier<Prop, DestPropNotifier> onFirstEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Visible ]
        SourceNotifier<Prop, DestPropNotifier> onVisible(const long visible);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Visible == @b MUIV_EveryTime ]
        SourceNotifier<Prop, DestPropNotifier> onVisibleEveryTime();
    };
}
