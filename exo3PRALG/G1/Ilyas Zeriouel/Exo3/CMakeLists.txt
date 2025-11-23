cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Exo3)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
set(CMAKE_CXX_STANDARD 11)



add_executable(Exo3 main.cpp
    eleves.h
    eleves.cpp)

