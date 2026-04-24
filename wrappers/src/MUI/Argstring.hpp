//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIC_Argstring

#include "Group.hpp"

namespace MUI
{
    /// @brief Build dynamic GUIs from ReadArgs() templates.
    class Argstring : public Group
    {
      public:
        explicit Argstring(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Argstring_Contents ] Return current contents string.
        std::string getContents() const;
        /// @brief [ @b MUIA_Argstring_Template ] Return current template string.
        std::string getTemplate() const;

        /// @brief [ @b MUIA_Argstring_Contents ] Set contents string.
        Argstring &setContents(const char *contents);
        /// @brief [ @b MUIA_Argstring_Contents ] Set contents string.
        Argstring &setContents(const std::string &contents);
        /// @brief [ @b MUIA_Argstring_Template ] Set template string.
        Argstring &setTemplate(const char *templateValue);
        /// @brief [ @b MUIA_Argstring_Template ] Set template string.
        Argstring &setTemplate(const std::string &templateValue);
    };

    template <typename T, typename U> class ArgstringBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        ArgstringBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Argstring)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Argstring_Contents ] Set initial contents string.
        T &tagContents(const char *contents);
        /// @brief [ @b MUIA_Argstring_Contents ] Set initial contents string.
        T &tagContents(const std::string &contents);
        /// @brief [ @b MUIA_Argstring_Template ] Set initial template string.
        T &tagTemplate(const char *templateValue);
        /// @brief [ @b MUIA_Argstring_Template ] Set initial template string.
        T &tagTemplate(const std::string &templateValue);
    };

    class ArgstringBuilder : public ArgstringBuilderTemplate<ArgstringBuilder, Argstring>
    {
      public:
        ArgstringBuilder();
    };
}

#define MUI_ARGSTRING_TPP_INCLUDE
#include "Argstring.tpp"
#undef MUI_ARGSTRING_TPP_INCLUDE

#endif
