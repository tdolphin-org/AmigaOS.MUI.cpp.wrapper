//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    /// @brief Gadget class is the direct common base for many interactive controls.
    class Gadget : public Area
    {
      public:
        explicit Gadget(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Gadget(const Root &root)
          : Area(root.muiObject())
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

        /// @brief [ @b MUIA_Gadget_Gadget ] Read underlying Intuition gadget pointer.
        ::Gadget *getGadget() const;
    };

    template <typename T, typename U> class GadgetBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        GadgetBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Gadget)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class GadgetBuilder : public GadgetBuilderTemplate<GadgetBuilder, Gadget>
    {
      public:
        GadgetBuilder();
    };
}
