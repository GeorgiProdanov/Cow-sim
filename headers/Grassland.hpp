#ifndef SIMULATION_GRASSLAND_HPP
#define SIMULATION_GRASSLAND_HPP


#include "Land.hpp"

class Grassland: public Land {
public:
    Grassland(int initFood);
    void reduceFood(unsigned int amount) override;
    int getFood() override;
};


#endif //SIMULATION_GRASSLAND_HPP
