//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Area.hpp"

#include "ValueTypes/RGBColor.hpp"

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
        unsigned long getBlue() const;
        /// @brief [ @b MUIA_Colorfield_Green ]
        unsigned long getGreen() const;
        /// @brief [ @b MUIA_Colorfield_Pen ]
        unsigned long getPen() const;
        /// @brief [ @b MUIA_Colorfield_Red ]
        unsigned long getRed() const;
        /// @brief [ @b MUIA_Colorfield_RGB ]
        RGBColor getRGB() const;

        /// @brief [ @b MUIA_Colorfield_Blue ]
        Colorfield &setBlue(const unsigned long blue);
        /// @brief [ @b MUIA_Colorfield_Green ]
        Colorfield &setGreen(const unsigned long green);
        /// @brief [ @b MUIA_Colorfield_Red ]
        Colorfield &setRed(const unsigned long red);
        /// @brief [ @b MUIA_Colorfield_RGB ]
        Colorfield &setRGB(const unsigned long red, const unsigned long green, const unsigned long blue);
    };

    template <typename T, typename U> class ColorfieldBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        ColorfieldBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Colorfield)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Colorfield_Blue ]
        T &tagBlue(const unsigned long blue);
        /// @brief [ @b MUIA_Colorfield_Green ]
        T &tagGreen(const unsigned long green);
        /// @brief [ @b MUIA_Colorfield_Red ]
        T &tagRed(const unsigned long red);
        /// @brief [ @b MUIA_Colorfield_RGB ]
        T &tagRGB(const unsigned long red, const unsigned long green, const unsigned long blue);
    };

    class ColorfieldBuilder : public ColorfieldBuilderTemplate<ColorfieldBuilder, Colorfield>
    {
      public:
        ColorfieldBuilder();
    };

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagBlue(const unsigned long blue)
    {
        this->PushTag(MUIA_Colorfield_Blue, blue);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagGreen(const unsigned long green)
    {
        this->PushTag(MUIA_Colorfield_Green, green);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ColorfieldBuilderTemplate<T, U>::tagRed(const unsigned long red)
    {
        this->PushTag(MUIA_Colorfield_Red, red);
        return (T &)*this;
    }

    template <typename T, typename U>
    inline T &ColorfieldBuilderTemplate<T, U>::tagRGB(const unsigned long red, const unsigned long green, const unsigned long blue)
    {
        unsigned long rgb[3] = { red, green, blue };
        this->PushTag(MUIA_Colorfield_RGB, rgb);
        return (T &)*this;
    }
}
