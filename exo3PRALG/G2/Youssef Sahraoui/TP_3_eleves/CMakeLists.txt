# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(TP_3_eleves)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Optional: Add debug symbols by default
# set(CMAKE_BUILD_TYPE Debug)

# Add the executable and the source files
add_executable(TP_3_eleves
    eleve.cpp
    eleve.h
    main.cpp
)