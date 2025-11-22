cmake_minimum_required(VERSION 3.5)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Exercice_STL)
# list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?

# find_package(Imagine REQUIRED COMPONENTS
# Graphics)
add_executable(Exercice_STL main.cpp eleve.cpp
eleve.h
comparateur.h
affichage.h)
# target_link_libraries(Exercice_STL Imagine::Graphics)
