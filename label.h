#pragma once
#include "component.h"
#include <string>

class Label : public Component
{
private:
    uint16_t font_size_;
    std::string text_;
    rgb565_t active_color;
    float* attached_value;
    
public:
    // ctors
    using Component::Component;
    Label(uint16_t x, uint16_t y, uint16_t height, uint16_t width, std::string text);
    // setters
    void set_text(std::string text);
    void set_font_size(uint16_t font_sizes);
    static void set_render_handler(void (*render_handler)(Component*));
    void set_active_color(rgb565_t color);
    void attach_value(float* value); 
    // getters
    std::string get_text() const;
    uint16_t get_font_size() const;
    rgb565_t get_active_color() const;
    // virtual method implementation
    void render();
protected:
    static RenderHandler render_handler_label;
};