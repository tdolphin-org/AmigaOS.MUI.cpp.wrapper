//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AOS/Identifier.hpp"
#include "Core/BuilderRoot.hpp"
#include "Core/Root.hpp"

#include <libraries/mui.h>
#include <workbench/workbench.h>

namespace MUI
{
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

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_ApplicationObject ]
        Object *getApplicationObject() const;
        /// @brief [ @b MUIA_AppMessage ]
        AppMessage *getAppMessage() const;
        /// @brief [ @b MUIA_HelpLine ]
        long getHelpLine() const;
        /// @brief [ @b MUIA_HelpNode ]
        std::string getHelpNode() const;
        /// @brief [ @b MUIA_ObjectID ]
        AOS::Identifier getObjectID() const;
        /// @brief [ @b MUIA_Parent ]
        Object *getParent();
        /// @brief [ @b MUIA_Revision ]
        long getRevision() const;
        /// @brief [ @b MUIA_UserData ]
        unsigned long getUserData() const;
        /// @brief [ @b MUIA_Version ]
        long getVersion() const;

        /// @brief [ @b MUIA_HelpLine ]
        Notify &setHelpLine(const long helpLine);
        /// @brief [ @b MUIA_HelpNode ]
        Notify &setHelpNode(const std::string &helpNode);
        /// @brief [ @b MUIA_NoNotify ]
        Notify &setNoNotify(const bool noNotify);
        /// @brief [ @b MUIA_NoNotifyMethod ]
        Notify &setNoNotifyMethod(const unsigned long noNotifyMethod);
        /// @brief [ @b MUIA_ObjectID ]
        Notify &setObjectID(const AOS::Identifier &objectID);
        /// @brief [ @b MUIA_UserData ]
        Notify &setUserData(const unsigned long userData);

        // methods, some returns object reference

        /// @brief [ @b MUIM_FindObject ]
        Object *FindObject(const Root &findme) const;
        /// @brief [ @b MUIM_FindObject ]
        Object *FindObject(const Object *findme) const;
        /// @brief [ @b MUIM_FindUData ]
        Object *FindUData(const unsigned long udata) const;
        /// @brief [ @b MUIM_GetUData ]
        Object *GetUData(const unsigned long udata, const unsigned long attr, const unsigned long *storage);
        /// @brief [ @b MUIM_KillNotify ]
        Notify &KillNotify(const unsigned long trigAttr);
        /// @brief [ @b MUIM_KillNotifyObj ]
        Notify &KillNotifyObj(const unsigned long trigAttr, const Root &dest);
        /// @brief [ @b MUIM_KillNotifyObj ]
        Notify &KillNotifyObj(const unsigned long trigAttr, const Object *dest);
        /// @brief [ @b MUIM_MultiSet ]
        Notify &MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0);
        Notify &MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0, const Root &obj1);
        Notify &MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0, const Root &obj1, const Root &obj2);
        Notify &MultiSet(const unsigned long attr, const unsigned long val, const Root &obj0, const Root &obj1, const Root &obj2,
                         const Root &obj3);
        /// @brief [ @b MUIM_NoNotifySet ]
        Notify &NoNotifySet(const unsigned long attr, const unsigned long val);
        /// @brief [ @b MUIM_Notify ]
        Notify &doNotify(const unsigned long attr, const unsigned long val, const Root destObj);
        /// @brief [ @b MUIM_Set ]
        Notify &Set(const unsigned long attr, const unsigned long val);
        /// @brief [ @b MUIM_SetAsString ]
        Notify &SetAsString(const unsigned long attr, const std::string &format, const unsigned long val0);
        Notify &SetAsString(const unsigned long attr, const std::string &format, const unsigned long val0, const unsigned long val1);
        Notify &SetAsString(const unsigned long attr, const std::string &format, const unsigned long val0, const unsigned long val1,
                            const unsigned long val2);
        /// @brief [ @b MUIM_SetUData ]
        /// Method tests if the MUIA_UserData of the object contains the given user data (udata) and sets attaribute to value for itself in
        /// this case.
        /// @param udata userdata to look for
        /// @param attr attribute to set
        /// @param val value to set attribute to
        Notify &SetUData(const unsigned long udata, const unsigned long attr, const unsigned long val);
        /// @brief [ @b MUIM_SetUDataOnce ]
        // Method performs like SetUData(), but stops when it has found an object with the given user data (udata).
        Notify &SetUDataOnce(const unsigned long udata, const unsigned long attr, const unsigned long val);
    };

    template <typename T, typename U> class NotifyBuilderTemplate : public BuilderRoot<U>
    {
      public:
        NotifyBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Notify)
          : BuilderRoot<U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_HelpLine ]
        T &tagHelpLine(const long helpLine);
        /// @brief [ @b MUIA_HelpNode ]
        T &tagHelpNode(const std::string &helpNode);
        /// @brief [ @b MUIA_ObjectID ]
        /// Objects with a non NULL MUIA_ObjectID export their contents during MUIM_Application_Save and import them during MUIM_Application_Load.
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

    template <typename T, typename U> T &NotifyBuilderTemplate<T, U>::tagHelpLine(const long helpLine)
    {
        this->PushTag(MUIA_HelpLine, helpLine);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NotifyBuilderTemplate<T, U>::tagHelpNode(const std::string &helpNode)
    {
        this->PushTag(MUIA_HelpNode, helpNode);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NotifyBuilderTemplate<T, U>::tagObjectID(const AOS::Identifier &objectID)
    {
        this->PushTag(MUIA_ObjectID, objectID.value());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NotifyBuilderTemplate<T, U>::tagUserData(const unsigned long userData)
    {
        this->PushTag(MUIA_UserData, userData);
        return (T &)*this;
    }
}
