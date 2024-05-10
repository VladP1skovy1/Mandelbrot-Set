#define _POSIX_C_SOURCE 200112L
 
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
 
#define M_PI 3.1415
 
unsigned int hsv2rgb_lcd(int hue, int saturation, int value) {
  hue = (hue%360);    
  float f = ((hue%60)/60.0);
  int p = (value*(255-saturation))/255;
  int q = (value*(255-(saturation*f)))/255;
  int t = (value*(255-(saturation*(1.0-f))))/255;
  unsigned int r,g,b;
  if (hue < 60){
    r = value; g = t; b = p;
  } else if (hue < 120) {
    r = q; g = value; b = p;
  } else if (hue < 180) {
    r = p; g = value; b = t;
  } else if (hue < 240) {
    r = p; g = q; b = value;
  } else if (hue < 300) {
    r = t; g = p; b = value;
  } else {
    r = value; g = p; b = q;
  }
  r>>=3;
  g>>=2;
  b>>=3;
  return (((r&0x1f)<<11)|((g&0x3f)<<5)|(b&0x1f));
}
 
unsigned short fb[320*480*2];
font_descriptor_t *fdes;
int scale=4;
 
 

int main(int argc, char *argv[]) {
  unsigned char *parlcd_mem_base;
  int i,j;
  printf("Hello\n");
  parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
  if (parlcd_mem_base == NULL)
    exit(1);
 
  parlcd_hx8357_init(parlcd_mem_base);
 
  parlcd_write_cmd(parlcd_mem_base, 0x2c);

//sleep(5);
 
  int k;
  int ptr;
  struct timespec loop_delay = 
    {.tv_sec = 0, .tv_nsec = 60 * 1000 * 1000};
 
 
  fdes = &font_winFreeSystem14x16;
 
  // Green color
  unsigned int green = hsv2rgb_lcd(120, 255, 255);

  // Draw "Madelbrot Set"
  char text1[] = "Mandelbrot Set";
  int x_offset = 10; // Start x position
  int y_offset = 100; // Start y position
  int spacing = 0;
  for (int i = 0; i < sizeof(text1) - 1; i++) {
    draw_char(x_offset + i * (fdes->maxwidth + spacing), y_offset, text1[i], green);
    x_offset += (char_width(text1[i]) * 2.2 + 5);
  }

    // Draw "Madelbrot Set"
  char text2[] = "press to continue";
  x_offset = 10; // Start x position
  y_offset = 200; // Start y position
  spacing = 0;
  for (int i = 0; i < sizeof(text2) - 1; i++) {
    draw_char(x_offset + i * (fdes->maxwidth + spacing), y_offset, text2[i], green);
    x_offset += (char_width(text2[i]) * 1.2 + 5);
  }

  
  // Update the display
  parlcd_write_cmd(parlcd_mem_base, 0x2c);
  for (ptr = 0; ptr < 480 * 320; ptr++) {
    parlcd_write_data(parlcd_mem_base, fb[ptr]);
  }

  //clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL);
    sleep(20);
  printf("Goodbye\n");
 
  return 0;
}


