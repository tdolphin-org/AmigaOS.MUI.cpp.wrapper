//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Scrollbar.hpp"

namespace MUI
{
    const std::string Scrollbar::className = MUIC_Scrollbar;

    ScrollbarBuilder::ScrollbarBuilder() { }

#ifdef MUIA_Scrollbar_IncDecSize
    unsigned long Scrollbar::getIncDecSize() const
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
