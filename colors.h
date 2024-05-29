#pragma once
#include <cstdint>

enum COLORS{
    RED = 0xf800,
    GREEN = 0x27a627,
    BLUE = 0x001f,
    WHITE = 0xffff,
    BLACK = 0x0000,
    YELLOW = 0xffe0,
    PURPLE = 0xf81f,
    CYAN = 0x07ff,
    DARK_GREEN = 0x007800
};

typedef struct RGB565 {
    unsigned int blue : 5;
    unsigned int green : 6;
    unsigned int red : 5;

    RGB565() : blue(0), green(0), red(0) {}
    RGB565(uint16_t color) {
        blue = (color & 0x001F);
        green = (color & 0x07E0) >> 5;
        red = (color & 0xF800) >> 11;
    }
    RGB565 operator*(int factor) const {
        RGB565 result;
        result.blue = blue * factor;
        result.green = green * factor;
        result.red = red * factor;
        return result;
    }
    RGB565 operator*(float factor) const {
        RGB565 result;
        result.blue = blue * factor;
        result.green = green * factor;
        result.red = red * factor;
        return result;
    }
    operator uint16_t() const {
        return (red << 11) | (green << 5) | blue;
    }
} rgb565_t;