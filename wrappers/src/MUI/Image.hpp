//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
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

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, MUIC_Image);
        }
    };

    template <typename T, typename U> class ImageBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        ImageBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Image)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Image_Spec ]
        T &tagSpec(char *spec);
        /// @brief [ @b MUIA_Image_Spec with predefined images (like MUI::ImageOrBackground::ArrowUp) ]
        T &tagSpec(const enum ImageOrBackground spec);
    };

    class ImageBuilder : public ImageBuilderTemplate<ImageBuilder, Image>
    {
      public:
        ImageBuilder();
    };

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagSpec(char *spec)
    {
        this->PushTag(MUIA_Image_Spec, spec);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ImageBuilderTemplate<T, U>::tagSpec(const enum ImageOrBackground spec)
    {
        this->PushTag(MUIA_Image_Spec, (long)spec);
        return (T &)*this;
    }
}
