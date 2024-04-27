//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Coloradjust.hpp"

namespace MUI
{
    const std::string Coloradjust::className = MUIC_Coloradjust;

    unsigned char Coloradjust::getBlue() const
    {
        return RGBColor::from32Bit(GetValueAsULong(MUIA_Coloradjust_Blue));
    }

    unsigned char Coloradjust::getGreen() const
    {
        return RGBColor::from32Bit(GetValueAsULong(MUIA_Coloradjust_Green));
    }

    unsigned long Coloradjust::getModeID() const
    {
        return GetValueAsULong(MUIA_Coloradjust_ModeID);
    }

    unsigned char Coloradjust::getRed() const
    {
        return RGBColor::from32Bit(GetValueAsULong(MUIA_Coloradjust_Red));
    }

    RGBColor Coloradjust::getRGB() const
    {
        auto *rgb = (unsigned long *)GetValueAsPtr(MUIA_Coloradjust_RGB);
        return RGBColor(rgb);
    }

    Coloradjust &Coloradjust::setBlue(const unsigned char blue)
    {
        SetValue(MUIA_Coloradjust_Blue, RGBColor::to32Bit(blue));
        return *this;
    }

    Coloradjust &Coloradjust::setGreen(const unsigned char green)
    {
        SetValue(MUIA_Coloradjust_Green, RGBColor::to32Bit(green));
        return *this;
    }

    Coloradjust &Coloradjust::setModeID(const unsigned long modeID)
    {
        SetValue(MUIA_Coloradjust_ModeID, modeID);
        return *this;
    }

    Coloradjust &Coloradjust::setRed(const unsigned char red)
    {
        SetValue(MUIA_Coloradjust_Red, RGBColor::to32Bit(red));
        return *this;
    }

    Coloradjust &Coloradjust::setRGB(const unsigned char red, const unsigned char green, const unsigned char blue)
    {
        unsigned long rgb[3] = { red, green, blue };
        SetValue(MUIA_Coloradjust_RGB, (void *)rgb);
        return *this;
    }

    Coloradjust &Coloradjust::setRGB(const RGBColor &rgbColor)
    {
        unsigned long rgb[3] = { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
        SetValue(MUIA_Coloradjust_RGB, (void *)rgb);
        return *this;
    }

    ColoradjustBuilder::ColoradjustBuilder() { }
}
