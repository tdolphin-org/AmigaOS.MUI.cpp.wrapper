//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "AOS/Identifier.hpp"
#include "Core/BuilderRoot.hpp"
#include "Core/Root.hpp"
#include "Notifier/Core/NotifyDestType.hpp"

#include <libraries/mui.h>
#include <type_traits>
#include <workbench/workbench.h>

namespace MUI
{
    template <typename... Ts> struct AllRootDerived : std::true_type
    {
    };

    template <typename T, typename... Ts>
    struct AllRootDerived<T, Ts...>
      : std::integral_constant<bool,
                               std::is_base_of<Root, typename std::remove_cv<typename std::remove_reference<T>::type>::type>::value
                                   && AllRootDerived<Ts...>::value>
    {
    };

    /// @brief Notify class is superclass of all other MUI classes.
    /// Its main purpose is to handle MUI's notification mechanism, but it also contains useful methods and attributes.
    class Notify : public Root
    {
      public:
        explicit Notify(Object *pMuiObject)
          : Root(pMuiObject)
        {
        }

        Notify(const Root &root)
          : Root(root.muiObject())
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

        /// @brief [ @b MUIA_ApplicationObject ]
        /// Obtain a pointer to the application object that this object belongs to.
        /// Returns NULL if the object is not currently attached to an application.
        Object *getApplicationObject() const;
        /// @brief [ @b MUIA_AppMessage ]
        /// When the window is an AppWindow, this attribute will be set to the AppMessage whenever an icon is dropped on the object.
        /// The pointer is valid only while the notification callback is executing.
        ::AppMessage *getAppMessage() const;
        /// @brief [ @b MUIA_HelpLine ]
        /// Returns the line number in a help file specified with @b MUIA_Application_HelpFile.
        long getHelpLine() const;
        /// @brief [ @b MUIA_HelpNode ]
        /// Returns the node name in a help file specified with @b MUIA_Application_HelpFile.
        std::string getHelpNode() const;
        /// @brief [ @b MUIA_ObjectID ]
        /// Objects with a non-zero ObjectID export their contents during MUIM_Application_Save and import them during MUIM_Application_Load.
        AOS::Identifier getObjectID() const;
        /// @brief [ @b MUIA_Parent ]
        /// Returns a pointer to the parent group/family object that contains this object. Returns NULL if the object has no parent.
        Object *getParent();
        /// @brief [ @b MUIA_Revision ]
        /// Returns the revision number of the object's true class.
        long getRevision() const;
        /// @brief [ @b MUIA_UserData ]
        /// Returns the general purpose user data value stored in this object.
        unsigned long getUserData() const;
        /// @brief [ @b MUIA_Version ]
        /// Returns the version number of the object's true class.
        long getVersion() const;

        /// @brief [ @b MUIA_HelpLine ]
        /// Sets the line number in a help file specified with @b MUIA_Application_HelpFile.
        Notify &setHelpLine(const long helpLine);
        /// @brief [ @b MUIA_HelpNode ]
        /// Sets the node name in a help file specified with @b MUIA_Application_HelpFile.
        Notify &setHelpNode(const std::string &helpNode);
        /// @brief [ @b MUIA_HelpNode ]
        /// Sets the node name in a help file specified with @b MUIA_Application_HelpFile.
        Notify &setHelpNode(const char *helpNode);
        /// @brief [ @b MUIA_NoNotify ]
        /// Setting to true prevents the next attribute change from triggering notifications.
        /// This is a "one time" attribute valid only during the current SetAttrs() call.
        Notify &setNoNotify(const bool noNotify);
#ifdef MUIA_NoNotifyMethod
        /// @brief [ @b MUIA_NoNotifyMethod ]
        /// Sets a specific method ID whose notification will not be triggered on the next attribute change.
        /// Unlike @b MUIA_NoNotify, all other notifications will still fire.
        /// This is a "one time" attribute valid only during the current SetAttrs() call.
        Notify &setNoNotifyMethod(const unsigned long noNotifyMethod);
#endif
        /// @brief [ @b MUIA_ObjectID ]
        /// Sets the object ID. Objects with a non-zero ObjectID export their contents during MUIM_Application_Save and import them during MUIM_Application_Load.
        Notify &setObjectID(const AOS::Identifier &objectID);
        /// @brief [ @b MUIA_UserData ]
        /// Sets the general purpose user data value for this object.
        Notify &setUserData(const unsigned long userData);

        // methods, some returns object reference

#ifdef MUIM_FindObject
        /// @brief [ @b MUIM_FindObject ]
        /// Check if the given object is contained in the object tree of this object.
        /// @return true if the object is found, false otherwise.
        bool FindObject(const Root &findme) const;
        /// @brief [ @b MUIM_FindObject ]
        /// Check if the given object is contained in the object tree of this object.
        /// @return true if the object is found, false otherwise.
        bool FindObject(const Object *findme) const;
#endif
        /// @brief [ @b MUIM_FindUData ]
        /// Walk through the object tree and find the first object with the given @b MUIA_UserData value.
        Object *FindUData(const unsigned long udata) const;
        /// @brief [ @b MUIM_GetUData ]
        /// Walk through the object tree, find the first object with the given @b MUIA_UserData value and get one of its attributes into
        /// storage.
        Object *GetUData(const unsigned long udata, const unsigned long attr, unsigned long *storage);
        /// @brief [ @b MUIM_GetConfigItem ]
        /// Retrieve the value of a MUI prefs configuration item identified by id into storage.
        unsigned long GetConfigItem(const unsigned long id, unsigned long *storage) const;
        /// @brief [ @b MUIM_KillNotify ]
        /// Remove all notifications that have been set up for the given trigger attribute.
        Notify &KillNotify(const unsigned long trigAttr);
        /// @brief [ @b MUIM_KillNotifyObj ]
        /// Remove all notifications for the given trigger attribute that target a specific destination object.
        Notify &KillNotifyObj(const unsigned long trigAttr, const Root &dest);
        /// @brief [ @b MUIM_KillNotifyObj ]
        /// Remove all notifications for the given trigger attribute that target a specific destination object.
        Notify &KillNotifyObj(const unsigned long trigAttr, const Object *dest);
        /// @brief [ @b MUIM_MultiSet ]
        /// Set an attribute to a value on multiple objects at once. The object list is NULL-terminated automatically.
        template <typename... Args>
        Notify &MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0, const Args &...obj)
        {
            static_assert(AllRootDerived<Args...>::value, "MultiSet: all Args must derive from MUI::Root");
            DoMethod(muiObject(), MUIM_MultiSet, attr, val, obj0.muiObject(), obj.muiObject()..., nullptr);
            return *this;
        }
        /// @brief [ @b MUIM_NoNotifySet ]
        /// Set an attribute without triggering any notifications on this object.
        template <typename... Args> Notify &NoNotifySet(const unsigned long attr, const unsigned long val, Args... args)
        {
            DoMethod(muiObject(), MUIM_NoNotifySet, attr, val, args...);
            return *this;
        }

        // --- low-level notification API ---
        // These three doNotify overloads map directly to MUIM_Notify.
        // @note For new code it is recommended to use the higher-level type-safe notification infrastructure
        //       class MUI::Notifiert (see Notifier/ directory).
        //       FIXME: That layer is not yet complete — it will be developed after all wrappers and builders are finished.

        /// @brief [ @b MUIM_Notify ]
        /// Set up a notification: when @a attr changes to @a val, invoke a method on @a destObj.
        /// The number of additional arguments is passed as FollowParams automatically via sizeof...(Args).
        template <typename... Args> Notify &doNotify(const unsigned long attr, const unsigned long val, const Root &destObj, Args... args)
        {
            return doNotify(attr, val, destObj.muiObject(), args...);
        }
        /// @brief [ @b MUIM_Notify ]
        /// Set up a notification: when @a attr changes to @a val, invoke a method on @a destObj.
        /// The number of additional arguments is passed as FollowParams automatically via sizeof...(Args).
        template <typename... Args> Notify &doNotify(const unsigned long attr, const unsigned long val, const Object *destObj, Args... args)
        {
            DoMethod(muiObject(), MUIM_Notify, attr, val, destObj, (unsigned long)sizeof...(Args), args...);
            return *this;
        }
        /// @brief [ @b MUIM_Notify ]
        /// Set up a notification using a predefined destination type (e.g. @b NotifyDestType::Self, @b NotifyDestType::Window).
        /// The number of additional arguments is passed as FollowParams automatically via sizeof...(Args).
        template <typename... Args>
        Notify &doNotify(const unsigned long attr, const unsigned long val, const NotifyDestType destType, Args... args)
        {
            return doNotify(attr, val, reinterpret_cast<const Object *>((unsigned long)destType), args...);
        }

        /// @brief [ @b MUIM_Set ]
        /// Set a single attribute to a value, triggering any registered notifications.
        Notify &Set(const unsigned long attr, const unsigned long val);
        /// @brief [ @b MUIM_SetAsString ]
        /// Set a string attribute using printf-style formatting. The result replaces the attribute value.
        template <typename... Args> Notify &SetAsString(const unsigned long attr, const char *format, Args... args)
        {
            DoMethod(muiObject(), MUIM_SetAsString, attr, format, args...);
            return *this;
        }
        /// @brief [ @b MUIM_SetAsString ]
        /// Set a string attribute using printf-style formatting. The result replaces the attribute value.
        template <typename... Args> Notify &SetAsString(const unsigned long attr, const std::string &format, Args... args)
        {
            return SetAsString(attr, format.c_str(), args...);
        }
        /// @brief [ @b MUIM_SetUData ]
        /// Method tests if the MUIA_UserData of the object contains the given user data (udata) and sets attaribute to value for itself in
        /// this case.
        /// @param udata userdata to look for
        /// @param attr attribute to set
        /// @param val value to set attribute to
        Notify &SetUData(const unsigned long udata, const unsigned long attr, const unsigned long val);
        /// @brief [ @b MUIM_SetUDataOnce ]
        /// Method performs like SetUData(), but stops after finding the first matching object.
        Notify &SetUDataOnce(const unsigned long udata, const unsigned long attr, const unsigned long val);

        /// @brief [ @b MUIM_CallHook ]
        /// Call a standard Amiga hook callback with zero or more parameters.
        template <typename... Args> unsigned long CallHook(const Hook *hook, Args... args)
        {
            return DoMethod(muiObject(), MUIM_CallHook, hook, args...);
        }
        /// @brief [ @b MUIM_Export ]
        /// Export the object's persistent data into the given dataspace. Used with MUIM_Application_Save.
        unsigned long Export(const Root &dataspace);
        /// @brief [ @b MUIM_Import ]
        /// Import the object's persistent data from the given dataspace. Used with MUIM_Application_Load.
        unsigned long Import(const Root &dataspace);
        /// @brief [ @b MUIM_WriteLong ]
        /// Write a long word value to the given memory location. Useful for storing attribute values from notification hooks.
        Notify &WriteLong(const unsigned long value, unsigned long *memory);
        /// @brief [ @b MUIM_WriteString ]
        /// Write a string value to the given memory buffer. Useful for storing string attribute values from notification hooks.
        Notify &WriteString(const char *value, char *memory);
        /// @brief [ @b MUIM_WriteString ]
        /// Write a string value to the given memory buffer. Useful for storing string attribute values from notification hooks.
        Notify &WriteString(const std::string &value, char *memory);
    };

    template <typename T, typename U> class NotifyBuilderTemplate : public BuilderRoot<U>
    {
      public:
        NotifyBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Notify)
          : BuilderRoot<U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_HelpLine ]
        /// Sets the line number in a help file specified with @b MUIA_Application_HelpFile.
        T &tagHelpLine(const long helpLine);
        /// @brief [ @b MUIA_HelpNode ]
        /// Sets the node name in a help file specified with @b MUIA_Application_HelpFile.
        T &tagHelpNode(const std::string &helpNode);
        /// @brief [ @b MUIA_HelpNode ]
        /// Sets the node name in a help file specified with @b MUIA_Application_HelpFile.
        T &tagHelpNode(const char *helpNode);
        /// @brief [ @b MUIA_ObjectID ]
        /// Objects with a non NULL MUIA_ObjectID export their contents during MUIM_Application_Save and import them during
        /// MUIM_Application_Load.
        T &tagObjectID(const AOS::Identifier &idobjectID);
        /// @brief [ @b MUIA_UserData ]
        /// A general purpose value to fill in any kind of information.
        T &tagUserData(const unsigned long userData);
    };

    class NotifyBuilder : public NotifyBuilderTemplate<NotifyBuilder, Notify>
    {
      public:
        NotifyBuilder();
    };
}

#define MUI_NOTIFY_TPP_INCLUDE
#include "Notify.tpp"
#undef MUI_NOTIFY_TPP_INCLUDE
