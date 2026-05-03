//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "List.hpp"

namespace MUI
{
    /// @brief MUI Volumelist class wrapper.
    /// Volumelist generates a list of all available volumes.
    /// Since you shouldn't use your own file requester in every application, this class is probably not of much use.
    class Volumelist : public List
    {
      public:
        explicit Volumelist(Object *pMuiObject)
          : List(pMuiObject)
        {
        }

        Volumelist(const Root &root)
          : List(root.muiObject())
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
    };

    template <typename T, typename U> class VolumelistBuilderTemplate : public ListBuilderTemplate<T, U>
    {
      public:
        VolumelistBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Volumelist)
          : ListBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Volumelist_ExampleMode
        /// @brief [ @b MUIA_Volumelist_ExampleMode ]
        /// Switches the list to example mode. Only one entry of each type will be displayed.
        T &tagExampleMode(const bool exampleMode);
#endif
    };

    class VolumelistBuilder : public VolumelistBuilderTemplate<VolumelistBuilder, Volumelist>
    {
      public:
        VolumelistBuilder();
    };
}

#define MUI_VOLUMELIST_TPP_INCLUDE
#include "Volumelist.tpp"
#undef MUI_VOLUMELIST_TPP_INCLUDE
