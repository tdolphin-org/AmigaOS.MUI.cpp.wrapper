//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "RGBColor.hpp"

namespace MUI
{
    RGBColor::RGBColor(unsigned char red, unsigned char green, unsigned char blue)
      : red(red)
      , green(green)
      , blue(blue)
    {
    }

    RGBColor::RGBColor(unsigned long *rgb)
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
