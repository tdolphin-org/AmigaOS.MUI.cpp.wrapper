//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Family.hpp"

#include "ValueTypes/Menuitem/Shortcut.hpp"

namespace MUI
{
    class Menuitem : public Family
    {
      public:
        explicit Menuitem(Object *pMuiObject)
          : Family(pMuiObject)
        {
        }

        Menuitem(const Root &root)
          : Family(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Menuitem_Checked ]
        /// Query whether this menu item is currently checked.
        bool isChecked() const;
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        /// Query whether this menu item is checkmark-capable.
        bool isCheckit() const;
        /// @brief [ @b MUIA_Menuitem_CommandString ]
        /// Query whether the shortcut is interpreted as a command string.
        bool isCommandString() const;
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        /// Query whether this menu item is enabled.
        bool isEnabled() const;
        /// @brief [ @b MUIA_Menuitem_Title ]
        /// Return the current title text of this menu item.
        std::string getTitle() const;
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        /// Query whether this menu item is configured as a toggle item.
        bool isToggle() const;
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        /// Return the current keyboard shortcut string.
        std::string getShortcut() const;
        /// @brief [ @b MUIA_Menuitem_Trigger ]
        /// Return the native MenuItem trigger structure associated with this item.
        const MenuItem *getTrigger() const;
#ifdef MUIA_Menuitem_AISSName
        /// @brief [ @b MUIA_Menuitem_AISSName ]
        /// Return the current AISS image specification name.
        std::string getAISSName() const;
#endif
#ifdef MUIA_Menuitem_Image
        /// @brief [ @b MUIA_Menuitem_Image ]
        /// Return the Intuition image currently associated with this menu item.
        const ::Image *getImage() const;
#endif
#ifdef MUIA_Menuitem_Menuitem
        /// @brief [ @b MUIA_Menuitem_Menuitem ]
        /// Return the native MUI object pointer referenced by this menu item.
        Object *getMenuitemObject() const;
        /// @brief [ @b MUIA_Menuitem_Menuitem ]
        /// Return the referenced menu item as a wrapper object.
        Menuitem getMenuitem() const;
#endif

        /// @brief [ @b MUIA_Menuitem_Checked ]
        /// Set the checked state of this menu item.
        Menuitem &setChecked(const bool checked);
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        /// Enable or disable checkmark support for this menu item.
        Menuitem &setCheckit(const bool checkit);
        /// @brief [ @b MUIA_Menuitem_CommandString ]
        /// Define whether the shortcut string is treated as a command string.
        Menuitem &setCommandString(const bool commandString);
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        /// Enable or disable this menu item.
        Menuitem &setEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Title ]
        /// Set the visible title text of this menu item.
        Menuitem &setTitle(const std::string &title);
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        /// Enable or disable toggle behavior for this menu item.
        Menuitem &setToggle(const bool toggle);

        // methods, some returns object reference
    };

    class MenuItemFactory
    {
      public:
        /// @brief create and return menu separator [ @b NM_BARLABEL ]
        static Menuitem Separator();
        /// @brief create and return basic menu item with title and user data
        /// @param title text in item
        /// @param userData user data
        static Menuitem BasicItem(const std::string &title, const unsigned long userData);
    };

    template <typename T, typename U> class MenuitemBuilderTemplate : public FamilyBuilderTemplate<T, U>
    {
      public:
        MenuitemBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Menuitem)
          : FamilyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Menuitem_AISSName
        /// @brief [ @b MUIA_Menuitem_AISSName ]
        /// Set the AISS image specification name used by this menu item.
        T &tagAISSName(const std::string &aissName);
#endif
        /// @brief [ @b MUIA_Menuitem_Checked ]
        /// Define checked state of a checkit menu item
        T &tagChecked(const bool checked);
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        /// For @b true this item will become a checkmarkable item.
        T &tagCheckit(const bool checkit);
        /// @brief [ @b MUIA_Menuitem_CommandString ]
        /// Set to true if MUIA_Menuitem_Shortcut points to a command string (e.g. "shift alt q") instead of a simple letter. Note that MUI
        /// won't check if these keys are pressed (just like intuition), you'll have to do this yourself.
        T &tagCommandString(const long commandString = true);
#ifdef MUIA_Menuitem_CopyStrings
        /// @brief [ @b MUIA_Menuitem_CopyStrings ]
        /// Set to true if the title string defined by MUIA_Menuitem_Title is to be copied. Otherwise the title will be used directly and
        /// must remain valid throughout the object's life time. By default is false (no copy).
        T &tagCopyStrings(const bool copyStrings = true);
#endif
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        /// Set the initial enabled state for this menu item.
        T &tagEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Exclude ]
        /// Define exclude mask for mutually exclusive check items.
        T &tagExclude(const long exclude);
#ifdef MUIA_Menuitem_FreeImage
        /// @brief [ @b MUIA_Menuitem_FreeImage ]
        /// Define whether the image object passed to MUIA_Menuitem_Image will be disposed automatically or not. If this attribute is set to
        /// false it is the responsibility of the application to dispose the image object itself. Default is true.
        T &tagFreeImage(const bool freeImage);
#endif
#ifdef MUIA_Menuitem_Image
        /// @brief [ @b MUIA_Menuitem_Image ]
        /// Set the Intuition image object used by this menu item.
        T &tagImage(const ::Image *image);
#endif
#ifdef MUIA_Menuitem_Menuitem
        /// @brief [ @b MUIA_Menuitem_Menuitem ]
        /// Set the referenced native MUI menu item object.
        T &tagMenuitem(const Object *menuitem);
#endif
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        /// Set keyboard shortcut text for this menu item.
        T &tagShortcut(const std::string &shortcut);
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        /// Set keyboard shortcut using predefined shortcut constants.
        T &tagShortcut(const enum Menuitem_Shortcut shortcut);
        /// @brief [ @b MUIA_Menuitem_Title ]
        /// Set title text from a C string.
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Menuitem_Title ]
        /// Set title text from a std::string.
        T &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        /// Define the state of the TOGGLE flag for this item.
        T &tagToggle(const bool toggle);
    };

    class MenuitemBuilder : public MenuitemBuilderTemplate<MenuitemBuilder, Menuitem>
    {
      public:
        MenuitemBuilder();
    };
}

#define MUI_MENUITEM_TPP_INCLUDE
#include "Menuitem.tpp"
#undef MUI_MENUITEM_TPP_INCLUDE
