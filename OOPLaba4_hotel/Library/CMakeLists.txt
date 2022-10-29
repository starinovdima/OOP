cmake_minimum_required(VERSION 3.20)
project(Library)

set(CMAKE_CXX_STANDARD 17)
include_directories(../Instruments)
include_directories(../Vector)

add_library(Hotel_lib SHARED Multi.cpp Floor.h Room.cpp Lux.cpp Single.cpp
        Floor.cpp ../Instruments/instruments.h Room.h Descriptors.h ../Instruments/instruments.cpp Person.cpp Table.cpp Table.h)
