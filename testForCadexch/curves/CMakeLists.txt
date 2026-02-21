add_library(curves_lib
    circle.cpp
    ellipse.cpp
    helix.cpp
)

target_include_directories(curves_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Warnings for library as well
if (MSVC)
    target_compile_options(curves_lib PRIVATE /W4)
else()
    target_compile_options(curves_lib PRIVATE -Wall -Wextra -Wpedantic)
endif()