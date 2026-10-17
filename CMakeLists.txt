cmake_minimum_required(VERSION 3.28.3)
project(wave VERSION 0.1 LANGUAGES CXX)

# 1. Enforce C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 2. Default to Debug build on single-config generators (like Linux Makefiles/Ninja)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build (Debug, Release, RelWithDebInfo)." FORCE)
endif()

# 3. Clean Binary Output Directory Structure (bin/Debug, bin/Release, etc.)
# This uses generator expressions so it works seamlessly on both Linux (Make/Ninja) and Windows (Visual Studio)
if(CMAKE_CONFIGURATION_TYPES)
    # Multi-config generators (e.g., Visual Studio)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)
else()
    # Single-config generators (e.g., Linux Makefiles or Ninja)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
endif()

# 4. Define the Executable Target
add_executable(${PROJECT_NAME} src/wave.cpp)

# 5. Strict Compiler Warnings (Catches bugs early on both GCC and MSVC)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()