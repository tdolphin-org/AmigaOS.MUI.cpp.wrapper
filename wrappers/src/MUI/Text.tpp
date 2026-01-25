//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_TEXT_TPP_INCLUDE
#error "Text.tpp should only be included by Text.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagContents(const char *contents)
    {
        this->PushTag(MUIA_Text_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagContents(const std::string &contents)
    {
        this->PushTag(MUIA_Text_Contents, contents);
        return (T &)*this;
    }

#ifdef MUIA_Text_ControlChar
    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagControlChar(const char controlChar)
    {
        this->PushTag(MUIA_Text_ControlChar, controlChar);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Text_Copy
    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagCopy(const bool copy)
    {
        this->PushTag(MUIA_Text_Copy, copy);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Text_Data
    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagData(const Object *data)
    {
        this->PushTag(MUIA_Text_Data, data);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagHiChar(const char hiChar)
    {
        this->PushTag(MUIA_Text_HiChar, hiChar);
        return (T &)*this;
    }

#ifdef MUIA_Text_Marking
    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagMarking(const bool marking)
    {
        this->PushTag(MUIA_Text_Marking, marking);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagPreParse(const char *preParse)
    {
        this->PushTag(MUIA_Text_PreParse, preParse);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagPreParse(const std::string &preParse)
    {
        this->PushTag(MUIA_Text_PreParse, preParse);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagSetMax(const bool setMax)
    {
        this->PushTag(MUIA_Text_SetMax, setMax);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagSetMin(const bool setMin)
    {
        this->PushTag(MUIA_Text_SetMin, setMin);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagSetVMax(const bool setVMax)
    {
        this->PushTag(MUIA_Text_SetVMax, setVMax);
        return (T &)*this;
    }

#ifdef MUIA_Text_Shorten
    template <typename T, typename U> inline T &TextBuilderTemplate<T, U>::tagShorten(const enum Text_Shorten shorten)
    {
        this->PushTag(MUIA_Text_Shorten, (long)shorten);
        return (T &)*this;
    }
#endif
}
