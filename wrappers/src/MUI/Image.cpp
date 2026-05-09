//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Image.hpp"
#include <cstdio>

namespace
{
    std::string ToImageColorSpec(const unsigned long rgbColor)
    {
        const unsigned long r8 = (rgbColor >> 16) & 0xff;
        const unsigned long g8 = (rgbColor >> 8) & 0xff;
        const unsigned long b8 = rgbColor & 0xff;

        const unsigned long r32 = r8 * 0x01010101UL;
        const unsigned long g32 = g8 * 0x01010101UL;
        const unsigned long b32 = b8 * 0x01010101UL;

        char colorSpec[29] = { 0 };
        std::snprintf(colorSpec, sizeof(colorSpec), "2:%08lx,%08lx,%08lx", r32, g32, b32);
        return std::string { colorSpec };
    }
}

namespace MUI
{
    const std::string Image::className = MUIC_Image;

    ImageBuilder::ImageBuilder() { }

#ifdef MOS_MUI_VERSION_5
    // MUIA_Image_Spec is isg (gettable) only on MorphOS MUI 5.0
    std::string Image::getSpec() const
    {
        return GetValueAsString(MUIA_Image_Spec);
    }

    // MUIA_Image_BuiltinSpec is isg (gettable) only on MorphOS MUI 5.0
    unsigned long Image::getBuiltinSpec() const
    {
        return GetValueAsULong(MUIA_Image_BuiltinSpec);
    }
#endif // MOS_MUI_VERSION_5

#if defined(AOS_MUI_VERSION_5)
    Image &Image::setFontMatch(const bool fontMatch)
    {
        SetValue(MUIA_Image_FontMatch, fontMatch);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5)
    Image &Image::setFontMatchHeight(const bool fontMatchHeight)
    {
        SetValue(MUIA_Image_FontMatchHeight, fontMatchHeight);
        return *this;
    }
#endif

#ifdef MUIA_Image_FontMatchString
    Image &Image::setFontMatchString(const std::string &fontMatchString)
    {
        SetValue(MUIA_Image_FontMatchString, fontMatchString);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5)
    Image &Image::setFontMatchWidth(const bool fontMatchWidth)
    {
        SetValue(MUIA_Image_FontMatchWidth, fontMatchWidth);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5)
    Image &Image::setFreeHoriz(const bool freeHoriz)
    {
        SetValue(MUIA_Image_FreeHoriz, freeHoriz);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5)
    Image &Image::setFreeVert(const bool freeVert)
    {
        SetValue(MUIA_Image_FreeVert, freeVert);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Image &Image::setSpec(const std::string &spec)
    {
        SetValue(MUIA_Image_Spec, StoreString(MUIA_Image_Spec, spec));
        return *this;
    }

#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Image &Image::setSpec(const enum ImageOrBackground spec)
    {
        SetValue(MUIA_Image_Spec, (long)spec);
        return *this;
    }

#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Image &Image::setSpecPicture(const std::string &imagePath)
    {
        const std::string spec = "5:" + imagePath;
        SetValue(MUIA_Image_Spec, StoreString(MUIA_Image_Spec, spec));
        return *this;
    }

#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Image &Image::setSpecColor(const unsigned long rgbColor)
    {
        const std::string spec = ToImageColorSpec(rgbColor);
        SetValue(MUIA_Image_Spec, StoreString(MUIA_Image_Spec, spec));
        return *this;
    }
#endif

#ifdef MOS_MUI_VERSION_5
#ifdef MUIA_Image_BuiltinSpec
    Image &Image::setBuiltinSpec(const unsigned long builtinSpec)
    {
        SetValue(MUIA_Image_BuiltinSpec, builtinSpec);
        return *this;
    }
#endif
#endif

    Image &Image::setState(const long state)
    {
        SetValue(MUIA_Image_State, (long)state);
        return *this;
    }
}
