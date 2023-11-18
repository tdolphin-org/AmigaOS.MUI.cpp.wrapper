//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Family.hpp"
#include "ValueTypes/Menuitem/Shortcut.hpp"

namespace MUI
{
    class Menuitem : public Family
    {
      public:
        Menuitem(const Object *pMuiObject)
          : Family(pMuiObject)
        {
        }

        Menuitem(const APTR pMuiObject)
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
        bool isChecked() const;
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        bool isCheckit() const;
        /// @brief [ @b MUIA_Menuitem_CommandString ]
        bool isCommandString() const;
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        bool isEnabled() const;
        /// @brief [ @b MUIA_Menuitem_Title ]
        std::string getTitle() const;
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        bool isToggle() const;

        /// @brief [ @b MUIA_Menuitem_Checked ]
        Menuitem &setChecked(const bool checked);
        /// @brief [ @b MUIA_Menuitem_Checkit ]
        Menuitem &setCheckit(const bool checkit);
        /// @brief [ @b MUIA_Menuitem_CommandString ]
        Menuitem &setCommandString(const bool commandString);
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        Menuitem &setEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Title ]
        Menuitem &setTitle(const std::string &title);
        /// @brief [ @b MUIA_Menuitem_Toggle ]
        Menuitem &setToggle(const bool toggle);

        // methods, some can return object reference
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

        /// @brief [ @b MUIA_Menuitem_AISSName ]
        T &tagAISSName(const std::string &aissName);
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
        /// @brief [ @b MUIA_Menuitem_CopyStrings ]
        /// Set to true if the title string defined by MUIA_Menuitem_Title is to be copied. Otherwise the title will be used directly and
        /// must remain valid throughout the object's life time. By default is false (no copy).
        T &tagCopyStrings(const bool copyStrings = true);
        /// @brief [ @b MUIA_Menuitem_Enabled ]
        T &tagEnabled(const bool enabled);
        /// @brief [ @b MUIA_Menuitem_Exclude ]
        T &tagExclude(const long exclude);
        /// @brief [ @b MUIA_Menuitem_FreeImage ]
        /// Define whether the image object passed to MUIA_Menuitem_Image will be disposed automatically or not. If this attribute is set to
        /// false it is the responsibility of the application to dispose the image object itself. Default is true.
        T &tagFreeImage(const bool freeImage);
        /// @brief [ @b MUIA_Menuitem_Image ]
        T &tagImage(const Image *image);
        /// @brief [ @b MUIA_Menuitem_Menuitem ]
        T &tagMenuitem(const Object *menuitem);
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        T &tagShortcut(const std::string &shortcut);
        /// @brief [ @b MUIA_Menuitem_Shortcut ]
        T &tagShortcut(const enum Menuitem_Shortcut shortcut);
        /// @brief [ @b MUIA_Menuitem_Title ]
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Menuitem_Title ]
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

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagAISSName(const std::string &aissName)
    {
        this->PushTag(MUIA_Menuitem_AISSName, aissName);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagChecked(const bool checked)
    {
        this->PushTag(MUIA_Menuitem_Checked, checked);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagCheckit(const bool checkit)
    {
        this->PushTag(MUIA_Menuitem_Checkit, checkit);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagCommandString(const long commandString)
    {
        this->PushTag(MUIA_Menuitem_CommandString, commandString);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagCopyStrings(const bool copyStrings)
    {
        this->PushTag(MUIA_Menuitem_CopyStrings, copyStrings);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagEnabled(const bool enabled)
    {
        this->PushTag(MUIA_Menuitem_Enabled, enabled);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagExclude(const long exclude)
    {
        this->PushTag(MUIA_Menuitem_Exclude, exclude);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagFreeImage(const bool freeImage)
    {
        this->PushTag(MUIA_Menuitem_FreeImage, freeImage);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagImage(const Image *image)
    {
        this->PushTag(MUIA_Menuitem_Image, image);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagMenuitem(const Object *menuitem)
    {
        this->PushTag(MUIA_Menuitem_Menuitem, menuitem);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagShortcut(const std::string &shortcut)
    {
        this->PushTag(MUIA_Menuitem_Shortcut, shortcut);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagShortcut(const enum Menuitem_Shortcut shortcut)
    {
        this->PushTag(MUIA_Menuitem_Shortcut, shortcut);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Menuitem_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagTitle(const std::string &title)
    {
        auto copy = this->StoreString(title);
        this->PushTag(MUIA_Menuitem_Title, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagToggle(const bool toggle)
    {
        this->PushTag(MUIA_Menuitem_Toggle, toggle);
        return (T &)*this;
    }
}
