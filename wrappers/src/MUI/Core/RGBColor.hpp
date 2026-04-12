//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

#if !defined(MUI_RGBcolor) && !defined(MUI_RGBColor)
// force to define MUI_RGBcolor if neither MUI_RGBColor nor MUI_RGBcolor is defined
// that struct definition is missed in MUI3.8!!! (but is used)
struct MUI_RGBcolor
{
    unsigned long red;
    unsigned long green;
    unsigned long blue;
};
#endif

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
#ifdef MUI_RGBColor
        RGBColor(const MUI_RGBColor &rgbColor);
#else
        RGBColor(const MUI_RGBcolor &rgbColor);
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
