//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Slider.hpp"

namespace MUI
{
    const std::string Slider::className = MUIC_Slider;

    SliderBuilder::SliderBuilder() { }

    bool Slider::getHoriz() const
    {
        return GetValueAsBool(MUIA_Slider_Horiz);
    }

    Slider &Slider::setHoriz(const bool horiz)
    {
        SetValue(MUIA_Slider_Horiz, horiz);
        return *this;
    }
}
