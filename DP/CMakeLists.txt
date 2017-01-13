cmake_minimum_required(VERSION 3.5)
project(triangle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES triangle.cpp house_robber.cpp unique_path.cpp jump_game.cpp longest_increasing_seq.cpp)
add_executable(triangle ${SOURCE_FILES})