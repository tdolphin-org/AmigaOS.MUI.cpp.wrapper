//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Pendisplay.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Pendisplay::className = MUIC_Pendisplay;

    unsigned long Pendisplay::getPen() const
    {
        return GetValueAsULong(MUIA_Pendisplay_Pen);
    }

    Object *Pendisplay::getReference() const
    {
        return GetValueAsObjectPtr(MUIA_Pendisplay_Reference);
    }

    RGBColor Pendisplay::getRGBcolor() const
    {
#ifdef MOS_MUI_VERSION_5
        auto *rgbColor = reinterpret_cast<MUI_RGBColor *>(GetValueAsULongPtr(MUIA_Pendisplay_RGBcolor));
#else
        auto *rgbColor = reinterpret_cast<MUI_RGBcolor *>(GetValueAsULongPtr(MUIA_Pendisplay_RGBcolor));
#endif
        return rgbColor == nullptr ? RGBColor() : RGBColor(*rgbColor);
    }

    const MUI_PenSpec *Pendisplay::getSpec() const
    {
        return GetValueAsConstPenSpecPtr(MUIA_Pendisplay_Spec);
    }

#ifdef MUIA_Pendisplay_ARGB
    unsigned long Pendisplay::getARGB() const
    {
        return GetValueAsULong(MUIA_Pendisplay_ARGB);
    }
#endif

#ifdef MUIA_Pendisplay_XRGB
    unsigned long Pendisplay::getXRGB() const
    {
        return GetValueAsULong(MUIA_Pendisplay_XRGB);
    }
#endif

    Pendisplay &Pendisplay::setReference(const Object *reference)
    {
        SetValue(MUIA_Pendisplay_Reference, reference);
        return *this;
    }

    Pendisplay &Pendisplay::setRGBcolor(const RGBColor &rgbColor)
    {
#ifdef MOS_MUI_VERSION_5
        MUI_RGBColor rgb { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
#else
        MUI_RGBcolor rgb { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
#endif
        SetValue(MUIA_Pendisplay_RGBcolor, &rgb);
        return *this;
    }

    Pendisplay &Pendisplay::setSpec(const MUI_PenSpec *spec)
    {
        SetValue(MUIA_Pendisplay_Spec, spec);
        return *this;
    }

#ifdef MUIA_Pendisplay_ARGB
    Pendisplay &Pendisplay::setARGB(const unsigned long argb)
    {
        SetValue(MUIA_Pendisplay_ARGB, argb);
        return *this;
    }
#endif

#ifdef MUIA_Pendisplay_XRGB
    Pendisplay &Pendisplay::setXRGB(const unsigned long xrgb)
    {
        SetValue(MUIA_Pendisplay_XRGB, xrgb);
        return *this;
    }
#endif

    Pendisplay &Pendisplay::SetColormap(const long colormap)
    {
        DoMethod(muiObject(), MUIM_Pendisplay_SetColormap, colormap);
        return *this;
    }

    Pendisplay &Pendisplay::SetMUIPen(const long muipen)
    {
        DoMethod(muiObject(), MUIM_Pendisplay_SetMUIPen, muipen);
        return *this;
    }

    Pendisplay &Pendisplay::SetRGB(const unsigned char red, const unsigned char green, const unsigned char blue)
    {
        DoMethod(muiObject(), MUIM_Pendisplay_SetRGB, RGBColor::to32Bit(red), RGBColor::to32Bit(green), RGBColor::to32Bit(blue));
        return *this;
    }

    PendisplayBuilder::PendisplayBuilder() { }
}
