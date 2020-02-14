#ifndef SIMULATION_TWOSTEPSEARCH_HPP
#define SIMULATION_TWOSTEPSEARCH_HPP


#include "SearchStrategy.hpp"

class TwoStepSearch: public SearchStrategy {
public:
    TwoStepSearch(std::vector<std::vector<Tile*>>* field);
    Tile* search(Tile* current);
};


#endif //SIMULATION_TWOSTEPSEARCH_HPP
