//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <proto/muimaster.h>

#include <string>

// undef macros from mui.h
#undef SimpleButton
#undef PopButton
#undef Label
#undef Label1
#undef Label2
#undef LLabel
#undef LLabel1
#undef LLabel2
#undef CLabel
#undef CLabel1
#undef CLabel2
#undef FreeLabel
#undef FreeLabel1
#undef FreeLabel2
#undef FreeLLabel
#undef FreeLLabel1
#undef FreeLLabel2
#undef FreeCLabel
#undef FreeCLabel1
#undef FreeCLabel2
#undef HVSpace
#undef HSpace
#undef VSpace
#undef HCenter
#undef VCenter

namespace MUI
{
    /// @brief factory
    class MakeObject
    {
      public:
        /// @brief [ @b MUIO_Checkmark ]
        static Object *Checkmark();

        /// @brief [ @b MUIO_Button ]
        static Object *SimpleButton(const char *label);
        /// @brief [ @b MUIO_Button ]
        static Object *SimpleButton(const std::string &label);

        /// @brief [ @b MUIO_Button ]
        static Object *PopButton(unsigned long img);

        /// @brief [ @b MUIO_Label ] For use with objects without a frame. Right justify. [ like MUI macro @b Label() ]
        static Object *Label(const char *label);
        /// @brief [ @b MUIO_Label ] For use with objects without a frame. Right justify. [ like MUI macro @b Label() ]
        static Object *Label(const std::string &label);
        /// @brief [ @b MUIO_Label ] For use with standard frames (e.g. checkmarks). Right justify. [ like MUI macro @b Label1() ]
        static Object *Label1(const char *label);
        /// @brief [ @b MUIO_Label ] For use with standard frames (e.g. checkmarks). Right justify. [ like MUI macro @b Label1() ]
        static Object *Label1(const std::string &label);
        /// @brief [ @b MUIO_Label ] For use with double high frames (e.g. string gadgets). Right justify. [ like MUI macro @b Label2() ]
        static Object *Label2(const char *label);
        /// @brief [ @b MUIO_Label ] For use with double high frames (e.g. string gadgets). Right justify. [ like MUI macro @b Label2() ]
        static Object *Label2(const std::string &label);

        /// @brief [ @b MUIO_Label ] For use with objects without a frame. Left justify. [ like MUI macro @b LLabel() ]
        static Object *LLabel(const char *label);
        /// @brief [ @b MUIO_Label ] For use with objects without a frame. Left justify. [ like MUI macro @b LLabel() ]
        static Object *LLabel(const std::string &label);
        /// @brief [ @b MUIO_Label ] For use with standard frames (e.g. checkmarks). Left justify. [ like MUI macro @b LLabel1() ]
        static Object *LLabel1(const char *label);
        /// @brief [ @b MUIO_Label ] For use with standard frames (e.g. checkmarks). Left justify. [ like MUI macro @b LLabel1() ]
        static Object *LLabel1(const std::string &label);
        /// @brief [ @b MUIO_Label ] For use with double high frames (e.g. string gadgets). Left justify. [ like MUI macro @b LLabel2() ]
        static Object *LLabel2(const char *label);
        /// @brief [ @b MUIO_Label ] For use with double high frames (e.g. string gadgets). Left justify. [ like MUI macro @b LLabel2() ]
        static Object *LLabel2(const std::string &label);

        /// @brief [ @b MUIO_Label ] For use with objects without a frame. Centered. [ like MUI macro @b CLabel() ]
        static Object *CLabel(const char *label);
        /// @brief [ @b MUIO_Label ] For use with objects without a frame. Centered. [ like MUI macro @b CLabel() ]
        static Object *CLabel(const std::string &label);
        /// @brief [ @b MUIO_Label ] For use with standard frames (e.g. checkmarks). Centered. [ like MUI macro @b CLabel1() ]
        static Object *CLabel1(const char *label);
        /// @brief [ @b MUIO_Label ] For use with standard frames (e.g. checkmarks). Centered. [ like MUI macro @b  CLabel1() ]
        static Object *CLabel1(const std::string &label);
        /// @brief [ @b MUIO_Label ] For use with double high frames (e.g. string gadgets). Centered. [ like MUI macro @b CLabel2() ]
        static Object *CLabel2(const char *label);
        /// @brief [ @b MUIO_Label ] For use with double high frames (e.g. string gadgets). Centered. [ like MUI macro @b CLabel2() ]
        static Object *CLabel2(const std::string &label);

        /// @brief [ @b MUIO_Label ] For use with objects without a frame. Right justify. [ like MUI macro @b FreeLabel() ]
        static Object *FreeLabel(const std::string &label);
        /// @brief [ @b MUIO_Label ] For use with standard frames (e.g. checkmarks). Right justify. [ like MUI macro @b FreeLabel1() ]
        static Object *FreeLabel1(const std::string &label);
        /// @brief [ @b MUIO_Label ] For use with double high frames (e.g. string gadgets). Right justify. [ like MUI macro @b FreeLabel2()
        /// ]
        static Object *FreeLabel2(const std::string &label);
        /// @brief [ @b MUIO_Label, @b MUIO_Label_FreeVert ] For use with objects without a frame. Left justify. [ like MUI macro @b
        /// FreeLLabel() ]
        static Object *FreeLLabel(const std::string &label);
        /// @brief [ @b MUIO_Label, @b MUIO_Label_FreeVert ] For use with standard frames (e.g. checkmarks). Left justify. [ like MUI macro
        /// @b FreeLLabel1() ]
        static Object *FreeLLabel1(const std::string &label);
        /// @brief [ @b MUIO_Label, @b MUIO_Label_FreeVert ] For use with double high frames (e.g. string gadgets). Left justify. [ like MUI
        /// macro @b FreeLLabel2() ]
        static Object *FreeLLabel2(const std::string &label);
        /// @brief [ @b MUIO_Label, @b MUIO_Label_FreeVert ] For use with objects without a frame. Centered. [ like MUI macro @b CLabel() ]
        static Object *FreeCLabel(const std::string &label);
        /// @brief [ @b MUIO_Label, @b MUIO_Label_FreeVert ] For use with standard frames (e.g. checkmarks). Centered. [ like MUI macro @b
        /// CLabel1() ]
        static Object *FreeCLabel1(const std::string &label);
        /// @brief [ @b MUIO_Label, @b MUIO_Label_FreeVert ] For use with double high frames (e.g. string gadgets). Centered. [ like MUI
        /// macro @b CLabel2() ]
        static Object *FreeCLabel2(const std::string &label);

        /// @brief [ @b HVSpace --> MUI_NewObject(MUIC_Rectangle, TAG_DONE) ]
        static Object *HVSpace();
        /// @brief [ @b MUIO_HSpace --> MUI_MakeObject(MUIO_HSpace,(space)) ]
        static Object *HSpace(const unsigned long space);
        /// @brief [ @b MUIO_VSpace --> MUI_MakeObject(MUIO_VSpace,(space)) ]
        static Object *VSpace(const unsigned long space);
        /// @brief [ @b MUIO_HBar ]
        static Object *HBar(const unsigned long space);
        /// @brief [ @b MUIO_VBar ]
        static Object *VBar(const unsigned long space);

        /// @brief [ @b HCenter --> (HGroup, GroupSpacing(0), Child, HSpace(0), Child, (obj), Child, HSpace(0), End) ]
        static Object *HCenter(const Object *object);
        /// @brief [ @b VCenter --> (VGroup, GroupSpacing(0), Child, VSpace(0), Child, (obj), Child, VSpace(0), End) ]
        static Object *VCenter(const Object *object);
    };
}
