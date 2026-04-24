//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_ABOUTMUI_TPP_INCLUDE
#error "Aboutmui.tpp should only be included by Aboutmui.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &AboutmuiBuilderTemplate<T, U>::tagApplication(const Object *application)
    {
        this->PushTag(MUIA_Aboutmui_Application, application);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AboutmuiBuilderTemplate<T, U>::tagApplication(const Root &application)
    {
        return tagApplication(application.muiObject());
    }
}
