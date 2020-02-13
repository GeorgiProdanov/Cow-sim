#ifndef SIMULATION_GRAZINGANIMALSTATE_HPP
#define SIMULATION_GRAZINGANIMALSTATE_HPP


#include "AnimalState.hpp"
#include "GrazingAnimal.hpp"

class GrazingAnimalState: public AnimalState {
public:
    GrazingAnimalState(): AnimalState() {}
    virtual ~GrazingAnimalState() {}
    virtual int act(Animal* animal) = 0;
};


#endif //SIMULATION_GRAZINGANIMALSTATE_HPP
