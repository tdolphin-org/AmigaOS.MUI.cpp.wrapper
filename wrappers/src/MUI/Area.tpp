//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_AREA_TPP_INCLUDE
#error "File Area.tpp can not be included directly, include file Area.hpp instead!"
#endif

#include "Menustrip.hpp"

namespace MUI
{
    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagBackground(const enum ImageOrBackground background)
    {
        this->PushTag(MUIA_Background, (long)background);
        return (T &)*this;
    }

    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagBackground(const std::string &background)
    {
        this->PushTag(MUIA_Background, this->StoreString(MUIA_Background, background));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagBackground(const char *background)
    {
        this->PushTag(MUIA_Background, this->StoreString(MUIA_Background, background));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagContextMenu(const Menustrip &contextMenu)
    {
        this->PushTag(MUIA_ContextMenu, contextMenu.muiObject());
        return (T &)*this;
    }

#ifdef MUIA_ContextMenuHook
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagContextMenuHook(const Hook *contextMenuHook)
    {
        this->PushTag(MUIA_ContextMenuHook, contextMenuHook);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagControlChar(const char controlChar)
    {
        this->PushTag(MUIA_ControlChar, (long)controlChar);
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

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagDraggable(const bool draggable)
    {
        this->PushTag(MUIA_Draggable, draggable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagDropable(const bool dropable)
    {
        this->PushTag(MUIA_Dropable, dropable);
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
        this->PushTag(MUIA_FixHeightTxt, this->StoreString(MUIA_FixHeightTxt, fixHeightTxt));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFixWidth(const long fixWidth)
    {
        this->PushTag(MUIA_FixWidth, fixWidth);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFixWidthTxt(const std::string &fixWidthTxt)
    {
        this->PushTag(MUIA_FixWidthTxt, this->StoreString(MUIA_FixWidthTxt, fixWidthTxt));
        return (T &)*this;
    }

#ifdef MUIA_Floating
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFloating(const bool floating)
    {
        this->PushTag(MUIA_Floating, floating);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagMaxHeight(const long maxHeight)
    {
        this->PushTag(MUIA_MaxHeight, maxHeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagMaxWidth(const long maxWidth)
    {
        this->PushTag(MUIA_MaxWidth, maxWidth);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagMinHeight(const long minHeight)
    {
        this->PushTag(MUIA_MinHeight, minHeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagMinWidth(const long minWidth)
    {
        this->PushTag(MUIA_MinWidth, minWidth);
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

#ifdef MUIA_FrameDynamic
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFrameDynamic(const bool dynamic)
    {
        this->PushTag(MUIA_FrameDynamic, dynamic);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFramePhantomHoriz(const bool phantomHoriz)
    {
        this->PushTag(MUIA_FramePhantomHoriz, phantomHoriz);
        return (T &)*this;
    }

    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagFrameTitle(const std::string &frameTitle)
    {
        if (!frameTitle.empty())
        {
            auto copy = this->StoreString(MUIA_FrameTitle, frameTitle);
            this->PushTag(MUIA_FrameTitle, copy);
        }

        return (T &)*this;
    }

#ifdef MUIA_FrameVisible
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFrameVisible(const bool frameVisible)
    {
        this->PushTag(MUIA_FrameVisible, frameVisible);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagHorizDisappear(const long horizDisappear)
    {
        this->PushTag(MUIA_HorizDisappear, horizDisappear);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagHorizWeight(const short horizWeight)
    {
        if (horizWeight >= 0)
            this->PushTag(MUIA_HorizWeight, (long)horizWeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInnerBottom(const long innerBottom)
    {
        this->PushTag(MUIA_InnerBottom, innerBottom);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInnerLeft(const long innerLeft)
    {
        this->PushTag(MUIA_InnerLeft, innerLeft);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInnerRight(const long innerRight)
    {
        this->PushTag(MUIA_InnerRight, innerRight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInnerTop(const long innerTop)
    {
        this->PushTag(MUIA_InnerTop, innerTop);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInnerSpacing(const long horiz, const long vert)
    {
        this->PushTag(MUIA_InnerLeft, horiz);
        this->PushTag(MUIA_InnerRight, horiz);
        this->PushTag(MUIA_InnerTop, vert);
        this->PushTag(MUIA_InnerBottom, vert);
        return (T &)*this;
    }

#ifdef MUIA_InputMode
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInputMode(const enum InputMode inputMode)
    {
        this->PushTag(MUIA_InputMode, (long)inputMode);
        return (T &)*this;
    }
#endif

#ifdef MUIA_KnowsDisabled
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagKnowsDisabled(const bool knowsDisabled)
    {
        this->PushTag(MUIA_KnowsDisabled, knowsDisabled);
        return (T &)*this;
    }
#endif

#ifdef MUIA_DoubleBuffer
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagDoubleBuffer(const bool doubleBuffer)
    {
        this->PushTag(MUIA_DoubleBuffer, doubleBuffer);
        return (T &)*this;
    }
#endif

#ifdef MUIA_PointerType
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
        if (!shortHelp.empty())
        {
            auto copy = this->StoreString(MUIA_ShortHelp, shortHelp);
            this->PushTag(MUIA_ShortHelp, copy);
        }
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagShowSelState(const bool showSelState)
    {
        this->PushTag(MUIA_ShowSelState, showSelState);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagVertDisappear(const long vertDisappear)
    {
        this->PushTag(MUIA_VertDisappear, vertDisappear);
        return (T &)*this;
    }

#ifdef MUIA_TextColor
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagTextColor(const struct MUI_PenSpec *textColor)
    {
        this->PushTag(MUIA_TextColor, textColor);
        return (T &)*this;
    }
#endif

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

    template <typename T, typename U> inline bool AreaBuilderTemplate<T, U>::Validate() const
    {
        auto result = NotifyBuilderTemplate<T, U>::Validate();
        if (this->ContainsTag(MUIA_FrameTitle))
        {
            if (!this->ContainsTag(MUIA_Frame))
            {
                std::cerr << __PRETTY_FUNCTION__ << ", missing Frame attribute for Area with FrameTitle attribute!" << std::endl;
                return false;
            }
        }

        return result;
    }
}
