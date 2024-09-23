//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <intuition/classusr.h> // Object

#include "Root.hpp"

namespace MUI
{
    /// @brief scope for MUI object, calls @b MUI_DisposeObject on destructor
    class ObjectScope
    {
        Object *mpObject;

      public:
        /// @param pObject pointer to MUI Object
        ObjectScope(const Root &root);
        ObjectScope(Object *pObject);
        ~ObjectScope();

        // explicitly no copy
        ObjectScope(const ObjectScope &) = delete;
        ObjectScope &operator=(const ObjectScope &) = delete;

        // explicitly no move
        ObjectScope(ObjectScope &&) = delete;
        ObjectScope &operator=(ObjectScope &&) = delete;

        Object *muiObject() const
        {
            return mpObject;
        }
    };
};
