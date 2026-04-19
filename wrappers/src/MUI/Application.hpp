//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Core/ObjectScope.hpp"
#include "Notify.hpp"

struct MsgPort;
struct NewMenu;
struct RexxMsg;

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
        /// For non single task applications MUI may append .1, .2, etc. after object creation.
        std::string getBase() const;
        /// @brief [ @b MUIA_Application_Broker ]
        /// Returns pointer to the application's commodities broker object.
        /// May be NULL if the commodities interface is unavailable.
        void *getBroker() const;
        /// @brief [ @b MUIA_Application_BrokerHook ]
        /// Hook called whenever a commodities message arrives between MUI's GetMsg() and ReplyMsg().
        Hook *getBrokerHook() const;
        /// @brief [ @b MUIA_Application_BrokerPort ]
        /// Returns pointer to the application's commodities message port.
        /// May be NULL if the commodities interface is unavailable.
        MsgPort *getBrokerPort() const;
        /// @brief [ @b MUIA_Application_BrokerPri ]
        /// Priority of the application's commodities broker.
        long getBrokerPri() const;
        /// @brief [ @b MUIA_Application_Commands ]
        /// Returns pointer to the application's ARexx command table.
        /// The table describes programmer defined ARexx commands handled by MUI.
        const struct MUI_Command *getCommands() const;
        /// @brief [ @b MUIA_Application_Copyright ]
        /// Copyright string containing the year and the company.
        std::string getCopyright() const;
        /// @brief [ @b MUIA_Application_Description ]
        /// Short description, about 40 characters, shown e.g. in commodities exchange.
        std::string getDescription() const;
        /// @brief [ @b MUIA_Application_DiskObject ]
        /// Pointer to DiskObject used for the AppIcon when the application is iconified.
        /// If absent, MUI tries fallback icons automatically.
        const DiskObject *getDiskObject() const;
        /// @brief [ @b MUIA_Application_DoubleStart ]
        /// True if the user tried to start a single task application twice.
        bool isDoubleStart() const;
        /// @brief [ @b MUIA_Application_DropObject ]
        /// Object that receives AppMessages when icons are dropped onto the AppIcon while iconified.
        Object *getDropObject() const;
        /// @brief [ @b MUIA_Application_ForceQuit ]
        /// True if the application should exit quietly without additional safety requesters.
        /// MUI sets this e.g. for a QUIT FORCE ARexx command.
        bool isForceQuit() const;
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// AmigaGuide style help file used for online help.
        /// MUI resolves help nodes and lines by walking from the current object up to the application.
        std::string getHelpFile() const;
        /// @brief [ @b MUIA_Application_Iconified ]
        /// True if the application is currently iconified.
        /// While iconified, windows are closed and reopened automatically when the application is restored.
        bool isIconified() const;
        /// @brief [ @b MUIA_Application_IconifyTitle ]
        /// Alternative title used for the iconification icon and/or menu.
        /// Defaults to the normal application title.
        std::string getIconifyTitle() const;
        /// @brief [ @b MUIA_Application_MenuAction ]
        /// Returns UserData of the selected menu item.
        unsigned long getMenuAction() const;
        /// @brief [ @b MUIA_Application_Menu ]
        /// Obsolete gadtools NewMenu definition for the application.
        /// Prefer @b MUIA_Application_Menustrip.
        const ::NewMenu *getMenu() const;
        /// @brief [ @b MUIA_Application_MenuHelp ]
        /// Returns UserData of the menu item selected with the help key.
        unsigned long getMenuHelp() const;
        /// @brief [ @b MUIA_Application_Menustrip ]
        /// Returns raw menustrip object pointer.
        /// This menu is shared by application windows that do not define a private menu.
        Object *getMenustripObject() const;
        /// @brief [ @b MUIA_Application_Menustrip ]
        /// Returns menustrip wrapper.
        /// The menustrip is treated as child of the application and disposed together with it.
        Menustrip getMenustrip() const;
        /// @brief [ @b MUIA_Application_RexxHook ]
        /// Hook called when a Rexx message cannot be mapped to a built in or programmer defined command.
        /// The hook result is used as ARexx return code.
        Hook *getRexxHook() const;
        /// @brief [ @b MUIA_Application_RexxMsg ]
        /// Returns current RexxMsg within an ARexx callback hook.
        /// This allows use of amiga.lib ARexx support functions.
        RexxMsg *getRexxMsg() const;
        /// @brief [ @b MUIA_Application_Sleep ]
        /// True if the application is currently sleeping.
        /// This attribute uses a nesting count, so sleep and wake-up calls must be balanced.
        bool isSleep() const;
        /// @brief [ @b MUIA_Application_Title ]
        /// Title of the application.
        /// It should be unique, without version information, and no longer than 30 characters.
        std::string getTitle() const;
#ifdef MUIA_Application_UsedClasses
        /// @brief [ @b MUIA_Application_UsedClasses ]
        /// NULL terminated list of external custom classes used by the application.
        /// Only external classes ending in .mcc should be listed here.
        std::vector<std::string> getUsedClasses() const;
#endif
        /// @brief [ @b MUIA_Application_Version ]
        /// Version string of the application.
        /// It should follow standard version string conventions and must not begin with a leading NUL byte.
        std::string getVersion() const;
        /// @brief [ @b MUIA_Application_WindowList ]
        /// Read only exec list containing the child windows of the application.
        /// The original list must be treated as read-only.
        std::vector<Window> getWindowList() const;

        /// @brief [ @b MUIA_Application_DiskObject ]
        /// Provide DiskObject used for the AppIcon when the application becomes iconified.
        Application &setDiskObject(const DiskObject &diskObject);
        /// @brief [ @b MUIA_Application_BrokerHook ]
        /// Specify a hook called whenever a commodities message arrives.
        /// The hook is never called if the commodities interface is unavailable.
        Application &setBrokerHook(const Hook *brokerHook);
        /// @brief [ @b MUIA_Application_Commands ]
        /// Provide an array of ARexx commands for the application.
        /// The array must be terminated by a NULL entry.
        Application &setCommands(const struct MUI_Command *commands);
        /// @brief [ @b MUIA_Application_DropObject ]
        /// Specify the object that shall receive AppMessages when icons are dropped onto the AppIcon.
        Application &setDropObject(const Object *dropObject);
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// Define an AmigaGuide style file to be displayed when the user requests online help.
        Application &setHelpFile(const char *helpFile);
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// Define an AmigaGuide style file to be displayed when the user requests online help.
        Application &setHelpFile(const std::string &helpFile);
        /// @brief [ @b MUIA_Application_Iconified ]
        /// Set whether the application is iconified.
        /// Iconifying closes all open windows and shows an AppIcon.
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
        /// @brief [ @b MUIA_Application_RexxHook ]
        /// Specify a hook called whenever an unmapped Rexx message arrives.
        /// The hook may return an ARexx secondary result via @b MUIA_Application_RexxString.
        Application &setRexxHook(const Hook *rexxHook);

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
        /// Each added handler must later be removed exactly once.
        Application &AddInputHandler(const struct MUI_InputHandlerNode *ihnode);
        /// @brief [ @b MUIM_Application_BuildSettingsPanel ]
        /// Implement this method if the application provides built in settings panels.
        Application &BuildSettingsPanel(const unsigned long number);
        /// @brief [ @b MUIM_Application_CheckRefresh ]
        /// Refresh all open windows that currently need refreshing.
        /// Useful when your code temporarily runs outside the normal MUI input loop.
        Application &CheckRefresh();
        /// @brief [ @b MUIM_Application_DefaultConfigItem ]
        /// Override this to return sensible default values for application specific config items.
        Application &DefaultConfigItem(const unsigned long cfgid);
        /// @brief [ @b MUIM_Application_Execute ]
        /// Execute the ideal main loop of a MUI application.
#ifdef MUIM_Application_Execute
        long Execute() const;
#endif
        /// @brief [ @b MUIM_Application_GetMenuCheck ]
        /// Return whether the first matching checkmark menu item is set.
        /// The search is delegated to application subwindows.
        bool GetMenuCheck(const unsigned long menuId) const;
        /// @brief [ @b MUIM_Application_GetMenuState ]
        /// Return whether the first matching menu item is enabled.
        /// The search is delegated to application subwindows.
        bool GetMenuState(const unsigned long menuId) const;
        /// @brief [ @b MUIM_Application_Input ]
        /// Process pending GUI input and update the supplied signal mask.
        /// MUI expects this to be called whenever one of its input signals arrives.
        Application &Input(const unsigned long *signal);
        /// @brief [ @b MUIM_Application_InputBuffered ]
        /// Process GUI related actions without consuming queued return IDs.
        /// This is useful during long-running operations when the application should stay responsive.
        Application &InputBuffered();
        /// @brief [ @b MUIM_Application_Load ]
        /// Load application settings from the given file or magic cookie.
        /// Objects with non-NULL @b MUIA_ObjectID restore their exported state during this call.
        Application &Load(const char *name);
        /// @brief [ @b MUIM_Application_Load ]
        /// Load application settings from the given file or magic cookie.
        Application &Load(const std::string &name);
        /// @brief [ @b MUIM_Application_Load, @b MUIV_Application_Load_ENVARC ]
        /// Load application settings from ENVARC:mui/.
        Application &LoadEnvArc();
        /// @brief [ @b MUIM_Application_NewInput ]
        /// Enhanced replacement for MUIM_Application_Input which expects the previous Wait() result in signal.
        /// This is generally the preferred input method over MUIM_Application_Input.
        long NewInput(unsigned long *signal) const;
        /// @brief [ @b MUIM_Application_OpenConfigWindow ]
        /// Open the application's MUI configuration window.
        Application &OpenConfigWindow();
        /// @brief [ @b MUIM_Application_OpenConfigWindow ]
        /// Open the application's MUI configuration window with explicit flags and class id.
        Application &OpenConfigWindow(const unsigned long flags, char *classid);
        /// @brief [ @b MUIM_Application_PushMethod ]
        /// Schedule a method to be executed later in the application's task context.
        /// This is the safe way to talk to MUI from a secondary task.
        template <typename... Args> unsigned long PushMethod(const Object *dest, Args... args)
        {
            return DoMethod(muiObject(), MUIM_Application_PushMethod, dest, (long)sizeof...(Args), args...);
        }
        /// @brief [ @b MUIM_Application_RemInputHandler ]
        /// Remove a previously registered input handler node.
        Application &RemInputHandler(const struct MUI_InputHandlerNode *ihnode);
        /// @brief [ @b MUIM_Application_ReturnID ]
        /// Queue a return id for the next non-buffered input call.
        /// MUI stores return ids in a private FIFO and feeds them back through the input methods.
        Application &ReturnID(const unsigned long retid);
        /// @brief [ @b MUIM_Application_Run ]
        /// Execute the ideal main loop of a MUI application.
        long Run() const;
        /// @brief [ @b MUIM_Application_Save ]
        /// Save application settings to the given file or magic cookie.
        /// Objects with non-NULL @b MUIA_ObjectID export their state during this call.
        Application &Save(const char *name);
        /// @brief [ @b MUIM_Application_Save ]
        /// Save application settings to the given file or magic cookie.
        Application &Save(const std::string &name);
        /// @brief [ @b MUIM_Application_SetConfigItem ]
        /// Private PSI method for setting a configuration item.
        Application &SetConfigItem(const unsigned long item, const void *data);
        /// @brief [ @b MUIM_Application_SetMenuCheck ]
        /// Set or clear all matching checkmark menu items.
        /// Matching is done by the UserData value stored in the menu definition.
        Application &SetMenuCheck(const unsigned long menuId, const bool stat);
        /// @brief [ @b MUIM_Application_SetMenuState ]
        /// Enable or disable all matching menu items.
        /// Matching is done by the UserData value stored in the menu definition.
        Application &SetMenuState(const unsigned long menuId, const bool stat);
        /// @brief [ @b MUIM_Application_Save, @b MUIV_Application_Save_ENVARC ]
        /// Save application settings to ENVARC:mui/.
        Application &SaveEnvArc();
        /// @brief [ @b MUIM_Application_ShowHelp ]
        /// Display an AmigaGuide help file and optionally jump to a node and line.
        /// The application is put to sleep until the help file is shown.
        Application &ShowHelp(const Object *window, const char *name, const char *node, const long line);
        /// @brief [ @b MUIM_Application_UnpushMethod ]
        /// Remove queued methods previously scheduled with MUIM_Application_PushMethod.
        /// If all filters are zero or NULL, the whole queue is cleared.
        unsigned long UnpushMethod(const Object *targetobj = nullptr, const unsigned long methodid = 0, const unsigned long method = 0);
        /// @brief [ @b MUIA_Application_Sleep, @b TRUE ]
        /// Put the whole application to sleep. Open windows are disabled and a busy pointer appears.
        /// Because this attribute nests, each sleep should be matched with one wake-up.
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
        /// It must not contain spaces or special characters such as :/()#?*.
        ApplicationBuilder &tagBase(const char *base);
        /// @brief [ @b MUIA_Application_Base ]
        /// Basename used for the built in ARexx port and internal file management.
        ApplicationBuilder &tagBase(const std::string &base);
        /// @brief [ @b MUIA_Application_BrokerHook ]
        /// Hook called whenever a commodities message arrives.
        ApplicationBuilder &tagBrokerHook(const Hook *brokerHook);
        /// @brief [ @b MUIA_Application_BrokerPri ]
        /// Priority of the application's broker.
        ApplicationBuilder &tagBrokerPri(const long brokerPri);
        /// @brief [ @b MUIA_Application_Commands ]
        /// Array of ARexx commands handled by the application.
        /// The array must be terminated by a NULL entry.
        ApplicationBuilder &tagCommands(const struct MUI_Command *commands);
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
        /// @brief [ @b MUIA_Application_DropObject ]
        /// Object receiving AppMessages when icons are dropped onto the AppIcon.
        ApplicationBuilder &tagDropObject(const Object *dropObject);
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// Define an AmigaGuide style file to be displayed when the user requests online help.
        ApplicationBuilder &tagHelpFile(const char *helpFile);
        /// @brief [ @b MUIA_Application_HelpFile ]
        /// Define an AmigaGuide style file to be displayed when the user requests online help.
        ApplicationBuilder &tagHelpFile(const std::string &helpFile);
        /// @brief [ @b MUIA_Application_IconifyTitle ]
        /// Alternative name used for the iconification icon and/or menu.
        /// Defaults to the application title if not specified.
        ApplicationBuilder &tagIconifyTitle(const char *iconifyTitle);
        /// @brief [ @b MUIA_Application_IconifyTitle ]
        /// Alternative name used for the iconification icon and/or menu.
        ApplicationBuilder &tagIconifyTitle(const std::string &iconifyTitle);
        /// @brief [ @b MUIA_Application_Menu ]
        /// Obsolete gadtools NewMenu definition for the application.
        /// Prefer @b MUIA_Application_Menustrip.
        ApplicationBuilder &tagMenu(const ::NewMenu *menu);
        /// @brief [ @b MUIA_Application_Menustrip ]
        /// Menu strip shared by all windows of the application that do not define a private menu.
        ApplicationBuilder &tagMenustrip(const Menustrip &menustrip);
        /// @brief [ @b MUIA_Application_RexxHook ]
        /// Hook called whenever an unmapped Rexx message arrives.
        ApplicationBuilder &tagRexxHook(const Hook *rexxHook);
        /// @brief [ @b MUIA_Application_SingleTask ]
        /// Indicate whether the application is a single task program.
        /// If true, MUI refuses to create more than one application object.
        ApplicationBuilder &tagSingleTask(const bool singleTask);
        /// @brief [ @b MUIA_Application_Title ]
        /// Title of the application. It should be unique and must not contain version information.
        ApplicationBuilder &tagTitle(const char *title);
        /// @brief [ @b MUIA_Application_Title ]
        /// Title of the application. It should be unique and must not contain version information.
        ApplicationBuilder &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Application_UseCommodities ]
        /// When false, the application runs without a commodities interface.
        /// Think carefully before disabling it.
        ApplicationBuilder &tagUseCommodities(const bool useCommodities);
#ifdef MUIA_Application_UsedClasses
        /// @brief [ @b MUIA_Application_UsedClasses ]
        /// NULL terminated array listing external custom classes used by the application.
        /// List only external .mcc classes, not default .mui classes or .mcp preference classes.
        ApplicationBuilder &tagUsedClasses(char *usedClasses[]);
#endif
        /// @brief [ @b MUIA_Application_UseRexx ]
        /// When false, the application runs without an ARexx interface.
        /// Think carefully before disabling it.
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
