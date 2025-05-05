cmake_minimum_required(VERSION 3.29)
project(cunit C)

set(CMAKE_C_STANDARD 99)

add_executable(cunit main.c
        c_unit.h
        c_unit.c
)
