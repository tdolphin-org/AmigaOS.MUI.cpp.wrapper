//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIC_Fontpanel

namespace MUI
{
    enum class Fontpanel_ShowCollection
    {
        All = MUIV_Fontpanel_ShowCollection_All,
        FixedWidth = MUIV_Fontpanel_ShowCollection_FixedWidth,
        Bitmap = MUIV_Fontpanel_ShowCollection_Bitmap,
        TrueType = MUIV_Fontpanel_ShowCollection_TrueType,
        User = MUIV_Fontpanel_ShowCollection_User
    };
}

#endif
