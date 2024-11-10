//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Scale.hpp"

namespace MUI
{
    const std::string Scale::className = MUIC_Scale;

    ScaleBuilder::ScaleBuilder() { }

#ifdef MUIA_Scale_Horiz
    bool Scale::getHoriz() const
    {
        return GetValueAsBool(MUIA_Scale_Horiz);
    }

    Scale &Scale::setHoriz(const bool horiz)
    {
        SetValue(MUIA_Scale_Horiz, horiz);
        return *this;
    }
#endif
}
