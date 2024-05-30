/**
 * @file render_controller.h
 * @brief Header file for the RenderController class.
 */

#pragma once
#include "math.h"
#include "font_types.h"
#include "component.h"
#include "label.h"
#include "set.h"
#include "parlcd.h"
#include "colors.h"
#include <string.h>

/**
 * @class RenderController
 * @brief A singleton class to manage rendering operations on the LCD display.
 */
class RenderController {
private:
    ParLCD* parlcd;           /**< Pointer to the ParLCD instance */
    unsigned short* fb;       /**< Framebuffer for the display */
    int width;                /**< Width of the display */
    int height;               /**< Height of the display */

    static RenderController* instance;   /**< Singleton instance of the RenderController */
    static const font_descriptor_t *fdes; /**< Font descriptor */

    /**
     * @brief Calculate the width of a character.
     * @param ch Character to calculate the width for.
     * @return Width of the character.
     */
    static int char_width(int ch);

    /**
     * @brief Draw a pixel with scaling.
     * @param x X position.
     * @param y Y position.
     * @param scale Scaling factor.
     * @param color Color of the pixel.
     */
    void draw_pixel_big(int x, int y, int scale, unsigned short color);

    /**
     * @brief Draw a character on the display.
     * @param x X position.
     * @param y Y position.
     * @param scale Scaling factor.
     * @param ch Character to draw.
     * @param color Color of the character.
     */
    void draw_char(int x, int y, int scale, char ch, unsigned short color);

    /**
     * @brief Draw a pixel on the display.
     * @param x X position.
     * @param y Y position.
     * @param color Color of the pixel.
     */
    void draw_pixel(int x, int y, unsigned short color);

public:
    // Deleted constructors

    /**
     * @brief Deleted copy constructor to prevent copying.
     * @param other Reference to another RenderController instance.
     */
    RenderController(RenderController& other) = delete;

    /**
     * @brief Deleted assignment operator to prevent assignment.
     * @param other Reference to another RenderController instance.
     */
    void operator=(const RenderController&) = delete;

    /**
     * @brief Get the singleton instance of the RenderController.
     * @return Pointer to the singleton instance.
     */
    static RenderController* get_instance();

    /**
     * @brief Render a label component.
     * @param comp Pointer to the label component.
     */
    static void render_label(Component* comp);

    /**
     * @brief Render a set component.
     * @param comp Pointer to the set component.
     */
    static void render_set(Component* comp);

    /**
     * @brief Render the display.
     */
    void render();

    /**
     * @brief Refresh the display.
     */
    void refresh();

    /**
     * @brief Constructor for the RenderController.
     */
    RenderController();

    /**
     * @brief Destructor for the RenderController.
     */
    ~RenderController();
};
