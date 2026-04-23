//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#ifdef __MORPHOS__
#include <optional>
#else
#include <experimental/optional>
#endif

namespace MUI
{
#ifdef __MORPHOS__
    template <typename T> using Optional = std::optional<T>;
#else
    template <typename T> using Optional = std::experimental::optional<T>;
#endif
}