set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add raylib
include(FetchContent)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.5 # Use a specific version tag for stability
)
FetchContent_MakeAvailable(raylib)

add_library(visual_lib
    window.cpp
    window.h    
)

target_link_libraries(visual_lib PRIVATE curves_lib raylib)

target_include_directories(visual_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        curves_lib
        raylib        
)

