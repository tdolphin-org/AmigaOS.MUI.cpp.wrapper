//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Popasl.hpp"

namespace MUI
{
    const std::string Popasl::className = MUIC_Popasl;

    PopaslBuilder::PopaslBuilder() { }

    bool Popasl::isActive() const
    {
        return GetValueAsBool(MUIA_Popasl_Active);
    }

    Hook *Popasl::getStartHook() const
    {
        return (Hook *)GetValueAsPtr(MUIA_Popasl_StartHook);
    }

    Hook *Popasl::getStopHook() const
    {
        return (Hook *)GetValueAsPtr(MUIA_Popasl_StopHook);
    }

    unsigned long Popasl::getType() const
    {
        return GetValueAsULong(MUIA_Popasl_Type);
    }

    Popasl &Popasl::setStartHook(const Hook *startHook)
    {
        SetValue(MUIA_Popasl_StartHook, startHook);
        return *this;
    }

    Popasl &Popasl::setStopHook(const Hook *stopHook)
    {
        SetValue(MUIA_Popasl_StopHook, stopHook);
        return *this;
    }
}
