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
            return;

        red = from32Bit(rgb[0]);
        green = from32Bit(rgb[1]);
        blue = from32Bit(rgb[2]);
    }

    unsigned long RGBColor::componentTo32Bit(const unsigned char &component)
    {
        return (unsigned long)component | (unsigned long)component << 8 | (unsigned long)component << 16 | (unsigned long)component << 24;
    }

    unsigned char RGBColor::from32Bit(const unsigned long &component)
    {
        return component >> 24;
    }
}
