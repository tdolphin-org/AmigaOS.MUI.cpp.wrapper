//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Semaphore.hpp"

#ifdef MUIC_Datamap

namespace MUI
{
    /// @brief MUI Datamap class wrapper.
    /// Datamap is a key-sorted container for arbitrary data indexed by string keys.
    class Datamap : public Semaphore
    {
      public:
        explicit Datamap(Object *pMuiObject)
          : Semaphore(pMuiObject)
        {
        }

        Datamap(const Root &root)
          : Semaphore(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

#ifdef MUIA_Datamap_Count
        /// @brief [ @b MUIA_Datamap_Count ] Returns the number of stored items in the Datamap object.
        /// @return Number of stored items.
        unsigned long getCount() const;
#endif

        // methods, some returns object reference

#ifdef MUIM_Datamap_Clear
        /// @brief [ @b MUIM_Datamap_Clear ] Remove and free all entries in the Datamap object.
        Datamap &Clear();
#endif

#ifdef MUIM_Datamap_Find
        /// @brief [ @b MUIM_Datamap_Find ] Look up an entry by a key.
        /// @param key Key to look up the entry by.
        /// @return Pointer to stored data or nullptr when the key is not found.
        const void *Find(const char *key) const;

        /// @brief [ @b MUIM_Datamap_Find ] Look up an entry by a key.
        /// @param key Key to look up the entry by.
        /// @return Pointer to stored data or nullptr when the key is not found.
        const void *Find(const std::string &key) const;
#endif

#ifdef MUIM_Datamap_Get
        /// @brief [ @b MUIM_Datamap_Get ] Look up an entry by a key and optionally return its size.
        /// @param key Key to look up the entry by.
        /// @param size Optional pointer receiving entry size.
        /// @return Pointer to stored data or nullptr when the key is not found.
        const void *Get(const char *key, unsigned long *size = nullptr) const;

        /// @brief [ @b MUIM_Datamap_Get ] Look up an entry by a key and optionally return its size.
        /// @param key Key to look up the entry by.
        /// @param size Optional pointer receiving entry size.
        /// @return Pointer to stored data or nullptr when the key is not found.
        const void *Get(const std::string &key, unsigned long *size = nullptr) const;
#endif

#ifdef MUIM_Datamap_Iterate
        /// @brief [ @b MUIM_Datamap_Iterate ] Iterates over stored data entries.
        /// @param counter Pointer to 32-bit iterator storage. Must be zeroed before first iteration.
        /// @return Pointer to stored data or nullptr after the last item.
        const void *Iterate(unsigned long *counter) const;
#endif

#ifdef MUIM_Datamap_IterationKey
        /// @brief [ @b MUIM_Datamap_IterationKey ] Returns key associated with current iteration stage.
        /// @param counter Pointer to iterator storage used by Iterate().
        /// @return Key pointer or nullptr if the counter does not reference a valid entry.
        const char *IterationKey(unsigned long *counter) const;
#endif

#ifdef MUIM_Datamap_Remove
        /// @brief [ @b MUIM_Datamap_Remove ] Removes the entry corresponding to the specified key.
        /// @param key Key to remove.
        /// @return Pointer to removed data or nullptr if no entry matched.
        const void *Remove(const char *key);

        /// @brief [ @b MUIM_Datamap_Remove ] Removes the entry corresponding to the specified key.
        /// @param key Key to remove.
        /// @return Pointer to removed data or nullptr if no entry matched.
        const void *Remove(const std::string &key);
#endif

#ifdef MUIM_Datamap_Set
        /// @brief [ @b MUIM_Datamap_Set ] Adds or changes an entry corresponding to the specified key.
        /// @param data Pointer to data to store.
        /// @param len Size of data.
        /// @param key Key to index data by.
        /// @return true on success, false on failure.
        bool Set(const void *data, const long len, const char *key);

        /// @brief [ @b MUIM_Datamap_Set ] Adds or changes an entry corresponding to the specified key.
        /// @param data Pointer to data to store.
        /// @param len Size of data.
        /// @param key Key to index data by.
        /// @return true on success, false on failure.
        bool Set(const void *data, const long len, const std::string &key);
#endif
    };

    template <typename T, typename U> class DatamapBuilderTemplate : public SemaphoreBuilderTemplate<T, U>
    {
      public:
        DatamapBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Datamap)
          : SemaphoreBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Datamap_AutoLock
        /// @brief [ @b MUIA_Datamap_AutoLock ] Enables automatic locking around Datamap methods.
        T &tagAutoLock(const bool autoLock = true);
#endif

#ifdef MUIA_Datamap_CopyKeys
        /// @brief [ @b MUIA_Datamap_CopyKeys ] Controls whether keys passed to Set() are copied internally.
        T &tagCopyKeys(const bool copyKeys = true);
#endif

#ifdef MUIA_Datamap_Pool
        /// @brief [ @b MUIA_Datamap_Pool ] Sets memory pool used for Datamap internal allocations.
        T &tagPool(const void *pool);
#endif
    };

    class DatamapBuilder : public DatamapBuilderTemplate<DatamapBuilder, Datamap>
    {
      public:
        DatamapBuilder();
    };
}

#define MUI_DATAMAP_TPP_INCLUDE
#include "Datamap.tpp"
#undef MUI_DATAMAP_TPP_INCLUDE

#endif
