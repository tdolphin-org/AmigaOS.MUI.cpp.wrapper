//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_DIRLIST_TPP_INCLUDE
#error "Do not include Dirlist.tpp directly! It is included by Dirlist.hpp."
#endif

namespace MUI
{
    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagAcceptPattern(const char *acceptPattern)
    {
        if (acceptPattern != nullptr)
            this->PushTag(MUIA_Dirlist_AcceptPattern, this->StoreString(MUIA_Dirlist_AcceptPattern, std::string { acceptPattern }));
        else
            this->PushTag(MUIA_Dirlist_AcceptPattern, 0);

        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagAcceptPattern(const std::string &acceptPattern)
    {
        this->PushTag(MUIA_Dirlist_AcceptPattern, this->StoreString(MUIA_Dirlist_AcceptPattern, acceptPattern));
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagDirectory(const char *directory)
    {
        if (directory != nullptr)
            this->PushTag(MUIA_Dirlist_Directory, this->StoreString(MUIA_Dirlist_Directory, std::string { directory }));
        else
            this->PushTag(MUIA_Dirlist_Directory, 0);

        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagDirectory(const std::string &directory)
    {
        this->PushTag(MUIA_Dirlist_Directory, this->StoreString(MUIA_Dirlist_Directory, directory));
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagDrawersOnly(const bool drawersOnly)
    {
        this->PushTag(MUIA_Dirlist_DrawersOnly, drawersOnly);
        return (T &)*this;
    }

#ifdef MUIA_Dirlist_ExAllType
    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagExAllType(const unsigned long exAllType)
    {
        this->PushTag(MUIA_Dirlist_ExAllType, exAllType);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagFilesOnly(const bool filesOnly)
    {
        this->PushTag(MUIA_Dirlist_FilesOnly, filesOnly);
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagFilterDrawers(const bool filterDrawers)
    {
        this->PushTag(MUIA_Dirlist_FilterDrawers, filterDrawers);
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagFilterHook(const Hook *pFilterHook)
    {
        this->PushTag(MUIA_Dirlist_FilterHook, pFilterHook);
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagMultiSelDirs(const bool multiSelDirs)
    {
        this->PushTag(MUIA_Dirlist_MultiSelDirs, multiSelDirs);
        return (T &)*this;
    }

#ifdef MUIA_Dirlist_Pattern
    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagPattern(const char *pattern)
    {
        if (pattern != nullptr)
            this->PushTag(MUIA_Dirlist_Pattern, this->StoreString(MUIA_Dirlist_Pattern, std::string { pattern }));
        else
            this->PushTag(MUIA_Dirlist_Pattern, 0);

        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagPattern(const std::string &pattern)
    {
        this->PushTag(MUIA_Dirlist_Pattern, this->StoreString(MUIA_Dirlist_Pattern, pattern));
        return (T &)*this;
    }
#endif

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagRejectIcons(const bool rejectIcons)
    {
        this->PushTag(MUIA_Dirlist_RejectIcons, rejectIcons);
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagRejectPattern(const char *rejectPattern)
    {
        if (rejectPattern != nullptr)
            this->PushTag(MUIA_Dirlist_RejectPattern, this->StoreString(MUIA_Dirlist_RejectPattern, std::string { rejectPattern }));
        else
            this->PushTag(MUIA_Dirlist_RejectPattern, 0);

        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagRejectPattern(const std::string &rejectPattern)
    {
        this->PushTag(MUIA_Dirlist_RejectPattern, this->StoreString(MUIA_Dirlist_RejectPattern, rejectPattern));
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagSortDirs(const long sortDirs)
    {
        this->PushTag(MUIA_Dirlist_SortDirs, sortDirs);
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagSortDirs(const enum Dirlist_SortDirs sortDirs)
    {
        return tagSortDirs(static_cast<long>(sortDirs));
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagSortHighLow(const bool sortHighLow)
    {
        this->PushTag(MUIA_Dirlist_SortHighLow, sortHighLow);
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagSortType(const long sortType)
    {
        this->PushTag(MUIA_Dirlist_SortType, sortType);
        return (T &)*this;
    }

    template <typename T, typename U> T &DirlistBuilderTemplate<T, U>::tagSortType(const enum Dirlist_SortType sortType)
    {
        return tagSortType(static_cast<long>(sortType));
    }
}