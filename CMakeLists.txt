
# Set cmake minimum version required
cmake_minimum_required(VERSION 3.2)

# Name Project
project(design_patterns)

# Project version number
set(DESIGN_PATTERNS_VERSION_MAJOR 1)
set(DESIGN_PATTERNS_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
"${PROJECT_SOURCE_DIR}/design_patterns_version.h.in"
"${PROJECT_SOURCE_DIR}/include/design_patterns_version.h"
)

# Set Variables
set(SOURCE_FILES src/design_patterns.cpp src/observer.cpp)

# Add SOURCE_FILES to executable/library
add_executable(design_patterns ${SOURCE_FILES})

# Add include directories
target_include_directories(design_patterns PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Set some properties (standard)
set_target_properties(design_patterns PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    )
# Export compile command json file for use with source trail and YCM
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Add find GMock.cmake module to cmake modules
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/modules)

# Find Gtest and GMock packages
find_package(GTest)
find_package(GMock)
if(NOT GTEST_FOUND)
    message(WARNING "GTest couldn't be found")
else()
    message("GTest Found")
endif()
if(NOT GMOCK_FOUND)
    message(WARNING "GMock couldn't be found")
else()
    message("GMock Found")
endif()

if(GTEST_FOUND AND GMOCK_FOUND)
# Set testing project sources 
set(TESTING_SOURCES ${PROJECT_SOURCE_DIR}/tests/design_patterns_test.cpp)

# Make Testing executable
add_executable(design_patterns_testing ${TESTING_SOURCES})

# Include Project's Include dir plus Gtest and GMock include dirs
target_include_directories(design_patterns_testing PUBLIC ${PROJECT_SOURCE_DIR}/include ${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

# Link with Gtest and GMock libs
target_link_libraries(design_patterns_testing GTest::GTest GTest::Main ${GMOCK_BOTH_LIBRARIES})

set_target_properties(design_patterns_testing PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    )
# Enabling testing
enable_testing()
add_test(design_patterns_test testing_project_name)
endif()

