#include "scene.h"

    
void Scene::add_component(std::unique_ptr<Component> comp){
    components.push_back(comp);
}

void Scene::render(){   
    for (int i = 0; i < components.size(); i++)
    {
        components[i]->render();
    }
}

