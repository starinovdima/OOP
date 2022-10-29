cmake_minimum_required(VERSION 3.20)
project(Library)

set(CMAKE_CXX_STANDARD 17)

set(library_files library.cpp)

add_library(Lib STATIC ${library_files})
