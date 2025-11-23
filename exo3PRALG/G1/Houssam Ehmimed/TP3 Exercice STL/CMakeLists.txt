cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Exo_stl)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(Exo_stl main.cpp
    Eleve.cpp
    Eleve.h)
# target_link_libraries(Exo_stl Imagine::Graphics)
