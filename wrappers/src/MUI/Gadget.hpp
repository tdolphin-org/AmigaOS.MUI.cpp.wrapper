//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Gadget : public Area
    {
      public:
        Gadget(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Gadget_Gadget ]
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
