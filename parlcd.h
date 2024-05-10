#include <string.h>
#include <cstdlib>
#include "mzapo_regs.h"
#include "mzapo_phys.h"
#include "mzapo_parlcd.h"

class ParLCD
{
private:
    static ParLCD* instance;
    unsigned char* mem_base;
protected:
    ParLCD();
public:
    // deleted constructors
    ParLCD() = delete;
    ParLCD(ParLCD& other) = delete;
    void operator=(const ParLCD&) = delete;

    static ParLCD* GetInstance();
    void update(unsigned char* fb, int len);
    ~ParLCD();
};