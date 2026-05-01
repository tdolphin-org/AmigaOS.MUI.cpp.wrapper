//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Window_ActiveObject
    {
        None = MUIV_Window_ActiveObject_None,
        Next = MUIV_Window_ActiveObject_Next,
        Prev = MUIV_Window_ActiveObject_Prev,
#ifdef MUIV_Window_ActiveObject_Left
        Left = MUIV_Window_ActiveObject_Left,
        Right = MUIV_Window_ActiveObject_Right,
        Up = MUIV_Window_ActiveObject_Up,
        Down = MUIV_Window_ActiveObject_Down,
#endif
    };
}
