//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

#include "Core/RGBColor.hpp"

namespace MUI
{
    class Coloradjust : public Group
    {
      public:
        explicit Coloradjust(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Coloradjust_Blue ]
        unsigned char getBlue() const;
        /// @brief [ @b MUIA_Coloradjust_Green ]
        unsigned char getGreen() const;
        /// @brief [ @b MUIA_Coloradjust_ModeID ]
        unsigned long getModeID() const;
        /// @brief [ @b MUIA_Coloradjust_Red ]
        unsigned char getRed() const;
        /// @brief [ @b MUIA_Coloradjust_RGB ]
        RGBColor getRGB() const;

        /// @brief [ @b MUIA_Coloradjust_Blue ]
        Coloradjust &setBlue(const unsigned char blue);
        /// @brief [ @b MUIA_Coloradjust_Green ]
        Coloradjust &setGreen(const unsigned char green);
        /// @brief [ @b MUIA_Coloradjust_ModeID ]
        Coloradjust &setModeID(const unsigned long modeID);
        /// @brief [ @b MUIA_Coloradjust_Red ]
        Coloradjust &setRed(const unsigned char red);
        /// @brief [ @b MUIA_Coloradjust_RGB ]
        Coloradjust &setRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
        /// @brief [ @b MUIA_Coloradjust_RGB ]
        Coloradjust &setRGB(const RGBColor &rgbColor);
    };

    template <typename T, typename U> class ColoradjustBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        ColoradjustBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Coloradjust)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Coloradjust_Blue ]
        T &tagBlue(const unsigned char blue);
        /// @brief [ @b MUIA_Coloradjust_Green ]
        T &tagGreen(const unsigned char green);
        /// @brief [ @b MUIA_Coloradjust_ModeID ]
        T &tagModeID(const unsigned long modeID);
        /// @brief [ @b MUIA_Coloradjust_Red ]
        T &tagRed(const unsigned char red);
        /// @brief [ @b MUIA_Coloradjust_RGB ]
        T &tagRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
        /// @brief [ @b MUIA_Coloradjust_RGB ]
        T &tagRGB(const RGBColor &rgbColor);
    };

    class ColoradjustBuilder : public ColoradjustBuilderTemplate<ColoradjustBuilder, Coloradjust>
    {
      public:
        ColoradjustBuilder();
    };
}

#define MUI_COLORADJUST_TPP_INCLUDE
#include "Coloradjust.tpp"
#undef MUI_COLORADJUST_TPP_INCLUDE
