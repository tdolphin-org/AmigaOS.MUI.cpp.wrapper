//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    class Panel : public Group
    {
      public:
        Panel(const Object *pMuiObject)
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

        /// @brief [ @b MUIM_Panel_Run ]
        /// This method opens the panel window and eventually "runs" the panel asynchronously to the main MUI application in a separate
        /// process.
        /// @param app the application object to let the panel run asynchronously to the main application
        /// @param win the window object containing the panel object
        Panel &Run(Object *app, Object *win);
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
