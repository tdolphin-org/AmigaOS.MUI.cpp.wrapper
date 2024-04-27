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
        Poppen(const Object *pMuiObject)
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
    };

    class PoppenBuilder : public PoppenBuilderTemplate<PoppenBuilder, Poppen>
    {
      public:
        PoppenBuilder();
    };
}
