#ifndef SIMULATION_UISTRATEGY_HPP
#define SIMULATION_UISTRATEGY_HPP

#include <vector>
#include "SDL_events.h"

typedef std::vector<std::vector<std::vector<std::pair<int, bool>>>> WorldInfo;
class UIStrategy {
public:
    UIStrategy() = default;
    virtual ~UIStrategy() {};
    virtual int updateUI(WorldInfo) = 0;
    virtual unsigned int input() = 0;
};


#endif //SIMULATION_UISTRATEGY_HPP
