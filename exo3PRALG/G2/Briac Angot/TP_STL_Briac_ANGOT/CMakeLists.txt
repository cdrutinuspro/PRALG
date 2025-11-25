cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64)
project(TP_STL_Eleve_Briac_ANGOT)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks)
set(CMAKE_CXX_STANDREQ 11)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(TP_STL
               main.cpp
               eleve.h
               eleve.cpp)

# target_link_libraries(TP_STL Imagine::Graphics)
