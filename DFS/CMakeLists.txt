cmake_minimum_required(VERSION 3.5)
project(DFS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES house_robber.cpp)
add_executable(DFS ${SOURCE_FILES})