//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    /// @brief MUI Popstring class wrapper.
    /// Popstring is a base class for popup objects composed of a string-like gadget and a popup button.
    class Popstring : public Group
    {
      public:
        explicit Popstring(Object *pMuiObject)
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

        /// @brief [ @b MUIA_Popstring_Button ] Get popup button object used by this popstring.
        Object *getButton() const;
        /// @brief [ @b MUIA_Popstring_CloseHook ] Get hook called when popup is closed.
        Hook *getCloseHook() const;
        /// @brief [ @b MUIA_Popstring_OpenHook ] Get hook called when popup is opened.
        Hook *getOpenHook() const;
        /// @brief [ @b MUIA_Popstring_String ] Get string object associated with this popup.
        Object *getString() const;
        /// @brief [ @b MUIA_Popstring_Toggle ] Query whether toggle mode is enabled.
        bool isToggle() const;

        /// @brief [ @b MUIA_Popstring_CloseHook ] Set hook called when popup is closed.
        Popstring &setCloseHook(const Hook *closeHook);
        /// @brief [ @b MUIA_Popstring_OpenHook ] Set hook called when popup is opened.
        Popstring &setOpenHook(const Hook *openHook);
        /// @brief [ @b MUIA_Popstring_Toggle ] Enable or disable toggle mode for popup button behavior.
        Popstring &setToggle(const bool toggle);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Popstring_Close ] Close the popup by invoking the configured close hook.
        /// @param result Success flag passed to close hook (typically `true` for accept, `false` for cancel).
        Popstring &Close(long result);
        /// @brief [ @b MUIM_Popstring_Open ] Open the popup by invoking the configured open hook.
        Popstring &Open();
    };

    template <typename T, typename U> class PopstringBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        PopstringBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popstring)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Popstring_Button ] Set popup button object at initialization.
        T &tagButton(const Object *button);
        /// @brief [ @b MUIA_Popstring_CloseHook ] Set close hook at initialization.
        T &tagCloseHook(const Hook *closeHook);
        /// @brief [ @b MUIA_Popstring_OpenHook ] Set open hook at initialization.
        T &tagOpenHook(const Hook *openHook);
        /// @brief [ @b MUIA_Popstring_String ] Set popup string object at initialization.
        T &tagString(const Object *string);
        /// @brief [ @b MUIA_Popstring_Toggle ] Enable or disable toggle mode at initialization.
        T &tagToggle(const bool toggle);
    };

    class PopstringBuilder : public PopstringBuilderTemplate<PopstringBuilder, Popstring>
    {
      public:
        PopstringBuilder();
    };
}

#define MUI_POPSTRING_TPP_INCLUDE
#include "Popstring.tpp"
#undef MUI_POPSTRING_TPP_INCLUDE
