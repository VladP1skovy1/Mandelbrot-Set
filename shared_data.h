#pragma once
#define DEFAULT_MIN_X -1
#define DEFAULT_D_X 0.01
#define DEFAULT_MIN_Y -1
#define DEFAULT_D_Y 0.01

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
    Serpinski
};

typedef struct {
    int scene;
    int active_component_index;
    int set;
    int led_fired;
    int set_params_changed;
} data_t;

typedef struct SetData {
    float min_x;
    float min_y;
    float d_x;
    float d_y;
    void refresh() { 
        min_x = DEFAULT_MIN_X; 
        min_y = DEFAULT_MIN_Y; 
        d_x = DEFAULT_D_X; 
        d_y = DEFAULT_D_Y;
    }
} set_t;

extern data_t shared_data;
extern set_t set_data;

