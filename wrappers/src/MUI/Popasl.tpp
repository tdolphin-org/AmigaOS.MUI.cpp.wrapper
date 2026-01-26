//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_POPASL_TPP_INCLUDE
#error "Popasl.tpp should only be included by Popasl.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagStartHook(const Hook *startHook)
    {
        this->PushTag(MUIA_Popasl_StartHook, startHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagStopHook(const Hook *stopHook)
    {
        this->PushTag(MUIA_Popasl_StopHook, stopHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagType(const unsigned long type)
    {
        this->PushTag(MUIA_Popasl_Type, type);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrTitleText(const char *titleText)
    {
        this->PushTag(ASLFR_TitleText, titleText);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrTitleText(const std::string &titleText)
    {
        this->PushTag(ASLFR_TitleText, titleText);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrDoPatterns(const bool doPatterns)
    {
        this->PushTag(ASLFR_DoPatterns, doPatterns);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrDrawersOnly(const bool drawersOnly)
    {
        this->PushTag(ASLFR_DrawersOnly, drawersOnly);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrRejectIcons(const bool rejectIcons)
    {
        this->PushTag(ASLFR_RejectIcons, rejectIcons);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrRejectPattern(const std::string &rejectPattern)
    {
        this->PushTag(ASLFR_RejectPattern, rejectPattern);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrAcceptPattern(const std::string &acceptPattern)
    {
        this->PushTag(ASLFR_AcceptPattern, acceptPattern);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrFilterDrawers(const bool filterDrawers)
    {
        this->PushTag(ASLFR_FilterDrawers, filterDrawers);
        return (T &)*this;
    }
}
