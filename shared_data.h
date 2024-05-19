enum STATES{
    MENU,
    SETTINGS,
    CHANGE_COLOR,
    CHANGE_VALUE,
    CHANGE_SET,
    MAIN
};

typedef struct {
    int app_state;
} data_t;

static data_t shared_data = {
    .app_state = MAIN
};

