//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "ObjectScope.hpp"

#include "mui.hpp"
#include <proto/muimaster.h>

#include <stdexcept>
#include <string>

#ifdef TRACE_MUI
#include "amiga_std_light/iostream.hpp"
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
        std::cerr << __PRETTY_FUNCTION__ << " " << static_cast<void *>(pObject) << "\n";
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
        std::cerr << __PRETTY_FUNCTION__ << " MUI_DisposeObject(" << static_cast<void *>(mpObject) << ")\n";
#endif

        MUI_DisposeObject(mpObject);
    }
}
