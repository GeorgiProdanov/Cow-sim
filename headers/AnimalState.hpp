#ifndef SIMULATION_ANIMALSTATE_HPP
#define SIMULATION_ANIMALSTATE_HPP



class AnimalState {
public:
    AnimalState() = default;
    virtual ~AnimalState() {}
    virtual int act(class Animal* animal) = 0;

};


#endif //SIMULATION_ANIMALSTATE_HPP
