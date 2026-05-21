//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "NullObject.hpp"

#ifdef TRACE_MUI
#include "amiga_std_light/iostream.hpp"
#endif

namespace MUI
{
    NullObject::NullObject()
    {
#ifdef TRACE_MUI
        std::cerr << __PRETTY_FUNCTION__ << "\n";
#endif
    }
}
