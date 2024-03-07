//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "ListAndImageTab.hpp"

#include "MUI/Core/MakeObject.hpp"

namespace Components
{
    ListAndImageTab::ListAndImageTab()
      : mExampleImage(MUI::ImageBuilder()
                          .tagFrame(MUI::Frame::Button)
                          .tagFixWidth(160)
                          .tagFixHeight(160)
                          .tagSpecPicture("PROGDIR:close.160x160.png")
                          .tagFreeHoriz(true)
                          .tagFreeVert(true)
                          .object())
      , mComponent(MUI::GroupBuilder()
                       .horizontal()
                       .tagChild(mHardwareList)
                       .tagChild(MUI::GroupBuilder()
                                     .vertical()
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .tagChild(mExampleImage)
                                     .tagChild(MUI::MakeObject::HVSpace())
                                     .object())
                       .object())
    {
    }
}
