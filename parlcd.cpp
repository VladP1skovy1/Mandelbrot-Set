#include "parlcd.h"

ParLCD* ParLCD::instance = nullptr;

ParLCD::ParLCD()
{
    mem_base = (unsigned char*)map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
    if(mem_base == nullptr) {
        std::exit(1);
    }
    parlcd_hx8357_init(mem_base);
    parlcd_write_cmd(mem_base, 0x2c);
}

ParLCD *ParLCD::GetInstance()
{
    if(instance == nullptr) {
        ParLCD::instance = new ParLCD();
    }
    return instance;
}

void ParLCD::update(unsigned short *fb, int len)
{
    parlcd_write_cmd(mem_base, 0x2c);
    for (size_t i = 0; i < len; i++) {
        *(volatile uint16_t*)(mem_base + PARLCD_REG_DATA_o) = fb[i];
    }
}
