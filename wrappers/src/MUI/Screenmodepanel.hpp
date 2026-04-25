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
    /// @brief MUI Screenmodepanel class wrapper.
    /// Full-featured replacement for ASL screen mode requesters.
    class Screenmodepanel : public Panel
    {
      public:
        explicit Screenmodepanel(Object *pMuiObject)
          : Panel(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
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
