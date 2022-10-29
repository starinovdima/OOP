set(FIND_Lib1_PATHS /home/dmitry/CLionProjects/Laba3/Library/cmake-build-debug)
set(FIND_Lib2_PATHS /home/dmitry/CLionProjects/Laba3/Library)

find_path(CLASS_INCLUDE_DIR1 library.h
        PATHS ${FIND_Lib2_PATHS})

find_library(CLASS_LIBRARY1
        NAMES Library
        PATHS ${FIND_Lib1_PATHS})