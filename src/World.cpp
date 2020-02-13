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
/*    for(std::vector<Field>::iterator it = fields.begin(); it != fields.end(); ++it){
        fieldReport report = (*it).update();
        info.push_back(report);
    }*/
    for(int i = 0; i < fields.size(); i++){
        fieldReport report = fields[i].update();
        info.push_back(report);
    }
    return info;
}

void World::addField(FieldGenStrategy* strategy, int width, int height, int cbri, int le) {
    Field newField = strategy->generateField(width, height, cbri, le);
    fields.push_back(newField);
}
