//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_NOTIFY_TPP_INCLUDE
#error "Notify.tpp should only be included by Notify.hpp"
#endif

namespace MUI
{
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
