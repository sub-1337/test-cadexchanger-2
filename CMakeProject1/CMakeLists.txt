# Require 20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create executable
add_executable(curves_app main.cpp)

# Enable warnings (portable)
if (MSVC)
    target_compile_options(curves_app PRIVATE /W4)
else()
    target_compile_options(curves_app PRIVATE -Wall -Wextra -Wpedantic)
endif()

