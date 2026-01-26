//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Panel.hpp"

#ifdef MUIC_Fontpanel

#include "ValueTypes/Fontpanel/ShowCollection.hpp"

#include <set>

namespace MUI
{
    class Fontpanel : public Panel
    {
      public:
        explicit Fontpanel(Object *pMuiObject)
          : Panel(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class FontpanelBuilderTemplate : public PanelBuilderTemplate<T, U>
    {
      public:
        FontpanelBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Fontpanel)
          : PanelBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Fontpanel_ShowCollection ]
        /// This attribute allows to specify the types of font families to select from. Just pass a value.
        T &tagShowCollection(const enum Fontpanel_ShowCollection showCollection);

        /// @brief [ @b MUIA_Fontpanel_ShowCollection ]
        /// This attribute allows to specify the types of font families to select from.
        /// Just pass set of values for logical OR of the suitable MUIV_Fontpanel_ShowCollection_#? values.
        T &tagShowCollection(const std::set<enum Fontpanel_ShowCollection> showCollections);
    };

    class FontpanelBuilder : public FontpanelBuilderTemplate<FontpanelBuilder, Fontpanel>
    {
      public:
        FontpanelBuilder();
    };
}

#define MUI_FONTPANEL_TPP_INCLUDE
#include "Fontpanel.tpp"
#undef MUI_FONTPANEL_TPP_INCLUDE

#endif
