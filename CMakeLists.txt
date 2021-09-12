cmake_minimum_required(VERSION 2.8)
project(CSE310Project1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_CXX_STANDARD 14)

add_executable(encode main.cpp insertion.h merge.h)
add_executable(insertion main.cpp insertion.h)
add_executable(merge main.cpp merge.h)
