#pragma once
#include "colors.h"
#define DEFAULT_MIN_X -1
#define DEFAULT_D_X 0.01
#define DEFAULT_MIN_Y -1
#define DEFAULT_D_Y 0.01
#define DEFAULT_X_CONSTANT 0.274
#define DEFAULT_Y_CONSTANT -0.008
#define DEFAULT_RESOLUTION 1
#define STANDARD_COLOR WHITE

enum STATES{
    MENU,
    SETTINGS,
    CHANGE_COLOR,
    CHANGE_VALUE,
    CHANGE_SET,
    MAIN
};

enum SETS {
    Mandelbrot,
    Julia,
    Serpinski
};

typedef struct {
    int scene;
    int active_component_index;
    int set;
    int led_fired;
    int light_rgbs;
    int set_params_changed;
} data_t;

typedef struct SetData {
    float resolution;
    float min_x;
    float min_y;
    float d_x;
    float d_y;
    float constant_x;
    float constant_y;
    rgb565_t color;

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

    void refresh() {
        min_x = DEFAULT_MIN_X;
        min_y = DEFAULT_MIN_Y;
        d_x = DEFAULT_D_X;
        d_y = DEFAULT_D_Y;
    }
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

extern data_t shared_data;
extern set_t set_data;

