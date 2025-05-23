//
// Created by Alexander Sachs on 22.05.25.
//

#include "WebPCompressor.h"

// webp_compressor.cpp
#include <webp/encode.h>
#include <fstream>
#include <iostream>


WebPCompressor::WebPCompressor(float quality)
    : quality_(quality) {}
    bool WebPCompressor::compressRGB(const uint8_t* rgbData, int width, int height, const std::string& outputPath) {
    uint8_t* outputData = nullptr;
    size_t outputSize = WebPEncodeRGB(rgbData, width, height, width * 3, quality_, &outputData);

    if (outputSize == 0) {
        return false; // Compression failed
    }

    std::filesystem::create_directories(std::filesystem::path(outputPath).parent_path());
    std::ofstream outFile(outputPath, std::ios::binary);

    if (!outFile) {
        std::cout << "TEST";

        WebPFree(outputData);
        return false;
    }

    outFile.write(reinterpret_cast<char*>(outputData), outputSize);
    outFile.close();

    WebPFree(outputData);
    return true;
}
