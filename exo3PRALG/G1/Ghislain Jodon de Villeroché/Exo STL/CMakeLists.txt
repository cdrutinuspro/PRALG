cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(ExoSTL)
# list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(ExoSTL Main.cpp
    eleve.h
    eleve.cpp)
# target_link_libraries(ExoSTL Imagine::Graphics)
