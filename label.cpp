#include "label.h"

Label::RenderHandler Label::render_handler_label = nullptr;

Label::Label(uint16_t x, uint16_t y, uint16_t height, uint16_t width, std::string text) :
Label(x, y, width, height)
{
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

std::string Label::get_text() const
{
    return text_;
}

uint16_t Label::get_font_size() const
{
    return font_size_;
}

void Label::render()
{
  this->render_handler_label(this);
}
