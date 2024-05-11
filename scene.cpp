#include "scene.h"

    
void Scene::add_component(Component* comp){
    components.push_back(std::unique_ptr<Component>(comp));
}

void Scene::render(){   
    for (int i = 0; i < components.size(); i++)
    {
        components[i]->render();
    }
}

