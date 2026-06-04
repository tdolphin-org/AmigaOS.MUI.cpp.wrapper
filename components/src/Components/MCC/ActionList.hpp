//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Core/ActionRoot.hpp"
#include "MUI/List.hpp"

namespace Components::MCC
{
    class ActionListDispatcher : public ActionDispatcherRoot
    {
      public:
        /// @brief called when entry activated in list
        virtual unsigned long OnActiveEntry() = 0;

        /// @brief called when entry double clicked in list
        virtual unsigned long OnDoubleClickEntry() = 0;
    };

    class ActionListBuilder : public MUI::ListBuilderTemplate<ActionListBuilder, ActionRoot<MUI::List>>
    {
      public:
        ActionListBuilder();

        ActionRoot<MUI::List> object(ActionListDispatcher &dispatcher);
    };
}
