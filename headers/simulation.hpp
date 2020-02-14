#ifndef SIMULATION_SIMULATION_HPP
#define SIMULATION_SIMULATION_HPP


#include "UIStrategy.hpp"
#include "GUIStrategy.hpp"
#include "World.hpp"

class Simulation {
public:
    Simulation(UIStrategy* ui);
    void run();
    void setUIState(UIStrategy* ui);
    void addWorld(World newWorld);
private:
    UIStrategy* userInterface;
    std::vector<World> worlds;
};


#endif //SIMULATION_SIMULATION_HPP
