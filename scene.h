#pragma once
#include <memory>
#include <vector>
#include "component.h"

class Scene{
private:
    std::vector<std::unique_ptr<Component>>components;

public:    
    void add_component(Component* comp);

    void render();

};

