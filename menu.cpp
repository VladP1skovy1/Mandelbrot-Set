#define _POSIX_C_SOURCE 200112L
 
 #include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#include "mzapo_parlcd.h"
#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "font_types.h"
#include "label.h"
#include "parlcd.h"
#include "scene.h"
#include "scene_builder.h"
#include "render_controller.h"
#include "input_controller.h"
#include "shared_data.h"
 
#define M_PI 3.1415
 

int main(int argc, char *argv[]) {
  RenderController* rnd_ct = RenderController::get_instance();
  InputController* inpt_ct = InputController::GetInstance();
  SceneManager* scene_manager = new SceneManager();
  inpt_ct->set_scene_manager(scene_manager);
//sleep(5);
 
  int k;
  int ptr;
  struct timespec loop_delay = 
    {.tv_sec = 0, .tv_nsec = 30 * 1000 * 1000};
  while(1) {
    scene_manager->update();
    rnd_ct->render();
    inpt_ct->update();
    clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
  }
  printf("Goodbye\n");

  return 0;
}


