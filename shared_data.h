#pragma once
enum STATES{
    MENU,
    SETTINGS,
    CHANGE_COLOR,
    CHANGE_VALUE,
    CHANGE_SET,
    MAIN
};

typedef struct {
    int scene;
    int active_component_index;
} data_t;

extern data_t shared_data;

