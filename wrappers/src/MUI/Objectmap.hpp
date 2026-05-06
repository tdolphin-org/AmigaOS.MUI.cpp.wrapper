//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Semaphore.hpp"

#ifdef MUIC_Objectmap

namespace MUI
{
    /// @brief Objectmap class wrapper.
    /// The Objectmap class is a key-sorted container for MUI objects using string keys.
    /// Ownership of inserted objects is transferred to Objectmap until they are removed.
    class Objectmap : public Semaphore
    {
      public:
        explicit Objectmap(Object *pMuiObject)
          : Semaphore(pMuiObject)
        {
        }

        Objectmap(const Root &root)
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

#ifdef MUIA_Objectmap_Count
        /// @brief [ @b MUIA_Objectmap_Count ] Returns the number of stored objects in the Objectmap object.
        /// @return Number of stored objects.
        unsigned long getCount() const;
#endif

        // methods, some returns object reference

#ifdef MUIM_Objectmap_Clear
        /// @brief [ @b MUIM_Objectmap_Clear ] Removes and disposes all objects in the Objectmap.
        Objectmap &Clear();
#endif

#ifdef MUIM_Objectmap_Find
        /// @brief [ @b MUIM_Objectmap_Find ] Looks up an object by key.
        /// @param key Key to look up the object by.
        /// @return Stored object pointer or nullptr when not found.
        Object *Find(const char *key) const;
#endif

#ifdef MUIM_Objectmap_Iterate
        /// @brief [ @b MUIM_Objectmap_Iterate ] Iterates over stored objects using an external iterator counter.
        /// @param counter Pointer to 32-bit iterator storage. Must be zeroed before first iteration.
        /// @return Next stored object or nullptr when iteration is complete.
        Object *Iterate(unsigned long *counter) const;
#endif

#ifdef MUIM_Objectmap_IterationKey
        /// @brief [ @b MUIM_Objectmap_IterationKey ] Returns key associated with current iteration stage.
        /// @param counter Pointer to iterator storage used by Iterate().
        /// @return Key pointer or nullptr if counter does not reference a valid entry.
        const char *IterationKey(unsigned long *counter) const;
#endif

#ifdef MUIM_Objectmap_Remove
        /// @brief [ @b MUIM_Objectmap_Remove ] Removes and returns object ownership for the specified key.
        /// @param key Key to look up the object by.
        /// @return Removed object pointer or nullptr when no key matched.
        Object *Remove(const char *key);
#endif

#ifdef MUIM_Objectmap_Set
        /// @brief [ @b MUIM_Objectmap_Set ] Adds or replaces an object for the specified key.
        /// @param object Object to store in the map.
        /// @param key Key used to index the object.
        /// @return true on success, false on failure.
        bool Set(const Object *object, const char *key);

        /// @brief [ @b MUIM_Objectmap_Set ] Adds or replaces an object for the specified key.
        /// @param object Root wrapper object to store in the map.
        /// @param key Key used to index the object.
        /// @return true on success, false on failure.
        bool Set(const Root &object, const char *key);
#endif
    };

    template <typename T, typename U> class ObjectmapBuilderTemplate : public SemaphoreBuilderTemplate<T, U>
    {
      public:
        ObjectmapBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Objectmap)
          : SemaphoreBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Objectmap_AutoLock
        /// @brief [ @b MUIA_Objectmap_AutoLock ] Enables automatic locking around Objectmap methods.
        T &tagAutoLock(const bool autoLock);
#endif

#ifdef MUIA_Objectmap_CopyKeys
        /// @brief [ @b MUIA_Objectmap_CopyKeys ] Controls whether keys passed to Set() are copied internally.
        T &tagCopyKeys(const bool copyKeys);
#endif

#ifdef MUIA_Objectmap_Pool
        /// @brief [ @b MUIA_Objectmap_Pool ] Sets memory pool used for Objectmap internal allocations.
        T &tagPool(const void *pool);
#endif
    };

    class ObjectmapBuilder : public ObjectmapBuilderTemplate<ObjectmapBuilder, Objectmap>
    {
      public:
        ObjectmapBuilder();
    };
}

#define MUI_OBJECTMAP_TPP_INCLUDE
#include "Objectmap.tpp"
#undef MUI_OBJECTMAP_TPP_INCLUDE

#endif
