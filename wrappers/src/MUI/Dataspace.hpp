//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Semaphore.hpp"
#include "AOS/IFFParse/ValueTypes/IffError.hpp"

struct IFFHandle;

namespace MUI
{
    /// @brief MUI Dataspace class wrapper.
    /// Simple container for arbitrary data items referenced by IDs, with IFF import/export support.
    class Dataspace : public Semaphore
    {
      public:
        explicit Dataspace(Object *pMuiObject)
          : Semaphore(pMuiObject)
        {
        }

        Dataspace(const Root &root)
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

#ifdef MUIA_Dataspace_Count
        /// @brief [ @b MUIA_Dataspace_Count ] Determine the number of entries in the Dataspace object.
        /// @return Number of entries stored in the dataspace.
        unsigned long getCount() const;
#endif

        // methods, some returns object reference

#ifdef MUIM_Dataspace_Add
        /// @brief [ @b MUIM_Dataspace_Add ] Adds or replaces an entry identified by ID.
        /// @param data Pointer to entry data.
        /// @param len Data length in bytes. Negative values are treated as NUL-terminated string length.
        /// @param id Entry reference ID.
        /// @return true on success, false on failure.
        bool Add(const void *data, const long len, const unsigned long id);
#endif

#ifdef MUIM_Dataspace_Clear
        /// @brief [ @b MUIM_Dataspace_Clear ] Clears all entries from the dataspace.
        Dataspace &Clear();
#endif

#ifdef MUIM_Dataspace_Find
        /// @brief [ @b MUIM_Dataspace_Find ] Looks up entry data by ID.
        /// @param id Entry reference ID.
        /// @return Pointer to stored entry data or nullptr if not found.
        const void *Find(const unsigned long id) const;
#endif

#ifdef MUIM_Dataspace_Get
        /// @brief [ @b MUIM_Dataspace_Get ] Looks up entry data by ID and optionally returns its size.
        /// @param id Entry reference ID.
        /// @param size Optional pointer receiving entry size in bytes.
        /// @return Pointer to stored entry data or nullptr if not found.
        const void *Get(const unsigned long id, unsigned long *size = nullptr) const;
#endif

#ifdef MUIM_Dataspace_Merge
        /// @brief [ @b MUIM_Dataspace_Merge ] Merges all entries from another dataspace, replacing equal IDs.
        /// @param dataspace Source dataspace object to merge from.
        /// @return Number of entries added or replaced.
        unsigned long Merge(const Object *dataspace);

        /// @brief [ @b MUIM_Dataspace_Merge ] Merges all entries from another dataspace, replacing equal IDs.
        /// @param dataspace Source dataspace wrapper to merge from.
        /// @return Number of entries added or replaced.
        unsigned long Merge(const Dataspace &dataspace);
#endif

#ifdef MUIM_Dataspace_ReadIFF
        /// @brief [ @b MUIM_Dataspace_ReadIFF ] Reads dataspace entries from current chunk in an IFF handle.
        /// @param handle Open IFF handle positioned on a chunk previously written by Dataspace_WriteIFF.
        /// @return 0 on success or IFFERR_xxx on failure.
        AOS::IFFParse::IFFError ReadIFF(struct IFFHandle *handle);
#endif

#ifdef MUIM_Dataspace_Remove
        /// @brief [ @b MUIM_Dataspace_Remove ] Removes an entry by ID.
        /// @param id Entry reference ID.
        /// @return true if the entry existed and was removed, false otherwise.
        bool Remove(const unsigned long id);
#endif

#ifdef MUIM_Dataspace_WriteIFF
        /// @brief [ @b MUIM_Dataspace_WriteIFF ] Writes dataspace entries into a newly created IFF chunk.
        /// @param handle Open IFF handle initialized for writing.
        /// @param type Chunk type.
        /// @param id Chunk ID.
        /// @return 0 on success or IFFERR_xxx on failure.
        AOS::IFFParse::IFFError WriteIFF(struct IFFHandle *handle, const unsigned long type, const unsigned long id);
#endif
    };

    template <typename T, typename U> class DataspaceBuilderTemplate : public SemaphoreBuilderTemplate<T, U>
    {
      public:
        DataspaceBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Dataspace)
          : SemaphoreBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Dataspace_Pool
        /// @brief [ @b MUIA_Dataspace_Pool ] Sets memory pool used for dataspace entries.
        /// If nullptr is passed or this tag is omitted, the dataspace creates its own pool.
        T &tagPool(const void *pool);
#endif
    };

    class DataspaceBuilder : public DataspaceBuilderTemplate<DataspaceBuilder, Dataspace>
    {
      public:
        DataspaceBuilder();
    };
}

#define MUI_DATASPACE_TPP_INCLUDE
#include "Dataspace.tpp"
#undef MUI_DATASPACE_TPP_INCLUDE
