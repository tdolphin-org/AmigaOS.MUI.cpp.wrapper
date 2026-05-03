//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

#ifdef MUIC_Keyadjust

namespace MUI
{
    /// @brief MUI Keyadjust class wrapper.
    /// Keyadjust is a special input class for capturing and customizing keyboard key inputs.
    /// It allows configuration of modifiers, key repetition, and alternative input modes.
    class Keyadjust : public Group
    {
      public:
        explicit Keyadjust(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Keyadjust(const Root &root)
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

        /// @brief [ @b MUIA_Keyadjust_AllowDoubleClick ] Query whether double-click events are captured.
        bool getAllowDoubleClick() const;
        /// @brief [ @b MUIA_Keyadjust_AllowMouseEvents ] Query whether mouse events are captured.
        bool getAllowMouseEvents() const;
        /// @brief [ @b MUIA_Keyadjust_AllowMultipleKeys ] Query whether multiple simultaneous key presses are captured.
        bool getAllowMultipleKeys() const;
        /// @brief [ @b MUIA_Keyadjust_AllowTripleClick ] Query whether triple-click events are captured.
        bool getAllowTripleClick() const;
#ifdef MUIA_Keyadjust_ForceKeyCode
        /// @brief [ @b MUIA_Keyadjust_ForceKeyCode ] Return forced key code value (MorphOS MUI5 only).
        unsigned long getForceKeyCode() const;
#endif
        /// @brief [ @b MUIA_Keyadjust_Key ] Return current captured key string.
        std::string getKey() const;

        /// @brief [ @b MUIA_Keyadjust_AllowDoubleClick ] Enable or disable double-click event capture.
        Keyadjust &setAllowDoubleClick(const bool allowDoubleClick);
        /// @brief [ @b MUIA_Keyadjust_AllowMouseEvents ] Enable or disable mouse event capture.
        Keyadjust &setAllowMouseEvents(const bool allowMouseEvents);
        /// @brief [ @b MUIA_Keyadjust_AllowMultipleKeys ] Enable or disable simultaneous multiple key capture.
        Keyadjust &setAllowMultipleKeys(const bool allowMultipleKeys);
        /// @brief [ @b MUIA_Keyadjust_AllowTripleClick ] Enable or disable triple-click event capture.
        Keyadjust &setAllowTripleClick(const bool allowTripleClick);
#ifdef MUIA_Keyadjust_ForceKeyCode
        /// @brief [ @b MUIA_Keyadjust_ForceKeyCode ] Force specific key code value (MorphOS MUI5 only).
        Keyadjust &setForceKeyCode(const unsigned long forceKeyCode);
#endif
        /// @brief [ @b MUIA_Keyadjust_Key ] Set captured key string from C string.
        Keyadjust &setKey(const char *key);
        /// @brief [ @b MUIA_Keyadjust_Key ] Set captured key string from std::string.
        Keyadjust &setKey(const std::string &key);
    };

    template <typename T, typename U> class KeyadjustBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        KeyadjustBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Keyadjust)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Keyadjust_AllowDoubleClick ] Enable or disable double-click event capture during initialization.
        T &tagAllowDoubleClick(const bool allowDoubleClick);
        /// @brief [ @b MUIA_Keyadjust_AllowMouseEvents ] Enable or disable mouse event capture during initialization.
        T &tagAllowMouseEvents(const bool allowMouseEvents);
        /// @brief [ @b MUIA_Keyadjust_AllowMultipleKeys ] Enable or disable simultaneous multiple key capture during initialization.
        T &tagAllowMultipleKeys(const bool allowMultipleKeys);
        /// @brief [ @b MUIA_Keyadjust_AllowTripleClick ] Enable or disable triple-click event capture during initialization.
        T &tagAllowTripleClick(const bool allowTripleClick);
#ifdef MUIA_Keyadjust_ForceKeyCode
        /// @brief [ @b MUIA_Keyadjust_ForceKeyCode ] Force specific key code value during initialization (MorphOS MUI5 only).
        T &tagForceKeyCode(const unsigned long forceKeyCode);
#endif
        /// @brief [ @b MUIA_Keyadjust_Key ] Set initial captured key string from C string.
        T &tagKey(const char *key);
        /// @brief [ @b MUIA_Keyadjust_Key ] Set initial captured key string from std::string.
        T &tagKey(const std::string &key);
    };

    class KeyadjustBuilder : public KeyadjustBuilderTemplate<KeyadjustBuilder, Keyadjust>
    {
      public:
        KeyadjustBuilder();
    };
}

#define MUI_KEYADJUST_TPP_INCLUDE
#include "Keyadjust.tpp"
#undef MUI_KEYADJUST_TPP_INCLUDE

#endif
