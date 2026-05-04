//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Panel.hpp"

#ifdef MUIC_Screenmodepanel

namespace MUI
{
    /// @brief Screenmodepanel class offers a full featured replacement for ASL screenmode requesters.
    /// As a replacement it understands most of ASL's screenmode requester tags.
    /// It has no own attributes or methods; all configuration is done through inherited Panel attributes.
    class Screenmodepanel : public Panel
    {
      public:
        explicit Screenmodepanel(Object *pMuiObject)
          : Panel(pMuiObject)
        {
        }

        Screenmodepanel(const Root &root)
          : Panel(root.muiObject())
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

    template <typename T, typename U> class ScreenmodepanelBuilderTemplate : public PanelBuilderTemplate<T, U>
    {
      public:
        ScreenmodepanelBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId,
                                       const std::string &muiClassName = MUIC_Screenmodepanel)
          : PanelBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class ScreenmodepanelBuilder : public ScreenmodepanelBuilderTemplate<ScreenmodepanelBuilder, Screenmodepanel>
    {
      public:
        ScreenmodepanelBuilder();
    };
}

#define MUI_SCREENMODEPANEL_TPP_INCLUDE
#include "Screenmodepanel.tpp"
#undef MUI_SCREENMODEPANEL_TPP_INCLUDE

#endif
