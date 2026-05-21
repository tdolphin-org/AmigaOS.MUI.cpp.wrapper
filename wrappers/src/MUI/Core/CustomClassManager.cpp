//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "CustomClassManager.hpp"

#include "CustomClassScope.hpp"

#include "amiga_std_light/iostream.hpp"

namespace MUI
{
    CustomClassesLifeTimeScope::~CustomClassesLifeTimeScope()
    {
#ifdef TRACE_MUI
        std::cerr << __PRETTY_FUNCTION__ << "\n";
#endif
        CustomClassManager::instance().Clear();
    }

    CustomClassManagerCore::CustomClassManagerCore() { }

    CustomClassManagerCore::~CustomClassManagerCore()
    {
#ifdef TRACE_MUI
        std::cerr << __PRETTY_FUNCTION__ << "\n";
#endif
        if (!mCustomClassesMap.empty())
            std::cerr << __PRETTY_FUNCTION__ << " map is not empty, use CustomClassesLifeTimeScope!\n";
    }

    void CustomClassManagerCore::Clear()
    {
#ifdef TRACE_MUI
        std::cerr << __PRETTY_FUNCTION__ << "\n";
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
