//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2025 TDolphin
//

#include "BasicImageButton.hpp"

#include "Components/MCC/ActionImage.hpp"

namespace Components
{
    BasicImageButton::BasicImageButton(const MUI::ImageOrBackground imageOrBackground, const std::string &shortHelp, const long weight)
      : mComponent(MCC::ActionImageBuilder()
                       .tagInputMode(MUI::InputMode::RelVerify)
                       .tagSpec(imageOrBackground)
                       .tagFrame(MUI::Frame::Button)
                       .tagWeight(weight)
                       .tagShortHelp(shortHelp)
                       .object(*this))
    {
    }
}
