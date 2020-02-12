#include "../headers/World.hpp"
#include "../headers/FieldGenStrategy.hpp"
#include "../headers/GrasslandGenStrategy.hpp"

World::World() {
    FieldGenStrategy* strategy = new GrasslandGenStrategy();
    addField(strategy);
    delete strategy;
}

WorldInfo World::update() {
    WorldInfo info;
    for(auto field : fields){
        info.push_back(field.update());
    }
    return info;
}

void World::addField(FieldGenStrategy* strategy, int width, int height, int cbri, int le) {
    Field newField = strategy->generateField(width, height, cbri, le);
    fields.push_back(newField);
}
