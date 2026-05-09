//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Pendisplay.hpp"

namespace MUI
{
    /// @brief Poppen class adds input capabilities to its super class Pendisplay. It should be
    /// used if your application allows users to configure some custom pens for rendering. A Poppen
    /// object will appear as kind of a button which displays the currently selected color. When the
    /// user hits the button, a Popup window containing a Penadjust object opens up and lets the
    /// user change the color.
    class Poppen : public Pendisplay
    {
      public:
        explicit Poppen(Object *pMuiObject)
          : Pendisplay(pMuiObject)
        {
        }

        Poppen(const Root &root)
          : Pendisplay(root.muiObject())
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

    template <typename T, typename U> class PoppenBuilderTemplate : public PendisplayBuilderTemplate<T, U>
    {
      public:
        PoppenBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Poppen)
          : PendisplayBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Window_Title ] Control the window title of the popup window.
        /// The Poppen object will remember its value and use it when creating the popup window.
        T &tagWindowTitle(const char *title);

        /// @brief [ @b MUIA_Window_Title ] Control the window title of the popup window.
        /// The Poppen object will remember its value and use it when creating the popup window.
        T &tagWindowTitle(const std::string &title);
    };

    class PoppenBuilder : public PoppenBuilderTemplate<PoppenBuilder, Poppen>
    {
      public:
        PoppenBuilder();
    };
}

#define MUI_POPPEN_TPP_INCLUDE
#include "Poppen.tpp"
#undef MUI_POPPEN_TPP_INCLUDE
