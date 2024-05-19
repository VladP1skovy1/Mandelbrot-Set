#include "component.h"

Component::RenderHandler Component::render_handler = nullptr;

Component::Component()
{
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
    this->color = COLORS::WHITE;
    this->bg_color = (color565_t)(COLORS::CYAN)/2;
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

color565_t Component::get_color() const
{
    return color;
}

color565_t Component::get_bg_color() const
{
    return bg_color;
}

bool Component::is_active() const
{
    return is_active_;
}

void Component::set_bg_color(color565_t color)
{
    this->bg_color = color;
}

void Component::set_color(color565_t color)
{
    this->color = color;
}

void Component::set_active(bool active)
{
    this->is_active_ = active;
}

void Component::set_render_handler(void (*render_handler)(Component *))
{
    Component::render_handler = render_handler;
}

void Component::render()
{
    if(this->render_handler) {
        this->render_handler(this);
    }
}
