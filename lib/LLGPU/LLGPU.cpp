#include <Arduino.h>
#include "LLGPU.h"

//#define USE_FRAMEBUFFER_APPROACH

#ifdef USE_FRAMEBUFFER_APPROACH
// This shit can't run past 256x256!
#define WIDTH 256
#define HEIGHT 256
#else
// If you're running this mode, you have a *BEAST*. Just hope you don't need a framebuffer!
#define WIDTH 1280
#define HEIGHT 720
#endif

#ifdef USE_FRAMEBUFFER_APPROACH
int framebuffer[WIDTH][HEIGHT][1];
#endif

void LowGPU::putpixel(int x, int y, int r, int g, int b) {
  #ifdef USE_FRAMEBUFFER_APPROACH
  framebuffer[x][y][0] = g; // Use green like the monochrome days
  #else
  Serial.print(x);
  Serial.print(".");
  Serial.print(y);
  Serial.print(".");
  Serial.print(r);
  Serial.print(".");
  Serial.print(g);
  Serial.print(".");
  Serial.print(b);
  Serial.print("\n");
  #endif
}

void LowGPU::clear() {
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      LowGPU::putpixel(x, y, 0, 0, 0);
    }
  }
}

int LowGPU::get_width() {
  return WIDTH;
}

int LowGPU::get_height() {
  return HEIGHT; 
}

void LowGPU::processing_loop_iteration() {
  #ifdef USE_FRAMEBUFFER_APPROACH
  for (int x = 0; x < LowGPU::get_width(); x++) {
    for (int y = 0; y < LowGPU::get_height(); y++) {
      Serial.print(x);
      Serial.print(".");
      Serial.print(y);
      Serial.print(".");
      Serial.print(framebuffer[x][y][0]);
      Serial.print(".");
      Serial.print(framebuffer[x][y][0]);
      Serial.print(".");
      Serial.println(framebuffer[x][y][0]);
    }
  }
  #endif
}