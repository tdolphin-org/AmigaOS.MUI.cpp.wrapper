//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#include "Root.hpp"

#include <proto/muimaster.h>

namespace Components
{
    void Root::MuiAlert(const std::string &message) const
    {
        auto appObject = muiNotify().getApplicationObject();
#ifdef __MORPHOS__
        auto flags = 0;
#else
        auto flags = MUIV_Requester_Image_Error;
#endif
        MUI_Request(appObject, nullptr, flags, nullptr, (char *)"_Ok", (char *)message.c_str(), TAG_END);
    }

    void Root::MuiWarining(const std::string &message) const
    {
        auto appObject = muiNotify().getApplicationObject();
#ifdef __MORPHOS__
        auto flags = 0;
#else
        auto flags = MUIV_Requester_Image_Warning;
#endif
        MUI_Request(appObject, nullptr, 0, nullptr, (char *)"_Ok", (char *)message.c_str(), TAG_END);
    }

    void Root::MuiInfo(const std::string &message, const std::string &gadgets) const
    {
        auto appObject = muiNotify().getApplicationObject();
        MUI_Request(appObject, nullptr, 0, nullptr, (char *)gadgets.c_str(), (char *)message.c_str(), TAG_END);
    }

    long Root::MuiRequest(const std::string &title, const std::string &message, const std::string &gadgets) const
    {
        auto appObject = muiNotify().getApplicationObject();
        return MUI_Request(appObject, nullptr, 0, (char *)title.c_str(), (char *)gadgets.c_str(), (char *)message.c_str(), TAG_END);
    }
}
