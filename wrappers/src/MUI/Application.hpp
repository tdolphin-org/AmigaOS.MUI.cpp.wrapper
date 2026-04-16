//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Core/ObjectScope.hpp"
#include "Notify.hpp"

namespace MUI
{
    class Window;
    class Menustrip;

    class Application : public Notify
    {
      public:
        explicit Application(Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Application_Active ]
        /// This attribute reflects the state that the user adjusted with commodities Exchange.
        bool isActive() const;
        /// @brief [ @b MUIA_Application_Author ]
        /// Name of the application's author.
        std::string getAuthor() const;
        /// @brief [ @b MUIA_Application_Base ]
        /// Basename of the application used for the built in ARexx port and some internal file management.
        std::string getBase() const;
        /// @brief [ @b MUIA_Application_Copyright ]
        /// Copyright string containing the year and the company.
        std::string getCopyright() const;
        /// @brief [ @b MUIA_Application_Description ]
        /// Short description, about 40 characters, shown e.g. in commodities exchange.
        std::string getDescription() const;
        /// @brief [ @b MUIA_Application_DiskObject ]
        /// Pointer to DiskObject used for the AppIcon when the application is iconified.
        const DiskObject *getDiskObject() const;
        /// @brief [ @b MUIA_Application_DoubleStart ]
        /// True if the user tried to start a single task application twice.
        bool isDoubleStart() const;
        /// @brief [ @b MUIA_Application_ForceQuit ]
        /// True if the application should exit quietly without additional safety requesters.
        bool isForceQuit() const;
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// AmigaGuide style help file used for online help.
        std::string getHelpFile() const;
        /// @brief [ @b MUIA_Application_Iconified ]
        /// True if the application is currently iconified.
        bool isIconified() const;
        /// @brief [ @b MUIA_Application_IconifyTitle ]
        /// Alternative title used for the iconification icon and/or menu.
        std::string getIconifyTitle() const;
        /// @brief [ @b MUIA_Application_MenuAction ]
        /// Returns UserData of the selected menu item.
        unsigned long getMenuAction() const;
        /// @brief [ @b MUIA_Application_MenuHelp ]
        /// Returns UserData of the menu item selected with the help key.
        unsigned long getMenuHelp() const;
        /// @brief [ @b MUIA_Application_Menustrip ]
        /// Returns raw menustrip object pointer.
        Object *getMenustripObject() const;
        /// @brief [ @b MUIA_Application_Menustrip ]
        /// Returns menustrip wrapper.
        Menustrip getMenustrip() const;
        /// @brief [ @b MUIA_Application_Sleep ]
        /// True if the application is currently sleeping.
        bool isSleep() const;
        /// @brief [ @b MUIA_Application_Title ]
        /// Title of the application.
        std::string getTitle() const;
#ifdef MUIA_Application_UsedClasses
        /// @brief [ @b MUIA_Application_UsedClasses ]
        /// NULL terminated list of external custom classes used by the application.
        std::vector<std::string> getUsedClasses() const;
#endif
        /// @brief [ @b MUIA_Application_Version ]
        /// Version string of the application.
        std::string getVersion() const;
        /// @brief [ @b MUIA_Application_WindowList ]
        /// Read only exec list containing the child windows of the application.
        std::vector<Window> getWindowList() const;

        /// @brief [ @b MUIA_Application_DiskObject ]
        /// Provide DiskObject used for the AppIcon when the application becomes iconified.
        Application &setDiskObject(const DiskObject &diskObject);
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// Define an AmigaGuide style file to be displayed when the user requests online help.
        Application &setHelpFile(const char *helpFile);
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// Define an AmigaGuide style file to be displayed when the user requests online help.
        Application &setHelpFile(const std::string &helpFile);
        /// @brief [ @b MUIA_Application_Iconified ]
        /// Set whether the application is iconified.
        Application &setIconified(const bool iconified);
        /// @brief [ @b MUIA_Application_IconifyTitle ]
        /// Use a different name than the application title for the iconification icon and/or menu.
        Application &setIconifyTitle(const char *iconifyTitle);
        /// @brief [ @b MUIA_Application_IconifyTitle ]
        /// Use a different name than the application title for the iconification icon and/or menu.
        Application &setIconifyTitle(const std::string &iconifyTitle);
        /// @brief [ @b MUIA_Application_RexxString ]
        /// Return an ARexx result string from within an ARexx callback hook.
        Application &setRexxString(const char *rexxString);
        /// @brief [ @b MUIA_Application_RexxString ]
        /// Return an ARexx result string from within an ARexx callback hook.
        Application &setRexxString(const std::string &rexxString);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Application_AboutMUI ]
        /// Show the MUI about window. If non-NULL, the window is centered according to the given MUI window object.
#ifdef MUIWindow
        Application &AboutMUI(const MUIWindow *refwindow = nullptr);
#else
        Application &AboutMUI(const Object *refwindow = nullptr);
#endif
        /// @brief [ @b MUIM_Application_AddInputHandler ]
        /// Register an input handler node so MUI can notify an object when signals or timer events arrive.
        Application &AddInputHandler(const struct MUI_InputHandlerNode *ihnode);
        /// @brief [ @b MUIM_Application_BuildSettingsPanel ]
        /// Implement this method if the application provides built in settings panels.
        Application &BuildSettingsPanel(const unsigned long number);
        /// @brief [ @b MUIM_Application_CheckRefresh ]
        /// Refresh all open windows that currently need refreshing.
        Application &CheckRefresh();
        /// @brief [ @b MUIM_Application_DefaultConfigItem ]
        /// Override this to return sensible default values for application specific config items.
        Application &DefaultConfigItem(const unsigned long cfgid);
        /// @brief [ @b MUIM_Application_Execute ]
        /// Execute the ideal main loop of a MUI application.
        long Execute() const;
        /// @brief [ @b MUIM_Application_Input ]
        /// Process pending GUI input and update the supplied signal mask.
        Application &Input(const unsigned long *signal);
        /// @brief [ @b MUIM_Application_InputBuffered ]
        /// Process GUI related actions without consuming queued return IDs.
        Application &InputBuffered();
        /// @brief [ @b MUIM_Application_Load ]
        /// Load application settings from the given file or magic cookie.
        Application &Load(const char *name);
        /// @brief [ @b MUIM_Application_Load ]
        /// Load application settings from the given file or magic cookie.
        Application &Load(const std::string &name);
        /// @brief [ @b MUIM_Application_Load, @b MUIV_Application_Load_ENVARC ]
        /// Load application settings from ENVARC:mui/.
        Application &LoadEnvArc();
        /// @brief [ @b MUIM_Application_NewInput ]
        /// Enhanced replacement for MUIM_Application_Input which expects the previous Wait() result in signal.
        long NewInput(unsigned long *signal) const;
        /// @brief [ @b MUIM_Application_OpenConfigWindow ]
        /// Open the application's MUI configuration window.
        Application &OpenConfigWindow();
        /// @brief [ @b MUIM_Application_OpenConfigWindow ]
        /// Open the application's MUI configuration window with explicit flags and class id.
        Application &OpenConfigWindow(const unsigned long flags, char *classid);
        /// @brief [ @b MUIM_Application_PushMethod ]
        /// Schedule a method to be executed later in the application's task context.
        template <typename... Args> unsigned long PushMethod(const Object *dest, Args... args)
        {
            return DoMethod(muiObject(), MUIM_Application_PushMethod, dest, (long)sizeof...(Args), args...);
        }
        /// @brief [ @b MUIM_Application_RemInputHandler ]
        /// Remove a previously registered input handler node.
        Application &RemInputHandler(const struct MUI_InputHandlerNode *ihnode);
        /// @brief [ @b MUIM_Application_ReturnID ]
        /// Queue a return id for the next non-buffered input call.
        Application &ReturnID(const unsigned long retid);
        /// @brief [ @b MUIM_Application_Run ]
        /// Execute the ideal main loop of a MUI application.
        long Run() const;
        /// @brief [ @b MUIM_Application_Save ]
        /// Save application settings to the given file or magic cookie.
        Application &Save(const char *name);
        /// @brief [ @b MUIM_Application_Save ]
        /// Save application settings to the given file or magic cookie.
        Application &Save(const std::string &name);
        /// @brief [ @b MUIM_Application_Save, @b MUIV_Application_Save_ENVARC ]
        /// Save application settings to ENVARC:mui/.
        Application &SaveEnvArc();
        /// @brief [ @b MUIM_Application_ShowHelp ]
        /// Display an AmigaGuide help file and optionally jump to a node and line.
        Application &ShowHelp(const Object *window, const char *name, const char *node, const long line);
        /// @brief [ @b MUIM_Application_UnpushMethod ]
        /// Remove queued methods previously scheduled with MUIM_Application_PushMethod.
        unsigned long UnpushMethod(const Object *targetobj = nullptr, const unsigned long methodid = 0, const unsigned long method = 0);
        /// @brief [ @b MUIA_Application_Sleep, @b TRUE ]
        /// Put the whole application to sleep. Open windows are disabled and a busy pointer appears.
        Application &Sleep();
        /// @brief [ @b MUIA_Application_Sleep, @b FALSE ]
        /// Wake up a previously sleeping application.
        Application &WakeUp();

        /// @brief [ @b OM_ADDMEMBER ]
        /// Add a window as child of the application.
        Application &AddMember(const Window &window);
        /// @brief [ @b OM_REMMEMBER ]
        /// Remove a child window from the application.
        /// After disconnecting a window from an application you still need to dispose that child object explicitly.
        Application &RemMember(const Window &window);
    };

    class ApplicationBuilder : public NotifyBuilderTemplate<ApplicationBuilder, Application>
    {
      public:
        ApplicationBuilder();

        /// @brief [ @b MUIA_Application_Author ]
        /// Name of the application's author.
        ApplicationBuilder &tagAuthor(const char *author);
        /// @brief [ @b MUIA_Application_Author ]
        /// Name of the application's author.
        ApplicationBuilder &tagAuthor(const std::string &author);
        /// @brief [ @b MUIA_Application_Base ]
        /// Basename used for the built in ARexx port and internal file management.
        ApplicationBuilder &tagBase(const char *base);
        /// @brief [ @b MUIA_Application_Base ]
        /// Basename used for the built in ARexx port and internal file management.
        ApplicationBuilder &tagBase(const std::string &base);
        /// @brief [ @b MUIA_Application_Copyright ]
        /// Copyright string containing the year and the company.
        ApplicationBuilder &tagCopyright(const char *copyright);
        /// @brief [ @b MUIA_Application_Copyright ]
        /// Copyright string containing the year and the company.
        ApplicationBuilder &tagCopyright(const std::string &copyright);
        /// @brief [ @b MUIA_Application_Description ]
        /// Short description, about 40 characters, shown e.g. in commodities exchange.
        ApplicationBuilder &tagDescription(const char *description);
        /// @brief [ @b MUIA_Application_Description ]
        /// Short description, about 40 characters, shown e.g. in commodities exchange.
        ApplicationBuilder &tagDescription(const std::string &description);
        /// @brief [ @b MUIA_Application_DiskObject ]
        /// DiskObject used for the AppIcon when the application becomes iconified.
        ApplicationBuilder &tagDiskObject(const DiskObject &diskObject);
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// Define an AmigaGuide style file to be displayed when the user requests online help.
        ApplicationBuilder &tagHelpFile(const char *helpFile);
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// Define an AmigaGuide style file to be displayed when the user requests online help.
        ApplicationBuilder &tagHelpFile(const std::string &helpFile);
        /// @brief [ @b MUIA_Application_IconifyTitle ]
        /// Alternative name used for the iconification icon and/or menu.
        ApplicationBuilder &tagIconifyTitle(const char *iconifyTitle);
        /// @brief [ @b MUIA_Application_IconifyTitle ]
        /// Alternative name used for the iconification icon and/or menu.
        ApplicationBuilder &tagIconifyTitle(const std::string &iconifyTitle);
        /// @brief [ @b MUIA_Application_Menustrip ]
        /// Menu strip shared by all windows of the application that do not define a private menu.
        ApplicationBuilder &tagMenustrip(const Menustrip &menustrip);
        /// @brief [ @b MUIA_Application_SingleTask ]
        /// Indicate whether the application is a single task program.
        ApplicationBuilder &tagSingleTask(const bool singleTask);
        /// @brief [ @b MUIA_Application_Title ]
        /// Title of the application. It should be unique and must not contain version information.
        ApplicationBuilder &tagTitle(const char *title);
        /// @brief [ @b MUIA_Application_Title ]
        /// Title of the application. It should be unique and must not contain version information.
        ApplicationBuilder &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Application_UseCommodities ]
        /// When false, the application runs without a commodities interface.
        ApplicationBuilder &tagUseCommodities(const bool useCommodities);
#ifdef MUIA_Application_UsedClasses
        /// @brief [ @b MUIA_Application_UsedClasses ]
        /// NULL terminated array listing external custom classes used by the application.
        ApplicationBuilder &tagUsedClasses(char *usedClasses[]);
#endif
        /// @brief [ @b MUIA_Application_UseRexx ]
        /// When false, the application runs without an ARexx interface.
        ApplicationBuilder &tagUseRexx(const bool useRexx);
        /// @brief [ @b MUIA_Application_UseScreenNotify ]
        /// When false, windows are not automatically closed and reopened while the Workbench screen is closing.
        ApplicationBuilder &tagUseScreenNotify(const bool useScreenNotify);
        /// @brief [ @b MUIA_Application_Version ]
        /// Define application version string. It should follow standard version string conventions.
        /// @param version version text with $VER !!!!
        ApplicationBuilder &tagVersion(const char *version);
        /// @brief [ @b MUIA_Application_Version ]
        /// Define application version string. It should follow standard version string conventions.
        /// @param version version text with $VER !!!!
        ApplicationBuilder &tagVersion(const std::string &version);
        /// @brief [ @b MUIA_Application_Window ]
        /// Add a child window to the application.
        ApplicationBuilder &tagWindow(const Window &window);
        /// @brief [ @b MUIA_Application_Window ]
        /// Add multiple child windows to the application.
        ApplicationBuilder &tagWindows(const std::vector<Window> &windows);
    };

    class ApplicationScope : ObjectScope
    {
      public:
        ApplicationScope(const Application &application);
        ~ApplicationScope();

        // explicitly no copy
        ApplicationScope(const ApplicationScope &) = delete;
        ApplicationScope &operator=(const ApplicationScope &) = delete;

        // explicitly no move
        ApplicationScope(ApplicationScope &&) = delete;
        ApplicationScope &operator=(ApplicationScope &&) = delete;
    };

    /// @brief Scope for temporarily sleeping the application
    /// set MUIA_Application_Sleep TRUE, and set to MUIA_Application_Sleep FALSE on destruction
    class ApplicationSleepScope
    {
      public:
        ApplicationSleepScope();
        ~ApplicationSleepScope();

        // explicitly no copy
        ApplicationSleepScope(const ApplicationSleepScope &) = delete;
        ApplicationSleepScope &operator=(const ApplicationSleepScope &) = delete;

        // explicitly no move
        ApplicationSleepScope(ApplicationSleepScope &&) = delete;
        ApplicationSleepScope &operator=(ApplicationSleepScope &&) = delete;
    };
}
