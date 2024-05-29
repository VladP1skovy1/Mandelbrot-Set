#include "input_controller.h"


InputController* InputController::instance = nullptr;

InputController::InputController() {
    mem_base = static_cast<unsigned char *>(map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0));
    if (mem_base == nullptr) {
        std::exit(1);
    }
    knobs = *(volatile uint32_t *)(mem_base + SPILED_REG_KNOBS_8BIT_o);
}

void InputController::update() {
    knobs_t r = *(volatile uint32_t *)(mem_base + SPILED_REG_KNOBS_8BIT_o);

    knobs_t diff = r^knobs;
    if (diff == 0){
        return;
    }

    if(diff.is_blue_pressed && r.is_blue_pressed) {
        scene_manager->knob_pressed(2);
        //std::cout << "Blue button pressed. Value is " << (r.is_blue_pressed) << std::endl;
        //std::cout << "Old knobs value: " << (knobs.is_blue_pressed) << std::endl;
    } else if(diff.is_green_pressed && r.is_green_pressed) {
        scene_manager->knob_pressed(1);
        //std::cout << "Green button pressed. Value is " << (r.is_green_pressed) << std::endl;
        //std::cout << "Old knobs value: " << (knobs.is_green_pressed) << std::endl;
    } else if(diff.is_red_pressed && r.is_red_pressed) {
        scene_manager->knob_pressed(0);
        //std::cout << "Red button pressed. Value is "<< (r.is_red_pressed) << std::endl;
        //std::cout << "Old knobs value: " << (knobs.is_red_pressed) << std::endl;
    }

    if(diff.red) {
        scene_manager->knob_turned(0, knobs.red, r.red);
        scene_manager->knob_turned_directed(0, knobs.red < r.red ? 1 : -1);
        //std::cout << "Red button turned. Value is "<< (r.red) << std::endl;
        //std::cout << "Old knobs value: " << (knobs.red) << std::endl;
    } else if(diff.green) {
        scene_manager->knob_turned(1, knobs.green, r.green);
        scene_manager->knob_turned_directed(1, knobs.green < r.green ? 1 : -1);
        //std::cout << "Green button turned. Value is "<< (r.green) << std::endl;
        //std::cout << "Old knobs value: " << (knobs.green) << std::endl;
    } else if(diff.blue) {
        scene_manager->knob_turned(2, knobs.blue, r.blue);
        scene_manager->knob_turned_directed(2, knobs.blue < r.blue ? 1 : -1);
        //std::cout << "Blue button turned. Value is "<< (r.blue) << std::endl;
        //std::cout << "Old knobs value: " << (knobs.blue) << std::endl;
    }

    knobs = r;
}

void InputController::set_scene_manager(SceneManager *scene_manager)
{
    this->scene_manager = scene_manager;
}

InputController *InputController::get_instance() {
    if(instance == nullptr) {
        InputController::instance = new InputController();
    }
    return instance;
}




