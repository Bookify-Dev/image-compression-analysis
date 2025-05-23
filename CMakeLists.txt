cmake_minimum_required(VERSION 3.16)
project(ImageCompressor)

set(CMAKE_CXX_STANDARD 17)

# Include wrapper directory
include_directories(${PROJECT_SOURCE_DIR}/wrapper)

# Link Homebrew includes and libs (macOS ARM/M1 default paths)
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

# Add sources
set(SOURCES
        main.cpp
        wrapper/WebPCompressor.cpp
        # wrapper/jpeg_compressor.cpp (später hinzufügen)
)

add_executable(ImageCompressor ${SOURCES})

# Link webp (später weitere hinzufügen wie jpeg)
target_link_libraries(ImageCompressor webp)
