//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    class Popstring : public Group
    {
      public:
        Popstring(const Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, MUIC_Popstring);
        }
    };

    template <typename T, typename U> class PopstringBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        PopstringBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popstring)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Popstring_Button ]
        T &tagButton(const Object *button);
        /// @brief [ @b MUIA_Popstring_String ]
        T &tagString(const Object *string);
    };

    class PopstringBuilder : public PopstringBuilderTemplate<PopstringBuilder, Popstring>
    {
      public:
        PopstringBuilder();
    };

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagButton(const Object *button)
    {
        this->PushTag(MUIA_Popstring_Button, button);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagString(const Object *string)
    {
        this->PushTag(MUIA_Popstring_String, string);
        return (T &)*this;
    }
}
