//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "GroupNotifier.hpp"
#include "MUI/Cycle.hpp"

namespace MUI
{
    template <typename T = Cycle, typename U = DestCycleNotifier> class CycleNotifier : public GroupNotifier<T, U>
    {
      public:
        CycleNotifier() = delete;
        CycleNotifier(const T &cycle)
          : GroupNotifier<T, U>(cycle)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Cycle_Active ]
        SourceNotifier<T, U> onActive(const enum Cycle_Active active);
        /// @brief [ @b MUIM_Notify, @b MUIA_Cycle_Active == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onActiveEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Cycle_Entries == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onEntriesEveryTime();
    };

    template <typename T, typename U> SourceNotifier<T, U> inline CycleNotifier<T, U>::onActive(const enum Cycle_Active active)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Cycle_Active, (unsigned long)active);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline CycleNotifier<T, U>::onActiveEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Cycle_Active, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline CycleNotifier<T, U>::onEntriesEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Cycle_Entries, (long)MUIV_EveryTime);
    }
}
