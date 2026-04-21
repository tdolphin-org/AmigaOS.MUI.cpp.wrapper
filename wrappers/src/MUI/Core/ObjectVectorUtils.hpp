//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <intuition/classusr.h>

#include <vector>

namespace MUI
{
    namespace Detail
    {
        std::vector<const Object *> makeNullTerminatedObjectVector(const std::vector<const Object *> &objects);
    }
}
