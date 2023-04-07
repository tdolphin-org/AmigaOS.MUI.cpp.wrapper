//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include <string>

#include <proto/muimaster.h>

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
#undef HSpace
#undef VSpace

namespace MUI
{
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

        /// @brief [ @b MUIO_HSpace ]
        static Object *HSpace(const unsigned long space);
        /// @brief [ @b MUIO_VSpace ]
        static Object *VSpace(const unsigned long space);
        /// @brief [ @b MUIO_HBar ]
        static Object *HBar();
        /// @brief [ @b MUIO_VBar ]
        static Object *VBar();
    };
}
