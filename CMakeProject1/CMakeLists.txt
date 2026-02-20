cmake_minimum_required(VERSION 3.14)

project(CurvesProject VERSION 1.0 LANGUAGES CXX)

# Require 20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add curves library
add_subdirectory(curves)

# Create executable
add_executable(curves_app main.cpp)

# Link library
target_link_libraries(curves_app PRIVATE curves_lib)

add_subdirectory(tests)

# Enable warnings (portable)
if (MSVC)
    target_compile_options(curves_app PRIVATE /W4)
else()
    target_compile_options(curves_app PRIVATE -Wall -Wextra -Wpedantic)
endif()