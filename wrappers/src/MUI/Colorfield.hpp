//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Area.hpp"

#include "Core/RGBColor.hpp"

namespace MUI
{
    class Colorfield : public Area
    {
      public:
        Colorfield(const Object *pMuiObject)
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

        /// @brief [ @b MUIA_Colorfield_Blue ]
        unsigned char getBlue() const;
        /// @brief [ @b MUIA_Colorfield_Green ]
        unsigned char getGreen() const;
        /// @brief [ @b MUIA_Colorfield_Pen ]
        unsigned long getPen() const;
        /// @brief [ @b MUIA_Colorfield_Red ]
        unsigned char getRed() const;
        /// @brief [ @b MUIA_Colorfield_RGB ]
        RGBColor getRGB() const;

        /// @brief [ @b MUIA_Colorfield_Blue ]
        Colorfield &setBlue(const unsigned char blue);
        /// @brief [ @b MUIA_Colorfield_Green ]
        Colorfield &setGreen(const unsigned char green);
        /// @brief [ @b MUIA_Colorfield_Red ]
        Colorfield &setRed(const unsigned char red);
        /// @brief [ @b MUIA_Colorfield_RGB ]
        Colorfield &setRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
        /// @brief [ @b MUIA_Colorfield_RGB ]
        Colorfield &setRGB(const RGBColor &rgbColor);
    };

    template <typename T, typename U> class ColorfieldBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        ColorfieldBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Colorfield)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Colorfield_Blue ]
        T &tagBlue(const unsigned char blue);
        /// @brief [ @b MUIA_Colorfield_Green ]
        T &tagGreen(const unsigned char green);
        /// @brief [ @b MUIA_Colorfield_Red ]
        T &tagRed(const unsigned char red);
        /// @brief [ @b MUIA_Colorfield_RGB ]
        T &tagRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
        /// @brief [ @b MUIA_Colorfield_RGB ]
        T &tagRGB(const RGBColor &rgbColor);
    };

    class ColorfieldBuilder : public ColorfieldBuilderTemplate<ColorfieldBuilder, Colorfield>
    {
      public:
        ColorfieldBuilder();
    };

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagBlue(const unsigned char blue)
    {
        this->PushTag(MUIA_Colorfield_Blue, RGBColor::componentTo32Bit(blue));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagGreen(const unsigned char green)
    {
        this->PushTag(MUIA_Colorfield_Green, RGBColor::componentTo32Bit(green));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagRed(const unsigned char red)
    {
        this->PushTag(MUIA_Colorfield_Red, RGBColor::componentTo32Bit(red));
        return (T &)*this;
    }

    template <typename T, typename U>
    inline T &ColorfieldBuilderTemplate<T, U>::tagRGB(const unsigned char red, const unsigned char green, const unsigned char blue)
    {
        unsigned long rgb[3] = { RGBColor::componentTo32Bit(red), RGBColor::componentTo32Bit(green), RGBColor::componentTo32Bit(blue) };
        this->PushTag(MUIA_Colorfield_RGB, rgb);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagRGB(const RGBColor &rgbColor)
    {
        unsigned long rgb[3] = { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
        this->PushTag(MUIA_Colorfield_RGB, rgb);
        return (T &)*this;
    }
}
