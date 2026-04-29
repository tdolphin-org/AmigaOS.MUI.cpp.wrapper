//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

#include "Core/MUICompileConfig.hpp"
#include "ValueTypes/Register/Titles.hpp"

namespace MUI
{
    /// @brief Wrapper for MUIC_Register - a multi-page group with user-selectable page titles.
    /// The titles are provided as a NULL-terminated string array describing the group's children,
    /// while the user decides whether they are visualized as a cycle gadget or register tabs.
    class Register : public Group
    {
      public:
        explicit Register(Object *pMuiObject)
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

        /// @brief [ @b MUIA_Register_Titles ] Get the NULL-terminated array of page titles.
        const char **getTitles() const;

#if defined(AOS_MUI_VERSION_5) && defined(MUIA_Register_Titles)
        /// @brief [ @b MUIA_Register_Titles ] Set page titles from a NULL-terminated C string array.
        Register &setTitles(const char *titles[]);
        /// @brief [ @b MUIA_Register_Titles ] Set page titles from a vector of strings copied by this wrapper.
        Register &setTitles(const std::vector<std::string> &titles);
#if defined(MUIV_Register_Titles_UData) && defined(MUIV_Register_Titles_Frame)
        /// @brief [ @b MUIA_Register_Titles ] Set special title source for MUI5-compatible targets.
        Register &setTitles(const enum Register_Titles titles);
#endif
#endif
    };

    template <typename T, typename U> class RegisterBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        RegisterBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Register)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Register_Titles ] Set page titles from a NULL-terminated C string array.
        /// @param pTitles pointer to NULL-terminated array of titles
        T &tagTitles(const char *pTitles[]);
        /// @brief [ @b MUIA_Register_Titles ] Set page titles from a vector of strings copied by this wrapper.
        /// @param pTitles vector of titles copied and stored by this wrapper
        T &tagTitles(const std::vector<std::string> &pTitles);
#if defined(MUIV_Register_Titles_UData) && defined(MUIV_Register_Titles_Frame)
        /// @brief [ @b MUIA_Register_Titles ] Set special title source for targets that support MUIV_Register_Titles_* values.
        T &tagTitles(const enum Register_Titles pTitles);
#endif
    };

    class RegisterBuilder : public RegisterBuilderTemplate<RegisterBuilder, Register>
    {
      public:
        RegisterBuilder();
    };
}

#define MUI_REGISTER_TPP_INCLUDE
#include "Register.tpp"
#undef MUI_REGISTER_TPP_INCLUDE
