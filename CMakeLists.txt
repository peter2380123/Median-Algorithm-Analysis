cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

project(median VERSION 1.0
    LANGUAGES C CXX)

add_library(timer STATIC timer.h timer.cpp)
add_library(mtrandom STATIC mt_random.h mt_random.cpp)

add_executable(median
    avg.c
    avg.h
    bfmedian.h
    bfmedian.c
    main.c
    qmedian.c
    qmedian.h
    random_array.c
    random_array.h)

target_link_libraries(median timer mtrandom)
