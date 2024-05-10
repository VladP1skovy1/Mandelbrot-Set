#include "render_controller.h"

void RenderController::draw_pixel(int x, int y, unsigned short color)
{ 
    if (x >= 0 && x < width && y >= 0 && y < height) {
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

RenderController::RenderController(int width, int height)
{
    fb = new unsigned short[width * height * 2];
    fdes = &font_winFreeSystem14x16;
}

RenderController::~RenderController()
{
    if(!fb) delete fb;
}

void RenderController::render_label(Label *lbl)
{
    
}
