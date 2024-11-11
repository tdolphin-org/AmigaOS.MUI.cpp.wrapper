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
#ifdef MUIV_Notify_ParentParent
        ParentParent = MUIV_Notify_ParentParent,
#endif
#ifdef MUIV_Notify_ParentParentParent
        ParentParentParent = MUIV_Notify_ParentParentParent,
#endif
    };
}

std::ostream &operator<<(std::ostream &os, const enum MUI::NotifyDestType notifyDestType);
