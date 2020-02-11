#include <stdexcept>
#include "../headers/GUIState.hpp"
//#include <SDL2/SDL_render.h>
//#include <SDL2/SDL_video.h>
GUIState::GUIState(std::string windowName, const int width, const int height, const int tileSize): UIState() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        throw std::runtime_error("SDL_Init failed");
    }

    window = SDL_CreateWindow(
            windowName.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height,
            SDL_WINDOW_SHOWN
            );
    if(0 == window){
        throw std::runtime_error("SDL_CreateWindow failed");
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if(0 == renderer){
        throw std::runtime_error("SDL_CreateRenderer failed");
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    int horizontalTiles = width / tileSize;
    int verticalTiles = height / tileSize;
    for(int i = 0; i < verticalTiles; i++){
        tiles.push_back(std::vector<SDL_Rect>());
        for(int j = 0; j < horizontalTiles; j++){
            SDL_Rect rect = {tileSize*j, tileSize*i, tileSize, tileSize};
            tiles[i].push_back(rect);
            SDL_SetRenderDrawColor(renderer, 0, 128, 0, 0);
            SDL_RenderFillRect(renderer, &rect);
            SDL_RenderPresent(renderer);
        }
    }
}

void GUIState::updateUI() {

}

GUIState::~GUIState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}


