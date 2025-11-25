cmake_minimum_required(VERSION 3.10)
project(TP3)

set(CMAKE_CXX_STANDARD 17)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(main
    src/main.cpp
    src/Eleve.cpp
    src/Eleve.h
)
# target_link_libraries(main PRIVATE Imagine::Graphics)

target_include_directories(main PRIVATE src)