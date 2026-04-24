//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Core/Optional.hpp"
#include "Notify.hpp"
#include "ValueTypes/Area/Font.hpp"
#include "ValueTypes/Area/Frame.hpp"
#include "ValueTypes/Area/InputMode.hpp"
#include "ValueTypes/Area/PointerType.hpp"
#include "ValueTypes/ImageOrBackground.hpp"

#undef Enable
#undef Disable

namespace MUI
{
    class Menuitem;
    class Menustrip;

#ifdef MUIM_TextDim
    struct Dim
    {
        long width;
        long height;

        Dim(const unsigned long value);
    };
#endif

    /// @brief Area class is the common base for visible MUI objects and gadgets.
    class Area : public Notify
    {
      public:
        explicit Area(Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Area(const Root &root)
          : Notify(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_BottomEdge ] Read current bottom edge coordinate of this object.
        long getBottomEdge() const;
        /// @brief [ @b MUIA_ContextMenu ] Read currently assigned context menu object.
        Optional<Menustrip> getContextMenu() const;
        /// @brief [ @b MUIA_ContextMenu ] Assign context menu shown for this object.
        Area &setContextMenu(const Menustrip &contextMenu);
#ifdef MUIA_ContextMenuHook
        /// @brief [ @b MUIA_ContextMenuHook ] Read custom hook used to build/modify context menus.
        Hook *getContextMenuHook() const;
        /// @brief [ @b MUIA_ContextMenuHook ] Set custom hook used to build/modify context menus.
        Area &setContextMenuHook(const Hook *contextMenuHook);
#endif
        /// @brief [ @b MUIA_ContextMenuTrigger ] Read menu item that triggered currently open context menu.
        Optional<Menuitem> getContextMenuTrigger() const;
        /// @brief [ @b MUIA_ControlChar ] Read keyboard shortcut character for this object.
        char getControlChar() const;
        /// @brief [ @b MUIA_ControlChar ] Set keyboard shortcut character for this object.
        Area &setControlChar(const char controlChar);
        /// @brief [ @b MUIA_CycleChain ] Read whether object participates in keyboard cycle chain.
        long getCycleChain() const;
        /// @brief [ @b MUIA_Disabled ] Check whether the object is disabled.
        bool isDisabled() const;
#ifdef MUIA_DoubleBuffer
        /// @brief [ @b MUIA_DoubleBuffer ] Check whether double buffering is enabled.
        bool isDoubleBuffer() const;
        /// @brief [ @b MUIA_DoubleBuffer ] Enable or disable double buffering.
        Area &setDoubleBuffer(const bool doubleBuffer);
#endif
#ifdef MUIA_DoubleClick
        /// @brief [ @b MUIA_DoubleClick ] Check whether latest input was a double click.
        bool isDoubleClick() const;
#endif
        /// @brief [ @b MUIA_Draggable ] Check whether object can be dragged.
        bool isDraggable() const;
        /// @brief [ @b MUIA_Draggable ] Enable or disable drag source behavior.
        Area &setDraggable(const bool draggable);
        /// @brief [ @b MUIA_Dropable ] Check whether object accepts drag-and-drop drops.
        bool isDropable() const;
        /// @brief [ @b MUIA_Dropable ] Enable or disable drop target behavior.
        Area &setDropable(const bool dropable);
#ifdef MUIA_Floating
        /// @brief [ @b MUIA_Floating ] Check whether object is treated as floating.
        bool isFloating() const;
#endif
        /// @brief [ @b MUIA_Font ] Read currently active render font.
        TextFont *getFont() const;
#ifdef MUIA_FrameDynamic
        /// @brief [ @b MUIA_FrameDynamic ] Check whether frame reacts dynamically to state changes.
        bool isFrameDynamic() const;
        /// @brief [ @b MUIA_FrameDynamic ] Enable or disable dynamic frame behavior.
        Area &setFrameDynamic(const bool frameDynamic);
#endif
        /// @brief [ @b MUIA_FrameTitle ] Read frame title text.
        std::string getFrameTitle() const;
#ifdef MUIA_FrameVisible
        /// @brief [ @b MUIA_FrameVisible ] Check whether object frame is visible.
        bool isFrameVisible() const;
        /// @brief [ @b MUIA_FrameVisible ] Show or hide object frame.
        Area &setFrameVisible(const bool frameVisible);
#endif
        /// @brief [ @b MUIA_Height ] Read current object height.
        long getHeight() const;
        /// @brief [ @b MUIA_HorizDisappear ] Read horizontal disappear behavior value.
        long getHorizDisappear() const;
        /// @brief [ @b MUIA_HorizDisappear ] Set horizontal disappear behavior value.
        Area &setHorizDisappear(const long horizDisappear);
        /// @brief [ @b MUIA_HorizWeight ] Read horizontal layout weight.
        short getHorizWeight() const;
        /// @brief [ @b MUIA_InnerBottom ] Read bottom inner spacing.
        long getInnerBottom() const;
        /// @brief [ @b MUIA_InnerLeft ] Read left inner spacing.
        long getInnerLeft() const;
        /// @brief [ @b MUIA_InnerRight ] Read right inner spacing.
        long getInnerRight() const;
        /// @brief [ @b MUIA_InnerTop ] Read top inner spacing.
        long getInnerTop() const;
#ifdef MUIA_KnowsDisabled
        /// @brief [ @b MUIA_KnowsDisabled ] Check whether object handles disabled state itself.
        bool isKnowsDisabled() const;
        /// @brief [ @b MUIA_KnowsDisabled ] Tell MUI that object handles disabled state itself.
        Area &setKnowsDisabled(const bool knowsDisabled);
#endif
        /// @brief [ @b MUIA_LeftEdge ] Read current left edge coordinate of this object.
        long getLeftEdge() const;
#ifdef MUIA_PointerType
        /// @brief [ @b MUIA_PointerType ] Read currently selected pointer type for this object.
        enum PointerType getPointerType() const;
#endif
        /// @brief [ @b MUIA_Pressed ] Check whether object is currently pressed.
        bool isPressed() const;
        /// @brief [ @b MUIA_RightEdge ] Read current right edge coordinate of this object.
        long getRightEdge() const;
        /// @brief [ @b MUIA_Selected ] Check whether object is selected.
        bool isSelected() const;
        /// @brief [ @b MUIA_ShortHelp ] Read short help text shown for this object.
        std::string getShortHelp() const;
        /// @brief [ @b MUIA_ShowMe ] Check whether object is currently visible.
        bool isShowMe() const;
#ifdef MUIA_TextColor
        /// @brief [ @b MUIA_TextColor ] Read configured text color value.
        unsigned long getTextColor() const;
        /// @brief [ @b MUIA_TextColor ] Set text color using MUI pen specification.
        Area &setTextColor(const struct MUI_PenSpec *textColor);
#endif
        /// @brief [ @b MUIA_Timer ] Read current timer value associated with this object.
        long getTimer() const;
        /// @brief [ @b MUIA_TopEdge ] Read current top edge coordinate of this object.
        long getTopEdge() const;
        /// @brief [ @b MUIA_VertDisappear ] Read vertical disappear behavior value.
        long getVertDisappear() const;
        /// @brief [ @b MUIA_VertDisappear ] Set vertical disappear behavior value.
        Area &setVertDisappear(const long vertDisappear);
        /// @brief [ @b MUIA_VertWeight ] Read vertical layout weight.
        short getVertWeight() const;
        /// @brief [ @b MUIA_Width ] Read current object width.
        long getWidth() const;
        /// @brief [ @b MUIA_Window ] Read Intuition window pointer hosting this object.
        Window *getWindow() const;
        /// @brief [ @b MUIA_WindowObject ] Read MUI window object hosting this object.
        Object *getWindowObject() const;

        /// @brief [ @b MUIA_Background ] Set background using predefined image/background enum value.
        Area &setBackground(const enum ImageOrBackground background);
        /// @brief [ @b MUIA_Background ] Set background from textual specification.
        /// The string is copied and stored internally by this C++ wrapper!
        Area &setBackground(const std::string &background);
        /// @brief [ @b MUIA_CycleChain ]
        /// Keyboard cycle chain system. Set MUIA_CycleChain to 1 for every object that you want to have in your chain, MUI does the rest
        /// automatically.
        Area &setCycleChain(const long cycleChain = 1);
        /// @brief [ @b MUIA_Disabled ] Enable or disable object interaction.
        Area &setDisabled(const bool disabled);
        /// @brief [ @b MUIA_FillArea ] Enable or disable filling complete object area during rendering.
        Area &setFillArea(const bool fillArea);
#ifdef MUIA_Floating
        /// @brief [ @b MUIA_Floating ] Enable or disable floating layout behavior.
        Area &setFloating(const bool floating);
#endif
        /// @brief [ @b MUIA_Font ] - seems that setting font doesn't work (at least for MUI::Floattext)
        Area &setFont(const enum Font font);
        /// @brief [ @b MUIA_FrameTitle ] Set frame title text.
        Area &setFrameTitle(const std::string &frameTitle);
        /// @brief [ @b MUIA_HorizWeight ] Set horizontal layout weight.
        Area &setHorizWeight(const short horizWeight);
#ifdef MUIA_PointerType
        /// @brief [ @b MUIA_PointerType ] Set pointer shape used when cursor is over this object.
        Area &setPointerType(const PointerType pointerType);
#endif
        /// @brief [ @b MUIA_Selected ] Select or deselect the object.
        Area &setSelected(const bool selected);
        /// @brief [ @b MUIA_ShortHelp ] Set short help text shown for this object.
        Area &setShortHelp(const std::string &shortHelp);
        /// @brief [ @b MUIA_ShowMe ] Show or hide the object.
        Area &setShowMe(const bool showMe);
        /// @brief [ @b MUIA_VertWeight ] Set vertical layout weight.
        Area &setVertWeight(const short vertWeight);
        /// @brief [ @b MUIA_Weight ]
        /// An object with a weight of 0 will always stay at its minimum size. By default, all objects have a weight of 100.
        /// @param weight short weight of object, for negative value is ignored
        Area &setWeight(const short weight);

        // methods, some returns object reference

        /// @brief setDisabled(false)
        Area &Enable();
        /// @brief setDisabled(true)
        Area &Disable();

        /// @brief [ @b MUIM_Cleanup /* Custom Class */ ]
        Area &Cleanup();
        /// @brief [ @b MUIM_Hide /* Custom Class */ ]
        Area &Hide();
        /// @brief [ @b MUIM_Show /* Custom Class */ ]
        Area &Show(struct LongRect *clip);

#ifdef MUIM_ContextMenuBuild
        /// @brief [ @b MUIM_ContextMenuBuild ] Build a popup menu for the given mouse coordinates.
        /// @param mx horizontal mouse position
        /// @param my vertical mouse position
        /// @return generated Menustrip or empty Optional if no context menu
        Optional<Menustrip> ContextMenuBuild(const long mx, const long my);
#endif
#ifdef MUIM_ContextMenuAdd
        /// @brief [ @b MUIM_ContextMenuAdd ] Add context-menu entries and optionally update popup coordinates.
        /// @param menustrip menu strip object to extend
        /// @param mx horizontal mouse position
        /// @param my vertical mouse position
        /// @param mxp optional output pointer for adjusted x coordinate
        /// @param myp optional output pointer for adjusted y coordinate
        /// @return result code from MUIM_ContextMenuAdd
        unsigned long ContextMenuAdd(const Menustrip &menustrip, const long mx, const long my, long *mxp = nullptr, long *myp = nullptr);
#endif
#ifdef MUIM_ContextMenuChoice
        /// @brief [ @b MUIM_ContextMenuChoice ] Notify the object that a popup menu item was chosen.
        /// @param item selected menu item object
        /// @return result code from MUIM_ContextMenuChoice
        unsigned long ContextMenuChoice(const Menuitem &item);
#endif
#ifdef MUIM_CreateBubble
        /// @brief [ @b MUIM_CreateBubble ] Create a bubble help object at the given coordinates.
        /// @param x horizontal position
        /// @param y vertical position
        /// @param txt bubble help text
        /// @param flags bubble creation flags
        /// @return bubble handle for DeleteBubble or nullptr on failure
        APTR CreateBubble(const long x, const long y, const char *txt, const unsigned long flags = 0);
#endif
#ifdef MUIM_CreateShortHelp
        /// @brief [ @b MUIM_CreateShortHelp ] Create bubble-help text for the given mouse coordinates.
        /// @param mx horizontal mouse position
        /// @param my vertical mouse position
        /// @return pointer to short-help text or nullptr
        char *CreateShortHelp(const long mx, const long my);
#endif
#ifdef MUIM_CreateDragImage
        /// @brief [ @b MUIM_CreateDragImage ] Create a drag image for this object at the given touch coordinates.
        /// @param touchx x coordinate where the user grabbed the object
        /// @param touchy y coordinate where the user grabbed the object
        /// @param flags creation flags, by default 0
        /// @return pointer to the created MUI_DragImage structure, or nullptr on failure
        struct MUI_DragImage *CreateDragImage(const long touchx, const long touchy, const unsigned long flags = 0);
#endif
#ifdef MUIM_DeleteBubble
        /// @brief [ @b MUIM_DeleteBubble ] Delete a previously created bubble handle.
        /// @param bubble handle returned by CreateBubble
        Area &DeleteBubble(APTR bubble);
#endif
#ifdef MUIM_DeleteDragImage
        /// @brief [ @b MUIM_DeleteDragImage ] Delete a drag image previously created by CreateDragImage.
        /// @param di drag image structure returned by CreateDragImage
        Area &DeleteDragImage(struct MUI_DragImage *di);
#endif
#ifdef MUIM_DeleteShortHelp
        /// @brief [ @b MUIM_DeleteShortHelp ] Release short-help text created by CreateShortHelp.
        /// @param help pointer previously returned by CreateShortHelp
        Area &DeleteShortHelp(char *help);
#endif
#ifdef MUIM_DoDrag
        /// @brief [ @b MUIM_DoDrag ] Start drag and drop operation from this object.
        /// @param touchx x coordinate where user grabbed object
        /// @param touchy y coordinate where user grabbed object
        /// @param flags drag flags
        /// @return result code from MUIM_DoDrag
        unsigned long DoDrag(const long touchx, const long touchy, const unsigned long flags = 0);
#endif
#ifdef MUIM_DragQuery
        /// @brief [ @b MUIM_DragQuery ] Ask whether dragging from the given object is accepted.
        /// @param obj source object
        /// @return MUIV_DragQuery_Refuse or MUIV_DragQuery_Accept
        unsigned long DragQuery(const Object *obj);
        /// @brief [ @b MUIM_DragQuery ] Ask whether dragging from the given object is accepted.
        /// @param obj source object
        /// @return MUIV_DragQuery_Refuse or MUIV_DragQuery_Accept
        unsigned long DragQuery(const Root &obj);
#endif
#ifdef MUIM_DragBegin
        /// @brief [ @b MUIM_DragBegin ] Notify destination that a drag operation from source object has started.
        /// @param obj source object
        /// @return result code from MUIM_DragBegin
        unsigned long DragBegin(const Object *obj);
        /// @brief [ @b MUIM_DragBegin ] Notify destination that a drag operation from source object has started.
        /// @param obj source object
        /// @return result code from MUIM_DragBegin
        unsigned long DragBegin(const Root &obj);
#endif
#ifdef MUIM_DragDrop
        /// @brief [ @b MUIM_DragDrop ] Notify destination about a drop operation.
        /// @param obj source object
        /// @param x drop x position
        /// @param y drop y position
        /// @param qualifier input qualifier flags
        /// @return result code from MUIM_DragDrop
        unsigned long DragDrop(const Object *obj, const long x, const long y, const unsigned long qualifier);
        /// @brief [ @b MUIM_DragDrop ] Notify destination about a drop operation.
        /// @param obj source object
        /// @param x drop x position
        /// @param y drop y position
        /// @param qualifier input qualifier flags
        /// @return result code from MUIM_DragDrop
        unsigned long DragDrop(const Root &obj, const long x, const long y, const unsigned long qualifier);
#endif
#ifdef MUIM_DragFinish
        /// @brief [ @b MUIM_DragFinish ] Notify destination that drag operation finished.
        /// @param obj source object
        /// @param dropfollows non-zero if a drop call will follow
        /// @return result code from MUIM_DragFinish
        unsigned long DragFinish(const Object *obj, const long dropfollows);
        /// @brief [ @b MUIM_DragFinish ] Notify destination that drag operation finished.
        /// @param obj source object
        /// @param dropfollows non-zero if a drop call will follow
        /// @return result code from MUIM_DragFinish
        unsigned long DragFinish(const Root &obj, const long dropfollows);
#endif
#ifdef MUIM_DragReport
        /// @brief [ @b MUIM_DragReport ] Report drag position updates to the destination object.
        /// @param obj source object
        /// @param x current mouse x position
        /// @param y current mouse y position
        /// @param update non-zero if this is a move/update notification
        /// @param qualifier input qualifier flags from Intuition
        /// @return one of MUIV_DragReport_* values
        unsigned long DragReport(const Object *obj, const long x, const long y, const long update, const unsigned long qualifier);
        /// @brief [ @b MUIM_DragReport ] Report drag position updates to the destination object.
        /// @param obj source object
        /// @param x current mouse x position
        /// @param y current mouse y position
        /// @param update non-zero if this is a move/update notification
        /// @param qualifier input qualifier flags from Intuition
        /// @return one of MUIV_DragReport_* values
        unsigned long DragReport(const Root &obj, const long x, const long y, const long update, const unsigned long qualifier);
#endif
#ifdef MUIM_DrawBackground
        /// @brief [ @b MUIM_DrawBackground ] Draw the object's background in the specified rectangle.
        /// @param left left edge of destination rectangle
        /// @param top top edge of destination rectangle
        /// @param width destination width
        /// @param height destination height
        /// @param xoffset background source x offset
        /// @param yoffset background source y offset
        /// @param flags draw flags, by default 0
        Area &DrawBackground(const long left, const long top, const long width, const long height, const long xoffset, const long yoffset,
                             const long flags = 0);
#endif
#ifdef MUIM_DrawBackgroundParent
        /// @brief [ @b MUIM_DrawBackgroundParent ] Draw parent background in the specified rectangle.
        /// @param left left edge of destination rectangle
        /// @param top top edge of destination rectangle
        /// @param width destination width
        /// @param height destination height
        /// @param brightness brightness adjustment
        /// @param xoffset background source x offset
        /// @param yoffset background source y offset
        /// @param flags draw flags, by default 0
        Area &DrawBackgroundParent(const long left, const long top, const long width, const long height, const long brightness,
                                   const long xoffset, const long yoffset, const long flags = 0);
#endif

#ifdef MUIM_Relayout
        /// @brief [ @b MUIM_Relayout, flags = 0 ] Perform a full relayout of the object in case it is visible. Actually the object will be
        /// completely hidden and shown again to trigger a full redraw as well.
        Area &Relayout();
#endif
#ifdef MUIM_WhichPointerType
        /// @brief [ @b MUIM_WhichPointerType ] Ask what pointer type should be displayed at the given coordinates.
        /// @param mx horizontal mouse position relative to the object
        /// @param my vertical mouse position relative to the object
        /// @return pointer type suggested by MUI for the given coordinates
        enum PointerType WhichPointerType(const long mx, const long my);
#endif
#ifdef MUIM_Text
        /// @brief [ @b MUIM_Text ] This function is a preferred way to render text inside the object. It uses the object's font and it's
        /// color (if not specified in the string itself).
        /// @param left rectangle to render the text into
        /// @param top rectangle to render the text into
        /// @param width rectangle to render the text into
        /// @param height rectangle to render the text into
        /// @param text the text to be rendered
        /// @param len the number of characters to be respected, pass -1 to render the full string
        /// @param preparse an optional preparse string, may be empty
        /// @param ulchar character to be underlined (i.e. as shortcut), pass 0 for no underlining
        Area &Text(const long left, const long top, const long width, const long height, const std::string &text, const long len,
                   const std::string &preparse, const char ulchar = 0);
#endif
#ifdef MUIM_TextDim
        /// @brief [ @b MUIM_TextDim ] Use this function to measure the area which will be required to render a text of the given length.
        /// All facilities of MUI's text engine are allowed for both the text and the preparse string. Refer to MUIA_Text_Contents for all
        /// possible sequences.
        /// @param text the text to be measured
        /// @param len the number of characters to be respected, pass -1 to measure the full string
        /// @param preparse an optional preparse string, may be empty
        /// @param flags currently unused, by default 0
        /// @return the calculated width and height of the text string
        Dim TextDim(const std::string &text, const long len, const std::string &preparse, const long flags = 0);
#endif
    };

    template <typename T, typename U> class AreaBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
      public:
        AreaBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Area)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Background ]
        T &tagBackground(const enum ImageOrBackground background);
        /// @brief [ @b MUIA_Background ]
        /// The string is copied and stored internally by this C++ wrapper!
        T &tagBackground(const std::string &background);
        /// @brief [ @b MUIA_Background ]
        /// The string is copied and stored internally by this C++ wrapper!
        T &tagBackground(const char *background);
        /// @brief [ @b MUIA_ContextMenu ]
        T &tagContextMenu(const Menustrip &contextMenu);
#ifdef MUIA_ContextMenuHook
        /// @brief [ @b MUIA_ContextMenuHook ]
        T &tagContextMenuHook(const Hook *contextMenuHook);
#endif
        /// @brief [ @b MUIA_ControlChar ]
        T &tagControlChar(const char controlChar);
        /// @brief [ @b MUIA_CycleChain ]
        /// Keyboard cycle chain system. Set MUIA_CycleChain to 1 for every object that you want to have in your chain, MUI does the rest
        /// automatically.
        T &tagCycleChain(const long cycleChain = 1);
        /// @brief [ @b MUIA_Disabled ]
        T &tagDisabled(const bool disabled = true);
        /// @brief [ @b MUIA_Draggable ]
        T &tagDraggable(const bool draggable);
        /// @brief [ @b MUIA_Dropable ]
        T &tagDropable(const bool dropable);
        /// @brief [ @b MUIA_FillArea ]
        T &tagFillArea(const bool fillArea);
        /// @brief [ @b MUIA_FixHeight ]
        /// Give your object a fixed pixel height. This tag is absolutely not needed in a general MUI application and only present for
        /// emergency situations.
        T &tagFixHeight(const long fixHeight);
        /// @brief [ @b MUIA_FixHeightTxt ]
        T &tagFixHeightTxt(const std::string &fixHeightTxt);
        /// @brief [ @b MUIA_FixWidth ]
        /// Give your object a fixed pixel width. This tag is absolutely not needed in a general MUI application and only present for
        /// emergency situations.
        T &tagFixWidth(const long fixWidth);
        /// @brief [ @b MUIA_FixWidthTxt ]
        T &tagFixWidthTxt(const std::string &fixWidthTxt);
#ifdef MUIA_Floating
        /// @brief [ @b MUIA_Floating ]
        T &tagFloating(const bool floating);
#endif
        /// @brief [ @b MUIA_MaxHeight ]
        T &tagMaxHeight(const long maxHeight);
        /// @brief [ @b MUIA_MaxWidth ]
        T &tagMaxWidth(const long maxWidth);
        /// @brief [ @b MUIA_MinHeight ]
        T &tagMinHeight(const long minHeight);
        /// @brief [ @b MUIA_MinWidth ]
        T &tagMinWidth(const long minWidth);
        /// @brief [ @b MUIA_Font] (for "struct TextFont *" should be separate method)
        /// @param font enum Font
        T &tagFont(const enum Font font);
        /// @brief [ @b MUIA_Frame ]
        /// @param frame enum Frame
        T &tagFrame(const enum Frame frame);
#ifdef MUIA_FrameDynamic
        /// @brief [ @b MUIA_FrameDynamic ]
        /// Defines whether the object's frame will be dynamically visible or not. If set to `true` the frame will be made visible as soon
        /// as the mouse pointer is over the object and made invisible when the mouse leaves the object. Best use the attribute together
        /// with attribute `MUIA_FrameVisible` set to `false` to make the frame invisible by default.
        T &tagFrameDynamic(const bool dynamic);
#endif
        /// @brief [ @b MUIA_FramePhantomHoriz ]
        /// Setting this to `true` causes the specified frame to be a horizontal phantom frame. The frame will not appear but its vertical
        /// components (frame height, inner top and inner bottom spacing) will be used to calculate positions and dimensions (horizontal
        /// components are treated as 0). This is extremely useful for a correct labeling of objects. You would e.g. label a string gadget
        /// by using a text object with a phantom string frame. Thus, the label text will be always on the same vertical position as the
        /// string gadget text, no matter what spacing values the user configured.
        T &tagFramePhantomHoriz(const bool phantomHoriz);
        /// @brief [ @b MUIA_FrameTitle ]
        /// This tag identifies a text string that will be displayed in the top line of a frame. This can come in handy if you want to name
        /// groups of objects. You may not use `MUIA_FrameTitle` without defining a `MUIA_Frame`.
        T &tagFrameTitle(const std::string &frameTitle);
#ifdef MUIA_FrameVisible
        /// @brief [ @b MUIA_FrameVisible ]
        T &tagFrameVisible(const bool frameVisible);
#endif
        /// @brief [ @b MUIA_HorizDisappear ]
        T &tagHorizDisappear(const long horizDisappear);
        /// @brief [ @b MUIA_HorizWeight ]
        T &tagHorizWeight(const short horizWeight);
        /// @brief [ @b MUIA_InnerBottom ]
        T &tagInnerBottom(const long innerBottom);
        /// @brief [ @b MUIA_InnerLeft ]
        T &tagInnerLeft(const long innerLeft);
        /// @brief [ @b MUIA_InnerRight ]
        T &tagInnerRight(const long innerRight);
        /// @brief [ @b MUIA_InnerTop ]
        T &tagInnerTop(const long innerTop);
        /// @brief [ @b MUIA_InnerLeft, @b MUIA_InnerRight, @b MUIA_InnerTop, @b MUIA_InnerBottom ]
        /// Convenience method to set all inner spacing at once.
        T &tagInnerSpacing(const long horiz, const long vert);
        /// @brief [ @b MUIA_InputMode ]
        /// @param inputMode enum InputMode
        T &tagInputMode(const enum InputMode inputMode);
#ifdef MUIA_KnowsDisabled
        /// @brief [ @b MUIA_KnowsDisabled ]
        T &tagKnowsDisabled(const bool knowsDisabled);
#endif
#ifdef MUIA_DoubleBuffer
        /// @brief [ @b MUIA_DoubleBuffer ]
        T &tagDoubleBuffer(const bool doubleBuffer);
#endif
#ifdef MUIA_PointerType
        /// @brief [ @b MUIA_PointerType ]
        /// @param font enum PointerType
        T &tagPointerType(const enum PointerType pointerType);
#endif
        /// @brief [ @b MUIA_Selected ]
        T &tagSelected(const bool selected);
        /// @brief [ @b MUIA_ShowMe ]
        T &tagShowMe(const bool showMe);
        /// @brief [ @b MUIA_ShortHelp ] Specify a string that is to be used as bubble help for this object.
        /// @param shortHelp help text, if empty then is ignored, not added to tag list
        T &tagShortHelp(const std::string &shortHelp);
        /// @brief [ @b MUIA_ShowSelState ]
        T &tagShowSelState(const bool showSelState);
        /// @brief [ @b MUIA_VertDisappear ]
        T &tagVertDisappear(const long vertDisappear);
#ifdef MUIA_TextColor
        /// @brief [ @b MUIA_TextColor ]
        T &tagTextColor(const struct MUI_PenSpec *textColor);
#endif
        /// @brief [ @b MUIA_VertWeight ]
        T &tagVertWeight(const short vertWeight);
        /// @brief [ @b MUIA_Weight ]
        /// An object with a weight of 0 will always stay at its minimum size. By default, all objects have a weight of 100.
        /// @param weight short weight of object, for negative value is ignored
        T &tagWeight(const short weight);

      protected:
        bool Validate() const override;
    };

    class AreaBuilder : public AreaBuilderTemplate<AreaBuilder, Area>
    {
      public:
        AreaBuilder();
    };
}

#define MUI_AREA_TPP_INCLUDE
#include "Area.tpp"
#undef MUI_AREA_TPP_INCLUDE
