//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestAreaNotifier.hpp"
#include "MUI/List.hpp"

namespace MUI
{
    enum class ListActivePage;

    class DestListNotifier : public DestAreaNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestListNotifier() = delete;
        DestListNotifier(const NotifierObject &notifierObject, const List &list);
    };
}
