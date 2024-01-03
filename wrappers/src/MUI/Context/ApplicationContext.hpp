//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <intuition/classusr.h>
#include <vector>

#include "AOS/Identifier.hpp"
#include "Core/Singleton.hpp"

namespace MUI
{
    class Application;
    class Notify;
    class Menustrip;
    class Window;

    /// @brief application context facade class to get application object and related objects
    /// NOTICE: to use it application have to be scoped by @b ApplicationScope
    class ApplicationContextCore
    {
        friend class td::Singleton<ApplicationContextCore>;
        friend class ApplicationScope;

        Object *mpMuiApplicationObject;

        ApplicationContextCore();
        ~ApplicationContextCore();

        void Init(const Notify &notify);
        void Init(const Application &application);

      public:
        /// @brief return current application object
        /// or throw excpetion if application not scoped by @b ApplicationScope
        /// @return Application object
        Application getApplication();
        /// @brief return current menu strip of application
        /// @return Menustrip object
        Menustrip getMenustrip();
        std::vector<Window> getWindows();
        /// @brief return current main application window (first window)
        /// @return Window object
        Window getAppWindow();
        /// @brief return window with given identifier, or throw excpetion if window doesn't exists
        /// @param id identifier of window to get
        /// @return Window object
        Window getWindow(const AOS::Identifier &id);
    };

    typedef class td::Singleton<ApplicationContextCore> ApplicationContext;
}
