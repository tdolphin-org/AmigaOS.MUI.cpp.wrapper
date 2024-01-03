//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "CustomClassManager.hpp"

#include <iostream>

#include "CustomClassScope.hpp"

namespace MUI
{
    CustomClassesLifeTimeScope::~CustomClassesLifeTimeScope()
    {
#ifdef TRACE_MUI
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        CustomClassManager::instance().Clear();
    }

    CustomClassManagerCore::CustomClassManagerCore() { }

    CustomClassManagerCore::~CustomClassManagerCore()
    {
#ifdef TRACE_MUI
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        if (!mCustomClassesMap.empty())
            std::cerr << __PRETTY_FUNCTION__ << " map is not empty, use CustomClassesLifeTimeScope!" << std::endl;
    }

    void CustomClassManagerCore::Clear()
    {
#ifdef TRACE_MUI
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

        for (auto item : mCustomClassesMap)
            delete item.second;
        mCustomClassesMap.clear();
    }

    CustomClassScope *CustomClassManagerCore::get(const std::string &uniqueId, const std::string &superClassName,
                                                  const unsigned long dataSize, const void *dispatcher)
    {
        auto result = mCustomClassesMap.find(uniqueId);
        if (result != mCustomClassesMap.end()) // class scope exists
            return result->second;

        auto classScope = new CustomClassScope(superClassName, dataSize, dispatcher);
        mCustomClassesMap.insert({ uniqueId, classScope });

        return classScope;
    }
}
