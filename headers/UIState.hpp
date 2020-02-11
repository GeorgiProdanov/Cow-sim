#ifndef SIMULATION_UISTATE_HPP
#define SIMULATION_UISTATE_HPP

#include "SDL_events.h"
class UIState {
public:
    UIState() = default;
    virtual ~UIState() {};
    virtual int updateUI(SDL_Event event) = 0;
    virtual int input() = 0;
};


#endif //SIMULATION_UISTATE_HPP
