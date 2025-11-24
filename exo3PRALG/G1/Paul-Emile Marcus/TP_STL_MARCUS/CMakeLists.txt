cmake_minimum_required(VERSION 3.5)

project(TP_STL LANGUAGES CXX)

# find_package(Imagine REQUIRED COMPONENTS
#     Graphics)

add_executable(TP_STL main.cpp
    Eleve.h
    CompareNom.h
    CompareNote.h
    Eleve.cpp)


# target_link_libraries(TP_STL Imagine::Graphics)

include(GNUInstallDirs)
# install(TARGETS TP_STL
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )
