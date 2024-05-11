#pragma once
#include "scene.h"
#include "label.h"

class SceneBuilder {
public:
    static Scene* create_menu_scene();
    static Scene* create_settings_scene();
    static Scene* create_change_color_scene();
    static Scene* create_change_value_scene();
    static Scene* create_choose_set_scene();
    static Scene* create_main_scene();
};

