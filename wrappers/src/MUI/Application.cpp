//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#include "Application.hpp"

#include "Menustrip.hpp"
#include "Window.hpp"

namespace MUI
{
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

    ApplicationBuilder &ApplicationBuilder::tagUsedClasses(char *usedClasses[])
    {
        this->PushTag(MUIA_Application_UsedClasses, (const char **)usedClasses);
        return *this;
    }

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
        this->PushTag(MUIA_Application_Window, window.muiObject());
        return *this;
    }
}
