//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_PENDISPLAY_TPP_INCLUDE
#error "Pendisplay.tpp should only be included by Pendisplay.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &PendisplayBuilderTemplate<T, U>::tagReference(const Object *reference)
    {
        this->PushTag(MUIA_Pendisplay_Reference, reference);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PendisplayBuilderTemplate<T, U>::tagRGBcolor(const RGBColor &rgbColor)
    {
#if MUIMASTER_VMIN >= 20 // MUI5
        MUI_RGBColor rgb { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
#else
        MUI_RGBcolor rgb { rgbColor.red32bit(), rgbColor.green32bit(), rgbColor.blue32bit() };
#endif
        this->PushTag(MUIA_Pendisplay_RGBcolor, &rgb);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PendisplayBuilderTemplate<T, U>::tagSpec(const MUI_PenSpec *spec)
    {
        this->PushTag(MUIA_Pendisplay_Spec, spec);
        return (T &)*this;
    }
}
