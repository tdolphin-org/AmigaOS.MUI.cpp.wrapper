//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AOS/TagItemObject.hpp"
#include "Core/ToString.hpp"

#include <vector>

namespace MUI
{
    Object *muiObject(const std::string &className, const std::vector<AOS::TagItemObject> &tags);
    /// @brief application (internal) mui custom class
    Object *amccObject(const std::string &uniqueId, const std::string &className, const std::vector<AOS::TagItemObject> &tags,
                       const unsigned long dataSize = 0, const void *pDispatcher = nullptr);
}
