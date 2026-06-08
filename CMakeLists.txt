cmake_minimum_required(VERSION 4.1)
project(strutil C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(strutil
        include/strutil.h
        src/main.c
        src/strutil.c
        src/test_strutil.c
        include/test_strutil.h)
