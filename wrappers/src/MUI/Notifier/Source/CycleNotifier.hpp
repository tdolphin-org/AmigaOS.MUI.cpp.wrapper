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
    template <typename T = DestCycleNotifier> class CycleNotifier : public GroupNotifier<T>
    {
        Cycle mCycle;

      public:
        CycleNotifier() = delete;
        CycleNotifier(const Cycle &cycle)
          : GroupNotifier<T>(cycle)
          , mCycle(cycle)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Cycle_Active ]
        SourceNotifier<Cycle, T> onActive(const enum Cycle_Active active);
        /// @brief [ @b MUIM_Notify, @b MUIA_Cycle_Active == @b MUIV_EveryTime ]
        SourceNotifier<Cycle, T> onActiveEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Cycle_Entries == @b MUIV_EveryTime ]
        SourceNotifier<Cycle, T> onEntriesEveryTime();
    };

    template <typename T> SourceNotifier<Cycle, T> inline CycleNotifier<T>::onActive(const enum Cycle_Active active)
    {
        return SourceNotifier<Cycle, T>(mCycle, MUIA_Cycle_Active, (unsigned long)active);
    }

    template <typename T> SourceNotifier<Cycle, T> inline CycleNotifier<T>::onActiveEveryTime()
    {
        return SourceNotifier<Cycle, T>(mCycle, MUIA_Cycle_Active, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Cycle, T> inline CycleNotifier<T>::onEntriesEveryTime()
    {
        return SourceNotifier<Cycle, T>(mCycle, MUIA_Cycle_Entries, (long)MUIV_EveryTime);
    }
}
