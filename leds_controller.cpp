#include "leds_controller.h"

unsigned char *LedsController::mem_base = (unsigned char*)map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);

void LedsController::light_leds(int n)
{
    *(volatile uint32_t *)(mem_base + SPILED_REG_LED_LINE_o) =  0xffffffff << (32 - n);

}

void LedsController::update()
{
    light_leds(shared_data.led_fired);
}
