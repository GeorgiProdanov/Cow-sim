#ifndef SIMULATION_ANIMAL_HPP
#define SIMULATION_ANIMAL_HPP


#include "Tile.hpp"
#include "AnimalState.hpp"

class Animal {
protected:
    unsigned int age;
    int energy;
    Tile* tile;
    AnimalState* state;
public:
    Animal();
    virtual ~Animal() {}
    virtual Tile* getTile() { return tile; }
    virtual void setTile(Tile* newTile){ tile = newTile;}
    virtual unsigned int* getAge() { return &age; }
    virtual int* getEnergy() { return &energy; }
    virtual void setState(AnimalState* newState);
    int act();


};


#endif //SIMULATION_ANIMAL_HPP
