cmake_minimum_required(VERSION 3.14)
project(exo_stl LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(exo_stl
    eleves.cpp
    main.cpp
)

# target_include_directories(exo_stl PRIVATE .)
# target_compile_options(exo_stl PRIVATE -Wall -Wextra -O2)
