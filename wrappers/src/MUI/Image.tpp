//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_IMAGE_TPP_INCLUDE
#error "Image.tpp should only be included by Image.hpp"
#endif

#include <cstdio>

namespace MUI
{
#ifdef MUIA_Image_BuiltinSpec
    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagBuiltinSpec(const unsigned long builtinSpec)
    {
        this->PushTag(MUIA_Image_BuiltinSpec, builtinSpec);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Image_CopySpec
    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagCopySpec(const bool copySpec /* = true */)
    {
        this->PushTag(MUIA_Image_CopySpec, copySpec);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagFontMatch(const bool fontMatch)
    {
        this->PushTag(MUIA_Image_FontMatch, fontMatch);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagFontMatchHeight(const bool fontMatchHeight)
    {
        this->PushTag(MUIA_Image_FontMatchHeight, fontMatchHeight);
        return (T &)*this;
    }

#ifdef MUIA_Image_FontMatchString
    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagFontMatchString(const std::string &fontMatchString)
    {
        this->PushTag(MUIA_Image_FontMatchString, fontMatchString);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagFontMatchWidth(const bool fontMatchWidth)
    {
        this->PushTag(MUIA_Image_FontMatchWidth, fontMatchWidth);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagFreeHoriz(const bool freeHoriz)
    {
        this->PushTag(MUIA_Image_FreeHoriz, freeHoriz);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagFreeVert(const bool freeVert)
    {
        this->PushTag(MUIA_Image_FreeVert, freeVert);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagOldImage(const ::Image *oldImage)
    {
        this->PushTag(MUIA_Image_OldImage, oldImage);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagSpec(const std::string &spec)
    {
#ifdef MUIA_Image_CopySpec
        this->PushTag(MUIA_Image_CopySpec, true);
        this->PushTag(MUIA_Image_Spec, spec);
#else
        this->PushTag(MUIA_Image_Spec, this->StoreString(MUIA_Image_Spec, spec));
#endif
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagSpec(const enum ImageOrBackground spec)
    {
        this->PushTag(MUIA_Image_Spec, (long)spec);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagSpecPicture(const std::string &imagePath)
    {
        spec = "5:" + imagePath;
#ifdef MUIA_Image_CopySpec
        this->PushTag(MUIA_Image_CopySpec, true);
        this->PushTag(MUIA_Image_Spec, spec);
#else
        this->PushTag(MUIA_Image_Spec, this->StoreString(MUIA_Image_Spec, spec));
#endif
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagSpecColor(const unsigned long rgbColor)
    {
        const unsigned long r8 = (rgbColor >> 16) & 0xff;
        const unsigned long g8 = (rgbColor >> 8) & 0xff;
        const unsigned long b8 = rgbColor & 0xff;

        const unsigned long r32 = r8 * 0x01010101UL;
        const unsigned long g32 = g8 * 0x01010101UL;
        const unsigned long b32 = b8 * 0x01010101UL;

        char colorSpec[29] = { 0 };
        std::snprintf(colorSpec, sizeof(colorSpec), "2:%08lx,%08lx,%08lx", r32, g32, b32);

#ifdef MUIA_Image_CopySpec
        this->PushTag(MUIA_Image_CopySpec, true);
        this->PushTag(MUIA_Image_Spec, colorSpec);
#else
        this->PushTag(MUIA_Image_Spec, this->StoreString(MUIA_Image_Spec, colorSpec));
#endif
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagState(const long state)
    {
        this->PushTag(MUIA_Image_State, state);
        return (T &)*this;
    }
}
