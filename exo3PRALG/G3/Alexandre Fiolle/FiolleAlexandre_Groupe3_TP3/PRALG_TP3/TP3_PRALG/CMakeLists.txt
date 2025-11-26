cmake_minimum_required(VERSION 3.5)

project(TP3_PRALG LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(TP3_PRALG main.cpp
    Eleve.h
    Eleve.cpp)

# target_link_libraries(TP3_PRALG Imagine::Graphics)

# include(GNUInstallDirs)
# install(TARGETS TP3_PRALG
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )
