#ifndef SIMULATION_SEARCHSTRATEGY_HPP
#define SIMULATION_SEARCHSTRATEGY_HPP


#include <vector>
#include "Tile.hpp"

class SearchStrategy {
public:
    SearchStrategy(std::vector<std::vector<Tile*>>* field): field(field){}
    virtual ~SearchStrategy() {}
    virtual Tile* search(Tile* current) = 0;
protected:
    std::vector<std::vector<Tile*>>* field;
};


#endif //SIMULATION_SEARCHSTRATEGY_HPP
