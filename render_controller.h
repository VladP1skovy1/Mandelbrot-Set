#pragma once
#include "font_types.h"
#include "component.h"
#include "label.h"
#include "parlcd.h"
#include <string.h>

class RenderController
{
private:
    ParLCD* parlcd;
    unsigned short* fb;
    int width;
    int height;

    static RenderController* instance;
    static const font_descriptor_t *fdes;
    static int char_width(int ch);

    void draw_pixel_big(int x, int y, int scale ,unsigned short color);
    void draw_char(int x, int y, int scale, char ch, unsigned short color);
    void draw_pixel(int x, int y, unsigned short color);
    
public:
    // deleted constructors
    RenderController(RenderController& other) = delete;
    void operator=(const RenderController&) = delete;

    static RenderController* get_instance();

    static void render_label(Component* comp);
    void render();
    void refresh();
    RenderController();
    ~RenderController();
};
