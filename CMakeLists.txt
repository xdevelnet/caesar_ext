cmake_minimum_required(VERSION 3.2)
project(caesar_ext C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES
    main.c)

add_executable(caesar_ext ${SOURCE_FILES})
