cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64)
project(TP3)
list(APPEND CMAKE_SYSTEM_FRAMEWORK_PATH /Library/Frameworks)
# find_package(Imagine REQUIRED)

add_executable(TP3 main.cpp
    Eleve.h Eleve.cpp
    Comparateur.h)
# target_link_libraries(TP3 Imagine::Graphics)
