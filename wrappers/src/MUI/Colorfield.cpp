//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Colorfield.hpp"

namespace MUI
{
    const std::string Colorfield::className = MUIC_Colorfield;

    unsigned char Colorfield::getBlue() const
    {
        return RGBColor::from32Bit(GetValueAsULong(MUIA_Colorfield_Blue));
    }

    unsigned char Colorfield::getGreen() const
    {
        return RGBColor::from32Bit(GetValueAsULong(MUIA_Colorfield_Green));
    }

    unsigned long Colorfield::getPen() const
    {
        return GetValueAsULong(MUIA_Colorfield_Pen);
    }

    unsigned char Colorfield::getRed() const
    {
        return RGBColor::from32Bit(GetValueAsULong(MUIA_Colorfield_Red));
    }

    RGBColor Colorfield::getRGB() const
    {
        auto *rgb = (unsigned long *)GetValueAsPtr(MUIA_Colorfield_RGB);
        return RGBColor(rgb);
    }

    Colorfield &Colorfield::setBlue(const unsigned char blue)
    {
        SetValue(MUIA_Colorfield_Blue, RGBColor::to32Bit(blue));
        return *this;
    }

    Colorfield &Colorfield::setGreen(const unsigned char green)
    {
        SetValue(MUIA_Colorfield_Green, RGBColor::to32Bit(green));
        return *this;
    }

    Colorfield &Colorfield::setRed(const unsigned char red)
    {
        SetValue(MUIA_Colorfield_Red, RGBColor::to32Bit(red));
        return *this;
    }

    Colorfield &Colorfield::setRGB(const unsigned char red, const unsigned char green, const unsigned char blue)
    {
        unsigned long rgb[3] = { red, green, blue };
        SetValue(MUIA_Colorfield_RGB, (void *)rgb);
        return *this;
    }

    Colorfield &Colorfield::setRGB(const RGBColor &rgbColor)
    {
        unsigned long rgb[3] = { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
        SetValue(MUIA_Colorfield_RGB, (void *)rgb);
        return *this;
    }

    ColorfieldBuilder::ColorfieldBuilder() { }
}
