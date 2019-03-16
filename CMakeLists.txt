cmake_minimum_required(VERSION 3.13)
project(graph_implementation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(graph_implementation
    graph.cpp
    graph.h
    main.cpp node.cpp node.h link.cpp link.h)
