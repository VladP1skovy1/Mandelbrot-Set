/**
 * @file parlcd.h
 * @brief Header file for the ParLCD class.
 */

#pragma once
#include <stdlib.h>
#include "mzapo_regs.h"
#include "mzapo_phys.h"
#include "mzapo_parlcd.h"

#define PARLCD_WIDTH 480  /**< Width of the display */
#define PARLCD_HEIGHT 320 /**< Height of the display */

/**
 * @class ParLCD
 * @brief A singleton class to control the parallel LCD display.
 */
class ParLCD {
private:
    static ParLCD* instance; /**< Singleton instance of the ParLCD */

    unsigned char* mem_base; /**< Base memory address for the LCD */

protected:
    /**
     * @brief Protected constructor to prevent direct instantiation.
     */
    ParLCD();

public:
    // Deleted constructors

    /**
     * @brief Deleted copy constructor to prevent copying.
     * @param other Reference to another ParLCD instance.
     */
    ParLCD(ParLCD& other) = delete;

    /**
     * @brief Deleted assignment operator to prevent assignment.
     * @param other Reference to another ParLCD instance.
     */
    void operator=(const ParLCD&) = delete;

    /**
     * @brief Get the singleton instance of the ParLCD.
     * @return Pointer to the singleton instance.
     */
    static ParLCD* GetInstance();

    /**
     * @brief Update the LCD display with new data.
     * @param fb Pointer to the framebuffer containing the data to be displayed.
     * @param len Length of the data to be displayed.
     */
    void update(unsigned short* fb, int len);

    /**
     * @brief Destructor for the ParLCD class.
     */
    ~ParLCD();
};
