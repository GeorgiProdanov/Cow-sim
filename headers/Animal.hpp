#ifndef SIMULATION_ANIMAL_HPP
#define SIMULATION_ANIMAL_HPP


#include <iostream>
#include "Tile.hpp"
#include "AnimalState.hpp"
#include "SearchStrategy.hpp"

class Animal {
protected:
    unsigned int age;
    int energy;
    Tile* tile;
    AnimalState* state;
    SearchStrategy* searchStrategy;
public:
    Animal();
    virtual ~Animal() {std::cout << "Dead" <<std::endl;}
    virtual Tile* getTile() { return tile; }
    virtual void setTile(Tile* newTile){ tile = newTile;}
    virtual unsigned int* getAge() { return &age; }
    virtual int* getEnergy() { return &energy; }
    virtual void setState(AnimalState* newState);
    int act();
    Tile* search();
    void move(Tile* whereTo);
    void setSearchStrategy(SearchStrategy* newStrategy);
};


#endif //SIMULATION_ANIMAL_HPP
