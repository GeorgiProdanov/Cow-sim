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
                WorldInfo info = world.update();
                try{
                    info.at(0).at(0);
                }catch (std::out_of_range){
                    return;
                }
                userInterface->updateUI(info);
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
