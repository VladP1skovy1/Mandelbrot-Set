#include "render_controller.h"

RenderController *RenderController::instance = nullptr;
const font_descriptor_t *RenderController::fdes = &font_winFreeSystem14x16;

void RenderController::draw_pixel(int x, int y, unsigned short color)
{
    if (x >= 0 && x < width && 
        y >= 0 && y < height) {
        fb[x + width * y] = color;
    }
}

void RenderController::draw_pixel_big(int x, int y, int scale, unsigned short color)
{
    int i, j;
    for (i = 0; i < scale; i++) {
        for (j = 0; j < scale; j++) {
            draw_pixel(x + i, y + j, color);
        }
    }
}

int RenderController::char_width(int ch)
{
    int width;
    if (!fdes->width) {
        width = fdes->maxwidth;
    }
    else {
        width = fdes->width[ch - fdes->firstchar];
    }
    return width;
}

void RenderController::draw_char(int x, int y, int scale, char ch, unsigned short color)
{
    int w = char_width(ch);
    const font_bits_t *ptr;
    if ((ch >= fdes->firstchar) && (ch - fdes->firstchar < fdes->size))
    {
        if (fdes->offset)
        {
            ptr = &fdes->bits[fdes->offset[ch - fdes->firstchar]];
        }
        else
        {
            int bw = (fdes->maxwidth + 15) / 16;
            ptr = &fdes->bits[(ch - fdes->firstchar) * bw * fdes->height];
        }
        int i, j;
        for (i = 0; i < fdes->height; i++)
        {
            font_bits_t val = *ptr;
            for (j = 0; j < w; j++)
            {
                if ((val & 0x8000) != 0)
                {
                    draw_pixel_big(x + scale * j, y + scale * i, scale, color);
                }
                val <<= 1;
            }
            ptr++;
        }
    }
}

RenderController *RenderController::get_instance()
{
    if(instance == nullptr) {
        instance = new RenderController();
    }
    return instance;
}

void RenderController::render_label(Component* comp)
{
    Label* lbl = dynamic_cast<Label*>(comp);
    RenderController* ren_con = RenderController::get_instance(); 
    std::string text = lbl->get_text();
    int x_offset = lbl->get_pos_x();
    int y_offset = lbl->get_pos_y();
    int lbl_height = lbl->get_height();
    int lbl_width = lbl->get_width();
    rgb565_t bg_color = lbl->get_bg_color();
    if(lbl->is_active()) {
        bg_color = lbl->get_active_color() * 2;
    }
    for (size_t i = 0; i < lbl_height; i++) {
        for (size_t j = 0; j < lbl_width; j++) {
            ren_con->draw_pixel(j + x_offset, i + y_offset, bg_color);
        }
    
    }

    int scale = lbl->get_font_size();
    int text_length = text.size();
    int text_width = 0;
    int text_height = 16 * scale;
    for (int i = 0; i < text_length; i++)
    {
        text_width += char_width(text[i] + 1) * scale;
    }

    int color = comp->get_color();
    x_offset = x_offset - text_width/2 + lbl_width/2;
    y_offset = y_offset - text_height/2 + lbl_height/2;
    

    for (int i = 0; i < text_length; i++) {
      ren_con->draw_char(x_offset, y_offset, scale, text[i], color);
      x_offset += ((char_width(text[i]) + 1) * scale);
    }
}

void RenderController::render_set(Component* comp) {
    Set* set = dynamic_cast<Set*>(comp);
    RenderController* ren_con = RenderController::get_instance();
    rgb565_t color = set->get_color();
    int max_value = set->get_max_value();

    if(shared_data.set_params_changed) {
        set->update();
        shared_data.set_params_changed = false;
    }

    int width = set->get_width();
    int height = set->get_height();
    const unsigned char *buffer = set->get_buffer();
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            int k = buffer[i * width + j];
            ren_con->draw_pixel(j, i, color * ((float)k / max_value));
        }
    }
}

void RenderController::render()
{
    this->parlcd->update(fb, width * height);
    this->refresh();
}

void RenderController::refresh()
{
    memset(fb, 0, width * height * 2);
}

RenderController::RenderController()
{
    parlcd = ParLCD::GetInstance();
    this->width = PARLCD_WIDTH;
    this->height = PARLCD_HEIGHT;
    fb = new unsigned short[width * height * 2];
    Label::set_render_handler(RenderController::render_label);
    Set::set_render_handler(RenderController::render_set);
}
