cmake_minimum_required(VERSION 3.10)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(TP_3_STL)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
set(CMAKE_CXX_STANDARD 11)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(TP_3_STL
               main.cpp
               eleve.h
               eleve.cpp
           )
# target_link_libraries(TP_3_STL Imagine::Graphics)
