//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "ObjectScope.hpp"

#include <proto/muimaster.h>

#include <stdexcept>
#include <string>

#ifdef TRACE_MUI
#include <iostream>
#endif

namespace MUI
{
    ObjectScope::ObjectScope(const Root &root)
      : mpObject { root }
    {
    }

    ObjectScope::ObjectScope(Object *pObject)
    {
#ifdef TRACE_MUI
        std::cout << __PRETTY_FUNCTION__ << " " << pObject << std::endl;
#endif
        if (pObject == nullptr)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + " nullptr Object!";
            throw std::runtime_error(error);
        }

        mpObject = pObject;
    }

    ObjectScope::~ObjectScope()
    {
#ifdef TRACE_MUI
        std::cout << __PRETTY_FUNCTION__ << " MUI_DisposeObject(" << mpObject << ")" << std::endl;
#endif

        MUI_DisposeObject(mpObject);
    }
}
