//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Panel.hpp"

#ifdef MUIC_Fontpanel

#ifdef MUIA_Fontpanel_ShowCollection
#include "ValueTypes/Fontpanel/ShowCollection.hpp"
#endif

#include <set>

namespace MUI
{
    /// @brief MUI Fontpanel class wrapper.
    /// MUI replacement for ASL font requesters with extended style, size, color and family selection.
    class Fontpanel : public Panel
    {
      public:
        explicit Fontpanel(Object *pMuiObject)
          : Panel(pMuiObject)
        {
        }

        Fontpanel(const Root &root)
          : Panel(root.muiObject())
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

    template <typename T, typename U> class FontpanelBuilderTemplate : public PanelBuilderTemplate<T, U>
    {
      public:
        FontpanelBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Fontpanel)
          : PanelBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Fontpanel_ShowCollection
        /// @brief [ @b MUIA_Fontpanel_ShowCollection ] Restricts selectable font family types in the font panel.
        /// Pass a single filter flag from Fontpanel_ShowCollection.
        /// @param showCollection Single collection filter value.
        T &tagShowCollection(const enum Fontpanel_ShowCollection showCollection);

        /// @brief [ @b MUIA_Fontpanel_ShowCollection ] Restricts selectable font family types in the font panel.
        /// Pass multiple filter flags combined by logical OR.
        /// @param showCollections Set of filter flags combined with logical OR.
        T &tagShowCollection(const std::set<enum Fontpanel_ShowCollection> &showCollections);
#endif
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
