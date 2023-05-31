//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Core/Singleton.hpp"
#include <intuition/classusr.h>

namespace MUI
{
    class Notify;
    class Application;
    class Menustrip;

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
    };

    typedef class td::Singleton<ApplicationContextCore> ApplicationContext;
}
