//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "ObjectVectorUtils.hpp"

namespace MUI
{
    namespace Detail
    {
        std::vector<const Object *> makeNullTerminatedObjectVector(const std::vector<const Object *> &objects)
        {
            std::vector<const Object *> orderedObjects;
            orderedObjects.reserve(objects.size() + 1);
            for (auto object : objects)
            {
                if (object)
                    orderedObjects.push_back(object);
            }
            orderedObjects.push_back(nullptr);
            return orderedObjects;
        }
    }
}
