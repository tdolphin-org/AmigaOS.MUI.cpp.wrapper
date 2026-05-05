//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

#include "Core/RGBColor.hpp"

namespace MUI
{
    /// @brief Pendisplay class takes a struct MUI_PenSpec and displays it. Its main use is to
    /// be sub-classed by Poppen class which adds a popup window to adjust the MUI_PenSpec.
    /// Poppen class should be used by every application that allows users to configure custom
    /// drawing pens.
    class Pendisplay : public Area
    {
      public:
        explicit Pendisplay(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Pendisplay(const Root &root)
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

        /// @brief [ @b MUIA_Pendisplay_Pen ] Between MUIM_Setup and MUIM_Cleanup, this attribute
        /// returns the pen number MUI uses for color representation of the current pendisplay object.
        /// Returns -1 when outside of MUIM_Setup/MUIM_Cleanup or when the Pendisplay object didn't
        /// allocate a color on its own, e.g. because of MUIA_Pendisplay_Reference.
        unsigned long getPen() const;
        /// @brief [ @b MUIA_Pendisplay_Reference ] Display exactly this pen, don't allocate one
        /// on your own.
        Object *getReference() const;
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ] Get the RGB values of the currently set pen.
        RGBColor getRGBcolor() const;
        /// @brief [ @b MUIA_Pendisplay_Spec ] The black box structure MUI_PenSpec specifies a
        /// drawing pen which should be displayed by Pendisplay class. If you use Poppen class to
        /// allow your users to configure custom drawing pens, its this attribute that you need to
        /// get() and save in your preferences.
        const struct MUI_PenSpec *getSpec() const;

#ifdef MUIA_Pendisplay_ARGB
        /// @brief [ @b MUIA_Pendisplay_ARGB ] Get packed 32-bit ARGB value (MorphOS MUI5 V22 only).
        unsigned long getARGB() const;
#endif
#ifdef MUIA_Pendisplay_XRGB
        /// @brief [ @b MUIA_Pendisplay_XRGB ] Get packed 32-bit XRGB value (MorphOS MUI5 V22 only).
        unsigned long getXRGB() const;
#endif

        /// @brief [ @b MUIA_Pendisplay_Reference ] Display exactly this pen, don't allocate one
        /// on your own.
        Pendisplay &setReference(const Object *reference);
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ] Set a pen spec via RGB values.
        Pendisplay &setRGBcolor(const RGBColor &rgbColor);
        /// @brief [ @b MUIA_Pendisplay_Spec ] The black box structure MUI_PenSpec specifies a
        /// drawing pen which should be displayed by Pendisplay class.
        Pendisplay &setSpec(const struct MUI_PenSpec *spec);

#ifdef MUIA_Pendisplay_ARGB
        /// @brief [ @b MUIA_Pendisplay_ARGB ] Set packed 32-bit ARGB value (MorphOS MUI5 V22 only).
        Pendisplay &setARGB(const unsigned long argb);
#endif
#ifdef MUIA_Pendisplay_XRGB
        /// @brief [ @b MUIA_Pendisplay_XRGB ] Set packed 32-bit XRGB value (MorphOS MUI5 V22 only).
        Pendisplay &setXRGB(const unsigned long xrgb);
#endif

        // methods, some returns object reference

        /// @brief [ @b MUIM_Pendisplay_SetColormap ] Switch the pendisplay object to a specific
        /// colormap entry.
        /// @param colormap colormap number
        Pendisplay &SetColormap(const long colormap);
        /// @brief [ @b MUIM_Pendisplay_SetMUIPen ] Switch the pendisplay object to a specific MUI
        /// pen (MPEN_SHINE, MPEN_SHADOW, ...)
        /// @param muipen MUI pen number
        Pendisplay &SetMUIPen(const long muipen);
        /// @brief [ @b MUIM_Pendisplay_SetRGB ] Switch the pendisplay object to an RGB value.
        /// @param red red color value
        /// @param green green color value
        /// @param blue blue color value
        Pendisplay &SetRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
    };

    template <typename T, typename U> class PendisplayBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        PendisplayBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Pendisplay)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Pendisplay_Reference ] Display exactly this pen, don't allocate one
        /// on your own.
        T &tagReference(const Object *reference);
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ] Set a pen spec via RGB values.
        T &tagRGBcolor(const RGBColor &rgbColor);
        /// @brief [ @b MUIA_Pendisplay_Spec ] The black box structure MUI_PenSpec specifies a
        /// drawing pen which should be displayed by Pendisplay class.
        T &tagSpec(const struct MUI_PenSpec *spec);

#ifdef MUIA_Pendisplay_ARGB
        /// @brief [ @b MUIA_Pendisplay_ARGB ] Set initial packed 32-bit ARGB value (MorphOS MUI5
        /// V22 only).
        T &tagARGB(const unsigned long argb);
#endif
#ifdef MUIA_Pendisplay_XRGB
        /// @brief [ @b MUIA_Pendisplay_XRGB ] Set initial packed 32-bit XRGB value (MorphOS MUI5
        /// V22 only).
        T &tagXRGB(const unsigned long xrgb);
#endif
    };

    class PendisplayBuilder : public PendisplayBuilderTemplate<PendisplayBuilder, Pendisplay>
    {
      public:
        PendisplayBuilder();
    };
}

#define MUI_PENDISPLAY_TPP_INCLUDE
#include "Pendisplay.tpp"
#undef MUI_PENDISPLAY_TPP_INCLUDE
