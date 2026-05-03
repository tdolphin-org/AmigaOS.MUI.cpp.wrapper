//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "List.hpp"

#include "Core/MUICompileConfig.hpp"
#include "ValueTypes/Dirlist/SortDirs.hpp"
#include "ValueTypes/Dirlist/SortType.hpp"
#include "ValueTypes/Dirlist/Status.hpp"

namespace MUI
{
    /// @brief MUI Dirlist class wrapper.
    /// Specialized list class for browsing filesystem entries.
    class Dirlist : public List
    {
      public:
        explicit Dirlist(Object *pMuiObject)
          : List(pMuiObject)
        {
        }

        Dirlist(const Root &root)
          : List(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

#if defined(AOS_MUI_VERSION_5) && defined(MUIA_Dirlist_AcceptPattern)
        /// @brief [ @b MUIA_Dirlist_AcceptPattern ]
        std::string getAcceptPattern() const;
#endif
        /// @brief [ @b MUIA_Dirlist_Directory ]
        std::string getDirectory() const;
#ifdef MUIA_Dirlist_ExAllType
        /// @brief [ @b MUIA_Dirlist_ExAllType ]
        unsigned long getExAllType() const;
#endif
        /// @brief [ @b MUIA_Dirlist_NumBytes ]
        long getNumBytes() const;
#ifdef MUIA_Dirlist_NumBytes64
        /// @brief [ @b MUIA_Dirlist_NumBytes64 ]
        const std::int64_t *getNumBytes64() const;
#endif
        /// @brief [ @b MUIA_Dirlist_NumDrawers ]
        long getNumDrawers() const;
        /// @brief [ @b MUIA_Dirlist_NumFiles ]
        long getNumFiles() const;
        /// @brief [ @b MUIA_Dirlist_Path ]
        std::string getPath() const;
#if defined(AOS_MUI_VERSION_5) && defined(MUIA_Dirlist_RejectPattern)
        /// @brief [ @b MUIA_Dirlist_RejectPattern ]
        std::string getRejectPattern() const;
#endif
        /// @brief [ @b MUIA_Dirlist_Status ]
        long getStatus() const;
        /// @brief [ @b MUIA_Dirlist_Status ]
        Dirlist_Status getStatusType() const;

        /// @brief [ @b MUIA_Dirlist_AcceptPattern ]
        Dirlist &setAcceptPattern(const char *acceptPattern);
        /// @brief [ @b MUIA_Dirlist_AcceptPattern ]
        Dirlist &setAcceptPattern(const std::string &acceptPattern);
        /// @brief [ @b MUIA_Dirlist_Directory ]
        Dirlist &setDirectory(const char *directory);
        /// @brief [ @b MUIA_Dirlist_Directory ]
        Dirlist &setDirectory(const std::string &directory);
        /// @brief [ @b MUIA_Dirlist_DrawersOnly ]
        Dirlist &setDrawersOnly(const bool drawersOnly = true);
        /// @brief [ @b MUIA_Dirlist_FilesOnly ]
        Dirlist &setFilesOnly(const bool filesOnly = true);
        /// @brief [ @b MUIA_Dirlist_FilterDrawers ]
        Dirlist &setFilterDrawers(const bool filterDrawers = true);
        /// @brief [ @b MUIA_Dirlist_FilterHook ]
        Dirlist &setFilterHook(const Hook *pFilterHook);
        /// @brief [ @b MUIA_Dirlist_MultiSelDirs ]
        Dirlist &setMultiSelDirs(const bool multiSelDirs = true);
#ifdef MUIA_Dirlist_Pattern
        /// @brief [ @b MUIA_Dirlist_Pattern ]
        Dirlist &setPattern(const char *pattern);
        /// @brief [ @b MUIA_Dirlist_Pattern ]
        Dirlist &setPattern(const std::string &pattern);
#endif
        /// @brief [ @b MUIA_Dirlist_RejectIcons ]
        Dirlist &setRejectIcons(const bool rejectIcons = true);
        /// @brief [ @b MUIA_Dirlist_RejectPattern ]
        Dirlist &setRejectPattern(const char *rejectPattern);
        /// @brief [ @b MUIA_Dirlist_RejectPattern ]
        Dirlist &setRejectPattern(const std::string &rejectPattern);
        /// @brief [ @b MUIA_Dirlist_SortDirs ]
        Dirlist &setSortDirs(const long sortDirs);
        /// @brief [ @b MUIA_Dirlist_SortDirs ]
        Dirlist &setSortDirs(const enum Dirlist_SortDirs sortDirs);
        /// @brief [ @b MUIA_Dirlist_SortHighLow ]
        Dirlist &setSortHighLow(const bool sortHighLow = true);
        /// @brief [ @b MUIA_Dirlist_SortType ]
        Dirlist &setSortType(const long sortType);
        /// @brief [ @b MUIA_Dirlist_SortType ]
        Dirlist &setSortType(const enum Dirlist_SortType sortType);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Dirlist_ReRead ]
        Dirlist &ReRead();

#ifdef MUIM_Dirlist_Rename
        /// @brief [ @b MUIM_Dirlist_Rename ]
        Dirlist &Rename(const long row, const char *newName);
        /// @brief [ @b MUIM_Dirlist_Rename ]
        Dirlist &Rename(const long row, const std::string &newName);
#endif
#ifdef MUIM_Dirlist_SetComment
        /// @brief [ @b MUIM_Dirlist_SetComment ]
        Dirlist &SetComment(const long row, const char *comment);
        /// @brief [ @b MUIM_Dirlist_SetComment ]
        Dirlist &SetComment(const long row, const std::string &comment);
#endif
#ifdef MUIM_Dirlist_SetProtection
        /// @brief [ @b MUIM_Dirlist_SetProtection ]
        Dirlist &SetProtection(const long row, const unsigned long flags);
#endif
    };

    template <typename T, typename U> class DirlistBuilderTemplate : public ListBuilderTemplate<T, U>
    {
      public:
        DirlistBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Dirlist)
          : ListBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Dirlist_AcceptPattern ]
        T &tagAcceptPattern(const char *acceptPattern);
        /// @brief [ @b MUIA_Dirlist_AcceptPattern ]
        T &tagAcceptPattern(const std::string &acceptPattern);
        /// @brief [ @b MUIA_Dirlist_Directory ]
        T &tagDirectory(const char *directory);
        /// @brief [ @b MUIA_Dirlist_Directory ]
        T &tagDirectory(const std::string &directory);
        /// @brief [ @b MUIA_Dirlist_DrawersOnly ]
        T &tagDrawersOnly(const bool drawersOnly = true);
#ifdef MUIA_Dirlist_ExAllType
        /// @brief [ @b MUIA_Dirlist_ExAllType ]
        T &tagExAllType(const unsigned long exAllType);
#endif
        /// @brief [ @b MUIA_Dirlist_FilesOnly ]
        T &tagFilesOnly(const bool filesOnly = true);
        /// @brief [ @b MUIA_Dirlist_FilterDrawers ]
        T &tagFilterDrawers(const bool filterDrawers = true);
        /// @brief [ @b MUIA_Dirlist_FilterHook ]
        T &tagFilterHook(const Hook *pFilterHook);
        /// @brief [ @b MUIA_Dirlist_MultiSelDirs ]
        T &tagMultiSelDirs(const bool multiSelDirs = true);
#ifdef MUIA_Dirlist_Pattern
        /// @brief [ @b MUIA_Dirlist_Pattern ]
        T &tagPattern(const char *pattern);
        /// @brief [ @b MUIA_Dirlist_Pattern ]
        T &tagPattern(const std::string &pattern);
#endif
        /// @brief [ @b MUIA_Dirlist_RejectIcons ]
        T &tagRejectIcons(const bool rejectIcons = true);
        /// @brief [ @b MUIA_Dirlist_RejectPattern ]
        T &tagRejectPattern(const char *rejectPattern);
        /// @brief [ @b MUIA_Dirlist_RejectPattern ]
        T &tagRejectPattern(const std::string &rejectPattern);
        /// @brief [ @b MUIA_Dirlist_SortDirs ]
        T &tagSortDirs(const long sortDirs);
        /// @brief [ @b MUIA_Dirlist_SortDirs ]
        T &tagSortDirs(const enum Dirlist_SortDirs sortDirs);
        /// @brief [ @b MUIA_Dirlist_SortHighLow ]
        T &tagSortHighLow(const bool sortHighLow = true);
        /// @brief [ @b MUIA_Dirlist_SortType ]
        T &tagSortType(const long sortType);
        /// @brief [ @b MUIA_Dirlist_SortType ]
        T &tagSortType(const enum Dirlist_SortType sortType);
    };

    class DirlistBuilder : public DirlistBuilderTemplate<DirlistBuilder, Dirlist>
    {
      public:
        DirlistBuilder();
    };
}

#define MUI_DIRLIST_TPP_INCLUDE
#include "Dirlist.tpp"
#undef MUI_DIRLIST_TPP_INCLUDE