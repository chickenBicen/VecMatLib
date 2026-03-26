cmake_minimum_required(VERSION 4.1)
project(VecMatLib)

set(CMAKE_CXX_STANDARD 20)

add_library(VecMatLib
        src/vec2.cpp
        src/utils.cpp
        src/vec3.cpp
        src/Mat2.cpp
        src/Transform2.cpp
)

target_include_directories(VecMatLib PUBLIC include)

add_executable(tests
        tests/main.cpp
        tests/vec2Test.cpp
        tests/vec3Test.cpp
        tests/Mat2Tests.cpp
)

target_link_libraries(tests VecMatLib)
