#include "../headers/Grassland.hpp"

Grassland::Grassland(int initFood): Land(initFood) {
}

void Grassland::reduceFood(unsigned int amount) {
    if(foodAmount - amount < 0){
        foodAmount = 0;
    } else {
        foodAmount -= amount;
    }
}

int Grassland::getFood() {
    return this->foodAmount;
}
