//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    class Register : public Group
    {
      public:
        Register(const Object *pMuiObject)
          : Group(pMuiObject)
        {
        }
    };

    template <typename T, typename U> class RegisterBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        RegisterBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Register)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Register_Titles ]
        /// @param pTitles pointer to array (array of char *)
        T &tagTitles(const char *pTitles[]);
    };

    class RegisterBuilder : public RegisterBuilderTemplate<RegisterBuilder, Register>
    {
      public:
        RegisterBuilder();
    };

    template <typename T, typename U> inline T &RegisterBuilderTemplate<T, U>::tagTitles(const char *pTitles[])
    {
        this->PushTag(MUIA_Register_Titles, (const char **)pTitles);
        return (T &)*this;
    }
}