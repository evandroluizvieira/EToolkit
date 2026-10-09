/**
 * @file EColorTest.cpp
 * @brief Validates the public EColor API from a consumer perspective.
 */

#include <EColor>

#include <iostream>

int main(){
    EToolkit::Color1<int> grayscale(128);
    EToolkit::Color2<int> grayscaleWithAlpha(128, 255);
    EToolkit::Color3<int> rgb(10, 20, 30);
    EToolkit::Color4<int> rgba(10, 20, 30, 255);
    const EToolkit::Color3uc white = EToolkit::Color3uc::White();
    const EToolkit::Color3f red = EToolkit::Color3f::Red();

    if(grayscale.gray != 128 || grayscaleWithAlpha.alpha != 255 ||
       rgb.red != 10 || rgb.green != 20 || rgb.blue != 30 ||
       rgba.alpha != 255){
        std::cerr << "EColor API validation failed for color classes." << std::endl;
        return 1;
    }

    if(white.red != 255 || white.green != 255 || white.blue != 255 ||
       red.red != 1.0f || red.green != 0.0f || red.blue != 0.0f){
        std::cerr << "EColor API validation failed for color presets." << std::endl;
        return 1;
    }

    std::cout << "EColor API validation passed." << std::endl;
    return 0;
}
