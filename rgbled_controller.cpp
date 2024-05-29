#include "rgbled_controller.h"

unsigned char *RGBLedController::mem_base = (unsigned char*)map_phys_address(SPILED_REG_BASE_PHYS, SPILED_REG_SIZE, 0);

void RGBLedController::light_leds(rgb565_t color)
{
    int r = color.red * 255 / 31;
    int g = color.green * 255 / 63;
    int b = color.blue * 255 / 31;
    *(volatile uint32_t *)(mem_base + SPILED_REG_LED_RGB1_o) = 0xff000000 | (r << 16) | (g << 8) | b;
    *(volatile uint32_t *)(mem_base + SPILED_REG_LED_RGB2_o) = 0xff000000 | (r << 16) | (g << 8) | b;

}

void RGBLedController::update()
{
    if(shared_data.light_rgbs)
        light_leds(set_data.color);
    else {
        light_leds(BLACK);
    }
}
