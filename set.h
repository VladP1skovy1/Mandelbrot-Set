/**
 * @file set.h
 * @brief Header file for the Set class.
 */

#pragma once
#include <algorithm>
#include <vector>
#include <complex>
#include <functional>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include "shared_data.h"
#include "component.h"

/**
 * @class Set
 * @brief A class representing a fractal set component.
 */
class Set : public Component {
    unsigned char* buffer = nullptr; /**< Buffer for the fractal set data */
    set_t params; /**< Parameters for the fractal set */
    SETS set; /**< Type of the fractal set */

public:
    using Component::Component;

    /**
     * @brief Constructor for the Set class.
     * @param x X position of the set.
     * @param y Y position of the set.
     * @param width Width of the set.
     * @param height Height of the set.
     */
    Set(int x, int y, int width, int height);

    /**
     * @brief Initialize the Mandelbrot set.
     */
    void init_mandelbrot();

    /**
     * @brief Initialize the Julia set for a specific region.
     * @param start Start index of the region.
     * @param end End index of the region.
     */
    void init_julia_for_region(int start, int end);

    /**
     * @brief Initialize the Mandelbrot set for a specific region.
     * @param start Start index of the region.
     * @param end End index of the region.
     */
    void init_mandelbrot_for_region(int start, int end);

    /**
     * @brief Render the set.
     */
    void render() override;

    /**
     * @brief Get the maximum value of the set.
     * @return Maximum value.
     */
    int get_max_value() const;

    /**
     * @brief Get the buffer containing the set data.
     * @return Pointer to the buffer.
     */
    const unsigned char *get_buffer() const;

    /**
     * @brief Set the render handler for the set.
     * @param render_handler Function pointer to the render handler.
     */
    static void set_render_handler(RenderHandler render_handler);

    /**
     * @brief Update the set.
     */
    void update();

    /**
     * @brief Destructor for the Set class.
     */
    ~Set();

protected:
    static RenderHandler render_handler_set; /**< Static render handler for the set */
};
