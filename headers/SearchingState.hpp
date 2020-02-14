#ifndef SIMULATION_SEARCHINGSTATE_HPP
#define SIMULATION_SEARCHINGSTATE_HPP


#include "GrazingAnimalState.hpp"

class SearchingState: public GrazingAnimalState {
public:
    SearchingState();
    int act(Animal* animal) override;

};


#endif //SIMULATION_SEARCHINGSTATE_HPP
