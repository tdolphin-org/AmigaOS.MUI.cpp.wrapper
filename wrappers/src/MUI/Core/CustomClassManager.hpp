//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include <map>
#include <string>

#include "Core/Singleton.hpp"

namespace MUI
{
    class CustomClassScope;

    /// @brief call CustomClassManager::Clear() on destructor
    class CustomClassesLifeTimeScope
    {
      public:
        ~CustomClassesLifeTimeScope();
    };

    class CustomClassManagerCore
    {
        friend class td::Singleton<CustomClassManagerCore>;
        friend class CustomClassesLifeTimeScope;

        std::map<std::string, CustomClassScope *> mCustomClassesMap;

        CustomClassManagerCore();
        ~CustomClassManagerCore();

        void Clear();

      public:
        /// @brief get or create&get if not exists custom class
        /// @param uniqueId unique id used by manager to identify internal (app) class, for external classes (#?.mcc) use method without this id
        /// @param superClassName name of MUI class (#?.mui)
        /// @param dataSize data size for object
        /// @param dispatcher dispatcher function
        /// @return pointer to CustomClassScope
        CustomClassScope *get(const std::string &uniqueId, const std::string &superClassName, const unsigned long dataSize = 0,
                              const void *dispatcher = nullptr);
    };

    typedef class td::Singleton<CustomClassManagerCore> CustomClassManager;
}
