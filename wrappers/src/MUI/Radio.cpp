//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Radio.hpp"

namespace MUI
{
    const std::string Radio::className = MUIC_Radio;

    long Radio::getActive() const
    {
        return GetValueAsLong(MUIA_Radio_Active);
    }

    Radio &Radio::setActive(const long active)
    {
        SetValue(MUIA_Radio_Active, active);
        return *this;
    }

    RadioBuilder::RadioBuilder() { }
}
