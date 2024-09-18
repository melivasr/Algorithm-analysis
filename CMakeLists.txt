cmake_minimum_required(VERSION 3.28)
project(Algorithm_analysis)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithm_analysis main.cpp
        source/SortAlgorithms.cpp
        headers/SortAlgorithms.h
        source/LinkedList.cpp
        headers/LinkedList.h
        source/Benchmark.cpp
        headers/Benchmark.h)
