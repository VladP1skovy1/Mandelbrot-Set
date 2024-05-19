#pragma once
#include <cstdint>
#include "scene.h"
#include "scene_builder.h"

class SceneManager {
private:
    Scene* current_scene;
    int current_scene_id;
public:
    SceneManager();
    void update();
    void knob_pressed(int knob);
    void knob_turned(int knob, int old_value, int new_value);
};
