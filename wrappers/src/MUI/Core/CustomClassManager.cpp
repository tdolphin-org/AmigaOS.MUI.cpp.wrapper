//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "CustomClassManager.hpp"

#include <cstdio>

#include "CustomClassScope.hpp"

namespace MUI
{
    CustomClassesLifeTimeScope::~CustomClassesLifeTimeScope()
    {
#ifdef TRACE_MUI
        std::fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
#endif
        CustomClassManager::instance().Clear();
    }

    CustomClassManagerCore::CustomClassManagerCore() { }

    CustomClassManagerCore::~CustomClassManagerCore()
    {
#ifdef TRACE_MUI
        std::fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
#endif
        if (!mCustomClassesMap.empty())
            std::fprintf(stderr, "%s map is not empty, use CustomClassesLifeTimeScope!\n", __PRETTY_FUNCTION__);
    }

    void CustomClassManagerCore::Clear()
    {
#ifdef TRACE_MUI
        std::fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
#endif

        mCustomClassesMap.clear();
    }

    CustomClassScope &CustomClassManagerCore::get(const std::string &uniqueId, const std::string &superClassName,
                                                  const unsigned long dataSize, const void *dispatcher)
    {
        auto result = mCustomClassesMap.find(uniqueId);
        if (result != mCustomClassesMap.end()) // class scope exists
            return result->second;

        auto emplace = mCustomClassesMap.emplace(uniqueId, CustomClassScope { superClassName, dataSize, dispatcher });

        return emplace.first->second;
    }
}
