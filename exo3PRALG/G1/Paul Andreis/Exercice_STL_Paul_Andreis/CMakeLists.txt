cmake_minimum_required(VERSION 3.5)

project(Exercice_STL_Paul_Andreis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Imagine REQUIRED COMPONENTS Common)

add_executable(Exercice_STL_Paul_Andreis main.cpp
    eleve.cpp
    eleve.h)

# target_link_libraries(Exercice_STL_Paul_Andreis Imagine::Common)

include(GNUInstallDirs)
install(TARGETS Exercice_STL_Paul_Andreis
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
