#pragma once
#include <algorithm>
#include <vector>
#include <complex>
#include <functional>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include "shared_data.h"
#include "component.h"

class Set : public Component {
    unsigned char* buffer = nullptr;
    set_t params;
    SETS set;

    public:
    using Component::Component;
    Set(int x, int y, int width, int height);
    void init_mandelbrot();
    void init_julia_for_region(int start, int end);
    void init_mandelbrot_for_region(int start, int end);
    void render();
    int get_max_value() const;
    const unsigned char *get_buffer() const;

    static void  set_render_handler(RenderHandler render_handler);
    void update();
    ~Set();

protected:
    static RenderHandler render_handler_set;
};