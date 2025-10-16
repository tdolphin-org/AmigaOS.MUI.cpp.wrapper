//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Core/Dispatcher/OnClickDispatcher.hpp"
#include "MUI/Image.hpp"

namespace Components::MCC
{
    class ActionImageBuilder : public MUI::ImageBuilderTemplate<ActionImageBuilder, ActionRoot<MUI::Image>>
    {
      public:
        ActionImageBuilder();

        ActionRoot<MUI::Image> object(OnClickDispatcher &dispatcher);
    };
}
