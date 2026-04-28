//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#ifdef AOS_MUI_VERSION_5
namespace MUI
{
    namespace ValueTypes
    {
        enum class Selectgroup_Active : long
        {
            Next = MUIV_Selectgroup_Active_Next,
            Prev = MUIV_Selectgroup_Active_Prev
        };
    }
}
#endif // AOS_MUI_VERSION_5
