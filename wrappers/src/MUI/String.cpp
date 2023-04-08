//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#include "String.hpp"

namespace MUI
{
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
