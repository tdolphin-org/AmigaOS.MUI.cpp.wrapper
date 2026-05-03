//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Gadget.hpp"

#include <intuition/classes.h>

namespace MUI
{
    /// @brief MUI Boopsi class wrapper.
    /// Provides an interface to standard, system-style BOOPSI gadgets. MUI passes through all
    /// unknown attributes to the underlying BOOPSI gadget and converts IDCMP_UPDATE notifications
    /// into MUI notification events, allowing BOOPSI gadgets to participate in MUI's notification system.
    class Boopsi : public Gadget
    {
      public:
        explicit Boopsi(Object *pMuiObject)
          : Gadget(pMuiObject)
        {
        }

        Boopsi(const Root &root)
          : Gadget(root.muiObject())
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

        /// @brief [ @b MUIA_Boopsi_Class ]
        /// Returns the pointer to the (private) BOOPSI class this object was created from.
        struct IClass *getClass() const;
        /// @brief [ @b MUIA_Boopsi_Class ]
        /// Sets the pointer to the (private) BOOPSI class. Only useful if you previously generated
        /// your own BOOPSI class with MakeClass(). The class must not be freed until you are done with this object.
        Boopsi &setClass(struct IClass *pClass);

        /// @brief [ @b MUIA_Boopsi_ClassID ]
        /// Returns the public BOOPSI class name this object was created from.
        std::string getClassID() const;
        /// @brief [ @b MUIA_Boopsi_ClassID ]
        /// Specifies the name of the public BOOPSI class to create an object of. Used only when MUIA_Boopsi_Class is NULL.
        /// The string must remain valid until you are done with the object.
        Boopsi &setClassID(const std::string &classID);

        /// @brief [ @b MUIA_Boopsi_MaxHeight ]
        /// Returns the maximum height hint for MUI's layout system.
        unsigned long getMaxHeight() const;
        /// @brief [ @b MUIA_Boopsi_MaxHeight ]
        /// Sets the maximum height for MUI's layout system. BOOPSI gadgets do not report their sizes,
        /// so you must supply this value manually. Default is unlimited.
        Boopsi &setMaxHeight(const unsigned long maxHeight);

        /// @brief [ @b MUIA_Boopsi_MaxWidth ]
        /// Returns the maximum width hint for MUI's layout system.
        unsigned long getMaxWidth() const;
        /// @brief [ @b MUIA_Boopsi_MaxWidth ]
        /// Sets the maximum width for MUI's layout system. BOOPSI gadgets do not report their sizes,
        /// so you must supply this value manually. Default is unlimited.
        Boopsi &setMaxWidth(const unsigned long maxWidth);

        /// @brief [ @b MUIA_Boopsi_MinHeight ]
        /// Returns the minimum height hint for MUI's layout system.
        unsigned long getMinHeight() const;
        /// @brief [ @b MUIA_Boopsi_MinHeight ]
        /// Sets the minimum height for MUI's layout system. BOOPSI gadgets do not report their sizes,
        /// so you must supply this value manually. Default is 1 pixel.
        Boopsi &setMinHeight(const unsigned long minHeight);

        /// @brief [ @b MUIA_Boopsi_MinWidth ]
        /// Returns the minimum width hint for MUI's layout system.
        unsigned long getMinWidth() const;
        /// @brief [ @b MUIA_Boopsi_MinWidth ]
        /// Sets the minimum width for MUI's layout system. BOOPSI gadgets do not report their sizes,
        /// so you must supply this value manually. Default is 1 pixel.
        Boopsi &setMinWidth(const unsigned long minWidth);

        /// @brief [ @b MUIA_Boopsi_Object ]
        /// Returns a pointer to the underlying BOOPSI gadget object.
        /// The pointer is only valid when the containing window is open.
        Object *getObject() const;

        /// @brief [ @b MUIA_Boopsi_TagDrawInfo ]
        /// Returns the tag ID used by MUI to fill in the DrawInfo structure pointer at window-open time.
        unsigned long getTagDrawInfo() const;
        /// @brief [ @b MUIA_Boopsi_TagDrawInfo ]
        /// Specifies the tag ID where MUI should fill in a pointer to the current DrawInfo structure
        /// when the window is opened.
        Boopsi &setTagDrawInfo(const unsigned long tagDrawInfo);

        /// @brief [ @b MUIA_Boopsi_TagScreen ]
        /// Returns the tag ID used by MUI to fill in the Screen structure pointer at window-open time.
        unsigned long getTagScreen() const;
        /// @brief [ @b MUIA_Boopsi_TagScreen ]
        /// Specifies the tag ID where MUI should fill in a pointer to the current Screen structure
        /// when the window is opened.
        Boopsi &setTagScreen(const unsigned long tagScreen);

        /// @brief [ @b MUIA_Boopsi_TagWindow ]
        /// Returns the tag ID used by MUI to fill in the Window structure pointer at window-open time.
        unsigned long getTagWindow() const;
        /// @brief [ @b MUIA_Boopsi_TagWindow ]
        /// Specifies the tag ID where MUI should fill in a pointer to the current Window structure
        /// when the window is opened.
        Boopsi &setTagWindow(const unsigned long tagWindow);
    };

    template <typename T, typename U> class BoopsiBuilderTemplate : public GadgetBuilderTemplate<T, U>
    {
      public:
        BoopsiBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Boopsi)
          : GadgetBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Boopsi_Class ]
        /// Pointer to the (private) BOOPSI class created with MakeClass(). The class must not be freed
        /// until you are done with the object.
        T &tagClass(struct IClass *pClass);

        /// @brief [ @b MUIA_Boopsi_ClassID ]
        /// Name of the public BOOPSI class to instantiate. Used only when MUIA_Boopsi_Class is NULL.
        /// The string must remain valid until you are done with the object.
        T &tagClassID(const std::string &classID);

        /// @brief [ @b MUIA_Boopsi_MaxHeight ]
        /// Maximum height for MUI's layout system. Default is unlimited.
        T &tagMaxHeight(const unsigned long maxHeight);

        /// @brief [ @b MUIA_Boopsi_MaxWidth ]
        /// Maximum width for MUI's layout system. Default is unlimited.
        T &tagMaxWidth(const unsigned long maxWidth);

        /// @brief [ @b MUIA_Boopsi_MinHeight ]
        /// Minimum height for MUI's layout system. Default is 1 pixel.
        T &tagMinHeight(const unsigned long minHeight);

        /// @brief [ @b MUIA_Boopsi_MinWidth ]
        /// Minimum width for MUI's layout system. Default is 1 pixel.
        T &tagMinWidth(const unsigned long minWidth);

        /// @brief [ @b MUIA_Boopsi_Remember ]
        /// Tag ID of a BOOPSI attribute that should be remembered across object dispose/regeneration.
        /// Can be specified up to five times for different tag IDs.
        T &tagRemember(const unsigned long tagID);

        /// @brief [ @b MUIA_Boopsi_Smart ]
        /// Set to true for smart BOOPSI gadgets that support resizing (e.g. textfield.class).
        /// MUI will not dispose and recreate smart gadgets. By default is false.
        T &tagSmart(const bool smart);

        /// @brief [ @b MUIA_Boopsi_TagDrawInfo ]
        /// Tag ID where MUI should fill in a pointer to the DrawInfo structure when the window is opened.
        T &tagTagDrawInfo(const unsigned long tagDrawInfo);

        /// @brief [ @b MUIA_Boopsi_TagScreen ]
        /// Tag ID where MUI should fill in a pointer to the Screen structure when the window is opened.
        T &tagTagScreen(const unsigned long tagScreen);

        /// @brief [ @b MUIA_Boopsi_TagWindow ]
        /// Tag ID where MUI should fill in a pointer to the Window structure when the window is opened.
        T &tagTagWindow(const unsigned long tagWindow);
    };

    class BoopsiBuilder : public BoopsiBuilderTemplate<BoopsiBuilder, Boopsi>
    {
      public:
        BoopsiBuilder();
    };
}

#define MUI_BOOPSI_TPP_INCLUDE
#include "Boopsi.tpp"
#undef MUI_BOOPSI_TPP_INCLUDE
