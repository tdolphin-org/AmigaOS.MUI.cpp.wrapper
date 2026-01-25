//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_RECTANGLE_TPP_INCLUDE
#error "Rectangle.tpp should only be included by Rectangle.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &RectangleBuilderTemplate<T, U>::tagBarTitle(const char *barTitle)
    {
        this->PushTag(MUIA_Rectangle_BarTitle, barTitle);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &RectangleBuilderTemplate<T, U>::tagHBar(const bool hBar)
    {
        this->PushTag(MUIA_Rectangle_HBar, hBar);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &RectangleBuilderTemplate<T, U>::tagVBar(const bool vBar)
    {
        this->PushTag(MUIA_Rectangle_VBar, vBar);
        return (T &)*this;
    }
}
