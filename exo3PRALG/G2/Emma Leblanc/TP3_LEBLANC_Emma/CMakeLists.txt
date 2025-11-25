cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Tp7_Initial)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?
set(CMAKE_CXX_STANDARD 11)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(Tron
               main.cpp

               eleve.h
               eleve.cpp)
# target_link_libraries(Tron Imagine::Graphics)
