#include "component.h"

Component::Component()
{
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
}

Component::Component(uint16_t x, uint16_t y) : Component()
{
    this->x = x;
    this->y = y;
}

Component::Component(uint16_t x, uint16_t y, uint16_t width, uint16_t height) : 
Component(x, y)
{
    this->width = width;
    this->height = height;
}
