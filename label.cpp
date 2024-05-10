#include "label.h"

Label::Label(uint16_t x, uint16_t y, uint16_t height, uint16_t width, std::string text) :
Label(x, y, width, height)
{
    this->text_ = text;
}

void Label::set_text(std::string text)
{
    this->text_ = text;
}

void Label::set_font_size(uint16_t font_size)
{
    this->font_size_ = font_size;
}

void Label::render()
{
    RenderController::render_label(this);
}
