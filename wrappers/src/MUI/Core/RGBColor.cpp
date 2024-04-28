//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "RGBColor.hpp"

namespace MUI
{
    RGBColor::RGBColor()
      : red(0)
      , green(0)
      , blue(0)
    {
    }

    RGBColor::RGBColor(const unsigned char red, const unsigned char green, const unsigned char blue)
      : red(red)
      , green(green)
      , blue(blue)
    {
    }

    RGBColor::RGBColor(const unsigned long *rgb)
    {
        if (rgb == nullptr)
        {
            red = green = blue = 0;
            return;
        }

        red = from32Bit(rgb[0]);
        green = from32Bit(rgb[1]);
        blue = from32Bit(rgb[2]);
    }

    RGBColor::RGBColor(const MUI_RGBColor &rgbColor)
    {
        red = from32Bit(rgbColor.red);
        green = from32Bit(rgbColor.green);
        blue = from32Bit(rgbColor.blue);
    }

    RGBColor::RGBColor(const unsigned long argb)
    {
        red = (argb & 0x00ff0000) >> 16;
        green = (argb & 0x0000ff00) >> 8;
        blue = (argb & 0x000000ff);
    }

    unsigned long RGBColor::to32Bit(const unsigned char &colorComponent)
    {
        return (unsigned long)colorComponent | (unsigned long)colorComponent << 8 | (unsigned long)colorComponent << 16
            | (unsigned long)colorComponent << 24;
    }

    unsigned char RGBColor::from32Bit(const unsigned long &colorComponent)
    {
        return colorComponent >> 24;
    }
}
