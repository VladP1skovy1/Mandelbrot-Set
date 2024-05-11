#include "component.h"

Component::Component()
{
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->color = COLORS::BLACK;
}

Component::Component(uint16_t x, uint16_t y) : Component()
{
    this->x = x;
    this->y = y;
}

Component::Component(uint16_t x, uint16_t y, uint16_t width, uint16_t height) : Component(x, y)
{
    this->width = width;
    this->height = height;
}

uint16_t Component::get_pos_x() const
{
    return x;
}

uint16_t Component::get_pos_y() const
{
    return y;
}

uint16_t Component::get_width() const
{
    return width;
}

uint16_t Component::get_height() const
{
    return height;
}

void Component::set_color(uint16_t color)
{
    this->color = color;
}
