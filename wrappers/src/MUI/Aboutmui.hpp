//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIC_Aboutmui

#include "Window.hpp"

namespace MUI
{
    /// @brief This class can be used to display a MUI about window in MUI applications.
    class Aboutmui : public Window
    {
      public:
        explicit Aboutmui(Object *pMuiObject)
          : Window(pMuiObject)
        {
        }

        Aboutmui(const Root &root)
          : Window(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }
    };

    template <typename T, typename U> class AboutmuiBuilderTemplate : public WindowBuilderTemplate<T, U>
    {
      public:
        AboutmuiBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Aboutmui)
          : WindowBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Aboutmui_Application ] Inform the Aboutmui object about the application.
        T &tagApplication(const Object *application);
        /// @brief [ @b MUIA_Aboutmui_Application ] Inform the Aboutmui object about the application.
        T &tagApplication(const Root &application);
    };

    class AboutmuiBuilder : public AboutmuiBuilderTemplate<AboutmuiBuilder, Aboutmui>
    {
      public:
        AboutmuiBuilder();
    };
}

#define MUI_ABOUTMUI_TPP_INCLUDE
#include "Aboutmui.tpp"
#undef MUI_ABOUTMUI_TPP_INCLUDE

#endif
