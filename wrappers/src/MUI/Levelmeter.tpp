//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_LEVELMETER_TPP_INCLUDE
#error "Levelmeter.tpp should only be included by Levelmeter.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &LevelmeterBuilderTemplate<T, U>::tagLabel(const char *label)
    {
        this->PushTag(MUIA_Levelmeter_Label, label);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &LevelmeterBuilderTemplate<T, U>::tagLabel(const std::string &label)
    {
        this->PushTag(MUIA_Levelmeter_Label, label);
        return (T &)*this;
    }
}
