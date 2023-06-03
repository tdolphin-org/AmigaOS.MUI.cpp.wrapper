//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
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
        Application getApplication();
        Menustrip getMenustrip();
        std::vector<Window> getWindows();
        Window getAppWindow();
        Window getWindow(const AOS::Identifier &id);
    };

    typedef class td::Singleton<ApplicationContextCore> ApplicationContext;
}
