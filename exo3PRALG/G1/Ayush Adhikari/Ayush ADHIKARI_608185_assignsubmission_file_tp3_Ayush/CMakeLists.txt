cmake_minimum_required(VERSION 3.16)

project(tp3_pralg VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tp3_pralg main.cpp
            eleve.h eleve.cpp)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#     qt_add_executable(tp3_pralg MANUAL_FINALIZATION main.cpp)
# else()
#     if(ANDROID)
#         add_library(tp3_pralg SHARED main.cpp)
#     else()
#         add_executable(tp3_pralg main.cpp
#             eleve.h eleve.cpp)
#     endif()
# endif()

# target_link_libraries(tp3_pralg PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# include(GNUInstallDirs)
# install(TARGETS tp3_pralg
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# set_target_properties(tp3_pralg PROPERTIES MACOSX_BUNDLE FALSE)

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(tp3_pralg)
# endif()
