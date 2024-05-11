#include "scene.h"
#include "label.h"

class SceneBuilder {
public:
    Scene* create_menu_scene();
    Scene* create_settings_scene();
    Scene* create_change_color_scene();
    Scene* create_change_value_scene();
    Scene* create_choose_set_scene();
    Scene* create_main_scene();
};

