#ifndef SIMULATION_SIMULATION_HPP
#define SIMULATION_SIMULATION_HPP


#include "UIState.hpp"
#include "GUIState.hpp"

class Simulation {
public:
    Simulation(UIState* ui);
    void run();
    UIState* getUIState();
    void setUIState(UIState* ui);

private:
    UIState* userInterface;
};


#endif //SIMULATION_SIMULATION_HPP
