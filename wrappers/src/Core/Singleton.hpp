//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

namespace td
{
    template <typename T> class Singleton
    {
        Singleton() {};
        Singleton(Singleton const &) = delete;
        void operator=(Singleton const &) = delete;

      public:
        static T &instance()
        {
            static T inst;
            return inst;
        };
    };
}
