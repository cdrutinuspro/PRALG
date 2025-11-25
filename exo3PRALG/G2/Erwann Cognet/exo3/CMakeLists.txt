cmake_minimum_required(VERSION 3.5)

project(exo3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(exo3 main.cpp
    Eleve.h
    Eleve.cpp)

include(GNUInstallDirs)
install(TARGETS exo3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
