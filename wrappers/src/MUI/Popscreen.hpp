//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Popobject.hpp"

namespace MUI
{
    /// @brief This is a private class.
    class Popscreen : public Popobject
    {
      public:
        explicit Popscreen(Object *pMuiObject)
          : Popobject(pMuiObject)
        {
        }

        Popscreen(const Root &root)
          : Popobject(root.muiObject())
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

    template <typename T, typename U> class PopscreenBuilderTemplate : public PopobjectBuilderTemplate<T, U>
    {
      public:
        PopscreenBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popscreen)
          : PopobjectBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class PopscreenBuilder : public PopscreenBuilderTemplate<PopscreenBuilder, Popscreen>
    {
      public:
        PopscreenBuilder();
    };
}

#define MUI_POPSCREEN_TPP_INCLUDE
#include "Popscreen.tpp"
#undef MUI_POPSCREEN_TPP_INCLUDE
