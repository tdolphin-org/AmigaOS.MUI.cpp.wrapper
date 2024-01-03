//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Image : public Area
    {
      public:
        Image(const Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Image(const APTR pMuiObject)
          : Area(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Image_FontMatch ]
        Image &setFontMatch(const bool fontMatch);
        /// @brief [ @b MUIA_Image_FontMatchHeight ]
        Image &setFontMatchHeight(const bool fontMatchHeight);
        /// @brief [ @b MUIA_Image_FontMatchString ]
        Image &setFontMatchString(const std::string &fontMatchString);
        /// @brief [ @b MUIA_Image_FontMatchWidth ]
        Image &setFontMatchWidth(const bool fontMatchWidth);
        /// @brief [ @b MUIA_Image_FreeHoriz ]
        Image &setFreeHoriz(const bool freeHoriz);
        /// @brief [ @b MUIA_Image_FreeVert ]
        Image &setFreeVert(const bool freeVert);
        /// @brief [ @b MUIA_Image_Spec ]
        Image &setSpec(const std::string &spec);
        /// @brief [ @b MUIA_Image_Spec with predefined images (like MUI::ImageOrBackground::ArrowUp) ]
        Image &setSpec(const enum ImageOrBackground spec);
        /// @brief [ @b MUIA_Image_Spec, @b 5:<n> an external picture file that should be loaded with datatypes ]
        Image &setSpecPicture(const std::string &imagePath);
        /// @brief [ @b MUIA_Image_Spec, @b 2:<RGB> RGB color ]
        Image &setSpecColor(const unsigned long rgbColor);
        /// @brief [ @b MUIA_Image_State ]
        Image &setState(const long state);
    };

    template <typename T, typename U> class ImageBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
        std::string spec;
        char colorSpec[29] = { '2', ':', 0, 0, 0, 0, 0, 0, 0, 0, ',', 0, 0, 0, 0, 0, 0, 0, 0, ',', 0, 0, 0, 0, 0, 0, 0, 0, '\0' }; // FIXME

      public:
        ImageBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Image)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Image_BuiltinSpec ]
        T &tagBuiltinSpec(const unsigned long builtinSpec);
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_Image_CopySpec ]
        T &tagCopySpec(const bool copySpec);
#endif
        /// @brief [ @b MUIA_Image_FontMatch ]
        T &tagFontMatch(const bool fontMatch);
        /// @brief [ @b MUIA_Image_FontMatchHeight ]
        T &tagFontMatchHeight(const bool fontMatchHeight);
        /// @brief [ @b MUIA_Image_FontMatchString ]
        T &tagFontMatchString(const std::string &fontMatchString);
        /// @brief [ @b MUIA_Image_FontMatchWidth ]
        T &tagFontMatchWidth(const bool fontMatchWidth);
        /// @brief [ @b MUIA_Image_FreeHoriz ]
        /// The image if its allowed to get scaled horizontally. Default is false.
        T &tagFreeHoriz(const bool freeHoriz);
        /// @brief [ @b MUIA_Image_FreeVert ]
        /// The image if its allowed to get scaled vertically. Default is false.
        T &tagFreeVert(const bool freeVert);
        /// @brief [ @b MUIA_Image_OldImage ]
        T &tagOldImage(const struct Image *oldImage);
        /// @brief [ @b MUIA_Image_Spec (also sets MUIA_Image_CopySpec to TRUE) ]
        T &tagSpec(const std::string &spec);
        /// @brief [ @b MUIA_Image_Spec with predefined images (like MUI::ImageOrBackground::ArrowUp) ]
        T &tagSpec(const enum ImageOrBackground spec);
        /// @brief [ @b MUIA_Image_Spec, @b 5:<n> an external picture file that should be loaded with datatypes (also for sets
        /// MUIA_Image_CopySpec to TRUE) ]
        T &tagSpecPicture(const std::string &imagePath);
        /// @brief [ @b MUIA_Image_Spec, @b 2:<RGB> RGB color (also for sets MUIA_Image_CopySpec to TRUE) ]
        T &tagSpecColor(const unsigned long rgbColor);
        /// @brief [ @b MUIA_Image_State ]
        T &tagState(const long state);
    };

    class ImageBuilder : public ImageBuilderTemplate<ImageBuilder, Image>
    {
      public:
        ImageBuilder();
    };

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagBuiltinSpec(const unsigned long builtinSpec)
    {
        this->PushTag(MUIA_Image_BuiltinSpec, builtinSpec);
        return (T &)*this;
    }

#ifndef __MORPHOS__
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

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagFontMatchString(const std::string &fontMatchString)
    {
        this->PushTag(MUIA_Image_FontMatchString, fontMatchString);
        return (T &)*this;
    }

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

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagOldImage(const Image *oldImage)
    {
        this->PushTag(MUIA_Image_OldImage, oldImage);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagSpec(const std::string &spec)
    {
#ifdef __MORPHOS__
        auto copy = this->StoreString(spec);
        this->PushTag(MUIA_Image_Spec, copy);
#else
        this->PushTag(MUIA_Image_CopySpec, true);
        this->PushTag(MUIA_Image_Spec, spec);
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
#ifdef __MORPHOS__
        auto copy = this->StoreString(spec);
        this->PushTag(MUIA_Image_Spec, copy);
#else
        this->PushTag(MUIA_Image_CopySpec, true);
        this->PushTag(MUIA_Image_Spec, spec);
#endif
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagSpecColor(const unsigned long rgbColor)
    {
        // FIXME add proper convert rgbColor to "2:RRRRRRRR,GGGGGGGG,BBBBBBBB" from rgbColor
#ifdef __MORPHOS__
        auto copy = this->StoreString(colorSpec);
        this->PushTag(MUIA_Image_Spec, copy);
#else
        this->PushTag(MUIA_Image_CopySpec, true);
        this->PushTag(MUIA_Image_Spec, colorSpec);
#endif
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagState(const long state)
    {
        this->PushTag(MUIA_Image_State, state);
        return (T &)*this;
    }
}
