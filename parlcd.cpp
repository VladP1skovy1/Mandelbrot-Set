#include "parlcd.h"

ParLCD::ParLCD()
{
    mem_base = (unsigned char*)map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
    if(mem_base == nullptr) {
        exit(1);
    }
    parlcd_hx8357_init(mem_base);
    parlcd_write_cmd(mem_base, 0x2c);
}

ParLCD *ParLCD::GetInstance()
{
    if(instance == nullptr) {
        instance = new ParLCD();
    }
    return instance;
}

void ParLCD::update(unsigned char *fb, int len)
{
    memcpy(mem_base + PARLCD_REG_DATA_o, fb, len);
    parlcd_write_cmd(mem_base, 0x2c);
}
