//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
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

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Cycle_Active ]
        DestCycleNotifier &setActivePage(const enum Cycle_Active active, bool notify = true);
    };
}
