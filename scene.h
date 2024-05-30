/**
 * @file scene.h
 * @brief Header file for the Scene class.
 */

#pragma once
#include <memory>
#include <vector>
#include <stdio.h>
#include "component.h"

/**
 * @class Scene
 * @brief A class representing a scene containing multiple components.
 */
class Scene {
private:
    std::vector<std::unique_ptr<Component>> components; /**< Vector of unique pointers to components */
    int active_component_index; /**< Index of the currently active component */

public:
    /**
     * @brief Typedef for the press handler function pointer.
     */
    typedef void (*PressHandler)(int);

    /**
     * @brief Typedef for the turn directed handler function pointer.
     */
    typedef void (*TurnDirectedHandler)(int, int);

    /**
     * @brief Typedef for the turn handler function pointer.
     */
    typedef void (*TurnHandler)(int, int, int);

    /**
     * @brief Constructor for the Scene class.
     */
    Scene();

    /**
     * @brief Add a component to the scene.
     * @param comp Pointer to the component to add.
     */
    void add_component(Component* comp);

    /**
     * @brief Render the scene.
     */
    void render();

    /**
     * @brief Set the active component by index.
     * @param index Index of the component to set as active.
     */
    void set_active_component(int index);

    /**
     * @brief Handle a knob press event.
     * @param knob ID of the knob that was pressed.
     */
    void knob_pressed(int knob);

    /**
     * @brief Handle a knob turn event.
     * @param knob ID of the knob that was turned.
     * @param old_value Previous value of the knob.
     * @param new_value New value of the knob.
     */
    void knob_turned(int knob, int old_value, int new_value);

    /**
     * @brief Handle a directed knob turn event.
     * @param knob ID of the knob that was turned.
     * @param direction Direction of the turn.
     */
    void knob_turned_directed(int knob, int direction);

    /**
     * @brief Set the press handler for the scene.
     * @param press_handler Function pointer to the press handler.
     */
    void set_press_handler(PressHandler press_handler);

    /**
     * @brief Set the turn handler for the scene.
     * @param turn_handler Function pointer to the turn handler.
     */
    void set_turn_handler(TurnHandler turn_handler);

    /**
     * @brief Set the directed turn handler for the scene.
     * @param dir_tur_handler Function pointer to the directed turn handler.
     */
    void set_dir_turn_handler(TurnDirectedHandler dir_tur_handler);

private:
    PressHandler press_handler; /**< Function pointer to the press handler */
    TurnHandler turn_handler; /**< Function pointer to the turn handler */
    TurnDirectedHandler dir_tur_handler; /**< Function pointer to the directed turn handler */
};
