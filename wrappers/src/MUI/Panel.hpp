//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

#ifdef MUIC_Panel

namespace MUI
{
    class Application;
    class Window;

    /// @brief MUI Panel class wrapper.
    /// Abstract base class for ASL-like selector panels.
    class Panel : public Group
    {
      public:
        explicit Panel(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // methods, some returns object reference

#ifdef MUIM_Panel_Run
        /// @brief [ @b MUIM_Panel_Run ]
        /// Opens the panel window and runs the panel asynchronously to the main MUI application in a separate process.
        /// @param app Application wrapper used as async context.
        /// @param win Window wrapper containing this panel.
        /// @return Reference to this panel.
        Panel &Run(Application &app, Window &win);
#endif
    };

    template <typename T, typename U> class PanelBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        PanelBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Panel)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class PanelBuilder : public PanelBuilderTemplate<PanelBuilder, Panel>
    {
      public:
        PanelBuilder();
    };
}

#endif
