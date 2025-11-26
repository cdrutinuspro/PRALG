cmake_minimum_required(VERSION 3.10)
project(MonProjet)

# Choix de la version de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajout de l'exécutable à construire
add_executable(programme main.cpp eleve.cpp)
