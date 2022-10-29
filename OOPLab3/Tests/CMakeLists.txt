cmake_minimum_required(VERSION 3.20)
project(Tests_l3)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(Tests_l3 tests.cpp)

include(FindPkgConfig)
find_package(Lib3 REQUIRED)
include_directories(${CLASS_INCLUDE_DIR})
target_link_libraries(Tests_l3 ${CLASS_LIBRARY})
target_link_libraries(Tests_l3 gtest gtest_main )
