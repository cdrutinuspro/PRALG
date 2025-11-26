cmake_minimum_required(VERSION 3.5)
project(pralg_2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt automatique
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

# # Chercher Qt Widgets
# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Créer l'exécutable
add_executable(pralg_2
    main.cpp
    Eleve.cpp
    Eleve.h
)

# Lier Qt Widgets
# target_link_libraries(pralg_2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
