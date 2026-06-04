//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Components/MCC/Core/Dispatcher/OnActiveEntryDispatcher.hpp"
#include "MUI/List.hpp"

namespace Components::MCC
{
    class ActionListBuilder : public MUI::ListBuilderTemplate<ActionListBuilder, ActionRoot<MUI::List>>
    {
      public:
        ActionListBuilder();

        ActionRoot<MUI::List> object(OnActiveEntryDispatcher &dispatcher);
    };
}
