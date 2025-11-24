cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(T3_2A_C++)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
set(CMAKE_CXX_STANDARD 11)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(TP1
               main.cpp
               Eleve.h
               Eleve.cpp
)
           
# target_link_libraries(TP1 Imagine::Graphics)
