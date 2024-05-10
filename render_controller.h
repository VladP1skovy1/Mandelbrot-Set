#include "parlcd.h"
#include "label.h"
#include "font_types.h"

class RenderController
{
private:
    int width;
    int height;
    unsigned short *fb;
    font_descriptor_t *fdes;
    ParLCD *parlcd;

    void draw_pixel(int x, int y, unsigned short color);

    void draw_pixel_big(int x, int y, int scale ,unsigned short color);

    int char_width(int ch);

    void draw_char(int x, int y, int scale, char ch, unsigned short color);

public:
    RenderController(int width, int height);
    ~RenderController();

    static void render_label(Label *lbl);
};
