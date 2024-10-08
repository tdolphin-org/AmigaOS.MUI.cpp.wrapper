//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "NList.hpp"
#include "ValueTypes/NListview/HSB.hpp"
#include "ValueTypes/NListview/VSB.hpp"

namespace MUI::MCC
{
    class NListview : public MUI::Area
    {
      public:
        explicit NListview(Object *pObject)
          : Area(pObject)
        {
        }

        NListview(const Root &root)
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

        /// @biref [ @b MUIA_NListview_NList ]
        NList getNList() const;
        /// @biref [ @b MUIA_NListview_Vert_ScrollBar ]
        enum NListview_VSB getVert_ScrollBar() const;
        /// @biref [ @b MUIA_NListview_Horiz_ScrollBar ]
        enum NListview_HSB getHoriz_ScrollBar() const;
        /// @biref [ @b MUIA_NListview_VSB_Width ]
        long getVSB_Width() const;
        /// @biref [ @b MUIA_NListview_HSB_Height ]
        long getHSB_Height() const;

        /// @biref [ @b MUIA_NListview_Vert_ScrollBar ]
        NListview &setVert_ScrollBar(const enum NListview_VSB vert_ScrollBar);
        /// @biref [ @b MUIA_NListview_Horiz_ScrollBar ]
        NListview &setHoriz_ScrollBar(const enum NListview_HSB horiz_ScrollBar);

        // methods, some returns object reference
    };

    class NListviewBuilder : public AreaBuilderTemplate<NListviewBuilder, NListview>
    {
        bool hasNListObject;

      public:
        NListviewBuilder();

        /// @brief [ @b MUIA_NListview_NList ]
        NListviewBuilder &tagNList(const NList &list);
        /// @brief [ @b MUIA_NListview_Vert_ScrollBar ]
        NListviewBuilder &tagVert_ScrollBar(const enum NListview_VSB vert_ScrollBar);
        /// @brief [ @b MUIA_NListview_Horiz_ScrollBar ]
        NListviewBuilder &tagHoriz_ScrollBar(const enum NListview_HSB horiz_ScrollBar);

        NListview object() const;
        NListview object(const unsigned long dataSize, const void *pDispatcher) const;
    };
}
