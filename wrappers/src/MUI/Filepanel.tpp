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
        if (acceptPattern == nullptr)
            this->PushTag(MUIA_Filepanel_AcceptPattern, nullptr);
        else
            this->PushTag(MUIA_Filepanel_AcceptPattern, this->StoreString(MUIA_Filepanel_AcceptPattern, std::string { acceptPattern }));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagAcceptPattern(const std::string &acceptPattern)
    {
        auto copy = this->StoreString(MUIA_Filepanel_AcceptPattern, acceptPattern);
        this->PushTag(MUIA_Filepanel_AcceptPattern, copy);
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
        if (drawer == nullptr)
            this->PushTag(MUIA_Filepanel_Drawer, nullptr);
        else
            this->PushTag(MUIA_Filepanel_Drawer, this->StoreString(MUIA_Filepanel_Drawer, std::string { drawer }));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagDrawer(const std::string &drawer)
    {
        auto copy = this->StoreString(MUIA_Filepanel_Drawer, drawer);
        this->PushTag(MUIA_Filepanel_Drawer, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagDrawersOnly(const bool drawersOnly)
    {
        this->PushTag(MUIA_Filepanel_DrawersOnly, drawersOnly);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagFile(const char *file)
    {
        if (file == nullptr)
            this->PushTag(MUIA_Filepanel_File, nullptr);
        else
            this->PushTag(MUIA_Filepanel_File, this->StoreString(MUIA_Filepanel_File, std::string { file }));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagFile(const std::string &file)
    {
        auto copy = this->StoreString(MUIA_Filepanel_File, file);
        this->PushTag(MUIA_Filepanel_File, copy);
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
        if (pattern == nullptr)
            this->PushTag(MUIA_Filepanel_Pattern, nullptr);
        else
            this->PushTag(MUIA_Filepanel_Pattern, this->StoreString(MUIA_Filepanel_Pattern, std::string { pattern }));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagPattern(const std::string &pattern)
    {
        auto copy = this->StoreString(MUIA_Filepanel_Pattern, pattern);
        this->PushTag(MUIA_Filepanel_Pattern, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagRejectIcons(const bool rejectIcons)
    {
        this->PushTag(MUIA_Filepanel_RejectIcons, rejectIcons);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagRejectPattern(const char *rejectPattern)
    {
        if (rejectPattern == nullptr)
            this->PushTag(MUIA_Filepanel_RejectPattern, nullptr);
        else
            this->PushTag(MUIA_Filepanel_RejectPattern, this->StoreString(MUIA_Filepanel_RejectPattern, std::string { rejectPattern }));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FilepanelBuilderTemplate<T, U>::tagRejectPattern(const std::string &rejectPattern)
    {
        auto copy = this->StoreString(MUIA_Filepanel_RejectPattern, rejectPattern);
        this->PushTag(MUIA_Filepanel_RejectPattern, copy);
        return (T &)*this;
    }
}
