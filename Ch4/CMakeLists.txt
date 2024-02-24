cmake_minimum_required(VERSION 3.24)
project(CH4 C)

set(CMAKE_C_STANDARD 11)

add_executable(CH4 main.c quicksort.c quicksort.h)
