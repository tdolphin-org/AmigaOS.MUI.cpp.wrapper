//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

#include "ValueTypes/Cycle/Active.hpp"

#undef Cycle

namespace MUI
{
    /// @brief MUI Cycle class wrapper.
    /// Cycle class generates well known cycle gadgets with a configurable popup menu.
    class Cycle : public Group
    {
      public:
        explicit Cycle(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Cycle(const Root &root)
          : Group(root.muiObject())
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

        /// @brief [ @b MUIA_Cycle_Active ] Get the index of the currently active cycle entry.
        long getActive() const;

        /// @brief [ @b MUIA_Cycle_Active ] Set the active cycle entry using predefined Cycle_Active values.
        Cycle &setActive(const enum Cycle_Active active);
        /// @brief [ @b MUIA_Cycle_Active, @b MUIV_Cycle_Active_Next ] Select the next cycle entry.
        Cycle &setActiveNext();
        /// @brief [ @b MUIA_Cycle_Active, @b MUIV_Cycle_Active_Prev ] Select the previous cycle entry.
        Cycle &setActivePrev();
        /// @brief [ @b MUIA_Cycle_Active ] Set the active cycle entry by zero-based index.
        Cycle &setActive(const unsigned long active);
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Cycle_Entries ] Set displayed cycle entries using a NULL-terminated C string array.
        Cycle &setEntries(const char *entries[]);
#endif
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Cycle_Entries ]
        /// The string copies are stored internally by this C++ wrapper!
        Cycle &setEntries(const std::vector<std::string> &entries);
#endif
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Cycle_Entries ] Clear entries by explicitly setting the attribute to nullptr.
        Cycle &setEntriesNull();
#endif
    };

    template <typename T, typename U> class CycleBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        CycleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Cycle)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Cycle_Active ]
        /// Defines the number of the active entry in the cycle gadget. Valid range is from 0 for the first entry to NumEntries-1 for the
        /// last.
        T &tagActive(const long active);
        /// @brief [ @b MUIA_Cycle_Entries ]
        /// Define what entries shall be displayed in your cycle gadget. You must supply a pointer to a string array, containing one entry
        /// for each item and terminated with a NULL.
        T &tagEntries(const char *entries[]);

        /// @brief [ @b MUIA_Cycle_Entries ]
        /// Define what entries shall be displayed in your cycle gadget. You must supply a vector of strings, containing one entry
        /// for each item. The string copies are stored internally by this C++ wrapper!
        T &tagEntries(const std::vector<std::string> &entries);

        /// @brief [ @b MUIA_Cycle_Entries ] Clear entries by explicitly setting the builder tag to nullptr.
        T &tagEntriesNull();
    };

    class CycleBuilder : public CycleBuilderTemplate<CycleBuilder, Cycle>
    {
      public:
        CycleBuilder();
    };
}

#define MUI_CYCLE_TPP_INCLUDE
#include "Cycle.tpp"
#undef MUI_CYCLE_TPP_INCLUDE
