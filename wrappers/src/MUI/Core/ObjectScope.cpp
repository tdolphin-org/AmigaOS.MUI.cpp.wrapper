//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "ObjectScope.hpp"

#include <stdexcept>
#include <string>

#include <proto/muimaster.h>

namespace MUI
{
    ObjectScope::ObjectScope(Object *pObject)
    {
        if (pObject == nullptr)
        {
            std::string error = (std::string) __PRETTY_FUNCTION__ + " nullptr Object!";
            throw std::runtime_error(error);
        }

        mpObject = pObject;
    }

    ObjectScope::~ObjectScope()
    {
        MUI_DisposeObject(mpObject);
    }
}
