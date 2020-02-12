#ifndef SIMULATION_FIELDGENSTRATEGY_HPP
#define SIMULATION_FIELDGENSTRATEGY_HPP


#include "Field.hpp"

class FieldGenStrategy {
public:
    FieldGenStrategy() = default;
    virtual Field generateField(int width = 16, int height = 9, int cbri = 20, int le = 200) = 0;
    virtual ~FieldGenStrategy() {};
};


#endif //SIMULATION_FIELDGENSTRATEGY_HPP
