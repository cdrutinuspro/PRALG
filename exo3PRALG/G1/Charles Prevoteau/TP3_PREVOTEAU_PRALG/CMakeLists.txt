cmake_minimum_required(VERSION 3.5)
project(TP3_PREVOTEAU_PRALG)
# find_package(Imagine REQUIRED COMPONENTS Graphics)

include_directories(include)

add_executable(TP3_PREVOTEAU_PRALG src/main.cpp src/eleve.cpp)

# ImagineUseModules(TP3_PREVOTEAU_PRALG Graphics)