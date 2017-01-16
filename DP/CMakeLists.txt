cmake_minimum_required(VERSION 3.5)
project(palidrome_partition)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES palidrome_partition.cpp word_break.cpp longgest_common_subsequence.cpp longgest_common_substring.cpp min_distance.cpp distinct_subsequence.cpp)
add_executable(palidrome_partition ${SOURCE_FILES})