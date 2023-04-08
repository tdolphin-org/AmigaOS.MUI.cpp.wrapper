//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#include "Text.hpp"

namespace MUI
{
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
