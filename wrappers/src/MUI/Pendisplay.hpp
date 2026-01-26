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

        /// @brief [ @b MUIA_Pendisplay_Pen ]
        unsigned long getPen() const;
        /// @brief [ @b MUIA_Pendisplay_Reference ]
        Object *getReference() const;
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ]
        RGBColor getRGBcolor() const;
        /// @brief [ @b MUIA_Pendisplay_Spec ]
        struct MUI_PenSpec *getSpec() const;

        /// @brief [ @b MUIA_Pendisplay_Reference ]
        Pendisplay &setReference(const Object *reference);
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ]
        Pendisplay &setRGBcolor(const RGBColor &rgbColor);
        /// @brief [ @b MUIA_Pendisplay_Spec ]
        Pendisplay &setSpec(const struct MUI_PenSpec *spec);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Pendisplay_SetColormap ]
        Pendisplay &SetColormap(const long colormap);
        /// @brief [ @b MUIM_Pendisplay_SetMUIPen ]
        Pendisplay &SetMUIPen(const long muipen);
        /// @brief [ @b MUIM_Pendisplay_SetRGB ]
        Pendisplay &SetRGB(const unsigned char red, const unsigned char green, const unsigned char blue);
    };

    template <typename T, typename U> class PendisplayBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        PendisplayBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Pendisplay)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Pendisplay_Reference ]
        /// display exactly this pen, don't allocate one on your own
        T &tagReference(const Object *reference);
        /// @brief [ @b MUIA_Pendisplay_RGBcolor ]
        /// set a pen spec via RGB values
        T &tagRGBcolor(const RGBColor &rgbColor);
        /// @brief [ @b MUIA_Pendisplay_Spec ]
        /// specifies a drawing pen which should be displayed
        T &tagSpec(const struct MUI_PenSpec *spec);
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
