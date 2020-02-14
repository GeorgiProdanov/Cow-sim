#include "../headers/Field.hpp"
#include "../headers/OneStepSearch.hpp"
#include "../headers/TwoStepSearch.hpp"

Field::Field(std::vector<std::vector<Tile*>> initTiles, int cbri, int le): tiles(initTiles), LE(le), CBRI(cbri),
    height(initTiles.size()), width(initTiles.at(0).size()), CBRI_count(cbri - 1){
    std::srand(time(NULL));
}

fieldReport Field::update() {
    fieldReport report;
    if(CBRI_count == CBRI){
        Animal* newAnimal = farm.createAnimal("cow");
        Tile* spawnpoint = findSpawn();
        if(spawnpoint == nullptr){
            return report;
        }
        newAnimal->setTile(spawnpoint);
        newAnimal->setSearchStrategy(new OneStepSearch(&tiles));
        animals.push_back(newAnimal);
        CBRI_count = 0;
    }
    CBRI_count++;
    for(std::vector<Animal*>::iterator it = animals.begin(); it != animals.end(); ){
        *(*it)->getAge() += 1;
        if(*(*it)->getAge() == LE/4){
            (*it)->setSearchStrategy(new TwoStepSearch(&tiles));
        }
        if((*it)->act() == -1){
            delete (*it);
            it = animals.erase(it);
        } else {
            ++it;
        }

    }
    report = generateReport();
    return report;
}

Tile *Field::findSpawn() {
    std::vector<Tile*> fertileTiles;
    for(std::vector<Tile*> vec : tiles){
        for(Tile* tile : vec){
            if(tile->getFood() > 0){
                fertileTiles.push_back(tile);
            }
        }
    }
    if(fertileTiles.size() < 1){
        return nullptr;
    }
    unsigned int index = rand() % fertileTiles.size();
    return fertileTiles[index];
}

fieldReport Field::generateReport() {
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
