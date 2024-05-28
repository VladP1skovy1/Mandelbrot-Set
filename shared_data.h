#pragma once
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
} data_t;

typedef struct {
    float zoom;
    float trans_x;
    float trans_y;
} set_t;

extern data_t shared_data;
extern set_t set_data;

