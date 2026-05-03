//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    /// @brief MUI Virtgroup class wrapper.
    /// Virtgroup class generates special kinds of group objects whose children can be a lot larger than the actual group.
    /// The group acts as a (small) window through which a rectangle area of its contents is visible.
    /// Virtual groups themselves don't offer any scrollbars; those are handled by Scrollgroup class.
    class Virtgroup : public Group
    {
      public:
        explicit Virtgroup(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Virtgroup(const Root &root)
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

        /// @brief [ @b MUIA_Virtgroup_Height ]
        /// Read the virtual height of a virtual group.
        long getHeight() const;
        /// @brief [ @b MUIA_Virtgroup_Left ]
        /// Get the virtual left edge of a virtual group.
        /// The left edge is automatically clipped to be between 0 and (VirtualWidth-DisplayWidth).
        long getLeft() const;
        /// @brief [ @b MUIA_Virtgroup_Left ]
        /// Set the virtual left edge of a virtual group.
        /// The left edge will automatically be clipped to be between 0 and (VirtualWidth-DisplayWidth).
        Virtgroup &setLeft(const long left);
        /// @brief [ @b MUIA_Virtgroup_Top ]
        /// Get the virtual top edge of a virtual group.
        /// The top edge is automatically clipped to be between 0 and (VirtualTop-DisplayTop).
        long getTop() const;
        /// @brief [ @b MUIA_Virtgroup_Top ]
        /// Set the virtual top edge of a virtual group.
        /// The top edge will automatically be clipped to be between 0 and (VirtualTop-DisplayTop).
        Virtgroup &setTop(const long top);
        /// @brief [ @b MUIA_Virtgroup_Width ]
        /// Read the virtual width of a virtual group.
        long getWidth() const;
#ifdef MUIA_Virtgroup_TryFit
        /// @brief [ @b MUIA_Virtgroup_TryFit ]
        /// During a layout, the virtgroup will first try to force a window size large enough to fit the whole object.
        /// In case it still would not fit, the window gets resized to the maximum allowed by the screen size.
        bool getTryFit() const;
        /// @brief [ @b MUIA_Virtgroup_TryFit ]
        /// Set whether the virtgroup should try to force a window size large enough to fit the whole object during layout.
        Virtgroup &setTryFit(const bool tryFit);
#endif
    };

    template <typename T, typename U> class VirtgroupBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        VirtgroupBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Virtgroup)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Virtgroup_Input ]
        /// Specify if a virtual group should be moveable by clicking into it and dragging the mouse.
        /// Defaults to true.
        T &tagInput(const bool input);
        /// @brief [ @b MUIA_Virtgroup_Left ]
        /// Set the initial virtual left edge of a virtual group.
        /// The left edge will automatically be clipped to be between 0 and (VirtualWidth-DisplayWidth).
        T &tagLeft(const long left);
        /// @brief [ @b MUIA_Virtgroup_Top ]
        /// Set the initial virtual top edge of a virtual group.
        /// The top edge will automatically be clipped to be between 0 and (VirtualTop-DisplayTop).
        T &tagTop(const long top);
#ifdef MUIA_Virtgroup_TryFit
        /// @brief [ @b MUIA_Virtgroup_TryFit ]
        /// During a layout, the virtgroup will first try to force a window size large enough to fit the whole object.
        /// In case it still would not fit, the window gets resized to the maximum allowed by the screen size.
        T &tagTryFit(const bool tryFit);
#endif
    };

    class VirtgroupBuilder : public VirtgroupBuilderTemplate<VirtgroupBuilder, Virtgroup>
    {
      public:
        VirtgroupBuilder();
    };
}

#define MUI_VIRTGROUP_TPP_INCLUDE
#include "Virtgroup.tpp"
#undef MUI_VIRTGROUP_TPP_INCLUDE
