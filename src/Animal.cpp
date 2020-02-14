#include "../headers/Animal.hpp"
#include "../headers/TwoStepSearch.hpp"

int Animal::act() {
    int result = state->act(this);
    return result;
}

void Animal::setState(AnimalState *newState) {
    if(state != nullptr){
        delete state;
    }
    this->state = newState;
}

Animal::Animal():age(0), state(nullptr), energy(0), searchStrategy(nullptr) {

}

Tile* Animal::search() {
    return searchStrategy->search(tile);
}

void Animal::setSearchStrategy(SearchStrategy *newStrategy) {
    if(searchStrategy != nullptr){
        delete searchStrategy;
    }
    searchStrategy = newStrategy;
}
