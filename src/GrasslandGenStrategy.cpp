#include "../headers/GrasslandGenStrategy.hpp"
#include "../headers/Grassland.hpp"

GrasslandGenStrategy::GrasslandGenStrategy() {

}

Field GrasslandGenStrategy::generateField(int width, int height, int cbri, int le){
    std::vector<std::vector<Tile*>> tiles;
    for(int i = 0; i < height; i++){
        tiles.push_back(std::vector<Tile*>());
        for(int j = 0; j < width; j++){
            Grassland* grass = new Grassland(128);
            tiles[i].push_back(grass);
        }
    }
    Field newField(tiles);
    return newField;
}
