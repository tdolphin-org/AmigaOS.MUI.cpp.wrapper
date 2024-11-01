//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Core/ActionRoot.hpp"
#include "MUI/Cycle.hpp"

namespace Components::MCC
{
    class ActionCycleDispatcher : public ActionDispatcherRoot
    {
      public:
        /// @brief called when cycle active (MUIA_Cycle_Active, MUIV_EveryTime)
        virtual unsigned long OnCycle() = 0;
    };

    class ActionCycleBuilder : public MUI::CycleBuilderTemplate<ActionCycleBuilder, ActionRoot<MUI::Cycle>>
    {
      public:
        ActionCycleBuilder();

        ActionRoot<MUI::Cycle> object(ActionCycleDispatcher &dispatcher);
    };
}
