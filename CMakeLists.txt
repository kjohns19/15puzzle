cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(puzzle)

include_directories(src)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Werror")

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(puzzle ${SRC_FILES})

target_link_libraries(puzzle kj sfml-system sfml-window sfml-graphics)
