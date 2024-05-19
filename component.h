#pragma once
#include <inttypes.h>
#include "colors.h"


class Component
{
protected:
    uint16_t x;
    uint16_t y;
    uint16_t width;
    uint16_t height;
    color565_t color;
    color565_t bg_color;
    bool is_active_ = false;

public:
    typedef void (*RenderHandler)(Component*);
    // ctors
    Component();
    Component(uint16_t x, uint16_t y);
    Component(uint16_t x, uint16_t y, uint16_t width, uint16_t height);

    // getters
    uint16_t get_pos_x() const;
    uint16_t get_pos_y() const;
    uint16_t get_width() const;
    uint16_t get_height() const;
    color565_t get_color() const;
    color565_t get_bg_color() const;
    bool is_active() const;

    //setter
    void set_bg_color(color565_t color);
    void set_color(color565_t color);
    void set_active(bool active);
    static void set_render_handler(void (*render_handler)(Component*));

    // MUST BE IMPLEMENTED IN INHERITED CLASSES
    virtual void render();
    ~Component() {};
private:
    static RenderHandler render_handler;
};