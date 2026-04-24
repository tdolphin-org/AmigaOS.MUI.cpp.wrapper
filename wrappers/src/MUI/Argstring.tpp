//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_ARGSTRING_TPP_INCLUDE
#error "Argstring.tpp should only be included by Argstring.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &ArgstringBuilderTemplate<T, U>::tagContents(const char *contents)
    {
        this->PushTag(MUIA_Argstring_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ArgstringBuilderTemplate<T, U>::tagContents(const std::string &contents)
    {
        this->PushTag(MUIA_Argstring_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ArgstringBuilderTemplate<T, U>::tagTemplate(const char *templateValue)
    {
        this->PushTag(MUIA_Argstring_Template, templateValue);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ArgstringBuilderTemplate<T, U>::tagTemplate(const std::string &templateValue)
    {
        this->PushTag(MUIA_Argstring_Template, templateValue);
        return (T &)*this;
    }
}
