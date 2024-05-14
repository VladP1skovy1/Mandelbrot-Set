#include "input_controller.h"


InputController* InputController::instance = nullptr;

InputController::InputController() {
    mem_base = static_cast<unsigned char *>(map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0));
    if (mem_base == nullptr) {
        std::exit(1);
    }
    *(volatile uint32_t *)(mem_base + SPILED_REG_KNOBS_8BIT_o) = 0;
    knobs = *(volatile uint32_t *)(mem_base + SPILED_REG_KNOBS_8BIT_o);
}

void InputController::check_update() {
    uint32_t r = *(volatile uint32_t *)(mem_base + SPILED_REG_KNOBS_8BIT_o);

    int diff = r^knobs;
    if (diff == 0){
        return;
    }

    if(diff & BLUE_KNOB_PRESSED) {
        std::cout << "Blue button pressed. Value is " << (r&BLUE_KNOB_PRESSED) << std::endl;
        std::cout << "Old knobs value: " << (knobs&BLUE_KNOB_PRESSED) << std::endl;
    } else if(diff & GREEN_KNOB_PRESSED) {
        std::cout << "Green button pressed. Value is " << (r&GREEN_KNOB_PRESSED) << std::endl;
        std::cout << "Old knobs value: " << (knobs&GREEN_KNOB_PRESSED) << std::endl;
    } else if(diff & RED_KNOB_PRESSED) {
        std::cout << "Red button pressed. Value is "<< (r&RED_KNOB_PRESSED) << std::endl;
        std::cout << "Old knobs value: " << (knobs&RED_KNOB_PRESSED) << std::endl;
    }

    if(diff & RED_KNOB_VALUE) {
        std::cout << "Red button turned. Value is "<< (r&RED_KNOB_VALUE) << std::endl;
        std::cout << "Old knobs value: " << (knobs&RED_KNOB_PRESSED) << std::endl;
    } else if(diff & GREEN_KNOB_VALUE) {
        std::cout << "Green button turned. Value is "<< (r&GREEN_KNOB_VALUE) << std::endl;
        std::cout << "Old knobs value: " << (knobs&GREEN_KNOB_PRESSED) << std::endl;
    } else if(diff & BLUE_KNOB_VALUE) {
        std::cout << "Blue button turned. Value is "<< (r&BLUE_KNOB_VALUE) << std::endl;
        std::cout << "Old knobs value: " << (knobs&BLUE_KNOB_PRESSED) << std::endl;
    }
}




InputController *InputController::GetInstance() {
    if(instance == nullptr) {
        InputController::instance = new InputController();
    }
    return instance;
}




