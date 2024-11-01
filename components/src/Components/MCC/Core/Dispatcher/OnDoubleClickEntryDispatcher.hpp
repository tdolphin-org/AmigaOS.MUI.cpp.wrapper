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
    class OnDoubleClickEntryDispatcher : virtual public ActionDispatcherRoot
    {
      public:
        /// @brief called when entry double clicked in list
        virtual unsigned long OnDoubleClickEntry() = 0;
    };
}
