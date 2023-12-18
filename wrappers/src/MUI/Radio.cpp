//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Radio.hpp"

namespace MUI
{
    const std::string Radio::className = MUIC_Radio;

    long Radio::getActive() const
    {
        return GetValueAsLong(MUIA_Radio_Active);
    }

    Radio &Radio::setActive(const unsigned long active)
    {
        SetValue(MUIA_Radio_Active, active);
        return *this;
    }

    RadioBuilder::RadioBuilder() { }
}
