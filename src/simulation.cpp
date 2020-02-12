#include <zconf.h>
#include <iostream>
#include "../headers/simulation.hpp"
#include "../headers/World.hpp"
Simulation::Simulation(UIState* ui): userInterface(ui){
}

void Simulation::run() {
    World world;
    addWorld(world);
    while(true){
        unsigned int stepsRemaining = userInterface->input();
        while(stepsRemaining > 0){
            stepsRemaining--;
            for(World world : worlds){
                userInterface->updateUI(world.update());
            }
        }
    }
}

UIState* Simulation::getUIState() {
    return this->userInterface;
}

void Simulation::setUIState(UIState *ui) {
    delete userInterface;
    userInterface = ui;
}

void Simulation::addWorld(World newWorld) {
    worlds.push_back(newWorld);
}
