
#include <stdexcept>
#include "../headers/Farm.hpp"
#include "../headers/Cow.hpp"
#include "../headers/GrazingEatState.hpp"

Farm::Farm() {

}

Animal *Farm::createAnimal(std::string type) {
    if(type == "cow"){
        Cow* newAnimal = new Cow();
        GrazingEatState* state = new GrazingEatState();
        newAnimal->setState(state);
        return newAnimal;
    } else {
        throw std::runtime_error("farm::createAnimal unknown Animal");
    }
}
