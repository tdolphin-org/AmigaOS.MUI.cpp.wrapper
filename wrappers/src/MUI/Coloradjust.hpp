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
    /// @brief MUI Coloradjust class wrapper.
    /// Coloradjust creates gadgets for adjusting a single color.
    /// Depending on the operating system, different gadget sets can be used.
    class Coloradjust : public Group
    {
      public:
        explicit Coloradjust(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Coloradjust(const Root &root)
          : Group(root.muiObject())
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

        /// @brief [ @b MUIA_Coloradjust_Blue ] Get the 32-bit blue component of the adjusted color.
        unsigned char getBlue() const;
        /// @brief [ @b MUIA_Coloradjust_Green ] Get the 32-bit green component of the adjusted color.
        unsigned char getGreen() const;
        /// @brief [ @b MUIA_Coloradjust_ModeID ] Get the screen mode used to adapt color adjustment behavior.
        unsigned long getModeID() const;
        /// @brief [ @b MUIA_Coloradjust_Red ] Get the 32-bit red component of the adjusted color.
        unsigned char getRed() const;
        /// @brief [ @b MUIA_Coloradjust_RGB ] Get all color components at once as RGB values.
        RGBColor getRGB() const;

#ifdef MUIA_Coloradjust_Alpha
        /// @brief [ @b MUIA_Coloradjust_Alpha ] Get the 8-bit alpha component (MorphOS MUI5 only).
        unsigned char getAlpha() const;
#endif
#ifdef MUIA_Coloradjust_ARGB
        /// @brief [ @b MUIA_Coloradjust_ARGB ] Get packed 32-bit ARGB color value (MorphOS MUI5 only).
        unsigned long getARGB() const;
#endif
#ifdef MUIA_Coloradjust_ShowAlpha
        /// @brief [ @b MUIA_Coloradjust_ShowAlpha ] Query whether alpha controls are visible (MorphOS MUI5 only).
        bool getShowAlpha() const;
#endif
#ifdef MUIA_Coloradjust_XRGB
        /// @brief [ @b MUIA_Coloradjust_XRGB ] Get packed 32-bit XRGB color value (MorphOS MUI5 only).
        unsigned long getXRGB() const;
#endif

        /// @brief [ @b MUIA_Coloradjust_Blue ] Set the 32-bit blue component of the adjusted color.
        Coloradjust &setBlue(const unsigned char blue);
        /// @brief [ @b MUIA_Coloradjust_Green ] Set the 32-bit green component of the adjusted color.
        Coloradjust &setGreen(const unsigned char green);
        /// @brief [ @b MUIA_Coloradjust_ModeID ] Set the screen mode used to adapt color adjustment behavior.
        Coloradjust &setModeID(const unsigned long modeID);
        /// @brief [ @b MUIA_Coloradjust_Red ] Set the 32-bit red component of the adjusted color.
        Coloradjust &setRed(const unsigned char red);
        /// @brief [ @b MUIA_Coloradjust_RGB ] Set all color components at once from 8-bit RGB values.
        Coloradjust &setRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
        /// @brief [ @b MUIA_Coloradjust_RGB ] Set all color components at once from RGBColor.
        Coloradjust &setRGB(const RGBColor &rgbColor);

#ifdef MUIA_Coloradjust_Alpha
        /// @brief [ @b MUIA_Coloradjust_Alpha ] Set the 8-bit alpha component (MorphOS MUI5 only).
        Coloradjust &setAlpha(const unsigned char alpha);
#endif
#ifdef MUIA_Coloradjust_ARGB
        /// @brief [ @b MUIA_Coloradjust_ARGB ] Set packed 32-bit ARGB color value (MorphOS MUI5 only).
        Coloradjust &setARGB(const unsigned long argb);
#endif
#ifdef MUIA_Coloradjust_ShowAlpha
        /// @brief [ @b MUIA_Coloradjust_ShowAlpha ] Show or hide alpha controls (MorphOS MUI5 only).
        Coloradjust &setShowAlpha(const bool showAlpha);
#endif
#ifdef MUIA_Coloradjust_XRGB
        /// @brief [ @b MUIA_Coloradjust_XRGB ] Set packed 32-bit XRGB color value (MorphOS MUI5 only).
        Coloradjust &setXRGB(const unsigned long xrgb);
#endif
    };

    template <typename T, typename U> class ColoradjustBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        ColoradjustBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Coloradjust)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Coloradjust_Blue ] Set initial 32-bit blue component.
        T &tagBlue(const unsigned char blue);
        /// @brief [ @b MUIA_Coloradjust_Green ] Set initial 32-bit green component.
        T &tagGreen(const unsigned char green);
        /// @brief [ @b MUIA_Coloradjust_ModeID ] Set initial screen mode used for color adaptation.
        T &tagModeID(const unsigned long modeID);
        /// @brief [ @b MUIA_Coloradjust_Red ] Set initial 32-bit red component.
        T &tagRed(const unsigned char red);
        /// @brief [ @b MUIA_Coloradjust_RGB ] Set initial color from 8-bit RGB components.
        T &tagRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
        /// @brief [ @b MUIA_Coloradjust_RGB ] Set initial color from RGBColor.
        T &tagRGB(const RGBColor &rgbColor);

#ifdef MUIA_Coloradjust_Alpha
        /// @brief [ @b MUIA_Coloradjust_Alpha ] Set initial alpha component (MorphOS MUI5 only).
        T &tagAlpha(const unsigned char alpha);
#endif
#ifdef MUIA_Coloradjust_ARGB
        /// @brief [ @b MUIA_Coloradjust_ARGB ] Set initial packed ARGB value (MorphOS MUI5 only).
        T &tagARGB(const unsigned long argb);
#endif
#ifdef MUIA_Coloradjust_ShowAlpha
        /// @brief [ @b MUIA_Coloradjust_ShowAlpha ] Set initial alpha visibility (MorphOS MUI5 only).
        T &tagShowAlpha(const bool showAlpha);
#endif
#ifdef MUIA_Coloradjust_XRGB
        /// @brief [ @b MUIA_Coloradjust_XRGB ] Set initial packed XRGB value (MorphOS MUI5 only).
        T &tagXRGB(const unsigned long xrgb);
#endif
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
