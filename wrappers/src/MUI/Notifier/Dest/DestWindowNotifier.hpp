//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestNotifyNotifier.hpp"
#include "MUI/Window.hpp"

namespace MUI
{
    class DestWindowNotifier : public DestNotifyNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestWindowNotifier() = delete;
        DestWindowNotifier(const NotifierObject &notifierObject, const Window &window);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Window_Open ]
        DestWindowNotifier &setOpen(const bool open, bool notify = true);
    };
}
