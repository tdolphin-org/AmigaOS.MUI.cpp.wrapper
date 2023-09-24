//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Image.hpp"

namespace MUI
{
    const std::string Image::className = MUIC_Image;

    ImageBuilder::ImageBuilder() { }
    
    Image &Image::setBackground(const ImageOrBackground spec)
    {
        SetValue(MUIA_Image_Spec, (long)spec);
        return *this;
    }
}
