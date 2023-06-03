//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "ApplicationContext.hpp"

#include <stdexcept>

#include <libraries/iffparse.h>

#include "MUI/Application.hpp"
#include "MUI/Menustrip.hpp"
#include "MUI/Window.hpp"

namespace MUI
{
    ApplicationContextCore::ApplicationContextCore() { }

    ApplicationContextCore::~ApplicationContextCore() { }

    void ApplicationContextCore::Init(const Notify &notify)
    {
        mpMuiApplicationObject = notify.getApplicationObject();
        if (mpMuiApplicationObject == nullptr)
        {
            std::string error = (std::string) __PRETTY_FUNCTION__ + " getApplicationObject() returns null!";
            throw std::runtime_error(error);
        }
    }

    void ApplicationContextCore::Init(const Application &application)
    {
        mpMuiApplicationObject = application.muiObject();
    }

    Application ApplicationContextCore::getApplication()
    {
        return Application(mpMuiApplicationObject);
    }

    Menustrip ApplicationContextCore::getMenustrip()
    {
        return Application(mpMuiApplicationObject).getMenustrip();
    }

    std::vector<Window> ApplicationContextCore::getWindows()
    {
        return Application(mpMuiApplicationObject).getWindowList();
    }

    Window ApplicationContextCore::getAppWindow()
    {
        return Application(mpMuiApplicationObject).getWindowList().at(0);
    }

    Window ApplicationContextCore::getWindow(const AOS::Identifier &id)
    {
        auto windows = Application(mpMuiApplicationObject).getWindowList();
        for (auto &window : windows)
            if (window.getID() == id)
                return window;

        std::string error = (std::string) __PRETTY_FUNCTION__ + " undefined window " + id.toString() + "!";
        throw std::runtime_error(error);
    }
}
