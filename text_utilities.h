#pragma once
#include "font_types.h"
#include "parlcd.h"
#define SPACING 5

void draw_pixel_big(int x, int y, int scale ,unsigned short color, ParLCD* parlcd);

int char_width(int ch);

void draw_char(int x, int y, int scale, char ch, unsigned short color, ParLCD* parlcd);

void draw_pixel(int x, int y, unsigned short color, ParLCD* parlcd);