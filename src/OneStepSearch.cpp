#include <iostream>
#include "../headers/OneStepSearch.hpp"

OneStepSearch::OneStepSearch(std::vector<std::vector<Tile*>>* field) : SearchStrategy(field) {

}

Tile *OneStepSearch::search(Tile * current) {
    for(std::size_t x = 0; x < field->size(); x++){
        for(std::size_t y = 0; y < field->at(x).size(); y++){
            if(field->at(x).at(y) == current){
                int maxFood = 0;
                Tile* moveTo = current;
                for(int i = -1; i <=1; i++){
                    try {
                        int food = field->at(x + 1).at(y + i)->getFood();
                        if(food > maxFood){
                            maxFood = food;
                            moveTo = field->at(x + 1).at(y + i);
                        }
                    } catch(std::out_of_range e){}

                    try {
                        int food = field->at(x).at(y + i)->getFood();
                        if(food > maxFood){
                            maxFood = food;
                            moveTo = field->at(x).at(y + i);
                        }
                    } catch(std::out_of_range e){}

                    try {
                        int food = field->at(x-1).at(y + i)->getFood();
                        if(food > maxFood){
                            maxFood = food;
                            moveTo = field->at(x - 1).at(y + i);
                        }
                    } catch(std::out_of_range e){}

                }
                return moveTo;
            }
        }
    }
    return nullptr;
}
