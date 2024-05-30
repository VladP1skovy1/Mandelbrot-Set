/**
 * @file shared_data.h
 * @brief Header file containing shared data definitions and constants.
 */

#pragma once
#include "colors.h"

/// Default and constant values for fractal set calculations
#define DEFAULT_MIN_X -1
#define DEFAULT_D_X 0.01
#define DEFAULT_MIN_Y -1
#define DEFAULT_D_Y 0.01
#define DEFAULT_X_CONSTANT 0.274
#define DEFAULT_Y_CONSTANT -0.008
#define MIN_X_CONSTANT -0.5
#define MAX_X_CONSTANT 0.5
#define MIN_Y_CONSTANT -0.5
#define MAX_Y_CONSTANT 0.5
#define DEFAULT_RESOLUTION 0.2
#define MIN_RESOLUTION 0.01
#define MAX_RESOLUTION 1
#define STANDARD_COLOR WHITE

/**
 * @enum STATES
 * @brief Enumeration of possible states in the application.
 */
enum STATES {
    MENU,               /**< Menu state */
    SETTINGS,           /**< Settings state */
    CHANGE_COLOR,       /**< Change color state */
    CHANGE_VALUE,       /**< Change value state */
    CHANGE_SET,         /**< Change set state */
    CHANGE_RESOLUTION,  /**< Change resolution state */
    MAIN                /**< Main state */
};

/**
 * @enum SETS
 * @brief Enumeration of fractal sets.
 */
enum SETS {
    Mandelbrot, /**< Mandelbrot set */
    Julia      /**< Julia set */
};

/**
 * @struct data_t
 * @brief Structure to hold shared application data.
 */
typedef struct {
    int scene;                  /**< Current scene */
    int active_component_index; /**< Index of the active component */
    int set;                    /**< Current set */
    int led_fired;              /**< LED fired status */
    int light_rgbs;             /**< RGB LEDs status */
    int set_params_changed;     /**< Set parameters changed status */
} data_t;

/**
 * @struct SetData
 * @brief Structure to hold parameters for fractal sets.
 */
typedef struct SetData {
    float resolution;   /**< Resolution of the set */
    float min_x;        /**< Minimum x-coordinate */
    float min_y;        /**< Minimum y-coordinate */
    float d_x;          /**< Delta x for calculations */
    float d_y;          /**< Delta y for calculations */
    float constant_x;   /**< Constant x-coordinate for Julia set */
    float constant_y;   /**< Constant y-coordinate for Julia set */
    rgb565_t color;     /**< Color of the set */

    /**
     * @brief Initialize the set data with default values.
     */
    void init() { 
        resolution = DEFAULT_RESOLUTION;
        min_x = DEFAULT_MIN_X; 
        min_y = DEFAULT_MIN_Y; 
        d_x = DEFAULT_D_X; 
        d_y = DEFAULT_D_Y;
        constant_x = DEFAULT_X_CONSTANT;
        constant_y = DEFAULT_Y_CONSTANT;
        color = STANDARD_COLOR;
    }

    /**
     * @brief Refresh the set data to default min and delta values.
     */
    void refresh() {
        min_x = DEFAULT_MIN_X;
        min_y = DEFAULT_MIN_Y;
        d_x = DEFAULT_D_X;
        d_y = DEFAULT_D_Y;
    }

    /**
     * @brief Assignment operator to copy set data.
     * @param data Reference to the source SetData structure.
     */
    void operator=(const SetData &data) {
        resolution = data.resolution;
        min_x = data.min_x;
        min_y = data.min_y;
        d_x = data.d_x;
        d_y = data.d_y;
        constant_x = data.constant_x;
        constant_y = data.constant_y;
        color = data.color;
    }
} set_t;

extern data_t shared_data; /**< Extern declaration of shared application data */
extern set_t set_data;     /**< Extern declaration of fractal set parameters */
