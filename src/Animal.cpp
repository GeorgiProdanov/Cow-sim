#include "../headers/Animal.hpp"

int Animal::act() {
    state->act(this);
    return 0;
}

void Animal::setState(AnimalState *newState) {
    if(state != nullptr){
        delete state;
    }
    this->state = newState;
}

Animal::Animal():age(0), state(nullptr), energy(0) {

}
