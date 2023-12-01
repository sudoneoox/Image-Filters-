#include "../../helpers/filters/filters.h"

void applyGreenTint(std::vector<Pixel>& pixels) {
    for (auto& pixel : pixels) {
        pixel.green = std::min(255, pixel.green + 50); // Increase green component
    }
}