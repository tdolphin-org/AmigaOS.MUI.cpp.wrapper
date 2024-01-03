//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "String.hpp"

namespace MUI
{
    const std::string String::className = MUIC_String;

    std::string String::getContents()
    {
        return GetValueAsString(MUIA_String_Contents);
    }

    String &String::setContents(const std::string &contents)
    {
        SetValue(MUIA_String_Contents, contents);
        return *this;
    }

    String &String::Clear()
    {
        SetValue(MUIA_String_Contents, "");
        return *this;
    }

    StringBuilder::StringBuilder() { }
}
