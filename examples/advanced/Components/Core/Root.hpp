//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "MUI/Notify.hpp"

namespace Components
{
    class Root
    {
      public:
        Object *muiObject() const
        {
            return muiNotify().muiObject();
        }

        operator const MUI::Notify &() const
        {
            return muiNotify();
        }

        void MuiAlert(const std::string &message) const;
        void MuiWarning(const std::string &message) const;
        void MuiInfo(const std::string &message, const std::string &gadgets) const;
        long MuiRequest(const std::string &title, const std::string &message, const std::string &gadgets) const;

      protected:
        virtual const MUI::Notify &muiNotify() const = 0;
    };
}
