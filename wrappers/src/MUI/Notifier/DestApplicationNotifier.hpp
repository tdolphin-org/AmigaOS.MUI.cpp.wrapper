//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestNotifyNotifier.hpp"

namespace MUI
{
    class DestApplicationNotifier : public DestNotifyNotifier
    {
        friend class SourceNotifier;

      protected:
        DestApplicationNotifier(const SourceNotifier &sourceNotifier, const Application &application);

      public:
        /// @brief [ @b MUIM_Application_ReturnID, @b MUIV_Application_ReturnID_Quit ]
        DestApplicationNotifier &returnIDQuit();
        /// @brief [ @b MUIM_Application_ReturnID ]
        DestApplicationNotifier &returnID(const unsigned long returnId);
    };
}
