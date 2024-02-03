//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Window.hpp"

#include <libraries/gadtools.h>
#include <libraries/iffparse.h>
#include <proto/intuition.h>

namespace MUI
{
    const std::string Window::className = MUIC_Window;

    bool Window::isOpen() const
    {
        return GetValueAsBool(MUIA_Window_Open);
    }

    AOS::Identifier Window::getID() const
    {
        return AOS::Identifier(GetValueAsULong(MUIA_Window_ID));
    }

    Object *Window::getRootObject() const
    {
        return GetValueAsObjectPtr(MUIA_Window_RootObject);
    }

    std::string Window::getScreenTitle() const
    {
        return GetValueAsString(MUIA_Window_ScreenTitle);
    }

    Window &Window::setID(const AOS::Identifier &id)
    {
        SetValue(MUIA_Window_ID, id.value());
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

    WindowBuilder::WindowBuilder() { }

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
