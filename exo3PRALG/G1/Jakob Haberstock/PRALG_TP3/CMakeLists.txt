cmake_minimum_required(VERSION 3.15)
project(PRALG_TP3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Alle Quell-Dateien in src einbinden
file(GLOB SRC_FILES src/*.cpp)

# Alle Header-Dateien in include einbinden (optional, für IDEs)
file(GLOB HEADER_FILES include/*.h)

# Executable anlegen
add_executable(PRALG_TP3
    ${SRC_FILES}
    ${HEADER_FILES} # optional
)

# Include-Ordner hinzufügen
target_include_directories(PRALG_TP3 PRIVATE include)
