cmake_minimum_required(VERSION 3.10)
set(CMAKE_OSX_ARCHITECTURES x86_64) 
project(TP01)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) 

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(Eleve main.cpp eleve.cpp)

