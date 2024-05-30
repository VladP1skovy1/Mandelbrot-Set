/**
 * @file label.h
 * @brief Header file for the Label class.
 */

#pragma once
#include "component.h"
#include <string>

/**
 * @class Label
 * @brief A class representing a text label in the UI.
 */
class Label : public Component {
private:
    uint16_t font_size_;       /**< Font size of the label */
    std::string text_;         /**< Text of the label */
    rgb565_t active_color;     /**< Active color of the label */
    float* attached_value;     /**< Pointer to a value attached to the label */

public:
    // Constructors
    using Component::Component;

    /**
     * @brief Constructor with position and size, and initial text.
     * @param x X position of the label.
     * @param y Y position of the label.
     * @param width Width of the label.
     * @param height Height of the label.
     * @param text Initial text of the label.
     */
    Label(uint16_t x, uint16_t y, uint16_t width, uint16_t height, std::string text);

    // Setters

    /**
     * @brief Set the text of the label.
     * @param text New text for the label.
     */
    void set_text(std::string text);

    /**
     * @brief Set the font size of the label.
     * @param font_size New font size.
     */
    void set_font_size(uint16_t font_size);

    /**
     * @brief Set the render handler for the label.
     * @param render_handler New render handler.
     */
    static void set_render_handler(void (*render_handler)(Component *));

    /**
     * @brief Set the active color of the label.
     * @param color New active color.
     */
    void set_active_color(rgb565_t color);

    /**
     * @brief Attach a value to the label.
     * @param value Pointer to the value to be attached.
     */
    void attach_value(float* value);

    // Getters

    /**
     * @brief Get the text of the label.
     * @return Current text of the label.
     */
    std::string get_text() const;

    /**
     * @brief Get the font size of the label.
     * @return Current font size.
     */
    uint16_t get_font_size() const;

    /**
     * @brief Get the active color of the label.
     * @return Current active color.
     */
    rgb565_t get_active_color() const;

    // Virtual method implementation

    /**
     * @brief Render the label.
     */
    void render() override;

protected:
    static RenderHandler render_handler_label; /**< Static render handler for label */
};
