cmake_minimum_required(VERSION 3.20)
project(Laba3_static)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Tests/googletest)
add_subdirectory(Library)

include_directories(Tests/${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(Library)

set(dialog_laba Dialog/main.cpp Dialog/dialog.cpp Dialog/dialog.h)
set(tests_laba Tests/tests.cpp)

add_executable(Laba3_dialog ${dialog_laba})
add_executable(Laba3_tests ${tests_laba})

target_link_libraries(Laba3_dialog Lib)
target_link_libraries(Laba3_tests gtest gtest_main )
target_link_libraries(Laba3_tests Lib)
