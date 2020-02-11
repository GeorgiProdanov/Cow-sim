#ifndef SIMULATION_SIMULATION_HPP
#define SIMULATION_SIMULATION_HPP


#include "UIState.hpp"
#include "GUIState.hpp"
#include "World.hpp"

class Simulation {
public:
    Simulation(UIState* ui, int cbri = 20, int le = 200);
    void run();
    UIState* getUIState();
    void setUIState(UIState* ui);
    void addWorld(World newWorld);
private:
    UIState* userInterface;
    std::vector<World> worlds;
    int CBRI;
    int LE;
};


#endif //SIMULATION_SIMULATION_HPP
