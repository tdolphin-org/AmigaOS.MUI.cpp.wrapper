//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_SCALE_TPP_INCLUDE
#error "Scale.tpp should only be included by Scale.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Scale_Horiz
    template <typename T, typename U> inline T &ScaleBuilderTemplate<T, U>::tagHoriz(const bool horiz)
    {
        this->PushTag(MUIA_Scale_Horiz, horiz);
        return (T &)*this;
    }
#endif
}
