//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

enum class AppEventType
{
    /// @brief if greater or equal than from main menu
    OnMenu = 1000,
    OnMenuAbout = OnMenu,
    OnMenuMUISettings,
};
