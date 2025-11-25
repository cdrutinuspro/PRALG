cmake_minimum_required(VERSION 3.5)

project(exo_stl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exo_stl main.cpp
    Eleve.h
    Eleve.cpp)

include(GNUInstallDirs)
install(TARGETS exo_stl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
