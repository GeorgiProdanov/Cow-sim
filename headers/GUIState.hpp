#ifndef SIMULATION_GUISTATE_HPP
#define SIMULATION_GUISTATE_HPP

#include "SDL2/SDL.h"
#include "UIState.hpp"
#include <string>
#include <vector>

class GUIState: public UIState {
public:
    GUIState(std::string windowName = "Sim", const int width = 640, const int height = 360, const int tileSize = 40);
    int updateUI(WorldInfo) override;
    unsigned int input() override ;
    ~GUIState();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<std::vector<SDL_Rect>> tiles;
    SDL_Texture* image;
    int tileSize;
};


#endif //SIMULATION_GUISTATE_HPP
