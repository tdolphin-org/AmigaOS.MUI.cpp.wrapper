//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Core/Optional.hpp"
#include "Virtgroup.hpp"

namespace MUI
{
    class Scrollbar;
    /// @brief Scrollgroup objects can be used to supply virtual groups with scrollbars. These scrollbars
    /// automatically adjust according to the virtual and display sizes of the underlying virtual group.
    /// When scrolling is unnecessary, the scrollers might get disabled or disappear, depending on user preferences.
    class Scrollgroup : public Group
    {
      public:
        explicit Scrollgroup(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Scrollgroup(const Root &root)
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

        /// @brief [ @b MUIA_Scrollgroup_Contents ]
        /// Returns the Virtgroup object specified during construction.
        Optional<Virtgroup> getContents() const;
        /// @brief [ @b MUIA_Scrollgroup_Contents ]
        /// Returns the raw Object pointer of the Virtgroup child.
        Object *getContentsObject() const;

        /// @brief [ @b MUIA_Scrollgroup_HorizBar ]
        /// Returns the scrollbar object for horizontal scrolling. Can be nullptr in a vertical only scrollgroup.
        Optional<Scrollbar> getHorizBar() const;
        /// @brief [ @b MUIA_Scrollgroup_HorizBar ]
        /// Returns the raw Object pointer of the horizontal scrollbar.
        Object *getHorizBarObject() const;

        /// @brief [ @b MUIA_Scrollgroup_VertBar ]
        /// Returns the scrollbar object for vertical scrolling. Can be nullptr in a horizontal only scrollgroup.
        Optional<Scrollbar> getVertBar() const;
        /// @brief [ @b MUIA_Scrollgroup_VertBar ]
        /// Returns the raw Object pointer of the vertical scrollbar.
        Object *getVertBarObject() const;

#ifdef MUIA_Scrollgroup_AutoBars
        /// @brief [ @b MUIA_Scrollgroup_AutoBars ]
        /// Returns whether the scroll group's scrollbars appear and vanish on demand.
        bool getAutoBars() const;
        /// @brief [ @b MUIA_Scrollgroup_AutoBars ]
        /// Specify if a scroll group's scrollbars should appear and vanish on demand.
        Scrollgroup &setAutoBars(const bool autoBars);
#endif
#ifdef MUIA_Scrollgroup_NoHorizBar
        /// @brief [ @b MUIA_Scrollgroup_NoHorizBar ]
        /// Returns whether the horizontal scrollbar is suppressed.
        bool getNoHorizBar() const;
        /// @brief [ @b MUIA_Scrollgroup_NoHorizBar ]
        /// Don't add a horizontal scrollbar even if it would be needed.
        Scrollgroup &setNoHorizBar(const bool noHorizBar);
#endif
#ifdef MUIA_Scrollgroup_NoVertBar
        /// @brief [ @b MUIA_Scrollgroup_NoVertBar ]
        /// Returns whether the vertical scrollbar is suppressed.
        bool getNoVertBar() const;
        /// @brief [ @b MUIA_Scrollgroup_NoVertBar ]
        /// Don't add a vertical scrollbar even if it would be needed.
        Scrollgroup &setNoVertBar(const bool noVertBar);
#endif
    };

    template <typename T, typename U> class ScrollgroupBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        ScrollgroupBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Scrollgroup)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Scrollgroup_AutoBars
        /// @brief [ @b MUIA_Scrollgroup_AutoBars ]
        /// Specify if a scroll group's scrollbars should appear and vanish on demand. Defaults to false.
        T &tagAutoBars(const bool autoBars);
#endif
        /// @brief [ @b MUIA_Scrollgroup_Contents ]
        /// You have to specify an object of Virtgroup class here.
        T &tagContents(const Object *contents);
        /// @brief [ @b MUIA_Scrollgroup_Contents ]
        /// You have to specify an object of Virtgroup class here.
        T &tagContents(const Virtgroup &contents);
        /// @brief [ @b MUIA_Scrollgroup_FreeHoriz ]
        /// Specify if a scroll group should be horizontally moveable. Defaults to true.
        T &tagFreeHoriz(const bool freeHoriz);
        /// @brief [ @b MUIA_Scrollgroup_FreeVert ]
        /// Specify if a scroll group should be vertically moveable. Defaults to true.
        T &tagFreeVert(const bool freeVert);
#ifdef MUIA_Scrollgroup_NoHorizBar
        /// @brief [ @b MUIA_Scrollgroup_NoHorizBar ]
        /// Don't add a horizontal scrollbar even if it would be needed.
        T &tagNoHorizBar(const bool noHorizBar);
#endif
#ifdef MUIA_Scrollgroup_NoVertBar
        /// @brief [ @b MUIA_Scrollgroup_NoVertBar ]
        /// Don't add a vertical scrollbar even if it would be needed.
        T &tagNoVertBar(const bool noVertBar);
#endif
        /// @brief [ @b MUIA_Scrollgroup_UseWinBorder ]
        /// If set to true, MUI will make this scrollgroup controllable from gadgets in the window border.
        T &tagUseWinBorder(const bool useWinBorder);

      protected:
        bool Validate() const override;
    };

    class ScrollgroupBuilder : public ScrollgroupBuilderTemplate<ScrollgroupBuilder, Scrollgroup>
    {
      public:
        ScrollgroupBuilder();
    };
}

#define MUI_SCROLLGROUP_TPP_INCLUDE
#include "Scrollgroup.tpp"
#undef MUI_SCROLLGROUP_TPP_INCLUDE
