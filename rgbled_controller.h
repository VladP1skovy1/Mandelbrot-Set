/**
 * @file rgbled_controller.h
 * @brief Header file for the RGBLedController class.
 */

#include "shared_data.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "colors.h"

/**
 * @class RGBLedController
 * @brief A class to control the RGB LEDs.
 */
class RGBLedController {
    static unsigned char *mem_base; /**< Base memory address for the LEDs */

public:
    /**
     * @brief Light up the RGB LEDs with a specific color.
     * @param color The color to set the LEDs to.
     */
    static void light_leds(rgb565_t color);

    /**
     * @brief Update the state of the RGB LEDs.
     */
    static void update();
};
