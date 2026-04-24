//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Argstring.hpp"

#ifdef MUIC_Argstring

namespace MUI
{
    const std::string Argstring::className = MUIC_Argstring;

    ArgstringBuilder::ArgstringBuilder() { }

    std::string Argstring::getContents() const
    {
        return GetValueAsString(MUIA_Argstring_Contents);
    }

    std::string Argstring::getTemplate() const
    {
        return GetValueAsString(MUIA_Argstring_Template);
    }

    Argstring &Argstring::setContents(const char *contents)
    {
        SetValue(MUIA_Argstring_Contents, contents);
        return *this;
    }

    Argstring &Argstring::setContents(const std::string &contents)
    {
        SetValue(MUIA_Argstring_Contents, contents);
        return *this;
    }

    Argstring &Argstring::setTemplate(const char *templateValue)
    {
        SetValue(MUIA_Argstring_Template, templateValue);
        return *this;
    }

    Argstring &Argstring::setTemplate(const std::string &templateValue)
    {
        SetValue(MUIA_Argstring_Template, templateValue);
        return *this;
    }
}

#endif
