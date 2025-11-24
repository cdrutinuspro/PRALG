cmake_minimum_required(VERSION 3.14)

project(Pralg03_STL LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Pralg03_STL
  main.cpp
  Eleve.h
  Eleve.cpp
)