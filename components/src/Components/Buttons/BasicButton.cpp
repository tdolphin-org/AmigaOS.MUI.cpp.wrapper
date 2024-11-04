//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#include "BasicButton.hpp"

#include "Components/MCC/ActionText.hpp"

namespace Components
{
    BasicButton::BasicButton(const std::string &label, const std::string &shortHelp, const long weight)
      : mComponent(MCC::ActionTextBuilder()
                       .tagFont(MUI::Font::Button)
                       .tagInputMode(MUI::InputMode::RelVerify)
                       .tagBackground(MUI::ImageOrBackground::ButtonBack)
                       .tagFrame(MUI::Frame::Button)
                       .tagContents(label)
                       .tagWeight(weight)
                       .tagShortHelp(shortHelp)
                       .object(*this))
    {
    }

    void BasicButton::setLabel(const std::string &label)
    {
        mComponent.setContents(label);
    }
}
