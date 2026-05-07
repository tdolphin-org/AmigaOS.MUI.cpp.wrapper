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
    /// @brief MUI Menuitem class wrapper.
    /// Describes a single menu item. Since Menuitem is a subclass of Family, other menu items can be added as children
    /// to form sub menus. The OS currently allows a maximum nesting level of one.
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

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Menuitem_Checked ]
        /// Returns the checked state of a checkit menu item.
        bool isChecked() const;
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        /// Returns true if this item is configured as a checkmarkable item.
        bool isCheckit() const;
        /// @brief [ @b MUIA_Menuitem_CommandString ]
        /// Returns true if @b MUIA_Menuitem_Shortcut is interpreted as a command string (e.g. "shift alt q") instead of a single key.
        bool isCommandString() const;
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        /// Returns true if this menu item is currently enabled.
        bool isEnabled() const;
        /// @brief [ @b MUIA_Menuitem_Exclude ]
        /// Returns the bitmask of menu item numbers that are deselected when this item is selected.
        long getExclude() const;
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        /// Returns the keyboard shortcut string defined for this menu item.
        std::string getShortcut() const;
        /// @brief [ @b MUIA_Menuitem_Title ]
        /// Returns the current title text of this menu item. May be NM_BARLABEL for a horizontal separator bar.
        std::string getTitle() const;
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        /// Returns the state of the TOGGLE flag for this menu item.
        bool isToggle() const;
        /// @brief [ @b MUIA_Menuitem_Trigger ]
        /// Returns a pointer to the @b struct @b MenuItem of this item when it is selected.
        /// Set up a notification with @b MUIV_EveryTime to react on menu actions and query the MenuItem flags immediately.
        /// @note The returned pointer is strictly read-only; only the flags field should be examined.
        const MenuItem *getTrigger() const;
#ifdef MUIA_Menuitem_AISSName
        /// @brief [ @b MUIA_Menuitem_AISSName ]
        /// Returns the optional AISS image name placed in front of the item's text (filename in TBIMAGES: directory, e.g. "cut").
        std::string getAISSName() const;
#endif
#ifdef MUIA_Menuitem_Image
        /// @brief [ @b MUIA_Menuitem_Image ]
        /// Returns the optional BOOPSI image placed in front of the item's text.
        const ::Image *getImage() const;
#endif
#ifdef MUIA_Menuitem_Menuitem
        /// @brief [ @b MUIA_Menuitem_Menuitem ]
        /// Returns the native MUI object pointer of the source Menuitem; during OM_GET all settings from the current object are copied to
        /// it.
        Object *getMenuitemObject() const;
        /// @brief [ @b MUIA_Menuitem_Menuitem ]
        /// Returns the source Menuitem as a wrapper; during OM_GET all settings from the current object are copied to it.
        Menuitem getMenuitem() const;
#endif

        /// @brief [ @b MUIA_Menuitem_Checked ]
        /// Set or clear the checked state of a checkit menu item.
        Menuitem &setChecked(const bool checked);
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        /// Set to true to make this item a checkmarkable item.
        Menuitem &setCheckit(const bool checkit);
        /// @brief [ @b MUIA_Menuitem_CommandString ]
        /// Set to true if @b MUIA_Menuitem_Shortcut points to a command string (e.g. "shift alt q") instead of a single key letter.
        Menuitem &setCommandString(const bool commandString);
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        /// Enable or disable this menu item.
        Menuitem &setEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Exclude ]
        /// Set the bitmask of menu item numbers (bit 0 = item 0, etc.) to be deselected when this checkit item is selected.
        Menuitem &setExclude(const long exclude);
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        /// Set the keyboard shortcut for this menu item. The string must remain valid for the lifetime of the object.
        Menuitem &setShortcut(const std::string &shortcut);
        /// @brief [ @b MUIA_Menuitem_Title ]
        /// Set the visible title text of this menu item. The string must remain valid for the lifetime of the object unless
        /// @b MUIA_Menuitem_CopyStrings is set. May be NM_BARLABEL to create a horizontal separator bar.
        Menuitem &setTitle(const std::string &title);
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        /// Set the TOGGLE flag state for this menu item.
        Menuitem &setToggle(const bool toggle);
#ifdef MUIA_Menuitem_AISSName
        /// @brief [ @b MUIA_Menuitem_AISSName ]
        /// Set an optional AISS image name to be placed in front of the item's text. The name is the filename in the TBIMAGES: directory
        /// (e.g. "cut" or "copy"). The image is displayed only if AISS is installed and MUI prefs have it enabled.
        Menuitem &setAISSName(const std::string &aissName);
#endif
#ifdef MUIA_Menuitem_Image
        /// @brief [ @b MUIA_Menuitem_Image ]
        /// Set an optional BOOPSI image (created by imageclass) to be placed in front of the item's text.
        /// The image is disposed automatically unless @b MUIA_Menuitem_FreeImage is set to false.
        Menuitem &setImage(const ::Image *image);
#endif
#ifdef MUIA_Menuitem_Menuitem
        /// @brief [ @b MUIA_Menuitem_Menuitem ]
        /// Copy all settings from the specified Menuitem object to this object. Existing strings and images are freed before copying.
        Menuitem &setMenuitem(const Object *menuitem);
#endif

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
        /// Define an optional AISS image to be placed in front of the item's text. The name is the filename in TBIMAGES:
        /// (e.g. "cut" or "copy"). Displayed only if AISS is installed, the image can be loaded, and the user enabled it in MUI prefs.
        T &tagAISSName(const std::string &aissName);
#endif
        /// @brief [ @b MUIA_Menuitem_Checked ]
        /// Set the initial checked state of a checkit menu item.
        T &tagChecked(const bool checked);
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        /// Set to true to make this item a checkmarkable item.
        T &tagCheckit(const bool checkit);
        /// @brief [ @b MUIA_Menuitem_CommandString ]
        /// Set to true if @b MUIA_Menuitem_Shortcut points to a command string (e.g. "shift alt q") instead of a single key letter.
        /// Note that MUI won't check if these keys are pressed — you must do this yourself.
        T &tagCommandString(const long commandString = true);
#ifdef MUIA_Menuitem_CopyStrings
        /// @brief [ @b MUIA_Menuitem_CopyStrings ]
        /// Set to true if the title string (@b MUIA_Menuitem_Title) is to be copied by MUI. Otherwise the title must remain
        /// valid throughout the object's lifetime. Defaults to false.
        T &tagCopyStrings(const bool copyStrings = true);
#endif
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        /// Set the initial enabled or disabled state for this menu item.
        T &tagEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Exclude ]
        /// Set the bitmask of menu item numbers (bit 0 = item 0, etc.) to be deselected when this checkit item is selected.
        T &tagExclude(const long exclude);
#ifdef MUIA_Menuitem_FreeImage
        /// @brief [ @b MUIA_Menuitem_FreeImage ]
        /// Set to false if the image passed via @b MUIA_Menuitem_Image should NOT be disposed automatically; the application
        /// then must dispose it. Defaults to true (image is disposed automatically).
        T &tagFreeImage(const bool freeImage);
#endif
#ifdef MUIA_Menuitem_Image
        /// @brief [ @b MUIA_Menuitem_Image ]
        /// Set an optional BOOPSI image (imageclass or subclass) to be placed in front of the item's text.
        /// Disposed automatically unless @b MUIA_Menuitem_FreeImage is set to false.
        T &tagImage(const ::Image *image);
#endif
#ifdef MUIA_Menuitem_Menuitem
        /// @brief [ @b MUIA_Menuitem_Menuitem ]
        /// Copy all settings from the specified Menuitem object to this object during initialisation.
        T &tagMenuitem(const Object *menuitem);
#endif
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        /// Set keyboard shortcut text for this menu item. The string must remain valid for the lifetime of the object.
        T &tagShortcut(const std::string &shortcut);
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        /// Set keyboard shortcut using predefined shortcut constants (e.g. @b Menuitem_Shortcut::Check).
        T &tagShortcut(const enum Menuitem_Shortcut shortcut);
        /// @brief [ @b MUIA_Menuitem_Title ]
        /// Set title text from a C string literal. The string must remain valid for the lifetime of the object
        /// unless @b MUIA_Menuitem_CopyStrings is set. May be NM_BARLABEL to create a horizontal separator bar.
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Menuitem_Title ]
        /// Set title text from a std::string; the string is copied internally by the wrapper for safe lifetime management.
        T &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        /// Set the TOGGLE flag state for this menu item.
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
