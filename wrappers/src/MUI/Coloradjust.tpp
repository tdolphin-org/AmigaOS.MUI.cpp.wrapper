//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_COLORADJUST_TPP_INCLUDE
#error "File Coloradjust.tpp can not be included directly, include file Coloradjust.hpp instead!"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &ColoradjustBuilderTemplate<T, U>::tagBlue(const unsigned char blue)
    {
        this->PushTag(MUIA_Coloradjust_Blue, RGBColor::to32Bit(blue));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColoradjustBuilderTemplate<T, U>::tagGreen(const unsigned char green)
    {
        this->PushTag(MUIA_Coloradjust_Green, RGBColor::to32Bit(green));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColoradjustBuilderTemplate<T, U>::tagModeID(const unsigned long modeID)
    {
        this->PushTag(MUIA_Coloradjust_ModeID, modeID);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColoradjustBuilderTemplate<T, U>::tagRed(const unsigned char red)
    {
        this->PushTag(MUIA_Coloradjust_Red, RGBColor::to32Bit(red));
        return (T &)*this;
    }

    template <typename T, typename U>
    inline T &ColoradjustBuilderTemplate<T, U>::tagRGB(const unsigned char red, const unsigned char green, const unsigned char blue)
    {
        unsigned long rgb[3] = { RGBColor::to32Bit(red), RGBColor::to32Bit(green), RGBColor::to32Bit(blue) };
        this->PushTag(MUIA_Coloradjust_RGB, rgb);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColoradjustBuilderTemplate<T, U>::tagRGB(const RGBColor &rgbColor)
    {
        unsigned long rgb[3] = { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
        this->PushTag(MUIA_Coloradjust_RGB, rgb);
        return (T &)*this;
    }
}
