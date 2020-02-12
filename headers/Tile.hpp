#ifndef SIMULATION_TILE_HPP
#define SIMULATION_TILE_HPP


class Tile {
public:
    Tile(int initFood): foodAmount(initFood) {};
    virtual ~Tile() {}
    virtual void reduceFood(unsigned int amount) = 0;
    virtual int getFood() = 0;
protected:
    int foodAmount;


};


#endif //SIMULATION_TILE_HPP
