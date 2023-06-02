//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Window.hpp"

#include <stdexcept>

#include <libraries/gadtools.h>
#include <libraries/iffparse.h>
#include <proto/intuition.h>
#include <proto/muimaster.h>

#include "Menustrip.hpp"

namespace MUI
{
    bool Window::isOpen()
    {
        return GetValueAsBool(MUIA_Window_Open);
    }

    unsigned long Window::getID()
    {
        return GetValueAsULong(MUIA_Window_ID);
    }

    std::string Window::getIDAsString()
    {
        auto id = GetValueAsULong(MUIA_Window_ID);
        return std::string({ (char)(id >> 24 & 0xFF), (char)(id >> 16 & 0xFF), (char)(id >> 8 & 0xFF), (char)(id & 0xFF), 0 });
    }

    Object *Window::getRootObject()
    {
        return GetValueAsObjectPtr(MUIA_Window_RootObject);
    }

    std::string Window::getScreenTitle()
    {
        return GetValueAsString(MUIA_Window_ScreenTitle);
    }

    Window &Window::setID(const unsigned long id)
    {
        SetValue(MUIA_Window_ID, id);
        return *this;
    }

    Window &Window::setID(const char id[4])
    {
        SetValue(MUIA_Window_ID, MAKE_ID(id[0], id[1], id[2], id[3]));
        return *this;
    }

    Window &Window::setRootObject(const Object *rootObject)
    {
        SetValue(MUIA_Window_RootObject, rootObject);
        return *this;
    }

    Window &Window::setScreenTitle(const std::string &screenTitle)
    {
        SetValue(MUIA_Window_ScreenTitle, screenTitle);
        return *this;
    }

    Window &Window::Open()
    {
        SetValue(MUIA_Window_Open, true);
        return *this;
    }

    Window &Window::Close()
    {
        SetValue(MUIA_Window_Open, false);
        return *this;
    }

    WindowBuilder::WindowBuilder()
      : NotifyBuilderTemplate(MUI::EmptyUniqueId, MUIC_Window)
      , hasRootObject(false)
    {
    }

    WindowBuilder &WindowBuilder::tagAltHeight(const long altHeight)
    {
        this->PushTag(MUIA_Window_AltHeight, altHeight);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagAltWidth(const long altWidth)
    {
        this->PushTag(MUIA_Window_AltWidth, altWidth);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagHeight(const long height)
    {
        this->PushTag(MUIA_Window_Height, height);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagID(const char id[4])
    {
        this->PushTag(MUIA_Window_ID, MAKE_ID(id[0], id[1], id[2], id[3]));
        return *this;
    }

    WindowBuilder &WindowBuilder::tagMenustrip(const Menustrip &menustrip)
    {
        this->PushTag(MUIA_Window_Menustrip, menustrip.muiObject());
        return *this;
    }

    WindowBuilder &WindowBuilder::tagMenustrip(const NewMenu &newmenu, const unsigned long flags)
    {
        this->PushTag(MUIA_Window_Menustrip, MUI_MakeObject(MUIO_MenustripNM, (unsigned long)&newmenu, flags));
        return *this;
    }

    WindowBuilder &WindowBuilder::tagNoMenus(const bool noMenus)
    {
        this->PushTag(MUIA_Window_NoMenus, noMenus);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagRootObject(const Object *pRootObject)
    {
        this->PushTag(MUIA_Window_RootObject, pRootObject);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagRootObject(const Root &root)
    {
        hasRootObject = true;
        this->PushTag(MUIA_Window_RootObject, root.muiObject());
        return *this;
    }

    WindowBuilder &WindowBuilder::tagScreenTitle(const char *screenTitle)
    {
        this->PushTag(MUIA_Window_ScreenTitle, screenTitle);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagScreenTitle(const std::string &screenTitle)
    {
        this->PushTag(MUIA_Window_ScreenTitle, screenTitle);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Window_Title, title);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagTitle(const std::string &title)
    {
        this->PushTag(MUIA_Window_Title, title);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagWidth(const long width)
    {
        this->PushTag(MUIA_Window_Width, width);
        return *this;
    }

    Window WindowBuilder::object() const
    {
        // The root object is mandatory during window creation and trying to create a window without a root object will fail.
        // So check if there is tag for RootObject.
        if (!hasRootObject)
        {
            std::string error = (std::string) __PRETTY_FUNCTION__ + ", missing RootObject for Window!";
            throw std::runtime_error(error);
        }

        return NotifyBuilderTemplate<WindowBuilder, Window>::object();
    }

    WindowScope::WindowScope(Window &window)
      : mWindow(window)
    {
        if (!mWindow.Open().isOpen())
        {
            std::string error = (std::string) __PRETTY_FUNCTION__ + ", failed to open window!";
            throw std::runtime_error(error);
        }
    }

    WindowScope::~WindowScope()
    {
        mWindow.Close();
    }
}
