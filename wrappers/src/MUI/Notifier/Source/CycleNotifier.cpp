//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "CycleNotifier.hpp"

namespace MUI
{
    CycleNotifier::CycleNotifier(const Cycle &cycle)
      : GroupNotifier(cycle)
      , mCycle(cycle)
    {
    }

    SourceNotifier<Cycle, DestCycleNotifier> CycleNotifier::onActiveEveryTime()
    {
        return SourceNotifier<Cycle, DestCycleNotifier>(mCycle, MUIA_List_Active, (long)MUIV_EveryTime);
    }

    SourceNotifier<Cycle, DestCycleNotifier> CycleNotifier::onActive(const enum CycleActive active)
    {
        return SourceNotifier<Cycle, DestCycleNotifier>(mCycle, MUIA_List_Active, (unsigned long)active);
    }
}