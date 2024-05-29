#include "shared_data.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "colors.h"

class RGBLedController {
    static unsigned char *mem_base;
public:
    static void light_leds(rgb565_t color);
    static void update(); 
};