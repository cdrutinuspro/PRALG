cmake_minimum_required(VERSION 3.16)
project(mon_projet_TP1 VERSION 1.0 LANGUAGES CXX)

# Utiliser C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Créer l’exécutable à partir de plusieurs fichiers .cpp
add_executable(mon_projet_TP3
    Eleve.cpp
    main.cpp
)