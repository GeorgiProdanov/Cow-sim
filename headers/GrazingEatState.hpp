#ifndef SIMULATION_GRAZINGEATSTATE_HPP
#define SIMULATION_GRAZINGEATSTATE_HPP


#include "GrazingAnimalState.hpp"

class GrazingEatState: public GrazingAnimalState {
public:
    GrazingEatState();
    int act(Animal* animal) override;
};


#endif //SIMULATION_GRAZINGEATSTATE_HPP
