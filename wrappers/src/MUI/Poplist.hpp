//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Popobject.hpp"

namespace MUI
{
    /// @brief MUI Poplist class wrapper.
    /// Poplist simplifies creation of popups that contain only a simple list of predefined string entries.
    class Poplist : public Popobject
    {
      public:
        explicit Poplist(Object *pMuiObject)
          : Popobject(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class PoplistBuilderTemplate : public PopobjectBuilderTemplate<T, U>
    {
      public:
        PoplistBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Poplist)
          : PopobjectBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Poplist_Array ] Set popup list entries using a NULL-terminated C string array.
        T &tagArray(const char *array[]);

        /// @brief [ @b MUIA_Poplist_Array ]
        /// Set popup list entries from a vector of strings. The string copies are stored internally by this C++ wrapper.
        T &tagArray(const std::vector<std::string> &array);

        /// @brief [ @b MUIA_Poplist_Array ] Explicitly set popup list array to nullptr.
        T &tagArrayNull();
    };

    class PoplistBuilder : public PoplistBuilderTemplate<PoplistBuilder, Poplist>
    {
      public:
        PoplistBuilder();
    };
}

#define MUI_POPLIST_TPP_INCLUDE
#include "Poplist.tpp"
#undef MUI_POPLIST_TPP_INCLUDE
