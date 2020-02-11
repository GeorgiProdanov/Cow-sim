cmake_minimum_required(VERSION 3.15)
project(simulation)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(simulation main.cpp src/simulation.cpp headers/simulation.hpp headers/UIState.hpp src/GUIState.cpp headers/GUIState.hpp)
target_link_libraries(simulation ${SDL2_LIBRARIES})