//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/MCC/Core/ActionRoot.hpp"
#include "MUI/List.hpp"

namespace Components::MCC
{
    class BoardsListBuilder : public MUI::ListBuilderTemplate<BoardsListBuilder, ActionRoot<MUI::List>>
    {
      public:
        BoardsListBuilder();

        ActionRoot<MUI::List> object();
    };
}
