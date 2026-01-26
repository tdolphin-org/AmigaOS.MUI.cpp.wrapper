//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_FLOATTEXT_TPP_INCLUDE
#error "File Floattext.tpp can not be included directly, include file Floattext.hpp instead!"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagJustify(const bool justify)
    {
        this->PushTag(MUIA_Floattext_Justify, justify);
        return (T &)*this;
    }

#ifdef MUIA_Floattext_KeepStyles
    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagKeepStyles(const bool keepStyles)
    {
        this->PushTag(MUIA_Floattext_KeepStyles, keepStyles);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagSkipChars(const char *skipChars)
    {
        this->PushTag(MUIA_Floattext_SkipChars, skipChars);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagSkipChars(const std::string &skipChars)
    {
        this->PushTag(MUIA_Floattext_SkipChars, skipChars);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagTabSize(const long tabSize)
    {
        this->PushTag(MUIA_Floattext_TabSize, tabSize);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagText(const char *text)
    {
        this->PushTag(MUIA_Floattext_Text, text);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FloattextBuilderTemplate<T, U>::tagText(const std::string &text)
    {
        this->PushTag(MUIA_Floattext_Text, text);
        return (T &)*this;
    }
}
