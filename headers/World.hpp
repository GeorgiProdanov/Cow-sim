#ifndef SIMULATION_WORLD_HPP
#define SIMULATION_WORLD_HPP


#include <vector>
#include "Field.hpp"
#include "FieldGenStrategy.hpp"

typedef std::vector<std::vector<std::vector<std::pair<int, bool>>>> WorldInfo;
class World {
public:
    World();
    WorldInfo update();
    void addField(FieldGenStrategy* strategy, int width = 16, int height = 9, int cbri = 20, int le = 200);

private:
    std::vector<Field> fields;

};


#endif //SIMULATION_WORLD_HPP
