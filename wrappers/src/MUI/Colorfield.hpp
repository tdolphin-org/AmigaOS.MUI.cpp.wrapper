//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

#include "Core/RGBColor.hpp"

#include <array>
#include <deque>

namespace MUI
{
    /// @brief MUI Colorfield class wrapper.
    /// Colorfield creates a rectangle filled with a specific color.
    /// The color can be changed at runtime via RGB attributes.
    class Colorfield : public Area
    {
      public:
        explicit Colorfield(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Colorfield(const Root &root)
          : Area(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Colorfield_Blue ] Get the 32-bit blue component of the field color.
        unsigned char getBlue() const;
        /// @brief [ @b MUIA_Colorfield_Green ] Get the 32-bit green component of the field color.
        unsigned char getGreen() const;
        /// @brief [ @b MUIA_Colorfield_Pen ] Get the currently used pen index.
        unsigned long getPen() const;
        /// @brief [ @b MUIA_Colorfield_Red ] Get the 32-bit red component of the field color.
        unsigned char getRed() const;
        /// @brief [ @b MUIA_Colorfield_RGB ] Get all field color components at once as RGB values.
        RGBColor getRGB() const;

        /// @brief [ @b MUIA_Colorfield_Blue ] Set the 32-bit blue component of the field color.
        Colorfield &setBlue(const unsigned char blue);
        /// @brief [ @b MUIA_Colorfield_Green ] Set the 32-bit green component of the field color.
        Colorfield &setGreen(const unsigned char green);
        /// @brief [ @b MUIA_Colorfield_Red ] Set the 32-bit red component of the field color.
        Colorfield &setRed(const unsigned char red);
        /// @brief [ @b MUIA_Colorfield_RGB ] Set all field color components at once from 8-bit RGB values.
        Colorfield &setRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
        /// @brief [ @b MUIA_Colorfield_RGB ] Set all field color components at once from RGBColor.
        Colorfield &setRGB(const RGBColor &rgbColor);
    };

    template <typename T, typename U> class ColorfieldBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      private:
        // Keep RGB triplets alive until object() consumes tag list.
        std::deque<std::array<unsigned long, 3>> mStoredRgbValues;

      public:
        ColorfieldBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Colorfield)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Colorfield_Blue ] Set initial 32-bit blue component.
        T &tagBlue(const unsigned char blue);
        /// @brief [ @b MUIA_Colorfield_Green ] Set initial 32-bit green component.
        T &tagGreen(const unsigned char green);
        /// @brief [ @b MUIA_Colorfield_Red ] Set initial 32-bit red component.
        T &tagRed(const unsigned char red);
        /// @brief [ @b MUIA_Colorfield_RGB ] Set initial color from 8-bit RGB components.
        T &tagRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
        /// @brief [ @b MUIA_Colorfield_RGB ] Set initial color from RGBColor.
        T &tagRGB(const RGBColor &rgbColor);
    };

    class ColorfieldBuilder : public ColorfieldBuilderTemplate<ColorfieldBuilder, Colorfield>
    {
      public:
        ColorfieldBuilder();
    };
}

#define MUI_COLORFIELD_TPP_INCLUDE
#include "Colorfield.tpp"
#undef MUI_COLORFIELD_TPP_INCLUDE
