#ifndef SIMULATION_ONESTEPSEARCH_HPP
#define SIMULATION_ONESTEPSEARCH_HPP


#include "SearchStrategy.hpp"

class OneStepSearch: public SearchStrategy {
public:
    OneStepSearch(std::vector<std::vector<Tile*>>* field);
    Tile* search(Tile*) override;
};


#endif //SIMULATION_ONESTEPSEARCH_HPP
