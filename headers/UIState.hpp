#ifndef SIMULATION_UISTATE_HPP
#define SIMULATION_UISTATE_HPP


class UIState {
public:
    UIState() = default;
    virtual ~UIState() {};
    virtual void updateUI() = 0;
};


#endif //SIMULATION_UISTATE_HPP
