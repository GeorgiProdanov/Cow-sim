#ifndef SIMULATION_GRASSLANDGENSTRATEGY_HPP
#define SIMULATION_GRASSLANDGENSTRATEGY_HPP


#include "FieldGenStrategy.hpp"

class GrasslandGenStrategy: public FieldGenStrategy {
public:
    GrasslandGenStrategy();
    Field* generateField(int width = 16, int height = 9, int cbri = 20, int le = 200) override;

};


#endif //SIMULATION_GRASSLANDGENSTRATEGY_HPP
