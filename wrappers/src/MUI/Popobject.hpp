//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Popstring.hpp"

namespace MUI
{
    /// @brief Popobject class takes a MUI object as parameter and uses it as popup. It creates
    /// a borderless popup window around the given object and displays it when the user hits the
    /// popup button. Using this class instead of creating the popup windows yourself prevents
    /// you from having lots of problems.
    class Popobject : public Popstring
    {
      public:
        explicit Popobject(Object *pMuiObject)
          : Popstring(pMuiObject)
        {
        }

        Popobject(const Root &root)
          : Popstring(root.muiObject())
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

        /// @brief [ @b MUIA_Popobject_Follow ] Setting this attribute causes the popup window to
        /// follow its parent window when its moved. Defaults to true.
        bool isFollow() const;
        /// @brief [ @b MUIA_Popobject_Light ] This attribute causes the popup window to be border
        /// and titleless. Defaults to true.
        bool isLight() const;
        /// @brief [ @b MUIA_Popobject_Volatile ] Setting this attribute causes the popup window to
        /// disappear when the corresponding popobject disappears, e.g. because its in a page group
        /// and the user toggled the page. Defaults to true.
        bool isVolatile() const;

        /// @brief [ @b MUIA_Popobject_Object ] Specify the object to pop up. Usually this is a
        /// relatively simple thing like a single listview, but you can of course use group class here
        /// and make rather complex popups.
        Object *getObject() const;
        /// @brief [ @b MUIA_Popobject_ObjStrHook ] When a popup is closed, this hook is called.
        /// You can examine the state of your MUIA_Popobject_Object and set the contents of the string
        /// gadget respectively. Only called when popup is closed with success value TRUE.
        Hook *getObjStrHook() const;
        /// @brief [ @b MUIA_Popobject_StrObjHook ] Before the popup opens, this hook is called.
        /// You can use it to prepare your MUIA_Popobject_Object according to the contents of the
        /// string gadget. Return TRUE if you want the popup to appear, FALSE otherwise.
        Hook *getStrObjHook() const;
        /// @brief [ @b MUIA_Popobject_WindowHook ] If specified, this hook is called immediately
        /// after the popup's window object has been created but before the window is opened.
        Hook *getWindowHook() const;

        /// @brief [ @b MUIA_Popobject_Follow ] Setting this attribute causes the popup window to
        /// follow its parent window when its moved. Defaults to true.
        Popobject &setFollow(const bool follow);
        /// @brief [ @b MUIA_Popobject_Light ] This attribute causes the popup window to be border
        /// and titleless. Defaults to true.
        Popobject &setLight(const bool light);
        /// @brief [ @b MUIA_Popobject_Volatile ] Setting this attribute causes the popup window to
        /// disappear when the corresponding popobject disappears. Defaults to true.
        Popobject &setVolatile(const bool vol);
        /// @brief [ @b MUIA_Popobject_ObjStrHook ] When a popup is closed, this hook is called.
        /// You can examine the state of your MUIA_Popobject_Object and set the contents of the string
        /// gadget respectively. Only called when popup is closed with success value TRUE.
        Popobject &setObjStrHook(const Hook *objStrHook);
        /// @brief [ @b MUIA_Popobject_StrObjHook ] Before the popup opens, this hook is called.
        /// You can use it to prepare your MUIA_Popobject_Object according to the contents of the
        /// string gadget. Return TRUE if you want the popup to appear, FALSE otherwise.
        Popobject &setStrObjHook(const Hook *strObjHook);
        /// @brief [ @b MUIA_Popobject_WindowHook ] If specified, this hook is called immediately
        /// after the popup's window object has been created but before the window is opened.
        Popobject &setWindowHook(const Hook *windowHook);
    };

    template <typename T, typename U> class PopobjectBuilderTemplate : public PopstringBuilderTemplate<T, U>
    {
      public:
        PopobjectBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popobject)
          : PopstringBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Popobject_Follow ] Setting this attribute causes the popup window to
        /// follow its parent window when its moved. Defaults to true.
        T &tagFollow(const bool follow);
        /// @brief [ @b MUIA_Popobject_Light ] This attribute causes the popup window to be border
        /// and titleless. Defaults to true.
        T &tagLight(const bool light);
        /// @brief [ @b MUIA_Popobject_Object ] Specify the object to pop up. Usually this is a
        /// relatively simple thing like a single listview, but you can of course use group class here
        /// and make rather complex popups.
        T &tagObject(const Object *object);
        /// @brief [ @b MUIA_Popobject_ObjStrHook ] When a popup is closed, this hook is called.
        /// You can examine the state of your MUIA_Popobject_Object and set the contents of the string
        /// gadget respectively. Only called when popup is closed with success value TRUE.
        T &tagObjStrHook(const Hook *objStrHook);
        /// @brief [ @b MUIA_Popobject_StrObjHook ] Before the popup opens, this hook is called.
        /// You can use it to prepare your MUIA_Popobject_Object according to the contents of the
        /// string gadget. Return TRUE if you want the popup to appear, FALSE otherwise.
        T &tagStrObjHook(const Hook *strObjHook);
        /// @brief [ @b MUIA_Popobject_Volatile ] Setting this attribute causes the popup window to
        /// disappear when the corresponding popobject disappears. Defaults to true.
        T &tagVolatile(const bool vol);
        /// @brief [ @b MUIA_Popobject_WindowHook ] If specified, this hook is called immediately
        /// after the popup's window object has been created but before the window is opened.
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
