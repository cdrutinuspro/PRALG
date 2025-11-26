cmake_minimum_required(VERSION 3.16)

project(Pierre_Gineste_TP3 LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# add_library(Pierre_Gineste_TP3 SHARED
#   Pierre_Gineste_TP3_global.h
#   pierre_gineste_tp3.cpp
#   pierre_gineste_tp3.h
# )

add_executable(Pierre_Gineste_TP3 main.cpp
eleve.h eleve.cpp Comparators.h Comparators.cpp)
# target_link_libraries(Pierre_Gineste_TP3 PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# target_compile_definitions(Pierre_Gineste_TP3 PRIVATE PIERRE_GINESTE_TP3_LIBRARY)
