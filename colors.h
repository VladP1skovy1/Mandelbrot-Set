#pragma once
#include <cstdint>

enum COLORS{
    RED = 0xf800,
    GREEN = 0x07e0,
    BLUE = 0x001f,
    WHITE = 0xffff,
    BLACK = 0x0000,
    YELLOW = 0xffe0,
    PURPLE = 0xf81f,
    CYAN = 0x07ff
};

typedef struct Color565 {
    unsigned int blue : 5;
    unsigned int green : 6;
    unsigned int red : 5;

    Color565() : blue(0), green(0), red(0) {}
    Color565(uint16_t color) {
        blue = (color & 0x001F);
        green = (color & 0x07E0) >> 5;
        red = (color & 0xF800) >> 11;
    }
    Color565 operator*(int factor) const {
        Color565 result;
        result.blue = blue * factor;
        result.green = green * factor;
        result.red = red * factor;
        return result;
    }
    operator uint16_t() const {
        return (red << 11) | (green << 5) | blue;
    }
} color565_t;