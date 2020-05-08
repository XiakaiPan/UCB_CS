cmake_minimum_required(VERSION 3.16)
project(hw2_starter_hw1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(hw2_starter_hw1
        bear_git.c
        beargit.c
        beargit.h
        cunittests.c
        cunittests.h
        main.c
        util.c
        util.h)
