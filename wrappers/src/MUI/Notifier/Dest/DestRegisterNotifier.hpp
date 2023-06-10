//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestGroupNotifier.hpp"
#include "MUI/Register.hpp"

namespace MUI
{
    class DestRegisterNotifier : public DestGroupNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestRegisterNotifier() = delete;
        DestRegisterNotifier(const NotifierObject &notifierObject, const Register &registerObject);
    };
}
