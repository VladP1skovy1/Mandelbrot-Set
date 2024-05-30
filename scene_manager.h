/**
 * @file scene_manager.h
 * @brief Header file for the SceneManager class.
 */

#pragma once
#include <cstdint>
#include "scene.h"
#include "scene_builder.h"

/**
 * @class SceneManager
 * @brief A class to manage scenes in the application.
 */
class SceneManager {
private:
    Scene* current_scene;    /**< Pointer to the current scene */
    int current_scene_id;    /**< ID of the current scene */

public:
    /**
     * @brief Constructor for SceneManager.
     */
    SceneManager();

    /**
     * @brief Update the current scene.
     */
    void update();

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
};
