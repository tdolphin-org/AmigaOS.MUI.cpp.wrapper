//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
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
        explicit String(Object *pMuiObject)
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
#ifdef MUIA_String_Multiline
        /// @brief [ @b MUIA_String_Multiline ]
        T &tagMultiline(const bool multiline);
#endif
#ifdef MUIA_String_Placeholder
        /// @brief [ @b MUIA_String_Placeholder ]
        T &tagPlaceholder(const char *placeholder);
        /// @brief [ @b MUIA_String_Placeholder ]
        T &tagPlaceholder(const std::string &placeholder);
#endif
    };

    class StringBuilder : public StringBuilderTemplate<StringBuilder, String>
    {
      public:
        StringBuilder();
    };
}

#define MUI_STRING_TPP_INCLUDE
#include "String.tpp"
#undef MUI_STRING_TPP_INCLUDE
