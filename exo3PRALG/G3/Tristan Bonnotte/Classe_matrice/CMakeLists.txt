cmake_minimum_required(VERSION 3.10)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Classe_matrice)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(Classe_matrice main.cpp
    eleve.h
    eleve.cpp

)
# target_link_libraries(Classe_matrice Imagine::Graphics)
