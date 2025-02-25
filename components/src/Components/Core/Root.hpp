//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "MUI/Notify.hpp"

namespace Components
{
    class AbstractRoot
    {
      public:
        virtual Object *muiObject() const = 0;

        // requesters
        void MuiAlert(const std::string &message) const;
        void MuiWarning(const std::string &message) const;
        void MuiInfo(const std::string &message, const std::string &gadgets) const;
        long MuiRequest(const std::string &title, const std::string &message, const std::string &gadgets) const;
    };

    /// @brief Root class for all components (including Application, Windows).
    template <typename T> class NotifyRoot : public AbstractRoot
    {
      public:
        Object *muiObject() const
        {
            return muiRoot().muiObject();
        }

        operator T &() const
        {
            return (T &)muiRoot();
        }

        virtual T &muiRoot() const = 0;
    };

    /// @brief Root class for all components builded on at least MUI::Area (base class with MUIA_Disabled attribute)
    template <typename T> class Root : public NotifyRoot<T>
    {
      public:
        void Enable()
        {
            this->muiRoot().Enable();
        }

        void Disable()
        {
            this->muiRoot().Disable();
        }
    };
}
