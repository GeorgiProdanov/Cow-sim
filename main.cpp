

#include "headers/GUIState.hpp"
#include "headers/simulation.hpp"

int main() {
    Simulation sim(new GUIState("Cow sim", 640, 360));
    sim.run();
    return 0;
}
