#include "../headers/GrazingEatState.hpp"
#include "../headers/SearchingState.hpp"

GrazingEatState::GrazingEatState(): GrazingAnimalState() {

}

int GrazingEatState::act(Animal* animal) {
    if(*animal->getEnergy() < 0 || *animal->getAge() >= 200){
        return -1; //dead
    }

    if(animal->getTile()->getFood() <= 0){
        animal->setState(new SearchingState());
        return 0;
    }

    if(*animal->getAge() + 3 > animal->getTile()->getFood()){
        *animal->getEnergy() += animal->getTile()->getFood();
        animal->getTile()->reduceFood(animal->getTile()->getFood());
    } else {
        *animal->getEnergy() += *animal->getAge() + 3;
        animal->getTile()->reduceFood(*animal->getAge() +3);
    }
    *animal->getAge() += 1;
    return 0;
}
