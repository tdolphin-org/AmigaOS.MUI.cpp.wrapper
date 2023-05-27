//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestNotifyNotifier.hpp"
#include "MUI/Application.hpp"

namespace MUI
{
    class Window;

    class DestApplicationNotifier : public DestNotifyNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestApplicationNotifier() = delete;
        DestApplicationNotifier(const NotifierObject &notifierObject, const Application &application);

      public:
        /// @brief [ @b MUIM_Application_AboutMUI ]
        DestApplicationNotifier &aboutMUI(const Window &window);
        /// @brief [ @b MUIM_Application_ReturnID, @b MUIV_Application_ReturnID_Quit ]
        DestApplicationNotifier &returnIDQuit();
        /// @brief [ @b MUIM_Application_ReturnID ]
        DestApplicationNotifier &returnID(const unsigned long returnId);
    };
}
