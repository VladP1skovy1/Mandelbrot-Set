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
    typedef void (*TurnDirectedHandler)(int, int);
    typedef void (*TurnHandler)(int, int, int);
    //typedef [] (int, int, int) TurnHandler;
    Scene();
    void add_component(Component* comp);
    void render();
    void set_active_component(int index);
    void knob_pressed(int knob);
    void knob_turned(int knob, int old_value, int new_value);
    void knob_turned_directed(int knob, int direction);
    void set_press_handler(PressHandler press_handler);
    void set_turn_handler(TurnHandler turn_handler);
    void set_dir_turn_handler(TurnDirectedHandler dir_tur_handler);
private:

    PressHandler press_handler;
    TurnHandler turn_handler;
    TurnDirectedHandler dir_tur_handler;
};

