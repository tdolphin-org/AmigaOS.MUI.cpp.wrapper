//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Image.hpp"

namespace MUI
{
    const std::string Image::className = MUIC_Image;

    ImageBuilder::ImageBuilder() { }

    Image &Image::setFontMatch(const bool fontMatch)
    {
        SetValue(MUIA_Image_FontMatch, fontMatch);
        return *this;
    }

    Image &Image::setFontMatchHeight(const bool fontMatchHeight)
    {
        SetValue(MUIA_Image_FontMatchHeight, fontMatchHeight);
        return *this;
    }

#ifdef MUIA_Image_FontMatchString
    Image &Image::setFontMatchString(const std::string &fontMatchString)
    {
        SetValue(MUIA_Image_FontMatchString, fontMatchString);
        return *this;
    }
#endif

    Image &Image::setFontMatchWidth(const bool fontMatchWidth)
    {
        SetValue(MUIA_Image_FontMatchWidth, fontMatchWidth);
        return *this;
    }

    Image &Image::setFreeHoriz(const bool freeHoriz)
    {
        SetValue(MUIA_Image_FreeHoriz, freeHoriz);
        return *this;
    }

    Image &Image::setFreeVert(const bool freeVert)
    {
        SetValue(MUIA_Image_FreeVert, freeVert);
        return *this;
    }

#if MUIMASTER_VMIN >= 20 // MUI5
    Image &Image::setSpec(const std::string &spec)
    {
        SetValue(MUIA_Image_Spec, spec);
        return *this;
    }

    Image &Image::setSpec(const enum ImageOrBackground spec)
    {
        SetValue(MUIA_Image_Spec, (long)spec);
        return *this;
    }

    Image &Image::setSpecPicture(const std::string &imagePath)
    {
        SetValue(MUIA_Image_Spec, "5:" + imagePath);
        return *this;
    }

    Image &Image::setSpecColor(const unsigned long rgbColor)
    {
        // FIXME add proper convert rgbColor to "2:RRRRRRRR,GGGGGGGG,BBBBBBBB"
        char colorSpec[29] = { '2', ':', 0, 0, 0, 0, 0, 0, 0, 0, ',', 0, 0, 0, 0, 0, 0, 0, 0, ',', 0, 0, 0, 0, 0, 0, 0, 0, '\0' };
        SetValue(MUIA_Image_Spec, colorSpec);
        return *this;
    }
#endif

    Image &Image::setState(const long state)
    {
        SetValue(MUIA_Image_State, (long)state);
        return *this;
    }
}
