//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Dirlist.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Dirlist::className = MUIC_Dirlist;

    DirlistBuilder::DirlistBuilder() { }

#if defined(AOS_MUI_VERSION_5) && defined(MUIA_Dirlist_AcceptPattern)
    std::string Dirlist::getAcceptPattern() const
    {
        return GetValueAsString(MUIA_Dirlist_AcceptPattern);
    }
#endif

    std::string Dirlist::getDirectory() const
    {
        return GetValueAsString(MUIA_Dirlist_Directory);
    }

#ifdef MUIA_Dirlist_ExAllType
    unsigned long Dirlist::getExAllType() const
    {
        return GetValueAsULong(MUIA_Dirlist_ExAllType);
    }
#endif

    long Dirlist::getNumBytes() const
    {
        return GetValueAsLong(MUIA_Dirlist_NumBytes);
    }

#ifdef MUIA_Dirlist_NumBytes64
    const std::int64_t *Dirlist::getNumBytes64() const
    {
        return static_cast<const std::int64_t *>(GetValueAsPtr(MUIA_Dirlist_NumBytes64));
    }
#endif

    long Dirlist::getNumDrawers() const
    {
        return GetValueAsLong(MUIA_Dirlist_NumDrawers);
    }

    long Dirlist::getNumFiles() const
    {
        return GetValueAsLong(MUIA_Dirlist_NumFiles);
    }

    std::string Dirlist::getPath() const
    {
        return GetValueAsString(MUIA_Dirlist_Path);
    }

#if defined(AOS_MUI_VERSION_5) && defined(MUIA_Dirlist_RejectPattern)
    std::string Dirlist::getRejectPattern() const
    {
        return GetValueAsString(MUIA_Dirlist_RejectPattern);
    }
#endif

    long Dirlist::getStatus() const
    {
        return GetValueAsLong(MUIA_Dirlist_Status);
    }

    Dirlist_Status Dirlist::getStatusType() const
    {
        return static_cast<Dirlist_Status>(GetValueAsLong(MUIA_Dirlist_Status));
    }

    Dirlist &Dirlist::setAcceptPattern(const char *acceptPattern)
    {
        if (acceptPattern == nullptr)
        {
            ClearStoredString(MUIA_Dirlist_AcceptPattern);
            SetValue(MUIA_Dirlist_AcceptPattern, nullptr);
        }
        else
            SetValue(MUIA_Dirlist_AcceptPattern, StoreString(MUIA_Dirlist_AcceptPattern, std::string { acceptPattern }));

        return *this;
    }

    Dirlist &Dirlist::setAcceptPattern(const std::string &acceptPattern)
    {
        SetValue(MUIA_Dirlist_AcceptPattern, StoreString(MUIA_Dirlist_AcceptPattern, acceptPattern));
        return *this;
    }

    Dirlist &Dirlist::setDirectory(const char *directory)
    {
        if (directory == nullptr)
        {
            ClearStoredString(MUIA_Dirlist_Directory);
            SetValue(MUIA_Dirlist_Directory, nullptr);
        }
        else
            SetValue(MUIA_Dirlist_Directory, StoreString(MUIA_Dirlist_Directory, std::string { directory }));

        return *this;
    }

    Dirlist &Dirlist::setDirectory(const std::string &directory)
    {
        SetValue(MUIA_Dirlist_Directory, StoreString(MUIA_Dirlist_Directory, directory));
        return *this;
    }

    Dirlist &Dirlist::setDrawersOnly(const bool drawersOnly)
    {
        SetValue(MUIA_Dirlist_DrawersOnly, drawersOnly);
        return *this;
    }

    Dirlist &Dirlist::setFilesOnly(const bool filesOnly)
    {
        SetValue(MUIA_Dirlist_FilesOnly, filesOnly);
        return *this;
    }

    Dirlist &Dirlist::setFilterDrawers(const bool filterDrawers)
    {
        SetValue(MUIA_Dirlist_FilterDrawers, filterDrawers);
        return *this;
    }

    Dirlist &Dirlist::setFilterHook(const Hook *pFilterHook)
    {
        SetValue(MUIA_Dirlist_FilterHook, pFilterHook);
        return *this;
    }

    Dirlist &Dirlist::setMultiSelDirs(const bool multiSelDirs)
    {
        SetValue(MUIA_Dirlist_MultiSelDirs, multiSelDirs);
        return *this;
    }

#ifdef MUIA_Dirlist_Pattern
    Dirlist &Dirlist::setPattern(const char *pattern)
    {
        if (pattern == nullptr)
        {
            ClearStoredString(MUIA_Dirlist_Pattern);
            SetValue(MUIA_Dirlist_Pattern, nullptr);
        }
        else
            SetValue(MUIA_Dirlist_Pattern, StoreString(MUIA_Dirlist_Pattern, std::string { pattern }));

        return *this;
    }

    Dirlist &Dirlist::setPattern(const std::string &pattern)
    {
        SetValue(MUIA_Dirlist_Pattern, StoreString(MUIA_Dirlist_Pattern, pattern));
        return *this;
    }
#endif

    Dirlist &Dirlist::setRejectIcons(const bool rejectIcons)
    {
        SetValue(MUIA_Dirlist_RejectIcons, rejectIcons);
        return *this;
    }

    Dirlist &Dirlist::setRejectPattern(const char *rejectPattern)
    {
        if (rejectPattern == nullptr)
        {
            ClearStoredString(MUIA_Dirlist_RejectPattern);
            SetValue(MUIA_Dirlist_RejectPattern, nullptr);
        }
        else
            SetValue(MUIA_Dirlist_RejectPattern, StoreString(MUIA_Dirlist_RejectPattern, std::string { rejectPattern }));

        return *this;
    }

    Dirlist &Dirlist::setRejectPattern(const std::string &rejectPattern)
    {
        SetValue(MUIA_Dirlist_RejectPattern, StoreString(MUIA_Dirlist_RejectPattern, rejectPattern));
        return *this;
    }

    Dirlist &Dirlist::setSortDirs(const long sortDirs)
    {
        SetValue(MUIA_Dirlist_SortDirs, sortDirs);
        return *this;
    }

    Dirlist &Dirlist::setSortDirs(const enum Dirlist_SortDirs sortDirs)
    {
        return setSortDirs(static_cast<long>(sortDirs));
    }

    Dirlist &Dirlist::setSortHighLow(const bool sortHighLow)
    {
        SetValue(MUIA_Dirlist_SortHighLow, sortHighLow);
        return *this;
    }

    Dirlist &Dirlist::setSortType(const long sortType)
    {
        SetValue(MUIA_Dirlist_SortType, sortType);
        return *this;
    }

    Dirlist &Dirlist::setSortType(const enum Dirlist_SortType sortType)
    {
        return setSortType(static_cast<long>(sortType));
    }

    Dirlist &Dirlist::ReRead()
    {
        DoMethod(muiObject(), MUIM_Dirlist_ReRead);
        return *this;
    }

#ifdef MUIM_Dirlist_Rename
    Dirlist &Dirlist::Rename(const long row, const char *newName)
    {
        DoMethod(muiObject(), MUIM_Dirlist_Rename, row, newName);
        return *this;
    }

    Dirlist &Dirlist::Rename(const long row, const std::string &newName)
    {
        return Rename(row, newName.c_str());
    }
#endif

#ifdef MUIM_Dirlist_SetComment
    Dirlist &Dirlist::SetComment(const long row, const char *comment)
    {
        DoMethod(muiObject(), MUIM_Dirlist_SetComment, row, comment);
        return *this;
    }

    Dirlist &Dirlist::SetComment(const long row, const std::string &comment)
    {
        return SetComment(row, comment.c_str());
    }
#endif

#ifdef MUIM_Dirlist_SetProtection
    Dirlist &Dirlist::SetProtection(const long row, const unsigned long flags)
    {
        DoMethod(muiObject(), MUIM_Dirlist_SetProtection, row, flags);
        return *this;
    }
#endif
}