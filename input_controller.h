#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include <cstdlib>
#include <cstdint>
#include <iostream>

enum KNOBS{
    RED_KNOB_PRESSED = 0x40000000,
    GREEN_KNOB_PRESSED = 0x20000000,
    BLUE_KNOB_PRESSED = 0x10000000,
    RED_KNOB_VALUE = 0xff0000,
    GREEN_KNOB_VALUE = 0xff00,
    BLUE_KNOB_VALUE = 0xff,
};

class InputController {
private:
    static InputController* instance;
    unsigned char *mem_base;
    uint32_t knobs;

public:
    InputController();
    void check_update();
    static InputController* GetInstance();
};

