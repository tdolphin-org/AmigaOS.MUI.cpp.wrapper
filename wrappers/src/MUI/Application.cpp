//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
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

    const DiskObject *Application::getDiskObject() const
    {
        return (const DiskObject *)GetValueAsPtr(MUIA_Application_DiskObject);
    }

    Object *Application::getMenustripObject() const
    {
        return GetValueAsObjectPtr(MUIA_Application_Menustrip);
    }

    Menustrip Application::getMenustrip() const
    {
        return Menustrip(GetValueAsObjectPtr(MUIA_Application_Menustrip));
    }

    std::vector<Window> Application::getWindowList() const
    {
        struct List *list = (struct List *)GetValueAsObjectPtr(MUIA_Application_WindowList);
        if (IsListEmpty(list))
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

    Application &Application::setDiskObject(const DiskObject &diskObject)
    {
        SetValue(MUIA_Application_DiskObject, (long)&diskObject);
        return *this;
    }

    Application &Application::LoadEnvArc()
    {
        DoMethod(muiObject(), MUIM_Application_Load, MUIV_Application_Load_ENVARC);
        return *this;
    }

    Application &Application::SaveEnvArc()
    {
        DoMethod(muiObject(), MUIM_Application_Save, MUIV_Application_Save_ENVARC);
        return *this;
    }

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

    ApplicationBuilder &ApplicationBuilder::tagMenustrip(const Menustrip &menustrip)
    {
        this->PushTag(MUIA_Application_Menustrip, menustrip.muiObject());
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

#ifdef MUIA_Application_UsedClasses
    ApplicationBuilder &ApplicationBuilder::tagUsedClasses(char *usedClasses[])
    {
        this->PushTag(MUIA_Application_UsedClasses, (const char **)usedClasses);
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
