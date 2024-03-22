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
        const std::string mClassName;
        /// @brief not empty if class is internal for application, created based od other MUI builtin class
        const std::string mUniqueId;
        unsigned long mStringStorageObjectId;

      public:
        /// @brief
        /// @param uniqueId be default set to empty "", only for internal app class is set
        /// @param className class name: #?.mui, #?.mcc
        BuilderRoot(const std::string &uniqueId, const std::string &className)
          : mUniqueId(uniqueId)
          , mClassName(className)
          , mStringStorageObjectId(0)
        {
        }

        T object() const
        {
            T object = T(mUniqueId.empty() ? muiObject(mClassName, getTags()) : amccObject(mUniqueId, mClassName, getTags()));
            if (mStringStorageObjectId != 0)
                StringStorage::instance().FinalizeObject(mStringStorageObjectId, object);
            return object;
        }

      protected:
        T object(const unsigned long dataSize, const void *pDispatcher) const
        {
            T object = T(mUniqueId.empty() ? muiObject(mClassName, getTags())
                                           : amccObject(mUniqueId, mClassName, getTags(), dataSize, pDispatcher));
            if (mStringStorageObjectId != 0)
                StringStorage::instance().FinalizeObject(mStringStorageObjectId, object);
            return object;
        }

        const char *StoreString(const unsigned long tagName, const std::string &string)
        {
            return StringStorage::instance().Add(mStringStorageObjectId, tagName, string);
        }
    };
}
