//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Floattext.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Floattext::className = MUIC_Floattext;

    bool Floattext::isJustify() const
    {
        return GetValueAsBool(MUIA_Floattext_Justify);
    }

    char *Floattext::getText() const
    {
        return (char *)GetValueAsPtr(MUIA_Floattext_Text);
    }

    Floattext &Floattext::setJustify(const bool justify)
    {
        SetValue(MUIA_Floattext_Justify, justify);
        return *this;
    }

    Floattext &Floattext::setSkipChars(const std::string &skipChars)
    {
        SetValue(MUIA_Floattext_SkipChars, skipChars);
        return *this;
    }

    Floattext &Floattext::setTabSize(const long tabSize)
    {
        SetValue(MUIA_Floattext_TabSize, tabSize);
        return *this;
    }

    Floattext &Floattext::setText(const std::string &text)
    {
        SetValue(MUIA_Floattext_Text, text);
        return *this;
    }

#ifdef MUIM_Floattext_Append
    Floattext &Floattext::Append(const std::string &text)
    {
        DoMethod(muiObject(), MUIM_Floattext_Append, (ULONG)text.c_str());
        return *this;
    }
#endif

    FloattextBuilder::FloattextBuilder() { }
}
