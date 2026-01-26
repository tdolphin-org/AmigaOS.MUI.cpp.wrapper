//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_COLORFIELD_TPP_INCLUDE
#error "File Colorfield.tpp can not be included directly, include file Colorfield.hpp instead!"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagBlue(const unsigned char blue)
    {
        this->PushTag(MUIA_Colorfield_Blue, RGBColor::to32Bit(blue));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagGreen(const unsigned char green)
    {
        this->PushTag(MUIA_Colorfield_Green, RGBColor::to32Bit(green));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagRed(const unsigned char red)
    {
        this->PushTag(MUIA_Colorfield_Red, RGBColor::to32Bit(red));
        return (T &)*this;
    }

    template <typename T, typename U>
    inline T &ColorfieldBuilderTemplate<T, U>::tagRGB(const unsigned char red, const unsigned char green, const unsigned char blue)
    {
        unsigned long rgb[3] = { RGBColor::to32Bit(red), RGBColor::to32Bit(green), RGBColor::to32Bit(blue) };
        this->PushTag(MUIA_Colorfield_RGB, rgb);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagRGB(const RGBColor &rgbColor)
    {
        unsigned long rgb[3] = { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
        this->PushTag(MUIA_Colorfield_RGB, rgb);
        return (T &)*this;
    }
}
