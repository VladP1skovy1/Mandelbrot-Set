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
    scene->set_dir_turn_handler([](int knob, int dir){
        if(knob == 2) {
            shared_data.active_component_index = 
                    ((shared_data.active_component_index + dir) % 2);
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
    scene->set_dir_turn_handler([](int knob, int dir){
        if(knob == 2) {
            shared_data.active_component_index = 
                    ((shared_data.active_component_index + dir) % 4);
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
    scene->add_component(new Label(40, 130, 30, 200, "Julias set"));
    scene->add_component(new Label(40, 160, 30, 200, "Sierpinski triangle"));
    scene->set_press_handler([](int knob){
        switch (knob)
        {
        case 0:
            shared_data.scene = SETTINGS;
            break;
        case 2:
            set_data.init();
            shared_data.set = shared_data.active_component_index;
            shared_data.scene = SETTINGS;
            break;
        default:
            break;
        }
    });

    scene->set_dir_turn_handler([](int knob, int dir){
        if(knob == 2) {
            shared_data.active_component_index = 
                    ((shared_data.active_component_index + dir) % 3);
        }
    });
    return scene;
}

Scene* SceneBuilder::create_main_scene(){
    Scene* scene = new Scene();
    Set* set = new Set(0, 0, 480, 320);
    set_data.refresh();
    set->update();
    scene->add_component(set);
    scene->set_press_handler([](int knob){
        if(knob == 0) {
            shared_data.led_fired = 0;
            shared_data.scene = MENU;
        }
    });
    
    scene->set_dir_turn_handler([](int knob, int dir) {
        shared_data.set_params_changed = 1;
        switch (knob)
        {
        case 0:
            printf("Knob 0 turned %d\n", dir);
            set_data.min_x += set_data.d_x * dir * 20;
            break;
        case 1:
            printf("Knob 1 turned %d\n", dir);
            set_data.min_y += set_data.d_y * dir * 20;
            break;
        case 2:
            printf("Knob 2 turned %d\n", dir);
            set_data.d_x *= (dir > 0 ? 1.1 : 0.9);
            set_data.d_y *= (dir > 0 ? 1.1 : 0.9);
            break;
        
        default:
            break;
        }
    });
    return scene;
}



