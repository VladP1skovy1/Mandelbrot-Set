#include "label.h"

Label::RenderHandler Label::render_handler_label = nullptr;

Label::Label(uint16_t x, uint16_t y, uint16_t height, uint16_t width, std::string text) :
Label(x, y, width, height)
{
    this->attached_value = nullptr;
    this->text_ = text;
    this->font_size_ = 1;
}

void Label::set_text(std::string text)
{
    this->text_ = text;
}

void Label::set_font_size(uint16_t font_size)
{
    this->font_size_ = font_size;
}

void Label::set_render_handler(void (*render_handler)(Component *))
{
    Label::render_handler_label = render_handler;
}

void Label::set_active_color(rgb565_t color)
{
    this->active_color = color;
}

void Label::attach_value(float *value)
{
    printf("Attached value\n");
    attached_value = value;
}

std::string Label::get_text() const
{
    return text_;
}

uint16_t Label::get_font_size() const
{
    return font_size_;
}

rgb565_t Label::get_active_color() const
{
    return active_color;
}

void Label::render()
{
    if(attached_value != nullptr) {
        this->text_ = std::to_string(*attached_value);
    }
    if(render_handler_label != nullptr) {
        render_handler_label(this);
    }
}
