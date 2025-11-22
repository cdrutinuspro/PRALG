cmake_minimum_required(VERSION 3.5)

project(stl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stl main.cpp
    stl.cpp
    stl.h)

include(GNUInstallDirs)
install(TARGETS stl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
