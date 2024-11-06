//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Prop.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Prop::className = MUIC_Prop;

    PropBuilder::PropBuilder() { }

#ifdef MUIA_Prop_DeltaFactor
    long Prop::getDeltaFactor() const
    {
        return GetValueAsLong(MUIA_Prop_DeltaFactor);
    }
#endif

    long Prop::getEntries() const
    {
        return GetValueAsLong(MUIA_Prop_Entries);
    }

    long Prop::getFirst() const
    {
        return GetValueAsLong(MUIA_Prop_First);
    }

    bool Prop::isHoriz() const
    {
        return GetValueAsBool(MUIA_Prop_Horiz);
    }

    long Prop::getVisible() const
    {
        return GetValueAsLong(MUIA_Prop_Visible);
    }

#ifdef MUIA_Prop_DeltaFactor
    Prop &Prop::setDeltaFactor(const long deltaFactor)
    {
        SetValue(MUIA_Prop_DeltaFactor, deltaFactor);
        return *this;
    }
#endif

    Prop &Prop::setEntries(const long entries)
    {
        SetValue(MUIA_Prop_Entries, entries);
        return *this;
    }

    Prop &Prop::setFirst(const long first)
    {
        SetValue(MUIA_Prop_First, first);
        return *this;
    }

    Prop &Prop::setVisible(const long visible)
    {
        SetValue(MUIA_Prop_Visible, visible);
        return *this;
    }

    Notify &Prop::Decrease(const long amount)
    {
        DoMethod(muiObject(), MUIM_Prop_Decrease, amount);
        return *this;
    }

    Notify &Prop::Increase(const long amount)
    {
        DoMethod(muiObject(), MUIM_Prop_Increase, amount);
        return *this;
    }
}
