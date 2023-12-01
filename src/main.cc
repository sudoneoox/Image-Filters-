#include "../helpers/bmp.h"
#include "../helpers/filters/filters.h"

#include <fstream>
#include <iostream>
#include <vector>





int main() {
    BMPHeader header;
    std::ifstream input_file("../TestImages/example.bmp", std::ios::binary);
    std::vector<Pixel> pixels;

    if (input_file) {
        input_file.read(reinterpret_cast<char*>(&header), sizeof(header));
        pixels.resize(header.width * header.height);
        input_file.read(reinterpret_cast<char*>(pixels.data()), pixels.size() * sizeof(Pixel));
        std::cout << header << std::endl;

        std::ofstream output_file("../TestImages/output.bmp", std::ios::binary);
        if (output_file) {
            output_file.write(reinterpret_cast<char*>(&header), sizeof(header));
            output_file.write(reinterpret_cast<char*>(pixels.data()), pixels.size() * sizeof(Pixel));
        } else {
            std::cerr << "Error opening output file" << std::endl;
        }
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }

    return 0;
}
