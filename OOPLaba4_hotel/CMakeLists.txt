cmake_minimum_required(VERSION 3.20)
project(Laba4_hotel)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(Library)
add_subdirectory(Tests/googletest)

include_directories(Tests/${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(Library)
include_directories(Instruments)
include_directories(Vector)

add_executable(Laba4_hotel main.cpp Instruments/instruments.cpp)

add_executable(Laba4_tests Tests/Tests.cpp)

target_link_libraries(Laba4_hotel Hotel_lib)

target_link_libraries(Laba4_tests gtest gtest_main )

target_link_libraries(Laba4_tests Hotel_lib)