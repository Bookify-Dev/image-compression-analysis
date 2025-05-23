// WebPCompressor.h
#ifndef WEBP_COMPRESSOR_H
#define WEBP_COMPRESSOR_H

#include <string>

class WebPCompressor {
public:
    WebPCompressor(float quality = 75.0f);
    bool compressRGB(const uint8_t* rgbData, int width, int height, const std::string& outputPath);

private:
    float quality_; // Compression quality (0-100)
};

#endif
