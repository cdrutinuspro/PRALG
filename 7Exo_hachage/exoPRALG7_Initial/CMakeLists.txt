cmake_minimum_required(VERSION 3.12)

project(isotoponyms)

add_executable(example example.cpp town.cpp town.h point2d.cpp point2d.h)
add_executable(isotopo isotopo.cpp town.cpp town.h point2d.cpp point2d.h)

add_definitions(-DsrcPath="${CMAKE_CURRENT_SOURCE_DIR}")
