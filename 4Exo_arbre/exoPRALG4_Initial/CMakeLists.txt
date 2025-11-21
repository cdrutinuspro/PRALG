cmake_minimum_required(VERSION 3.12)
project(ZipImage)
find_package(Imagine REQUIRED COMPONENTS Graphics)

add_subdirectory(quadtree)

add_executable(zipimage zipimage.cpp quadtree/quadtree.h)
target_link_libraries(zipimage Imagine::Graphics)
