
#ifndef SIMULATION_FIELD_HPP
#define SIMULATION_FIELD_HPP


#include <vector>
#include "Tile.hpp"
#include "Farm.hpp"

typedef std::vector<std::vector<std::pair<int, bool>>> fieldReport;

class Field {
public:
    Field(std::vector<std::vector<Tile*>> initTiles, int CBRI = 20, int LE = 200);
    fieldReport update();

private:
    std::vector<std::vector<Tile*>> tiles;
    std::vector<Animal*> animals;
    Farm farm;
    int width;
    int height;
    int CBRI;
    int CBRI_count;
    int LE;
    Tile* findSpawn();
    fieldReport generateReport();
};


#endif //SIMULATION_FIELD_HPP
