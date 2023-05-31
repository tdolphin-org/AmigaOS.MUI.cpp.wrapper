//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "ApplicationContext.hpp"

#include <stdexcept>

#include "MUI/Application.hpp"
#include "MUI/Menustrip.hpp"

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
}
