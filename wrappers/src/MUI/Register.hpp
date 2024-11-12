//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
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

        /// @brief [ @b MUIA_Register_Titles ]
        char **getTitles() const;

#if MUIMASTER_VMIN >= 20 // MUI5
        /// @brief [ @b MUIA_Register_Titles ]
        Register &setTitles(const char *titles[]);
#endif
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

    template <typename T, typename U> inline T &RegisterBuilderTemplate<T, U>::tagTitles(const char *titles[])
    {
        this->PushTag(MUIA_Register_Titles, (const char **)titles);
        return (T &)*this;
    }
}
