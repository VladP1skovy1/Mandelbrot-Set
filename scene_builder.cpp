#include "scene_builder.h"
#include "set.h"

Scene *SceneBuilder::create_scene(int scene_id)
{
    Scene *scene = nullptr;
    switch ((STATES)scene_id)
    {
    case MENU:
        scene = create_menu_scene();
        break;
    case SETTINGS:
        scene = create_settings_scene();
        break;
    case CHANGE_COLOR:
        scene = create_change_color_scene();
        break;
    case CHANGE_VALUE:
        scene = create_change_value_scene();
        break;
    case CHANGE_SET:
        scene = create_change_set_scene();
        break;
    case MAIN:
        scene = create_main_scene();
        break;
    default:
        break;
    }
    return scene;
}

Scene *SceneBuilder::create_menu_scene()
{
    Scene* scene = new Scene();
    Label* lbl = new Label(0, 80, 80, 480, "Set Generator");
    Label* lbl2 = new Label(0, 170, 80, 480, "Settings");
    lbl->set_color(WHITE);
    lbl2->set_color(WHITE);
    lbl->set_active_color(GREEN);
    lbl2->set_active_color(GREEN);
    lbl->set_font_size(3);
    lbl2->set_font_size(2);
    lbl->set_bg_color(DARK_GREEN);
    lbl2->set_bg_color(DARK_GREEN);
    scene->add_component(lbl);
    scene->add_component(lbl2);
    printf("CREATING MAIN MENU SCENE \n");
    scene->set_press_handler([](int knob){
        if(knob == 2) {
            printf("Knob 2 pressed\n");
            switch (shared_data.active_component_index)
            {
            case 0:
                shared_data.scene = MAIN;
                break;
            case 1:
                shared_data.scene = SETTINGS;
                break;
            default:
                break;
            }
        }
    });
    scene->set_turn_handler([](int knob, int old_value, int new_value){
        if(knob == 2) {
            printf("New value: %d\n", new_value);
            shared_data.active_component_index = ((new_value / 16) % 2);
        }
    });
    scene->set_active_component(shared_data.active_component_index);
    return scene;
}

Scene* SceneBuilder::create_settings_scene(){

    Scene* scene = new Scene();
    scene->add_component(new Label(40, 130, 30, 200, "Change fractal"));
    scene->add_component(new Label(40, 160, 30, 200, "Change color"));
    scene->add_component(new Label(40, 190, 30, 200, "Change C value"));
    scene->add_component(new Label(40, 210, 30, 200, "To menu"));
    scene->set_press_handler([](int knob) {
        if(knob == 2) {
            switch (shared_data.active_component_index)
            {
            case 0:
                shared_data.scene = CHANGE_SET;
                break;
            case 1:
                shared_data.scene = CHANGE_COLOR;
                break;
            case 2:
                shared_data.scene = CHANGE_VALUE;
                break;
            case 3:
                shared_data.scene = MENU;
                break;
            default:
                break;
            }
        }
    });
    scene->set_turn_handler([](int knob, int old_value, int new_value){
        if(knob == 2) {
            shared_data.active_component_index = ((new_value / 16) % 4);
        }
    });
    scene->set_active_component(0);
    return scene;
}

Scene* SceneBuilder::create_change_color_scene(){
    
    Scene* scene = new Scene();
    scene->add_component(new Label(220, 140, 40, 40, "Change color"));
    scene->set_press_handler([](int knob){
        if(knob == 0) {
            shared_data.scene = SETTINGS;
        }
    });
    return scene;
}

Scene* SceneBuilder::create_change_value_scene(){

    Scene* scene = new Scene();
    scene->add_component(new Label(220, 140, 40, 40, "Change value"));
    scene->set_press_handler([](int knob){
        if(knob == 0) {
            shared_data.scene = SETTINGS;
        }
    });
    return scene;
}

Scene* SceneBuilder::create_change_set_scene(){

    Scene* scene = new Scene();
    scene->add_component(new Label(40, 100, 30, 200, "Mandelbrto Set"));
    scene->add_component(new Label(40, 130, 30, 200, "Sierpinski Triangle"));
    scene->add_component(new Label(40, 160, 30, 200, "Koch curve"));
    scene->add_component(new Label(40, 190, 30, 200, "Sierpinski carpet"));
    scene->add_component(new Label(40, 210, 30, 200, "Menger sponge"));
    scene->set_press_handler([](int knob){
        if(knob == 0) {
            shared_data.scene = SETTINGS;
        }
    });

    scene->set_turn_handler([](int knob, int old_value, int new_value){
        if(knob == 2) {
            shared_data.active_component_index = ((new_value / 16) % 5);
        }
    });
    return scene;
}

Scene* SceneBuilder::create_main_scene(){
    Scene* scene = new Scene();
    Set* set = new Set((SETS)shared_data.set);
    scene->add_component(set);
    scene->set_press_handler([](int knob){
        if(knob == 0) {
            shared_data.scene = MENU;
        }
    });
    
    scene->set_turn_handler([](int knob, int old_value, int new_value){
        switch(knob) {
            case 0:
                set_data.trans_x = ((float)new_value / 255) * 50; 
                break;
            case 1:
                set_data.trans_y = ((float)new_value / 255) * 50; 
                break;
            case 2:
                set_data.zoom = ((float)new_value / 255) / 2 + 0.25;
                break;
        }
        shared_data.led_fired = (32 - new_value / 8);
    });
    return scene;
}



