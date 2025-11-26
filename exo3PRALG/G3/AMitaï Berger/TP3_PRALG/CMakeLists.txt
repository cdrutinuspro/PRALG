cmake_minimum_required(VERSION 3.14)

project(TP3_PRALG LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(TP3_PRALG
  main.cpp
  Eleve.cpp
  Eleve.h
)
# target_link_libraries(TP3_PRALG Qt${QT_VERSION_MAJOR}::Core)

# include(GNUInstallDirs)
# install(TARGETS TP3_PRALG
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )
