#include "../headers/SearchingState.hpp"
#include "../headers/GrazingEatState.hpp"

SearchingState::SearchingState() {

}

int SearchingState::act(Animal* animal) {
    if(animal->getTile()->getFood() > 0){
        animal->setState(new GrazingEatState());
        return 0;
    }
    Tile* moveTo = animal->search();
    *animal->getEnergy() -= *animal->getAge()/2;
    if(*animal->getEnergy() < 0 || *animal->getAge() > 200){
        return -1;//dead;
    }
    *animal->getAge() += 1;
    animal->setTile(moveTo);
    return 0;
}
