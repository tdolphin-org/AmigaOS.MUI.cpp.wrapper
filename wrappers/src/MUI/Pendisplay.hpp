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
    /// @brief MUI Pendisplay class wrapper.
    /// Pendisplay displays a MUI pen specification and is commonly used as a base for Poppen.
    class Pendisplay : public Area
    {
      public:
        explicit Pendisplay(Object *pMuiObject)
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

        /// @brief [ @b MUIA_Pendisplay_Pen ] Get the currently used pen number for this object.
        unsigned long getPen() const;
        /// @brief [ @b MUIA_Pendisplay_Reference ] Get referenced pendisplay object used as pen source.
        Object *getReference() const;
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ] Get current pen color as RGB components.
        RGBColor getRGBcolor() const;
        /// @brief [ @b MUIA_Pendisplay_Spec ] Get current pen specification structure.
        const struct MUI_PenSpec *getSpec() const;

#ifdef MUIA_Pendisplay_ARGB
        /// @brief [ @b MUIA_Pendisplay_ARGB ] Get packed 32-bit ARGB value (MorphOS MUI5 only).
        unsigned long getARGB() const;
#endif
#ifdef MUIA_Pendisplay_XRGB
        /// @brief [ @b MUIA_Pendisplay_XRGB ] Get packed 32-bit XRGB value (MorphOS MUI5 only).
        unsigned long getXRGB() const;
#endif

        /// @brief [ @b MUIA_Pendisplay_Reference ] Display exactly this reference pen, do not allocate a new one.
        Pendisplay &setReference(const Object *reference);
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ] Set pen color via RGB components.
        Pendisplay &setRGBcolor(const RGBColor &rgbColor);
        /// @brief [ @b MUIA_Pendisplay_Spec ] Set pen specification structure.
        Pendisplay &setSpec(const struct MUI_PenSpec *spec);

#ifdef MUIA_Pendisplay_ARGB
        /// @brief [ @b MUIA_Pendisplay_ARGB ] Set packed 32-bit ARGB value (MorphOS MUI5 only).
        Pendisplay &setARGB(const unsigned long argb);
#endif
#ifdef MUIA_Pendisplay_XRGB
        /// @brief [ @b MUIA_Pendisplay_XRGB ] Set packed 32-bit XRGB value (MorphOS MUI5 only).
        Pendisplay &setXRGB(const unsigned long xrgb);
#endif

        // methods, some returns object reference

        /// @brief [ @b MUIM_Pendisplay_SetColormap ] Switch object to a specific colormap entry.
        Pendisplay &SetColormap(const long colormap);
        /// @brief [ @b MUIM_Pendisplay_SetMUIPen ] Switch object to a specific MUI pen (e.g. MPEN_SHINE).
        Pendisplay &SetMUIPen(const long muipen);
        /// @brief [ @b MUIM_Pendisplay_SetRGB ] Switch object to an RGB color value.
        Pendisplay &SetRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
    };

    template <typename T, typename U> class PendisplayBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        PendisplayBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Pendisplay)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Pendisplay_Reference ] Set initial reference object used as pen source.
        T &tagReference(const Object *reference);
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ] Set initial pen color via RGB values.
        T &tagRGBcolor(const RGBColor &rgbColor);
        /// @brief [ @b MUIA_Pendisplay_Spec ] Set initial pen specification structure.
        T &tagSpec(const struct MUI_PenSpec *spec);

#ifdef MUIA_Pendisplay_ARGB
        /// @brief [ @b MUIA_Pendisplay_ARGB ] Set initial packed ARGB value (MorphOS MUI5 only).
        T &tagARGB(const unsigned long argb);
#endif
#ifdef MUIA_Pendisplay_XRGB
        /// @brief [ @b MUIA_Pendisplay_XRGB ] Set initial packed XRGB value (MorphOS MUI5 only).
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
