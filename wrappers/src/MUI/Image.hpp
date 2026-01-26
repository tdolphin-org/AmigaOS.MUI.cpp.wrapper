//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Image : public Area
    {
      public:
        explicit Image(Object *pMuiObject)
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
#ifdef MUIA_Image_FontMatchString
        /// @brief [ @b MUIA_Image_FontMatchString ]
        Image &setFontMatchString(const std::string &fontMatchString);
#endif
        /// @brief [ @b MUIA_Image_FontMatchWidth ]
        Image &setFontMatchWidth(const bool fontMatchWidth);
        /// @brief [ @b MUIA_Image_FreeHoriz ]
        Image &setFreeHoriz(const bool freeHoriz);
        /// @brief [ @b MUIA_Image_FreeVert ]
        Image &setFreeVert(const bool freeVert);
#if MUIMASTER_VMIN >= 20 // MUI5
        /// @brief [ @b MUIA_Image_Spec ]
        Image &setSpec(const std::string &spec);
        /// @brief [ @b MUIA_Image_Spec with predefined images (like MUI::ImageOrBackground::ArrowUp) ]
        Image &setSpec(const enum ImageOrBackground spec);
        /// @brief [ @b MUIA_Image_Spec, @b 5:<n> an external picture file that should be loaded with datatypes ]
        Image &setSpecPicture(const std::string &imagePath);
        /// @brief [ @b MUIA_Image_Spec, @b 2:<RGB> RGB color ]
        Image &setSpecColor(const unsigned long rgbColor);
#endif
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

#ifdef MUIA_Image_BuiltinSpec
        /// @brief [ @b MUIA_Image_BuiltinSpec ]
        T &tagBuiltinSpec(const unsigned long builtinSpec);
#endif
#ifdef MUIA_Image_CopySpec
        /// @brief [ @b MUIA_Image_CopySpec ]
        T &tagCopySpec(const bool copySpec);
#endif
        /// @brief [ @b MUIA_Image_FontMatch ]
        T &tagFontMatch(const bool fontMatch);
        /// @brief [ @b MUIA_Image_FontMatchHeight ]
        T &tagFontMatchHeight(const bool fontMatchHeight);
#ifdef MUIA_Image_FontMatchString
        /// @brief [ @b MUIA_Image_FontMatchString ]
        T &tagFontMatchString(const std::string &fontMatchString);
#endif
        /// @brief [ @b MUIA_Image_FontMatchWidth ]
        T &tagFontMatchWidth(const bool fontMatchWidth);
        /// @brief [ @b MUIA_Image_FreeHoriz ]
        /// The image if its allowed to get scaled horizontally. Default is false.
        T &tagFreeHoriz(const bool freeHoriz);
        /// @brief [ @b MUIA_Image_FreeVert ]
        /// The image if its allowed to get scaled vertically. Default is false.
        T &tagFreeVert(const bool freeVert);
        /// @brief [ @b MUIA_Image_OldImage ]
        T &tagOldImage(const ::Image *oldImage);
        /// @brief [ @b MUIA_Image_Spec (also sets MUIA_Image_CopySpec to TRUE) ]
        T &tagSpec(const std::string &spec);
        /// @brief [ @b MUIA_Image_Spec with predefined images (like MUI::ImageOrBackground::ArrowUp) ]
        T &tagSpec(const enum ImageOrBackground spec);
        /// @brief [ @b MUIA_Image_Spec, @b 5:<n> an external picture file that should be loaded with datatypes (also for sets
        /// MUIA_Image_CopySpec to TRUE) ]
        T &tagSpecPicture(const std::string &imagePath);
        /// @brief [ @b MUIA_Image_Spec, @b 2:<RGB> RGB color (also sets MUIA_Image_CopySpec to TRUE) ]
        T &tagSpecColor(const unsigned long rgbColor);
        /// @brief [ @b MUIA_Image_State ]
        T &tagState(const long state);
    };

    class ImageBuilder : public ImageBuilderTemplate<ImageBuilder, Image>
    {
      public:
        ImageBuilder();
    };
}

#define MUI_IMAGE_TPP_INCLUDE
#include "Image.tpp"
#undef MUI_IMAGE_TPP_INCLUDE
