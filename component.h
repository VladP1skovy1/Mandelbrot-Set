/**
 * @file component.h
 * @brief Header file for the Component class.
 */

#pragma once
#include <inttypes.h>
#include "colors.h"

/**
 * @class Component
 * @brief A base class for UI components.
 */
class Component
{
protected:
    uint16_t x;           /**< X position of the component */
    uint16_t y;           /**< Y position of the component */
    uint16_t width;       /**< Width of the component */
    uint16_t height;      /**< Height of the component */
    rgb565_t color;       /**< Foreground color of the component */
    rgb565_t bg_color;    /**< Background color of the component */
    bool is_active_ = false; /**< Active state of the component */

public:
    /**
     * @brief Typedef for the render handler function pointer.
     */
    typedef void (*RenderHandler)(Component*);

    // Constructors

    /**
     * @brief Default constructor.
     */
    Component();

    /**
     * @brief Constructor with position.
     * @param x X position of the component.
     * @param y Y position of the component.
     */
    Component(uint16_t x, uint16_t y);

    /**
     * @brief Constructor with position and size.
     * @param x X position of the component.
     * @param y Y position of the component.
     * @param width Width of the component.
     * @param height Height of the component.
     */
    Component(uint16_t x, uint16_t y, uint16_t width, uint16_t height);

    // Getters

    /**
     * @brief Get the X position of the component.
     * @return X position.
     */
    uint16_t get_pos_x() const;

    /**
     * @brief Get the Y position of the component.
     * @return Y position.
     */
    uint16_t get_pos_y() const;

    /**
     * @brief Get the width of the component.
     * @return Width.
     */
    uint16_t get_width() const;

    /**
     * @brief Get the height of the component.
     * @return Height.
     */
    uint16_t get_height() const;

    /**
     * @brief Get the foreground color of the component.
     * @return Foreground color.
     */
    rgb565_t get_color() const;

    /**
     * @brief Get the background color of the component.
     * @return Background color.
     */
    rgb565_t get_bg_color() const;

    /**
     * @brief Check if the component is active.
     * @return True if active, false otherwise.
     */
    bool is_active() const;

    // Setters

    /**
     * @brief Set the background color of the component.
     * @param color Background color.
     */
    void set_bg_color(rgb565_t color);

    /**
     * @brief Set the foreground color of the component.
     * @param color Foreground color.
     */
    void set_color(rgb565_t color);

    /**
     * @brief Set the active state of the component.
     * @param active Active state.
     */
    void set_active(bool active);

    /**
     * @brief Set the render handler for the component.
     * @param render_handler Function pointer to the render handler.
     */
    static void set_render_handler(void (*render_handler)(Component*));

    /**
     * @brief Render the component. Must be implemented in inherited classes.
     */
    virtual void render();

    /**
     * @brief Destructor.
     */
    ~Component() {};

protected:
    static RenderHandler render_handler; /**< Static render handler for all components */
};
