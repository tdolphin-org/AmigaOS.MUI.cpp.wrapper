//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Group.hpp"
#include "ValueTypes/Title/OnLastClose.hpp"
#include "ValueTypes/Title/Position.hpp"

namespace MUI
{
    class Title : public Group
    {
      public:
        Title(const Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Title(const APTR pMuiObject)
          : Group(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Title_Closable ]
        bool getClosable() const;
        /// @brief [ @b MUIA_Title_Newable ]
        bool getNewable() const;
        /// @brief [ @b MUIA_Title_Position ]
        enum Title_Position getPosition() const;
        /// @brief [ @b MUIA_Title_Sortable ]
        long getSortable() const;

        /// @brief [ @b MUIA_Title_Closable ]
        Title &setClosable(const bool closable);
        /// @brief [ @b MUIA_Title_Newable ]
        Title &setNewable(const bool newable);
        /// @brief [ @b MUIA_Title_OnLastClose ]
        Title &setOnLastClose(const enum Title_OnLastClose onLastClose);
        /// @brief [ @b MUIA_Title_Position ]
        Title &setPosition(const enum Title_Position position);
        /// @brief [ @b MUIA_Title_Sortable ]
        Title &setSortable(const bool sortable);
    };

    template <typename T, typename U> class TitleBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        TitleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Title)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Title_Clickable ]
        /// Setting this attribute to FALSE will let the Title object ignore all clicks on its tabs and hence prevent page changes. Defaults
        /// to TRUE.
        T &tagClickable(const bool clickable);
        /// @brief [ @b MUIA_Title_Closable ]
        /// Setting this attribute to TRUE will add a close button to each tab object. Clicking the close button will invoke the
        /// MUIM_Title_Close method with a pointer to the tab object the close buttons corresponds to. Title class will NOT close the tab
        /// itself. This task remains the responsibility of the implementing class and hence also requires the developer to implement a
        /// subclass of Title class to handle the method. Defaults to FALSE.
        T &tagClosable(const bool closable);
        /// @brief [ @b MUIA_Title_EventHandlerPriority ]
        /// Defines the priority of the internal eventhandler. This attribute is of use only if you need to do something before the internal
        /// eventhandler and eventually might eat the events you are interested in. Defaults to MUIV_Title_EventHandlerPriority_Default.
        T &tagEventHandlerPriority(const long eventHandlerPriority);
        /// @brief [ @b MUIA_Title_Newable ]
        /// Setting this attribute to TRUE will add a "+" button after the rightmost tab object. Clicking the "+" button will invoke the
        /// MUIM_Title_New method to let the application add a new title button object and a new page object. Title class will NOT add the
        /// new tab itself. This task remains the responsibility of the implementing class and hence also requires the developer to
        /// implement a subclass of Title class to handle the method.Defaults to FALSE.
        T &tagNewable(const bool newable);
        /// @brief [ @b MUIA_Title_OnLastClose ]
        /// This attribute defines how the object will react when the last tab is to be closed. Setting this attribute to
        /// MUIV_Title_OnLastClose_Remove will invoke the usual MUIM_Title_Close method on the object. Setting the attribute to
        /// MUIV_Title_OnLastClose_WindowAction will trigger a close request on the object's window. Defaults to
        /// MUIV_Title_OnLastClose_Remove.
        T &tagOnLastClose(const enum Title_OnLastClose onLastClose);
        /// @brief [ @b MUIA_Title_Position ]
        /// Defines the position of the tab titles. Currently only top and bottom placement is implemented. Left and right placement will
        /// hopefully be implemented in near future. Defaults to MUIV_Title_Position_Top.
        T &tagPosition(const enum Title_Position position);
        /// @brief [ @b MUIA_Title_Sortable ]
        /// Define whether the individual tabs can be rearranged by drag'n'drop operations. Title class will rearrange both the tab title
        /// objects as well as the page objects after a drag'n'drop operation. Defaults to FALSE.
        T &tagSortable(const bool sortable);
    };

    class TitleBuilder : public TitleBuilderTemplate<TitleBuilder, Title>
    {
      public:
        TitleBuilder();
    };

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagClickable(const bool clickable)
    {
        this->PushTag(MUIA_Title_Clickable, clickable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagClosable(const bool closable)
    {
        this->PushTag(MUIA_Title_Closable, closable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagEventHandlerPriority(const long eventHandlerPriority)
    {
        this->PushTag(MUIA_Title_EventHandlerPriority, eventHandlerPriority);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagNewable(const bool newable)
    {
        this->PushTag(MUIA_Title_Newable, newable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagOnLastClose(const enum Title_OnLastClose onLastClose)
    {
        this->PushTag(MUIA_Title_OnLastClose, onLastClose);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagPosition(const enum Title_Position position)
    {
        this->PushTag(MUIA_Title_Position, position);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagSortable(const bool sortable)
    {
        this->PushTag(MUIA_Title_Sortable, sortable);
        return (T &)*this;
    }
}
