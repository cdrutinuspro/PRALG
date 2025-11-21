cmake_minimum_required(VERSION 3.12)

project (villesFinal)

add_executable (test_villesFinal example.cpp town.cpp point2d.cpp)

add_executable (isotopoFinalFinal isotopo.cpp town.cpp point2d.cpp)

add_definitions(-DsrcPath="${CMAKE_CURRENT_SOURCE_DIR}")
