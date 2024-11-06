//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestGadgetNotifier.hpp"
#include "MUI/Prop.hpp"

namespace MUI
{
    class DestPropNotifier : public DestGadgetNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestPropNotifier() = delete;
        DestPropNotifier(const NotifierObject &notifierObject, const Prop &prop);

      public:
#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Prop_DeltaFactor ]
        DestPropNotifier &setDeltaFactor(const long deltaFactor, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Prop_DeltaFactor = @b MUIV_TriggerValue ]
        DestPropNotifier &setDeltaFactorTriggerValue(bool notify = true);
#endif
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Prop_Entries ]
        DestPropNotifier &setEntries(const long entries, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Prop_Entries = @b MUIV_TriggerValue ]
        DestPropNotifier &setEntriesTriggerValue(bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Prop_First ]
        DestPropNotifier &setFirst(const long first, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Prop_First = @b MUIV_TriggerValue ]
        DestPropNotifier &setFirstTriggerValue(bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Prop_Visible ]
        DestPropNotifier &setVisible(const long visible, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Prop_Visible = @b MUIV_TriggerValue ]
        DestPropNotifier &setVisibleTriggerValue(bool notify = true);
    };
}
