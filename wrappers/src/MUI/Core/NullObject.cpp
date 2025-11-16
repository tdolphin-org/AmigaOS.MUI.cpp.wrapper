//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2025 TDolphin
//

#include "NullObject.hpp"

#ifdef TRACE_MUI
#include <iostream>
#endif

namespace MUI
{
    NullObject::NullObject()
    {
#ifdef TRACE_MUI
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
    }
}
