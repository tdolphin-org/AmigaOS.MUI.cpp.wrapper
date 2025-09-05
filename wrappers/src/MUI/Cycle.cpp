//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Cycle.hpp"

namespace MUI
{
    const std::string Cycle::className = MUIC_Cycle;

    long Cycle::getActive() const
    {
        return GetValueAsLong(MUIA_Cycle_Active);
    }

    Cycle &Cycle::setActive(const enum Cycle_Active active)
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

    Cycle &Cycle::setEntries(const std::vector<std::string> &entries)
    {
        auto copy = StoreStringArray(MUIA_Cycle_Entries, entries);
        SetValue(MUIA_Cycle_Entries, copy);
        return *this;
    }

    CycleBuilder::CycleBuilder() { }
}
