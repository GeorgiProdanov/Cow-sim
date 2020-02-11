#include <stdexcept>
#include <iostream>
#include "../headers/GUIState.hpp"
GUIState::GUIState(std::string windowName, const int width, const int height, const int tileSize): UIState() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        throw std::runtime_error("SDL_Init failed");
    }

    window = SDL_CreateWindow(
            windowName.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width,
            height + 20,
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
        }
    }
    SDL_RenderPresent(renderer);
}

int GUIState::updateUI(SDL_Event event) {
    if(event.window.event == SDL_WINDOWEVENT_CLOSE){
        return -1;
    }
    std::cout << "update" << std::endl;
}

GUIState::~GUIState() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int GUIState::input() {
    int steps = 0;
    SDL_Event keyEvent;
    while(SDL_WaitEvent(&keyEvent)){
        if(keyEvent.window.event == SDL_WINDOWEVENT_CLOSE){
            return -1;
        }
        if(keyEvent.type == SDL_KEYUP){
            if(keyEvent.key.keysym.sym == SDLK_RETURN){
                break;
            }
            int digit = *SDL_GetKeyName(keyEvent.key.keysym.sym) - '0';
            if(digit >= 0 && digit <= 9){
                if(steps == 0){
                    steps += digit;
                } else {
                    steps *= 10;
                    steps += digit;
                }
            }
            if(keyEvent.key.keysym.sym == SDLK_BACKSPACE){
                if(steps > 0){
                    steps /= 10;
                }
            }
        }
        std::cout << steps << std::endl;
    }
    return steps;
}


