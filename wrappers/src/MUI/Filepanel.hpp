//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Panel.hpp"

#ifdef MUIC_Filepanel

namespace MUI
{
    /// @brief MUI Filepanel class wrapper.
    /// Full-featured replacement for ASL file requesters with directory history and navigation helpers.
    class Filepanel : public Panel
    {
      public:
        explicit Filepanel(Object *pMuiObject)
          : Panel(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Filepanel_AcceptPattern ] Return parsed DOS accept pattern used to include entries.
        std::string getAcceptPattern() const;
        /// @brief [ @b MUIA_Filepanel_DoMultiSelect ] Query whether selecting multiple files is enabled.
        bool isDoMultiSelect() const;
        /// @brief [ @b MUIA_Filepanel_DoPatterns ] Query whether the pattern gadget is shown.
        bool isDoPatterns() const;
        /// @brief [ @b MUIA_Filepanel_DoSaveMode ] Query whether panel is configured for save mode.
        bool isDoSaveMode() const;
        /// @brief [ @b MUIA_Filepanel_Drawer ] Return current drawer path string.
        std::string getDrawer() const;
        /// @brief [ @b MUIA_Filepanel_DrawersOnly ] Query whether only drawers are listed.
        bool isDrawersOnly() const;
        /// @brief [ @b MUIA_Filepanel_File ] Return current file string.
        std::string getFile() const;
        /// @brief [ @b MUIA_Filepanel_FilterDrawers ] Query whether pattern filters also apply to drawers.
        bool isFilterDrawers() const;
        /// @brief [ @b MUIA_Filepanel_FilterFunc ] Return custom filter hook used for entry filtering.
        Hook *getFilterFunc() const;
        /// @brief [ @b MUIA_Filepanel_Pattern ] Return current wildcard pattern string.
        std::string getPattern() const;
        /// @brief [ @b MUIA_Filepanel_RejectIcons ] Query whether icon files (*.info) are rejected.
        bool isRejectIcons() const;
        /// @brief [ @b MUIA_Filepanel_RejectPattern ] Return parsed DOS reject pattern used to exclude entries.
        std::string getRejectPattern() const;

        /// @brief [ @b MUIA_Filepanel_Drawer ] Set current drawer path string.
        Filepanel &setDrawer(const char *drawer);
        /// @brief [ @b MUIA_Filepanel_Drawer ] Set current drawer path string.
        Filepanel &setDrawer(const std::string &drawer);
        /// @brief [ @b MUIA_Filepanel_File ] Set current file string.
        Filepanel &setFile(const char *file);
        /// @brief [ @b MUIA_Filepanel_File ] Set current file string.
        Filepanel &setFile(const std::string &file);
        /// @brief [ @b MUIA_Filepanel_Pattern ] Set DOS wildcard pattern used for matching filenames.
        Filepanel &setPattern(const char *pattern);
        /// @brief [ @b MUIA_Filepanel_Pattern ] Set DOS wildcard pattern used for matching filenames.
        Filepanel &setPattern(const std::string &pattern);

#ifdef MUIM_Filepanel_AddRow
        /// @brief [ @b MUIM_Filepanel_AddRow ] Add an extra label/value row to the file panel.
        Filepanel &AddRow(const Object *label, const Object *contents);
        /// @brief [ @b MUIM_Filepanel_AddRow ] Add an extra label/value row to the file panel.
        Filepanel &AddRow(const Root &label, const Root &contents);
#endif
    };

    template <typename T, typename U> class FilepanelBuilderTemplate : public PanelBuilderTemplate<T, U>
    {
      public:
        FilepanelBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Filepanel)
          : PanelBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Filepanel_AcceptPattern ] Set parsed DOS accept pattern used to include entries.
        T &tagAcceptPattern(const char *acceptPattern);
        /// @brief [ @b MUIA_Filepanel_AcceptPattern ] Set parsed DOS accept pattern used to include entries.
        T &tagAcceptPattern(const std::string &acceptPattern);
        /// @brief [ @b MUIA_Filepanel_DoMultiSelect ] Enable or disable multiple file selection.
        T &tagDoMultiSelect(const bool doMultiSelect = true);
        /// @brief [ @b MUIA_Filepanel_DoPatterns ] Show or hide the pattern gadget.
        T &tagDoPatterns(const bool doPatterns = true);
        /// @brief [ @b MUIA_Filepanel_DoSaveMode ] Configure panel for save mode.
        T &tagDoSaveMode(const bool doSaveMode = true);
        /// @brief [ @b MUIA_Filepanel_Drawer ] Set initial drawer path string.
        T &tagDrawer(const char *drawer);
        /// @brief [ @b MUIA_Filepanel_Drawer ] Set initial drawer path string.
        T &tagDrawer(const std::string &drawer);
        /// @brief [ @b MUIA_Filepanel_DrawersOnly ] Restrict visible entries to drawers only.
        T &tagDrawersOnly(const bool drawersOnly = true);
        /// @brief [ @b MUIA_Filepanel_File ] Set initial file string.
        T &tagFile(const char *file);
        /// @brief [ @b MUIA_Filepanel_File ] Set initial file string.
        T &tagFile(const std::string &file);
        /// @brief [ @b MUIA_Filepanel_FilterDrawers ] Apply accept/reject/pattern filters to drawers as well.
        T &tagFilterDrawers(const bool filterDrawers = true);
        /// @brief [ @b MUIA_Filepanel_FilterFunc ] Set custom hook used to accept/reject each discovered entry.
        T &tagFilterFunc(const Hook *filterFunc);
        /// @brief [ @b MUIA_Filepanel_Pattern ] Set initial DOS wildcard pattern for filename matching.
        T &tagPattern(const char *pattern);
        /// @brief [ @b MUIA_Filepanel_Pattern ] Set initial DOS wildcard pattern for filename matching.
        T &tagPattern(const std::string &pattern);
        /// @brief [ @b MUIA_Filepanel_RejectIcons ] Enable or disable rejection of icon files (*.info).
        T &tagRejectIcons(const bool rejectIcons = true);
        /// @brief [ @b MUIA_Filepanel_RejectPattern ] Set parsed DOS reject pattern used to exclude entries.
        T &tagRejectPattern(const char *rejectPattern);
        /// @brief [ @b MUIA_Filepanel_RejectPattern ] Set parsed DOS reject pattern used to exclude entries.
        T &tagRejectPattern(const std::string &rejectPattern);
    };

    class FilepanelBuilder : public FilepanelBuilderTemplate<FilepanelBuilder, Filepanel>
    {
      public:
        FilepanelBuilder();
    };
}

#define MUI_FILEPANEL_TPP_INCLUDE
#include "Filepanel.tpp"
#undef MUI_FILEPANEL_TPP_INCLUDE

#endif
