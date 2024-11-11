//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <iostream>
#include <libraries/mui.h>

namespace MUI
{
    enum class NotifyDestType
    {
        GivenObject = 0,
        Self = MUIV_Notify_Self,
        Window = MUIV_Notify_Window,
        Application = MUIV_Notify_Application,
        Parent = MUIV_Notify_Parent,
        ParentParent = MUIV_Notify_ParentParent,
        ParentParentParent = MUIV_Notify_ParentParentParent,
    };
}

std::ostream &operator<<(std::ostream &os, const enum MUI::NotifyDestType notifyDestType);
