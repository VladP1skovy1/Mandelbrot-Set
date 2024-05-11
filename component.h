#pragma once
#include <inttypes.h>

class Component
{
protected:
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;

public:
    // ctors
    Component();
    Component(uint16_t x, uint16_t y);
    Component(uint16_t x, uint16_t y, uint16_t width, uint16_t height);

    // getters
    uint16_t get_pos_x() const;
    uint16_t get_pos_y() const;
    uint16_t get_width() const;
    uint16_t get_height() const;

    // MUST BE IMPLEMENTED IN INHERITED CLASSES
    virtual void render() {};
    ~Component() {};
};