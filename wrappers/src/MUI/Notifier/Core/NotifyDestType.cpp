//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "NotifyDestType.hpp"

#include "amiga_std_light/iostream.hpp"

static amiga_std_light::basic_ostream &WriteNotifyDestType(amiga_std_light::basic_ostream &os, const MUI::NotifyDestType notifyDestType)
{
    os << "MUI::NotifyDestType::";

    switch (notifyDestType)
    {
        case MUI::NotifyDestType::GivenObject:
            os << "GivenObject";
            break;
        case MUI::NotifyDestType::Self:
            os << "Self";
            break;
        case MUI::NotifyDestType::Window:
            os << "Window";
            break;
        case MUI::NotifyDestType::Application:
            os << "Application";
            break;
        case MUI::NotifyDestType::Parent:
            os << "Parent";
            break;
#ifdef MUIV_Notify_ParentParent
        case MUI::NotifyDestType::ParentParent:
            os << "ParentParent";
            break;
#endif
#ifdef MUIV_Notify_ParentParentParent
        case MUI::NotifyDestType::ParentParentParent:
            os << "ParentParentParent";
            break;
#endif
        default:
            os << "UNKNOWN";
    }

    return os;
}

amiga_std_light::basic_ostream &operator<<(amiga_std_light::basic_ostream &os, const MUI::NotifyDestType notifyDestType)
{
    return WriteNotifyDestType(os, notifyDestType);
}
