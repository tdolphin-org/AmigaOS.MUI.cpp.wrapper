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
    class OnClickDispatcher : virtual public ActionDispatcherRoot
    {
      public:
        /// @brief called when area clicked (MUIA_Pressed, FALSE)
        virtual unsigned long OnClick() = 0;
    };
}
