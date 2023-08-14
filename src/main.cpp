#include <Arduino.h>
#include "LLGPU.h"

bool is_set_up;

void setup() {
  Serial.begin(115200);
  Serial.println("device_tree: GPU");
  Serial.flush();
  Serial.end(); 
  Serial.begin(921600);
  delay(5000);

  // Encoded OwO
  for (int i = 0; i < 255; i++) {
    LowGPU::putpixel(i, i, i);
  }
  
  is_set_up = true;
}

void loop() {
  while (!is_set_up) delay(1000);
  LowGPU::processing_loop_iteration();
}