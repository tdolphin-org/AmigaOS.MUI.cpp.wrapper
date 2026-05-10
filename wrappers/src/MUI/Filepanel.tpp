//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_FILEPANEL_TPP_INCLUDE
#error "Filepanel.tpp should only be included by Filepanel.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagAcceptPattern(const char *acceptPattern)
    {
        this->PushTag(MUIA_Filepanel_AcceptPattern,
                      acceptPattern == nullptr ? nullptr : this->StoreString(MUIA_Filepanel_AcceptPattern, acceptPattern));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagAcceptPattern(const std::string &acceptPattern)
    {
        this->PushTag(MUIA_Filepanel_AcceptPattern, this->StoreString(MUIA_Filepanel_AcceptPattern, acceptPattern));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagDoMultiSelect(const bool doMultiSelect)
    {
        this->PushTag(MUIA_Filepanel_DoMultiSelect, doMultiSelect);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagDoPatterns(const bool doPatterns)
    {
        this->PushTag(MUIA_Filepanel_DoPatterns, doPatterns);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagDoSaveMode(const bool doSaveMode)
    {
        this->PushTag(MUIA_Filepanel_DoSaveMode, doSaveMode);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagDrawer(const char *drawer)
    {
        this->PushTag(MUIA_Filepanel_Drawer, drawer == nullptr ? nullptr : this->StoreString(MUIA_Filepanel_Drawer, drawer));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagDrawer(const std::string &drawer)
    {
        this->PushTag(MUIA_Filepanel_Drawer, drawer.empty() ? nullptr : this->StoreString(MUIA_Filepanel_Drawer, drawer));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagDrawersOnly(const bool drawersOnly)
    {
        this->PushTag(MUIA_Filepanel_DrawersOnly, drawersOnly);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagFile(const char *file)
    {
        this->PushTag(MUIA_Filepanel_File, file == nullptr ? nullptr : this->StoreString(MUIA_Filepanel_File, file));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagFile(const std::string &file)
    {
        this->PushTag(MUIA_Filepanel_File, file.empty() ? nullptr : this->StoreString(MUIA_Filepanel_File, file));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagFilterDrawers(const bool filterDrawers)
    {
        this->PushTag(MUIA_Filepanel_FilterDrawers, filterDrawers);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagFilterFunc(const Hook *filterFunc)
    {
        this->PushTag(MUIA_Filepanel_FilterFunc, filterFunc);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagPattern(const char *pattern)
    {
        this->PushTag(MUIA_Filepanel_Pattern, pattern == nullptr ? nullptr : this->StoreString(MUIA_Filepanel_Pattern, pattern));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagPattern(const std::string &pattern)
    {
        this->PushTag(MUIA_Filepanel_Pattern, pattern.empty() ? nullptr : this->StoreString(MUIA_Filepanel_Pattern, pattern));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagRejectIcons(const bool rejectIcons)
    {
        this->PushTag(MUIA_Filepanel_RejectIcons, rejectIcons);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagRejectPattern(const char *rejectPattern)
    {
        this->PushTag(MUIA_Filepanel_RejectPattern,
                      rejectPattern == nullptr ? nullptr : this->StoreString(MUIA_Filepanel_RejectPattern, rejectPattern));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagRejectPattern(const std::string &rejectPattern)
    {
        this->PushTag(MUIA_Filepanel_RejectPattern,
                      rejectPattern.empty() ? nullptr : this->StoreString(MUIA_Filepanel_RejectPattern, rejectPattern));
        return (T &)*this;
    }
}
