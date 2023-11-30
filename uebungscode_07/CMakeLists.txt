# Konfiguration des Buildsystems CMake
#-------------------------------------------#

# Minimale Version des Buildsystems
cmake_minimum_required(VERSION 3.14)
# Name des Projekts
project(Zettel07)

# Optionen
#-------------------------------------------#

# Setzte verwendeten C++-Standard auf C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Füge selbsgeschriebene Includes hinzu
include_directories(include)
# Füge externe Includes hinzu
include_directories(external)

# Baue Programme
#-------------------------------------------#
add_executable(aufg1 examples/aufg1.cpp src/simpler_graph.cpp)
add_executable(aufg2 examples/aufg2.cpp src/simpler_graph.cpp)

