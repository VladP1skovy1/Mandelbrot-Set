#pragma once
#include <string.h>
#include <cstdlib>
#include "mzapo_regs.h"
#include "mzapo_phys.h"
#include "mzapo_parlcd.h"

#define WIDTH 480
#define HEIGHT 320

class ParLCD
{
private:
    static ParLCD* instance;

    int width;
    int height;
    unsigned short *fb;
    unsigned char* mem_base;
protected:
    ParLCD();
public:
    // deleted constructors
    ParLCD(ParLCD& other) = delete;
    void operator=(const ParLCD&) = delete;

    static ParLCD* GetInstance();
    int get_width() const;
    int get_height() const;
    unsigned short* get_buffer() const;
    void update();
    void get_red();
    ~ParLCD();
};