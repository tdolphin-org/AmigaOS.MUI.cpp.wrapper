//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Core/BuilderRoot.hpp"
#include "Core/Root.hpp"

#include <libraries/mui.h>

namespace MUI
{
    class Notify : public Root
    {
      public:
        Notify(const Object *pMuiObject)
          : Root(pMuiObject)
        {
        }

        Notify(const Root &root)
          : Root(root.muiObject())
        {
        }

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_ApplicationObject ]
        Object *getApplicationObject() const;
        /// @brief [ @b MUIA_HelpLine ]
        long getHelpLine() const;
        /// @brief [ @b MUIA_HelpNode ]
        std::string getHelpNode() const;
        /// @brief [ @b MUIA_ObjectID ]
        unsigned long getObjectID() const;
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
        Notify &setObjectID(const unsigned long objectID);
        /// @brief [ @b MUIA_UserData ]
        Notify &setUserData(const unsigned long userData);

        // methods, some can return object reference
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
        T &tagHelpLine(const std::string &helpNode);
        /// @brief [ @b MUIA_ObjectID ]
        T &tagObjectID(const unsigned long objectID);
        /// @brief [ @b MUIA_UserData ]
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

    template <typename T, typename U> inline T &NotifyBuilderTemplate<T, U>::tagHelpLine(const std::string &helpNode)
    {
        this->PushTag(MUIA_HelpLine, helpNode);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NotifyBuilderTemplate<T, U>::tagObjectID(const unsigned long objectID)
    {
        this->PushTag(MUIA_ObjectID, objectID);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NotifyBuilderTemplate<T, U>::tagUserData(const unsigned long userData)
    {
        this->PushTag(MUIA_UserData, userData);
        return (T &)*this;
    }
}
