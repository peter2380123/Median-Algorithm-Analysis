cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

project(median VERSION 1.0
    LANGUAGES C CXX)

add_library(timer STATIC timer.h timer.cpp)
add_library(mtrandom STATIC mt_random.h mt_random.cpp)

set(files
    avg.c
    avg.h
    bfmedian.h
    bfmedian.c
    main.c
    qmedian.c
    qmedian.h)

set(libs
    timer
    mtrandom
    )

add_executable(mediantime
    ${files}
    )
add_executable(medianops
    ${files}
    )

target_compile_options(medianops
    PRIVATE
    -DBASIC_OPS)

target_link_libraries(mediantime ${libs})
target_link_libraries(medianops ${libs})
