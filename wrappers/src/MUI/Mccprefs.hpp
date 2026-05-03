//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    /// @brief Mccprefs is the base class for all custom class configuration classes. Each configuration class (*.mcp) must be a subclass of
    /// Mccprefs. Mccprefs does some internal house keeping stuff for configuration objects and also offers public methods that subclasses
    /// may call to improve their appearance.
    class Mccprefs : public Group
    {
      public:
        explicit Mccprefs(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Mccprefs(const Root &root)
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

        // methods, some returns object reference

#ifdef MUIM_Mccprefs_ConfigToGadgets
        /// @brief [ @bMUIA_Mccprefs_ConfigToGadgets ]
        /// This method will be called whenever MUI wants your custom prefs class to transfer configuration values from the configuration to
        /// the GUI.
        Mccprefs &ConfigToGadgets(const Object *configdata);
#endif
#ifdef MUIM_Mccprefs_GadgetsToConfig
        /// @brief [ @bMUIA_Mccprefs_GadgetsToConfig ]
        /// This method will be called whenever MUI wants your custom prefs class to transfer configuration values from the GUI to the
        /// configuration.
        Mccprefs &GadgetsToConfig(const Object *configdata, const Object *originator);
#endif
#ifdef MUIM_Mccprefs_RegisterGadget
        /// @brief [ @bMUIA_Mccprefs_RegisterGadget ]
        /// Registers a gadget with the MUI custom class preferences system.
        ///
        /// Preferences classes usually contain gadgets which are directly related to certain configuration options of your class, i.e.
        /// Poppen objects to adjust colors, String objects to adjust fonts, etc. These classes are directly related to a configuration ID
        /// value that you use to save their contents in the application's dataspace.
        ///
        /// By default, MUI does not know anything about your objects and what they are doing in your preferences class. With
        /// MUIM_Mccprefs_RegisterGadget, you can tell MUI which object is related to what configuration ID value. This knowledge helps MUI
        /// to improve handling of your gadget.
        ///
        /// Since version 20 of muimaster.library, MUI will e.g. add a default popup menu to all registered gadgets. Your object will
        /// automatically receive the same functionality as MUI's internal settings, like "Reset to defaults", "Last Saved", "Restore",
        /// "Presets..."
        ///
        /// Registering gadgets with MUIM_Mccprefs_RegisterGadget should be done right after the gadget was created.
        ///
        /// There's nothing more to be done to add the extra functionality to your gadgets besides registering them with this method. MUI
        /// can then automatically perform all the actions above (defaults, last saved, etc.) by altering the configuration dataspace while
        /// using the ID value you provided as a filter.
        Mccprefs &RegisterGadget(const Object *gadget, const unsigned long id, const unsigned long params, const std::string &title,
                                 const unsigned long attr, const Object *label);
#endif
    };

    template <typename T, typename U> class MccprefsBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        MccprefsBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Mccprefs)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class MccprefsBuilder : public MccprefsBuilderTemplate<MccprefsBuilder, Mccprefs>
    {
      public:
        MccprefsBuilder();
    };
}

#define MUI_MCCPREFS_TPP_INCLUDE
#include "Mccprefs.tpp"
#undef MUI_MCCPREFS_TPP_INCLUDE
