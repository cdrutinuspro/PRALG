cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(TP3)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(TP3 main.cpp
    eleves.h eleves.cpp)
# target_link_libraries(TP3 Imagine::Graphics)
