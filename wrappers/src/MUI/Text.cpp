//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Text.hpp"

namespace MUI
{
    const std::string Text::className = MUIC_Text;

    std::string Text::getContents() const
    {
        return GetValueAsString(MUIA_Text_Contents);
    }

    Text &Text::setContents(const std::string &contents)
    {
        SetValue(MUIA_Text_Contents, contents);
        return *this;
    }

    Text &Text::Clear()
    {
        SetValue(MUIA_Text_Contents, nullptr);
        return *this;
    }

    TextBuilder::TextBuilder() { }
}
