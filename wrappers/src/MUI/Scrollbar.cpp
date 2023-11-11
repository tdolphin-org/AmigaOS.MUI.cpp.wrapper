//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Scrollbar.hpp"

namespace MUI
{
    const std::string Scrollbar::className = MUIC_Scrollbar;

    ScrollbarBuilder::ScrollbarBuilder() { }

#ifndef __MORPHOS__
    unsigned long Scrollbar::getIncDecSize()
    {
        return GetValueAsULong(MUIA_Scrollbar_IncDecSize);
    }

    Scrollbar &Scrollbar::setIncDecSize(unsigned long incDecSize)
    {
        SetValue(MUIA_Scrollbar_IncDecSize, incDecSize);
        return *this;
    }
#endif
}
