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

        ObjectScope(const ObjectScope &other);
        ObjectScope &operator=(const ObjectScope &other);

        ObjectScope(ObjectScope &&other) noexcept;
        ObjectScope &operator=(ObjectScope &&other) noexcept;

        Object *muiObject() const
        {
            return mpObject;
        }
    };
};
