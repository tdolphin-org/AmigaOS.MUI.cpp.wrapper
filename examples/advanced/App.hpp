//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Components/Application.hpp"
#include "Core/Singleton.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"

class AppCore
{
    friend class td::Singleton<AppCore>;

    // open MUI library, close on destructor
    MuiMasterBaseScope muiBase;

    Components::Application mApplication;

    AppCore();

  public:
    void Run();
};

/// @brief main Application (singleton) object
using App = td::Singleton<AppCore>;
