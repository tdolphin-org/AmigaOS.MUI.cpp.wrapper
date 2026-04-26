//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Popstring.hpp"

namespace MUI
{
    /// @brief MUI Popobject class wrapper.
    /// Popobject takes any MUI object as a popup. It creates a borderless popup window around the
    /// given object and displays it when the user activates the popup button. Hooks allow
    /// synchronisation between the embedded string gadget and the popup object.
    class Popobject : public Popstring
    {
      public:
        explicit Popobject(Object *pMuiObject)
          : Popstring(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Popobject_Follow ] Query whether popup window follows its parent when moved.
        bool isFollow() const;
        /// @brief [ @b MUIA_Popobject_Light ] Query whether popup window is displayed without border and title.
        bool isLight() const;
        /// @brief [ @b MUIA_Popobject_Volatile ] Query whether popup disappears when the popobject is hidden.
        bool isVolatile() const;

        /// @brief [ @b MUIA_Popobject_Object ] Get the popup object.
        Object *getObject() const;
        /// @brief [ @b MUIA_Popobject_ObjStrHook ] Get hook called when the popup is closed (object → string transfer).
        Hook *getObjStrHook() const;
        /// @brief [ @b MUIA_Popobject_StrObjHook ] Get hook called before the popup opens (string → object transfer).
        Hook *getStrObjHook() const;
        /// @brief [ @b MUIA_Popobject_WindowHook ] Get hook called after the popup window is created but before it opens.
        Hook *getWindowHook() const;

        /// @brief [ @b MUIA_Popobject_Follow ] Set whether popup window follows its parent window when moved.
        Popobject &setFollow(const bool follow);
        /// @brief [ @b MUIA_Popobject_Light ] Set whether popup window is displayed without border and title.
        Popobject &setLight(const bool light);
        /// @brief [ @b MUIA_Popobject_Volatile ] Set whether popup disappears when the popobject is hidden.
        Popobject &setVolatile(const bool vol);
        /// @brief [ @b MUIA_Popobject_ObjStrHook ] Set hook called when the popup is closed (object → string transfer).
        Popobject &setObjStrHook(const Hook *objStrHook);
        /// @brief [ @b MUIA_Popobject_StrObjHook ] Set hook called before the popup opens (string → object transfer).
        Popobject &setStrObjHook(const Hook *strObjHook);
        /// @brief [ @b MUIA_Popobject_WindowHook ] Set hook called after the popup window is created but before it opens.
        Popobject &setWindowHook(const Hook *windowHook);
    };

    template <typename T, typename U> class PopobjectBuilderTemplate : public PopstringBuilderTemplate<T, U>
    {
      public:
        PopobjectBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popobject)
          : PopstringBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Popobject_Follow ] Set whether popup window follows parent window at initialization. Defaults to TRUE.
        T &tagFollow(const bool follow);
        /// @brief [ @b MUIA_Popobject_Light ] Set whether popup window is borderless and titleless at initialization. Defaults to TRUE.
        T &tagLight(const bool light);
        /// @brief [ @b MUIA_Popobject_Object ] Set the popup object at initialization.
        T &tagObject(const Object *object);
        /// @brief [ @b MUIA_Popobject_ObjStrHook ] Set close hook (object → string transfer) at initialization.
        T &tagObjStrHook(const Hook *objStrHook);
        /// @brief [ @b MUIA_Popobject_StrObjHook ] Set open hook (string → object transfer) at initialization.
        T &tagStrObjHook(const Hook *strObjHook);
        /// @brief [ @b MUIA_Popobject_Volatile ] Set volatile mode at initialization. Defaults to TRUE.
        T &tagVolatile(const bool vol);
        /// @brief [ @b MUIA_Popobject_WindowHook ] Set window hook at initialization.
        T &tagWindowHook(const Hook *windowHook);
    };

    class PopobjectBuilder : public PopobjectBuilderTemplate<PopobjectBuilder, Popobject>
    {
      public:
        PopobjectBuilder();
    };
}

#define MUI_POPOBJECT_TPP_INCLUDE
#include "Popobject.tpp"
#undef MUI_POPOBJECT_TPP_INCLUDE
