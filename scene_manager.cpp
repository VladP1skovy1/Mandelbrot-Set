#include "scene_manager.h"

SceneManager::SceneManager()
{
    this->current_scene_id = shared_data.scene;
    this->current_scene = SceneBuilder::create_scene(shared_data.scene);
}

void SceneManager::update()
{
    if(current_scene_id != shared_data.scene){
        shared_data.active_component_index = 0;
        current_scene_id = shared_data.scene;
        delete current_scene;
        current_scene = SceneBuilder::create_scene(shared_data.scene);
    }
    if (current_scene != nullptr) {
        current_scene->set_active_component(shared_data.active_component_index);
        current_scene->render();
    } else {
        printf("Error: Current scene is nullptr.\n");;
    }
}

void SceneManager::knob_pressed(int knob)
{
    this->current_scene->knob_pressed(knob);
}

void SceneManager::knob_turned(int knob, int old_value, int new_value) {
    this->current_scene->knob_turned(knob, old_value, new_value);
}
