//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Cycle.hpp"

namespace MUI
{
    CycleBuilder::CycleBuilder() { }

    long Cycle::getActive() const
    {
        return GetValueAsLong(MUIA_Cycle_Active);
    }

    Cycle &Cycle::setActive(const enum CycleActive active)
    {
        SetValue(MUIA_Cycle_Active, (long)active);
        return *this;
    }

    Cycle &Cycle::setActiveNext()
    {
        setActive(MUIV_Cycle_Active_Next);
        return *this;
    }

    Cycle &Cycle::setActivePrev()
    {
        setActive(MUIV_Cycle_Active_Prev);
        return *this;
    }

    Cycle &Cycle::setActive(const unsigned long active)
    {
        SetValue(MUIA_Cycle_Active, active);
        return *this;
    }

    Cycle &Cycle::setEntries(const char *entries[])
    {
        SetValue(MUIA_Cycle_Entries, entries);
        return *this;
    }
}
