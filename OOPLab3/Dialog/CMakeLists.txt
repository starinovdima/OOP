cmake_minimum_required(VERSION 3.20)
project(Dialog)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(Dialog main.cpp dialog.cpp)


include(FindPkgConfig)
find_package(Class3 REQUIRED)
include_directories(${CLASS_INCLUDE_DIR1})
target_link_libraries(Dialog ${CLASS_LIBRARY1})
