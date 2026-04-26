//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
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
        auto *rgb = GetValueAsULongPtr(MUIA_Coloradjust_RGB);
        return RGBColor(rgb);
    }

#ifdef MUIA_Coloradjust_Alpha
    unsigned char Coloradjust::getAlpha() const
    {
        return static_cast<unsigned char>(GetValueAsULong(MUIA_Coloradjust_Alpha));
    }
#endif

#ifdef MUIA_Coloradjust_ARGB
    unsigned long Coloradjust::getARGB() const
    {
        return GetValueAsULong(MUIA_Coloradjust_ARGB);
    }
#endif

#ifdef MUIA_Coloradjust_ShowAlpha
    bool Coloradjust::getShowAlpha() const
    {
        return GetValueAsBool(MUIA_Coloradjust_ShowAlpha);
    }
#endif

#ifdef MUIA_Coloradjust_XRGB
    unsigned long Coloradjust::getXRGB() const
    {
        return GetValueAsULong(MUIA_Coloradjust_XRGB);
    }
#endif

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
        unsigned long rgb[3] = { RGBColor::to32Bit(red), RGBColor::to32Bit(green), RGBColor::to32Bit(blue) };
        SetValue(MUIA_Coloradjust_RGB, (void *)rgb);
        return *this;
    }

    Coloradjust &Coloradjust::setRGB(const RGBColor &rgbColor)
    {
        unsigned long rgb[3] = { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
        SetValue(MUIA_Coloradjust_RGB, (void *)rgb);
        return *this;
    }

#ifdef MUIA_Coloradjust_Alpha
    Coloradjust &Coloradjust::setAlpha(const unsigned char alpha)
    {
        SetValue(MUIA_Coloradjust_Alpha, static_cast<unsigned long>(alpha));
        return *this;
    }
#endif

#ifdef MUIA_Coloradjust_ARGB
    Coloradjust &Coloradjust::setARGB(const unsigned long argb)
    {
        SetValue(MUIA_Coloradjust_ARGB, argb);
        return *this;
    }
#endif

#ifdef MUIA_Coloradjust_ShowAlpha
    Coloradjust &Coloradjust::setShowAlpha(const bool showAlpha)
    {
        SetValue(MUIA_Coloradjust_ShowAlpha, showAlpha);
        return *this;
    }
#endif

#ifdef MUIA_Coloradjust_XRGB
    Coloradjust &Coloradjust::setXRGB(const unsigned long xrgb)
    {
        SetValue(MUIA_Coloradjust_XRGB, xrgb);
        return *this;
    }
#endif

    ColoradjustBuilder::ColoradjustBuilder() { }
}
