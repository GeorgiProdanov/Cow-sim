#include "../headers/GrasslandGenStrategy.hpp"
#include "../headers/Grassland.hpp"
#include <cmath>
GrasslandGenStrategy::GrasslandGenStrategy() {

}

Field* GrasslandGenStrategy::generateField(int width, int height, int cbri, int le){
    std::vector<std::vector<Tile*>> tiles;
    int mod = 255/width;
    for(int i = 0; i < height; i++){
        tiles.push_back(std::vector<Tile*>());
        for(int j = 0; j < width; j++){
            Grassland* grass = new Grassland(abs((mod*j) - mod*i));
            tiles[i].push_back(grass);
        }
    }
    Field* newField = new Field(tiles, cbri, le);
    return newField;
}
