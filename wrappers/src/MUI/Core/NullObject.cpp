//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "NullObject.hpp"

#ifdef TRACE_MUI
#include <cstdio>
#endif

namespace MUI
{
    NullObject::NullObject()
    {
#ifdef TRACE_MUI
        std::fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
#endif
    }
}
