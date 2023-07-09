//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Text.hpp"

namespace MUI
{
    const std::string Text::className = MUIC_Text;

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
