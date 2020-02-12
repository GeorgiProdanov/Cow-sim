#ifndef SIMULATION_UISTATE_HPP
#define SIMULATION_UISTATE_HPP

#include <vector>
#include "SDL_events.h"

typedef std::vector<std::vector<std::vector<std::pair<int, bool>>>> WorldInfo;
class UIState {
public:
    UIState() = default;
    virtual ~UIState() {};
    virtual int updateUI(WorldInfo) = 0;
    virtual unsigned int input() = 0;
};


#endif //SIMULATION_UISTATE_HPP
