#include <stdexcept>
#include "../headers/TwoStepSearch.hpp"

TwoStepSearch::TwoStepSearch(std::vector<std::vector<Tile *>> *field) : SearchStrategy(field) {

}

Tile *TwoStepSearch::search(Tile *current) {
    int maxFood = 0;
    Tile* moveTo = current;
    int currentX = 0;
    int currentY = 0;
    int moveToX = 0;
    int moveToY = 0;

    for(size_t x = 0; x < field->size(); x++){
        for(size_t y = 0; y < field->at(x).size(); y++){
            if(current == field->at(x).at(y)){
                currentX = x;
                currentY = y;
                for(int i = -2; i <=2; i++){
                    for(int j = -2; j <= 2; j++){
                        try{
                            if(field->at(x + i).at(y + j)->getFood() > maxFood){
                                maxFood = field->at(x + i).at(y + j)->getFood();
                                moveTo = field->at(x + i).at(y + j);
                                moveToX = x + i;
                                moveToY = y + j;

                            }
                        }catch(std::out_of_range){
                            continue;
                        }
                    }
                }
                if(abs(currentX - moveToX) > 1){
                    if(currentX < moveToX){
                        moveToX = currentX + 1;
                    } else{
                        moveToX++;
                    }
                }
                if(abs(currentY - moveToY) > 1){
                    if(currentY < moveToY){
                        moveToY = currentY + 1;
                    } else{
                        moveToY++;
                    }
                }
                return field->at(moveToX).at(moveToY);
            }
        }
    }
}
