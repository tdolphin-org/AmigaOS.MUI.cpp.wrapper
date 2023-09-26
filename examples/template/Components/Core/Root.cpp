//
//  AmigaOS MUI C++ wrapper
//
//  Application Template
//
//  (c) 20xx XXXXX
//

#include "Root.hpp"

#include <proto/muimaster.h>

namespace Components
{
    void Root::MuiAlert(const std::string &message) const
    {
        auto appObject = muiNotify().getApplicationObject();
        MUI_Request(appObject, (ULONG)NULL, 0, (ULONG)NULL, (char *)"_Ok", (char *)message.c_str(), TAG_END);
    }

    void Root::MuiInfo(const std::string &message, const std::string &gadgets) const
    {
        auto appObject = muiNotify().getApplicationObject();
        MUI_Request(appObject, (ULONG)NULL, 0, (ULONG)NULL, (char *)gadgets.c_str(), (char *)message.c_str(), TAG_END);
    }

    long Root::MuiRequest(const std::string &title, const std::string &message, const std::string &gadgets) const
    {
        auto appObject = muiNotify().getApplicationObject();
        return MUI_Request(appObject, (ULONG)NULL, 0, (char *)title.c_str(), (char *)gadgets.c_str(), (char *)message.c_str(), TAG_END);
    }
}
