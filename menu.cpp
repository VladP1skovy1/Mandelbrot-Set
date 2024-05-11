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
 
#define M_PI 3.1415
 

int main(int argc, char *argv[]) {
  ParLCD* parlcd = ParLCD::GetInstance();


//sleep(5);
 
  int k;
  int ptr;
  struct timespec loop_delay = 
    {.tv_sec = 0, .tv_nsec = 60 * 1000 * 1000};
  Label* example = new Label(0,0,150,200,"example");
  example->set_color(233);
  while(1) {
  example->set_text(example->get_text() + "1");
  example->render();
  parlcd->update();
  //clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
  sleep(1);
  }
  printf("Goodbye\n");
 
  return 0;
}


