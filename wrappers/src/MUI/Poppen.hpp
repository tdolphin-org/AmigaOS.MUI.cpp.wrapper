//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Pendisplay.hpp"

namespace MUI
{
    class Poppen : public Pendisplay
    {
      public:
        explicit Poppen(Object *pMuiObject)
          : Pendisplay(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class PoppenBuilderTemplate : public PendisplayBuilderTemplate<T, U>
    {
      public:
        PoppenBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Poppen)
          : PendisplayBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Window_Title ]
        /// You can control the window title of the popup window using the MUIA_Window_Title on the Poppen object. It will remember its
        /// value and use it when creating the popup window.
        T &tagWindowTitle(const std::string &title);
    };

    class PoppenBuilder : public PoppenBuilderTemplate<PoppenBuilder, Poppen>
    {
      public:
        PoppenBuilder();
    };

    template <typename T, typename U> inline T &PoppenBuilderTemplate<T, U>::tagWindowTitle(const std::string &title)
    {
        auto copy = this->StoreString(MUIA_ShortHelp, title);
        this->PushTag(MUIA_Window_Title, copy);
        return (T &)*this;
    }
}
