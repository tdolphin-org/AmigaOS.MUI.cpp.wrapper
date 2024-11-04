//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Core/Dispatcher/OnClickDispatcher.hpp"
#include "MUI/Text.hpp"

namespace Components::MCC
{
    class ActionTextBuilder : public MUI::TextBuilderTemplate<ActionTextBuilder, ActionRoot<MUI::Text>>
    {
      public:
        ActionTextBuilder();

        ActionRoot<MUI::Text> object(OnClickDispatcher &dispatcher);
    };
}
