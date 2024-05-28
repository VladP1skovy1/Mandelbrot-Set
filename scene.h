#pragma once
#include <memory>
#include <vector>
#include <stdio.h>
#include "component.h"
class Scene{

private:
    std::vector<std::unique_ptr<Component>>components;
    int active_component_index;

public:
    typedef void (*PressHandler)(int);
    typedef void (*TurnHandler)(int, int, int);
    //typedef [] (int, int, int) TurnHandler;
    Scene();
    void add_component(Component* comp);
    void render();
    void set_active_component(int index);
    void knob_pressed(int knob);
    void knob_turned(int knob, int old_value, int new_value);
    void set_press_handler(PressHandler clickHandler);
    void set_turn_handler(TurnHandler turnHandler);
private:

    PressHandler press_handler;
    TurnHandler turnHandler;
};

