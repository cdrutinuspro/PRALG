cmake_minimum_required(VERSION 3.16)
project(exercice_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exercice_3 main.cpp eleve.cpp eleve.h)

# Force l'exécutable en mode console sous Windows
if (WIN32)
    set_target_properties(exercice_3 PROPERTIES WIN32_EXECUTABLE OFF)
endif()
