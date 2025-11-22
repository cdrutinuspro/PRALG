cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Exo3)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
set(CMAKE_CXX_STANDARD 11)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(Exo3
               main.cpp
               Eleves.cpp Eleves.h               
               )
# target_link_libraries(Exo3 Imagine::Graphics)
