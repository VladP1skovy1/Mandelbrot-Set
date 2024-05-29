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
    case CHANGE_RESOLUTION:
        scene = create_change_resolution_scene();
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
    scene->set_press_handler([](int knob){
        if(knob == 2) {
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

Scene* SceneBuilder::create_change_resolution_scene() {
    Scene* scene = new Scene();
    Label* title = new Label(220, 140, 40, 40, "Change resolution");
    title->set_font_size(2);
    title->set_bg_color(BLACK);
    scene->add_component(title);
    scene->add_component(new Label(40, 190, 30, 200, "Resolution"));
    Label* res = new Label(250, 190, 30, 200, "");
    res->attach_value(&set_data.resolution);
    scene->add_component(res);

    scene->set_press_handler([](int knob){
        if(knob == 0) {
            shared_data.scene = SETTINGS;
        }
    });
    
    scene->set_dir_turn_handler([](int knob, int dir) {
        shared_data.set_params_changed = 1;
        switch (knob)
        {
        case 2:
            if(set_data.resolution - 0.01 * dir >= MIN_RESOLUTION && 
            set_data.resolution - 0.01 * dir <= MAX_RESOLUTION) {
                set_data.resolution -= 0.01 * dir;
            }
            break;
        default:
            break;
        }
    });
    return scene;

}

Scene* SceneBuilder::create_settings_scene(){

    Scene* scene = new Scene();
    scene->add_component(new Label(40, 130, 30, 200, "Change fractal"));
    scene->add_component(new Label(40, 160, 30, 200, "Change color"));
    scene->add_component(new Label(40, 190, 30, 200, "Change C value"));
    scene->add_component(new Label(40, 220, 30, 200, "Change resolution"));
    scene->set_press_handler([](int knob) {
        switch(knob) {
        case 0:
            shared_data.scene = MENU;
            break;
        case 2:
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
                shared_data.scene = CHANGE_RESOLUTION;
                break;
            default:
                break;
            }
            break;
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
    Label* title = new Label(220, 140, 40, 40, "Change color");
    title->set_font_size(2);
    title->set_bg_color(BLACK);
    scene->add_component(title);

    scene->add_component(new Label(120, 190, 30, 220, "Rotate knobs to change"));
    scene->add_component(new Label(120, 220, 30, 220, "respective color value"));

    scene->set_press_handler([](int knob){
        if(knob == 0) {
            shared_data.scene = SETTINGS;
        }
    });
    shared_data.light_rgbs = true;

    
    scene->set_dir_turn_handler([](int knob, int dir) {
        shared_data.set_params_changed = 1;
        switch (knob)
        {
        case 0:
            if(set_data.color.red - 2 * dir >= 0 &&
                set_data.color.red - 2 * dir <= 31) 
                set_data.color.red -= 2 * dir;
            break;
        case 1:
            if(set_data.color.green - 2 * dir >= 0 &&
                set_data.color.green - 2 * dir <= 63) 
                set_data.color.green -= 2 * dir;
            break;
        case 2:
            if(set_data.color.blue - 2 * dir >= 0 &&
                set_data.color.blue - 2 * dir <= 31) 
                set_data.color.blue -= 2 * dir;
            break;
        default:
            break;
        }
    });
    return scene;
}

Scene* SceneBuilder::create_change_value_scene(){
    Scene* scene = new Scene();
    Label* title = new Label(220, 140, 40, 40, "Change C value");
    title->set_font_size(2);
    title->set_bg_color(BLACK);
    scene->add_component(title);
    scene->add_component(new Label(40, 190, 30, 200, "Real part"));
    scene->add_component(new Label(40, 220, 30, 200, "Imaginary part"));
    Label* rp = new Label(250, 190, 30, 200, "");
    rp->attach_value(&set_data.constant_x);
    Label* ip = new Label(250, 220, 30, 200, "");
    ip->attach_value(&set_data.constant_y);
    scene->add_component(rp);
    scene->add_component(ip);

    scene->set_press_handler([](int knob){
        if(knob == 0) {
            shared_data.scene = SETTINGS;
        }
    });
    
    scene->set_dir_turn_handler([](int knob, int dir) {
        shared_data.set_params_changed = 1;
        switch (knob)
        {
        case 1:
            if(set_data.constant_x + 0.05 * dir > MIN_X_CONSTANT && 
                set_data.constant_x + 0.05 * dir < MAX_X_CONSTANT)
                set_data.constant_x += 0.05 * dir;
            break;
        case 2:
            if(set_data.constant_y + 0.05 * dir > MIN_Y_CONSTANT && 
                set_data.constant_y + 0.05 * dir < MAX_Y_CONSTANT)
                set_data.constant_y += 0.05 * dir;
            break;
        default:
            break;
        }
    });
    return scene;
}

Scene* SceneBuilder::create_change_set_scene(){

    Scene* scene = new Scene();
    scene->add_component(new Label(40, 100, 30, 200, "Mandelbrto Set"));
    scene->add_component(new Label(40, 130, 30, 200, "Julias set"));
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
                    ((shared_data.active_component_index + dir) % 2);
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
            shared_data.scene = MENU;
        }
    });
    
    scene->set_dir_turn_handler([](int knob, int dir) {
        shared_data.set_params_changed = 1;
        switch (knob)
        {
        case 0:
            set_data.min_x -= set_data.d_x * dir * 20;
            break;
        case 1:
            set_data.min_y += set_data.d_y * dir * 20;
            break;
        case 2:
            set_data.d_x *= (dir > 0 ? 1.1 : 0.9);
            set_data.d_y *= (dir > 0 ? 1.1 : 0.9);
            set_data.min_y -= set_data.d_y * dir * 16;
            set_data.min_x -= set_data.d_x * dir * 24;
            break;
        
        default:
            break;
        }
    });
    return scene;
}



