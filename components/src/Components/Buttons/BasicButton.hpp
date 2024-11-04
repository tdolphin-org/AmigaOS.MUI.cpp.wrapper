//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Components/MCC/Core/Dispatcher/OnClickDispatcher.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    class BasicButton : public Root<MUI::Text>, public MCC::OnClickDispatcher
    {
        MUI::Text mComponent;

      public:
        BasicButton(const std::string &label, const std::string &shortHelp, const long weight = -1);

        void setLabel(const std::string &label);

      public:
        MUI::Text &muiRoot() const
        {
            return (MUI::Text &)mComponent;
        }
    };
}
