#pragma once
#include <stdlib.h>
#include "mzapo_regs.h"
#include "mzapo_phys.h"
#include "mzapo_parlcd.h"

#define PARLCD_WIDTH 480
#define PARLCD_HEIGHT 320

class ParLCD
{
private:
    static ParLCD* instance;

    unsigned char* mem_base;
protected:
    ParLCD();
public:
    // deleted constructors
    ParLCD(ParLCD& other) = delete;
    void operator=(const ParLCD&) = delete;

    static ParLCD* GetInstance();
    void update(unsigned short* fb, int len);
    ~ParLCD();
};