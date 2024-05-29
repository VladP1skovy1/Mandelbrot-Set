#pragma once
#include <cstdint>
#include "shared_data.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"

class LedsController {
private:
    static unsigned char *mem_base;

public:
    static void light_leds(int n);
    static void update();
};