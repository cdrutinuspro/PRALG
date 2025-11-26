cmake_minimum_required(VERSION 3.5)

project(TP3_PRALG_CamilleVienot LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TP3_PRALG_CamilleVienot main.cpp
    Eleve.h
    Eleve.cpp
    README.h)

# include(GNUInstallDirs)
# install(TARGETS TP3_PRALG_CamilleVienot
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )
