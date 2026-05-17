//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace amiga_std_light
{
    class basic_ostream;
}

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

amiga_std_light::basic_ostream &operator<<(amiga_std_light::basic_ostream &os, const enum MUI::NotifyDestType notifyDestType);
