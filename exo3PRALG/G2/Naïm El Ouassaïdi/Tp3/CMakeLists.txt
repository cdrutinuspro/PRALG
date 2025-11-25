cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Elève)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(main main.cpp
    Eleve.cpp
    Eleve.h)
# target_link_libraries(main Imagine::Graphics)
