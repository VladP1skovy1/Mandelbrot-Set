#include <cstdint>
#include "shared_data.h"
#include "scene.h"

class scene_controller {
private:
    Scene current_scene;
public:
    void knob_pressed(int knob);
    void knob_turned(int knob, int old_value, int new_value);
};
