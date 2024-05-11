#include "text_utilities.h"

const font_descriptor_t *fdes = &font_winFreeSystem14x16;

void draw_pixel(int x, int y,  unsigned short color, 
                    ParLCD* parlcd) {
    int height = parlcd->get_height();
    int width = parlcd->get_width();
    if (x >= 0 && x < width && 
        y >= 0 && y < height) {
        unsigned short* fb = parlcd->get_buffer();
        fb[x + width * y] = color;
    }
}

void draw_pixel_big(int x, int y, int scale, unsigned short color, 
                        ParLCD* parlcd)
{
    int i, j;
    for (i = 0; i < scale; i++) {
        for (j = 0; j < scale; j++) {
            draw_pixel(x + i, y + j, color, 
                            parlcd);
        }
    }
}

int char_width(int ch)
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

void draw_char(int x, int y, int scale, char ch, unsigned short color,
                 ParLCD* parlcd)
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
                    draw_pixel_big(x + scale * j, y + scale * i, scale, color, 
                                        parlcd);
                }
                val <<= 1;
            }
            ptr++;
        }
    }
}
