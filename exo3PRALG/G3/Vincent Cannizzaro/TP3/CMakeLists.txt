cmake_minimum_required(VERSION 3.110)
set(CMAKE_OSX_ARCHITECTURES x86_64) #Apple Silicon
project(Tp3)
list(APPEND CMAKE_FRAMEWORK_PATH /Library/Frameworks) #Mac, why not auto?

# find_package(Imagine REQUIRED COMPONENTS Graphics)

add_executable(Eleve
    main.cpp
    Eleve.h
    Eleve.cpp

)
# target_link_libraries(Eleve Imagine::Graphics)
