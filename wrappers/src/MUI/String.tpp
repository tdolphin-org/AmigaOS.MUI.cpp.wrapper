//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_STRING_TPP_INCLUDE
#error "String.tpp should only be included by String.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagContents(const char *contents)
    {
        this->PushTag(MUIA_String_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagContents(const std::string &contents)
    {
        this->PushTag(MUIA_String_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagFormat(const enum String_Format format)
    {
        this->PushTag(MUIA_String_Format, (long)format);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagMaxLen(const long maxLen)
    {
        this->PushTag(MUIA_String_MaxLen, maxLen);
        return (T &)*this;
    }

#ifdef MUIA_String_Multiline
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagMultiline(const bool multiline)
    {
        this->PushTag(MUIA_String_Multiline, multiline);
        return (T &)*this;
    }
#endif

#ifdef MUIA_String_Placeholder
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagPlaceholder(const char *placeholder)
    {
        this->PushTag(MUIA_String_Placeholder, placeholder);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagPlaceholder(const std::string &placeholder)
    {
        this->PushTag(MUIA_String_Placeholder, placeholder);
        return (T &)*this;
    }
#endif
}
