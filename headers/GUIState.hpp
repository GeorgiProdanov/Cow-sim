#ifndef SIMULATION_GUISTATE_HPP
#define SIMULATION_GUISTATE_HPP

#include "SDL2/SDL.h"
#include "UIState.hpp"
#include <string>
#include <vector>

class GUIState: public UIState {
public:
    GUIState(std::string windowName = "Sim", const int width = 640, const int height = 360, const int tileSize = 40);
    void updateUI() override;
    ~GUIState();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<std::vector<SDL_Rect>> tiles;
};


#endif //SIMULATION_GUISTATE_HPP
