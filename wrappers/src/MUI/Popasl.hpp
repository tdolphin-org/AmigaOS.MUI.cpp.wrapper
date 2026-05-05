//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <proto/asl.h>

#include "Popstring.hpp"

namespace MUI
{
    /// @brief As a subclass of popstring class, popasl can be used to pop up any kinds of
    /// standard system asl requesters. A separate task is spawned to handle these requesters,
    /// the application continues to run. MUI will automatically open one when the popup button
    /// is pressed and update the corresponding string gadget when the user terminates the requester.
    class Popasl : public Popstring
    {
      public:
        explicit Popasl(Object *pMuiObject)
          : Popstring(pMuiObject)
        {
        }

        Popasl(const Root &root)
          : Popstring(root.muiObject())
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

        /// @brief [ @b MUIA_Popasl_Active ] Popasl creates asynchronous popups. Requesters are
        /// opened in a separately spawned task and don't disturb the rest of the application.
        /// Returns true when the requester is currently open, false otherwise.
        bool isActive() const;
        /// @brief [ @b MUIA_Popasl_StartHook ] Hook called immediately before the asl requester
        /// is opened. Receives itself in A0, the popasl object in A2 and a taglist in A1.
        /// Return TRUE to open the requester, FALSE to cancel.
        Hook *getStartHook() const;
        /// @brief [ @b MUIA_Popasl_StopHook ] Hook called when the requester terminates. Receives
        /// itself in A0, the popasl object in A2 and a pointer to the asl requester structure in A1.
        Hook *getStopHook() const;
        /// @brief [ @b MUIA_Popasl_Type ] The type of asl requester. The same value you would use
        /// for AllocAslRequest(), e.g. ASL_FileRequest, ASL_FontRequest or ASL_ScreenModeRequest.
        unsigned long getType() const;
#ifdef MUIA_Popasl_MUIFontStyles
        /// @brief [ @b MUIA_Popasl_MUIFontStyles ] Whether MUI font styles are used for font
        /// requesters. MorphOS MUI5 extension.
        bool isMUIFontStyles() const;
#endif

        /// @brief [ @b MUIA_Popasl_StartHook ] Hook called immediately before the asl requester
        /// is opened. Receives itself in A0, the popasl object in A2 and a taglist in A1.
        /// Return TRUE to open the requester, FALSE to cancel.
        Popasl &setStartHook(const Hook *startHook);
        /// @brief [ @b MUIA_Popasl_StopHook ] Hook called when the requester terminates. Receives
        /// itself in A0, the popasl object in A2 and a pointer to the asl requester structure in A1.
        Popasl &setStopHook(const Hook *stopHook);
#ifdef MUIA_Popasl_MUIFontStyles
        /// @brief [ @b MUIA_Popasl_MUIFontStyles ] Whether MUI font styles are used for font
        /// requesters. MorphOS MUI5 extension.
        Popasl &setMUIFontStyles(const bool muiFontStyles);
#endif
    };

    template <typename T, typename U> class PopaslBuilderTemplate : public PopstringBuilderTemplate<T, U>
    {
      public:
        PopaslBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popasl)
          : PopstringBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Popasl_StartHook ] Hook called immediately before the asl requester
        /// is opened. Receives itself in A0, the popasl object in A2 and a taglist in A1.
        /// Return TRUE to open the requester, FALSE to cancel.
        T &tagStartHook(const Hook *startHook);
        /// @brief [ @b MUIA_Popasl_StopHook ] Hook called when the requester terminates. Receives
        /// itself in A0, the popasl object in A2 and a pointer to the asl requester structure in A1.
        T &tagStopHook(const Hook *stopHook);
        /// @brief [ @b MUIA_Popasl_Type ] Set the type of asl requester. Pass the same value you
        /// would use for AllocAslRequest(), e.g. ASL_FileRequest, ASL_FontRequest or
        /// ASL_ScreenModeRequest.
        T &tagType(const unsigned long type);
#ifdef MUIA_Popasl_MUIFontStyles
        /// @brief [ @b MUIA_Popasl_MUIFontStyles ] Whether MUI font styles are used for font
        /// requesters. MorphOS MUI5 extension.
        T &tagMUIFontStyles(const bool muiFontStyles = true);
#endif

        // File requester tags

        /// @brief [ @b ASLFR_TitleText ] Title text of the file requester window.
        T &tagAslFrTitleText(const char *titleText);
        /// @brief [ @b ASLFR_TitleText ] Title text of the file requester window.
        T &tagAslFrTitleText(const std::string &titleText);
        /// @brief [ @b ASLFR_DoPatterns ] Enable pattern matching in the file requester.
        T &tagAslFrDoPatterns(const bool doPatterns = true);
        /// @brief [ @b ASLFR_DrawersOnly ] Show only drawers (directories), no files.
        T &tagAslFrDrawersOnly(const bool drawersOnly = true);
        /// @brief [ @b ASLFR_RejectIcons ] Reject icon (.info) files from the file requester.
        T &tagAslFrRejectIcons(const bool rejectIcons = true);
        /// @brief [ @b ASLFR_RejectPattern ] Pattern for files to reject in the file requester.
        T &tagAslFrRejectPattern(const std::string &rejectPattern);
        /// @brief [ @b ASLFR_AcceptPattern ] Pattern for files to accept in the file requester.
        T &tagAslFrAcceptPattern(const std::string &acceptPattern);
        /// @brief [ @b ASLFR_FilterDrawers ] Apply the accept/reject pattern to drawers as well.
        T &tagAslFrFilterDrawers(const bool filterDrawers = true);
    };

    class PopaslBuilder : public PopaslBuilderTemplate<PopaslBuilder, Popasl>
    {
      public:
        PopaslBuilder();
    };
}

#define MUI_POPASL_TPP_INCLUDE
#include "Popasl.tpp"
#undef MUI_POPASL_TPP_INCLUDE
