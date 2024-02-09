//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Area.hpp"

#include "ValueTypes/String/Format.hpp"

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

        String(const APTR pMuiObject)
          : Area(pMuiObject)
        {
        }

        String(const Root &root)
          : Area(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_String_Contents ]
        std::string getContents() const;

        /// @brief [ @b MUIA_String_Contents ]
        String &setContents(const std::string &contents);

        // methods, some returns object reference

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
        /// @brief [ @b MUIA_String_Format ]
        T &tagFormat(const enum String_Format format);
        /// @brief [ @b MUIA_String_MaxLen ]
        T &tagMaxLen(const long maxLen);
#ifdef __MORPHOS__
        /// @brief [ @b MUIA_String_Multiline ]
        T &tagMultiline(const bool multiline);
#endif
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

#ifdef __MORPHOS__
    template <typename T, typename U> inline T &StringBuilderTemplate<T, U>::tagMultiline(const bool multiline)
    {
        this->PushTag(MUIA_String_Multiline, multiline);
        return (T &)*this;
    }
#endif

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
