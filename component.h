#include <inttypes.h>
#include "render_controller.h"
#pragma once

class Component
{
protected:
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;

public:
    Component();
    Component(uint16_t x, uint16_t y);
    Component(uint16_t x, uint16_t y, uint16_t width, uint16_t height);
    virtual void render();
    ~Component();
};