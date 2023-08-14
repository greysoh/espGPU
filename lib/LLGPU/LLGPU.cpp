#include <Arduino.h>
#include "LLGPU.h"

//#define USE_FRAMEBUFFER_APPROACH

#define WIDTH 256
#define HEIGHT 256

#ifdef USE_FRAMEBUFFER_APPROACH
int framebuffer[WIDTH][HEIGHT][1];
#endif

void LowGPU::putpixel(int x, int y, int lightness) {
  #ifdef USE_FRAMEBUFFER_APPROACH
  framebuffer[x][y][0] = lightness;
  #else
  Serial.print(x);
  Serial.print(".");
  Serial.print(y);
  Serial.print(".");
  Serial.print(lightness);
  Serial.print("\n");
  #endif
}

void LowGPU::clear() {
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      LowGPU::putpixel(x, y, 0);
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
      Serial.print("\n");
    }
  }
  #endif
}