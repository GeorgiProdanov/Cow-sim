
#include <iostream>
#include "../headers/Field.hpp"
#include "../headers/OneStepSearch.hpp"

Field::Field(std::vector<std::vector<Tile*>> initTiles, int cbri, int le): tiles(initTiles), LE(le), CBRI(cbri),
    height(initTiles.size()), width(initTiles.at(0).size()), CBRI_count(cbri - 1), LE_count(0){
}

fieldReport Field::update() {
    if(CBRI_count == CBRI){
        Animal* newAnimal = farm.createAnimal("cow");
        newAnimal->setTile(tiles[7][12]);
        newAnimal->setSearchStrategy(new OneStepSearch(&tiles));
        animals.push_back(newAnimal);
        CBRI_count = 0;
    }
    CBRI_count++;
    for(std::vector<Animal*>::iterator it = animals.begin(); it != animals.end(); ){
        if((*it)->act() == -1){
            delete (*it);
            it = animals.erase(it);
        } else {
            ++it;
        }
    }
    fieldReport report;
    for(std::vector<Tile*> vec : tiles){
        report.push_back(std::vector<std::pair<int, bool>>());
        for(Tile* tile: vec){
            report.back().push_back(std::pair<int, bool>());
            report.back().back().first = tile->getFood();
            report.back().back().second = false;
            for(Animal* animal : animals){
                if(animal->getTile() == tile){
                    report.back().back().second = true;
                }
            }
        }
    }

    return report;
}
