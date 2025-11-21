cmake_minimum_required(VERSION 3.12)
project(ZipImageFinal)
find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(zipimageFinal zipimage.cpp quadtree/quadtree.h)
target_link_libraries(zipimageFinal Imagine::Graphics)
