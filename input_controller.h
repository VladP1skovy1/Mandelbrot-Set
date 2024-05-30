/**
 * @file input_controller.h
 * @brief Header file for the InputController class and associated types.
 */

#pragma once
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include "scene_manager.h"

/**
 * @enum KNOBS
 * @brief Enumeration for knob values and states.
 */
enum KNOBS {
    RED_KNOB_PRESSED = 0x40000000,    /**< Red knob pressed */
    GREEN_KNOB_PRESSED = 0x20000000,  /**< Green knob pressed */
    BLUE_KNOB_PRESSED = 0x10000000,   /**< Blue knob pressed */
    RED_KNOB_VALUE = 0xff0000,        /**< Red knob value */
    GREEN_KNOB_VALUE = 0xff00,        /**< Green knob value */
    BLUE_KNOB_VALUE = 0xff,           /**< Blue knob value */
};

/**
 * @struct Knbs
 * @brief Structure to represent the state of knobs.
 */
typedef struct Knbs {
    unsigned int blue : 8;          /**< Blue knob value */
    unsigned int green : 8;         /**< Green knob value */
    unsigned int red : 8;           /**< Red knob value */
    unsigned int is_blue_pressed : 1; /**< Blue knob pressed state */
    unsigned int is_green_pressed : 1; /**< Green knob pressed state */
    unsigned int is_red_pressed : 1;   /**< Red knob pressed state */
    unsigned int trash : 5;         /**< Unused bits */

    /**
     * @brief Default constructor initializing knob values and states to 0.
     */
    Knbs() {
        blue = 0;
        green = 0;
        red = 0;
        is_blue_pressed = 0;
        is_green_pressed = 0;
        is_red_pressed = 0;
        trash = 0;
    }

    /**
     * @brief Constructor to initialize Knbs from an unsigned int value.
     * @param val Unsigned int value representing the knob states.
     */
    Knbs(unsigned int val) {
        *(unsigned int *)this = val;
    }

    /**
     * @brief Conversion operator to unsigned int.
     * @return Unsigned int representation of knob states.
     */
    operator unsigned int() const {
        return *(unsigned int *)this;
    }

    /**
     * @brief Assignment operator to set knob states from an unsigned int value.
     * @param val Unsigned int value representing the knob states.
     */
    void operator =(unsigned int val) {
        *(unsigned int *)this = val;
    }
} knobs_t;

/**
 * @class InputController
 * @brief Singleton class to manage input from knobs.
 */
class InputController {
private:
    static InputController* instance; /**< Singleton instance */
    SceneManager *scene_manager;      /**< Pointer to SceneManager */
    unsigned char *mem_base;          /**< Memory base pointer */
    unsigned char *led_mem_base;      /**< LED memory base pointer */
    knobs_t knobs;                    /**< Knob states */

public:
    /**
     * @brief Constructor for InputController.
     */
    InputController();

    /**
     * @brief Update the state of the InputController.
     */
    void update();

    /**
     * @brief Set the SceneManager for the InputController.
     * @param scene_manager Pointer to the SceneManager.
     */
    void set_scene_manager(SceneManager *scene_manager);

    /**
     * @brief Get the singleton instance of the InputController.
     * @return Pointer to the singleton instance.
     */
    static InputController* get_instance();
};
