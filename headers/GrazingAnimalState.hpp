#ifndef SIMULATION_GRAZINGANIMALSTATE_HPP
#define SIMULATION_GRAZINGANIMALSTATE_HPP


#include "AnimalState.hpp"
#include "GrazingAnimal.hpp"

class GrazingAnimalState: public AnimalState {
public:
    GrazingAnimalState(): AnimalState() {}
    virtual ~GrazingAnimalState() {}
};


#endif //SIMULATION_GRAZINGANIMALSTATE_HPP
