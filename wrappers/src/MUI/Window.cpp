//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#include "Window.hpp"

#include <libraries/iffparse.h>
#include <proto/intuition.h>

namespace MUI
{
    Window &Window::Open()
    {
        SetValue(MUIA_Window_Open, true);
        return *this;
    }

    Window &Window::Close()
    {
        SetValue(MUIA_Window_Open, false);
        return *this;
    }

    WindowBuilder::WindowBuilder()
      : NotifyBuilderTemplate(MUI::EmptyUniqueId, MUIC_Window)
    {
    }

    WindowBuilder &WindowBuilder::tagAltHeight(const long altHeight)
    {
        this->PushTag(MUIA_Window_AltHeight, altHeight);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagAltWidth(const long altWidth)
    {
        this->PushTag(MUIA_Window_AltWidth, altWidth);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagHeight(const long height)
    {
        this->PushTag(MUIA_Window_Height, height);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagID(const char id[4])
    {
        this->PushTag(MUIA_Window_ID, MAKE_ID(id[0], id[1], id[2], id[3]));
        return *this;
    }

    WindowBuilder &WindowBuilder::tagRootObject(const Object *pRootObject)
    {
        this->PushTag(MUIA_Window_RootObject, pRootObject);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagRootObject(const Root &root)
    {
        this->PushTag(MUIA_Window_RootObject, root.muiObject());
        return *this;
    }

    WindowBuilder &WindowBuilder::tagScreenTitle(const char *screenTitle)
    {
        this->PushTag(MUIA_Window_ScreenTitle, screenTitle);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Window_Title, title);
        return *this;
    }

    WindowBuilder &WindowBuilder::tagWidth(const long width)
    {
        this->PushTag(MUIA_Window_Width, width);
        return *this;
    }
}