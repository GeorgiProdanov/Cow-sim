//
// Created by georgi on 2/11/20.
//

#ifndef SIMULATION_LAND_HPP
#define SIMULATION_LAND_HPP


#include "Tile.hpp"

class Land: public Tile {
public:
    Land(int initFood): Tile(initFood) {};
    virtual ~Land() {}
    virtual void reduceFood(unsigned int amount) = 0;
    virtual int getFood() = 0;
};


#endif //SIMULATION_LAND_HPP
