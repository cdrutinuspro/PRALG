cmake_minimum_required(VERSION 3.16)

project(STL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(STL main.cpp
    eleve.h eleve.cpp)

include(GNUInstallDirs)
install(TARGETS STL
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
