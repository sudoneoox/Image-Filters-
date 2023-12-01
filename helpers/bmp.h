#ifndef BMP_H
#define BMP_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>

#pragma pack(push, 1)
struct BMPHeader {
    uint16_t file_type{0x4D42};          
    uint32_t file_size{0};               
    uint16_t reserved1{0};               
    uint16_t reserved2{0};               
    uint32_t offset_data{0};             

    uint32_t size{0};                   
    int32_t width{0};                   
    int32_t height{0};                  
    uint16_t planes{1};                 
    uint16_t bit_count{0};              
    uint32_t compression{0};            
    uint32_t size_image{0};             
    int32_t x_pixels_per_meter{0};      
    int32_t y_pixels_per_meter{0};      
    uint32_t colors_used{0};            
    uint32_t colors_important{0};       
    friend std::ostream& operator <<(std::ostream& COUT, BMPHeader& RHS){
        std::cout << "FILE TYPE: " << RHS.file_type << std::endl;
        std::cout << "FILE SIZE: " << RHS.file_size << std::endl;
        std::cout << "RESERVED 1: " << RHS.reserved1 << std::endl;
        std::cout << "RESERVED 2: " << RHS.reserved2 << std::endl;
        std::cout << "OFFSET DATA: " << RHS.offset_data << std::endl;
        std::cout << "SIZE: " << RHS.size << std::endl;
        std::cout << "WIDTH: " << RHS.width << std::endl;
        std::cout << "HEIGHT: " << RHS.height << std::endl;
        std::cout << "PLANES: " << RHS.planes << std::endl;
        std::cout << "BIT COUNT: " << RHS.bit_count << std::endl;  
        std::cout << "COMPRESSION: " << RHS.compression << std::endl;
        std::cout << "SIZE IMAGE: " << RHS.size_image << std::endl;
        std::cout << "X PIXELS PER METER: " << RHS.x_pixels_per_meter << std::endl;
        std::cout << "Y PIXELS PER METER: " << RHS.y_pixels_per_meter << std::endl;
        std::cout << "COLORS USED: " << RHS.colors_used << std::endl;
        std::cout << "COLORS IMPORTANT: " << RHS.colors_important << std::endl;
        return COUT;
    }
};
#pragma pack(pop)

struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};
#endif