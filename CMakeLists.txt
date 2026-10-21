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
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/$<CONFIG>)

# Configure spdlog
set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_BENCH OFF CACHE BOOL "" FORCE)

add_subdirectory(external/spdlog)


# 4. Define the Executable Target
add_executable(${PROJECT_NAME} 
    src/wave.cpp
    src/log.cpp
    src/application.cpp
    src/events/event.h
    src/events/application_event.h
    src/events/key_event.h
    src/events/mouse_event.h)

# Tell CMake to use pch.h as the precompiled header for this target
target_precompile_headers(${PROJECT_NAME}
    PRIVATE
        src/pch.h
)
# 5. Strict Compiler Warnings (Catches bugs early on both GCC and MSVC)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Link dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE
    spdlog::spdlog
)