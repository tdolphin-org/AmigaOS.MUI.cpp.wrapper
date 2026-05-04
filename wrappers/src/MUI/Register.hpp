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
    /// @brief Register class is a special class for handling multi page groups.
    /// Using this class, you only have to supply an array of strings describing the children's
    /// titles. How these titles are visualized, either with a cycle gadget or with a register-like
    /// group, is the choice of the user.
    class Register : public Group
    {
      public:
        explicit Register(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Register(const Root &root)
          : Group(root.muiObject())
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

        /// @brief [ @b MUIA_Register_Titles ] NULL terminated array of strings describing the titles
        /// of your groups children. This array must contain exactly as many entries as your group has children.
        const char **getTitles() const;

#if defined(AOS_MUI_VERSION_5) && defined(MUIA_Register_Titles)
        /// @brief [ @b MUIA_Register_Titles ] NULL terminated array of strings describing the titles
        /// of your groups children. This array must contain exactly as many entries as your group has children.
        Register &setTitles(const char *titles[]);
        /// @brief [ @b MUIA_Register_Titles ] NULL terminated array of strings describing the titles
        /// of your groups children. This array must contain exactly as many entries as your group has children.
        Register &setTitles(const std::vector<std::string> &titles);
#if defined(MUIV_Register_Titles_UData) && defined(MUIV_Register_Titles_Frame)
        /// @brief [ @b MUIA_Register_Titles ] Set special title source using a MUIV_Register_Titles_* value.
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

        /// @brief [ @b MUIA_Register_Titles ] NULL terminated array of strings describing the titles
        /// of your groups children. This array must contain exactly as many entries as your group has children.
        /// @param pTitles pointer to NULL-terminated array of titles
        T &tagTitles(const char *pTitles[]);
        /// @brief [ @b MUIA_Register_Titles ] NULL terminated array of strings describing the titles
        /// of your groups children. This array must contain exactly as many entries as your group has children.
        /// @param pTitles vector of titles copied and stored by this wrapper
        T &tagTitles(const std::vector<std::string> &pTitles);
#if defined(MUIV_Register_Titles_UData) && defined(MUIV_Register_Titles_Frame)
        /// @brief [ @b MUIA_Register_Titles ] Set special title source using a MUIV_Register_Titles_* value.
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
