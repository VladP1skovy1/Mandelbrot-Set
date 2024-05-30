/**
 * @file scene_builder.h
 * @brief Header file for the SceneBuilder class.
 */

#pragma once
#include "leds_controller.h"
#include "shared_data.h"
#include "scene.h"
#include "label.h"

/**
 * @class SceneBuilder
 * @brief A class to build different scenes.
 */
class SceneBuilder {
public:
    /**
     * @brief Create a scene based on the scene ID.
     * @param scene_id ID of the scene to create.
     * @return Pointer to the created scene.
     */
    static Scene* create_scene(int scene_id);

    /**
     * @brief Create the menu scene.
     * @return Pointer to the menu scene.
     */
    static Scene* create_menu_scene();

    /**
     * @brief Create the change resolution scene.
     * @return Pointer to the change resolution scene.
     */
    static Scene* create_change_resolution_scene();

    /**
     * @brief Create the settings scene.
     * @return Pointer to the settings scene.
     */
    static Scene* create_settings_scene();

    /**
     * @brief Create the change color scene.
     * @return Pointer to the change color scene.
     */
    static Scene* create_change_color_scene();

    /**
     * @brief Create the change value scene.
     * @return Pointer to the change value scene.
     */
    static Scene* create_change_value_scene();

    /**
     * @brief Create the change set scene.
     * @return Pointer to the change set scene.
     */
    static Scene* create_change_set_scene();

    /**
     * @brief Create the main scene.
     * @return Pointer to the main scene.
     */
    static Scene* create_main_scene();
};
