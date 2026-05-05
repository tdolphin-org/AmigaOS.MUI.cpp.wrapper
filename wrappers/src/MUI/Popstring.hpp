//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    /// @brief Popstring class is the base class for creating so called popup objects. Usually,
    /// a popup consists of a string or text gadget, followed by a little button. Pressing this
    /// button brings up a little window with a listview and lets the user choose an entry with the mouse.
    class Popstring : public Group
    {
      public:
        explicit Popstring(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Popstring(const Root &root)
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

        /// @brief [ @b MUIA_Popstring_Button ] Specify the button object to be used in the popup.
        /// Depending on the type of your popup, you should use an image button with MUII_PopUp,
        /// MUII_PopFile or MUII_PopDrawer here.
        Object *getButton() const;
        /// @brief [ @b MUIA_Popstring_CloseHook ] Whenever the popup receives a MUIM_Popstring_Close
        /// method and the popup is currently opened, this hook will be called.
        Hook *getCloseHook() const;
        /// @brief [ @b MUIA_Popstring_OpenHook ] Whenever the popup receives a MUIM_Popstring_Open
        /// method, this hook will be called.
        Hook *getOpenHook() const;
        /// @brief [ @b MUIA_Popstring_String ] Specify the string object to be used in the popup.
        /// This does not necessarily need to be a real string object, using text objects or even
        /// complete groups of other objects is perfectly ok.
        Object *getString() const;
        /// @brief [ @b MUIA_Popstring_Toggle ] Set/Clear the toggle mode for a popstring object.
        /// With toggling disabled, the popup button will get disabled whenever the user hits it and
        /// the popup opens. With toggling enabled, the popup button always stays enabled and can be
        /// used to cancel the popup.
        bool isToggle() const;

        /// @brief [ @b MUIA_Popstring_CloseHook ] Whenever the popup receives a MUIM_Popstring_Close
        /// method and the popup is currently opened, this hook will be called.
        Popstring &setCloseHook(const Hook *closeHook);
        /// @brief [ @b MUIA_Popstring_OpenHook ] Whenever the popup receives a MUIM_Popstring_Open
        /// method, this hook will be called.
        Popstring &setOpenHook(const Hook *openHook);
        /// @brief [ @b MUIA_Popstring_Toggle ] Set/Clear the toggle mode for a popstring object.
        /// With toggling disabled, the popup button will get disabled whenever the user hits it and
        /// the popup opens. With toggling enabled, the popup button always stays enabled and can be
        /// used to cancel the popup.
        Popstring &setToggle(const bool toggle);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Popstring_Close ] Close the popup. In fact, it only calls the predefined
        /// MUIA_Popstring_CloseHook with the supplied success parameter.
        /// @param result success parameter passed to the close hook (LONG).
        Popstring &Close(long result);
        /// @brief [ @b MUIM_Popstring_Open ] Open the popup. In fact, it only calls the predefined
        /// MUIA_Popstring_OpenHook and checks its return value. In case of TRUE, the popup button
        /// object is disabled as long as MUIA_Popstring_Toggle is unset.
        Popstring &Open();
    };

    template <typename T, typename U> class PopstringBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        PopstringBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popstring)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Popstring_Button ] Specify the button object to be used in the popup.
        /// Depending on the type of your popup, you should use an image button with MUII_PopUp,
        /// MUII_PopFile or MUII_PopDrawer here.
        T &tagButton(const Object *button);
        /// @brief [ @b MUIA_Popstring_CloseHook ] Whenever the popup receives a MUIM_Popstring_Close
        /// method and the popup is currently opened, this hook will be called.
        T &tagCloseHook(const Hook *closeHook);
        /// @brief [ @b MUIA_Popstring_OpenHook ] Whenever the popup receives a MUIM_Popstring_Open
        /// method, this hook will be called.
        T &tagOpenHook(const Hook *openHook);
        /// @brief [ @b MUIA_Popstring_String ] Specify the string object to be used in the popup.
        /// This does not necessarily need to be a real string object, using text objects or even
        /// complete groups of other objects is perfectly ok.
        T &tagString(const Object *string);
        /// @brief [ @b MUIA_Popstring_Toggle ] Set/Clear the toggle mode for a popstring object.
        /// With toggling disabled, the popup button will get disabled whenever the user hits it and
        /// the popup opens. With toggling enabled, the popup button always stays enabled and can be
        /// used to cancel the popup.
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
