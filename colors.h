/**
 * @file colors.h
 * @brief Header file containing color definitions and RGB565 structure for color manipulation.
 */

#pragma once
#include <cstdint>

/**
 * @enum COLORS
 * @brief Enumeration of colors with their corresponding RGB565 values.
 */
enum COLORS {
    RED = 0xf800,       /**< RGB565 value for red color */
    GREEN = 0x27a627,   /**< RGB565 value for green color */
    BLUE = 0x001f,      /**< RGB565 value for blue color */
    WHITE = 0xffff,     /**< RGB565 value for white color */
    BLACK = 0x0000,     /**< RGB565 value for black color */
    YELLOW = 0xffe0,    /**< RGB565 value for yellow color */
    PURPLE = 0xf81f,    /**< RGB565 value for purple color */
    CYAN = 0x07ff,      /**< RGB565 value for cyan color */
    DARK_GREEN = 0x007800 /**< RGB565 value for dark green color */
};

/**
 * @struct RGB565
 * @brief Structure to represent a color in RGB565 format.
 */
typedef struct RGB565 {
    unsigned int blue : 5;   /**< Blue component of the color (5 bits) */
    unsigned int green : 6;  /**< Green component of the color (6 bits) */
    unsigned int red : 5;    /**< Red component of the color (5 bits) */

    /**
     * @brief Default constructor initializing color to black.
     */
    RGB565() : blue(0), green(0), red(0) {}

    /**
     * @brief Constructor to initialize RGB565 from a 16-bit color value.
     * @param color 16-bit color value in RGB565 format.
     */
    RGB565(uint16_t color) {
        blue = (color & 0x001F);
        green = (color & 0x07E0) >> 5;
        red = (color & 0xF800) >> 11;
    }

    /**
     * @brief Overloaded multiplication operator to scale the color by an integer factor.
     * @param factor Scaling factor.
     * @return Scaled RGB565 color.
     */
    RGB565 operator*(int factor) const {
        RGB565 result;
        result.blue = blue * factor;
        result.green = green * factor;
        result.red = red * factor;
        return result;
    }

    /**
     * @brief Overloaded multiplication operator to scale the color by a floating-point factor.
     * @param factor Scaling factor.
     * @return Scaled RGB565 color.
     */
    RGB565 operator*(float factor) const {
        RGB565 result;
        result.blue = blue * factor;
        result.green = green * factor;
        result.red = red * factor;
        return result;
    }

    /**
     * @brief Overloaded conversion operator to convert RGB565 to a 16-bit color value.
     * @return 16-bit color value in RGB565 format.
     */
    operator uint16_t() const {
        return (red << 11) | (green << 5) | blue;
    }
} rgb565_t;
