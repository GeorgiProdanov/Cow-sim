#include <zconf.h>
#include "../headers/simulation.hpp"

Simulation::Simulation(UIState* ui) {
    userInterface = ui;
}

void Simulation::run() {
    sleep(6);
}

UIState* Simulation::getUIState() {
    return this->userInterface;
}

void Simulation::setUIState(UIState *ui) {
    delete userInterface;
    userInterface = ui;
}
