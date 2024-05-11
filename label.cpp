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
  std::string text = this->get_text();
  int x_offset = this->get_pos_x();
  int y_offset = this->get_pos_y();
  ParLCD* parlcd = ParLCD::GetInstance();
  for (size_t i = 0; i < this->get_height(); i++)
  {
    for (size_t j = 0; j < this->get_width(); j++)
    {
      draw_pixel(i + x_offset, j + y_offset, 0x07e0, parlcd);
    }
    
  }
  

  int scale = this->get_font_size();

  for (int i = 0; i < text.size(); i++) {
    draw_char(x_offset, y_offset, 2, text[i], 0xf800, parlcd);
    x_offset += (char_width(text[i]) * scale + SPACING);
  }
}
