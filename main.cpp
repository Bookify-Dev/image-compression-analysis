//
// Created by Alexander Sachs on 22.05.25.
//

#include "main.h"

#include "WebPCompressor.h"
#include <vector>
#include <iostream>

int main() {
    int width = 256, height = 256;
    std::vector<uint8_t> rgb(width * height * 3, 100); // Dummy-Grau-Bild

    WebPCompressor compressor(80.0f);
    std::string outputPath = "compressed/webp/test_image.webp";

    if (compressor.compressRGB(rgb.data(), width, height, outputPath)) {
        std::cout << "WebP-Kompression erfolgreich!\n";
    } else {
        std::cerr << "Fehler bei der Kompression.\n";
    }

    return 0;
}
