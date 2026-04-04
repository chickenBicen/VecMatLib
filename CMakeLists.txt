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
        src/Plane.cpp
)

target_include_directories(VecMatLib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
include(CMakePackageConfigHelpers)

# Generate a version file (optional, helps for versioned packages)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/VecMatLibConfigVersion.cmake"
        VERSION 1.0.0
        COMPATIBILITY AnyNewerVersion
)

# Generate a Config file that points to your exported targets
configure_package_config_file(
        "${CMAKE_CURRENT_LIST_DIR}/cmake/VecMatLibConfig.cmake.in"  # template
        "${CMAKE_CURRENT_BINARY_DIR}/VecMatLibConfig.cmake"
        INSTALL_DESTINATION lib/cmake/VecMatLib
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/VecMatLibConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/VecMatLibConfigVersion.cmake"
        DESTINATION lib/cmake/VecMatLib
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
        tests/UtilitiesTests.cpp

)

target_link_libraries(tests VecMatLib)


