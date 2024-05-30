/**
 * @file leds_controller.h
 * @brief Header file for the LedsController class.
 */

#pragma once
#include <cstdint>
#include "shared_data.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"

/**
 * @class LedsController
 * @brief A class to control the LEDs.
 */
class LedsController {
private:
    static unsigned char *mem_base; /**< Base memory address for the LEDs */

public:
    /**
     * @brief Light up LEDs based on the given value.
     * @param n Value to determine which LEDs to light up.
     */
    static void light_leds(int n);

    /**
     * @brief Update the state of the LEDs.
     */
    static void update();
};
