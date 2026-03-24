cmake_minimum_required(VERSION 4.1)
project(VecMatLib)

set(CMAKE_CXX_STANDARD 20)

add_library(VecMatLib
        src/vec2.cpp
        src/utils.cpp
        src/vec3.cpp
)

target_include_directories(VecMatLib PUBLIC include)

add_executable(tests
        tests/main.cpp
        tests/vec2Test.cpp
)

target_link_libraries(tests VecMatLib)
