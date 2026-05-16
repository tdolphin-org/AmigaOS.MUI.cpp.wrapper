//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "ObjectScope.hpp"

#include <proto/muimaster.h>

#include <stdexcept>
#include <string>

#ifdef TRACE_MUI
#include <cstdio>
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
        std::fprintf(stderr, "%s %p\n", __PRETTY_FUNCTION__, (void *)pObject);
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
        std::fprintf(stderr, "%s MUI_DisposeObject(%p)\n", __PRETTY_FUNCTION__, (void *)mpObject);
#endif

        MUI_DisposeObject(mpObject);
    }
}
