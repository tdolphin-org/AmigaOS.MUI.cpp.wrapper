//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

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
#ifndef __MORPHOS__
    struct Dim
    {
        long width;
        long height;

        Dim(const unsigned long value);
    };
#endif

    class Area : public Notify
    {
      public:
        Area(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Area(const APTR pMuiObject)
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

        /// @brief [ @b MUIA_BottomEdge ]
        long getBottomEdge() const;
        /// @brief [ @b MUIA_ContextMenu ]
        Object *getContextMenu() const;
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_ContextMenuHook ]
        Hook *getContextMenuHook() const;
#endif
        /// @brief [ @b MUIA_ContextMenuTrigger ]
        Object *getContextMenuTrigger() const;
        /// @brief [ @b MUIA_ControlChar ]
        char getControlChar() const;
        /// @brief [ @b MUIA_CycleChain ]
        long getCycleChain() const;
        /// @brief [ @b MUIA_Disabled ]
        bool isDisabled() const;
        /// @brief [ @b MUIA_DoubleBuffer ]
        bool isDoubleBuffer() const;
        /// @brief [ @b MUIA_DoubleClick ]
        bool isDoubleClick() const;
        /// @brief [ @b MUIA_Draggable ]
        bool isDraggable() const;
        /// @brief [ @b MUIA_Dropable ]
        bool isDropable() const;
        /// @brief [ @b MUIA_Floating ]
        bool isFloating() const;
        /// @brief [ @b MUIA_Font ]
        TextFont *getFont() const;
        /// @brief [ @b MUIA_FrameDynamic ]
        bool isFrameDynamic() const;
        /// @brief [ @b MUIA_FrameTitle ]
        std::string getFrameTitle() const;
        /// @brief [ @b MUIA_FrameVisible ]
        bool isFrameVisible() const;
        /// @brief [ @b MUIA_Height ]
        long getHeight() const;
        /// @brief [ @b MUIA_HorizDisappear ]
        long getHorizDisappear() const;
        /// @brief [ @b MUIA_HorizWeight ]
        short getHorizWeight() const;
        /// @brief [ @b MUIA_InnerBottom ]
        long getInnerBottom() const;
        /// @brief [ @b MUIA_InnerLeft ]
        long getInnerLeft() const;
        /// @brief [ @b MUIA_InnerRight ]
        long getInnerRight() const;
        /// @brief [ @b MUIA_InnerTop ]
        long getInnerTop() const;
        /// @brief [ @b MUIA_KnowsDisabled ]
        bool isKnowsDisabled() const;
        /// @brief [ @b MUIA_LeftEdge ]
        long getLeftEdge() const;
        /// @brief [ @b MUIA_PointerType ]
        enum PointerType getPointerType() const;
        /// @brief [ @b MUIA_Pressed ]
        bool isPressed() const;
        /// @brief [ @b MUIA_RightEdge ]
        long getRightEdge() const;
        /// @brief [ @b MUIA_Selected ]
        bool isSelected() const;
        /// @brief [ @b MUIA_ShortHelp ]
        std::string getShortHelp() const;
        /// @brief [ @b MUIA_ShowMe ]
        bool isShowMe() const;
        /// @brief [ @b MUIA_TextColor ]
        unsigned long getTextColor() const;
        /// @brief [ @b MUIA_Timer ]
        long getTimer() const;
        /// @brief [ @b MUIA_TopEdge ]
        long getTopEdge() const;
        /// @brief [ @b MUIA_VertDisappear ]
        long getVertDisappear() const;
        /// @brief [ @b MUIA_VertWeight ]
        short getVertWeight() const;
        /// @brief [ @b MUIA_Width ]
        long getWidth() const;
        /// @brief [ @b MUIA_Window ]
        Window *getWindow() const;
        /// @brief [ @b MUIA_WindowObject ]
        Object *getWindowObject() const;

        /// @brief [ @b MUIA_Background ]
        Area &setBackground(const enum ImageOrBackground background);
        /// @brief [ @b MUIA_Background ]
        Area &setBackground(const std::string &background);
        /// @brief [ @b MUIA_CycleChain ]
        /// Keyboard cycle chain system. Set MUIA_CycleChain to 1 for every object that you want to have in your chain, MUI does the rest
        /// automatically.
        Area &setCycleChain(const long cycleChain = 1);
        /// @brief [ @b MUIA_Disabled ]
        Area &setDisabled(const bool disabled);
        /// @brief [ @b MUIA_FillArea ]
        Area &setFillArea(const bool fillArea);
        /// @brief [ @b MUIA_Floating ]
        Area &setFloating(const bool floating);
        /// @brief [ @b MUIA_Font ] - seems that setting font doesn't work (at least for MUI::Floattext)
        Area &setFont(const enum Font font);
        /// @brief [ @b MUIA_HorizWeight ]
        Area &setHorizWeight(const short horizWeight);
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_PointerType ]
        Area &setPointerType(const enum PointerType pointerType);
#endif
        /// @brief [ @b MUIA_Selected ]
        Area &setSelected(const bool selected);
        /// @brief [ @b MUIA_ShortHelp ]
        Area &setShortHelp(const std::string &shortHelp);
        /// @brief [ @b MUIA_ShowMe ]
        Area &setShowMe(const bool showMe);
        /// @brief [ @b MUIA_VertWeight ]
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
        /// @brief setShowMe(true)
        Area &Show();
        /// @brief setShowMe(false)
        Area &Hide();

        /// @brief [ @b MUIM_Relayout, flags = 0 ] Perform a full relayout of the object in case it is visible. Actually the object will be
        /// completely hidden and shown again to trigger a full redraw as well.
        Area &Relayout();
#ifndef __MORPHOS__
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
        T &tagBackground(const std::string &background);
        /// @brief [ @b MUIA_Background ]
        T &tagBackground(const char *background);
        /// @brief [ @b MUIA_CycleChain ]
        /// Keyboard cycle chain system. Set MUIA_CycleChain to 1 for every object that you want to have in your chain, MUI does the rest
        /// automatically.
        T &tagCycleChain(const long cycleChain = 1);
        /// @brief [ @b MUIA_Disabled ]
        T &tagDisabled(const bool disabled = true);
        /// @brief [ @b MUIA_FillArea ]
        T &tagFillArea(const bool fillArea);
        /// @brief [ @b MUIA_FixHeight ]
        T &tagFixHeight(const long fixHeight);
        /// @brief [ @b MUIA_FixHeightTxt ]
        T &tagFixHeightTxt(const std::string &fixHeightTxt);
        /// @brief [ @b MUIA_FixWidth ]
        T &tagFixWidth(const long fixWidth);
        /// @brief [ @b MUIA_FixWidthTxt ]
        T &tagFixWidthTxt(const std::string &fixWidthTxt);
        /// @brief [ @b MUIA_Floating ]
        T &tagFloating(const bool floating);
        /// @brief [ @b MUIA_Font] (for "struct TextFont *" should be separate method)
        /// @param font enum Font
        T &tagFont(const enum Font font);
        /// @brief [ @b MUIA_Frame ]
        /// @param frame enum Frame
        T &tagFrame(const enum Frame frame);
        /// @brief [ @b MUIA_FrameDynamic ]
        T &tagDynamic(const bool dynamic);
        /// @brief [ @b MUIA_FramePhantomHoriz ]
        T &tagPhantomHoriz(const bool phantomHoriz);
        /// @brief [ @b MUIA_FrameTitle ]
        T &tagFrameTitle(const std::string &frameTitle);
        /// @brief [ @b MUIA_HorizWeight ]
        T &tagHorizWeight(const short horizWeight);
        /// @brief [ @b MUIA_InputMode ]
        /// @param inputMode enum InputMode
        T &tagInputMode(const enum InputMode inputMode);
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_PointerType ]
        /// @param font enum PointerType
        T &tagPointerType(const enum PointerType pointerType);
#endif
        /// @brief [ @b MUIA_Selected ]
        T &tagSelected(const bool selected);
        /// @brief [ @b MUIA_ShowMe ]
        T &tagShowMe(const bool showMe);
        /// @brief [ @b MUIA_ShortHelp ]
        T &tagShortHelp(const std::string &shortHelp);
        /// @brief [ @b MUIA_ShowSelState ]
        T &tagShowSelState(const bool showSelState);
        /// @brief [ @b MUIA_VertWeight ]
        T &tagVertWeight(const short vertWeight);
        /// @brief [ @b MUIA_Weight ]
        /// An object with a weight of 0 will always stay at its minimum size. By default, all objects have a weight of 100.
        /// @param weight short weight of object, for negative value is ignored
        T &tagWeight(const short weight);
    };

    class AreaBuilder : public AreaBuilderTemplate<AreaBuilder, Area>
    {
      public:
        AreaBuilder();
    };

    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagBackground(const enum ImageOrBackground background)
    {
        this->PushTag(MUIA_Background, (long)background);
        return (T &)*this;
    }

    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagBackground(const std::string &background)
    {
        this->PushTag(MUIA_Background, (long)background.c_str());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagBackground(const char *background)
    {
        this->PushTag(MUIA_Background, (long)background);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagCycleChain(const long cycleChain)
    {
        this->PushTag(MUIA_CycleChain, cycleChain);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagDisabled(const bool disabled)
    {
        this->PushTag(MUIA_Disabled, disabled);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFillArea(const bool fillArea)
    {
        this->PushTag(MUIA_FillArea, fillArea);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFixHeight(const long fixHeight)
    {
        this->PushTag(MUIA_FixHeight, fixHeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFixHeightTxt(const std::string &fixHeightTxt)
    {
        if (!fixHeightTxt.empty()) // no fixed height when empty string
            this->PushTag(MUIA_FixHeightTxt, fixHeightTxt);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFixWidth(const long fixWidth)
    {
        this->PushTag(MUIA_FixWidth, fixWidth);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFixWidthTxt(const std::string &fixWidthTxt)
    {
        if (!fixWidthTxt.empty()) // no fixed width when empty string
            this->PushTag(MUIA_FixWidthTxt, fixWidthTxt);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFloating(const bool floating)
    {
        this->PushTag(MUIA_Floating, floating);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFont(const enum Font font)
    {
        this->PushTag(MUIA_Font, (long)font);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFrame(const enum Frame frame)
    {
        this->PushTag(MUIA_Frame, (long)frame);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagDynamic(const bool dynamic)
    {
        this->PushTag(MUIA_FrameDynamic, dynamic);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagPhantomHoriz(const bool phantomHoriz)
    {
        this->PushTag(MUIA_FramePhantomHoriz, phantomHoriz);
        return (T &)*this;
    }

    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagFrameTitle(const std::string &frameTitle)
    {
        this->PushTag(MUIA_FrameTitle, frameTitle);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagHorizWeight(const short horizWeight)
    {
        if (horizWeight >= 0)
            this->PushTag(MUIA_HorizWeight, (long)horizWeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInputMode(const enum InputMode inputMode)
    {
        this->PushTag(MUIA_InputMode, (long)inputMode);
        return (T &)*this;
    }

#ifndef __MORPHOS__
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagPointerType(const enum PointerType pointerType)
    {
        this->PushTag(MUIA_PointerType, (long)pointerType);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagSelected(const bool selected)
    {
        this->PushTag(MUIA_Selected, selected);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagShowMe(const bool showMe)
    {
        this->PushTag(MUIA_ShowMe, showMe);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagShortHelp(const std::string &shortHelp)
    {
        auto copy = this->StoreString(shortHelp);
        this->PushTag(MUIA_ShortHelp, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagShowSelState(const bool showSelState)
    {
        this->PushTag(MUIA_ShowSelState, showSelState);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagVertWeight(const short vertWeight)
    {
        if (vertWeight >= 0)
            this->PushTag(MUIA_VertWeight, (long)vertWeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagWeight(const short weight)
    {
        if (weight >= 0)
            this->PushTag(MUIA_Weight, (long)weight);
        return (T &)*this;
    }
}
