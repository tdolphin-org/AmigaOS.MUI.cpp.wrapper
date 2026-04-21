//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIC_Title

#include "Group.hpp"
#include "ValueTypes/Title/OnLastClose.hpp"
#include "ValueTypes/Title/Position.hpp"

namespace MUI
{
    class Title : public Group
    {
      public:
        explicit Title(Object *pMuiObject)
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

        /// @brief [ @b MUIA_Title_Clickable ]
        /// Returns whether the title object reacts to clicks on its tabs.
        bool getClosable() const;
        /// @brief [ @b MUIA_Title_Closable ]
        /// Returns whether each tab has a close button.
        bool getClickable() const;
        /// @brief [ @b MUIA_Title_EventHandlerPriority ]
        /// Returns the priority of the internal event handler.
        long getEventHandlerPriority() const;
#ifdef MUIA_Title_Newable
        /// @brief [ @b MUIA_Title_Newable ]
        /// Returns whether a "+" new-tab button is visible.
        bool getNewable() const;
#endif
        /// @brief [ @b MUIA_Title_OnLastClose ]
        /// Returns the action taken when the last tab is closed.
        enum Title_OnLastClose getOnLastClose() const;
        /// @brief [ @b MUIA_Title_Position ]
        /// Returns the position of the tab titles (top/bottom/left/right).
        enum Title_Position getPosition() const;
        /// @brief [ @b MUIA_Title_Sortable ]
        /// Returns whether tabs can be rearranged via drag-and-drop.
        bool getSortable() const;

        /// @brief [ @b MUIA_Title_Clickable ]
        /// Setting this to false disables tab clicks and prevents page changes. By default true.
        Title &setClickable(const bool clickable);
        /// @brief [ @b MUIA_Title_Closable ]
        /// Setting this to true adds a close button to each tab. By default false.
        Title &setClosable(const bool closable);
        /// @brief [ @b MUIA_Title_EventHandlerPriority ]
        /// Sets the priority of the internal event handler.
        Title &setEventHandlerPriority(const long eventHandlerPriority);
#ifdef MUIA_Title_Newable
        /// @brief [ @b MUIA_Title_Newable ]
        /// Setting this to true adds a "+" new-tab button. By default false.
        Title &setNewable(const bool newable);
#endif
        /// @brief [ @b MUIA_Title_OnLastClose ]
        /// Defines behaviour when the last tab is closed (@ref Title_OnLastClose).
        Title &setOnLastClose(const enum Title_OnLastClose onLastClose);
        /// @brief [ @b MUIA_Title_Position ]
        /// Sets the position of the tab titles (@ref Title_Position).
        Title &setPosition(const enum Title_Position position);
        /// @brief [ @b MUIA_Title_Sortable ]
        /// Setting this to true allows tabs to be rearranged via drag-and-drop. By default false.
        Title &setSortable(const bool sortable);

        // methods, return object reference

        /// @brief [ @b MUIM_Title_Close ]
        /// Closes the given tab object. Title class itself does NOT remove the tab; the application subclass must handle this.
        Title &Close(Object *pTitleObject);
#ifdef MUIM_Title_FindPage
        /// @brief [ @b MUIM_Title_FindPage ]
        /// Returns the page index corresponding to the given title button object.
        long FindPage(Boopsiobject *pTitleButton);
        /// @brief [ @b MUIM_Title_New ]
        /// Invoked when the "+" button is clicked; the application subclass must add the new tab and page.
        Title &New();
#endif
    };

    template <typename T, typename U> class TitleBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        TitleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Title)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Title_Clickable ]
        /// Setting this attribute to false will let the Title object ignore all clicks on its tabs and hence prevent page changes.
        /// By default is true.
        T &tagClickable(const bool clickable);
        /// @brief [ @b MUIA_Title_Closable ]
        /// Setting this attribute to true will add a close button to each tab object. Clicking the close button will invoke the
        /// MUIM_Title_Close method with a pointer to the tab object the close button corresponds to. Title class will NOT close the tab
        /// itself. This task remains the responsibility of the implementing class and hence also requires the developer to implement a
        /// subclass of Title class to handle the method.
        /// By default is false.
        T &tagClosable(const bool closable);
        /// @brief [ @b MUIA_Title_EventHandlerPriority ]
        /// Defines the priority of the internal eventhandler. This attribute is of use only if you need to do something before the internal
        /// eventhandler and eventually might eat the events you are interested in.
        /// By default is MUIV_Title_EventHandlerPriority_Default.
        T &tagEventHandlerPriority(const long eventHandlerPriority);
#ifdef MUIA_Title_Newable
        /// @brief [ @b MUIA_Title_Newable ]
        /// Setting this attribute to true will add a "+" button after the rightmost tab object. Clicking the "+" button will invoke the
        /// MUIM_Title_New method to let the application add a new title button object and a new page object. Title class will NOT add the
        /// new tab itself. This task remains the responsibility of the implementing class and hence also requires the developer to
        /// implement a subclass of Title class to handle the method.
        /// By default is false.
        T &tagNewable(const bool newable);
#endif
        /// @brief [ @b MUIA_Title_OnLastClose ]
        /// This attribute defines how the object will react when the last tab is to be closed. Setting this attribute to
        /// MUIV_Title_OnLastClose_Remove will invoke the usual MUIM_Title_Close method on the object. Setting the attribute to
        /// MUIV_Title_OnLastClose_WindowAction will trigger a close request on the object's window.
        /// By default is MUIV_Title_OnLastClose_Remove.
        T &tagOnLastClose(const enum Title_OnLastClose onLastClose);
        /// @brief [ @b MUIA_Title_Position ]
        /// Defines the position of the tab titles. Currently only top and bottom placement is implemented. Left and right placement will
        /// hopefully be implemented in the near future.
        /// By default is MUIV_Title_Position_Top.
        T &tagPosition(const enum Title_Position position);
        /// @brief [ @b MUIA_Title_Sortable ]
        /// Define whether the individual tabs can be rearranged by drag'n'drop operations. Title class will rearrange both the tab title
        /// objects as well as the page objects after a drag'n'drop operation.
        /// By default is false.
        T &tagSortable(const bool sortable);
    };

    class TitleBuilder : public TitleBuilderTemplate<TitleBuilder, Title>
    {
      public:
        TitleBuilder();
    };
}

#define MUI_TITLE_TPP_INCLUDE
#include "Title.tpp"
#undef MUI_TITLE_TPP_INCLUDE

#endif
