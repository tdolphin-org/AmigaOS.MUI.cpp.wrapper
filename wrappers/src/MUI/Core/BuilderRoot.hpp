//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AOS/TagBuilderRoot.hpp"
#include "Core/StringStorage.hpp"
#include "Core/ToString.hpp"
#include "Object.hpp"

namespace MUI
{
    static std::string EmptyUniqueId = "";

    template <typename T> class BuilderRoot : public AOS::TagBuilderRoot
    {
        static StringStorage mStringStorage;

        const std::string mClassName;
        /// @brief not empty if class is internal for application, created based od other MUI builtin class
        const std::string mUniqueId;

      public:
        /// @brief
        /// @param uniqueId be default set to empty "", only for internal app class is set
        /// @param className class name: #?.mui, #?.mcc
        BuilderRoot(const std::string &uniqueId, const std::string &className)
          : mUniqueId(uniqueId)
          , mClassName(className)
        {
        }

        T object() const
        {
            return T(mUniqueId.empty() ? muiObject(mClassName, getTags()) : amccObject(mUniqueId, mClassName, getTags()));
        }

      protected:
        T object(const unsigned long dataSize, const void *pDispatcher) const
        {
            return T(mUniqueId.empty() ? muiObject(mClassName, getTags())
                                       : amccObject(mUniqueId, mClassName, getTags(), dataSize, pDispatcher));
        }

        const char *StoreString(const std::string &string)
        {
            return mStringStorage.Add(string);
        }
    };

    template <typename T> StringStorage BuilderRoot<T>::mStringStorage;
}
