cmake_minimum_required(VERSION 3.20)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Tp3)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
set(CMAKE_CXX_STANDARD 20)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(TP3 main.cpp)

# target_link_libraries(TP3 Imagine::Graphics)
