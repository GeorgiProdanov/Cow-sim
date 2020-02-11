#include <zconf.h>
#include <iostream>
#include "../headers/simulation.hpp"

Simulation::Simulation(UIState* ui, int cbri, int le): userInterface(ui), CBRI(cbri), LE(le) {
}

void Simulation::run() {
    while(true){
        int stepsRemaining = userInterface->input();
        while(stepsRemaining > 0){
            stepsRemaining--;
            SDL_Event event;//TODO if event e kuvto trqa togaa update
            SDL_WaitEvent(&event);
            int quit = userInterface->updateUI(event);
            if(quit < 0){
                return;
            }
        }
        if(stepsRemaining < 0){
            break;
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
