//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "Components/MCC/Core/Dispatcher/OnClickDispatcher.hpp"
#include "MUI/Image.hpp"

namespace Components
{
    class BasicImageButton : public Root<MUI::Image>, public MCC::OnClickDispatcher
    {
        MUI::Image mComponent;

      public:
        BasicImageButton(const MUI::ImageOrBackground imageOrBackground, const std::string &shortHelp, const long weight = -1);

        MUI::Image &muiRoot() const
        {
            return (MUI::Image &)mComponent;
        }
    };
}
