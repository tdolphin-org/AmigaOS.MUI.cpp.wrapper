//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "AppWindow.hpp"

#include "MUI/Context/ApplicationContext.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Group.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    AppWindow::AppWindow()
      : mCloseButton(MUI::MakeObject::SimpleButton("_Quit Application"))
      , mContent()
      , mInfoText(MUI::TextBuilder()
                      .tagFrame(MUI::Frame::String)
                      .tagSetMin(false)
#ifdef MUIA_Text_Shorten
                      .tagShorten(MUI::Text_Shorten::ElideRight)
#endif
                      .object())
      , mComponent(MUI::WindowBuilder()
                       .tagTitle("Window Title")
                       .tagScreenTitle("Application Screen Title")
                       .tagID("MAIN")
                       .tagWidth(600)
                       .tagHeight(240)
                       .tagAltWidth(1024)
                       .tagAltHeight(600)
                       .tagRootObject(
                           MUI::GroupBuilder()
                               .tagChild(MUI::TextBuilder()
                                             .tagShortHelp("some help text")
                                             .tagContents(MUIX_C "some centered text in MUI::Text\n\n" MUIX_PH " (c) 2022-2024 TDolphin")
                                             .object())
                               .tagChild(mCloseButton)
                               .tagChild(mInfoText)
                               .tagChild(mContent)
                               .tagChild(MUI::GroupBuilder()
                                             .horizontal()
                                             .tagChild(MUI::MakeObject::SimpleButton("_Left Button"))
                                             .tagChild(MUI::MakeObject::HVSpace())
                                             .tagChild(MUI::MakeObject::SimpleButton("_Right Button"))
                                             .object())
                               .object())
                       .object())
    {
        mCloseButton.setCycleChain();
        mInfoText.setContents(
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
            "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure "
            "dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non "
            "proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
    }

    void AppWindow::RegisterEvents()
    {
        auto app = MUI::ApplicationContext::instance().getApplication();

        MUI::Notifier::from(MUI::Area(mCloseButton)).onPressed(false).notifyObject(app).returnIDQuit();
    }
}
