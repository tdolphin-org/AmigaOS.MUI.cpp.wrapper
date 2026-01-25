//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_SLIDER_TPP_INCLUDE
#error "Slider.tpp should only be included by Slider.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &SliderBuilderTemplate<T, U>::tagHoriz(const bool horiz)
    {
        this->PushTag(MUIA_Slider_Horiz, horiz);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &SliderBuilderTemplate<T, U>::tagQuiet(const bool quiet)
    {
        this->PushTag(MUIA_Slider_Quiet, quiet);
        return (T &)*this;
    }
}
