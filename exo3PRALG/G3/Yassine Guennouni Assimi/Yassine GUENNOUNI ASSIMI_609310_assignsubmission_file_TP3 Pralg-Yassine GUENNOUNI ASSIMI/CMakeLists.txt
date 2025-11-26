cmake_minimum_required(VERSION 3.10)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(exo2)
list(APPEND CMAKE_SYSTEM_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
# find_package(Imagine REQUIRED)

add_executable(exo2 main.cpp
    Eleve.h
    Eleve.cpp)
# target_link_libraries(exo2 Imagine::Graphics)
