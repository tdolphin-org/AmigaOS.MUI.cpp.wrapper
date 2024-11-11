//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestGroupNotifier.hpp"
#include "MUI/Cycle.hpp"

namespace MUI
{
    enum class Cycle_Active;

    class DestCycleNotifier : public DestGroupNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestCycleNotifier() = delete;
        DestCycleNotifier(const NotifierObject &notifierObject, const Cycle &cycle);
        DestCycleNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Cycle_Active ]
        DestCycleNotifier &setActive(const enum Cycle_Active active, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Cycle_Active = @b MUIV_TriggerValue ]
        DestCycleNotifier &setActiveTriggerValue(bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Cycle_Entries ]
        DestCycleNotifier &setEntries(const char *entries[], bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Cycle_Entries = @b MUIV_TriggerValue ]
        DestCycleNotifier &setEntriesTriggerValue(bool notify = true);
    };
}
