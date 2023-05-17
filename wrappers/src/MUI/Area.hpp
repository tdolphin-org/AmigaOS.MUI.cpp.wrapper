//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Notify.hpp"
#include "ValueTypes/Font.hpp"
#include "ValueTypes/Frame.hpp"
#include "ValueTypes/ImageOrBackground.hpp"
#include "ValueTypes/InputMode.hpp"
#include "ValueTypes/PointerType.hpp"

#undef Enable
#undef Disable

namespace MUI
{
    class SourceNotifier;

    class Area : public Notify
    {
      public:
        Area(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Area(const Root &root)
          : Notify(root.muiObject())
        {
        }

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Selected ]
        bool getSelected() const;

        /// @brief [ @b MUIA_Disabled ]
        Area &setDisabled(const bool disabled);
        /// @brief [ @b MUIA_Font ] - seems that setting font doesn't work (at least for MUI::Floattext)
        Area &setFont(const enum Font font);
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_PointerType ]
        Area &setPointerType(const enum PointerType pointerType);
#endif
        /// @brief [ @b MUIA_Selected ]
        Area &setSelected(const bool selected);
        /// @brief [ @b MUIA_ShortHelp ]
        Area &setShortHelp(const std::string &shortHelp);

        // methods, some can return object reference

        /// @brief setDisabled(false)
        Area &Enable();
        /// @brief setDisabled(true)
        Area &Disable();

        //  notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Selected ]
        SourceNotifier onSelected(const bool selected);
        /// @brief [ @b MUIM_Notify, @b MUIA_Pressed ]
        SourceNotifier onPressed(const bool pressed);
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
        /// @brief [ @b MUIA_CycleChain ]
        T &tagCycleChain(const long cycleChain);
        /// @brief [ @b MUIA_Disabled ]
        T &tagDisabled(const bool disabled = true);
        /// @brief [ @b MUIA_Frame ]
        /// @param frame enum Frame
        T &tagFrame(const enum Frame frame);
        /// @brief [ @b MUIA_FrameTitle ]
        T &tagFrameTitle(char *frameTitle);
        /// @brief [ @b MUIA_Font] (for "struct TextFont *" should be separate method)
        /// @param font enum Font
        T &tagFont(const enum Font font);
        /// @brief [ @b MUIA_InputMode ]
        /// @param inputMode enum InputMode
        T &tagInputMode(const enum InputMode inputMode);
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_PointerType ]
        /// @param font enum PointerType
        T &tagPointerType(const enum PointerType pointerType);
#endif
        /// @brief [ @b MUIA_ShortHelp ]
        T &tagShortHelp(const std::string &shortHelp);
        /// @brief [ @b MUIA_Weight ]
        T &tagWeight(const long weight);
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

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFrame(const enum Frame frame)
    {
        this->PushTag(MUIA_Frame, (long)frame);
        return (T &)*this;
    }

    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagFrameTitle(char *frameTitle)
    {
        this->PushTag(MUIA_FrameTitle, frameTitle);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFont(const enum Font font)
    {
        this->PushTag(MUIA_Font, (long)font);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInputMode(const enum InputMode inputMode)
    {
        this->PushTag(MUIA_InputMode, (long)inputMode);
        return (T &)*this;
    }

#ifndef __MORPHOS__
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagPointerType(const PointerType pointerType)
    {
        this->PushTag(MUIA_PointerType, (long)pointerType);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagShortHelp(const std::string &shortHelp)
    {
        this->PushTag(MUIA_ShortHelp, shortHelp);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagWeight(const long weight)
    {
        this->PushTag(MUIA_Weight, weight);
        return (T &)*this;
    }
}
