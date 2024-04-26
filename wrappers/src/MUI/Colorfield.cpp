//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Colorfield.hpp"

namespace MUI
{
    const std::string Colorfield::className = MUIC_Colorfield;

    ColorfieldBuilder::ColorfieldBuilder() { }

    unsigned long Colorfield::getBlue() const
    {
        return GetValueAsULong(MUIA_Colorfield_Blue);
    }

    unsigned long Colorfield::getGreen() const
    {
        return GetValueAsULong(MUIA_Colorfield_Green);
    }

    unsigned long Colorfield::getPen() const
    {
        return GetValueAsULong(MUIA_Colorfield_Pen);
    }

    unsigned long Colorfield::getRed() const
    {
        return GetValueAsULong(MUIA_Colorfield_Red);
    }

    RGBColor Colorfield::getRGB() const
    {
        auto *rgb = (unsigned long *)GetValueAsPtr(MUIA_Colorfield_RGB);
        return RGBColor({ rgb[0], rgb[1], rgb[2] });
    }

    Colorfield &Colorfield::setBlue(const unsigned long blue)
    {
        SetValue(MUIA_Colorfield_Blue, blue);
        return *this;
    }

    Colorfield &Colorfield::setGreen(const unsigned long green)
    {
        SetValue(MUIA_Colorfield_Green, green);
        return *this;
    }

    Colorfield &Colorfield::setRed(const unsigned long red)
    {
        SetValue(MUIA_Colorfield_Red, red);
        return *this;
    }

    Colorfield &Colorfield::setRGB(const unsigned long red, const unsigned long green, const unsigned long blue)
    {
        unsigned long rgb[3] = { red, green, blue };
        SetValue(MUIA_Colorfield_RGB, (void *)rgb);
        return *this;
    }
}
