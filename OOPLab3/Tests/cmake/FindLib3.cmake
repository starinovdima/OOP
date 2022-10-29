set(FIND_CLASS1_PATHS /home/dmitry/CLionProjects/Laba3/Library)
set(FIND_CLASS2_PATHS /home/dmitry/CLionProjects/Laba3/Library/cmake-build-debug)

find_path(CLASS_INCLUDE_DIR library.h
        PATHS ${FIND_CLASS1_PATHS})

find_library(CLASS_LIBRARY
        NAMES Library
        PATHS ${FIND_CLASS2_PATHS})