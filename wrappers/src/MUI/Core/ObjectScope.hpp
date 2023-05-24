//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <intuition/classusr.h> // Object

namespace MUI
{
    /// @brief scope for MUI object, calls @b MUI_DisposeObject on destructor
    class ObjectScope
    {
        Object *mpObject;

      public:
        /// @param pObject pointer to MUI Object
        ObjectScope(Object *pObject);
        ~ObjectScope();

        Object *muiObject() const
        {
            return mpObject;
        }
    };
};
