//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Area.hpp"

#undef String // undef macro from mui.h

namespace MUI
{
    class String : public Area
    {
      public:
        String(const Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_String_Contents ]
        std::string getContents();

        /// @brief [ @b MUIA_String_Contents ]
        String &setContents(const std::string &contents);

        // methods, some can return object reference

        String &Clear();
    };

    template <typename T, typename U> class StringBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        StringBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_String)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_String_Contents ]
        T &tagContents(const char *contents);
        /// @brief [ @b MUIA_String_Contents ]
        T &tagContents(const std::string &contents);
        /// @brief [ @b MUIA_String_MaxLen ]
        T &tagMaxLen(const long maxLen);
        /// @brief [ @b MUIA_String_Placeholder ]
        T &tagPlaceholder(const char *placeholder);
        /// @brief [ @b MUIA_String_Placeholder ]
        T &tagPlaceholder(const std::string &placeholder);
    };

    class StringBuilder : public StringBuilderTemplate<StringBuilder, String>
    {
      public:
        StringBuilder();
    };

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

    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagMaxLen(const long maxLen)
    {
        this->PushTag(MUIA_String_MaxLen, maxLen);
        return (T &)*this;
    }

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
}
