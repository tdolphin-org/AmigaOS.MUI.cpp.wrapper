//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Rectangle.hpp"

namespace MUI
{
    const std::string Rectangle::className = MUIC_Rectangle;

    RectangleBuilder::RectangleBuilder() { }

    std::string Rectangle::getBarTitle() const
    {
        return GetValueAsString(MUIA_Rectangle_HBar);
    }

    bool Rectangle::isHBar() const
    {
        return GetValueAsBool(MUIA_Rectangle_HBar);
    }

    bool Rectangle::isVBar() const
    {
        return GetValueAsBool(MUIA_Rectangle_VBar);
    }
}
