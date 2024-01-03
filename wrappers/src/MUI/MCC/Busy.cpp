//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Busy.hpp"

#include <proto/alib.h>

namespace MUI::MCC
{
    const std::string Busy::className = MUIC_Busy;

    bool Busy::isSpeedOff() const
    {
        return GetValueAsLong(MUIA_Busy_Speed) == MUIV_Busy_Speed_Off;
    }

    bool Busy::isSpeedUser() const
    {
        return GetValueAsLong(MUIA_Busy_Speed) == MUIV_Busy_Speed_User;
    }

    long Busy::getSpeed() const
    {
        return GetValueAsLong(MUIA_Busy_Speed);
    }

    Busy &Busy::setSpeedOff()
    {
        SetValue(MUIA_Busy_Speed, (long)MUIV_Busy_Speed_Off);
        return *this;
    }

    Busy &Busy::setSpeedUser()
    {
        SetValue(MUIA_Busy_Speed, (long)MUIV_Busy_Speed_User);
        return *this;
    }

    Busy &Busy::setSpeed(const unsigned char speed)
    {
        SetValue(MUIA_Busy_Speed, (long)speed);
        return *this;
    }

    Busy &Busy::Move()
    {
        DoMethod(muiObject(), MUIM_Busy_Move);
        return *this;
    }

    BusyBuilder::BusyBuilder() { }
}
