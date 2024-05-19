#pragma once
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include "scene_manager.h"

enum KNOBS{
    RED_KNOB_PRESSED = 0x40000000,
    GREEN_KNOB_PRESSED = 0x20000000,
    BLUE_KNOB_PRESSED = 0x10000000,
    RED_KNOB_VALUE = 0xff0000,
    GREEN_KNOB_VALUE = 0xff00,
    BLUE_KNOB_VALUE = 0xff,
};

  typedef struct  Knbs {
    unsigned int blue : 8;
    unsigned int green : 8;
    unsigned int red : 8;
    unsigned int is_blue_pressed : 1;
    unsigned int is_green_pressed : 1;
    unsigned int is_red_pressed : 1;
    unsigned int trash : 5;

    Knbs() {
        blue = 0;
        green = 0;
        red = 0;
        is_blue_pressed = 0;
        is_green_pressed = 0;
        is_red_pressed = 0;
        trash = 0;
    }

    Knbs(unsigned int val) {
        *(unsigned int *)this = val;
    }

    operator unsigned int() const {
        return *(unsigned int *)this;
    }
    void operator =(unsigned int val) {
        *(unsigned int *)this = val;
    }
  } knobs_t;

class InputController {
private:
    static InputController* instance;
    SceneManager *scene_manager;
    unsigned char *mem_base;
    knobs_t knobs;

public:
    InputController();
    void update();
    void set_scene_manager(SceneManager *scene_manager);
    static InputController* GetInstance();
};

