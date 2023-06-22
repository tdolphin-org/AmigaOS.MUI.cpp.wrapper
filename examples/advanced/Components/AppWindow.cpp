//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#include "AppWindow.hpp"

#include "MUI/Context/ApplicationContext.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Group.hpp"

char const *items[] = { "AmigaOS", "MorphOS", "AROS", nullptr };

namespace Components
{
    AppWindow::AppWindow()
    : mItemsList(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).object())
    , mCloseButton(MUI::MakeObject::SimpleButton("_Quit Application"))
    , mComponent(MUI::WindowBuilder()
                  .tagTitle("Window Title")
                  .tagScreenTitle("Application Screen Title")
                  .tagID("MAIN")
                  .tagWidth(600)
                  .tagHeight(240)
                  .tagAltWidth(1024)
                  .tagAltHeight(600)
                  .tagRootObject(MUI::GroupBuilder()
                                     .tagChild(MUI::TextBuilder()
                                                   .tagShortHelp("help text")
                                                   .tagContents(MUIX_C "some centered text in MUI::Text\n\n" MUIX_PH " (c) 2022-2023 TDolphin")
                                                   .object())
                                     .tagChild(mCloseButton)
                                     .tagChild(mItemsList)
                                     .tagChild(MUI::GroupBuilder()
                                                   .horizontal()
                                                   .tagChild(MUI::MakeObject::SimpleButton("_Left Button"))
                                                   .tagChild(MUI::RectangleBuilder().object())
                                                   .tagChild(MUI::MakeObject::SimpleButton("_Right Button"))
                                                   .object())
                                     .object())
                  .object())
    {
    }

    void AppWindow::RegisterEvents()
    {
        auto app = MUI::ApplicationContext::instance().getApplication();

        MUI::Notifier::from(MUI::Area(mCloseButton)).onPressed(false).notifyObject(app).returnIDQuit();
    }
}
