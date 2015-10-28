cmake_minimum_required(VERSION 3.3)
project(Relaxsl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES src/main.cpp src/sources/CommandLineOptionsParser.cpp src/headers/CommandLineOptionsParser.h)
add_executable(Relaxsl ${SOURCE_FILES})