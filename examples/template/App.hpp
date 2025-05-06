//
//  AmigaOS MUI C++ wrapper
//
//  Application Template
//
//  (c) 20xx XXXXX
//

#pragma once

#include "Components/AppWindow.hpp"
#include "Components/Application.hpp"
#include "Components/InfoWindow.hpp"
#include "Core/Singleton.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"

class AppCore
{
    friend class td::Singleton<AppCore>;

    // open MUI library, close on destructor
    MuiMasterBaseScope muiBase;

    Components::AppWindow mAppWindow;
    Components::InfoWindow mInfoWindow;
    Components::Application mApplication;

    AppCore();
    ~AppCore();

  public:
    void Run();
};

/// @brief main Application (singleton) object
using App = td::Singleton<AppCore>;
