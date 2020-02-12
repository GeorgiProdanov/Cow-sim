
#include "../headers/Field.hpp"

Field::Field(std::vector<std::vector<Tile*>> initTiles): tiles(initTiles) {

}

fieldReport Field::update() {
    fieldReport report;
    for(std::vector<Tile*> vec : tiles){
        report.push_back(std::vector<std::pair<int, bool>>());
        for(Tile* tile: vec){
            report.back().push_back(std::pair<int, bool>());
            report.back().back().first = tile->getFood();
            report.back().back().second = false; //TODO add cows
        }
    }

    return report;
}
