//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_DTPIC_TPP_INCLUDE
#error "File Dtpic.tpp can not be included directly, include file Dtpic.hpp instead!"
#endif

namespace MUI
{
#ifdef MUIA_Dtpic_Alpha
    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagAlpha(const long alpha)
    {
        this->PushTag(MUIA_Dtpic_Alpha, alpha);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Dtpic_DarkenSelState
    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagDarkenSelState(const bool darkenSelState)
    {
        this->PushTag(MUIA_Dtpic_DarkenSelState, darkenSelState);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Dtpic_Fade
    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagFade(const long fade)
    {
        this->PushTag(MUIA_Dtpic_Fade, fade);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Dtpic_LightenOnMouse
    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagLightenOnMouse(const bool lightenOnMouse)
    {
        this->PushTag(MUIA_Dtpic_LightenOnMouse, lightenOnMouse);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Dtpic_Name
    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagName(const std::string &name)
    {
        auto copy = this->StoreString(MUIA_Dtpic_Name, name);
        this->PushTag(MUIA_Dtpic_Name, copy);
        return (T &)*this;
    }
#endif
}
