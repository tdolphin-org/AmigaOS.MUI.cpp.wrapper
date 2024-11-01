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
    class OnActiveEntryDispatcher : virtual public ActionDispatcherRoot
    {
      public:
        /// @brief called when entry activated in list
        virtual unsigned long OnActiveEntry() = 0;
    };
}
