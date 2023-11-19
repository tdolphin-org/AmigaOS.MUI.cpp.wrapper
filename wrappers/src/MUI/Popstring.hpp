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

        Popstring(const APTR pMuiObject)
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

        /// [ @b MUIA_Popstring_Button ]
        Object *getButton() const;
        /// [ @b MUIA_Popstring_CloseHook ]
        Hook *getCloseHook() const;
        /// [ @b MUIA_Popstring_OpenHook ]
        Hook *getOpenHook() const;
        /// [ @b MUIA_Popstring_String ]
        Object *getString() const;
        /// [ @b MUIA_Popstring_Toggle ]
        bool isToggle() const;

        /// [ @b MUIA_Popstring_CloseHook ]
        Popstring &setCloseHook(const Hook *closeHook);
        /// [ @b MUIA_Popstring_OpenHook ]
        Popstring &setOpenHook(const Hook *openHook);
        /// [ @b MUIA_Popstring_Toggle ]
        Popstring &setToggle(const bool toggle);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Popstring_Close ]
        Popstring &Close(long result);
        /// @brief [ @b MUIM_Popstring_Open ]
        Popstring &Open();
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
        /// @brief [ @b MUIA_Popstring_CloseHook ]
        T &tagCloseHook(const Hook *closeHook);
        /// @brief [ @b MUIA_Popstring_OpenHook ]
        T &tagOpenHook(const Hook *openHook);
        /// @brief [ @b MUIA_Popstring_String ]
        T &tagString(const Object *string);
        /// @brief [ @b MUIA_Popstring_Toggle ]
        T &tagToggle(const bool toggle);
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

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagCloseHook(const Hook *closeHook)
    {
        this->PushTag(MUIA_Popstring_CloseHook, closeHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagOpenHook(const Hook *openHook)
    {
        this->PushTag(MUIA_Popstring_OpenHook, openHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagString(const Object *string)
    {
        this->PushTag(MUIA_Popstring_String, string);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopstringBuilderTemplate<T, U>::tagToggle(const bool toggle)
    {
        this->PushTag(MUIA_Popstring_Toggle, toggle);
        return (T &)*this;
    }
}
