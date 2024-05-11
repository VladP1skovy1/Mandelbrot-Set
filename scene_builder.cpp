#include "scene_builder.h"

Scene* SceneBuilder::create_menu_scene(){
    Scene* scene = new Scene();
    scene->add_component(std::unique_ptr<Component>(new Label(40, 150, 40, 200, "Mandelbrot Set")));
    scene->add_component(std::unique_ptr<Component>(new Label(40, 190, 30, 200, "press to continiue")));
    return scene;
}

Scene* SceneBuilder::create_settings_scene(){

    Scene* scene = new Scene();
    scene->add_component(std::unique_ptr<Component>(new Label(40, 130, 30, 200, "Change fractal")));
    scene->add_component(std::unique_ptr<Component>(new Label(40, 160, 30, 200, "Change color")));
    scene->add_component(std::unique_ptr<Component>(new Label(40, 190, 30, 200, "Change C value")));
    return scene;
}

Scene* SceneBuilder::create_change_color_scene(){
    
    Scene* scene = new Scene();
    scene->add_component(std::unique_ptr<Component>(new Label(220, 140, 40, 40, " ")));
    return scene;
}

Scene* SceneBuilder::create_change_value_scene(){

    Scene* scene = new Scene();
    scene->add_component(std::unique_ptr<Component>(new Label(220, 140, 40, 40, " ")));
    return scene;
}

Scene* SceneBuilder::create_choose_set_scene(){

    Scene* scene = new Scene();
    scene->add_component(std::unique_ptr<Component>(new Label(40, 100, 30, 200, "Mandelbrto Set")));
    scene->add_component(std::unique_ptr<Component>(new Label(40, 130, 30, 200, "Sierpinski Triangle")));
    scene->add_component(std::unique_ptr<Component>(new Label(40, 160, 30, 200, "Koch curve")));
    scene->add_component(std::unique_ptr<Component>(new Label(40, 190, 30, 200, "Sierpinski carpet")));
    scene->add_component(std::unique_ptr<Component>(new Label(40, 210, 30, 200, "Menger sponge")));
    return scene;
}

Scene* SceneBuilder::create_main_scene(){

    Scene* scene = new Scene();
    return scene;
}



