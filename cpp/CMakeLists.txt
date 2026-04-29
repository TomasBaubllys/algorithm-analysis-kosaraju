cmake_minimum_required(VERSION 3.24)
project(kosaraju)

set(SOURCE_FILES
    src/main.cpp
    src/kosaraju.cpp
    src/graph.cpp
    src/graph_generator.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_compile_options(${PROJECT_NAME} PRIVATE -g)

