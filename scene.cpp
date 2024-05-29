#include "scene.h"
#include "shared_data.h"

Scene::Scene(){
    shared_data.active_component_index = 0;
    this->active_component_index = 0;
    this->press_handler = nullptr;
    this->turn_handler = nullptr;
}
void Scene::add_component(Component* comp){
    components.push_back(std::unique_ptr<Component>(comp));
}

void Scene::render(){
    if(components.size() == 0){
        return;
    }
    for (int i = 0; i < components.size(); i++)
    {
        components[i]->render();
    }
}

void Scene::set_active_component(int index)
{
    if (index >= 0 && index < components.size())
    {
        components[active_component_index]->set_active(false);
        active_component_index = index;
        components[active_component_index]->set_active(true);
    }
}

void Scene::knob_pressed(int knob)
{
    if (this->press_handler != nullptr)
    {
        this->press_handler(knob);
    }
}

void Scene::knob_turned(int knob, int old_value, int new_value)
{
    if (this->turn_handler != nullptr)
    {
        this->turn_handler(knob, old_value, new_value);
    }
}

void Scene::knob_turned_directed(int knob, int direction)
{
    if (this->dir_tur_handler != nullptr)
    {
        this->dir_tur_handler(knob, direction);
    }
}

void Scene::set_press_handler(PressHandler clickHandler)
{
    this->press_handler = clickHandler;
}

void Scene::set_turn_handler(TurnHandler turn_handler)
{
    this->turn_handler = turn_handler;
}

void Scene::set_dir_turn_handler(TurnDirectedHandler dir_tur_handler)
{
    this->dir_tur_handler = dir_tur_handler;
}
