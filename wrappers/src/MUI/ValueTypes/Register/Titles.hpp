//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
#if defined(MUIV_Register_Titles_UData) && defined(MUIV_Register_Titles_Frame)
    enum class Register_Titles
    {
        UData = MUIV_Register_Titles_UData,
        Frame = MUIV_Register_Titles_Frame,
    };
#endif
}