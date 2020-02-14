

#include "headers/GUIStrategy.hpp"
#include "headers/simulation.hpp"
#include <thread>

int main() {
    Simulation sim(new GUIStrategy("Cow sim", 640, 360));
    sim.run();
    return 0;
}
