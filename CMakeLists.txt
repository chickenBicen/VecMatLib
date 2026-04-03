cmake_minimum_required(VERSION 4.1)
project(VecMatLib)

set(CMAKE_CXX_STANDARD 20)


add_library(VecMatLib
        src/vec2.cpp
        src/utils.cpp
        src/vec3.cpp
        src/Mat2.cpp
        src/Transform2.cpp
        src/Mat3.cpp
        src/Transform3.cpp
        src/Quaternion.cpp
)

target_include_directories(VecMatLib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS VecMatLib
        EXPORT VecMatLibTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY include/
        DESTINATION include
)

install(EXPORT VecMatLibTargets
        FILE VecMatLibTargets.cmake
        NAMESPACE VecMatLib::
        DESTINATION lib/cmake/VecMatLib
)

add_executable(tests
        tests/main.cpp
        tests/vec2Test.cpp
        tests/vec3Test.cpp
        tests/Mat2Tests.cpp
        tests/Transform2Tests.cpp
        tests/Mat3Tests.cpp
        tests/Transform3Tests.cpp

)

target_link_libraries(tests VecMatLib)


