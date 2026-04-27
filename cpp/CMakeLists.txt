cmake_minimum_required(VERSION 3.24)
project(kosajaru)

set(SOURCE_FILES
    src/main.cpp
    src/kosajaru.cpp
    src/graph.cpp
    src/graph_generator.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
