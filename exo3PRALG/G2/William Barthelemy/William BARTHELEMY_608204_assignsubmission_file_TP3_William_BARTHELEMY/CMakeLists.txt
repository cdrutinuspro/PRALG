cmake_minimum_required(VERSION 3.20)
project(TP2 VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(TP3 main.cpp student.h student.cpp)
# target_link_libraries(TP3 Imagine::Graphics)
