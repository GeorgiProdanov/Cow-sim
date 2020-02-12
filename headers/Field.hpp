
#ifndef SIMULATION_FIELD_HPP
#define SIMULATION_FIELD_HPP


#include <vector>
#include "Tile.hpp"

typedef std::vector<std::vector<std::pair<int, bool>>> fieldReport;

class Field {
public:
    Field(std::vector<std::vector<Tile*>> initTiles);
    fieldReport update();

private:
    std::vector<std::vector<Tile*>> tiles;
    //TODO impl famr Farm farm;
    int width;
    int height;
    int CBRI;
    int LE;
};


#endif //SIMULATION_FIELD_HPP
