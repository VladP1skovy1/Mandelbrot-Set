#pragma once
#include <memory>
#include <vector>
#include "component.h"
#include "click_handler.h"
class Scene{

private:
    std::vector<std::unique_ptr<Component>>components;

public:
    typedef void (*ClickHandler)(int);
    typedef void (*TurnHandler)(int, int, int);
    Scene();
    void add_component(Component* comp);
    void render();
    void set_click_handler(ClickHandler clickHandler);
    void set_turn_handler(TurnHandler turnHandler);
private:

    ClickHandler clickHandler;
    TurnHandler turnHandler;
};

