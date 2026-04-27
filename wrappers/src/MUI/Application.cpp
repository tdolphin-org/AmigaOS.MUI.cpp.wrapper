//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Application.hpp"

#include "Context/ApplicationContext.hpp"
#include "Menustrip.hpp"
#include "Window.hpp"

#include <proto/alib.h>
#include <proto/intuition.h>

namespace MUI
{
    const std::string Application::className = MUIC_Application;

    bool Application::isActive() const
    {
        return GetValueAsBool(MUIA_Application_Active);
    }

    Application &Application::setActive(const bool active)
    {
        SetValue(MUIA_Application_Active, active);
        return *this;
    }

    std::string Application::getAuthor() const
    {
        return GetValueAsString(MUIA_Application_Author);
    }

    std::string Application::getBase() const
    {
        return GetValueAsString(MUIA_Application_Base);
    }

    void *Application::getBroker() const
    {
        return GetValueAsPtr(MUIA_Application_Broker);
    }

    Hook *Application::getBrokerHook() const
    {
        return GetValueAsHookPtr(MUIA_Application_BrokerHook);
    }

    MsgPort *Application::getBrokerPort() const
    {
        return GetValueAsMsgPortPtr(MUIA_Application_BrokerPort);
    }

    long Application::getBrokerPri() const
    {
        return GetValueAsLong(MUIA_Application_BrokerPri);
    }

    const struct MUI_Command *Application::getCommands() const
    {
        return GetValueAsCommandPtr(MUIA_Application_Commands);
    }

    std::string Application::getCopyright() const
    {
        return GetValueAsString(MUIA_Application_Copyright);
    }

    std::string Application::getDescription() const
    {
        return GetValueAsString(MUIA_Application_Description);
    }

    const DiskObject *Application::getDiskObject() const
    {
        return GetValueAsDiskObjectPtr(MUIA_Application_DiskObject);
    }

    bool Application::isDoubleStart() const
    {
        return GetValueAsBool(MUIA_Application_DoubleStart);
    }

    bool Application::isForceQuit() const
    {
        return GetValueAsBool(MUIA_Application_ForceQuit);
    }

    Application &Application::setForceQuit(const bool forceQuit)
    {
        SetValue(MUIA_Application_ForceQuit, forceQuit);
        return *this;
    }

    std::string Application::getHelpFile() const
    {
        return GetValueAsString(MUIA_Application_HelpFile);
    }

    bool Application::isIconified() const
    {
        return GetValueAsBool(MUIA_Application_Iconified);
    }

#ifdef MUIA_Application_IconifyTitle
    std::string Application::getIconifyTitle() const
    {
        return GetValueAsString(MUIA_Application_IconifyTitle);
    }
#endif

    unsigned long Application::getMenuAction() const
    {
        return GetValueAsULong(MUIA_Application_MenuAction);
    }

    const ::NewMenu *Application::getMenu() const
    {
        return GetValueAsNewMenuPtr(MUIA_Application_Menu);
    }

    unsigned long Application::getMenuHelp() const
    {
        return GetValueAsULong(MUIA_Application_MenuHelp);
    }

    Object *Application::getMenustripObject() const
    {
        return GetValueAsObjectPtr(MUIA_Application_Menustrip);
    }

    Menustrip Application::getMenustrip() const
    {
        return Menustrip(GetValueAsObjectPtr(MUIA_Application_Menustrip));
    }

    Hook *Application::getRexxHook() const
    {
        return GetValueAsHookPtr(MUIA_Application_RexxHook);
    }

    RexxMsg *Application::getRexxMsg() const
    {
        return GetValueAsRexxMsgPtr(MUIA_Application_RexxMsg);
    }

    std::vector<Window> Application::getWindowList() const
    {
        struct List *list = GetValueAsListPtr(MUIA_Application_WindowList);
        if (!list || IsListEmpty(list))
            return std::vector<Window>();

        std::vector<Window> result;
        Object *object, *objectstate = (Object *)list->lh_Head;
        while (object = (Object *)NextObject(&objectstate))
        {
            if (Window::instanceOf(object))
                result.push_back(Window(object));
        }

        return result;
    }

    bool Application::isSleep() const
    {
        return GetValueAsBool(MUIA_Application_Sleep);
    }

    std::string Application::getTitle() const
    {
        return GetValueAsString(MUIA_Application_Title);
    }

#ifdef MUIA_Application_UsedClasses
    std::vector<std::string> Application::getUsedClasses() const
    {
        const char **usedClasses = GetValueAsConstCharArrayPtr(MUIA_Application_UsedClasses);
        if (!usedClasses)
            return { };

        std::vector<std::string> result;
        for (const char **entry = usedClasses; *entry != nullptr; ++entry)
            result.emplace_back(*entry);

        return result;
    }

    Application &Application::setUsedClasses(const char *usedClasses[])
    {
        SetValue(MUIA_Application_UsedClasses, usedClasses);
        return *this;
    }

    Application &Application::setUsedClasses(const std::vector<std::string> &usedClasses)
    {
        auto copy = StoreStringArray(MUIA_Application_UsedClasses, usedClasses);
        SetValue(MUIA_Application_UsedClasses, copy);
        return *this;
    }
#endif

    std::string Application::getVersion() const
    {
        return GetValueAsString(MUIA_Application_Version);
    }

    Application &Application::setDiskObject(const DiskObject &diskObject)
    {
        SetValue(MUIA_Application_DiskObject, (long)&diskObject);
        return *this;
    }

    Application &Application::setBrokerHook(const Hook *brokerHook)
    {
        SetValue(MUIA_Application_BrokerHook, brokerHook);
        return *this;
    }

    Application &Application::setCommands(const struct MUI_Command *commands)
    {
        SetValue(MUIA_Application_Commands, commands);
        return *this;
    }

    Application &Application::setDropObject(const Object *dropObject)
    {
        SetValue(MUIA_Application_DropObject, dropObject);
        return *this;
    }

    Application &Application::setHelpFile(const char *helpFile)
    {
        SetValue(MUIA_Application_HelpFile, helpFile);
        return *this;
    }

    Application &Application::setHelpFile(const std::string &helpFile)
    {
        SetValue(MUIA_Application_HelpFile, helpFile);
        return *this;
    }

    Application &Application::setIconified(const bool iconified)
    {
        SetValue(MUIA_Application_Iconified, iconified);
        return *this;
    }

#ifdef MUIA_Application_IconifyTitle
    Application &Application::setIconifyTitle(const char *iconifyTitle)
    {
        SetValue(MUIA_Application_IconifyTitle, iconifyTitle);
        return *this;
    }

    Application &Application::setIconifyTitle(const std::string &iconifyTitle)
    {
        SetValue(MUIA_Application_IconifyTitle, iconifyTitle);
        return *this;
    }
#endif

    Application &Application::setRexxString(const char *rexxString)
    {
        SetValue(MUIA_Application_RexxString, rexxString);
        return *this;
    }

    Application &Application::setRexxString(const std::string &rexxString)
    {
        SetValue(MUIA_Application_RexxString, rexxString);
        return *this;
    }

    Application &Application::setRexxHook(const Hook *rexxHook)
    {
        SetValue(MUIA_Application_RexxHook, rexxHook);
        return *this;
    }

#ifdef MUIWindow
    Application &Application::AboutMUI(const MUIWindow *refwindow)
#else
    Application &Application::AboutMUI(const Object *refwindow)
#endif
    {
        DoMethod(muiObject(), MUIM_Application_AboutMUI, refwindow);
        return *this;
    }

    Application &Application::AddInputHandler(const struct MUI_InputHandlerNode *ihnode)
    {
        DoMethod(muiObject(), MUIM_Application_AddInputHandler, ihnode);
        return *this;
    }

#ifdef MUIM_Application_BuildSettingsPanel
    Application &Application::BuildSettingsPanel(const unsigned long number)
    {
        DoMethod(muiObject(), MUIM_Application_BuildSettingsPanel, number);
        return *this;
    }
#endif

    Application &Application::CheckRefresh()
    {
        DoMethod(muiObject(), MUIM_Application_CheckRefresh);
        return *this;
    }

#ifdef MUIM_Application_DefaultConfigItem
    Application &Application::DefaultConfigItem(const unsigned long cfgid)
    {
        DoMethod(muiObject(), MUIM_Application_DefaultConfigItem, cfgid);
        return *this;
    }
#endif

#ifdef MUIM_Application_Execute
    long Application::Execute() const
    {
        return DoMethod(muiObject(), MUIM_Application_Execute);
    }
#endif

    bool Application::GetMenuCheck(const unsigned long menuId) const
    {
        return DoMethod(muiObject(), MUIM_Application_GetMenuCheck, menuId);
    }

    bool Application::GetMenuState(const unsigned long menuId) const
    {
        return DoMethod(muiObject(), MUIM_Application_GetMenuState, menuId);
    }

    Application &Application::Input(const unsigned long *signal)
    {
        DoMethod(muiObject(), MUIM_Application_Input, signal);
        return *this;
    }

    Application &Application::InputBuffered()
    {
        DoMethod(muiObject(), MUIM_Application_InputBuffered);
        return *this;
    }

    Application &Application::Load(const char *name)
    {
        DoMethod(muiObject(), MUIM_Application_Load, name);
        return *this;
    }

    Application &Application::Load(const std::string &name)
    {
        DoMethod(muiObject(), MUIM_Application_Load, name.c_str());
        return *this;
    }

    Application &Application::LoadEnvArc()
    {
        DoMethod(muiObject(), MUIM_Application_Load, MUIV_Application_Load_ENVARC);
        return *this;
    }

    long Application::NewInput(unsigned long *signal) const
    {
        return DoMethod(muiObject(), MUIM_Application_NewInput, signal);
    }

    Application &Application::OpenConfigWindow()
    {
        DoMethod(muiObject(), MUIM_Application_OpenConfigWindow, 0);
        return *this;
    }

    Application &Application::OpenConfigWindow(const unsigned long flags, char *classid)
    {
        DoMethod(muiObject(), MUIM_Application_OpenConfigWindow, flags, classid);
        return *this;
    }

    Application &Application::RemInputHandler(const struct MUI_InputHandlerNode *ihnode)
    {
        DoMethod(muiObject(), MUIM_Application_RemInputHandler, ihnode);
        return *this;
    }

    Application &Application::ReturnID(const unsigned long retid)
    {
        DoMethod(muiObject(), MUIM_Application_ReturnID, retid);
        return *this;
    }

#ifdef MUIM_Application_Run
    long Application::Run() const
    {
        return DoMethod(muiObject(), MUIM_Application_Run);
    }
#endif

    Application &Application::Save(const char *name)
    {
        DoMethod(muiObject(), MUIM_Application_Save, name);
        return *this;
    }

    Application &Application::Save(const std::string &name)
    {
        DoMethod(muiObject(), MUIM_Application_Save, name.c_str());
        return *this;
    }

    Application &Application::SetConfigItem(const unsigned long item, const void *data)
    {
        DoMethod(muiObject(), MUIM_Application_SetConfigItem, item, data);
        return *this;
    }

    Application &Application::SetMenuCheck(const unsigned long menuId, const bool stat)
    {
        DoMethod(muiObject(), MUIM_Application_SetMenuCheck, menuId, stat);
        return *this;
    }

    Application &Application::SetMenuState(const unsigned long menuId, const bool stat)
    {
        DoMethod(muiObject(), MUIM_Application_SetMenuState, menuId, stat);
        return *this;
    }

    Application &Application::SaveEnvArc()
    {
        DoMethod(muiObject(), MUIM_Application_Save, MUIV_Application_Save_ENVARC);
        return *this;
    }

    Application &Application::ShowHelp(const Object *window, const char *name, const char *node, const long line)
    {
        DoMethod(muiObject(), MUIM_Application_ShowHelp, window, name, node, line);
        return *this;
    }

#ifdef MUIM_Application_UnpushMethod
    unsigned long Application::UnpushMethod(const Object *targetobj, const unsigned long methodid, const unsigned long method)
    {
        return (unsigned long)DoMethod(muiObject(), MUIM_Application_UnpushMethod, targetobj, methodid, method);
    }
#endif

    Application &Application::Sleep()
    {
        SetValue(MUIA_Application_Sleep, true);
        return *this;
    }

    Application &Application::WakeUp()
    {
        SetValue(MUIA_Application_Sleep, false);
        return *this;
    }

    Application &Application::AddMember(const Window &window)
    {
        DoMethod(muiObject(), OM_ADDMEMBER, window.muiObject());
        return *this;
    }

    Application &Application::RemMember(const Window &window)
    {
        DoMethod(muiObject(), OM_REMMEMBER, window.muiObject());
        return *this;
    }

    ApplicationBuilder::ApplicationBuilder()
      : NotifyBuilderTemplate(MUI::EmptyUniqueId, MUIC_Application)
    {
    }

    ApplicationBuilder &ApplicationBuilder::tagActive(const bool active)
    {
        this->PushTag(MUIA_Application_Active, active);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagAuthor(const char *author)
    {
        this->PushTag(MUIA_Application_Author, author);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagAuthor(const std::string &author)
    {
        tagAuthor((char *)author.c_str());
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagBase(const char *base)
    {
        this->PushTag(MUIA_Application_Base, base);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagBase(const std::string &base)
    {
        tagBase((char *)base.c_str());
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagBrokerHook(const Hook *brokerHook)
    {
        this->PushTag(MUIA_Application_BrokerHook, brokerHook);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagBrokerPri(const long brokerPri)
    {
        this->PushTag(MUIA_Application_BrokerPri, brokerPri);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagCommands(const struct MUI_Command *commands)
    {
        this->PushTag(MUIA_Application_Commands, commands);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagCopyright(const char *copyright)
    {
        this->PushTag(MUIA_Application_Copyright, copyright);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagCopyright(const std::string &copyright)
    {
        tagCopyright((char *)copyright.c_str());
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagDescription(const char *description)
    {
        this->PushTag(MUIA_Application_Description, description);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagDescription(const std::string &description)
    {
        tagDescription((char *)description.c_str());
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagDiskObject(const DiskObject &diskObject)
    {
        this->PushTag(MUIA_Application_DiskObject, (long)&diskObject);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagDropObject(const Object *dropObject)
    {
        this->PushTag(MUIA_Application_DropObject, dropObject);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagHelpFile(const char *helpFile)
    {
        this->PushTag(MUIA_Application_HelpFile, helpFile);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagHelpFile(const std::string &helpFile)
    {
        tagHelpFile(helpFile.c_str());
        return *this;
    }

#ifdef MUIA_Application_IconifyTitle
    ApplicationBuilder &ApplicationBuilder::tagIconifyTitle(const char *iconifyTitle)
    {
        this->PushTag(MUIA_Application_IconifyTitle, iconifyTitle);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagIconifyTitle(const std::string &iconifyTitle)
    {
        tagIconifyTitle(iconifyTitle.c_str());
        return *this;
    }
#endif

    ApplicationBuilder &ApplicationBuilder::tagMenu(const ::NewMenu *menu)
    {
        this->PushTag(MUIA_Application_Menu, menu);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagMenustrip(const Menustrip &menustrip)
    {
        this->PushTag(MUIA_Application_Menustrip, menustrip.muiObject());
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagRexxHook(const Hook *rexxHook)
    {
        this->PushTag(MUIA_Application_RexxHook, rexxHook);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagSingleTask(const bool singleTask)
    {
        this->PushTag(MUIA_Application_SingleTask, singleTask);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Application_Title, title);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagTitle(const std::string &title)
    {
        tagTitle((char *)title.c_str());
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagUseCommodities(const bool useCommodities)
    {
        this->PushTag(MUIA_Application_UseCommodities, useCommodities);
        return *this;
    }

#ifdef MUIA_Application_UsedClasses
    ApplicationBuilder &ApplicationBuilder::tagUsedClasses(char *usedClasses[])
    {
        auto copy = this->StoreStringArray(MUIA_Application_UsedClasses, (const char **)usedClasses);
        this->PushTag(MUIA_Application_UsedClasses, copy);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagUsedClasses(const std::vector<std::string> &usedClasses)
    {
        auto copy = this->StoreStringArray(MUIA_Application_UsedClasses, usedClasses);
        this->PushTag(MUIA_Application_UsedClasses, copy);
        return *this;
    }
#endif

    ApplicationBuilder &ApplicationBuilder::tagUseRexx(const bool useRexx)
    {
        this->PushTag(MUIA_Application_UseRexx, useRexx);
        return *this;
    }

#ifdef MUIA_Application_UseScreenNotify
    ApplicationBuilder &ApplicationBuilder::tagUseScreenNotify(const bool useScreenNotify)
    {
        this->PushTag(MUIA_Application_UseScreenNotify, useScreenNotify);
        return *this;
    }
#endif

    ApplicationBuilder &ApplicationBuilder::tagVersion(const char *version)
    {
        this->PushTag(MUIA_Application_Version, version);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagVersion(const std::string &version)
    {
        tagVersion((char *)version.c_str());
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagWindow(const Window &window)
    {
        this->PushTag(MUIA_Application_Window, window.muiObject(), false);
        return *this;
    }

    ApplicationBuilder &ApplicationBuilder::tagWindows(const std::vector<Window> &windows)
    {
        for (const auto &window : windows)
            this->PushTag(MUIA_Application_Window, window.muiObject(), false);
        return *this;
    }

    ApplicationScope::ApplicationScope(const Application &application)
      : ObjectScope(application.muiObject())
    {
        ApplicationContext::instance().Init(application);
        Application(muiObject()).LoadEnvArc();
    }

    ApplicationScope::~ApplicationScope()
    {
        Application(muiObject()).SaveEnvArc();
    }

    ApplicationSleepScope::ApplicationSleepScope()
    {
        ApplicationContext::instance().getApplication().Sleep();
    }

    ApplicationSleepScope::~ApplicationSleepScope()
    {
        ApplicationContext::instance().getApplication().WakeUp();
    }
}
