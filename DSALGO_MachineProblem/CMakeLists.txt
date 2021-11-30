cmake_minimum_required(VERSION 3.20)
project(machprob)

set(CMAKE_CXX_STANDARD 14)

add_executable(machprob main.cpp implementation.cpp data.h string.cpp string.h)
