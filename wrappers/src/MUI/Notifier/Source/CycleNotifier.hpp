//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "GroupNotifier.hpp"
#include "MUI/Cycle.hpp"

namespace MUI
{
    class CycleNotifier : public GroupNotifier
    {
        Cycle mCycle;

      public:
        CycleNotifier() = delete;
        CycleNotifier(const Cycle &cycle);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Cycle_Active ]
        SourceNotifier<Cycle, DestCycleNotifier> onActive(const enum Cycle_Active active);
        /// @brief [ @b MUIM_Notify, @b MUIA_Cycle_Active == @b MUIV_EveryTime ]
        SourceNotifier<Cycle, DestCycleNotifier> onActiveEveryTime();
    };
}
