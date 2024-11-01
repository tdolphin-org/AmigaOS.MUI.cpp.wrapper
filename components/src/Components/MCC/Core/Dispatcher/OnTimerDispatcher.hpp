//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "../ActionRoot.hpp"

namespace Components::MCC
{
    class OnTimerDispatcher : virtual public ActionDispatcherRoot
    {
      public:
        /// @brief called when timer
        virtual unsigned long OnTimer() = 0;
    };
}
