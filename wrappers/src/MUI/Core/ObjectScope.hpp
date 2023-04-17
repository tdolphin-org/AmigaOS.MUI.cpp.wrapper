//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <intuition/classusr.h> // Object

namespace MUI
{
    class ObjectScope
    {
        Object *mpObject;

      public:
        /// @param pObject pointer to MUI Object
        ObjectScope(Object *pObject);
        ~ObjectScope();

        Object *object() const // @todo maybe should be named muiObject() ???
        {
            return mpObject;
        }
    };
};
