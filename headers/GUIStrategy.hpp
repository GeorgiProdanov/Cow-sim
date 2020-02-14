#ifndef SIMULATION_GUISTRATEGY_HPP
#define SIMULATION_GUISTRATEGY_HPP

#include "SDL2/SDL.h"
#include "UIStrategy.hpp"
#include <string>
#include <vector>

class GUIStrategy: public UIStrategy {
public:
    GUIStrategy(std::string windowName = "Sim", const int width = 640, const int height = 360, const int tileSize = 40);
    int updateUI(WorldInfo) override;
    unsigned int input() override ;
    ~GUIStrategy();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<std::vector<SDL_Rect>> tiles;
    SDL_Texture* image;
    int tileSize;
};


#endif //SIMULATION_GUISTRATEGY_HPP
