#include "parlcd.h"
#include <stdio.h>

ParLCD* ParLCD::instance;

ParLCD::ParLCD()
{
    mem_base = (unsigned char*)map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
    if(mem_base == nullptr) {
        exit(1);
    }
    parlcd_hx8357_init(mem_base);
    parlcd_write_cmd(mem_base, 0x2c);
    this->width = WIDTH;
    this->height = HEIGHT;
    fb = new unsigned short[width * height];
}

ParLCD *ParLCD::GetInstance()
{
    if(instance == nullptr) {
        ParLCD::instance = new ParLCD();
    }
    return instance;
}

int ParLCD::get_width() const
{
    return width;
}

int ParLCD::get_height() const
{
    return height;
}

unsigned short *ParLCD::get_buffer() const
{
    return fb;
}

void ParLCD::update()
{
    parlcd_write_cmd(mem_base, 0x2c);
    for (size_t i = 0; i < width * height; i++) {
        *(volatile uint16_t*)(mem_base + PARLCD_REG_DATA_o) = fb[i];
    }
}
