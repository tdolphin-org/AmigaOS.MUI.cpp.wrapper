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
#include "MUI/Rectangle.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    AppWindow::AppWindow()
      : mCloseButton(MUI::MakeObject::SimpleButton("_Quit Application"))
      , mContentTabs()
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
                               .tagChild(mContentTabs)
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
    }

    void AppWindow::RegisterEvents()
    {
        auto app = MUI::ApplicationContext::instance().getApplication();

        MUI::Notifier::from(MUI::Area(mCloseButton)).onPressed(false).notifyObject(app).returnIDQuit();
    }
}
