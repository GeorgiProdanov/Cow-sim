#ifndef SIMULATION_FARM_HPP
#define SIMULATION_FARM_HPP


#include <string>
#include "Animal.hpp"

class Farm {
public:
    Farm();
    Animal* createAnimal(std::string type);
};


#endif //SIMULATION_FARM_HPP
