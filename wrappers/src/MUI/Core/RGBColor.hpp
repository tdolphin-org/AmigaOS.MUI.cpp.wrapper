//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "MUICompileConfig.hpp"

namespace MUI
{
    struct RGBColor
    {
        unsigned char red;
        unsigned char green;
        unsigned char blue;

        RGBColor();
        RGBColor(const unsigned char red, const unsigned char green, const unsigned char blue);
        RGBColor(const unsigned long *rgb);
#ifdef AOS_MUI_VERSION_3_8
        RGBColor(const MUI_RGBcolor &rgbColor);
#else
        RGBColor(const MUI_RGBColor &rgbColor);
#endif
        RGBColor(const unsigned long argb); // 0xAARRGGBB alpha red green blue .. alpha is ignored

        unsigned long red32bit() const
        {
            return to32Bit(red);
        }

        unsigned long green32bit() const
        {
            return to32Bit(green);
        }

        unsigned long blue32bit() const
        {
            return to32Bit(blue);
        }

        unsigned long rgb() const;

        static unsigned long to32Bit(const unsigned char &component);
        static unsigned char from32Bit(const unsigned long &component);
    };
}
