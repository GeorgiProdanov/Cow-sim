cmake_minimum_required(VERSION 3.15)
project(simulation)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(simulation main.cpp src/simulation.cpp headers/simulation.hpp headers/UIStrategy.hpp src/GUIStrategy.cpp headers/GUIStrategy.hpp src/World.cpp headers/World.hpp src/Field.cpp headers/Field.hpp headers/FieldGenStrategy.hpp headers/Tile.hpp headers/Land.hpp src/Grassland.cpp headers/Grassland.hpp headers/Animal.hpp headers/GrazingAnimal.hpp src/Cow.cpp headers/Cow.hpp src/GrasslandGenStrategy.cpp headers/GrasslandGenStrategy.hpp headers/AnimalState.hpp headers/GrazingAnimalState.hpp src/GrazingEatState.cpp headers/GrazingEatState.hpp src/Farm.cpp headers/Farm.hpp src/Animal.cpp src/SearchingState.cpp headers/SearchingState.hpp headers/SearchStrategy.hpp src/OneStepSearch.cpp headers/OneStepSearch.hpp src/TwoStepSearch.cpp headers/TwoStepSearch.hpp)
target_link_libraries(simulation ${SDL2_LIBRARIES} pthread)